#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

int* sortArray(int* arr, int N) {
    int* a = new int[N];
    for (int i = 0; i < N; i++) {
        a[i] = arr[i];
    }
    int min = 0, buf = 0;
    for (int i = 0; i < N; i++) {
        min = i;
        for (int j = i + 1; j < N; j++) min = (a[j] < a[min]) ? j : min;

        if (i != min) {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }
    return a;
}

void arrayToString(int* arr, int n, std::string& s) {
    for (int i = 0; i < n; i++) {
        std::string str = std::to_string(arr[i]);
        if (i == n - 1) {
            s.append(str).append(";\n");
        }
        else {
            s.append(str).append(", ");
        }
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int N = 10;
    std::string arrayStr = "", sortArrayStr = "";
    int arrayNumber[10];
    for (int i = 0; i < N; i++) {
        arrayNumber[i] = rand() % 100;
    }

    int* pArraySort = sortArray(arrayNumber, N);
    arrayToString(arrayNumber, N, arrayStr);
    arrayToString(pArraySort, N, sortArrayStr);

    std::fstream out("SortArrayToTxt.txt", std::ios::out);
    out.write((char*)&arrayStr[0], arrayStr.length());
    out.write((char*)&sortArrayStr[0], sortArrayStr.length());
    out.close();

    std::cout << "Массив успешно отсартирован и сохранен в файл: \"SortArrayToTxt.txt\"...\n";
}