#include <iostream>
#include <Windows.h>

double calcCR1(double a)
{
	return pow(a, (1. / 3.));
}

double calcCR2(double a)
{
	double x = a;
	double x1 = 0;
	while (abs(x - x1) > 0.0000001)
	{
		x1 = x;
		x = ((a / pow(x1, 2)) + 2 * x1) / 3;
	}
	return x;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	double a;
	std::cout << "Введите число для извлечения кубического корня: ";
	std::cin >> a;
	std::cout << "При решении Первым способом был получен ответ: " << calcCR1(a) << std::endl;
	std::cout << "При решении Вторым способом был получен ответ: " << calcCR2(a);
	return 0;
}