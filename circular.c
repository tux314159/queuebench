#include "skel.h"

struct Queue {
	int sz;
	volatile char *q;
	int h, t;
};

struct Queue mk_queue(int sz)
{
	return (struct Queue){ .sz = sz, .q = malloc(sz), .h = 0, .t = 0 };
}

void queue_push(struct Queue *q, char x)
{
	q->q[q->h] = x;
	q->h = (q->h + 1) % q->sz;
}

char queue_pop(struct Queue *q)
{
	char x = q->q[q->t];
	q->t = (q->t + 1) % q->sz;
	return x;
}

MAIN
