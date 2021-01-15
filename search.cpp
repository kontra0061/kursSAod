#include "search.h"
#include "pch.h"

void masiving(list *l, list *r[N]) {
	for (int i = 0; i < N; i++) {
		r[i] = l;
		l = l->next;
	}
}

int compare(char *a, char *b) {
	for (int i = 0; i < 3; i++) {
		if ((int)a[i] < (int)b[i]) return 1;
		else
			if ((int)a[i] > (int)b[i]) return -1;
	}
	return 0;
}

