#include <Windows.h>
#include <iostream>
#include "Map"
#include <vector>

struct StudentGrade 
{
	std::map<std::string, std::vector<char>> studArrayMark;

	void addStudentMark(std::string name, char mark) 
	{
		if (studArrayMark.find(name) != studArrayMark.cend()) {
			std::vector<char> marks = studArrayMark[name];
			marks.push_back(mark);
			studArrayMark[name] = marks;			
		}
		else studArrayMark[name] = { mark };
	}

	void printAll()
	{
		for (auto stud : studArrayMark)
		{
			std::cout << "Оценки студента " << stud.first << ": ";
			for (auto mark : stud.second)
			{
				std::cout << mark << "; ";
			}
			std::cout << std::endl;
		}
	}
	void printName(std::string name) 
	{
		std::vector<char> student = studArrayMark[name];
		std::cout << "Оценки студента " << name << ": ";
		for (auto mark : student)
		{
			std::cout << mark << "; ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::string name;

	StudentGrade studentGrades;
	studentGrades.addStudentMark("Михаил", '1');
	studentGrades.addStudentMark("Олег", '3');
	studentGrades.addStudentMark("Рауль", '3');
	studentGrades.addStudentMark("Олег", '5');
	studentGrades.addStudentMark("Александр", '2');
	studentGrades.addStudentMark("Олег", '4');
	studentGrades.addStudentMark("Михаил", '3');
	studentGrades.addStudentMark("Рауль", '5');


	studentGrades.printAll();
	std::cout << "Поиск по имени: ";
	std::cin >> name;
	studentGrades.printName(name);

	return 0;
}