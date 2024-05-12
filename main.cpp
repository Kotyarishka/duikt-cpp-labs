#include <iostream>
#include "ctime"

bool isLeap(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}
int monthLength(int year, int month) {
    int days[] = {31, isLeap(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

struct Date {
    int year;
    int month;
    int day;
};

Date today() {
    time_t t = time(0);
    tm *now = localtime(&t);
    Date date;
    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;
    return date;
}

// Знайдіть кількість днів, що пройшли від вашого дня народження до поточної дати.
int main() {
    Date birthDate;
    std::cout << "Enter your birth date (year month day): ";
    std::cin >> birthDate.year >> birthDate.month >> birthDate.day;

    Date currentDate = today();
    int days = 0;
    for (int year = birthDate.year; year <= currentDate.year; year++) {
        int startMonth = year == birthDate.year ? birthDate.month : 1;
        int endMonth = year == currentDate.year ? currentDate.month : 12;

        for (int month = startMonth; month <= endMonth; month++) {
            int startDay = year == birthDate.year && month == birthDate.month ? birthDate.day : 1;
            int endDay = year == currentDate.year && month == currentDate.month ? currentDate.day : monthLength(year, month);
            for (int day = startDay; day <= endDay; day++) {
                days++;
            }
        }
    }
    std::cout << "Days since your birth: " << days << std::endl;

    return 0;
}