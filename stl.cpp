#include <queue>
using namespace std;

#ifdef _DEBUG
#include <stdio.h>
#define DBG(x)
#define SZ 16
#define N 1
#else
#define DBG(x) (void)x
#define SZ 4096
#define N 10000
#endif

int main(void)
{
	queue<int> q;
	for (int i = 0; i < N; i++) {
		for (int i = 0; i < SZ/2; i++) {
			q.push(i);
		}
		for (int i = 0; i < SZ/4; i++) {
			DBG(q.front());
			q.pop();
		}
		for (int i = 0; i < SZ/2; i++) {
			q.push(i);
		}
		for (int i = 0; i < SZ/4; i++) {
			DBG(q.front());
			q.pop();
		}
		for (int i = 0; i < SZ/2; i++) {
			q.push(i);
		}
		for (int i = 0; i < SZ/4; i++) {
			DBG(q.front());
			q.pop();
		}
		for (int i = 0; i < SZ/4; i++) {
			q.push(i);
		}
		for (int i = 0; i < SZ; i++) {
			DBG(q.front());
			q.pop();
		}
	}
}
