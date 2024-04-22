#include<stdio.h>
int t = -1, s[100];
void push(char x){
    t = t + 1;
    s[t] = x;
}

void pop(){
    t = t - 1;
}

char top(){
    return s[t];
}

int empty(){
    if(t == -1) return 1;
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
    for(int i=0;i<size/2;i++){
        char temp = a[i];
        a[i] = a[size-i-1];
        a[size-i-1] = temp;
    }
    for(int i=0;i<size;i++){
        if (a[i] == '(') a[i] = ')';  
        else if (a[i] == ')') a[i] = '(';
    }
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
                    while (getPriority(a[i]) < getPriority(top())) {
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
    for(int i=0;i<j/2;i++){
        char temp = ans[i];
        ans[i] = ans[j-i-1];
        ans[j-i-1] = temp;
    }
    printf("Printing the prefix equation : ");
    for(int i=0;i<j;i++) printf("%c",ans[i]);
}