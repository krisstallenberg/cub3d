# Introduction
cub3D is a program, written in C, which generates interactive raycasted 3D-looking worlds, similar to those found in the 1992 game [Wolfenstein 3D](http://users.atw.hu/wolf3d/). The imaging is realized using the MiniLibX graphics library.

# Parameters
The worlds are created using `.cub` files, which specify the map of the maze as well as the wall and sprite textures, floor and ceiling colors and resolution of the window. A sample .cub file is displayed below:
```
R 1920 1080
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
S ./path_to_the_sprite_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000002000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001 11111111 1111111 111111111111
```

## The elements
**R(esolution)**: width x heigth (in px)  
**NO(rth)**: path to BMP texture  
**SO(uth)**: path to BMP texture  
**WE(st)**: path to BMP texture  
**EA(st)**: path to BMP texture  
**S(prite)**: path to BMP texture  
**F(loor)**: floor color (RGB value)  
**C(eiling)**: ceiling color (RGB value)

## The map
**0**: Empty  
**1**: Wall  
**2**: Sprite  
**N/S/E/W**: Start position, with the character specifying the camera orientation

## Parsing the .cub files
A couple things must be considered upon parsing a `.cub` file:
1. The map must be surrounded by walls.
2. The elements can be given in any order, the map is always given last.
3. The elements are seperated by 1 or more newlines.
4. Information within elements is seperated by 1 or more spaces.
