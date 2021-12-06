#include <iostream>
#include <execution>
#include <stdexcept>
#include "fraction.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	bool res;
	long numerator, denominator, numerator2, denominator2;
	cout << "Введите первую дробь : ";
	cin >> numerator;
	cin >> denominator;
	fraction first(numerator, denominator);
	try 
	{
		first.check();
	}
	catch (...)
	{
		cout << "Error"<<endl;
		return 1;
	}
	cout << endl;
	cout << "Введите вторую дробь : ";
	cin >> numerator2;
	cin >> denominator2;
	fraction second(numerator2, denominator2);
	try
	{
		second.check();
	}
	catch (...) 
	{
		std::cout << "Error"<<endl;
		return 1;
	}
	cout << "Сложение : ";
	fraction result = first + second;
	result.Print();
	cout << endl;
	cout << "Вычитание : ";
	fraction result1 = first - second;
	result1.Print();
	cout << endl;
	cout << "Умножение : ";
	fraction result2 = first * second;
	result2.Print();
	cout << endl;
	cout << "Деление : ";
	fraction result3 = first / second;
	result3.Print();
	cout << endl;
	cout << "Равны : ";
	if (first == second)
	{
		cout << "true"<<endl;
	}
	else
	{
		cout << "false"<<endl;
	}
	cout << "Не равны : ";
	if (first!=second)
	{
		cout << "true"<<endl;
	}
	else
	{

		cout << "false"<<endl;
	}
	cout << "Больше : ";
	if (first > second)
	{
		cout << "true" << endl;
	}
	else
	{

		cout << "false" << endl;
	}
	cout << "Больше или равно : ";
	if (first >= second)
	{
		cout << "true" << endl;
	}
	else
	{

		cout << "false" << endl;
	}
	cout << "Меньше : ";
	if (first < second)
	{
		cout << "true" << endl;
	}
	else
	{

		cout << "false" << endl;
	}
	cout << "Меньше или равно : ";
	if (first <= second)
	{
		cout << "true" << endl;
	}
	else
	{

		cout << "false" << endl;
	}
	cout << "Пременение get и  set :" << endl;

	fraction r;
	r.SetNumerator(5);
	r.SetDenominator(8);
	cout<<r.GetNumerator()<<endl;
	cout<<r.GetDenominator()<<endl;
	r.Print();
	cout << endl;
	cout << "Проверка на поиск исключений :" << endl;
	fraction r1;
	r1.SetNumerator(3);
	r1.SetDenominator(0);
	try {
		r1.check();
	}
	catch (...) 
	{
		cout << "Error";
		return 1;
	}
}

