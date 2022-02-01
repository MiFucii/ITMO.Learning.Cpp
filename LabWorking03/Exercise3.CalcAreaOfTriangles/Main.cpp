#include <Windows.h>
#include <iostream>

double calcAreaTriang(int a)
{
	double p = (3. * a) / 2.;
	double S = sqrt(p * pow((p - a), 3));
	return S;
}
double calcAreaTriang(int a, int b, int c)
{
	double p = ((double)a + (double)b + (double)c) / 2.;
	double S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	int chose;
	std::cout << "Пожалуйста, выберите площадь какого треугольник вы хотите рассчитать?:\n1 - Равносторонний\n2 - Разносторонний\n";
	std::cin >> chose;
	int a, b, c;

	switch (chose)
	{
	case 1:	
		std::cout << "Введите сторону треугольника: ";
		std::cin >> a;
		std::cout << "Площадь равностороннего треугольника равна: " << calcAreaTriang(a);
		break;
	case 2:
		std::cout << "Введите все стороны треугольника попорядку:\n";
		std::cin >> a >> b >> c;
		std::cout << "Площадь разностороннего треугольника равна: " << calcAreaTriang(a, b, c);
		break;
	default:
		std::cout << "Ошибка выбора!";
	}
	return 0;
}