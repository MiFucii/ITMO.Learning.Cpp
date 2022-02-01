#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <math.h>

class Point
{
private:
	double x;
	double y;
public:
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	double getX() { return x; }
	double getY() { return y; }

	double distToCentre()
	{
		return sqrt(pow(x - 0, 2) + pow(y - 0, 2));
	}

	bool operator<(Point& p)
	{
		return distToCentre() < p.distToCentre();
	}	
};

	std::ostream& operator<<(std::ostream& out, Point& p)
	{
		out << "{" << p.getX() << ", " << p.getY() << "}";
		return out;
	}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::vector<Point> v;

	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));

	std::sort(v.begin(), v.end());
	for (auto& point : v)
		std::cout << point << '\n';

	return 0;
}