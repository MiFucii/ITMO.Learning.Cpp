#pragma once

class Student : public Human
{
private:
	std::vector<int> scores;
public:
    Student(std::string firstName, std::string secondName, std::string lastName, std::vector<int> scores)
        : Human(firstName, secondName, lastName), scores(scores) {}

    float getAverageScore()
    {
        unsigned int scoresSum = 0;

        for (int var : scores)
        {
            scoresSum += var;
        }

        return (float)scoresSum / (float)scores.size();
    }

    std::string getInfo() {
        std::string infoStr;
        infoStr = "\tСредний бал: " + std::to_string(getAverageScore());
        return infoStr;
    }
};
