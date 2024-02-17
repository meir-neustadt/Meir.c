#include <stdio.h>
#include <stdbool.h>

#define LEN_ARRAY(a) sizeof(*a)
#define IS_LETTER(a) (a>='A' && a<='Z'  ||  a>='a' && a<='z')
#define IS_NUMBER(a) (a>='0' && a<='9')
#define IS_CHAR(a, boold) ({char* list_d="., \n\t:;'?!"; for(int i = 0; i<sizeof(list_d); i++)if(a==list_d[i])boold=1;})
#define IS_READY(a, boold) ({if(IS_LETTER(a) || IS_NUMBER(a) || a=='\0') boold=1; else IS_CHAR(a, boold);})
enum {one=1,two,three};
typedef int i;

int main() {
    char* a = "flf";
    char b[12];
    b[0]='l'; b[1]='2'; b[2]='t'; b[3]='K'; b[4]='8'; b[5]='7'; for(int i=6;i<12;i++)b[i]='\0'; b[9]='$';
    int size_a = LEN_ARRAY(a);bool ba=1;
    i size_b = LEN_ARRAY(b);bool bb=1;
    for(int i=0;i<size_a;i++){bool bn=0; IS_READY(a[i], bn); if(bn==0) ba=0;}
    for(int i=0;i<size_b;i++){bool bn=0; IS_READY(b[i], bn); if(bn==0) bb=0; if(b[i]=='\0')break;}
    printf("%d %d %s %s %d",ba,bb,a,b,sizeof(*a));

    return 0;
}
