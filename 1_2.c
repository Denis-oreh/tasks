#include <stdio.h>

/**
 * @brief Расчитывавет кол-во мегабайт по заданной формуле
 * @param bait - кол-во байт
 * @return расчитанное значение
 */
double Megabait(double bait);

/**
 * @brief Расчитывавет кол-во гигабайт по заданной формуле
 * @param bait - кол-во байт
 * @return расчитанное значение
 */
double Gigabait(double bait);

/**
 * @brief Точка входа в программу
 * @return вовзвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double bait = 0;
    printf("Введите число байт: \n");
    scanf("%lf", &bait);
    printf("Кол-во мегабайт=%lf\n", Megabait(bait));
    printf("Кол-во гигабайт=%lf\n", Gigabait(bait));
    return 0;
}

double Megabait(double bait)
{
    return bait / 1024 / 1024;
}

double Gigabait(double bait)
{
    return bait / 1024 / 1024 / 1024;
}