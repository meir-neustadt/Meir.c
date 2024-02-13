#include <stdio.h>
#include <string.h>

void find_longest_common_substring(
    const char* str1,
    const char* str2,
    size_t* str1_substring_start_idx,
    size_t* str2_substring_start_idx,
    size_t* substring_length) {
        *substring_length=0;
        size_t len_a = strlen(str1);
        size_t len_b = strlen(str2);
        for(size_t i=0; i<len_a; i++){
            for(size_t j=0; j<len_b; j++){
                if(str1[i]==str2[j]){
                    size_t t=1;
                    size_t T=((len_a-i)<(len_b-j))?len_a:len_b;
                    while(t<T && str1[i+t]==str2[j+t]) t++;
                    if(t > *substring_length){
                        *substring_length = t;
                        *str1_substring_start_idx = i;
                        *str2_substring_start_idx = j;
                    }   
                }
            }
        }
}

int main(){	
    char* a = "hsafgksajaaaaaaaarytr";
    char* b = "hdjsfaaaaaaaaaaaaaaaouhg";
    size_t st1, st2, len;
    find_longest_common_substring(a, b, &st1, &st2, &len);
    printf("%zu %zu %zu\n", st1, st2, len);
    return 0;
}
