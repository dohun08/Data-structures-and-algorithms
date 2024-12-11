#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100
typedef int element;
//int를 element로 재정의
//문제) 스택 구조체 변수 정의 
//문제) 전역변수로 스택 구조체 선언선언
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stack;

Stack s;

void initStack(){
	s.top = -1;
}
bool isEmpty(){
	return s.top == -1;	
}
bool isFull(){
	return s.top == MAX_STACK_SIZE-1;
}	 
void push(element item){
	 s.data[++(s.top)] = item; 
}
element pop(){ //반환후 제거
	if(isEmpty()) return 0;
	else return s.data[(s.top)--];
}
element peek(){//반환만
	if(isEmpty()) return 0;
	else return s.data[s.top];
}
int main(){
	initStack();
	push(1);
	push(2);
	push(3);
	printf("%d\n",pop());
	printf("%d\n",peek());
	printf("%d\n",pop());
	return 0;

}