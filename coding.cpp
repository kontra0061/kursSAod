#include "pch.h"
#include "coding.h"
#include <cmath>
#include <iomanip>


const int M = 256;

struct code {
	unsigned char a;
	float q;
	int w[30];
	int l;
};

code A[M];

long int n = 0;
float entropy = (float)(0);
float midlength = (float)(0);
int sim_cf = 0, sim_f = 0;

void reading() {
	int i, j = 0, e;
	FILE *f;
	errno_t err; 
	err = fopen_s(&f, "testBase3.dat", "rb");
	if (err != 0)
	{
		cout << "Ошибка: невозможно открыть файл" << endl;
		exit(1);
	}
	for (i = 0; i < M; i++) {
		A[i].a = i;
		A[i].q = (float)(0);
		A[i].l = 0;
	}
	int flag = 100;
	unsigned char ac;
	while (!feof(f)) {
		fscanf_s(f, "%c", &ac);
		A[ac].q = A[ac].q + 1.0;
		n++;
	}
	fclose(f);
	for (i = 0; i < M; i++)
		if (A[i].q != (float)(0)) {
			A[i].q /= (float)n;
			j++;
		}
	n = (unsigned long int)(j);
	code tmp;
	for (i = 1; i < M - 1; i++) {
		e = 1;
		if (A[i].q == (float)(0))
			for (j = i + 1; j < M; j++)
				if (e)
					if (A[j].q != (float)(0)) {
						tmp = A[i];
						A[i] = A[j];
						A[j] = tmp;
						e = 0;
					}
	}
	i = 0;
	while (A[i].q != 0.0) i++;
	n = (unsigned long int)(i);
	for (i = 0; i < n; ++i)
		for (j = 1; j < n; ++j) {
			if (A[j].q > A[j - 1].q) {
				tmp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = tmp;
			}
		}
}

int shanon() {
	float q[M];
	q[0] = 0;
	for (int i = 1; i < n; i++)
	{
		q[i] = q[i - 1] + A[i].q;
		A[i].l = ceil(-log(A[i].q) / log(2));
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= A[i].l; j++)
		{
			q[i - 1] *= 2;
			A[i].w[j] = floor(q[i - 1]);
			if (q[i - 1] > 1) q[i - 1] -= 1;

		}
	}
	return 0;
}

void code_file() {
	FILE *f, *cf;
	errno_t err;
	err = fopen_s(&f, "Base1.dat", "rb");
	if (err != 0)
	{
		SetConsoleCP(866);
		cout << "Ошибка: невозможно открыть файл" << endl;
		exit(1);
	}
	err = fopen_s(&cf, "CodeBase.dat", "wb");
	char sim;
	while (!feof(f)) {
		fscanf_s(f, "%c", &sim);
		sim_f++;
		for (int i = 0; i < n; i++) {
			if (sim == A[i].a) {
				for (int j = 0; j < A[i].l; j++) {
					putc(A[i].w[j], cf);
					sim_cf++;
				}
			}
		}
	}
	_fcloseall();
}

void print() {
	entropy = (float)(0);
	midlength = (float)(0);
	int j;
	int i;
	float check = 0;
	for (i = 1; i < n; i++) {
		entropy += -A[i].q * log(A[i].q) / log(2);
		midlength += A[i].l * A[i].q;
	}

	for (i = 1; i < n; i++) {
		cout << setw(1) << (char)A[i].a << setw(3) << " ";
		cout << (float)A[i].q << " " << setw(2)	<< (int)A[i].l << " ";
		for (j = 1; j <= A[i].l; ++j)
			cout << A[i].w[j];
		cout << endl;
	}
	SetConsoleCP(866);
	cout << endl;
	cout << setw(8) << "Средняя длина: " << midlength << endl;
	cout << setw(8) << "Энтропия: " << entropy << endl;
	cout << setw(8) << entropy + 1 << " > " << midlength << endl << endl;
	cout << setw(8) << "Коэфициент сжатия: " << (float) sim_f / sim_cf << endl;
	_getch();
}