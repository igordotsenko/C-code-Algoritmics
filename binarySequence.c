/* 
 * There is a sequence of nulls and ones
 * Program calculates minimal quantity of pair swaps of 1 and 0 needed for sequence to become sorted
 * Input: sequence of nulls and ones contained in file "task.in"
 * Output: minimal quantity of pair swaps of 1 and 0 needed for sequence to become sorted
 * 
 * Input and output examples:
 * Input: 1101
 * Output: 1
 *
 * Restrictions:
 * Can be included <stdio.h> only
 */

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int nulls = 0;
    int firstNulls = 0;
    int input;
    
    for ( ; fscanf(in, "%1d", &input) == 1; ) {
        if ( input == 0 ) {
            nulls += 1;
        }
    }
    
    rewind(in);
    
    for ( int i = 0; fscanf(in, "%1d", &input) == 1 && i < nulls; i++ ) {
        if ( input == 0 ) {
            firstNulls += 1;
        }
    }
    
    fclose(in);
    
    fprintf(out, "%d\n", nulls-firstNulls);
    
    fclose(out);
    
    return 0;
}
