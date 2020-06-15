# LO41 - C - Airport control tower simulation

<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/TheRolfFR/LO41_C_airport?style=flat-square"> <img alt="GitHub repo size" src="https://tokei.rs/b1/github/TheRolfFR/LO41_C_airport?category=code"> <a href="./LICENSE.md"><img alt="GitHub repo size" src="https://img.shields.io/badge/License-NPOSL--3.0-red?style=flat-square"></a>


_Personal academic project : C control tower simulation in system c_

## Objective
Understand Operating systems principles and management. Use C API to implement a real use case : a control tower of an
airport

## How to build and launch the project
By using the [CLion JetBrains Editor](https://www.jetbrains.com/clion/), you can easily get started. Else you could use
the [Makefile](./cmake-build-debug/Makefile) and the [cbp file](./cmake-build-debug/lo41_projet.cbp) generated
automatically by the project. Or simply, you could just type this in a tmerinal :
```sh
gcc -Wall main.c -o lo41_projet && chmod +x lo41_projet && ./lo41_projet
```

## Main parts of the code

Here data is separated in different categories/themes :

- display : everything displayed to the screen
- arguments : every argument passed to the threads
- plane : the plane data itself
- comptrolleur : the conptrolleur in charge of regulating traffic activity
- ipc : ipc messages sent between entities
- wating list : airplane waiting list for landing and take-off
- mutex : everything linked to critical and shared resources
- runway : handle the runway data 
- tarmac : handle the parking area
- utilities : additional functions created to code faster