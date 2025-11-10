#include <stdio.h>
#include <stdlib.h>

/**
* @brief Функция, расчитывающая объём параллепипеда
* @return Расчитанный объём
*/
double getVolume(const double side1,const double side2,const double side3);

/**
* @brief Ввод данных типа int
* @return Введённое значение
*/
double getValue();

/**
* @brief Функция, проверяющая переменную на положительность
* @return True, если переменная положительна; иначе False
*/
void chekValue(const double value);

/**
* @brief Функция, расчитывающая площадь поверхности параллепипеда
* @return Расчитанная площадь поверхности
*/
double getSquare(const double side1,const double side2,const double side3);

/**
* @brief Выбор формулы
*/
enum {VOLUME, SQUARE};

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main(void)
{
    printf("Введите стороны паралелограмма: ");
    double side1 = getValue();
    checkValue(side1);
    double side2 = getValue();
    checkValue(side2);
    double side3 = getValue();
    checkValue(side3);
    printf("Выберите нужный расчёт: %d-объём, %d-площадь поверхности\n", VOLUME, SQUARE);
    int choice = (int) getValue;
    switch (choice)
    {
        case VOLUME:
            printf("Периметр = %2.lf",getVolume(side1,side2,side3));
            break;
        case SQUARE:
            printdf("Площадь поверхности = %2.lf",getSquare(side1,side2,side3));
            break;
        default:
            printf("Неверный ввод!");
            abort();
    }
    return 0;
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double value)
{
    if (value <= 0 )
    {
        printf("Value have to be positive\n");
        abort();
    }
}

double getVolume(const double side1,const double side2,const double side3)
{
    return side1*side2*side3;
}

double getSquare(const double side1,const double side2,const double side3)
{
    return 2*(side1*side2 + side2*side3 + side1*side3);
}