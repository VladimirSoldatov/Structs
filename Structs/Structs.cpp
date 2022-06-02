#include<iostream>
using namespace std;

struct item //Обявление структуры
{
	char name[50]; //Создаем свойство наименование
	char genre[50]; //Создаем свойство жанр
	char director[50]; //Создаем режисер
	int price; //Создаем свойство цена
	int year; //Создаем свойство год


};
void seek_film_by_name(item * films,  char * seek_film) //Фунция поиска по названию
{
	for (int i = 0; i < 3; i++)
	{
		if (!strcmp(films[i].name, seek_film)) // strcmp - функция сравнения строк. Возращает 0, если строки равны. 0 ревалентен false
		{
			cout << "\nFilm found!\n"; //Фильм найден
			cout << films[i].name << "\t" << films[i].director << "\t" << films[i].genre << "\t" << films[i].year << endl;
			return;
		}
			
	}
	cout << "Film not found!\n";//Фильм не найден
}
void view_films(item* films) //Вывести список фильмов на экран
{
	for (int i = 0; i < 3; i++)
	{
		cout << films[i].name << "\t" << films[i].director << "\t" << films[i].genre << "\t" << films[i].year << endl;
	}
}
void init_films(item * films, char  _names[][15], char _directors[][15], char _genres[][15], int* _prices, int* _years) //Загрузить информацию по фильмам
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
	char names[][15] = { "Terminator", "Predator", "Iron man" }; //Cписок названий филмов
	char genres[][15] = { "Fantastic", "ActionFilm", "Marvel Film" }; //Список жанров
	char directors[][15] = { "J.Cameron", "J.Maveric", "B.Shakeapire" };//Список режисеров
	int prices[] = {100, 150, 200};//Cписок цен
	int years[] = {1984, 1988, 2004};//Список годов
	item * films = new item[3];//Инициализация динамического массива картотеки
	char seek_film[15];//Название искомого фильма
	cout << "Введите название фильма: ";
	cin >> seek_film; //Ввод названия фильма
	init_films(films, names,directors, genres, prices, years );
	view_films(films);
	seek_film_by_name(films, seek_film);
	return 0;
}