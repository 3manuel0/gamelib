## What's gamelib

#### IT's a javascript library that has:

`raylib.js`: for linking raylib functions in wasm to display in the html canvas.

`wasmlib.js`: for using printf, and also function to help making webassembly environment, with str_len and get_str to work with wasm (Cstrings)

feel free to include any of them in your project.

#### NOTE:

not all the raylib function are available only the ones you see in `raylib.js`file.

I'm still adding functions and fixing bugs from time to time.

#### How To Use

This library is mostly for learning puposes, if you don't want to use emscripten that does everything for you, but you want to compile things using clang then this library is for you.

First you can use/edit the templet in game.c, it basicaly works with raylib function, write your frame logic inside the function `GameFrame()` , you can compile using `clang` with `wasm-ld`, and also you can add your makefile or others (CMAKE, MSVC...) to compile for windows, linux, macos....

### More About Raylib

[raylib (github)](https://github.com/raysan5/raylib) is an awesome C library for game development and multimedia applications.

Visit [raylib.com](https://www.raylib.com/) to learn more or support the Raylib project!
