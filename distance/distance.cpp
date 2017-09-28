/**
 * @file cppVersion.cpp
 *
 * @author Jaroslaw Wiosna
 * @author Wojciech Mielczarek
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include <gtest/gtest.h>
#include <cmath>
#include "Coordinates.hpp"

TEST(Distance, dummyDistanceTestfromLodzToWarsaw)
{
    // A - Lodz
    // B - Warsaw
    double Alat = 51.75; //51deg 46' 36''
    double Alon = 19.49; //19deg 27' 17''
    double Blat = 51.24; // 51deg 13' 56''
    double Blon = 21.01; //21deg 00' 30''

    constexpr double R = 6371; // 6371000?
    Alat = Alat * 3.14 / 180.0; // to_radians
    Alon = Alon * 3.14 / 180.0; // to_radians
    Blat = Blat * 3.14 / 180.0; // to_radians
    Blon = Blon * 3.14 / 180.0; // to_radians
    double deltaLat = Blat - Alat;
    double deltaLon = Blon - Alon;

    double a = pow(sin(0.5 * deltaLat),2) + cos(Alat) * cos(Blat) * pow(sin(0.5 * deltaLon),2);
    double c = 2 * atan2(sqrt(a),sqrt(1-a));
    double d = R * c;

    ASSERT_TRUE( 0.8 > fabs(d - 119.0));
}

TEST(Distance, dummyCoordinatesObject)
{
    geo_location Lodz_lat{20,0,0,0};
    geo_location Lodz_lon{20,0,0,0};
    Coordinates Lodz{Lodz_lat,Lodz_lon};
    ASSERT_TRUE(true);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
