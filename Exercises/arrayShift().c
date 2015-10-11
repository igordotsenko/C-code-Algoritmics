/* 
 * Function performs shift of array to the right for <shift> elements
 * 
 * Parameters: 
 * int array[] - array that should be shifted
 * in size - size of array
 * shift - shift amount
 *
 * Restrictions:
 * Nothing can be included
 * Required time complexity: O(N)
 */

void arrayShift(int array[], int size, int shift) {
    int bufferSize;
    
    shift %= size;
    if ( shift < 0 ) {
        shift += size;
    }
    bufferSize = size - shift;
    
    if ( shift < bufferSize ) {
        int buffer[shift];
        
        for ( int i = 0, j = bufferSize; j < size; i++, j++ ) {
            buffer[i] = array[j];
        }
        for ( int i = size - 1, j = bufferSize - 1; j >= 0; i--, j-- ) {
            array[i] = array[j];
        }
        for ( int i = 0; i < shift; i++ ) {
            array[i] = buffer[i];
        }
    } else {
        int buffer[bufferSize];
        
        for ( int i = 0; i < bufferSize; i++ ) {
            buffer[i] = array[i];
        }
        for ( int i = 0, j = bufferSize; j < size; i++, j++ ) {
            array[i] = array[j];
        }
        for ( int i = shift, j = 0; i < size; i++, j++ ) {
            array[i] = buffer[j];
        }
    }
}

