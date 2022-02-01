#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

#include "Human.h"
#include "Student.h"
#include "Teacher.h"

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	std::vector<int> scores;
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);

	Student* student = new Student("Сергей", "Колобков", "Павлович", scores);
	unsigned int teacherWorkTime = 40;
	Teacher* teach = new Teacher("Андрей", "Андреевич", "Михайлович", teacherWorkTime);
	std::vector<Human*> humans;
	humans.push_back(student);
	humans.push_back(teach);
	for (auto var : humans)
	{
		std::cout << var->getFullName() << std::endl;
		std::cout << var->getInfo() << std::endl;
	}

	return 0;
}
