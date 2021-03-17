#include <stdio.h> 
#include <stdbool.h>
#include "date_util.h"

int main(){
    
    if (is_leap_year(2020)) {
        printf("2020 IS A LEAP YEAR\n");
    }
    else {
        printf("2020 ISN'T A LEAP YEAR\n");
    }

    int last_day_of_march = last_day_of_month(2021, 3);

    printf("THE LAST DAY OF MARCH IS %d\n", last_day_of_march);
    
}
