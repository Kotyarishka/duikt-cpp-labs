#include <iostream>

// Завдання 1.
// Ознайомтесь з поняттям динамічної пам’яті, операторами new i delete.
// Задати одновимірний динамічний масив (кількість елементів виберіть на
// власний розсуд). Заповнити масив випадковими значеннями з плаваючою
// крапкою з діапазону (-2, 2). Знайти кількість додатних та від'ємних чисел.
void problem1() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    float* arr = new float[n];
    for (int i = 0; i < n; i++) {
        arr[i] = -2 + static_cast<float>(rand()) / RAND_MAX * 4;
    }

    int positive = 0;
    int negative = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positive++;
        } else if (arr[i] < 0) {
            negative++;
        }
    }

    std::cout << "Positive: " << positive << std::endl;
    std::cout << "Negative: " << negative << std::endl;

    delete[] arr;
}

// Завдання 2.
// Задайте двовимірний динамічний масив цілих чисел розмірністю 3х3 (кількість
// елементів виберіть на власний розсуд). Заповнити його випадковими
// значеннями. Виведіть на екран, елементи, що знаходяться на головній діагоналі,
// побічній діагоналі, кількість парних та непарних елементів масиву.
void problem2() {
    int n = 3;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    std::cout << "Main diagonal: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i][i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Side diagonal: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i][n - i - 1] << " ";
    }
    std::cout << std::endl;

    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
    }

    std::cout << "Even: " << even << std::endl;
    std::cout << "Odd: " << odd << std::endl;

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    problem2();
    return 0;
}