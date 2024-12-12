#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 5
typedef int element;
typedef struct{
	int front;
	int rear;
	element arr[MAX_Q_SIZE];
}Queue;
//Queue 구조체 정의
void error(char* message){
	printf("%s\n",message);
	exit(0);//메인함수 종료
}
void initQueue(Queue* q){
	q->front = -1;
	q->rear = -1;
}
int isFull(Queue* q){
 if(q->rear == MAX_Q_SIZE) return 1;
	return 0;
}
int isEmpty(Queue* q){
 	if(q->rear == q->front) return 1;
	return 0;
}
void enQueue(Queue* q,element item){
 if(isFull(q)) return ;
	q->arr[++(q->rear)] = item;
}
element deQueue(Queue* q){
	if(isEmpty(q)) return 0;
	return q->arr[(q->front)++];
}
void queuePrint(Queue* q){
	int i;
	for(i=0;i<MAX_Q_SIZE;i++){
		if (i<=q->front || i > q->rear){
			printf("%7c",'|');
		}
		else{
			printf("%4d%3c",q->arr[i],'|');
		 }
	}
	printf("\n");
}
int main() {
	element item = 0;
	Queue * q = malloc(sizeof(Queue));
	initQueue(q);
	printf("\n");
	enQueue(q,10); 
	queuePrint(q);
	enQueue(q,20); 
	queuePrint(q);
	enQueue(q,30); 
	queuePrint(q);
	
	item = deQueue(q); 
	queuePrint(q);
	item = deQueue(q); 
	queuePrint(q);
	return 0;
}