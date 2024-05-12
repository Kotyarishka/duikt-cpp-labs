#include <iostream>

void increment(int &x) {
    x++;
}

void increment(int &x, int amount) {
    x += amount;
}

int main() {
    int var = 0;

    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            increment(var);
        } else {
            increment(var, i);
        }
    }

    std::cout << var << std::endl;

    return 0;
}