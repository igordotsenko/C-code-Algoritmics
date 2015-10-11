/* 
 * Realization of Merge sorting algoritm
 * 
 * Input: sequence lenth, unsorted sequence of integers (contained in "task.in" file)
 * Output: sorted sequence
 * 
 * Restrictions:
 * Can be included <stdio.h> only
 */

#include <stdio.h>

//Scans value from file
int fileScan(FILE *in) {
    int value;
    
    fscanf(in, "%d", &value);
    
    return value;
}

//Scans array from file
void arrayScan(int array[], int len, FILE *in) {
    for ( int i = 0; i < len; i++ ) {
        fscanf(in, "%d", &array[i]);
    }
}

//Prints array to file
void arrayPrint(int array[], int len, FILE *out) {
    int last = len - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

//Merges two arrays
void merge(int array[], int lo, int mid, int hi) {
    int lastFirst = mid - 1;
    int lastSecond = hi - 1;
    int arrayTemp[hi];
    int i = lo;
    int j = mid;
    int index = lo;
    
    for ( ; i <= lastFirst && j <= lastSecond; index++ ) {
        if ( array[i] < array[j] ) {
            arrayTemp[index] = array[i];
            i += 1;
        } else {
            arrayTemp[index] = array[j];
            j += 1;
        }
    }
    for ( ; i <= lastFirst; i++, index++ ) {
        arrayTemp[index] = array[i];
    }
    for ( ; j <= lastSecond; j++, index++ ) {
        arrayTemp[index] = array[j];
    }
    for ( int k = lo; k < hi; k++ ) {
        array[k] = arrayTemp[k];
    }
}

//Sorts an array
void mergeSort(int array[], int lo, int hi) {
    int mid = (lo + hi) / 2;
    
    if ( lo < mid ) {
        mergeSort(array, lo, mid);
        mergeSort(array, mid, hi);
        merge(array, lo, mid, hi);
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = fileScan(in);
    int array[len];
    
    arrayScan(array, len, in);
    
    fclose(in);
    
    mergeSort(array, 0, len);
    
    arrayPrint(array, len, out);
    
    fclose(out);
    
    return 0;
}
