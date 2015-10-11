/* 
 * Program converts nonnegative decimal integer value into another numeral system between 2 and 10 inclusive
 * Input: nonnegative decimal integer value, base of new numeral system
 * Output: value in new numeral system
 * Can include <stdio.h> only
 * Using of arrays is prohibited
 */

#include <stdio.h>

int main() {
    int decimal, base, result, numberPositions;
    int maxPower = 1;
    
    scanf("%d %d", &decimal, &base);

    numberPositions = decimal / base;
    for ( ; maxPower <= numberPositions; maxPower *= base );
    
    for ( ; maxPower > 1; maxPower /= base ) {
        result = decimal / maxPower;
        printf("%d", result);
        decimal -= maxPower * result;
    }
    
    printf("%d\n", decimal);
    
    return 0;
}
