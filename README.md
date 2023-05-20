# VibrateMii
Wii homebrew that activates the rumble function

This requires a modded wii with the homebrew channel installed.

Building requires DKP enviornment variables to be set.

# How to build:
1. Follow this page to setup devkitPro on your machine: https://devkitpro.org/wiki/Getting_Started
    Arch Linux is recommended for setting up DKP pacman, it's as simple as adding a repo, and doing a quick update.
2. Using DKP pacman, install the wii-dev package.
3. run the command "make" in the root repository, ensure libogc is installed.
4. To test this on your Wii, set the env variable "WIILOAD=tcp:yourip" where 'yourip' is the IP address of your Wii.
5. Run "wiiload 'VibrateMii.dol'" while your Wii is in the Homebrew channel.
