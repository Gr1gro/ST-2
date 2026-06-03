// Copyright 2025 UNN-CS

#include <gtest/gtest.h>

#include "circle.h"
#include "tasks.h"

static const double EPS = 1e-6;
static const double PI = 3.14159265358979323846;

TEST(CircleConstructorTest, RadiusIsSetCorrectly) {
    Circle circle(5.0);

    EXPECT_NEAR(circle.getRadius(), 5.0, EPS);
}

TEST(CircleConstructorTest, FerenceIsCalculatedCorrectly) {
    Circle circle(1.0);

    EXPECT_NEAR(circle.getFerence(), 2 * PI, EPS);
}

TEST(CircleConstructorTest, AreaIsCalculatedCorrectly) {
    Circle circle(1.0);

    EXPECT_NEAR(circle.getArea(), PI, EPS);
}

TEST(CircleGetterTest, GetRadiusReturnsCurrentRadius) {
    Circle circle(7.5);

    EXPECT_NEAR(circle.getRadius(), 7.5, EPS);
}

TEST(CircleGetterTest, GetFerenceReturnsCurrentFerence) {
    Circle circle(2.0);

    EXPECT_NEAR(circle.getFerence(), 4 * PI, EPS);
}

TEST(CircleGetterTest, GetAreaReturnsCurrentArea) {
    Circle circle(2.0);

    EXPECT_NEAR(circle.getArea(), 4 * PI, EPS);
}

TEST(CircleSetRadiusTest, RadiusChangesCorrectly) {
    Circle circle(1.0);

    circle.setRadius(10.0);

    EXPECT_NEAR(circle.getRadius(), 10.0, EPS);
}

TEST(CircleSetRadiusTest, FerenceChangesAfterRadius) {
    Circle circle(1.0);

    circle.setRadius(2.0);

    EXPECT_NEAR(circle.getFerence(), 4 * PI, EPS);
}

TEST(CircleSetRadiusTest, AreaChangesAfterRadius) {
    Circle circle(1.0);

    circle.setRadius(2.0);

    EXPECT_NEAR(circle.getArea(), 4 * PI, EPS);
}

TEST(CircleSetRadiusTest, ZeroRadiusIsSupported) {
    Circle circle(5.0);

    circle.setRadius(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, EPS);
    EXPECT_NEAR(circle.getFerence(), 0.0, EPS);
    EXPECT_NEAR(circle.getArea(), 0.0, EPS);
}

TEST(CircleSetFerenceTest, FerenceChangesCorrectly) {
    Circle circle(1.0);

    circle.setFerence(10.0);

    EXPECT_NEAR(circle.getFerence(), 10.0, EPS);
}

TEST(CircleSetFerenceTest, RadiusChangesAfterFerence) {
    Circle circle(5.0);

    circle.setFerence(2 * PI);

    EXPECT_NEAR(circle.getRadius(), 1.0, EPS);
}

TEST(CircleSetFerenceTest, AreaChangesAfterFerence) {
    Circle circle(5.0);

    circle.setFerence(2 * PI);

    EXPECT_NEAR(circle.getArea(), PI, EPS);
}

TEST(CircleSetFerenceTest, ZeroFerenceIsSupported) {
    Circle circle(5.0);

    circle.setFerence(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, EPS);
    EXPECT_NEAR(circle.getFerence(), 0.0, EPS);
    EXPECT_NEAR(circle.getArea(), 0.0, EPS);
}

TEST(CircleSetAreaTest, AreaChangesCorrectly) {
    Circle circle(1.0);

    circle.setArea(25.0);

    EXPECT_NEAR(circle.getArea(), 25.0, EPS);
}

TEST(CircleSetAreaTest, RadiusChangesAfterArea) {
    Circle circle(5.0);

    circle.setArea(PI);

    EXPECT_NEAR(circle.getRadius(), 1.0, EPS);
}

TEST(CircleSetAreaTest, FerenceChangesAfterArea) {
    Circle circle(5.0);

    circle.setArea(PI);

    EXPECT_NEAR(circle.getFerence(), 2 * PI, EPS);
}

TEST(CircleSetAreaTest, ZeroAreaIsSupported) {
    Circle circle(5.0);

    circle.setArea(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, EPS);
    EXPECT_NEAR(circle.getFerence(), 0.0, EPS);
    EXPECT_NEAR(circle.getArea(), 0.0, EPS);
}

TEST(CircleRecalculationTest, RadiusToFerenceAndBack) {
    Circle circle(5.0);

    const double ference = circle.getFerence();
    circle.setFerence(ference);

    EXPECT_NEAR(circle.getRadius(), 5.0, EPS);
}

TEST(CircleRecalculationTest, RadiusToAreaAndBack) {
    Circle circle(5.0);

    const double area = circle.getArea();
    circle.setArea(area);

    EXPECT_NEAR(circle.getRadius(), 5.0, EPS);
}

TEST(EarthRopeTaskTest, GapIsCorrect) {
    EXPECT_NEAR(earthRopeGap(), 1.0 / (2 * PI), EPS);
}

TEST(PoolTaskTest, ConcreteCostIsCorrect) {
    EXPECT_NEAR(poolConcreteCost(), 7 * PI * 1000, EPS);
}

TEST(PoolTaskTest, FenceCostIsCorrect) {
    EXPECT_NEAR(poolFenceCost(), 8 * PI * 2000, EPS);
}

TEST(PoolTaskTest, TotalCostIsCorrect) {
    EXPECT_NEAR(poolTotalCost(), 7 * PI * 1000 + 8 * PI * 2000, EPS);
}

TEST(PoolTaskTest, TotalCostEqualsConcretePlusFence) {
    EXPECT_NEAR(poolTotalCost(), poolConcreteCost() + poolFenceCost(), EPS);
}


