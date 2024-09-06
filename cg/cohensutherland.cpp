#include<iostream>
#include<graphics.h>

// Function to calculate the intersection point
void calculateIntersection(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax, int code, int &x, int &y) {
    if (code == 1) {  // Line is to the left of the rectangle
        y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
        x = xmin;
    }
    else if (code == 2) {  // Line is to the right of the rectangle
        y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
        x = xmax;
    }
    else if (code == 4) {  // Line is above the rectangle
        x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
        y = ymin;
    }
    else if (code == 8) {  // Line is below the rectangle
        x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
        y = ymax;
    }
    return x,y;
}

int main() {
    int code1 = 0, code2 = 0;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xmin = 100, ymin = 100, xmax = 400, ymax = 400;
    rectangle(xmin, ymin, xmax, ymax);

    int x1 = 120, y1 = 120, x2 = 500, y2 = 200;
    line(x1, y1, x2, y2);  // Draw initial line

    // Determine region codes for p1 and p2
    if (x2 < xmin) code2 |= 1;  // Left
    if (x2 > xmax) code2 |= 2;  // Right
    if (y2 < ymin) code2 |= 4;  // Above
    if (y2 > ymax) code2 |= 8;  // Below

    int x, y;

    // Clear the screen before drawing the second line
    delay(1000);
    cleardevice();
    rectangle(xmin, ymin, xmax, ymax);  // Redraw the rectangle

    // Calculate the new intersection point for p2
    if (code2 != 0) {
        calculateIntersection(x1, y1, x2, y2, xmin, ymin, xmax, ymax, code2, x, y);
        line(x1, y1, x, y);  // Draw the line after clipping
    } else {
        line(x1, y1, x2, y2);  // If p2 is inside, draw the original line
    }

    delay(10000);
    closegraph();
    return 0;
}
