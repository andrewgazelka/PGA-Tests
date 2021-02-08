#pragma once

#include <vector>
#include "multivector.h"
#include "pga.h"

bool insideConvexShape(Point2D point, const std::vector<Line2D>& lines);

struct PointStats {
    float edgeDist2;
    float cornerDist2;
};

PointStats pointStats(Point2D p, const std::vector<Point2D>& points);
