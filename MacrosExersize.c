#include <stdio.h>
#include <stdbool.h>

#define MIN(a,b) a < b ? a : b
#define CALCULATE(x,y,z) z=='+' ? x+y : (z=='-' ? x-y : (z=='*' ? x*y : (z=='/' ? x/y : 0 )))
#define NON_NULL_NUMBER(a) for(int i=0; i<sizeof(a)/4; i++) {if(a[i]!=0)w++;}
#define IS_EMPTY(a,b) int w = 0; for(int i=0; i<sizeof(a)/4; i++) {if(a[i]!=0)w++;} b=(w==0 ? 1 : 0)
#define IS_EMPTY_I(a,b)   w = 0; for(int i=0; i<sizeof(a)/4; i++) {if(a[i]!=0)w++;} b=(w==0 ? 1 : 0)
#define EMPTY(a) for(int i=0;i<sizeof(S)/4;i++)S[i]=0
#define A   bool Empty = IS_EMPTY(S);  printf("\n%s\n", Empty? "true":"false");  a=0;
#define IS_IN_RANGE(i,a,b) (i>=a || i<=b)
int main(){
    int a = 4;
    int c = 7;
    printf("%d\n",MIN(a, c));
    char s = '-';
    int n = 0;
    printf("%d\t%d\t",n=CALCULATE(a,c,s), a*(int)6.f);
    int S[8];
    IS_EMPTY(S,c);
    printf("%d",c);
    EMPTY(S);
    IS_EMPTY_I(S,c);
    printf("%d",c);
    printf("%lld\n",sizeof(a));
    int f=6;
    int d=13;
    int r=11;
    bool InRange = IS_IN_RANGE(r,f,d);
    printf("%d", InRange) ;
    return 0;
}
