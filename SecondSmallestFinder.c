#include <stdio.h>

int main() {
    int a[10];
    for (int i = 0; i<10; i++){scanf("%d",&a[i]);}
    int smallest=a[0];
    int smallest_place=0;
    for (int i = 1; i<10; i++){if(a[i]<smallest){smallest=a[i];smallest_place=i;}}
    int second=(smallest_place==0)?a[1]:a[0];
    for (int i = 1; i<10; i++){if(a[i]<second && i!=smallest_place)second=a[i];}
    (second==smallest)?printf("N/A"):printf("%d",second);
    return 0;
}
