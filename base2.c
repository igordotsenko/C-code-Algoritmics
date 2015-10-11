/* 
 * Program converts decimal integer value into another numeral system between 2 and 36 inclusive
 * Input: nonnegative decimal integer value, base of new numeral system
 * Output: value in new numeral system
 * Can include <stdio.h> only
 * Can use loops only
 * Can use int type only
 * Using of arrays is prohibited
 */

#include <stdio.h>

int main() {
    int decimal, base, numberPositions, result;
    int shift = 'A' - 10;
    int power = 1;
    
    scanf("%d %d", &decimal, &base);
    
    if ( decimal <= 0 ) {
        if ( decimal == 0 ) {
            printf("0\n");
            return 0;
        }
        printf("-");
        decimal *= -1;
    }
    
    numberPositions = decimal / base;
    for ( ; power <= numberPositions; power *= base );
    
    for ( ; power > 1; power /= base ) {
        result = decimal / power;
        if ( result > 9 ) {
            printf("%c", result+shift);
        } else {
            printf("%d", result);
        }
        decimal %= power;
    }
    if ( decimal > 9 ) {
        printf("%c\n", decimal+shift);
    } else {
        printf("%d\n", decimal);
    }
    
    return 0;
}
