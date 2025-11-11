#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return возвращает считанное число
 */
int getValue();

/** 
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void chekPositive(const int value);

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double getsum_n(const int n);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i);

/**
 * @brief считывает числот с плавающей точкой с клавиатуры в проверкой ввода
 * @return возвращает считанное число
 */
double getDouble();

/**
 * @brief рассчитывает сумму членов последовательности,
 * с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double getsum_e(const double e);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    printf("Введите n: ");
    int n = getValue();
    chekPositive(n);
    printf("Сумма %d чисел последовательности равна %.4lf\n",n,getsum_n(n));
    printf("Введите e: ");
    double e = getDouble();
    chekPositive(e);
    printf("Сумма чисел последовательности с точностью %lf равна %.4lf\n",e,getsum_e(e));
    return 0;
}

int getValue()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void chekPositive(const int value)
{
    if (!value > 0)
    {
        printf("Error\n");
        abort();
    }
}

double getsum_n(const int n)
{
    double cnt = -1.0;
    double result = 0;
    for (int i = 1; i < n; i += 1)
    {
        cnt *= getRecurent(i);
        result += cnt;
    }
    return result;
}

double getRecurent(const int i)
{
    return -1.0 / (4*i*i + 2*i);
}

double getDouble()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

double getsum_e(const double e)
{
    double cnt = -1.0;
    double result = 0;
    for (int i = 1; fabs(cnt) > e; i += 1)
    {
        result += cnt;
        cnt *= getRecurent(e);
    }
    return result;
}