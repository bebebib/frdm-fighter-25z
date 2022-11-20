# TODO
Lets make pong! Why not...

# How to run when board is flashed
1. Open minicom to 80 x 24 size and 921600 baud (or any other terminal software)
    - `sudo minicom -b 921600 -D /dev/ACM0`
    - can be other device for `-D` arg 
2. Select correct COM port!
3. """Game""" can be started!

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

# How to configure FRDM-KL25Z for J-Link Compatibility
1. Hold the reset button while board is powered off, and plug it in
2. Install J-Link firmware from the board from https://www.segger.com/downloads/jlink/OpenSDA_FRDM-KL25Z
3. Copy and paste the file from the above download to `BOOTLOADER:/`
4. Unplug and repower the board normally, should now be a J-Link device!

# Debugging this with J-Link
1. This is configured for VS Code WSL Ubuntu compatibility, please modify launch.json for how you wish to launch this
2. If you are using WSL Ubuntu, please launch the SEGGER J-Link Remove Server software in Windows
    - Make sure that it connects to the probe! Do `How to configure FRDM-KL25Z for J-Link Compatibility` if this does not happen
3. You should be able to "run and debug" the `Debug J-Link` config in VS Code, and the debugger should launch properly!
4. BAM! No need for MCUXpresso (except to regenerate / configure BSP...)

### BSP needs to be generated from the IDE, for now use the basic config from demo_apps/hello_world
### Need a way to do this without having to mess with SDK over and over...

# TODO

1. Create a "flashable" build target
2. Some CMake automation for finding packages?
3. Use stdlib print and scan
4. Make the actual game!