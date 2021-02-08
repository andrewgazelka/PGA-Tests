# Andrew Gazelka's CSCI5607 Project
Executable compiled for MacOS Big Sur

## Example usage

![Example usage](example.gif)

| Action | Effect|
| ------------- | ------------- |
| Pressing `r`  | Resets orientation  |
| Pressing `b`  | Toggles shape (btwn square and triangle)  |
| Dragging on edge | Rotates shape |
| Dragging on corner | Expands/Contracts shape |
| Dragging on corner | Expands/Contracts shape |

## Difficulties
The project was rather straight-forward. However, I did encounter a couple of difficulties.

### Setting up CMake
First, I wanted to setup the project with CMake and my brew-installed SDL-2. I am not super familiar with CMake, but I eventually 
figured out how to reference SDL-2 without giving an absolute path with the `find_package(SDL2 REQUIRED)` command. 

### SDL headers
Still, I could not get the project to compile because the `#include <SDL2/SDL.h>` header is not a universal import for SDL and did not work on 
MacOS. Instead I had to change it to `#include "SDL.h"`.

### inline functions
I didn't want all of my code in the same file. Several of the library functions were defined in header files and some did not have the `inline` keyword which led to linking errors. To fix this, I needed to add the `inline` keyword to prevent the compiler thinking there were multiple definitions.



## Extensions
- ✅ Animating the square
- ✅ Changing something visually when the user presses the keyboard
- ✅ Supporting a triangle in addition to a square

## Code
- [Zipped](project.zip)
- [Executable](bin/proj1)
- [Source](source_code)

## Compiling
```
mkdir build
cd build
cmake ..
```

## Running
Execute the compiled binary. Make sure that `face.ppm` is in the current working directory.
