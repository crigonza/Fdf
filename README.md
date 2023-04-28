# Fdf

Fdf is a project at 42 that aims to create a graphical representation of a terrain in relief using the [MLX42](https://github.com/codam-coding-college/MLX42) library.

![Fdf representation](https://github.com/crigonza/Fdf/blob/main/fdf.png)

## Getting Started

To use this program, you need to clone this repository and compile it with `make bonus`. This will generate an executable file: `fdf`.

## Usage

To use this program in your own project, you need to provide a map file as an argument to the `fdf` program. The map file must contain a grid of numbers that represent the height of each point. For example:

```txt
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

The program will display the map in a window using a perspective projection and a color gradient according to the height of each point.

![42 image](https://github.com/crigonza/Fdf/blob/main/fdf_42.png)

You can create your own maps with the .fdf extension or use the default maps that are in the /test_maps folder.
```
./fdf test_maps/t1.fdf
```
You can also interact with the map using the keyboard and mouse:

- Use arrow keys to move the map
- Use `O` and `P` keys to zoom in and out
- Use `Q` and `W` keys to rotate the X axis
- Use `A` and `S` keys to rotate the Y axis
- Use `Z` and `X` keys to rotate the Z axis
- Use `SPACE` to change perspective.
- Use `C` key to change color.
- Use `ESC` key to exit the program

## Requirements

The project has the following requirements:

- The program must use the MLX42 library for graphical output
- The program must use only basic functions from the standard C library (write, malloc, free, open, read, close)
- The program must handle errors properly and not leak memory
- The program must use a Makefile for compilation
