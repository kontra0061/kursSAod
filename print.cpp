#include "print.h"
#include "pch.h"

#include "print.h"
#include "pch.h"

void print_record(record* t) {
	SetConsoleCP(1251);///Меняем кодировку
	for (int j = 0; j < 30; j++)
		cout << t->username[j];
	cout << "|";
	cout << t->sum;
	cout << "|";
	for (int j = 0; j < 10; j++)
		cout << t->date[j];
	cout << "|";
	for (int j = 0; j < 22; j++)
		cout << t->lawyer[j];
	cout << "| " << endl;
}

void print_base(record* l[4000]) {
	int M = 20;
	int i = 0, num = 0;
	int c = 0;
	bool toNext = true;
	while (num >= 0) {
		system("cls");
		cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;
		while ((i < M) && (num <= N)) {
			num++;
			cout << "|";
			cout << setw(4) << num << ")|";
			print_record(l[i]);
			cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;

			i++;
		}
		SetConsoleCP(866);
		c = 0;
		while (true) {
			if (_kbhit()) {
				c = _getch();
				if (c == 13) {
					M += 20;
					break;
				}
				if (c == 8) {
					M -= 20;
					i -= 40;
					num -= 40;
					break;
				}
				if (c == 27) {
					return;
				}
			}
		}
	}
	return;
}

void print_stak(queue *p) {
	list *l = p->head;
	int M = 20; ///По столько элементов выводится на экран
	int i, flag = 1, num = 1;
	int c = 0;
	while (flag) {
		i = 0;
		system("cls");
		cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;
		while ((i < M) && (p->tail != l)) {
			cout << "|";
			cout << setw(4) << num << ")|";
			print_record(l->data);
			cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;
			num++;
			i++;
			if ((l->next == NULL) || (p->tail == l->next)) {
				num--;
				break;
			}
			else
				l = l->next;
		}
		SetConsoleCP(866);///Возвращаем кодировку
		c = 0;
		while ((c != 161) && (c != 27) && (c != 238)) {
			if (_kbhit()) {///Пользоавтель нажал на кнопку = 1
				c = _getch();
			}
		}
		if ((p->tail == l->next) && (c == 238)) {
			for (int j = 0; j < i - 1; j++) {
				if (l->prior == NULL) break;
				l = l->prior;
				num--;
			}
		}
		if (c == 161) {
			for (i = 0; i < 40; i++) {
				if ((l->prior == NULL) || (p->head == l)) break;
				l = l->prior;
				num--;
			}
		}
		else
			if (c == 27) {
				flag = 0;
				return;
			}
	}
}

void print_tree(vertex *&p) {
	if (p == NULL) return;
	list *tmp = p->fact;
	print_tree(p->left);
	tmp = p->fact;
	while (tmp != NULL) {
		print_record(tmp->data);
		tmp = tmp->next;
	}
	cout << "---------------------------------------------------------------------------" << endl;
	print_tree(p->right);
}