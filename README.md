# RIOT-Tutorials

## Recommended Setup (Using a Virtual Machine)
* bring your laptop
* if absent, install and set up [git](https://help.github.com/articles/set-up-git/)
* if absent, install [VirtualBox](https://www.virtualbox.org/wiki/Downloads)
* if absent, install [VirtualBox Extension Pack](https://www.virtualbox.org/wiki/Downloads)
* if absent, install [Vagrant](https://www.vagrantup.com/downloads.html)
* git clone --recursive https://github.com/cgundogan/RIOT-Tutorials.git
* run the [Vagrant RIOT Setup](https://github.com/RIOT-OS/RIOT/blob/master/dist/tools/vagrant/README.md)

## Advanced Setup (Without Using a VM)
* bring your laptop
* if absent, install and set up [git](https://help.github.com/articles/set-up-git/)
* install the build-essential packet (make, gcc etc.). This varies based on the operating system in use.
* [Native dependencies](https://github.com/RIOT-OS/RIOT/wiki/Family:-native#dependencies)
* [openOCD](https://github.com/RIOT-OS/RIOT/wiki/OpenOCD)
* [GCC Arm Embedded Toolchain](https://launchpad.net/gcc-arm-embedded)
* on OS X: [Tuntap for OS X](http://tuntaposx.sourceforge.net/)
* [additional tweaks](https://github.com/RIOT-OS/RIOT/wiki/Board:-Samr21-xpro) necessary to work with the targeted hardware (ATSAMR21)
* git clone --recursive https://github.com/cgundogan/RIOT-Tutorials.git
