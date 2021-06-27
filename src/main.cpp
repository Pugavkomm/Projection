/**
 * @file main.cpp
 * @author M.M. Pugavko (slavapugavko2@gmail.com)
 * @mainpage Projection of line
 * The program takes three arguments: name_file x y z
    name_file is file with line
    x, y and z  are coordinates of the point 
    The program prints output of the following form
    segment n parameter s point x y z
    n is number of segment of line
    s is a parameter that shows the part of the segment that the projection falls on. This parameter ranges from 0 to 1.
    The minimum distance to the line is defined as a perpendicular. If the perpendicular does not fall on the segment, then the nearest edge of the segment is selected.

    Example: 
    
        ./main data.dat 1 1 1 
    
    Output: 

        Segment 2 parameter 0.75 point 1.75 0.75 0
        Segment 3 parameter 0.25 point 2.25 1 0.25

    Computing:

    \f[
        x_2 (y_2) (z_2) = x_1 (y_1) (z_1) - P \cos(\alpha) (\cos(\beta)) (\cos(\gamma)),
    \f]
    \f[
        P = \frac{MM_1(x_1 - x_0) + MM_2(y_1 - y_0) + MM_3(z_1 - z_0)}{\sqrt{MM_1^2 + MM_2^2 + MM_3^2}},
    \f]
    \f[
       \cos(\alpha) = \frac{MM_1}{\sqrt{MM_1^2 + MM_2^2 + MM_3^2}},
    \f]
    \f[
        \cos(\beta) = \frac{MM_2}{\sqrt{MM_1^2 + MM_2^2 + MM_3^2}},
    \f]
    \f[
        \cos(\gamma) = \frac{MM_3}{\sqrt{MM_1^2 + MM_2^2 + MM_3^2}},
    \f]
    
    where \f$O(x_1, y_1, z_1)\f$ -- an input point, \f$O(x_2, y_2, z_2)\f$ -- a projected point and \f$ O(x_0, y_0, z_0)\f$ -- start point of piece of line. 
    


 * @version 2.0
 * @date 2021-06-27
 */
#include "point.h"
#include "read_data.h"
#include "compute.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using std::abs;
using std::cout;
using std::endl;
using std::ifstream;
using std::invalid_argument;
using std::string;
using std::stringstream;
using std::vector;
int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        throw invalid_argument("Error");
    }
    Point input_point;
    double ax;

    for (int i = 0; i < DIM; ++i)
    {
        stringstream convert(argv[i + 2]);
        convert >> ax;
        input_point[i] = ax;
    }
    cout << "Point:\n";
    input_point.printPoint();
    string namefile = argv[1];
    Read_Data file(namefile);
    vector<Point> line;
    cout << "Start Read\n";
    file.read_to_line(line);
    file.close();
    cout << "End Read\n";
    Compute comp;
    comp.get_points_and_input(line, input_point);
    comp.display_projections();
    return 0;
}
