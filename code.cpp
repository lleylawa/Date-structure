#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // Include for std::sort

using namespace std; 

// Define a structure to represent a Date
struct Date {
    int day;   
    int month;  
    int year;   
};

// Function to check if a date is valid
bool isValidDate(const Date& date) {
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Array storing the number of days in each month
    
    // Check if any part of the date is out of bounds
    if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > daysInMonth[date.month])
        return false;
    // Check for February in a leap year
    if (date.month == 2 && ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))) {
        return date.day <= 29; // February can have 29 days in a leap year
    }
    return true; // Date is valid
}

// Function to calculate the day of the week for a given date
string getDayOfWeek(const Date& date) {
    int m = date.month;
    int y = date.year;

    // Zeller's Congruence algorithm to calculate the day of the week
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int h = (date.day + (13 * (m + 1) / 5) + y + (y / 4) - (y / 100) + (y / 400)) % 7;

    string daysOfWeek[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return daysOfWeek[h];
}

// Function to calculate the difference in days between two dates
int calculateDifference(const Date& date1, const Date& date2) {
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Array storing the number of days in each month
    long int thisDateDays = date1.year * 365 + date1.day; // Convert date1 to days
    for (int i = 1; i < date1.month; ++i) {
        thisDateDays += daysInMonth[i];
    }
    if (date1.month > 2 && ((date1.year % 4 == 0 && date1.year % 100 != 0) || (date1.year % 400 == 0))) {
        thisDateDays += 1; // Leap year adjustment
    }

    long int otherDateDays = date2.year * 365 + date2.day; // Convert date2 to days
    for (int i = 1; i < date2.month; ++i) {
        otherDateDays += daysInMonth[i];
    }
    if (date2.month > 2 && ((date2.year % 4 == 0 && date2.year % 100 != 0) || (date2.year % 400 == 0))) {
        otherDateDays += 1; // Leap year adjustment
    }
    return abs(thisDateDays - otherDateDays); // Return the absolute difference
}

// Function to print a date
void printDate(const Date& date) {
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << months[date.month - 1] << " " << date.day << ", " << date.year << endl; // Print the date in a formatted manner
}

// Operator overloading for comparing dates
bool operator<(const Date& date1, const Date& date2) {
    if (date1.year != date2.year)
        return date1.year < date2.year;
    if (date1.month != date2.month)
        return date1.month < date2.month;
    return date1.day < date2.day;
}

// Function to sort an array of Date structures
void sortDates(vector<Date>& dates) {
    sort(dates.begin(), dates.end());
}

int main() {
    Date date1, date2; // Declare two Date variables

    // Prompt the user to input the first date
    cout << "Enter first date (day month year): ";
    cin >> date1.day >> date1.month >> date1.year;

    // Prompt the user to input the second date
    cout << "Enter second date (day month year): ";
    cin >> date2.day >> date2.month >> date2.year;

    // Check if either date is invalid
    if (!isValidDate(date1) || !isValidDate(date2)) {
        cout << "Error! Invalid date entered." << endl;
        return 1; // Exit the program with an error code
    }
    
    // Create a vector of dates and add the input dates to it
    vector<Date> dates = {date1, date2};

    // Sort the dates
    sortDates(dates);

    // Output the sorted dates
    cout << "Sorted dates: " << endl;
    for (const Date& date : dates) {
        printDate(date);
    }

    cout << "Day of the week for first date: " << getDayOfWeek(date1) << endl;
    cout << "Day of the week for second date: " << getDayOfWeek(date2) << endl;
    cout << "Difference in days between the two dates: " << calculateDifference(date1, date2) << endl;

    if (date1 < date2) {
        cout << "First date is earlier than second date." << endl;
    } else {
        cout << "Second date is earlier than first date." << endl;
    }
    return 0; 
}
