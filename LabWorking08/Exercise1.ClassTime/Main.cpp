#include <Windows.h>
#include <iostream>
#include <string>

class Time
{
private:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    void stabilizationTime()
    {
        while (seconds > 59) {
            seconds -= 60;
            minutes++;
        }
        while (minutes > 59) {
            minutes -= 60;
            if (hours > 23) hours = 0;
            else hours++;
        }
        while (hours > 23) {
            hours -= 24;
        }
    }
public:
    Time() 
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int h, int m, int s) 
    {
        hours = h;
        minutes = m;
        seconds = s;
        stabilizationTime();
    }
    std::string timeToString()const 
    {
        std::string h, m, s;

        h = std::to_string(hours) + ":";
        m = std::to_string(minutes) + ":";
        s = std::to_string(seconds);

        if (hours < 10) h = "0" + h;
        if (minutes < 10) m = "0" + m;
        if (seconds < 10) s = "0" + s;

        return h + m + s;
    }
    Time addTime(const Time& timeToAdd) const 
    {
        Time t;
        t.hours = hours + timeToAdd.hours;
        t.minutes = minutes + timeToAdd.minutes;
        t.seconds = seconds + timeToAdd.seconds;
        t.stabilizationTime();
        return t;
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int h, m, s;
   
    std::cout << "Введите часы: ";
    std::cin >> h;
    std::cout << "Введите минуты: ";
    std::cin >> m;
    std::cout << "Введите секунды: ";
    std::cin >> s;

    Time time(h,m,s);
    std::cout << "Вы ввели время: " << time.timeToString() << std::endl;

    Time timeRand(rand() % 23 + 0, rand() % 59 + 0, rand() % 59 + 0);
    std::cout << "Случайное время: " << timeRand.timeToString() << std::endl;

    Time timeRez = timeRand.addTime(time);
    std::cout << "Ваше время + случайное время: " << timeRez.timeToString() << std::endl;
}

