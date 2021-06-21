/** 
    @mainpage Projection of line
    @author M.M. Pugavko 

    The program takes three arguments: name_file x y z
    name_file is file with line
    x, y and z  are coordinates of the point 
    The program prints output of the following form
    segment n parameter s point x y z
    n is number of segment of line
    s is a parameter that shows the part of the segment that the projection falls on. This parameter ranges from 0 to 1
*/

#include "point.h"
#include <iostream>
#include <vector> 
#include <fstream>
#include <string> 
#include <cmath>
#include <stdexcept>
#include <sstream> 
using std::invalid_argument; 
using std::abs; 
using std::sqrt; 
using std::cout;
using std::endl; 
using std::vector; 
using std::string; 
using std::ofstream; 
using std::ifstream; 
using std::stringstream; 
#define ACCUR 1e-7 // Distance Accuracy
#define COS(top, bottom) top / bottom
#define DIST(X, Y, Z) sqrt(X * X + Y * Y + Z * Z) 
#define DIST_BETWEEN(x1, x2, y1, y2, z1, z2) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 -z2)) // The distance between two points 



/*! 
    \brief This function read file.
    Structure of file:
    x0 y0 z0
    x1 y1 z1
    ...
    xn yn zn
*/
void read_line(vector<Point>& points, string namefile){
    Point temp; 
    double read_point[DIM]; 
    ifstream file(namefile); 
    if(!file){
        throw invalid_argument("File not found!"); 
    } else{ 
        int i = 0; 
        while (file >> read_point[i]){
            i++; 
            if (i == DIM){
                i = 0; 
                temp.setPoint(read_point[0], read_point[1], read_point[2]);
                points.push_back(temp); 
                
            }
        }
    }
    file.close();
}

void calculate_dims(vector<Point> &points, Point &input_point){ // TODO add const
    size_t quant_points = points.size();
    Point direction_vector; 
    Point temp_projection; 
    vector<Point> all_projections; 
    vector<unsigned int> segments; 
    vector<float> parameters; 
    double cos;
    double vector_length; 
    double P; 
    double from_proj_to_point; 
    double old_from_proj_to_point = 100000; 
    vector<double> distances; 
    for (size_t i = 0; i < quant_points - 1; ++i){
        direction_vector = points[i + 1] - points[i]; 
        vector_length = DIST(direction_vector[0], direction_vector[1], direction_vector[2]); 
        P = 0; 
        for (size_t j = 0; j < DIM; ++j)
            P += direction_vector[j] * (points[i][j] - input_point[j]); 
        P /= vector_length; 
        for (size_t j = 0; j < DIM; ++j){
            cos = direction_vector[j] / vector_length; 
            temp_projection[j] = points[i][j] - P * cos; 
        }
        for (int j = 0; j < DIM; ++j){
            if (points[i][j] <  points[i + 1][j]){
                if (temp_projection[j] < points[i][j])
                    temp_projection[j] = points[i][j]; 
                else if (temp_projection[j] > points[i + 1][j])
                    temp_projection[j] = points[i + 1][j];
            }
            else if (points[i][j] > points[i + 1][j]){
                if (temp_projection[j] > points[i][j])
                    temp_projection[j] = points[i][j]; 
                else if (temp_projection[j] < points[i + 1][j])
                    temp_projection[j] = points[i + 1][j];
            }
        }
        from_proj_to_point = DIST_BETWEEN(input_point[0], temp_projection[0], 
                                          input_point[1], temp_projection[1],
                                          input_point[2], temp_projection[2]);
        if (from_proj_to_point < old_from_proj_to_point){
            all_projections.clear(); 
            segments.clear(); 
            parameters.clear();
            all_projections.push_back(temp_projection); 
            old_from_proj_to_point = from_proj_to_point;
        }
        else if (abs(from_proj_to_point - old_from_proj_to_point) < ACCUR){
            all_projections.push_back(temp_projection); 
            segments.push_back(i + 1); 
        }

            
    }
    cout << "Projection:\n"; 
    for (size_t i = 0; i < all_projections.size(); ++i){
        cout << "Segment " << segments[i];
        cout << " parameter " << (1.0f - (DIST_BETWEEN(all_projections[i][0], points[segments[i]][0], 
                    all_projections[i][1], points[segments[i]][1],
                    all_projections[i][2], points[segments[i]][2]) / DIST_BETWEEN(points[segments[i] - 1][0], 
                        points[segments[i]][0], points[segments[i] - 1][1], 
                        points[segments[i]][1], points[segments[i]-1][2], 
                        points[segments[i]][2])));
        cout  << " point " << all_projections[i][0] << ' ' << all_projections[i][1] << ' ' 
            << all_projections[i][2] << endl; 
    }
}
/**
 * @brief This main
 * 
 */
int main(int argc, char* argv[]){
    if (argc < 5){
        throw invalid_argument("Error"); 
    }
    Point input_point; 
    double ax; 

    for (int i = 0; i < DIM; ++i){    
        stringstream convert(argv[i + 2]); 
        convert >> ax; 
        input_point[i] = ax; 
    }
    cout << "Point:\n"; 
    input_point.printPoint(); 
    vector<Point> points; 
    string namefile = argv[1]; 
    cout << "Start Read\n";
    read_line(points, namefile); 
    cout << "END Read\n";
    calculate_dims(points, input_point); 

    return 0; 
}
