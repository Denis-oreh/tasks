#include <stdio.h>

/**
 * @brief Расчитывает общее сопротивление соединения по заданной формуле
 * @param R1 - значение параметра R1
 * @param R2 - значение параметра R2
 * @param R3 - значение параметра R3
 * @return рассчитанное значение
 */
double soprotivlenie(double R1, double R2, double R3);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double R1 = 0;
    double R2 = 0;
    double R3 = 0;
    printf("Введите сопротивление R1: \n");
    scanf("%lf", &R1);
    printf("Введите сопротивление R2: \n");
    scanf("%lf", &R2);
    printf("Введите сопротивление R3: \n");
    scanf("%lf", &R3);
    printf("Общее сопротивление соединения: %lf\n", soprotivlenie(R1, R2, R3));
    return 0;
}

double soprotivlenie(double R1, double R2, double R3)
{
    return R1 + R2 + R3;
}