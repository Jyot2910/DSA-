#include <iostream>
#include <string>
using namespace std;

int main() {
    string date;
    int n;

    cout << "Enter date (dd/mm/yyyy): ";
    cin >> date;

    cout << "Enter number of days: ";
    cin >> n;

   
    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 1000 +
               (date[7] - '0') * 100 +
               (date[8] - '0') * 10 +
               (date[9] - '0');

    
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        daysInMonth[1] = 29;

   
    if (month < 1 || month > 12) {
        cout << "Invalid Date";
        return 0;
    }

   
    if (day < 1 || day > daysInMonth[month - 1]) {
        cout << "Invalid Date";
        return 0;
    }

  
    while (n > 0) {
        day++;

        if (day > daysInMonth[month - 1]) {
            day = 1;
            month++;

            if (month > 12) {
                month = 1;
                year++;

                
                if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
                    daysInMonth[1] = 29;
                else
                    daysInMonth[1] = 28;
            }
        }

        n--;
    }

   
    if (day < 10)
        cout << "0";
    cout << day << "/";

    if (month < 10)
        cout << "0";
    cout << month << "/";

    cout << year;

    return 0;
}