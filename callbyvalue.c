#include<stdio.h>
int sumbyval(int a, int b){
    int temp;
    temp= a + b;
    return temp;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    sumbyval(a,b);
    printf("%d ",swapbyval(a,b));
}