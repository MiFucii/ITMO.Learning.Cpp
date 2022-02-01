#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ofstream fout("poem.txt");
    char poemWrite[410] = {0};
    char poemRead[410] = {0};
    cout << "~~Подсказка: чтобы завершить ввод стихотворения введите символ \"*\" и нажмите Enter.\nВведите ваше стихотворение ниже (не более 400 символов):\n";
    cin.get(poemWrite, sizeof(poemWrite), '*');
    fout.write(poemWrite, sizeof(poemWrite) / sizeof(char));
    fout.close();

    ifstream in("poem.txt");
    cout << "\nВаше стихотворение успешно сохранено в фаил \"poem.txt\"\nВот его содержимое:\n";
    in.read(poemRead, sizeof(poemRead));
    for (char var : poemRead)
    {
        cout << var << "";
    }
    in.close();
}