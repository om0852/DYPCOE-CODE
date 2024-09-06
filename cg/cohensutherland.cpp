#include<iostream>
#include<graphics.h>

int checker(int x2, int y2, int xmin, int xmax, int ymin, int ymax) {
    int code2 = 0;
    if (x2 < xmin) code2 |= 1;  // Left
    if (x2 > xmax) code2 |= 2;  // Right
    if (y2 < ymin) code2 |= 4;  // Above
    if (y2 > ymax) code2 |= 8;  // Below
    return code2;
}

void calculateIntersection(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax, int code, int &x, int &y) {
    if (code == 1) {  
        y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
        x = xmin;
    }
    else if (code == 2) {  
        y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
        x = xmax;
    }
    else if (code == 4) {  
        x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
        y = ymin;
    }
    else if (code == 8) {  
        x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
        y = ymax;
    }
}

int main() {
    int code1 = 0, code2 = 0;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xmin = 100, ymin = 100, xmax = 400, ymax = 400;
    rectangle(xmin, ymin, xmax, ymax);

    int x1 = 0, y1 = 20, x2 = 300, y2 = 10;
    line(x1, y1, x2, y2);

    code1 = checker(x1, y1, xmin, xmax, ymin, ymax);
    code2 = checker(x2, y2, xmin, xmax, ymin, ymax);

    int x, y;
    delay(1000);
    cleardevice();
    rectangle(xmin, ymin, xmax, ymax);

    if (code1 != 0) {
        calculateIntersection(x1, y1, x2, y2, xmin, ymin, xmax, ymax, code1, x1, y1);
    }

    if (code2 != 0) {
        calculateIntersection(x1, y1, x2, y2, xmin, ymin, xmax, ymax, code2, x2, y2);
    }

    line(x1, y1, x2, y2);

    delay(10000);
    closegraph();
    return 0;
}
