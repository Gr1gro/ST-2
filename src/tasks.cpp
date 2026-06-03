// Copyright 2025 UNN-CS

#include "tasks.h"

#include "circle.h"

double earthRopeGap() {
    const double earthRadius = 6378.1 * 1000;
    const double addedRopeLength = 1.0;

    Circle earth(earthRadius);
    Circle rope(earthRadius);
    rope.setFerence(earth.getFerence() + addedRopeLength);

    return rope.getRadius() - earth.getRadius();
}

double poolConcreteCost() {
    const double poolRadius = 3.0;
    const double pathWidth = 1.0;
    const double concretePrice = 1000.0;

    Circle inner(poolRadius);
    Circle outer(poolRadius + pathWidth);

    return (outer.getArea() - inner.getArea()) * concretePrice;
}

double poolFenceCost() {
    const double outerRadius = 4.0;
    const double fencePrice = 2000.0;

    Circle outer(outerRadius);

    return outer.getFerence() * fencePrice;
}

double poolTotalCost() {
    return poolConcreteCost() + poolFenceCost();
}
