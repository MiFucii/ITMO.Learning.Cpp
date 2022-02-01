#include <Windows.h>
#include <iostream>

int* getRandomArray(const int size)
{
	srand(time(NULL));

	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = 1 + rand() % 10;
	}
	return arr;
}

void printArray(const int size, int* arr) {
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int sumArray(const int size, int* arr)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}


void sortArray(const int size, int* arr)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	int size = 10;
	int* arr = getRandomArray(size);

	std::cout << "Получен случайный массив: ";
	printArray(size, arr);

	std::cout << "\nСумма чисел в массиве: " << sumArray(size, arr) << std::endl;
	
	std::cout << "Отсортированный исходный массив: ";
	sortArray(size, arr);
	printArray(size, arr);
}

