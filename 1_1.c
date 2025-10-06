#include <stdio.h>
#include <math.h>
/**
 * @brief Расчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return расчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 * @brief Расчитывает функцию В по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return расчитанное значение
 */
double getB(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return вовзвращает 0, если программа выполнена корректно
 */
int main(void)
{
	const double x = 0.2;
	const double y = 0.004;
	const double z = 1.1;
	printf("А=%lf\n", getA(x, y, z));
	printf("B=%lf\n", getB(x, y, z));
	return 0;
}

double getA(const double x, const double y, const double z)
{
	return pow(sin(pow(x * x + z, 2)), 3) - sqrt(x / y);
}

double getB(const double x, const double y, const double z)
{
	return x * x / z + cos(pow(x + y, 3));
}