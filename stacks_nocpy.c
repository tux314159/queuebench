#include "skel.h"

struct Queue {
	volatile char *in, *out, *inp, *outp, *base, *base2;
};

struct Queue mk_queue(int size)
{
	struct Queue q;
	q.base = malloc(2 * size * sizeof(*q.in));
	q.in = q.base;
	q.base2 = q.in + size * sizeof(*q.in);
	q.out = q.base2;
	q.inp = q.in;
	q.outp = q.out;
	return q;
}

void queue_push(struct Queue *q, char val)
{
	*(q->inp++) = val;
}

char queue_pop(struct Queue *q)
{
	if (q->outp == q->out) {
		q->outp = q->base;
		q->out = q->inp;
		q->in = q->base2;
		q->inp = q->base2;
		volatile char *t = q->base;
		q->base = q->base2;
		q->base2 = t;
	}
	return *(q->outp++);
}

MAIN
