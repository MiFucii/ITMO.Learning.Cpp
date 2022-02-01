#include <Windows.h>
#include <iostream>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int cost, k5k = 0, k2k = 0, k1k = 0, k5 = 0, k2 = 0, k1 = 0, k05 = 0, m10 = 0, m5 = 0, m2 = 0, m1 = 0;

    std::cout << "Введите сумму, которую необходимо разминять: ";
    std::cin >> cost;

    while (cost > 0)
    {
        if (cost >= 5000) { k5k++; cost -= 5000; continue; }
        if (cost >= 2000) { k2k++; cost -= 2000; continue; }
        if (cost >= 1000) { k1k++; cost -= 1000; continue; }
        if (cost >= 500) { k5++; cost -= 500; continue; }
        if (cost >= 200) { k2++; cost -= 200; continue; }
        if (cost >= 100) { k1++; cost -= 100; continue; }
        if (cost >= 50) { k05++; cost -= 50; continue; }
        if (cost >= 10) { m10++; cost -= 10; continue; }
        if (cost >= 5) { m5++; cost -= 5; continue; }
        if (cost >= 2) { m2++; cost -= 2; continue; }
        if (cost >= 1) { m1++; cost -= 1; }
    }
    std::cout << "Вы получили:\nКупюр номиналом 5000р: " << k5k << "\nКупюр номиналом 2000р: " << k2k << "\nКупюр номиналом 1000р: " << k1k
        << "\nКупюр номиналом 500р: " << k5 << "\nКупюр номиналом 200р: " << k2 << "\nКупюр номиналом 100р: " << k1
        << "\nКупюр номиналом 50р: " << k05 << "\nМонет номиналом 10р: " << m10 << "\nМонет номиналом 5р: " << m5
        << "\nМонет номиналом 2р: " << m2 << "\nМонет номиналом 1р: " << m1;
    return 0;
}
