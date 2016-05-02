# 2. Networking

## 2.1. Additional Modules necessary for networking
Look at the new modules in the `Makefile` and the additions in `main.c`.
```
USEMODULE += gnrc_netdev_default
USEMODULE += auto_init_gnrc_netif
USEMODULE += gnrc_ipv6_default
USEMODULE += gnrc_icmpv6_echo
```
```c
#include "msg.h"
#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];
msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);
```

## 2.2. Virtual Network Interfaces for Native
Setup a necessary virtual network interface for native:
```sh
sudo ip tuntap add tap0 mode tap user ${USER}
sudo ip link set tap0 up
```
This will create the interface `tap0` and can be verified with `ifconfig` or `ip link`

## 2.3. Starting the RIOT on Native
```sh
make all term
```

## 2.4. Help ?
Run `help` to see new commands
```
> help
help
Command              Description
---------------------------------------
reboot               Reboot the node
ps                   Prints information about running threads.
ping6                Ping via ICMPv6
random_init          initializes the PRNG
random_get           returns 32 bit of pseudo randomness
ifconfig             Configure network interfaces
txtsnd               Sends a custom string as is over the link layer
ncache               manage neighbor cache by hand
routers              IPv6 default router list
>
```

Look at the output of ps
```
> ps
ps
        pid | name                 | state    Q | pri | stack ( used) | location
          1 | idle                 | pending  Q |  15 |  8192 ( 6240) | 0x806e600
          2 | main                 | running  Q |   7 | 12288 ( 9312) | 0x806b600
          3 | ipv6                 | bl rx    _ |   4 |  8192 ( 6240) | 0x80796a0
          4 | gnrc_netdev2_tap     | bl rx    _ |   4 |  8192 ( 6240) | 0x8077660
            | SUM                  |            |     | 36864 (28032)
>
```

## 2.5 Ping the Host
1.  Run `ifconfig` to see the configured network interfaces and additional information.
    ```
    > ifconfig
    ifconfig
    Iface  4   HWaddr: 1a:06:e3:b8:e5:f1

               MTU:1500  HL:64  RTR  RTR_ADV
               Source address length: 6
               Link type: wired
               inet6 addr: ff02::1/128  scope: local [multicast]
               inet6 addr: fe80::1806:e3ff:feb8:e5f1/64  scope: local
               inet6 addr: ff02::1:ffb8:e5f1/128  scope: local [multicast]
               inet6 addr: ff02::2/128  scope: local [multicast]

    >
    ```

2.  Copy the [link-local address](https://en.wikipedia.org/wiki/Link-local_address#IPv6) of the
    RIOT node (prefixed with `fe80`, without the `/64`) and try to ping it from your host machine.
    ```
    ping fe80::1806:e3ff:feb8:e5f1%tap0
    ```
    If this notation does not work, then try the following command:
    ```
    ping -I tap0 fe80::1806:e3ff:feb8:e5f1
    ```
    It is necessary for link-local addresses to specify the desired interface.

## 2.6 Ping the Native Board
1.  Lookup the link-local address of your `tap0` interface on your host machine:

    ```sh
    > ip addr show dev tap0
    14: tap0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 500
        link/ether 4a:ba:26:52:88:dc brd ff:ff:ff:ff:ff:ff
        inet6 fe80::48ba:26ff:fe52:88dc/64 scope link
           valid_lft forever preferred_lft forever
    ```

    Copy this link-local address (again, without `/64`) and call the following command from within
    the RIOT shell:

    ```
    > ping6 fe80::48ba:26ff:fe52:88dc
    ping6 fe80::48ba:26ff:fe52:88dc
    12 bytes from fe80::48ba:26ff:fe52:88dc: id=84 seq=1 hop limit=64 time = 0.218 ms
    12 bytes from fe80::48ba:26ff:fe52:88dc: id=84 seq=2 hop limit=64 time = 0.234 ms
    12 bytes from fe80::48ba:26ff:fe52:88dc: id=84 seq=3 hop limit=64 time = 0.218 ms
    --- fe80::48ba:26ff:fe52:88dc ping statistics ---
    3 packets transmitted, 3 received, 0% packet loss, time 2.061141 s
    rtt min/avg/max = 0.218/0.223/0.234 ms
    ```

## 2.7 Ping from real hardware
1.  Flash the application onto your `samr21-xpro` board.
2.  Verify your link-local IPv6 address with the `ifconfig` command.
3.  Do a multicast ping with `ping6 ff02::1`.
4.  Ask your neighbor for a link-local IPv6 address and ping it.
