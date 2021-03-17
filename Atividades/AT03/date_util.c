#include <stdbool.h>

bool is_leap_year(int year) {
    if ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
        return true;

    return false;
}

int last_day_of_month(int year, int month) {

    if (month == 2 && is_leap_year(year))
        return 29;
    
    if (month == 2 && !is_leap_year(year))
        return 28;

    if (month == 1 || month == 3 || month == 5 || month == 7 
        || month == 8 || month == 10 && month == 12)
        return 31;

    if (month == 4 || month == 6 || month == 9 || month == 11 ) {
        return 30;
    }

    return -1;

}
