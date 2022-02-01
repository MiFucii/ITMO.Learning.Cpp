#include <Windows.h>
#include <iostream>

template<typename T>
double averageArray(T arr[], int size)
{
	T sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return (double)sum / size;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int intArray[] = { 4, 12, 5, 7, 9, 11, 2, 0 };
	long longArray[] = { 3654, 1733, 8742, 9234, 2324};
	double doublArray[] = { 4.3, 6.1, 34,23, 2.2, 3.01, 7.201 };
	char charArray[] = "This is char array!";

	int sIA = sizeof(intArray) / sizeof(intArray[0]);
	int sLA = sizeof(longArray) / sizeof(longArray[0]);
	int sDA = sizeof(doublArray) / sizeof(doublArray[0]);
	int sCA = sizeof(charArray) / sizeof(charArray[0]) - 1;

	std::cout << "Cреднее арифметическое массива целых чисел: " << averageArray(intArray, sIA) << std::endl;
	std::cout << "Cреднее арифметическое массива больших чисел: " << averageArray(longArray, sLA) << std::endl;
	std::cout << "Cреднее арифметическое массива чисел с плавующей точкой: " << averageArray(doublArray, sDA) << std::endl;
	std::cout << "Cреднее арифметическое массива символов: " << averageArray(charArray, sCA);
	return 0;
}

