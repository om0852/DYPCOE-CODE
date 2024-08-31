#include <graphics.h>
#include <conio.h>
#include <cmath>
using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = std::max(abs(dx), abs(dy));  // Determine the number of steps

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);  // Plot the pixel
        x += xIncrement;  // Increment the x coordinate
        y += yIncrement;  // Increment the y coordinate
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Example: Draw a line from (100, 200) to (400, 300)
    drawLineDDA(200, 200, 100, 300);
        drawLineDDA(100, 300, 200, 400);
                drawLineDDA(200, 400, 300, 300);
                        drawLineDDA(300, 300, 200, 200);



    getch();
    closegraph();
    return 0;
}
