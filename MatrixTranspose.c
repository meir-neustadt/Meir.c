#include <stdio.h>

int main() {
    int a[3][3];
    for (int i = 0; i<3; i++){for (int k = 0; k<3; k++){scanf("%d",&a[i][k]);}}
    int b[3][3];
    for (int i = 0; i<3; i++){for (int k = 0; k<3; k++){b[k][i]=a[i][k];}}
    for (int i = 0; i<3; i++){for (int k = 0; k<3; k++){printf("%d ",b[i][k]);}printf("\n");}
    return 0;
}
