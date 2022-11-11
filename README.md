# Links to get started
https://www.nxp.com/document/guide/get-started-with-the-frdm-kl25z:NGS-FRDM-KL25Z#0

Download the NXP Kinetis SDK and MCUXPresso
Make sure to download both!!!

# GCC arm none eabi embedded 
https://developer.arm.com/downloads/-/gnu-rm
^^ install then unzip tarball using 

```
sudo tar xjf gcc-arm-none-eabi-your-version.bz2 -C /usr/share/
```

then create symbolic commands in /usr/bin

```
sudo ln -s /usr/share/gcc-arm-none-eabi-your-version/bin/arm-none-eabi-gcc /usr/bin/arm-none-eabi-gcc 
sudo ln -s /usr/share/gcc-arm-none-eabi-your-version/bin/arm-none-eabi-g++ /usr/bin/arm-none-eabi-g++
sudo ln -s /usr/share/gcc-arm-none-eabi-your-version/bin/arm-none-eabi-gdb /usr/bin/arm-none-eabi-gdb
sudo ln -s /usr/share/gcc-arm-none-eabi-your-version/bin/arm-none-eabi-size /usr/bin/arm-none-eabi-size
sudo ln -s /usr/share/gcc-arm-none-eabi-your-version/bin/arm-none-eabi-objcopy /usr/bin/arm-none-eabi-objcopy
```

Do this so we can use gdb
```
sudo apt install libncurses-dev
sudo ln -s /usr/lib/x86_64-linux-gnu/libncurses.so.6 /usr/lib/x86_64-linux-gnu/libncurses.so.5
sudo ln -s /usr/lib/x86_64-linux-gnu/libtinfo.so.6 /usr/lib/x86_64-linux-gnu/libtinfo.so.5
```

check versions

```
arm-none-eabi-gcc --version
arm-none-eabi-g++ --version
arm-none-eabi-gdb --version
arm-none-eabi-size --version
```

# BSP needs to be generated from the IDE, for now use the basic config from demo_apps/hello_world
# Need a way to do this without having to mess with SDK over and over...

# TODO

1. Get CMAKE project to work with J-Link flashing, so everything can be done out of VS Code
    - Rebuilding hello world here... going to try and compile!
2. Make a basic "console" with integrated UART
3. Import Zephyr OS to make this project RTOS based
4. Create a "console game" that can be ran
    - Need ideas for this..