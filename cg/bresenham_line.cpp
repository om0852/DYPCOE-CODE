#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>


void bres_line(int x1,int y1,int x2,int y2){
	int x,y,dx,dy,p;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	p=2*(dy-dx);
	x=x1;
	y=y1;
			putpixel(x,y,WHITE);

	for(int i=0;i<=dx;i++){
		putpixel(x,y,2);
		while(p>=0){
			y++;
			p=p-2*dx;
					putpixel(x,y,WHITE);

		}
			x++;
			p=p+2*dy;
		
	}

	
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

bres_line(100,100,400,100); 

    delay(5000);
    closegraph();
    return 0;
}
