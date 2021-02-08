#include "helper.h"

bool insideConvexShape(Point2D point, const std::vector<Line2D> &lines) {
    int side = sign(vee(lines.front(), point));
    auto size = lines.size();
    for (int i = 1; i < size; i++) {
        Line2D line = lines[i];
        int tempSide = sign(vee(line, point));
        if (side != tempSide) {
            return false;
        }
    }
    return true;
}


PointStats pointStats(Point2D p, const std::vector<Point2D> &points) {
    auto distanceLineSegmentSq = [p](Point2D a, Point2D b) {
        const Line2D line = vee(a, b);
        const Line2D perpLine = dot(line, p);
        const int sideA = sign(vee(a, perpLine));
        const int sideB = sign(vee(b, perpLine));
        const bool intersects = sideA != sideB;
        if (intersects) {
            const float mag = vee(p, line.normalized()); // TODO: any way to not call normalized()...it is inefficient

            const float magSquared = mag * mag;
            return magSquared;
        } else {
            const float distA2 = vee(p, a).magnitudeSqr();
            const float distB2 = vee(p, b).magnitudeSqr();
            const float min = fmin(distA2, distB2);
            return min;
        }
    };

    auto size = points.size();
    float minEdgeDist2 = std::numeric_limits<float>::max();
    float minCornerDist2 = std::numeric_limits<float>::max();
    for (int i = 0; i < size; i++) {
        Point2D a = points[i];

        float cornerDist2 = vee(a, p).magnitudeSqr();
        if (cornerDist2 < minCornerDist2) {
            minCornerDist2 = cornerDist2;
        }

        Point2D b = points[(i + 1) % size]; // So it wraps around
        float lineSegmentDist2 = distanceLineSegmentSq(a, b);
        if (lineSegmentDist2 < minEdgeDist2) {
            minEdgeDist2 = lineSegmentDist2;
        }
    }

    return PointStats{
            .edgeDist2 = minEdgeDist2,
            .cornerDist2 = minCornerDist2
    };

}

