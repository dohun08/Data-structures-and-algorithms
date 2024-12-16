#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_DEQUE_SIZE];
	int front, rear;
} DequeType;

// 오류 함수
void error(char *message) {
	puts(message);
	return;
}

// 초기화
void initDeque(DequeType* q) {
	q->front = 0;
	q->rear = 0;
}

// 공백 상태 검출 함수
int isEmpty(DequeType* q) {
	return q->front == q->rear;
}

// 포화 상태 검출 함수
int isFull(DequeType* q) {
	return (q->rear+1)%MAX_DEQUE_SIZE == q->front;
}

// 덱 출력 함수(원형 큐 출력과 동일)
void printDeque(DequeType* q){
	int i;
	printf("DEQUE(front=%d rear=%d) = ",q->front, q->rear);
	if (isEmpty(q)) {
		printf("덱은 공백상태입니다.\n");
		return;
	}
	 i = q->front;
	do{
		i = (i+1)% (MAX_DEQUE_SIZE);
		printf("%d | ",q->data[i]);
		if(i == q->rear) break;
	}while(i!=q->front);
	printf("\n");
}

// front 삽입 함수
void addFront(DequeType* q, element item) {
	if(isFull(q)) return ;
	q->data[q->front] = item;
	q->front = (q->front-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
}

// rear 삽입 함수
void addRear(DequeType* q, element item) {
	if(isFull(q)) return ;
	q->rear = (q->rear+1)%MAX_DEQUE_SIZE;
	q->data[q->rear] = item;
}

// front 삭제 함수
element deleteFront(DequeType* q) {
	if(isEmpty(q)) return 0;
	q->front = (q->front+1)%MAX_DEQUE_SIZE;
	return q->data[q->front];
}

// rear 삭제 함수
element deleteRear(DequeType* q) {
	if(isEmpty(q)) return 0;
	element temp = q->data[q->rear];
	q->rear = (q->rear-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
	return temp;
}

// front get 함수
element getFront(DequeType* q) {
	return q->data[q->front+1];
}

// rear get 함수
element getRear(DequeType* q) {
	return q->data[q->rear];
}

int main() {
	DequeType deque;
	int command;
	element idata;
	
	initDeque(&deque);
	while(1) {
		printf("명령어 입력\n1: front 삽입   2: rear 삽입   3: front 삭제   4: rear 삭제   5: front get   6: rear get   7: exit\n");
		scanf("%d",&command);
		switch(command) {
			case 1:
				printf("삽입할 데이터 입력 : ");
				scanf("%d",&idata);
				addFront(&deque,idata);
				printDeque(&deque);
				break;
			case 2:
				printf("삽입할 데이터 입력 : ");
				scanf("%d",&idata);
				addRear(&deque,idata);
				printDeque(&deque);
				break;
			case 3:
				printf("삭제한 데이터 : %d\n",deleteFront(&deque));
				printDeque(&deque);
				break;
			case 4:
				printf("삭제한 데이터 : %d\n",deleteRear(&deque));
				printDeque(&deque);
				break;
			case 5:
				printf("얻은 데이터 : %d\n",getFront(&deque));
				printDeque(&deque);
				break;
			case 6:
				printf("얻은 데이터 : %d\n",getRear(&deque));
				printDeque(&deque);
				break;
			case 7:
				return 0;
		}
		printf("\n");
	}
	
	return 0;
}