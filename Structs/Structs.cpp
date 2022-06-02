#include<iostream>
using namespace std;

struct item //��������� ���������
{
	char name[50]; //������� �������� ������������
	char genre[50]; //������� �������� ����
	char director[50]; //������� �������
	int price; //������� �������� ����
	int year; //������� �������� ���


};
void seek_film_by_name(item * films,  char * seek_film) //������ ������ �� ��������
{
	for (int i = 0; i < 3; i++)
	{
		if (!strcmp(films[i].name, seek_film)) // strcmp - ������� ��������� �����. ��������� 0, ���� ������ �����. 0 ���������� false
		{
			cout << "\nFilm found!\n"; //����� ������
			cout << films[i].name << "\t" << films[i].director << "\t" << films[i].genre << "\t" << films[i].year << endl;
			return;
		}
			
	}
	cout << "Film not found!\n";//����� �� ������
}
void view_films(item* films) //������� ������ ������� �� �����
{
	for (int i = 0; i < 3; i++)
	{
		cout << films[i].name << "\t" << films[i].director << "\t" << films[i].genre << "\t" << films[i].year << endl;
	}
}
void init_films(item * films, char  _names[][15], char _directors[][15], char _genres[][15], int* _prices, int* _years) //��������� ���������� �� �������
{
	for (int i = 0; i < 3; i++)
	{
		strcpy_s(films[i].name, _names[i]);
		strcpy_s(films[i].director, _directors[i]);
		strcpy_s(films[i].genre, _genres[i]);
		films[i].price = _prices[i];
		films[i].year = _years[i];
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	char names[][15] = { "Terminator", "Predator", "Iron man" }; //C����� �������� ������
	char genres[][15] = { "Fantastic", "ActionFilm", "Marvel Film" }; //������ ������
	char directors[][15] = { "J.Cameron", "J.Maveric", "B.Shakeapire" };//������ ���������
	int prices[] = {100, 150, 200};//C����� ���
	int years[] = {1984, 1988, 2004};//������ �����
	item * films = new item[3];//������������� ������������� ������� ���������
	char seek_film[15];//�������� �������� ������
	cout << "������� �������� ������: ";
	cin >> seek_film; //���� �������� ������
	init_films(films, names,directors, genres, prices, years );
	view_films(films);
	seek_film_by_name(films, seek_film);
	return 0;
}