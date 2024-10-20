#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

int checker(int x,int y,int xmin,int ymin,int xmax,int ymax){
int code;
       if(x<xmin){
	 code=1;
       }
       else if(x>xmax){
       code=2;
       }
       else if(y<ymin){
       code = 4;
       }
       else if(y>ymax){
	code =8;
       }
       else{


       }

       return code;
}

int main(){
int gdriver = DETECT,gmode ,errorcode;
initgraph(&gdriver,&gmode,"C:\\turboc3\\bgi");
int x1=20,y1=40,x2=100,y2=300;
int xmin=30,ymin=30,xmax=400,ymax=400;
rectangle(xmin,ymin,xmax,ymax);
line(x1,y1,x2,y2);
 int code = checker(x1,y1,xmin,ymin,xmax,ymax);
 int m=(y2-y1)/(x2-x1);
if(code==1){
x1=xmin;
y1=y1+(xmin-x1)*m;
}
else if(code ==2){
y1=y1+(xmax-x1)*m;
x1=xmax;


}
else if(code ==4){
 x1 = x1+(ymax-y1)/m;
 y1=ymax;
}
else{
x1 =x1+(ymin-y1)/m;
y1=ymin;
}
getch();
clrscr();
rectangle(xmin,ymin,xmax,ymax);
line(x1,y1,x2,y2);

		 getch();
		 closegraph();
		 return 0;
}