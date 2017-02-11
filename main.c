
#include <stdio.h>
#define MAX 10

int partition(int* array, int left, int right) {
    int s = array[right], tmp_1 = 0, tmp_2 = 0;
    int i = left - 1;
    int j;
    for(j = left; j < right; j++) {
        if(array[j] <= s) {
            i++;
            tmp_1 = array[i];
            array[i] = array[j];
            array[j] = tmp_1;
        }
    }
    tmp_2 = array[i+1];
    array[i+1] = array[right];
    array[right] = tmp_2;
    
    return i+1;
}

int* Quick_Sort(int* array, int left, int right) {
    if(left < right) {
        int q = partition(array, left, right);
        Quick_Sort(array, left, q-1);
        Quick_Sort(array, q+1, right);
    }
    return array;
}

int main() {
    int data[10] = {34,36,11,99,48,44,28,66,55,19}, *array;
    array = Quick_Sort(data, 0, MAX-1);
    for(int k=0; k<10;k++){printf("%d\n",*(array+k));}
    return 0;
}
