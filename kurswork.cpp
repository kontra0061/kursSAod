#include "pch.h"
#include "print.h"
#include "sort.h"
#include "search.h"
#include "tree_search.h"
#include "coding.h"
#include <fstream> ///Для работы с файлом

record* base[4000], *sbase[4000];
queue *stack;
int *w;
int num_h = 0, num_t = 0;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(866);
	FILE* testBase3;
	errno_t err;
	err = fopen_s(&testBase3, "testBase3.dat", "rb");
	if (err != 0)
	{
		cout << "Ошибка: невозможно открыть файл" << endl;
		exit(1);
	}

	for (int i = 0; i < 4001; i++) {
	
	base[i] = read_base(testBase3);
			}
		_fcloseall();
	
	///sort///
	
	copy_base(base, sbase);
	QuickSort(base, 0, 3999, 0);
	list *mas_sbase[N] = {};
	///tree///
	vertex *root = NULL;
	///code//
	SetConsoleCP(1251);
	reading();
	shanon();
	code_file();
	///-menu-///
	int enter = 0;
	while (true) {
		system("CLS");
		enter = 0;
		SetConsoleCP(866);
		cout << "\t------------------------------МЕНЮ------------------------" << endl;
		cout << "\t1. Посмотреть базу данных (< - назад, esc - выйти)" << endl;
		cout << "\t2. Просмотр отсортированной базы данных (QuickSort)" << endl;
		cout << "\t3. Поиск в отсортированной базе по ключу (публикация)" << endl;
		cout << "\t4. Поиск в дереве (год)" << endl;
		cout << "\t5. Кодирование статистика" << endl;
		cout << "\tEsc. Выход " << endl;
		cout << "\t----------------------------------------------------------" << endl;
		while ((enter != 27) && (enter != 49) && (enter != 50) && (enter != 51) && (enter != 52) && (enter != 53)) {
			if (_kbhit()) {
				enter = _getch();
			}
		}
		switch (enter) {
		case 27: return 0;
		case 49:
			print_base(base);
			break;
		case 50:
			print_base(sbase);
			break;
		case 51:
			stack = NULL;
			root = NULL;
			char X[3];
			SetConsoleCP(866);
			cout << "Введите ключ (три буквы публикации): ";
			cin >> X;
		//	masiving(sbase, mas_sbase);
		//	binary_search(X, mas_sbase, stack);
			if (stack->head != stack->tail)
				print_stak(stack);
			else
				cout << "Такой записи нет";
			_getch();
			break;
	/*	case 52:
			if (mas_sbase[0] == NULL) break;
			if (root != NULL) {
				delete_tree(root);
				root = NULL;
			}
			short int x;
			weight(mas_sbase);
			DOP_A2(root, mas_sbase, num_h, num_t);
			cout << "Посмотреть дерево (1/0) ";
			cin >> x;
			if (x == 1) {
				print_tree(root);
			}
			while (true) {
				SetConsoleCP(866);
				cout << "Книги какого года хотите увидеть? (ext = 1)" << endl;
				cin >> x;
				if (x == 1) break;
				tree_search(root, x);
			}
			break;
			*/
		case 53:
			print();
			break;
		}
	}
	return 0;
}