// Function prototype
void quicksort(float *array, int start, int end);
int partition(float *array, int start, int end);

void quicksort(float *array, int start, int end) {

    if(end > start) {
        int pivot_index = partition(array, start, end);
        quicksort(array, start, pivot_index - 1);
        quicksort(array, pivot_index + 1, end);
    }

}

int partition(float *array, int start, int end) {
    
    float pivot = array[end];
    int p_index = start;

    for(int i = start; i < end; i++) {
        
        if(array[i] <= pivot) {
            float temp = array[p_index];
            array[p_index] = array[i];
            array[i] = temp;

            p_index++;

        }

    }

    float temp = array[p_index];
    array[p_index] = pivot;
    array[end] = temp;

    return p_index;

}