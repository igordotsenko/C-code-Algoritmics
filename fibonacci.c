/* 
 * Program calculates Fibonacci number with index between -46 and 46 inclusive
 * Input: index of Fibonacci number
 * Output: Fibonacci number     
 * Can include <stdio.h> only
 * Using of recursion is prohibited
 */

#include <stdio.h>

#define LIMIT 47

int main() {
    int sequence[LIMIT];
    int input;
    int isNegative = 0;
    int isEven = 0;
    
    scanf("%d", &input);
    
    if ( input <= 0 ) {
        if ( input == 0 ) {
            printf("0\n");
            return 0;
        }
        input *= -1;
        isNegative = 1;
        if ( input % 2 == 0 ) {
            isEven = 1;
        }
    }
    if ( input == 1 ) {
        printf("1\n");
        return 0;
    }
    for ( int i = 0; i <= 1; i++ ) {
        sequence[i] = i;
    }
    for ( int i = 2, j = 1, k = 0; i <= input; i++, j++, k++ ) {
        sequence[i] = sequence[j] + sequence[k];
    }
    if ( isNegative && isEven ) {
        sequence[input] *= -1;
        printf("%d\n", sequence[input]);
    } else {
        printf("%d\n", sequence[input]);
    }
    return 0;
}
