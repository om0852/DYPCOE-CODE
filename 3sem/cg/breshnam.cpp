#include <graphics.h>
#include <conio.h>
#include <cmath>
using namespace std;


void drawCircle(int xc, int yc, int x, int y){
    putpixel(xc+x, yc+y, 2);
    putpixel(xc-x, yc+y, 2);
    putpixel(xc+x, yc-y, 2);
    putpixel(xc-x, yc-y, 2);
    putpixel(xc+y, yc+x, 2);
    putpixel(xc-y, yc+x, 2);
    putpixel(xc+y, yc-x, 2);
    putpixel(xc-y, yc-x, 2);
}


void draw_circle(int xinc,int yinc,int r){
	int x=0,y=r;
	int d = 3-2*r;
	drawCircle(xinc,yinc,x,y);
	while(x<=y){
		if(d<0){
			d=d+4*x+6;
		}
		else{
			d=d+4*(x-y)+10;
			y--;
		}
		x++;
		        drawCircle(xinc, yinc, x, y);
        delay(50);

	}
	
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Example: Draw a line from (100, 200) to (400, 300)
draw_circle(200,300,70);



    getch();
    closegraph();
    return 0;
}
