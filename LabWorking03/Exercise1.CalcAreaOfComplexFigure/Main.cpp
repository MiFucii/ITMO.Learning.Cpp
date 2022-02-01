#include <iostream>
#include <Windows.h>

struct Point {
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

double getSideOfATriangle(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double calcAreaTriangle(Point A, Point B, Point C) {
	double ab = getSideOfATriangle(A, B);
	double ac = getSideOfATriangle(A, C);
	double bc = getSideOfATriangle(B, C);
	double halfP = (ab + ac + bc) / 2;
	return sqrt((halfP * (halfP - ab) * (halfP - ac) * (halfP - bc)));
}

double calcACF(Point A, Point B, Point C, Point D, Point E) {
	double abe = calcAreaTriangle(A, B, E);
	double bde = calcAreaTriangle(B, D, E);
	double bcd = calcAreaTriangle(B, C, D);
	return abe + bde + bcd;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Point A(1, 1);
	Point B(3, 8);
	Point C(10, 10);
	Point D(6, 15);
	Point E(1, 13);
	double area = calcACF(A, B, C, D, E);
	std::cout << "Площадь этой фигуры равна: " << area;
}