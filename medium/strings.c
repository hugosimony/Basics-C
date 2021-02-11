/*
 * Some basics functions manipulating strings
*/

#include "stddef.h"
#include "stdio.h"
#include <err.h>

//*****************************************
// Length
size_t len_str(char s[]){
    size_t i = 0;
    while(s[i] != 0)
        ++i;
    return i;
}

// With pointers
size_t mystrlen(char *s)
{
    size_t i = 0;
    for(char *p = s; *p != 0; p++) i++;
    return i;
}

//*****************************************
// Clear
void clear_string(char s[], size_t len){
    for(size_t i = 0; i < len; ++i)
        s[i] = 0;
}

//*****************************************
// Print Christmas Tree
void print_ctree(unsigned int n){
    for(unsigned j = 0; j < n-1; ++j) printf(" ");
    printf("*\n");
    unsigned c = 1;
    for(unsigned int i = 1; i < n*2-2; ++i){
        unsigned int j = c;
        for(; j < n-1; ++j)
            printf(" ");
        for(j = i % 2 == 0 ? 1 : 0; j < (c+1)*2-1; ++j)
            printf("*");
        if(i%2==0){
            printf("*");
            ++c;
        } 
        printf("\n");
    }
    for(unsigned int j = 0; j < n-1; ++j) printf(" ");
    printf("*\n");
    if(n>3){
        for(unsigned int j = 0; j < n-1; ++j) printf(" ");
        printf("*\n");
    }
}

//*****************************************
// Find substring
int get_index(char str1[], char str2[]){
    int l1 = len_str(str1);
    int l2 = len_str(str2);
    if(l2 > l1)
        return -1;
    int compare = 1;
    int j = 0;
    int index = -1;
    for(int i = 0; i < l1; i++){
        compare = 1;
        j = 0;
        while(compare == 1 && j < l2 && i+j<l1){
            if(str1[i+j] != str2[j])
                compare = 0;
            j++;
        }
        if(compare == 1){
            index = i;
            i = l1;
        }
    }
    return index;
}

//*****************************************
// Mix a string

// Check separator
int is_separator(char c){
    char separator[] = " ,;:!?./%*$=+)@_-('&1234567890\"\r\n";
    int separator_size = 33;
    int sep = 0;
    int i = 0;
    while(sep == 0 && i < separator_size){
        if(c == separator[i])
            sep = 1;
        ++i;
    }
    return sep;
}

// Check validity of a char
int is_valid_char(char c){
    if(((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) || is_separator(c) == 1)
        return 1;
    return 0;
}

// Check validity of the string
int check_validity(char s[], size_t len){
    int valid = 1;
    size_t i = 0;
    while(valid == 1 && i < len){
        valid = is_valid_char(s[i]);
        ++i;
    }
    return valid;
}

// Print a jumbled word
void print_jumbled_world(char s[]){
    size_t len = len_str(s);
    if(len <= 3){
        printf("%s", s);
    }
    else{
        printf("%c", s[0]);
        size_t i = 1;
        while(i < len-2){
            printf("%c%c", s[i+1], s[i]);
            i+=2;
        }
        if(len % 2 == 1)
            printf("%c", s[len-2]);
        printf("%c", s[len-1]);
    }
}

// Main
void mix(char s[]){
    size_t len = len_str(s);
    if(check_validity(s, len) != 1){
        errx(1, "String not valid : %s", s);
        return;
    }
    printf("%s\n", s);
    char world[len+1];
    clear_string(world, len+1);
    size_t pos = 0;
    for(size_t i = 0; i<len; ++i){
        if(is_separator(s[i]) == 1){
            pos = 0;
            print_jumbled_world(world);
            printf("%c", s[i]);
            clear_string(world, len+1);
        }
        else{
            world[pos] = s[i];
            pos++;
        }
    }
    if(world[0] != 0)
        print_jumbled_world(world);
    printf("\n");
}

//*****************************************

int main(int argc, char *argv[]) {
    // Do some stuff
    // print_ctree(10);
}