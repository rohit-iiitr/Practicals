#include<stdio.h>
void callbyref(int* a,int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
                                
}
int main(){
   int n,m;
   printf("Enter the numbers: ");
   scanf("%d %d",&n,&m);
   callbyref(&n,&m);
    printf("%d %d",n,m);
}