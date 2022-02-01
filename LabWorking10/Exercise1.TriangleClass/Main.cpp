#include <Windows.h>
#include <iostream>
#include <tuple>

class Dot
{
private:
	double x;
	double y;
public:
	Dot()
	{
		x = 0; y = 0;
	}
	~Dot()
	{
		std::cout << "Точка: x - " << x << ", y - " << y << " выгружена из памяти.\n";
	}
	Dot(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double distanceTo(Dot point)
	{
		return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
	}
};

class Triangle
{
private:
	double a;
	double b;
	double c;
public:
	Dot* d1;
	Dot* d2;
	Dot* d3;
	//Dot& d1;
	//Dot& d2;
	//Dot& d3;

	Triangle(Dot& a, Dot& b, Dot& c) //: d1(a), d2(b), d3(c)
	{
		d1 = new Dot(a);
		d2 = new Dot(b);
		d3 = new Dot(c);
		this->a = a.distanceTo(b);
		this->b = b.distanceTo(c);
		this->c = c.distanceTo(a);
	}

	Triangle(Dot* a, Dot* b, Dot* c) : d1(a), d2(b), d3(c) { }

	~Triangle()
	{
		if (d1) delete d1;
		if (d2) delete d2;
		if (d3) delete d3;
		std::cout << "Треугольник выгружен из памяти.\n";
	}

	std::tuple<double, double, double> getSides()
	{
		return std::make_tuple(a, b, c);
	}
	double calcPerimeter()
	{
		return a + b + c;
	}
	double calcArea()
	{
		double halfP = (a + b + c) / 2;
		return sqrt((halfP * (halfP - a) * (halfP - b) * (halfP - c)));
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Dot* a = new Dot(1, 5);
	Dot* b = new Dot(2, 7);
	Dot* c = new Dot(4, 9);

	//Dot a(1, 5);
	//Dot b(2, 7);
	//Dot c(4, 9);

	Triangle* triangle = new Triangle(a, b, c);
	delete triangle;
}

