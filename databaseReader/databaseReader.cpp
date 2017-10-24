/**
 * @file databaseReader.cpp
 *
 * @author Jaroslaw Wiosna
 * @author Wojciech Mielczarek
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "DatabaseReader.hpp"
#include <cmath>
#include <gtest/gtest.h>

TEST(DatabaseReader, dummyTest) {
    std::string path = "../../../database/Poland-Cities010-Top10-mock.txt";
    auto vec = DatabaseReader::readCitiesFromFile(path);

    ASSERT_EQ(10, vec.size());
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
