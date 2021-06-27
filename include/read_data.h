
/**
 * @file read_data.h
 * @brief Read_Data class interface.
 * 
 */
#ifndef READ
#define READ
#include <string>
#include <fstream>
#include <vector>
#include "point.h"
/**
 * @brief Read line from file. 
 * 
 */
class Read_Data
{
public:
    /**
         * @brief Construct a new Read_Data object
         * 
         * @param namefile file name with points
         */
    Read_Data(const std::string &namefile);

    /**
         * @brief open ifstream.
         * 
         * @param namefile file name with points.
         */
    void open(const std::string &namefile);

    /**
         * @brief close if stream.
         * 
         */
    void close();

    /**
         * @brief read point from file and save in @ref line
         * 
         * @param line input line (sequence of points).
         */
    void read_to_line(std::vector<Point> &line);

private:
    std::ifstream file;
};

#endif