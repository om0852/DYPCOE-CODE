#include <iostream>
#include <graphics.h>

using namespace std;

// Define the clipping window boundaries
const int xmin = 100, xmax = 400, ymin = 100, ymax = 400;

// Define the outcode constants
const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, INSIDE = 0;

// Function to compute the outcode for a point
int computeOutcode(int x, int y) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    if (y > ymax) code |= TOP;
    return code;
}

// Cohen-Sutherland line clipping algorithm
void cohenSutherlandClip(int &x1, int &y1, int &x2, int &y2) {
    int outcode1 = computeOutcode(x1, y1);
    int outcode2 = computeOutcode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(outcode1 | outcode2)) {
            // Both points inside
            accept = true;
            break;
        } else if (outcode1 & outcode2) {
            // Both points outside
            break;
        } else {
            int outcodeOut = outcode1 ? outcode1 : outcode2;
            int x, y;

            // Find intersection point
            if (outcodeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (outcodeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (outcodeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (outcodeOut & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // Replace outside point with intersection point
            if (outcodeOut == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = computeOutcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = computeOutcode(x2, y2);
            }
        }
    }

    if (accept) {
        // Draw the line if it is accepted
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw the clipping window
    rectangle(xmin, ymin, xmax, ymax);

    // Define the line endpoints
    int x1 = 200, y1 = 200, x2 = 500, y2 = 200;

    // Clip the line using Cohen-Sutherland algorithm
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    delay(10000);
    closegraph();

    return 0;
}
