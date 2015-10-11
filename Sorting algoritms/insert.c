/* 
 * Realization of Insert sorting algoritm
 * 
 * Parameters: sequence lenth, unsorted sequence of integers
 * 
 * Restrictions:
 * Nothing can be included
 */

void insertSort(int array[], int len) {
    for ( int i = 1, j = i - 1; i < len; i++ ) {
        int temp = array[i];
        
        for ( int k = i; temp < array[j] && j >= 0; j--, k-- ) {
            array[k] = array[j];
        }
        if ( temp < array[j+1] ) {
            array[j+1] = temp;
        }
        j = i;
    }
}
