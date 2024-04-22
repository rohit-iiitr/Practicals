#include<stdio.h>
int f=0,r=0,s[100];
void push(char x){
    r=r+1;
    s[r]=x;
    if(r==1) f=1;
}

void pop(){
    if(f==r && f!=0) f=r=0;
    else r=r-1;
}

char top(){
    if(f != r || (f==r && f!=0)) return s[r];
}

char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L';
}

int empty(){
    if(r==0) return 1;
    else return 0;
}

int isOperator(char c){
    return (!(c>=48&&c<=57) && !(c>=65&&c<=90) && !(c>=97&&c<=122)) ;
}

int getPriority(char c){
    if(c=='-' || c=='+') return 1;
    else if(c=='*' || c=='/' || c=='%') return 2;
    else if(c=='^') return 3;
    else if(c=='&') return 4;
    return 0;
}

void main(){
    char a[50],ans[50];
    printf("Enter the infix equation : ");
    scanf("%s",a);
    int size=0,j=0;
    while(a[size] != '\0') size++;
    for(int i=size;i>0;i--){
        a[i]=a[i-1];
    }
    a[0]='(',a[size+1]=')';
    size+=2;
    for(int i=0;i<size;i++){
        if ((a[i]>=48&&a[i]<=57) || (a[i]>=65&&a[i]<=90) || (a[i]>=97&&a[i]<=122)) ans[j++] = a[i];
        else if (a[i] == '(') push('(');
        else if (a[i] == ')') {
            while (top() != '(') {
                ans[j++] = top();
                pop();
            }
            pop();
        }
        else {
            if (isOperator(top())) {
                if (a[i] == '^') {
                    while (getPriority(a[i]) <= getPriority(top())) {
                        ans[j++] = top();
                        pop();
                    }
                }
                else {
                    while (getPriority(a[i]) < getPriority(top()) || getPriority(a[i]) == getPriority(top()) && associativity(a[i]) == 'L') {
                        ans[j++] = top();
                        pop();
                    }
                }
                push(a[i]);
            }
        }
    }
    while (!empty()) {
        ans[j++] = top();
        pop();
    }
    printf("Printing the postfix equation : ");
    for(int i=0;i<j;i++) printf("%c",ans[i]);
}