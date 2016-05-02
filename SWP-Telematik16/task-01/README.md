# 1. Running RIOT

## 1.1. Starting the RIOT on Native
```sh
make all term
```

## 1.2. Help ?
Run `help` to see a list of all available commands
```
> help
help
Command              Description
---------------------------------------
reboot               Reboot the node
ps                   Prints information about running threads.
```

Look at the output of `ps`
```
> ps
ps
        pid | name                 | state    Q | pri | stack ( used) | location
          1 | idle                 | pending  Q |  15 |  8192 ( 6240) | 0x8053240
          2 | main                 | running  Q |   7 | 12288 ( 9312) | 0x8050240
            | SUM                  |            |     | 20480 (15552)
>
```

## 1.3. Print the BOARD name
Add a print statement to the `main` function to output the name of the board.
```
printf("This application runs on %s\n", RIOT_BOARD);
```

## 1.4. Starting the RIOT on real hardware
1.  Get to know your hardware

    ![SAMR21-XPRO](../SAM-R21.jpg)

    MCU                    | ATSAMR21G18A
    -----------------------|------------------------------------
    Family                 | ARM Cortex-M0+
    Vendor                 | Atmel
    RAM                    | 32Kb
    Flash                  | 256Kb
    Frequency              | up to 48MHz
    FPU                    | no
    Timers                 | 6 (1x 16-bit, 2x 24-bit, 3x 32-bit)
    ADCs                   | 1x 12-bit (8 channels)
    UARTs / SPIs / I2Cs    | max 5 (shared)
    Vcc                    | 1.8V - 3.6V

2.  To compile an application for a specific board, we can make use of the `BOARD` environment
    variable.
    ```sh
    BOARD=samr21-xpro make all flash term
    ```
    This command will compile the application, burn the image onto the `samr21-xpro` and open a
    connection to the RIOT shell.

3.  Verify the output of `RIOT_BOARD` matches your hardware.
