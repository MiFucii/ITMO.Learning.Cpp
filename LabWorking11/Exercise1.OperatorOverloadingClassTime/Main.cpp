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

    int getHours() { return hours; }
    int getMinutes() { return minutes; }
    int getSeconds() { return seconds; }

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
    Time operator+(const Time& timeToAdd) const
    {
        Time t;
        t.hours = hours + timeToAdd.hours;
        t.minutes = minutes + timeToAdd.minutes;
        t.seconds = seconds + timeToAdd.seconds;
        t.stabilizationTime();

        return t;
    }
    Time operator-(const Time& timeToSub) const
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
    bool operator>(const Time& timeIn) {
        bool flag = false;
        if (hours > timeIn.hours) flag = true;
        else if (hours == timeIn.hours && minutes > timeIn.minutes) flag = true;
        else if (hours == timeIn.hours && minutes == timeIn.minutes && seconds > timeIn.seconds) flag = true;

        return flag;
    }
    bool operator<(const Time& timeIn) {
        bool flag = false;
        if (hours < timeIn.hours) flag = true;
        else if (hours == timeIn.hours && minutes < timeIn.minutes) flag = true;
        else if (hours == timeIn.hours && minutes == timeIn.minutes && seconds < timeIn.seconds) flag = true;

        return flag;
    }

    operator int() const {
        return hours + minutes + seconds;
    }
};

Time operator+ (Time& t, int value)
{
    return Time(t.getHours(), t.getMinutes(), t.getSeconds() + value);
}
Time operator- (Time& t, int value)
{
    return Time(t.getHours(), t.getMinutes(), t.getSeconds() - value);
}

int operator+ (int value, Time& t)
{
    return value + (int)t;
}
int operator- (int value, Time& t)
{
    return value - (int)t;
}

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

    Time timeAddRez =  (Time)time + (Time)timeRand;
    std::cout << "Ваше время + случайное время: " << timeAddRez.timeToString() << std::endl;

    Time timeSubRez =  (Time)time - (Time)timeRand;
    std::cout << "Ваше время - случайное время: " << timeSubRez.timeToString() << std::endl;

    if (time > timeRand) std::cout << "Ваше время больше случайного времени." << std::endl;
    if (time < timeRand) std::cout << "Ваше время меньше случайного времени." << std::endl;

    Time timeAddValue = time + 1000;
    std::cout << "Ваше время + 1000 секунд: " << timeAddValue.timeToString() << std::endl;

    int valueAddTime = 512 + time;
    std::cout << "К целому числу 512 прибавляем ваше время получаем число: " << valueAddTime << std::endl;
}

