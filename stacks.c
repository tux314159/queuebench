#include "skel.h"

struct Queue {
	volatile char *in, *out, *inp, *outp;
};

struct Queue mk_queue(int size)
{
	struct Queue q;
	q.in = malloc(2 * size * sizeof(*q.in));
	q.out = q.in + size * sizeof(*q.in);
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
		while (q->inp != q->in) {
			*(q->outp++) = *(--q->inp);
		}
	}
	return *(--q->outp);
}

MAIN
