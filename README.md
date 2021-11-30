# Pong
## Motivation

This is the classic Pong game that all retro players remember. The absolute beauty of a game like this can never be forgotten. I wanted to remake this game as it was something I played often because of how fun it it was given its simplicity. I also took this opportunity to try creating buttons for you to select the difficulty and whether you wanted to play this solo or against a friend in person.

## Getting Started

### Optional Dependency Installs

Note: You do not have to install the necessary libraries to play as they are already included in the downloads. You can move down to the usage section to start playing the game. However if the game doesn't work then you may have to follow the install guide below.

- [C++](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
- [SDL2 Library](https://www.libsdl.org/download-2.0.php)

#### Installing on Ubuntu/Debian
1. First check if C/C++ compiler is installed by opening up the terminal and enter the command

		g++ --version

2. If you see a g++ version then you can skip the following steps. Otherwise, continue following the steps below in your terminal

3. Update and upgrade the repositories

		sudo apt update && sudo apt upgrade

4. Install g++

		sudo apt install g++

5. Check g++ version

		g++ --version

6. Install the SDL2 Library by entering the command below in your terminal

		sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev

Note: The package manager you use will be different depending on which linux system you use. You can find your package manager by searching it on the internet if you don't know then install the libraries.

#### Installing on Windows
1. Follow tutorial to install on [windows](https://www.matsson.com/prog/sdl2-mingw-w64-tutorial.php)

## Installing the game
If you want to install the source code or appimage for Linux you can download it at [Linux Build](https://github.com/TvDragon/pong_cpp/releases/tag/Linux)

If you want to install the source code for Windows you can download it at [Windows Build](https://github.com/TvDragon/pong_cpp/releases/tag/Windows)
	
## Usage

1. Once you have installed and unzipped the file or cloned the repository move into the folder

2. If you use Ubuntu/Debian move into folder you unzipped then you can run the command in your terminal in the directory that you downloaded the game to and start playing the game

		sh play.sh

3. If you prefer using an app image then run the command below in your terminal in the directory that you downloaded the game and start playing the game by double clicking on it

		chmod a+x Pong-x86_64.AppImage

4. If you use Windows then you need to open the folder you just unzipped then play folder and double click on play.exe to play the game

## Controls

- Left Paddle:
	- Move Up - w
	- Move Down - d
- Right Paddle:
	- Move Up - up arrow key
	- Move Down - down arrow key
