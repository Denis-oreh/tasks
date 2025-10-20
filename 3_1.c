#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/**
 * @brief считывает значение, введённое с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getvalue();

/**
 * @brief проверяет, что переменная положительна
 * @param step - значение проверяемой переменной
 */
void chekstep(const double step);

/**
 * @brief проверяет, принадлежит ли значение аргумента функции
 * её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);

/**
 * @brief расчитывает значение функции у по заданной формуле
 * @param x - значение переменной x
 * @return значение функции
 */
double getY();

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    printf("Введите начальное значение: ");
    double start = getvalue();
    printf("Введите конечное значение: ");
    double end = getvalue();
    printf("Введите шаг: ");
    double step = getvalue();
    chekstep(step);
    for (double x = start; x < end + DBL_EPSILON; x += step)
    {
        if (defineOOF(x))
        {
            printf("x = %.2lf, y = %.4lf\n", x, getY(x));
        }
        else
        {
            printf("x = %.2lf, не принадлежит ООФ\n", x);
        }
    }
    return 0;
}

double getvalue()
{
    double value = 0;
    if (!scanf("%ld",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void chekstep(const double step)
{
    if (step <= DBL_EPSILON)
    {
        printf("Ошибка, шаг должен быть положительным");
        abort();
    }
}

bool defineOOF(const double x)
{
    return x > 0;
}

double getY(const double x)
{
    return 0.1*x*x - x*log(x);
}