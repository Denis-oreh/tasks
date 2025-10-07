#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает значение, введенное с клавиатуры(+проверка ввода)
 * @return считанное значение
 */
double getValue();

/**
 * @brief - Расчет функции y по заданной формуле
 * @param x - значение переменной х
 * @param A - значение переменной A(константа)
 * @return - рассчитанное значение
 */
double getF(double x, const double A);

/**
 * @brief - Точка входа в программу
 * @return - возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double const A = 0.9;
    printf("Введите значение х: \n");
    double x = getValue();
    printf("Функция у = %.5lf",getF(x,A));
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

double getF(double x, const double A)
{
    if (x <= 1)
    {
        return 2*A*cos(x)+3*(x*x);
    }
    else
    {
        return A*log10(x)+sqrt(abs(x));
    }
}