/* 
 * Realization of Select sorting algoritm
 * 
 * Parameters: sequence lenth, unsorted sequence of integers
 * 
 * Restrictions:
 * Nothing can be included
 */

void selectSort(int array[], int len) {
    for ( int i = 0, index = i; i < len; i++ ) {
        int min = array[i];
        
        for ( int j = i + 1; j < len; j++ ) {
            if ( array[j] < min ) {
                min = array[j];
                index = j;
            }
        }
        if ( array[i] > min ) {
            int temp = array[index];
            
            array[index] = array[i];
            array[i] = temp;
        }
    }
}
