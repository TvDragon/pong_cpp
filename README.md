# Basic Platformer
## Motivation

This is the classic Pong game that all retro players remember. The absolute beauty of a game like this can never be forgotten. I wanted to remake this game as it was something I played often because of how fun it it was given its simplicity. I also took this opportunity to try creating buttons for you to select the difficulty and whether you wanted to play this solo or against a friend in person.

## Getting Started

### Preprequisites

Note: If you are a windows user you can just skip the install prerequisites and move down to usage. Otherwise, you must install the prerequisites to play the game.

- [C++](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
- [SDL2 Library](https://www.libsdl.org/download-2.0.php)

#### Installing prerequisites on Ubuntu/Debian
1. First check if C/C++ compiler is installed by opening up the terminal and enter the command

		g++ --version

2. If you see a g++ version then you can skip the following steps. Otherwise, continue following the steps below in your terminal

3. Update and upgrade the repositories

		sudo apt update && sudo apt upgrade

4. Install g++

		sudo apt install g++

5. Check g++ version

		g++ --version

#### Optional Install on Windows
1. Follow tutorial to install on [windows](https://www.matsson.com/prog/sdl2-mingw-w64-tutorial.php)

### Installing
1. You can either download the zip file and upzip it or clone th repository

		git clone https://github.com/TvDragon/pong_cpp.git
	
## Usage

1. Once you have installed the prerequisites and unzipped the file or cloned the repository move into the folder

2. If you use Ubuntu/Debian move into linux_version then you can run the command below which will compile the files using a Makefile then you can run the game

		make play
		./play

3. If you use Windows then you need to open the windows folder then plays folder and double click on play.exe to play the game

## Controls

- Left Paddle:
	- Move Up - w
	- Move Down - d
- Right Paddle:
	- Move Up - up arrow key
	- Move Down - down arrow key
