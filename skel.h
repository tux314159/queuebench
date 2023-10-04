#include <stdlib.h>

#ifdef _DEBUG
#include <stdio.h>
#define DBG(x) printf("%d\n", x);
#define SZ 16
#define N 1
#else
#define DBG(x) x
#define SZ (1<<20)
#define N 100
#endif

#define MAIN int x = 0;\
int main(void)\
{\
	struct Queue q = mk_queue(SZ);\
	for (int i = 0; i < N; i++) {\
		for (int i = 0; i < SZ/2; i++) {\
			queue_push(&q, i);\
		}\
		for (int i = 0; i < SZ/4; i++) {\
			DBG(queue_pop(&q));\
		}\
		for (int i = 0; i < SZ/2; i++) {\
			queue_push(&q, i);\
		}\
		for (int i = 0; i < SZ/4; i++) {\
			DBG(queue_pop(&q));\
		}\
		for (int i = 0; i < SZ/2; i++) {\
			queue_push(&q, i);\
		}\
		for (int i = 0; i < SZ/4; i++) {\
			DBG(queue_pop(&q));\
		}\
		for (int i = 0; i < SZ/4; i++) {\
			queue_push(&q, i);\
		}\
		for (int i = 0; i < SZ; i++) {\
			DBG(queue_pop(&q));\
		}\
	}\
	for (int i = 0; i < SZ; i++) {\
		queue_push(&q, i);\
	}\
	for (int i = 0; i < SZ; i++) {\
		x ^= queue_pop(&q);\
	}\
}
