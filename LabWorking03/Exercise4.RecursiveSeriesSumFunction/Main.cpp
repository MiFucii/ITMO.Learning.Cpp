#include <Windows.h>
#include <iostream>

int rowSum(int repet)
{
	if (repet <= 0)
	{
		return 0;
	}
	else
		return (5 * repet + rowSum(repet - 1));
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	int nubmberRepete;
	std::cout << "Введите кол-во элементов для расчета суммы ряда: ";
	std::cin >> nubmberRepete;
	std::cout << "S = " << rowSum(nubmberRepete);
	return 0;
}

