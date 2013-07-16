#STM32F3-Discovery USB Example application

A USB Joystick implemented using the accelerometers in the STM32F3 Discovery board.

This is a use of the template application for the STM32F30x ARM microcontrollers
that compiles with GNU tools.

The template serves as a quick-start for those who do not wish to use an IDE, but rather
develop in a text editor of choice and build from the command line. It is
derived from [mblythe's version](https://github.com/mblythe86/stm32f3-discovery-basic-template),
which also credits other sources.

## Installing

Before building, you should install the GNU compiler tools.  I'm using the
ARM-supported [Launchpad gcc-arm-embedded](https://launchpad.net/gcc-arm-embedded)
toolchain, installed in **/usr/local/arm**.

The package expects a patched and compiled version of the [STM32F3 standard
peripherals and drivers library](http://www.st.com/web/en/catalog/tools/PF258154)
to be in an adjacent directory. Download the ZIP file, unzip it to the parent
directory above this one, and change into the new **STM32F3-Discovery_FW_V1.1.0**
directory and say:

    patch -p1 < ../stm32f3-discovery-usb-example/STM32F3-Discovery_FW_V1.1.0-gcc.patch

This should cleanly apply the patch to a number of files. Then say:

    make install

This should create an **inst** directory (under the top-level ST firmware
directory) containing two compiled code libraries and copies of all header files
required to build applications.

Now change back to this application template directory and build the application by saying:

    make

You should see five new files whose names start with *main*. These are your
executables and program listings and symbol maps.

##Source code
The **src** directory contains the source-code files for this application template.

**system_stm32f30x.c** can be re-generated using an Excel (.XLS) file developed
by ST. This sets up the system clock values for the project. The file included
in this repository is taken from the STM32F3-Discovery firmware package. It is
copied from the directory: **Libraries/CMSIS/Device/ST/STM32F30x/Source/Templates/**

##Programming and debugging code on the board

First, make sure you have OpenOCD installed and in your path. Then connect your
board, and load the application by saying:

    make program

This task relies on the OpenOCD script provided in the **extra** directory.

To load the program and debug it using GDB in TUI mode, simply say

    make debug

This relies on a gdb script which is also in the **extra** directory.
See [this blog post](http://www.mjblythe.com/hacks/2013/02/debugging-stm32-with-gdb-and-openocd/)
for info about how it works.

##Installing OpenOCD

Assuming you have your ARM gcc tools installed in **/usr/local/arm**, you
probably want to install OpenOCD there too. Change these instructions and the
Makefile if you want it elsewhere. After you have cloned the [OpenOCD
repository](http://openocd.git.sourceforge.net/git/gitweb.cgi?p=openocd/openocd;a=summary),
use these commands to compile and install it (it must be configured with stlink
support enabled):

    ./bootstrap
    ./configure --prefix=/usr/local/arm --enable-maintainer-mode --enable-stlink
    make 
    sudo make install

If there is an error finding the .cfg file, please double-check the
OPENOCD_BOARD_DIR constant in the Makefile.

###UDEV Rule for the Discovery Board

If you are not able to communicate with the STM32F3-Discovery board without
root privileges you should add a udev rule for this hardware by following
[these steps from the stlink repo readme file](https://github.com/texane/stlink#readme).
