#include <stdlib.h>

#define SZ (1<<20)
#define N 100

#include <stdio.h>
#ifdef _DEBUG
#include <stdio.h>
#define DBG(x) printf("%d\n", x);
#else
#define DBG(x) x
#endif

#define MAIN \
int main(void)\
{\
	struct Queue q = mk_queue(SZ);\
	for (size_t i = 0; i < N; i++) {\
		for (size_t i = 0; i < SZ/2; i++) {\
			queue_push(&q, i);\
		}\
		for (size_t i = 0; i < SZ/4; i++) {\
			DBG(queue_pop(&q));\
		}\
		for (size_t i = 0; i < SZ/2; i++) {\
			queue_push(&q, i);\
		}\
		for (size_t i = 0; i < SZ/4; i++) {\
			DBG(queue_pop(&q));\
		}\
		for (size_t i = 0; i < SZ/2; i++) {\
			queue_push(&q, i);\
		}\
		for (size_t i = 0; i < SZ/4; i++) {\
			DBG(queue_pop(&q));\
		}\
		for (size_t i = 0; i < SZ/4; i++) {\
			queue_push(&q, i);\
		}\
		for (size_t i = 0; i < SZ; i++) {\
			DBG(queue_pop(&q));\
		}\
	}\
	queue_push(&q, 0);\
	if (queue_pop(&q)) return 1;\
}
