#include <Windows.h>
#include <iostream>
#include <string>

 struct Time
{
    int hours;
    int minutes;
    int seconds;

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

    Time subTime(const Time& timeToSub) const
    {
        Time t;
        t.hours = hours - timeToSub.hours;
        if (t.hours < 0) t.hours *= -1;

        t.minutes = minutes - timeToSub.minutes;
        if (t.minutes < 0) t.minutes *= -1;

        t.seconds = seconds - timeToSub.seconds;
        if (t.seconds < 0) t.seconds *= -1;
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

    Time time(h, m, s);
    std::cout << "Вы ввели время: " << time.timeToString() << std::endl;

    Time timeRand(rand() % 23 + 0, rand() % 59 + 0, rand() % 59 + 0);
    std::cout << "Случайное время: " << timeRand.timeToString() << std::endl;

    Time timeRezAdd = timeRand.addTime(time);
    std::cout << "Ваше время + случайное время: " << timeRezAdd.timeToString() << std::endl;

    Time timeRezSub = timeRand.subTime(time);
    std::cout << "Ваше время - случайное время: " << timeRezSub.timeToString() << std::endl;
}

