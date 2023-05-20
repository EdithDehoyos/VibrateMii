# VibrateMii
Wii homebrew that activates the rumble function

This requires a modded wii with the homebrew channel installed.

Building requires DKP enviornment variables to be set.

# Installing
1. Download the latest release as a zip file
2. Extract the "VibrateMii" folder and place it in the 'apps' directory on your Wii's SD card.
3. Run VibrateMii from the Homebrew Channel.

# How to build:
1. Follow this page to setup devkitPro on your machine: https://devkitpro.org/wiki/Getting_Started
    Arch Linux is recommended for setting up DKP pacman, it's as simple as adding a repo, and doing a quick update.
2. Using DKP pacman, install the wii-dev package.
3. run the command "make" in the root repository, ensure libogc is installed.
4. To test this on your Wii, set the env variable "WIILOAD=tcp:yourip" where 'yourip' is the IP address of your Wii.
5. Run "wiiload 'VibrateMii.dol'" while your Wii is in the Homebrew channel.

# Supporting:
If you wish to support this project, any help is greatly appreciated. Thanks to the Wii modding community, and homebrew developers who made things like libogc that makes the job a lot easier.
