#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Ввод данных типа int
 * @return Введённое значение
 */
int getValue();

/**
 * @brief Ввод размера массива
 * @return размер массива
 */
size_t getSize();

/**
 * @brief Функция для заполнения массива с клавиатуры
 * @return Заполненный массив
 */
void fillmanual(int* arr, const size_t size);

/**
 * @brief Функция рандомного заполнения массива с клавиатуры
 * @return Заполненный массив
 */
void fillrandom(int* arr, const size_t size);

/**
 * @brief Функция, которая считает сумму элементов, которые по модулю меньше 10
 * @param cnt - сумма этих элементов
 * @return Итоговая сумма
 */
int summaARR(int* arr, const size_t size);

/**
 * @brief Функция, которая возвращает индексы тех элемнтов массива, которые больше следующего за ним элемента
 * @return Индексы этих элементов
 */
int Indeksbl(int* arr, const size_t size);

/**
 * @brief Функция для вывода массива
 * @return Массив
 */
void printArray(int* arr, const size_t size);

/**
 * @brief Функция, которая ищет в массиве элементы, кратные 3, и умножает их на 3-ий элемент массива
 * @param x - 3-ий элемент массива
 * @return Изменённый массив
 */
void Treti(int* arr, const size_t size);

/**
* @brief Выбор формулы
*/
enum { RANDOM, MANUAL };

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    size_t size = getSize("Введите размер массива:  ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Error\n");
        abort();
    }
    printf("Выберите способ заполнения массива: \n"
        "%d = случайными числами, %d = вводом с клавиатуры: \n", RANDOM, MANUAL);
    int choise = getValue();
    switch (choise)
    {
    case RANDOM:
        fillrandom(arr, size);
        break;
    case MANUAL:
        fillmanual(arr, size);
        break;
    default:
        printf("Error\n");
        free(arr);
        abort();
    }
    printf("Исходный масив:\n");
    printArray(arr, size);
    printf("Сумма элементов массива arr, меньших 10 по модулю = %d\n", summaARR(arr, size));
    printf("Индексы элементов, значения которых больше значений последующих элементов:\n");
    Indeksbl(arr, size);
    printf("Массив с элементами, где каждый элемент, кратный 3, был умножен на 3-ий элемент исходного массива:\n");
    Treti(arr, size);
    free(arr);
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

size_t getSize(char* message)
{
    printf("%s", message);
    int value = getValue();
    if (value <= 0)
    {
        printf("Error\n");
        abort();
    }
    return (size_t)value;
}

void fillrandom(int* arr, const size_t size)
{
    printf("Введите начало диапозона: \n");
    int start = getValue();
    printf("Введите конец диапозона: \n");
    int end = getValue();
    for (size_t i = 0; i < size; i += 1)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

void fillmanual(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i += 1)
    {
        printf("Введите значение = ");
        arr[i] = getValue();
    }
}

int summaARR(int* arr, const size_t size)
{
    int cnt = 0;
    for (size_t i = 0; i < size; i += 1)
    {
        if (abs(arr[i]) < 10)
        {
            cnt += arr[i];
        }
    }
    return cnt;
}

int Indeksbl(int* arr, const size_t size)
{
    for (size_t i = 0; i < size - 1; i += 1)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("%zu ", i);
        }
    }
    printf(" \n");
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf(" \n");
}

void Treti(int* arr, const size_t size)
{
    int x = arr[2];
    for (size_t i = 0; i < size; i += 1)
    {
        if (arr[i] % 3 == 0)
        {
            printf("%d ", arr[i] * x);
            continue;
        }
        printf("%d ", arr[i]);
    }
}