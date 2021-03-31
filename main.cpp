#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "parse.h"

using namespace std;

int main() {
    //store the county names 
    vector<string> theCounties;
    //store the associated percentage of the population over 65
    vector<double> percentPopOver65;

    read_csv("county_demographics.csv", theCounties, percentPopOver65);

    //print out the first 50 peices of data we read in
    for (int i=0; i < 50; i++) {
        cout << "County: " << theCounties.at(i);
        cout << " Percent population over 65: " << percentPopOver65.at(i) << endl;
    }

	 cout << "There are " << theCounties.size() << " counties in data set." << endl;

    return 0;
}

