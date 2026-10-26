#include <iostream>
#include <iomanip>
using namespace std;
// Введення елементів масиву
void inputArray(int* a, int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
// Виведення масиву в рядок
void printArray(const int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(6) << a[i];
	}
	cout << endl;
}
// Пошук мінімального елемента
int findMin(const int* a, int n)
{
	int minElement = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minElement)
		{
			minElement = a[i];
		}
	}
	return minElement;
}
// Обчислення суми між першим
// і останнім додатними елементами
long long sumBetweenPositive(const int* a, int n)
{
	int first = -1;
	int last = -1;
	// Знаходимо перший додатний елемент
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			first = i;
			break;
		}
	}
	// Знаходимо останній додатний елемент
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] > 0)
		{
			last = i;
			break;
		}
	}
	// Якщо додатних елементів менше двох
	if (first == -1 || last == -1 || first == last)
	{
		return 0;
	}
	long long sum = 0;
	// Сумуємо елементи МІЖ додатніми,
	// не враховуючи самі додатні елементи
	for (int i = first + 1; i < last; i++)
	{
		sum += a[i];
	}
	return sum;
}
// Переставлення: спочатку нулі,
// потім усі інші елементи зі збереженням порядку
void moveZerosToBeginning(int* a, int n)
{
	int* temp = new int[n];
	int k = 0;
	// Спочатку записуємо всі нулі
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			temp[k++] = a[i];
		}
	}
	// Потім записуємо всі ненульові елементи
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			temp[k++] = a[i];
		}
	}
	// Копіюємо результат у початковий масив
	for (int i = 0; i < n; i++)
	{
		a[i] = temp[i];
	}
	delete[] temp;
}
int main()
{
	int n;
	cout << "Enter n : ";
	cin >> n;
	if (n <= 0)
	{
		cout << "Error: n must be greater than 0." << endl;
		return 1;
	}
	// Створення динамічного масиву
	int* a = new int[n];
	// Введення та виведення початкового масиву
	inputArray(a, n);
	cout << "\nOriginal array : \n"	;
	printArray(a, n);
	// Знаходження мінімального елемента
	cout << "\nMinimum element : "
		<< findMin(a, n) << endl;
	// Обчислення суми
	cout << "Sum between positive elements : "
		<< sumBetweenPositive(a, n) << endl;
	// Модифікація масиву
	moveZerosToBeginning(a, n);
	cout << "\nModified array : \n";
	printArray(a, n);
	// Звільнення пам’яті
	delete[] a;
	return 0;
}