# Rubik-s-Cube-in-OpenGL
This repository contains the Final Project of Computer Graphics UCSP 2021-1 

## Authors

* **Marquez Choque, Patrick Xavier** - *San Pablo Catholic University* - [GitHub](https://github.com/patrick03524)
* **Diez Canseco Fuentes, Iñigo Manuel** - *San Pablo Catholic University* - [GitHub](https://github.com/inigomanuel)
* **Mendoza Alejandro, Oscar Andree** - *San Pablo Catholic University* - [GitHub](https://github.com/OscarMendoza99)

## Requirements
The sample code for the `Rubik's Cube` needs CMake 3.20.0 or later.
This project also depends on 6 libraries:

* [GLFW](https://www.glfw.org/)
* [GLAD](https://github.com/Dav1dde/glad)
* [GLM](https://github.com/g-truc/glm)
* [FREEIMAGE](https://freeimage.sourceforge.io/)
* [FREEGLUT](http://freeglut.sourceforge.net/)
* [GLEW](http://glew.sourceforge.net/)

## Solver
We use the Herbert Kociemba's two-phase algorithm for solving Rubik's Cube, you can found it in this [GitHub](https://github.com/muodov/kociemba)

## Demo

A full Demo of this project can be found on youtube: [DEMO-YOUTUBE](https://www.youtube.com/watch?v=6fgyo0bZMnU)

## Instructions

* First it is neccesary use CMake to compile the `CMakeLists.txt` file.
* After that create a directory with the name "texturas" in your local disk D:/ with the files in the `texturas` directory.
* Now you can compile it and run the project without problems!

## Visuals

This is the animation of the view of the Rubik's Cube:

![1](https://user-images.githubusercontent.com/21103950/124789893-4b41b400-df10-11eb-97fa-4b1c9b1c8e96.gif)

This is the animation of the ZOOM of the Rubik's Cube:

![2](https://user-images.githubusercontent.com/21103950/124801253-41be4900-df1c-11eb-9b48-adb1d9db1c74.gif)

This is the animation of every move of the Rubik's Cube like the `R`, `L`, `U`, `D`, `F`, `B` in that order:
![mov1](https://user-images.githubusercontent.com/21103950/124804878-62889d80-df20-11eb-9bf9-d4c606b18c1f.gif)

This is the animation of the solution of the movements previously made by the Rubik's Cube Solver:
![mov2](https://user-images.githubusercontent.com/21103950/124804894-67e5e800-df20-11eb-961e-605c4397fbf4.gif)

This is our animation of the "Breathing" of the Rubik's Cube:
![owo](https://user-images.githubusercontent.com/21103950/124804908-6b796f00-df20-11eb-826c-c97443354316.gif)

This is the animation of the Expansion of every cube in the Rubik's Cube:
![uwu](https://user-images.githubusercontent.com/21103950/124804914-6ddbc900-df20-11eb-9b35-45ff32c8d8bb.gif)

This is the animation of the Retraction of every cube in the Rubik's Cube:
![uwu2](https://user-images.githubusercontent.com/21103950/124804925-6fa58c80-df20-11eb-86df-64918ae049d8.gif)
