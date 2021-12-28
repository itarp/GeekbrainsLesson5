#include <iostream>

void task1();
void task2();
void task3();
void task4();
void task5();
void show(double *array, const int SIZE); //Объявление функции для task1
void show(int *array, const int SIZE);
void invert(int *array, const int SIZE);
void init(int *array, const int SIZE);
void shiftRight(int* array, const int SIZE);
void shiftRight(int* array, const int SIZE, int n);
void shiftLeft(int* array, const int SIZE);
void shiftLeft(int* array, const int SIZE, int n);
void shift(int* array, const int SIZE, int n);
bool checkBalance(int *array, const int SIZE);

int main() {
    std::cout << "---------------------- TASK 1 ----------------------" << std::endl;
    task1();
    std::cout << std::endl;
    std::cout << "---------------------- TASK 2 ----------------------" << std::endl;
    task2();
    std::cout << std::endl;
    std::cout << "---------------------- TASK 3 ----------------------" << std::endl;
    task3();
    std::cout << std::endl;
    std::cout << "---------------------- TASK 4 ----------------------" << std::endl;
    task4();
    std::cout << std::endl;
    std::cout << "---------------------- TASK 5 ----------------------" << std::endl;
    task5();
    std::cout << std::endl;
}

void task1() {
    //-------------------------- Задание 1 --------------------------
    //1. Написать функцию которая выводит массив double чисел
    //на экран. Параметры функции это сам массив и его размер.
    //Вызвать эту функцию из main.
    const size_t SIZE = 10; // Размер массива
    double array[SIZE] = { 5.25, .12, 8., 7.4, 46.1, 33., 44.444, .0, 9.5, 11.6 }; // Массив float типа
    show (array, SIZE); //Вызов функции которая выодит 
}

void task2() {
    //-------------------------- Задание 2 --------------------------
    //Задать целочисленный массив, состоящий из элементов 0
    //и 1. Например: [1, 1, 0, 0, 1, 0, 1, 1, 0, 0] .Написать функцию,
    //заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить
    //на экран массив до изменений и после.

    const size_t SIZE = 10;
    int array[SIZE] { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
    show(array, SIZE);
    invert(array, SIZE);
    show(array, SIZE);
}

void task3() {
    //-------------------------- Задание 3 --------------------------
    // Задать пустой целочисленный массив размером 8.
    // Написать функцию, которая с помощью цикла заполнит его
    // значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.
    const size_t SIZE = 8;
    int array[SIZE] = {0};
    init(array, SIZE);
    for (int i = 0; i < SIZE; i++)
        std::cout << array[i] << "  ";
}

void task4() {
    //-------------------------- Задание 4 --------------------------
    // Написать функцию, которой на вход подаётся
    // одномерный массив и число n(может быть положительным,
    // или отрицательным), при этом метод должен циклически
    // сместить все элементы массива на n позиций.

    const int SIZE = 10;
    int array[SIZE] = { 25, 70, 3, 14, 4, 63, 9, 43, 7, 77 };

    //показать массив элементов
    show(array, SIZE);
    //Сдвинуть вправо на 3 элемента
    std::cout << "Shift right by three elements >>3";
    shift(array, SIZE, 3);
    //показать массив элементов
    show(array, SIZE);
    //Сдвинуть влево на 4 элемента
    std::cout << "Shift left by four elements <<4";
    shift(array, SIZE, -4);
    // показать массив элементов
    show(array, SIZE);
    }

void task5() {
    //-------------------------- Задание 5 --------------------------
    // Написать функцию, которой передается не пустой
    // одномерный целочисленный массив, она должна вернуть
    // истину если в массиве есть место, в котором сумма левой и
    // правой части массива равны.Примеры: checkBalance([1, 1,
    //  1, || 2, 1]) → true, checkBalance([2, 1, 1, 2, 1]) → false,
    // checkBalance([10, || 1, 2, 3, 4]) → true.Абстрактная граница
    // показана символами || , эти символы в массив не входят.
    const int SIZE = 5;
    int array[SIZE] = { 4, 5, 2, 1, 12 };
    show(array, SIZE);
    if (checkBalance(array, SIZE) == true)
        std::cout << "true" << std::endl;
    else 
        std::cout << "false" << std::endl;

    const int SIZE1 = 7;
    int array1[SIZE1] = { 6, 3, 2, 7, 1, 4, 7};
    show(array1, SIZE1);
    if (checkBalance(array1, SIZE1) == true)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    const int SIZE2 = 5;
    int array2[SIZE2] = { 10, 1, 2, 3, 4 };
    show(array2, SIZE2);
    if (checkBalance(array2, SIZE2) == true)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

}

void show(double *aArray, const int SIZE) {
    for (int i = 0; i < SIZE; i++)
        std::cout << *(aArray + i) << "\t";
};


void show(int* array, const int SIZE ) {
    std::cout << std::endl;
    for (int i = 0 ; i < SIZE; i++)
        std::cout << *(array + i) << "  ";
    std::cout << std::endl;
}

void invert(int *array, const int SIZE) {
    for (int i = 0; i < SIZE; i++)
        *(array + i) = !(*(array + i));
}

void init(int* array, const int SIZE) {
    for (int i = 0, count = 1; i < SIZE; i++, count += 3)
        array[i] = count;
}

void shiftRight(int *array, const int SIZE) {
    //Сдвиг вправо на 1;
    int temp = 0;
    temp = array[SIZE - 1];
    for (int i = SIZE - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = temp;
}

void shiftLeft(int* array, const int SIZE) {
    //Сдвиг влево на 1;
    int temp = 0;
    temp = array[0];
    for (int i = 0; i < (SIZE - 1); i++) {
        array[i] = array[i + 1];
    }
    array[SIZE - 1] = temp;
}

void shiftRight(int* array, const int SIZE, int n) {
    for (int i = 0; i < n; i++)
        shiftRight(array, SIZE);
}

void shiftLeft(int* array, const int SIZE, int n) {
    for (int i = 0; i < n; i++)
        shiftLeft(array, SIZE);
}

void shift(int* array, const int SIZE, int n) {
    if (n < 0)
        shiftLeft(array, SIZE, -(n));
    else if (n > 0)
        shiftRight(array, SIZE, n);
}

bool checkBalance(int* array, const int SIZE) {
    bool balance =false;
    int leftSide = 0, rightSide = 0;
    for (int i = 0; i < SIZE-1; i++) {
        leftSide = 0;
        rightSide = 0;
        for (int ii = 0; ii <= i; ii++)
            leftSide = leftSide + array[ii];
        for (int ii = SIZE - 1; ii > i; ii--)
            rightSide = rightSide + array[ii];
        if (leftSide == rightSide) {
            balance = true;
            //std::cout << i << " - " << leftSide << "   " << rightSide << std::endl;
            break;
        }
    }
     return balance;
}