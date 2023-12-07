#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;
int mas6[6][6], mas8[8][8], mas10[10][10];


void MATR(int* p, int b){ 
	system("Cls");
	for (int *start = p, *end = start + b*b; start < end; start++){
		if ((start - p) % b == 0 && start != p)
			cout << "\n";
		cout << '[' << setw(4) << left <<  *start <<  ']' << ' ';
	}
	cout << '\n';
	Sleep(150);
}

void MATR1(int* p, int b) {
	for (int* start = p, *end = start + b * b; start < end; start++) {
		if ((start - p) % b == 0 && start != p)
			cout << "\n";
		cout << '[' << setw(4) << left << *start << ']' << ' ';
	}
	cout << '\n';
}

void DEISTV(int* p, int b) {
	system("cls");
	string z;
	int a;
	while (1) {
		cout << "Выберите действие:\n1 +\n2 -\n3 *\n4 /\nX Назад\n";
		cin >> z;
		int* end = p + b * b;
		if (z == "1") {
			system("cls");
			cout << "Введите число:\n";
			cin >> a;
			system("cls");
			cout << "Матрица до действия:\n";
			MATR1(p, b);
			cout << "\n\nМатрица после действия:\n";
			for (int* start = p; start < end; start++)
			{
				*start += a;
				if ((start - p) % b == 0 && start != p)
					cout << '\n';
				cout << '[' << setw(4) << left << *start << ']' << ' ';
			}
			cout << "\n";
			system("pause");
			system("cls");
		}
		else if (z == "2") {
			system("cls");
			cout << "Введите число:\n";
			cin >> a;
			system("cls");
			cout << "Матрица до действия:\n";
			MATR1(p, b);
			cout << "\n\nМатрица после действия:\n";
			for (int* start = p; start < end; start++)
			{
				*start -= a;
				if ((start - p) % b == 0 && start != p)
					cout << '\n';
				cout << '[' << setw(4) << left << *start << ']' << ' ';
			}
			cout << "\n";
			system("pause");
			system("cls");
		}
		else if (z == "3") {
			system("cls");
			cout << "Введите число:\n";
			cin >> a;
			system("cls");
			cout << "Матрица до действия:\n";
			MATR1(p, b);
			cout << "\n\nМатрица после действия:\n";
			for (int* start = p; start < end; start++)
			{
				*start *= a;
				if ((start - p) % b == 0 && start != p)
					cout << '\n';
				cout << '[' << setw(4) << left << *start << ']' << ' ';
			}
			cout << "\n";
			cout << "Умножить\n";
			system("pause");
			system("cls");
		}
		else if (z == "4") {
			system("cls");
			cout << "Введите число:\n";
			cin >> a;
			system("cls");
			cout << "Матрица до действия:\n";
			MATR1(p, b);
			cout << "\n\nМатрица после действия:\n";
			for (int* start = p; start < end; start++)
			{
				*start /= a;
				if ((start - p) % b == 0 && start != p)
					cout << '\n';
				cout << '[' << setw(4) << left << *start << ']' << ' ';
			}
			cout << "\n";
			cout << "Делить\n";
			system("pause");
			system("cls");
		}
		else if (z == "x" || z == "X")
			break;
		else if (z != "1" || z != "2" || z != "3" || z != "4" || z != "X" || z != "x") {
			cout << "Недопустимое значение\n";
			system("pause");
			system("cls");
		}
	}


}


void SORT(int* p, int b){
	system("cls");
	for (int i = 0; i < b * b / 2; i++)
	{
		for (int k = i; k < b * b - i - 1; k++)
		{
			if (*(p + k) > *(p + k + 1))
			{
				swap(*(p + k), *(p + k + 1));
			}
		}
		for (int k = b * b - 2 - i; k >= i; k--)
		{
			if (*(p + k) > *(p + k + 1))
			{
				swap(*(p + k), *(p + k + 1));
			}
		}
	}
	MATR1(p, b);
}


void PERV(int* p, int b){
	system("cls");
	cout << "Матрица до перестановки:\n";
	MATR1(p, b);
	cout << "\n\nМатрица после перестановки:\n";
	for (int k = 0; k < b / 2; k++)
	{
		for (int i = 0; i < b / 2; i++)
		{
			{
				swap(*(p + k + b * i), *(p + k + b * i + b / 2));
				swap(*(p + k + b * i), *(p + k + b / 2 + b * (i + b / 2)));
				swap(*(p + k + b * i), *(p + k + b * (i + b / 2)));
			}
		}
	}
	MATR1(p, b);
}

void VTOR(int* p, int b){
	system("cls");
	cout << "Матрица до перестановки:\n";
	MATR1(p, b);
	cout << "\n\nМатрица после перестановки:\n";
	for (int k = 0; k < b / 2; k++)
	{
		for (int i = 0; i < b / 2; i++)
		{
			swap(*(p + k + b * i), *(p + k + b / 2 + b * (i + b / 2)));
			swap(*(p + k + b / 2 + b * i), *(p + k + b * (i + b / 2)));

		}
	}
	MATR1(p, b);
}

void TRET(int* p, int b){
	system("cls");
	cout << "Матрица до перестановки:\n";
	MATR1(p, b);
	cout << "\n\nМатрица после перестановки:\n";
	for (int k = 0; k < b / 2; k++)
	{
		for (int i = 0; i < b / 2; i++)
		{
			swap(*(p + k + b * i), *(p + k + b * (i + b / 2)));
			swap(*(p + k + b / 2 + b * i), *(p + k + b / 2 + b * (i + b / 2)));
		}
	}
	MATR1(p, b);
}

void CHETVERT(int* p, int b){
	system("cls");
	cout << "Матрица до перестановки:\n";
	MATR1(p, b);
	cout << "\n\nМатрица после перестановки:\n";
	for (int k = 0; k < b / 2; k++)
	{
		for (int i = 0; i < b / 2; i++)
		{
			swap(*(p + k + b * i), *(p + k + b / 2 + b * i));
			swap(*(p + k + b * (i + b / 2)), *(p + k + b / 2 + b * (i + b / 2)));
		}
	}
	MATR1(p, b);
}



void ZIG(int* p, int b)
{
	for (int i = 0; i < b; i++) 
	{
		if (i % 2 == 0)
		{
			for (int l = 0; l < b; l++) 
			{
				*(p + i + b * l) = 1 + rand() % (b * b);
				MATR(p, b);
			}
		}
		else
		{
			for (int l = b - 1; l >= 0; l--) 
			{
				*(p + i + b * l) = 1 + rand() % (b * b);
				MATR(p, b);
			}
		}
	}
}

//Комменатрии для 6x6
void SNAKE(int* p, int b)
{
	for (int i = 0; i < b / 2; i++) //i < 3
	{
		for (int k = i; k < b - i; k++) //(0 ; 1 ; 2 ; 3 ; 4 ; 5) =>  (7 ; 8 ; 9 ; 10) => (14 ; 15)
		{
			*(p + k + b * i) = 1 + rand() % (b * b);
			MATR(p, b);
		}
		for (int k = i + 1; k < b - i; k++) //(11 ; 17 ; 23 ; 29; 35) => (16 ; 22 ; 28)  => (21)
		{
			*(p + b - 1 - i + b * k) = 1 + rand() % (b * b);
			MATR(p, b);
		}
		for (int k = b - i - 1; k > i; k--) //(34 ; 33 ; 32 ; 31 ; 30) => (27 ; 26 ; 25) => (20) 
		{
			*(p + (k - 1) + (b) * (b - i - 1)) = 1 + rand() % (b * b);
			MATR(p, b);
		}
		for (int k = b - i - 2; k >= 1 + i; k--) //(24 ; 18 ; 12 ; 6) => (19 ; 13)
		{
			*(p + i + b * k) = 1 + rand() % (b * b);
			MATR(p, b);
		}
	}
}



void ZAPOLN(int *p , int b) {
	system("Cls");
	string z;
	while (1) {
		cout << "Выберите тип заполнения:\n1 a\n2 b\nX Назад\n";
			cin >> z;
		if (z == "1") {
			SNAKE(p, b);
			system("Pause");
			system("Cls");
		}
		else if (z == "2") {
			ZIG(p, b);
			system("Pause");
			system("Cls");
		}
		else if (z == "x" || z == "X")
			break;
		else if (z != "1" || z != "2" || z != "x" || z != "X") {
			cout << "Недопустимое значение\n";
			system("Pause");
			system("Cls");
		}
	}
}

void NOVMAT(int* p, int b) {
	system("Cls");
	string z;
	while (1) {
		cout << "Выберите тип перестановки:\n1 a\n2 b\n3 c\n4 d\nX Назад\n";
		cin >> z;
		if (z == "1") {
			PERV(p ,b);
			system("Pause");
			system("Cls");
		}
		else if (z == "2") {
			VTOR(p, b);
			system("Pause");
			system("Cls");
		}
		else if (z == "3") {
			TRET(p, b);
			system("Pause");
			system("Cls");
		}
		else if (z == "4") {
			CHETVERT(p, b);
			system("Pause");
			system("Cls");
		}
		else if (z == "X" || z == "x") 
			break;
		else if (z != "1" || z != "2" || z != "3" || z != "4" || z != "X" || z != "x") {
			cout << "Недопустимое значение\n";
			system("Pause");
			system("Cls");
		}
	}

}



void ZADAN(int *p, int b){
	system("Cls");
	string razmer;
	while (1) {
		cout << "Выберите номер задания:\n1 Задание 1(заполнение матрицы) \n2 Задание 2(новая матрица)\n3 Задание 3(сортировка)\n4 Задание 4(слож/выч/умн/дел)\nX Назад\n";
		cin >> razmer;
		if (razmer == "1") {
			ZAPOLN(p, b);
			system("Pause");
			system("Cls");
		}
		else if (razmer == "2") {
			NOVMAT(p , b);
			system("Pause");
			system("Cls");
		}
		else if (razmer == "3") {
			SORT(p, b);
			system("Pause");
			system("Cls");
		}
		else if (razmer == "4") {
			DEISTV(p , b);
			system("Pause");
			system("Cls");
		}
		else if (razmer == "x" || razmer == "X")
			break;
		else if (razmer != "1" || razmer != "2" || razmer != "3" || razmer != "4" || razmer != "x" || razmer != "X") {
			cout << "Недопустимое значение\n";
			system("Pause");
			system("Cls");
		}

	}


}




int main() {
	setlocale(0, "");
	srand(time(NULL));
	int* p = nullptr;
	int b = 0;
	string razmer;
	while (1) {
		cout << "Выберите размерность массива:\n1 6 x 6\n2 8 х 8\n3 10 x 10\nX Выход\n ";
		cin >> razmer;
		if (razmer == "1") {
			p = *mas6;
			b = 6;
			ZADAN(p, b);
			system("Pause");
			system("Cls");
		}
		else if (razmer == "2") {
			p = *mas8;
			b = 8;
			ZADAN(p, b);
			system("Pause");
			system("Cls");
		}
		else if (razmer == "3") {
			p = *mas10;
			b = 10;
			ZADAN(p, b);
			system("Pause");
			system("Cls");
		}
		else if (razmer == "x" || razmer == "X")
			break;
		else if (razmer != "1" || razmer != "2" || razmer != "3" || razmer != "x" || razmer != "X") {
			cout << "Недопустимое значение\n";
			system("Pause");
			system("Cls");
		}


	}
	return 0;
}