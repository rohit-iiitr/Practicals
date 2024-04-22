#include<stdio.h>
#include<string.h>
int top=-1;
char s[50][50];
int isOperator(char c){
    return (!(c>=48&&c<=57) && !(c>=65&&c<=90) && !(c>=97&&c<=122)) ;
}

void main(){
    char a[50],ans[50];
    printf("Enter the prefix equation : ");
    scanf("%s",a);
    int size=0;
    while(a[size] != '\0') size++;
    for(int i=0;i<size/2;i++){
        char temp = a[i];
        a[i] = a[size-i-1];
        a[size-i-1] = temp;
    }
    for(int i=0;i<size;i++){
        if(!isOperator(a[i])){
            top+=1;
            s[top][0]=a[i], s[top][1]='\0';
        }
        else{
            int s1=0,s2=0,j=0;
            char x[50],y[50];
            while(s[top][s2] != '\0') s2++;
            strcpy(y,s[top]);
            top-=1;
            while(s[top][s1] != '\0') s1++;
            strcpy(x,s[top]);
            top-=1;
            top+=1;
            for(int k=0;k<s1;k++) s[top][j++]=x[k];
            s[top][j++]=a[i];
            for(int k=0;k<s2;k++) s[top][j++]=y[k];
        }
    }
    strcpy(ans,s[top]);
    printf("The infix equation is : ");
    for(int i=size-1;i>=0;i--) printf("%c",ans[i]);
}