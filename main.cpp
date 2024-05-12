#include <iostream>

// Функція повинна мати назву isPrime, приймати один аргумент типу int (тобто число, яке хочемо перевірити) та
// повертати true, якщо аргумент є простим числом, або false в іншому випадку.
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i = 0; i <= 21; i++) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}