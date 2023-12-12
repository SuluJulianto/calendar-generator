#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void printCalendar(int year) {
    string monthNames[12] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[1] = 29; 
    }

    for (int month = 0; month < 12; ++month) {
        cout << "\n" << monthNames[month] << " " << year << "\n";
        cout << "Su Mo Tu We Th Fr Sa\n";

        int startingDay = (year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;

        for (int i = 0; i < startingDay; ++i) {
            cout << "   ";
        }

        for (int day = 1; day <= daysInMonth[month]; ++day) {
            printf("%2d ", day);
            startingDay++;
            if (startingDay % 7 == 0) {
                cout << "\n";
            }
        }
        cout << "\n";
    }
}

int main() {
    int year;
    cout << "Enter the current year (1-9999): ";
    cin >> year;

    if (year < 1 || year > 9999) {
        cout << "Please choose another year within the range." << endl;
    } else {
        printCalendar(year);
    }

    return 0;
}
