#include "skel.h"

struct Queue {
	int sz;
	int *q;
	int h, t;
};

struct Queue mk_queue(int sz)
{
	return (struct Queue){ .sz = sz, .q = malloc(sz * sizeof(int *)), .h = 0, .t = 0 };
}

void queue_push(struct Queue *q, int x)
{
	q->q[q->h] = x;
	q->h = (q->h + 1) % q->sz;
}

int queue_pop(struct Queue *q)
{
	int x = q->q[q->t];
	q->t = (q->t + 1) % q->sz;
	return x;
}

MAIN
