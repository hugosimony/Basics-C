/*
 * Some basics functions manipulating arrays
*/

#include <stddef.h>

//*****************************************
// Swap

void array_swap(int array[], size_t i, size_t j)
{
    int x = array[i];
    array[i] = array[j];
    array[j] = x;
}

// With pointers
void swap(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}

//*****************************************
// Is Sorted
int array_is_sorted(int array[], size_t len)
{
    int yes = 1;
    size_t i = 0;
    while(yes == 1 && i < len - 1){
        if(array[i] > array[i+1])
            yes = 0;
        i++;
    }
    return yes;
}

// With pointers
int array_is_sorted_ptr(int *begin, int *end)
{
    for(int *p = begin; p < end - 1; p++){
        if(*p > *(p+1))
            return 0;
    }
    return 1;
}

//*****************************************
// Sum
int array_sum(int *begin, int *end)
{
    int sum = 0;
    for(int *p = begin; p < end; p++)
        sum += *p;
    return sum;
}

//*****************************************
// Reverse (with pointers)
void array_reverse(int *begin, int *end)
{
    for(int *p = begin; p < end - (end - begin)/2 ; p++)
        swap(p, (end - p + begin - 1));
}

//*****************************************
// Minimum
int array_min(int array[], size_t len)
{
    int min = array[0];
    for(size_t i = 1; i < len; i++){
        if(array[i] < min)
            min = array[i];
    }
    return min;
}

//*****************************************
// Maximum
int array_max(int array[], size_t len)
{
    int max = array[0];
    for(size_t i = 1; i < len; i++){
        if(array[i] > max)
            max = array[i];
    }
    return max;
}

//*****************************************
// Minimum index (if there are several, returns the first)
size_t array_min_index(int array[], size_t len)
{
    size_t index = 0;
    int min = array[0];
    for(size_t i = 1; i < len; i++){
        if(array[i] < min){
            min = array[i];
            index = i;
        }
    }
    return index;
}

//*****************************************
// Maximum index (if there are several, returns the first)
size_t array_max_index(int array[], size_t len)
{
    size_t index = 0;
    int max = array[0];
    for(size_t i = 1; i < len; i++){
        if(array[i] > max){
            max = array[i];
            index = i;
        }
    }
    return index;
}

//*****************************************
// Right shift (with pointers)
void array_rshift(int *begin, int *end)
{
    for(int *p = end-1; p > begin; p--)
        *p = *(p-1);
}

//*****************************************
// Searching (plain method, returns len if x not in the array)
size_t array_find(int array[], size_t len, int x)
{
    size_t index = 0;
    int found = 0;
    while(found == 0 && index < len){
        if(array[index] == x){
            found = 1;
            index--;
        }
        index++;
    }
    return index;
}

//*****************************************
// Searching (binary search method, returns expected index if x not in the array)
size_t array_bin_search(int array[], size_t len, int x)
{
    int left = 0;
    int right = len;
    int mid = 0;
    int found = 0;
    while(found == 0 && left != right){
        mid = left + (right - left) / 2;
        if(array[mid] == x)
            found = 1;
        else if(array[mid] > x)
            right = mid;
        else
            left = mid + 1;
    }
    if(found == 0)
        return right;
    return mid;
}

//*****************************************
// Sorting (select sort method)
void array_select_sort(int array[], size_t len)
{
    int min = 0;
    size_t index = 0;
    for(size_t i = 0; i < len; i++){
        min = array[i];
        index = i;
        for(size_t j = i; j < len; j++){
            if(array[j] < min){
                min = array[j];
                index = j;
            }
        }
        array_swap(array, i, index);
    }
}

//*****************************************
// Sorting (quick sort method)
static void _quick_sort(int *array, size_t begin, size_t end)
{
    // Sorted
    if (begin >= end)
        return;

    // The pivot is the item at begin index
    int pivot = array[begin];

    // Where we exchange lower values
    size_t thres = begin + 1;
    for (size_t i = thres; i <= end; ++i)
        if (array[i] < pivot)
        {
            // Swap values and update threshold
            int tmp = array[i];
            array[i] = array[thres];
            array[thres] = tmp;

            ++thres;
        }

    // Place pivot at the right place
    array[begin] = array[thres];
    array[thres] = pivot;

    // Sort lower and higher partitions
    if (thres > 0)
        _quick_sort(array, begin, thres - 1);
    _quick_sort(array, thres + 1, end);
}

void array_quick_sort(int array[], size_t len)
{
    // Avoid overflows
    if (!len)
        return;

    _quick_sort(array, 0, len - 1);
}

//*****************************************
