#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;
/*
Создать бинарный файл, компонентами которого являеться структура,
содержащая следующие поля:
- наименование товара;
- стоимость товара;
- еденица измерения(я поняла этот пункт как количество товара)
*/
struct Product
{
	string goods;
	double price;
	int quanlity;
};

void Input_data(Product* product, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Enter product name: " << endl;
		cin >> product[i].goods;
		cout << "Enter price: " << endl;
		cin >> product[i].price; cin.ignore();
		cout << "Enter quantity: " << endl;
		cin >> product[i].quanlity; cin.ignore();
	}
	cout << "---------------------------------------------" << endl;
}

void Write_to_file(Product* product, int N, ofstream& out)
{
	for (int i = 0; i < N; i++)
	{
		out << "Name of product: " << product[i].goods << endl;
		out << "Cost of product: " << product[i].price << endl;
		out << "Quantity of product: " << product[i].quanlity << endl;
	}

}

int main()
{
	int N = 0;
	cout << "Enter the number of types of product: " << endl;
	cin >> N;
	Product* product = new Product[N];
	Input_data(product, N);
	ofstream out("1.txt");
	if (!out.is_open())
	{
		cout << "Error! Unable to open file." << endl;
	}
	else
	{
		cout << "File opened successfuly!" << endl;
		Write_to_file(product, N, out);
	}

	out.close();
	system("pause");
	return 0;
}
