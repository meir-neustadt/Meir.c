#include <stdio.h>
#include <stdbool.h>

bool IsPrimary (int num){
if(num%2==0){printf("%d\n",2); return false;}
int i = 3;
int i_num = (int)((float)num/2.f);
while(i<i_num){
    if(num%i==0){printf("%d",i); return false;}
    i+=2;
    i_num=(int)((float)num/(float)i);
}
return true;};

int main() {
int num;
printf("Insert a number: ");
scanf("%d", &num);
printf("%s", (IsPrimary(num)?"true":"false"));
return 0;
}
