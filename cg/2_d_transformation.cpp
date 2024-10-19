#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265

class Translate {
public:
    int tx, ty;
    Translate(int x, int y) {
        tx = x;
        ty = y;
    }
};

class Rotate {
public:
    float deg;
    Rotate(float angle) {
        deg = angle;
    }
};

class Scale {
public:
    int sx, sy;
    Scale(int x, int y) {
        sx = x;
        sy = y;
    }
};

class Rectangle {
public:
    int x1, y1, x2, y2;
    Rectangle() {
        x1 = 100;
        y1 = 100;
        x2 = 400;
        y2 = 400;
    }

    Rectangle(int x_1, int y_1, int x_2, int y_2) {
        x1 = x_1;
        y1 = y_1;
        x2 = x_2;
        y2 = y_2;
    }

    Rectangle operator+(const Translate& t) {
        Rectangle r3;
        r3.x1 = x1 + t.tx;
        r3.y1 = y1 + t.ty;
        r3.x2 = x2 + t.tx;
        r3.y2 = y2 + t.ty;
        return r3;
    }

    Rectangle operator*(const Scale& s) {
        Rectangle r;
        r.x1 = x1;
        r.y1 = y1;
        r.x2 = x2 * s.sx;
        r.y2 = y2 * s.sy;
        return r;
    }

    Rectangle operator^(const Rotate& d) {
        Rectangle r;
	 float radians = d.deg*PI/180;
	double c = cos(radians);
	double s = sin(radians);
	  cout<<c<<endl<<s<<endl;
	int newX1 = abs(x1 * c - y2 * s);
	int newY1 = abs(x1 * s + y2 * c);
	int newX2 = abs(x2 * c - y1 * s);
	int newY2 = abs(x2 * s + y1 * c);
cout<<newX1<<endl<<newY1<<endl<<newX2<<endl<<newY2;
	r.x1 = newX1;
	r.y1 = newY1;
	r.x2 = newX2;
	r.y2 = newY2;
	return r;
    }

    void draw() {
	rectangle(x1, y1, x2, y2);
    }
};

int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

    Rectangle r1(200, 200, 300, 300);
r1.draw();
    Translate t1(30, 30);
    Rectangle r2 = r1 + t1;

    Scale s(2, 2);
    Rectangle r3 = r2 * s;

    Rotate d(60);
    Rectangle r4 = r1 ^ d;

    r4.draw();

    getch();
    closegraph();

    return 0;
}
