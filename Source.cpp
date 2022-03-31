// Персональный шаблон проекта C++
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

template <typename T> void showArr(T arr[], int length);
template <typename T> void fillArr(T arr[], int length, int min = 0, int max = 100);
template <typename T> T* addEl(T arr[], unsigned int& length, int n);
template <typename T> T* delEl(T arr[], unsigned int& length, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	//int n;

	/*
	int* pn = new int; 
	*pn = 10;

	cout << pn << " - " << *pn << endl;

	delete pn; // обязательно, чтобы очистить область памяти, перед тем указать на другую ячейку.
	pn = new int; // перенаправление указателя на другую ячейку памяти. При этом в старой ячейка остаётся 10. Необходимо удалять перед тем, как перенаправлять.

	delete pn; // удаляем данные, которые хранятся в ячейке, но не удаляет указатель. Дальше указывает на ячейку.
	// 0, NULL, nullptr
	pn = nullptr; // использлвать чтобы очистить область оперативной памяти. Желательно всегда использовать, когда удаляем динамическую переменную

	if (pn != nullptr)
		cout << pn << " - " << *pn << endl; */

	/*unsigned int n; // делаем unsigned - потому-что длина массива не может быть отрицательной.
	const int L = 5;
	int arr[L]; // должно быть константное значение (кол-во) элементов массива

	cout << "Введите длину массива: ";
	cin >> n;

	int* dArr = new int[n]; // значение может быть не константным. Создаём динамический массив.
	// dArr[0] = 10;
	for (int i = 0; i < n; i++)
		dArr[i] = i + 1;
	cout << "Изначальный массив:\n";
	showArr(dArr, n);

	delete[] dArr; // удаляем только его первый элемент (из оперативной памяти) .delete[] - так удаляем массив.
	dArr = nullptr; // указываем на нейтральный адрес.


	dArr = new int[n + 1]; */

	// Задача 1
	/*
	cout << "Задача 1.\nВведите длину массива: ";
	unsigned int size1;
	cin >> size1;
	int* z1 = new int[size1];
	fillArr(z1, size1, 10, 31);
	cout << "Изначальный массив:\n";
	showArr(z1, size1);
	z1 = addEl(z1, size1, 5);
	cout << "Итоговый массив:\n";
	showArr(z1, size1);
	delete[] z1;
	*/
 
	// Задача 2
	cout << "Задача 2.\nВведите длину массива: ";
	unsigned int size2;
	cin >> size2;
	int* z2 = new int[size2];
	fillArr(z2, size2, 10, 51);
	cout << "Изначальный массив:\n";
	showArr(z2, size2);
	z2 = delEl(z2, size2, 3);
	cout << "Итоговый массив:\n";
	showArr(z2, size2);

	return 0;
}
// Задача 2. Уменьшение размера массива
template <typename T> T* delEl(T arr[], unsigned int& length, int n) {
	if (n <= 0 || n >= length)
		return arr;
	length -= n;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = new T[length];
	for (int i = 0; i < length; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}

// Задача 1. Увеличение размера массива и переменной, хранящей размер этого массива.
template <typename T> T* addEl(T arr[], unsigned int& length, int n) {
	if (n <= 0)
		return arr;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = new T[length + n];
	length += n;
	for (int i = 0; i < length - n; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}

// Заполнение массива случайными числами от min до max
template <typename T> void fillArr(T arr[], int length, int min, int max) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min; // лучше делать не включительно. Чтобы передавать до 100 включительно - передаём 101.
}

// Вывод массива
template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}