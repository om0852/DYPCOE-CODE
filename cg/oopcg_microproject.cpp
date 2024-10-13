#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawBoat(int x, int y) {
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);

    line(x, y, x + 300, y);
    line(x , y , x + 100, y + 100);
    line(x+300, y, x + 200, y + 100);
    line(x + 100, y+100, x+200 , y + 100);

    int boatBase[] = {x, y, x + 300, y , x + 200, y + 100, x + 200, y+100, x+100, y+100};
    fillpoly(5, boatBase);

    setcolor(WHITE);

    line(x+100, y, x+100, y-100);
    line(x+100, y-100, x+120, y-80);
    line(x+120, y-80, x+100, y-60);
    
    setcolor(BLUE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 0, y = 300;

    while (!kbhit()) {
        cleardevice();

        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        bar(0, y + 20, getmaxx(), getmaxy());

        drawBoat(x, y);

        x += 5;

        if (x > getmaxx()) {
            x = -100;
        }

        delay(100);
    }

    closegraph();
    return 0;
}

