// Copyright 2014 Sirotin Nikita

#include <gtest/gtest.h>
#include <float.h>
#include <math.h>
#include <string>

#include "include/volumefigures.h"

class VolumeTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    Volume vol;
};

TEST_F(VolumeTest, Cube) {
    EXPECT_NEAR(8.0, vol.cube(2.0), 1e-6);
}

TEST_F(VolumeTest, Do_Throw_Exception_When_Volume_Is_Larger_Than_DBL_MAX_Cube) {
    EXPECT_THROW(vol.cube(DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Variable_Is_Less_Than_Zero_Cube) {
    EXPECT_THROW(vol.cube(-1.), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Zero_Cube) {
    EXPECT_THROW(vol.cube(0.), std::string);
}

TEST_F(VolumeTest, Sphere) {
    EXPECT_NEAR(M_PI * 4. / 3., vol.sphere(1.), 1e-6);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_DBL_MAX_Sphere) {
    EXPECT_THROW(vol.sphere(DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Variable_Is_Less_Than_Zero_Sphere) {
    EXPECT_THROW(vol.sphere(-1.), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Zero_Sphere) {
    EXPECT_THROW(vol.sphere(0.), std::string);
}

TEST_F(VolumeTest, Pyramid) {
    EXPECT_NEAR(4., vol.pyramid(3., 4.), 1e-6);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_DBL_MAX_Pyramid) {
    EXPECT_THROW(vol.pyramid(DBL_MAX, DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Variable_Is_Less_Than_Zero_Pyramid_1) {
    EXPECT_THROW(vol.pyramid(-1., 5.), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Variable_Is_Less_Than_Zero_Pyramid_2) {
    EXPECT_THROW(vol.pyramid(1., -5.), std::string);
}


TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Zero_Pyramid) {
    EXPECT_THROW(vol.pyramid(0., 23.), std::string);
}

TEST_F(VolumeTest, Cylinder) {
    EXPECT_NEAR(3. * M_PI, vol.cylinder(3., 1.), 1e-6);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_DBL_MAX_Cylinder) {
    EXPECT_THROW(vol.cylinder(DBL_MAX, DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Variable_Is_Less_Than_Zero_Cylinder_1) {
    EXPECT_THROW(vol.cylinder(-1., 3.), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Variable_Is_Less_Than_Zero_Cylinder_2) {
    EXPECT_THROW(vol.cylinder(1., -3.), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Zero_Cylinder) {
    EXPECT_THROW(vol.cylinder(0., 23.), std::string);
}
