#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getFirstDayOfMonth(int year, int month) {
    int day = 1;
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return (h + 5) % 7; 
}

int getDaysInMonth(int year, int month) {
    const int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysPerMonth[month];
}

void printCalendar(int year, int month, int firstDay) {
    const char* monthNames[] = {
        "January", "February", "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("\n%s %d\n", monthNames[month - 1], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    int daysInMonth = getDaysInMonth(year, month);
    int currentDay = 1;

    for (int i = 0; i < firstDay; i++) {
        printf("   ");
    }

    for (int i = firstDay; i < 7; i++) {
        printf("%2d ", currentDay);
        currentDay++;
    }
    printf("\n");

    while (currentDay <= daysInMonth) {
        for (int i = 0; i < 7 && currentDay <= daysInMonth; i++) {
            printf("%2d ", currentDay);
            currentDay++;
        }
        printf("\n");
    }
}

int main() {
    int year;

    printf("Enter a year (1-9999): ");
    scanf("%d", &year);

    if (year < 1 || year > 9999) {
        printf("Please choose another year within the range.\n");
    } else {
        for (int month = 1; month <= 12; month++) {
            int firstDay = getFirstDayOfMonth(year, month);
            printCalendar(year, month, firstDay);
        }
    }

    return 0;
}
