#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Talon.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << std::endl;
    
    std::cout << " Конструкторы без параметров" << std::endl;
    std::cout << " Статический" << std::endl;
    std::cout << std::endl;
    Talon one = Talon();
    std::cout << std::endl;
    one.PrintInfo();
    std::cout << " Динамический" << std::endl;
    std::cout << std::endl;
    Talon* two = new Talon();
    std::cout << std::endl;
    two->PrintInfo();

    std::cout << std::endl << std::endl;

    std::cout << " Конструкторы с одним параметром" << std::endl;
    std::cout << " Создание параметра:" << std::endl;
    std::cout << std::endl;
    Doctor* medic = new Doctor();
    std::cout << std::endl;
    std::cout << " Статический" << std::endl;
    std::cout << std::endl;
    one = Talon(medic);
    std::cout << std::endl;
    one.PrintInfo();
    std::cout << " Динамический" << std::endl;
    std::cout << std::endl;
    two = new Talon(medic);
    std::cout << std::endl;
    two->PrintInfo();

    std::cout << std::endl << std::endl;;

    std::cout << " Конструкторы со всеми параметрами" << std::endl;
    std::cout << " Создание параметров:" << std::endl;
    std::cout << std::endl;
    Date date = Date();
    Time time = Time();
    std::cout << std::endl;
    std::cout << " Введите кабинет:" << std::endl;
    int kabinet;
    std::cin >> kabinet;
    std::cout << std::endl;
    std::cout << " Статический" << std::endl;
    std::cout << std::endl;
    one = Talon(date, time, kabinet, *medic);
    std::cout << std::endl;
    one.PrintInfo();
    std::cout << std::endl;
    std::cout << " Динамический" << std::endl;
    std::cout << std::endl;
    two = new Talon(date, time, kabinet, *medic);
    std::cout << std::endl;
    two->PrintInfo();


    _getch();
}
