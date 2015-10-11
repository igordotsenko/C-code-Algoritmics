/* 
 * Realization of Quick sorting algoritm
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

//Searching of pivor element
int partition(int array[], int start, int end) {
    int mid = (start + end) / 2;
    int temp = array[end];
    int pivot = start;
    
    array[end] = array[mid];
    array[mid] = temp;
    for ( ; array[pivot] < array[end]; pivot++ );
    for ( int j = pivot + 1; j < end; j++ ) {
        if ( array[j] < array[end] ) {
            temp = array[pivot];
            array[pivot] = array[j];
            array[j] = temp;
            pivot += 1;
        }
    }
    temp = array[end];
    array[end] = array[pivot];
    array[pivot] = temp;
    
    return pivot;
}

//Sorting of array
void quickSort(int array[], int lo, int hi) {
    if ( lo < hi ) {
        int pivot = partition(array, lo, hi);
        
        quickSort(array, lo, pivot-1);
        quickSort(array, pivot+1, hi);
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = fileScan(in);
    int array[len];
    
    arrayScan(array, len, in);
    
    fclose(in);
    
    quickSort(array, 0, len-1);
    
    arrayPrint(array, len, out);
    
    fclose(out);
    
    return 0;
}
