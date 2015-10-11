/* 
 * Task:
 * There are <barnQuantity> of barns on farm
 * Every barn is marked with <hasCow>. <hasCow> == 1 if there is cow and <hasCow> == 0 if not
 * After hurricane roofs of barns became broken
 * There is need to buy boards to fix barns with cows
 * Board with lenght 1 can be used for one barn only; with lenght 2 for two barns and so on. 
 * Board may have any lenght
 * Board can not be cut
 * <maxBoards> is maximum quantity of boards that could be bought
 * 
 * Program calculates the <minLenght> of boards needed to fix all barns with cows and prints it to "task.out" file
 * Input: <maxBoards>, <barnQuantity>, <hasCow1>, <hasCow2> ... <hasCowN> (contained in "task.in" file)
 * Output: <minLenght>
 * 
 * Example of input and output:
 * Input: 
 * 1 8 
 * 1 1 0 0 0 1 1 0
 * Output:
 * 7
 *
 * Restrictions:   
 * Can include <stdio.h> only
 */

#include <stdio.h>

//Scans value from file
int scan(FILE *in) {
    int value;
    
    fscanf(in, "%d", &value);
    
    return value;
}

//Scans array from file
void arrayScan(FILE *in, int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        fscanf(in, "%d", &array[i]);
    }
}

//Returns quantity of barns with cow
int cowCount(int array[], int size) {
    int hasCow = 0;
    
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] == 1 ) {
            hasCow += 1;
        }
    }
    return hasCow;
}

//Fills an array of distances between barns with cows. Returns quantity of breaks between barns with cow.
int breaksCount(int barns[], int breaks[], int size) {
    int last = size - 1;
    int breaksCount = 0;
    int counterIsActive = 0;
    int i = 0;
    int j = 0;
    
    for ( ; barns[i] == 0; i++ );
    
    for ( ; i < size; i++ ) {
        if ( barns[i] == 0 ) {
            if ( !counterIsActive ) {
                breaksCount += 1;
                counterIsActive = 1;
            }
            breaks[j] += 1;
        } else if ( counterIsActive ) {
            counterIsActive = 0;
            j += 1;
        }
    }
    if ( barns[last] == 0 ) {
        breaksCount -= 1;
    }
    breaks[j] = -1;
    return breaksCount;
}

//Bubble sort
void arraySort(int array[], int size) {
    int isSorted = 0;
    
    for ( ; size > 1 && isSorted == 0; size-- ) {
        isSorted = 1;
        for ( int i = 0, j = 1; j < size; j++, i++ ) {
            if ( array[j] < array[i] ) {
                int temp = array[i];
                
                array[i] = array[j];
                array[j] = temp;
                isSorted = 0;
            }
        }
    }
}

//Counts min lenght of boards needed
int lenhgtCount(int boards, int breaks[], int size, int minLenght) {
    int breaksToCover = size - boards + 1;
    
    for ( int i = 0; i < breaksToCover; i++ ) {
        minLenght += breaks[i];
    }
    return minLenght;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int maxBoards = scan(in);
    int barnQuantity = scan(in);
    int barns[barnQuantity];
    int breaks[barnQuantity];
    int hasCow;
    int breaksQuantity;
    int minLenght;
    
    if ( maxBoards == 0 || barnQuantity == 0 ) {
        fprintf(out, "0\n");
        return 0;
    }
    
    arrayScan(in, barns, barnQuantity);
    
    hasCow = cowCount(barns, barnQuantity);
    
    fclose(in);
    
    if ( hasCow == maxBoards ) {
        fprintf(out, "%d\n", maxBoards);
        fclose(out);
        return 0;
    }
    if ( hasCow == 0 ) {
        fprintf(out, "0\n");
        fclose(out);
        return 0;
    }
    if ( hasCow == barnQuantity ) {
        fprintf(out, "%d\n", barnQuantity);
        fclose(out);
        return 0;
    }
    
    for ( int i = 0; i < barnQuantity; i++ ) {
        breaks[i] = 0;
    }
    
    breaksQuantity = breaksCount(barns, breaks, barnQuantity);
    
    if ( barnQuantity < maxBoards ) {
        fprintf(out, "%d\n", hasCow);
        fclose(out);
        return 0;
    }
    
    arraySort(breaks, breaksQuantity);
    
    minLenght = lenhgtCount(maxBoards, breaks, breaksQuantity, hasCow);
    
    fprintf(out, "%d\n", minLenght);
    
    fclose(out);
    
    return 0;
}
