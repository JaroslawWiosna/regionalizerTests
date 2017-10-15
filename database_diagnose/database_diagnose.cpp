/**
 * @file cities_data.txt
 *
 * @author Jaroslaw Wiosna
 * @author Wojciech Mielczarek
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include <gtest/gtest.h>
#include <cmath>

std::size_t database_diagnose(uint8_t option_to_return) {
    std::string input;
    std::ifstream cities_data;
    std::size_t cities_number=0;
    std::size_t pipe_occurances=0;
    bool same=false;
    try {
          cities_data.open("../../../database/cities_data",std::ios::in);
    }
    catch (const std::ifstream::failure& e) {
        std::cerr << "Error: File not found\n";
        exit(-1);
    }
    while(!cities_data.eof()) {
        std::getline(cities_data,input);
        pipe_occurances += std::count(input.begin(),input.end(),'|');
        if(input.find("Warszawa")!=std::string::npos) {
            same = input.compare("Warszawa|517,24|1753977|52.2|21.0333") ? false:true;
        }
        cities_number++;
    }
    cities_data.close();
    switch(option_to_return) {
        case 0: {
            return same;
        }
        case 1: {
            return (pipe_occurances+4)/cities_number;
        }
        case 2: {
            if(cities_number>=200){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return 0;
}

TEST(Database, common_database_tests)
{
    ASSERT_EQ(4, database_diagnose(0)) << "expects to have a 4 pipes in each city line";
    ASSERT_EQ(true, database_diagnose(1)) << "expects a database info for Warsaw to be as tested string";
    ASSERT_EQ(true, database_diagnose(2)) << "expects that the list contains at least 200 cities";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
