#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
struct stack{
	int data[MAXSIZE];
	int top;
};
struct stack s;
void push(int new_data){//insert new data to top of stack
	s.top++;
	s.data[s.top] = new_data;
	return;
}
int pop(){//remove item from top
	int num;
	num = s.data[s.top];
	s.top--;
	return num;
}
void printStack(){
	for(int i = s.top; i >= 0; i--){
		printf("%d\n", s.data[i]);
	}
	return;
}
int main(){
	s.top = -1;
	push(1);//1
	push(2);//2 1
	push(3);//3 2 1
	pop();//2 1
	push(12);// 12 2 1
	push(8);//8 12 2 1
	printStack();
	return 0;
}
	

