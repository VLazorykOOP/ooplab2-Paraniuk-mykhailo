#include <iostream>

unsigned int multiplyUsingBitwiseOperators(int a, int b) {
    unsigned int result = 0;

    while (b != 0) {
        // Якщо найменший біт b встановлений, додати a до результату
        if (b & 1) {
            result += a;
        }

        // Зсунути b вправо та a вліво
        b >>= 1;
        a <<= 1;
    }

    return result;
}

int main() {
    int a, b;

    // Зчитування цілих чисел від користувача
    std::cout << "Введіть перше число a: ";
    std::cin >> a;

    std::cout << "Введіть друге число b: ";
    std::cin >> b;

    // Обчислення та виведення добутку
    unsigned int result = multiplyUsingBitwiseOperators(a, b);
    std::cout << "Добуток " << a << " та " << b << " за допомогою побітового зсуву та додавання: " << result << std::endl;

    return 0;
}