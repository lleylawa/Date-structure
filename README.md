# Date structure
This C++ program allows users to input two dates and performs various operations on them, including checking the validity of the dates, calculating the day of the week for each date, finding the difference in days between the two dates, and comparing which date comes earlier.


### Functions:
- `isValidDate`: Checks if a given date is valid, considering the number of days in each month and accounting for leap years.
- `getDayOfWeek`: Calculates the day of the week for a given date using Zeller's Congruence algorithm.
- `calculateDifference` : Computes the difference in days between two dates by converting each date into days and then finding the absolute difference.
- `printDate` : Prints a date in a formatted way.
- `operator<` : Overloads the less than operator for comparing dates.


### Overview

The main features of the program include:
- **Date Validation**: Check if a given date is valid.
- **Day of the Week Calculation**: Determine the day of the week for a given date using Zeller's Congruence algorithm.
- **Difference Calculation**: Calculate the difference in days between two dates.
- **Date Comparison**: Compare two dates to determine which is earlier.
- **Date Sorting**: Sort a list of dates in chronological order.

**Libraries**: Includes <iostream> for input/output and <cmath> for mathematical functions.

**Date Structure**: Defines a Date structure with day, month, and year fields.

