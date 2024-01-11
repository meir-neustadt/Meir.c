#include <stdio.h>

int D(int num, int mp, int *c){
    int n=num;
    *c+=5;
    if(mp>3){
        int a=mp%2;
        num=D(num,mp/2, c);
        int r_num=num+num;
        r_num+=D(a,n,c);
        return r_num;
    }
    if(mp==3){return num+num+num;}
    if(mp==2){return num+num;}
    return num;
}

int DC(int num, int mp, int *c){
    *c+=3;
    if(mp>num){num=D(mp,num,c);}
    else{num=D(num,mp,c);}
    return num;
}

int F(int num, int R, int *c, int *n){
    *c+=5;
    if(R>3){
        int a=R%2;
        num=F(num,R/2,c,n);
        if(a==1){num=D(num,*n,c);}
        num=D(num,num,c);
        return num;
    }
    if(R==3){return D(D(num,num,c),num,c);}
    return D(num,num,c);
}

int main(){
    int c=0;
    int n=3;
    printf("%d\t\t",F(n,11,&c,&n));
    printf("%d\n",c);
    int x=0;
    printf("%d\t\t",DC(15,5,&x));
    printf("%d\n",x);    
    return 0;
}
