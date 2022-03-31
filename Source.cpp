// ������������ ������ ������� C++
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

	delete pn; // �����������, ����� �������� ������� ������, ����� ��� ������� �� ������ ������.
	pn = new int; // ��������������� ��������� �� ������ ������ ������. ��� ���� � ������ ������ ������� 10. ���������� ������� ����� ���, ��� ��������������.

	delete pn; // ������� ������, ������� �������� � ������, �� �� ������� ���������. ������ ��������� �� ������.
	// 0, NULL, nullptr
	pn = nullptr; // ������������ ����� �������� ������� ����������� ������. ���������� ������ ������������, ����� ������� ������������ ����������

	if (pn != nullptr)
		cout << pn << " - " << *pn << endl; */

	/*unsigned int n; // ������ unsigned - ������-��� ����� ������� �� ����� ���� �������������.
	const int L = 5;
	int arr[L]; // ������ ���� ����������� �������� (���-��) ��������� �������

	cout << "������� ����� �������: ";
	cin >> n;

	int* dArr = new int[n]; // �������� ����� ���� �� �����������. ������ ������������ ������.
	// dArr[0] = 10;
	for (int i = 0; i < n; i++)
		dArr[i] = i + 1;
	cout << "����������� ������:\n";
	showArr(dArr, n);

	delete[] dArr; // ������� ������ ��� ������ ������� (�� ����������� ������) .delete[] - ��� ������� ������.
	dArr = nullptr; // ��������� �� ����������� �����.


	dArr = new int[n + 1]; */

	// ������ 1
	/*
	cout << "������ 1.\n������� ����� �������: ";
	unsigned int size1;
	cin >> size1;
	int* z1 = new int[size1];
	fillArr(z1, size1, 10, 31);
	cout << "����������� ������:\n";
	showArr(z1, size1);
	z1 = addEl(z1, size1, 5);
	cout << "�������� ������:\n";
	showArr(z1, size1);
	delete[] z1;
	*/
 
	// ������ 2
	cout << "������ 2.\n������� ����� �������: ";
	unsigned int size2;
	cin >> size2;
	int* z2 = new int[size2];
	fillArr(z2, size2, 10, 51);
	cout << "����������� ������:\n";
	showArr(z2, size2);
	z2 = delEl(z2, size2, 3);
	cout << "�������� ������:\n";
	showArr(z2, size2);

	return 0;
}
// ������ 2. ���������� ������� �������
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

// ������ 1. ���������� ������� ������� � ����������, �������� ������ ����� �������.
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

// ���������� ������� ���������� ������� �� min �� max
template <typename T> void fillArr(T arr[], int length, int min, int max) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min; // ����� ������ �� ������������. ����� ���������� �� 100 ������������ - ������� 101.
}

// ����� �������
template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}