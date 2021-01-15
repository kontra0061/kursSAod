#include "pch.h"
#include "tree_search.h"
#include "print.h"
#include <time.h>

extern int num_h, num_t;
/*
void add(vertex *&point, record *x) {
	vertex **p = &point;
	list *tmp;

	while (*p) {
		if ((*x).year < (*p)->fact->data->year) {
			p = &((*p)->left);
		}
		else
			if ((*x).year > (*p)->fact->data->year) {
				p = &((*p)->right);
			}
			else
				if ((*x).year == (*p)->fact->data->year) {
					tmp = (*p)->fact;
					while (tmp->next != NULL) {
						tmp = tmp->next;
					}
					tmp->next = new list();
					tmp->next->data = x;
					tmp->next->prior = (*p)->fact;
					tmp->next->next = NULL;
					return;
				}
	}
	if ((*p) == NULL) {
		(*p) = new vertex();
		(*p)->fact = new list();
		(*p)->fact->data = x;
		(*p)->fact->next = NULL;
		(*p)->fact->prior = NULL;
		(*p)->left = NULL;
		(*p)->right = NULL;
	}
}

void DOP_A2(vertex *&q, list *mas[N], int L, int R) {
	int wes = 0, summa = 0;
	int i;
	L = L - num_h;
	R = R - num_h;
	if (L <= R)
	{
		for (i = L; i <= R; i++)
			wes = wes + w[i];
		for (i = L; i <= R; i++)
		{
			if ((summa <= (wes / 2)) && ((summa + w[i]) >= (wes / 2)))
				break;
			summa = summa + w[i];
		}
		add(q, mas[i + num_h]->data);
		DOP_A2(q, mas, L + num_h, i - 1 + num_h);
		DOP_A2(q, mas, i + 1 + num_h, R + num_h);
	}
}

void weight(list *mas[N]) {
	w = new int[num_t - num_h + 1];
	for (int i = 0; i < (num_t - num_h + 1); i++) {
		w[i] = rand() % 999 + 1;
	}
	QuickSort(w, mas, 0, num_t - num_h);
}

void QuickSort(int *a, list *mas[N],  int left, int right) {
	int current, i, j, t;
	list *tmp;
	current = mas[left + num_h]->data->year; 
	i = left; 
	j = right;

	while (i <= j) {
		while (mas[i + num_h]->data->year < current) {
			i++;
		}
		while (mas[j + num_h]->data->year > current) {
			j--;
		}
		if (i <= j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			tmp = mas[i + num_h];
			mas[i + num_h] = mas[j + num_h];
			mas[j + num_h] = tmp;
			i++; j--;
		}
	}

	if (left < j) {
		QuickSort(a, mas, left, j);
	}
	if (i < right) {
		QuickSort(a, mas, i, right);
	}
}

void tree_search(vertex *&p, short int x) {
	vertex *tmp = p;
	while (tmp != NULL) {
		if (tmp->fact->data->year == x) {
			print_base(tmp->fact);
			return;
		}
		else
			if (tmp->fact->data->year > x)
				tmp = tmp->left;
			else
				if (tmp->fact->data->year < x)
					tmp = tmp->right;
	}
	cout << " нига не найдена" << endl;
}

void delete_tree(vertex *&p) {
	if (p != NULL) {
		delete_tree(p->left);
		delete_tree(p->right);
		delete p;
	}
}
*/