#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Talon.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << std::endl << std::endl;
    std::cout << " Инициализация массива через конструктор с одним параметром" << std::endl;
    std::cout << " Создание параметра:" << std::endl;
    Doctor* for_array = new Doctor();
    std::cout << std::endl;
    std::cout << " Инициализация массива:" << std::endl;
    Talon* array[3];
    for (Talon*& elem : array) {
        elem = new Talon(for_array);
        std::cout << std::endl;
    }
    std::cout << " Печать массива:" << std::endl;
    for (Talon* elem : array)
        elem->PrintInfo();
    std::cout << std::endl << std::endl;

    std::cout << " Конструкторы со всеми параметрами" << std::endl;
    std::cout << " Создание параметров:" << std::endl;
    std::cout << std::endl;
    Date date = Date();
    Time time = Time();
    std::cout << " Введите кабинет: ";
    int kabinet;
    std::cin >> kabinet;
    while (std::cin.get() != '\n');
    Doctor* medic = new Doctor();
    std::cout << std::endl;
    std::cout << " Статический" << std::endl;
    Talon one = Talon(date, time, kabinet, *medic);
    one.PrintInfo();
    std::cout << " Динамический" << std::endl;
    Talon* two = new Talon(date, time, kabinet, *medic);
    two->PrintInfo();

    std::cout << std::endl << std::endl;

    std::cout << " Конструкторы с одним параметром" << std::endl;
    std::cout << " Статический" << std::endl;
    one = Talon(medic);
    std::cout << std::endl;
    one.PrintInfo();
    std::cout << " Динамический" << std::endl;
    two = new Talon(medic);
    std::cout << std::endl;
    two->PrintInfo();

    std::cout << std::endl << std::endl;

    std::cout << " Конструкторы без параметров" << std::endl;
    std::cout << " Статический" << std::endl;
    one = Talon();
    std::cout << std::endl;
    one.PrintInfo();
    std::cout << " Динамический" << std::endl;
    two = new Talon();
    std::cout << std::endl;
    two->PrintInfo();

    std::cout << std::endl << std::endl;

    std::cout << " Есть талон:" << std::endl;
    one.PrintInfo();
    std::cout << " Поверхностно его скопируем: " << std::endl;
    Talon three = Talon(date, time, kabinet, *medic);
    three = one;            //чтобы избежатть использования коснтруктора копирования
    three.PrintInfo();
    std::cout << " Изменим у начального талона статическую переменную кабинет:" << std::endl;
    one.ChengeKabinet(300);
    one.PrintInfo();
    three.PrintInfo();
    std::cout << " Изменим у начального талона динамическую переменную ФИО доктора: " << std::endl;
    one.GetLinkDoctor().ChengeDoctor("Минус поверхностного копирования");
    one.PrintInfo();
    three.PrintInfo();
    std::cout << " Создадим копию объекта с помощью конструктора и изменим значение" << std::endl;
    three = Talon(one);
    one.GetLinkDoctor().ChengeDoctor("Проверка копирования");
    one.PrintInfo();
    three.PrintInfo();

    std::cout << std::endl << std::endl;
    
    


    _getch();
}
