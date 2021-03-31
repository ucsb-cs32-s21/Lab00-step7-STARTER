
#include <iostream>
#include <vector>
#include "tddFuncs.h"
#include "parse.h"
using namespace std;

int main() {
  cout << "Testing county population data:" << endl;

  //store the county names 
  vector<string> theCounties;
  //store the associated percentage of the population over 65
  vector<double> percentPopOver65;
   //store the associated percentage of the population under 18
  vector<double> percentPopUnder18;

  read_csv("county_demographics.csv", theCounties, percentPopOver65);
  //read_csv("county_demographics.csv", theCounties, percentPopOver65, percentPopUnder18);

  ASSERT_EQUALS("Baldwin County",theCounties.at(1));
  ASSERT_EQUALS(18.7, percentPopOver65.at(1));
  //ASSERT_EQUALS(0,percentPopUnder18.at(1));

  return 0;
}
