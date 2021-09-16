# Projection
This program takes three arguments: name_file x y z name_file is file with line x, y and z are coordinates of
the point The program prints output of the following form segment n parameter s point x y z n is number of segment
of line s is a parameter that shows the part of the segment that the projection falls on. This parameter ranges from
0 to 1
## Documentation

[Documentation](http://http://95.182.120.139:8000/)

## Calculations are made according to the following formulas
<img src="https://render.githubusercontent.com/render/math?math=x_2 (y_2) (z_2) = x_1 (y_1) (z_1) - P \cos(\alpha) (\cos(\beta)) (\cos(\gamma))">, 

<img src="https://render.githubusercontent.com/render/math?math=P = \frac{MM_1(x_1 - x_0) + MM_2(y_1 - y_0) + MM_3(z_1 - z_0)}{\sqrt{MM_1^2 + MM_2^2 + MM_3^2}}">, 

<img src="https://render.githubusercontent.com/render/math?math=\cos(\alpha) = \frac{MM_1}{\sqrt{MM_1^2 + MM_2^2 + MM_3^2}}">, 

<img src="https://render.githubusercontent.com/render/math?math=\cos(\beta) = \frac{MM_2}{\sqrt{MM_1^2 + MM_2^2 + MM_3^2}}">, 

<img src="https://render.githubusercontent.com/render/math?math=\cos(\gamma) = \frac{MM_3}{\sqrt{MM_1^2 + MM_2^2 + MM_3^2}}">.

<img src="https://render.githubusercontent.com/render/math?math=O(x_1, y_1, z_1)"> -- an input point

<img src="https://render.githubusercontent.com/render/math?math=O(x_2, y_2, z_2)"> -- a projected point

<img src="https://render.githubusercontent.com/render/math?math=O(x_0, y_0, z_0)"> -- Start point of piece of line. 

## Сompiling
gcc compiler is required to compile.

## Run
Example:

```./main namefile x y z ```

## Structure
```
.
├── Makefile
├── LICENSE
├── README.md
├── doxygen_config
├── include
│   ├── consts.h
│   ├── read_data.h
|   ├── consts.h
│   ├── point.h
|   └── compute.h
├── src
│   ├── main.cpp
|   ├── compute.cpp
|   ├── read_data.cpp
│   └── point.cpp
├── lib
  ├── 
├── doc                 
│   ├── def             
│   ├── html             
│   ├── latex            
│   └── docbook
├── logo                 
│   ├── logo.png # logo for documentation            
├── bin
│   ├── main # уxecutable file
│   └── data.dat # example data
```
