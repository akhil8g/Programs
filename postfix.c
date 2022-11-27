#include<stdio.h>
#include<string.h>
int top=-1,k=-1;
char p[10],o[10],a[20];
void push(int item){
	top++;
	a[top]=item;
}
void pop(){
	k++;
	o[k]=a[top];
	top--;
}
int precedence(char op){
	if(op=='+'||op=='-'){
		return 1;
	}
	else if(op=='*'||op=='/'){
		return 2;
	}
	else if(op=='^'){
		return 3;
	}
	
	else{
		return -1;
	}
}
void main(){
	 printf("Enter the expression: ");
	 scanf("%s",p);
	 push('(');
	 strcat(p,')');
	 int i=0;
	 while(p[i]!='\0'){
	 	if(p[i]=='('){
	 		push(p[i]);
	 	}
	 	else if(p[i]==')'){
	 		while(a[top]!='('){
	 			pop();
	 		}
	 		top--;
	 	}
	 	else if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'||p[i]=='^'){
	 		while(precedence(a[top])>=precedence(p[i])){
	 			pop();
	 		}
	 		push(p[i]);
	 	}
	 	else{
	 		k++;
	 		o[k]==p[i];
	 	}
	 	i++;
	 }
}