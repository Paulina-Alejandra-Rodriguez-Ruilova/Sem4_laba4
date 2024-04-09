#include <iostream>
#include <limits>

template <typename T>
int findSecondMaxIndex(T* arr, int size) {
    if (size < 2) {
        std::cerr << "Массив должен содержать как минимум два элемента" << std::endl;
        return -1;
    }

    int maxIndex = 0;
    int secondMaxIndex = -1;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            secondMaxIndex = maxIndex;
            maxIndex = i;
        }
        else if (secondMaxIndex == -1 || arr[i] > arr[secondMaxIndex]) {
            if (arr[i] != arr[maxIndex]) {
                secondMaxIndex = i;
            }
        }
    }

    return secondMaxIndex;
}

int main() {
    setlocale(LC_ALL, "RU");
    float arrFloat[] = { 1.2, 3.4, 5.6, 2.1 };
    std::cout << "Индекс второго максимума в массиве float: " << findSecondMaxIndex(arrFloat, 4) << std::endl;

    double arrDouble[] = { 2.3, 4.5, 1.2, 5.6 };
    std::cout << "Индекс второго максимума в массиве double: " << findSecondMaxIndex(arrDouble, 4) << std::endl;

    int arrInt[] = { 5, 3, 7, 1, 9 };
    std::cout << "Индекс второго максимума в массиве int: " << findSecondMaxIndex(arrInt, 5) << std::endl;

    char arrChar[] = { 'a', 'b', 'z', 'f' };
    std::cout << "Индекс второго максимума в массиве char: " << findSecondMaxIndex(arrChar, 4) << std::endl;

    return 0;
}