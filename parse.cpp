#include <algorithm>
#include <iostream>
/* helper routines to read out csv data */
#include "parse.h"

using namespace std;

/* helper to strip out quotes from a string */
string stripQuotes(std::string temp) {
    temp.erase(
        remove(temp.begin(), temp.end(), '\"' ),
        temp.end());
    return temp;
}

/* helper: get field from string stream */
/* assume field has quotes for CORGIS */
string getField(std::stringstream &ss) {
    string data, junk;
    //ignore the first quotes
    std::getline(ss, junk, '\"');
    //read the data (not to comma as some data includes comma (Hospital names))
    std::getline(ss, data, '\"');
    //read to comma final comma (to consume and prep for next)
    std::getline(ss, junk, ',');
    //data includes final quote (see note line 18)
    return stripQuotes(data);
}

/* helper: read out column names for CSV file */
void consumeColumnNames(std::ifstream &myFile) {
    std::string line;
    std::string colname;

    // Extract the first line in the file
    std::getline(myFile, line);

    // Create a stringstream from line
    std::stringstream ss(line);

    // Read the column names (for debugging)
    // Extract each column name for debugging
    while(std::getline(ss, colname, ',')) {
        //print out left as debug
        //cout << colname << endl;
    }
}

/* Read one line from a CSV file for county demographic data specifically
   TODO: for lab01 you will be asked to add fields here - think about type */
void readCSVLineDemog(std::string theLine, vector<string>& theCounties, vector<double>& thePopOver65) {
    std::stringstream ss(theLine);
    
    string name = getField(ss);
    string state = getField(ss);
    double popOver65 = stod(getField(ss));
    double popUnder18 = stod(getField(ss));
    double popUnder5 = stod(getField(ss));

    theCounties.push_back(name);
    thePopOver65.push_back(popOver65);
}


//read from a CSV file into parallel vectors
void read_csv(std::string filename, vector<string>& theCounties, vector<double>& thePopOver65) {

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    if(myFile.good()) {
        consumeColumnNames(myFile);

        // Helper vars
        std::string line;

        // Now read data, line by line and create demographic dataobject
        while(std::getline(myFile, line)) {
            readCSVLineDemog(line, theCounties, thePopOver65);

        }

        // Close file
        myFile.close();
    }
}
