#include <Windows.h>
#include <iostream>

int calcRQE(double, double, double, double&, double&);
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	double a, b, c, x1, x2;
	std::cout << "Для расчета корней квадратного уравнения введите аргументы:\n";
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	std::cout << "c = ";
	std::cin >> c;

	switch (calcRQE(a, b, c, x1, x2))
	{
	case 1:
		std::cout << "x1 = " << x1 << ", x2 = " << x2; break;
	case 0:
		std::cout << "x1, x2 = " << x1; break;
	case (-1):
		std::cout << "Корней нет."; break;
	}
}

int calcRQE(double a, double b, double c, double& x1, double& x2)
{
	double d = b * b - 4 * a * c, res = -1;
	if (d > 0)
	{
		x1 = ((-1) * b + sqrt(d)) / (2 * a);
		x2 = ((-1) * b - sqrt(d)) / (2 * a);;
		res = 1;
	}
	else if (d == 0)
	{
		x1 = (-1) * b / (2 * a);
		x2 = x1;
		res = 0;
	}
	return res;
}
