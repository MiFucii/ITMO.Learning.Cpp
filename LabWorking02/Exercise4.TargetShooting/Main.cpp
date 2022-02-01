#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>
 
std::string targetArray[5][5] =
    {
        {"| |","| |","| |","| |","| |"},
        {"| |","| |","| |","| |","| |"},
        {"| |","| |","| |","| |","| |"},
        {"| |","| |","| |","| |","| |"},
        {"| |","| |","| |","| |","| |"}
    };

void printTarget()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << targetArray[i][j];
        }
        std::cout << "\n";
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int bullet, bulletPrice = 250, score = 0;

    std::cout << "Добро пожаловать в тир! Вы можете приобрести от 3 до 6 пуль." << 
        "Чем больше очков вы наберете при стельбе тем ценее приз вы заработаете.\n И так сколько пуль вы покупаете?: ";
    std::cin >> bullet;
    bulletPrice *= bullet;
    std::cout << "\nБыло куплено " << bullet << " пули за " << bulletPrice << " рублей.";

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "\n~~\"Вы берете в руки заряженое ружьё и становитесь напротив мишени\"";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "\n~~\"Вы долго целитесь и наконец делаете первый выстрел...\"";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    targetArray[rand() % 4 + 0][rand() % 4 + 0] = "|x|";

    std::cout << "\n~~\"Вы перевели взгляд на мишинь...\"\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printTarget();

    std::cout << "\n\"Неплохо для первого выстрела\" - подумали Вы\n";
    std::cout << "\n~~\"Сосредоточившись Вы начали стрелять по мешени...\"\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    //Алгоритм стрельбы по мешени
    system("Cls");
    for (int i = 0; i < bullet - 1; i++)
    {
        //Получаем случайные координаты точки попадания по мешени
        int x, y;
        x = rand() % 6 + 0;
        y = rand() % 6 + 0;
        //Проверяем на промах
        if (x < 5 || y < 5) 
        {
            //Записываем попадание
            if (targetArray[x][y] == "|x|") targetArray[x][y] = "|X|";
            else { targetArray[x][y] = "|x|"; }
        }
        std::cout << "~~ВЫСТРЕЛ....\n";
        printTarget();

        std::this_thread::sleep_for(std::chrono::seconds(5));
        if(i != bullet -2) system("Cls");
    }

    //Алгоритм подсчета очков. Первый круг - 1 очко. Второй круг - 5 очков. Попадание в центр - 10 очков.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || i == 4) 
            {
                if (targetArray[i][j] == "|X|") { score += 2; }
                else if (targetArray[i][j] == "|x|") { score++; }
            }
            if (i == 1 || i == 3)
            {
                if (j == 0 || j == 4)
                {
                    if (targetArray[i][j] == "|X|") { score += 2; }
                    else if (targetArray[i][j] == "|x|") { score++; }
                }
                else
                {
                    if (targetArray[i][j] == "|X|") { score += 10; }
                    else if (targetArray[i][j] == "|x|") { score += 5; }
                }                
            }
            if (i == 2)
            {
                if (j == 0 || j == 4)
                {
                    if (targetArray[i][j] == "|X|") { score += 2; }
                    else if (targetArray[i][j] == "|x|") { score++; }
                }
                else if (j == 1 || j == 3)
                {
                    if (targetArray[i][j] == "|X|") { score += 10; }
                    else if (targetArray[i][j] == "|x|") { score += 5; }
                }
                else
                {
                    if (targetArray[i][j] == "|X|") { score += 20; }
                    else if (targetArray[i][j] == "|x|") { score += 10; }
                }
            }
        }        
    }

    std::cout <<"\nИ так. Вы заработали " << score << " очков.";
    if (score < 10) std::cout << "\nУвы. Вы остались без приза!";
    else if (score >= 10 && score < 20) std::cout << "\nУра. Вы выйграли плюшевого кролика!";
    else if (score >= 20 && score < 30) std::cout << "\nПоздравляем. Вы выйграли большого плюшевого слоника!";
    else std::cout << "\nНевероятно. Вы выйграли огромного плюшевого медвежонка!";
    std::cout << "\nСпасибо за игру!!!";
}
