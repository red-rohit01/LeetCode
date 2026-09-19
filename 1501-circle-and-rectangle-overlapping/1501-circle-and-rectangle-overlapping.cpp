class Solution {
public:
    // If that single closest point lies inside the circle, the two shapes overlap. If even the closest point is too far away, nothing else can be closer so they don't.

    // Case A : center is inside the range: the closest x is the center's own x.

    // Case B : center is to the left: the closest x is the left edge.

    //  Case C : center is to the right: the closest x is the right edge.
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point of rectangle to circle center
        int closestX=max(x1, min(xCenter, x2));
        int closestY=max(y1, min(yCenter, y2));

        // Calculate squared distance
        int dx=xCenter - closestX;
        int dy=yCenter - closestY;

        // Check if closest point is inside/on circle
        return (dx*dx + dy*dy)<=(radius*radius);
    }
};