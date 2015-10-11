/* 
 * Task:
 * Hopper starts his way in cell #0 and finishes in cell #<cell>
 * Hopper can jump at a distance between 1 and <maxJump> inclusive at once
 * Jump distance is an integer value
 *
 * Program calculates the number of all possible ways of hopper from start to <cell> and prints it to "task.out" file
 * Input: <maxJump>, <cell> (contained in "task.in" file)
 * Output: quantity of all possible ways 
 *
 * Restrictions:
 * <maxJump> is between 1 and 100 inclusive
 * <cell> is between 1 and 100 inclusive
 * Quantity if ways is between 1 and 999 999 999 999 999 999 inclusive   
 * Can include <stdio.h> only
 */

#include <stdio.h>

int scan(FILE *in) {
    int scan;
    
    fscanf(in, "%d", &scan);
    return scan;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int maxJump = scan(in);
    int cell = scan(in);
    unsigned long long cells[cell];
    
    if ( maxJump > cell ) {
        maxJump = cell;
    }
    for ( int i = 0; i < maxJump; i++ ) {
        cells[i] = 1 << i;
    }
    for ( int i = maxJump; i < cell; i++ ) {
        unsigned long long cellSum = 0;
        
        for ( int j = i - maxJump; j < i; j++ ) {
            cellSum += cells[j];
        }
        cells[i] = cellSum;
    }
    
    fprintf(out, "%llu\n", cells[cell-1]);
    fclose(in);
    fclose(out);
    return 0;
}
