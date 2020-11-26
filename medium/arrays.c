/*
 * Some basics functions manipulating arrays
*/

//*****************************************
// Insert -> Insert Sort (plain method)

// Insert
void array_insert(int *begin, int *end, int x){
    int *p = end;
    for(; p > begin && x < *(p-1); p--)
        *p = *(p-1);
    *p = x;
}

// Insert Sort
void array_insert_sort(int *begin, int *end){
    for(int *p = begin; p < end; p++)
        array_insert(begin, p, *p);
}

//*****************************************
// Insert -> Insert Sort (binary search method)

// Binary Search
int *binary_search(int *begin, int *end, int x){
    if(begin == end)
        return end;
    int *mid = begin + (end-begin)/2;
    if(*mid == x)
        return mid;
    if(x < *mid)
        return binary_search(begin, mid, x);
    return binary_search(mid+1, end, x);
}

// Insert
void array_insert_bin(int *begin, int *end, int x){
    int *i = binary_search(begin, end, x);
    int *p = end;
    for(; p > i; p--)
        *(p) = *(p-1);
    *p = x;
}

// Insert Sort
void array_insert_sort_bin(int *begin, int *end){
    for(int *p = begin; p < end; p++)
        array_insert_bin(begin, p, *p);
}

//*****************************************