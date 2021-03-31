
#ifndef PARSE_H
#define PARSE_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream> // std::stringstream
#include <memory>

/*static functions to help parse CSV data */

/* helper to strip out quotes from a string */
std::string stripQuotes(std::string temp) ;

/* helper: get field from string stream */
/* assume field has quotes for CORGIS */
std::string getField(std::stringstream &ss);

/* helper: read out column names for CSV file */
void consumeColumnNames(std::ifstream &myFile);

//read from a CSV file (for a given data type) return a vector of the data
void read_csv(std::string filename, std::vector<std::string>& theCounties, std::vector<double>& thePopOver65);

// Read one line from a CSV file for county demographic data specifically
void readCSVLineDemog(std::string theLine, std::vector<std::string>& theCounties, std::vector<double>& thePopOver65);



#endif