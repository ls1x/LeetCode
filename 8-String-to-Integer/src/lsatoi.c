#include <stdbool.h>
#include <lsatoi.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int LSATOI(const char * s) {
    int i = 0;
    int count = 1;
    unsigned long result = 0;
    bool OVERFLOW = false;
    bool sign_character = false;

    // Check if there are any spaces before the number
    while ((int)s[i] == 32){
        i++;
    }

    // Check if there are any sign character after the spaces
    if (s[i] == '+' || s[i] == '-'){
        if (s[i] == '+'){
            sign_character = false;
        } else if (s[i] == '-') {
            sign_character = true;
        }
        i++;
    }

    // Skiping numbers starting with 0
    while (s[i] == '0'){
        i++;
    }

    // Check if the next character is a number.
    // If yes, typecast to int.
    while (s[i] >= '0' && s[i] <= '9'){
        if ((result + (s[i] - '0')) > MAX_INT){
            result = MAX_INT;
            OVERFLOW = true;
            break;
        }
        result = result + (s[i] - '0');
        if (s[i + 1] && (s[i + 1] >= '0' && s[i + 1] <= '9')){
            // Needed if the number is bigger than 1 digit.
            if ( ((count + 1) > 10) || ((result * 10) > MAX_INT) ){
                OVERFLOW = true;
                result = MAX_INT;
                break;
            }
            count++;
            result = result * 10;
        } else {
            break;
        }
        i++;
    }

    /*
    * Performs the following checks:
    *   - Number is negative?
    *   - Number overflows or underflows?
    *
    * Based on those checks, it returns the correct number.
    */
    if (sign_character == true && result == MAX_INT && OVERFLOW == true){
        return MIN_INT;
    }
    if (sign_character == true){
        return -result;
    } else {
        return result;
    }
}
