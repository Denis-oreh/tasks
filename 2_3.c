#include <stdio.h>
#include <stdlib.h>

/**
 * @brief считывает введенное с клавиатуры значение с проверкой ввода
 * @return считанное значение
 */
int getValue();

/**
 * @brief распознаёт пожелание по введённому времени суток
 * @param x - введённое время суток
 * @return возвращает пожелание
 */
char gettime(const int x);

/**
 * @brief проверяет,что переменная лежит в диапозоне от 0 до 23 включительно
 * @param x значение проверяемой переменной
 */
void checkValue(const int x);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{printf("Введите время(целое кол-во часов от 0 до 23 включительно): \n");
    const int x = (int)getValue();
    checkValue(x);
    gettime(x);
    return 0;
}

char gettime(const int x)
{
    if (x>=6 && x<12)
    {printf("Доброе утро!\n");
     abort();
    } else if (x>=12 && x<18)
    {printf("Добрый день!\n");
     abort();
    } else if (x>=18 && x<=23)
    {printf("Добрый вечер!\n");
     abort();
    } else if (x>=0 && x<6);
    {printf("Спокойной ночи!\n");
     abort();
    }
}

int getValue()
{
    int value = 0;
    if (!scanf("%d",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const int x)
{
    if (x<0 || x>23)
    {
        printf("Error\n");
        abort();
    }
}