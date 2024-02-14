#include <stdbool.h>
#include <stdlib.h>

bool my_strcmp(char *str1, char *str2) {
    char* end_of_string_ptr = str1;
    for(end_of_string_ptr ; *end_of_string_ptr!='\0' ; end_of_string_ptr++) {}
    size_t len_a=(size_t)end_of_string_ptr;
    end_of_string_ptr = str2;
    for(end_of_string_ptr ; *end_of_string_ptr!='\0' ; end_of_string_ptr++) {}
    size_t len_b=(size_t)end_of_string_ptr;
    if(len_a!=len_b){return false;}
    for(size_t i;i<len_a;i++){if(str1[i]!=str2[i])return false;}
    return true;
}
