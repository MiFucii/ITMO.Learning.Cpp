#include <Windows.h>
#include <iostream>
#include <string>


bool Input(int& a, int& b)
{
    std::string aStr, bStr;
    bool flag = true;
    std::cout << "Введите a: ";
    std::cin >> aStr;
    std::cout << "\nВведите b: ";
    std::cin >> bStr;

    for (char var : aStr)
    {
        if (!isdigit(var))
        {
            flag = false; 
            break;
        }
    }
    for (char var : bStr)
    {
        if (!isdigit(var))
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        a = stoi(aStr);
        b = stoi(bStr);
    }
    return flag;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int a, b;
	if (Input(a, b) == false)
	{
		std::cerr << "error";
		return 1;
	}
	int s = a + b;
    std::cout << s;
	return 0;

}

