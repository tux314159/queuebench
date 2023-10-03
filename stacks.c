#include "skel.h"

struct Queue {
	int *in, *out, *inp, *outp;
};

struct Queue mk_queue(int size)
{
	struct Queue q;
	q.in = malloc(2 * size * sizeof(*q.in));
	q.out = q.in + size;
	q.inp = q.in;
	q.outp = q.out;
	return q;
}

void queue_push(struct Queue *q, int val)
{
	*(q->inp++) = val;
}

int queue_pop(struct Queue *q)
{
	if (q->outp == q->out) {
		while (q->inp != q->in) {
			*(q->outp++) = *(--q->inp);
		}
	}
	return *(--q->outp);
}

MAIN
