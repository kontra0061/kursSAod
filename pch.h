#ifndef PCH_H
#define PCH_H

#include <iostream> ///Для работы с клавиатурой
#include <conio.h>///для getch
#include <Windows.h>///Для русских букв
#include <iomanip>/// для установки кол-ва символов при выводе
#include <cstdio> ///Например для fread()
#include <cstring> ///Для работы со строками
#include <cstdlib>

using namespace std;

const int N = 4000;

struct record
{
	char username[30];
	unsigned short int sum;
	char date[10];
	char lawyer[22];
};

struct list {
	record *data;
	list *next; 
	list *prior;
};

struct queue {
	list *head;
	list *tail;
};

struct vertex {
	list *fact;
	vertex *left;
	vertex *right;
};

extern record* base[4000];
extern queue *stack;
extern int *w;
extern int num_h, num_t;

record* read_base(FILE *);

#endif //PCH_H
