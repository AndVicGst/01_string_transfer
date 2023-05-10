/*
Добавить в уже существующий класс String конструктор
переноса, оператор присваивания переноса.
*/

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;


class String
{
private:
	string str;

public:
    String() : str() {} 

    String(const char* str_p) : str(str_p) {} 

    String(const String& other) : str(other.str) {} // Конструктор копирования

    String(String&& other) noexcept : str(move(other.str)) {} // Конструктор переноса

    ~String() {}

    String& operator=(const String& other) { // Оператор копирования
        str = other.str;
        return *this;
    }

    String& operator=(String&& other) noexcept { // Оператор переноса
        str = move(other.str);
        return *this;
    }

	friend ostream& operator<< (ostream& os, const String& st) { //выводим str в поток вывода
		return os << st.str;
	}
};


int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "------------Класс String-----------" << endl;
    cout << "--конструктор и оператор переноса--" << endl << endl;

    String str1("abcde");  //создаем 1 обьект 
    cout << "Строка 1: " << str1 << endl << endl;

    String str2{ str1 };  //создаем 2 обьект и копируем в него 1
    cout << "Строка 2 после копирования: " << str2 << endl << endl;

    String str3 = str2; //создаем 3 обьект и вызываем конструктор переноса 
    cout << "Строка 3 после переноса конструктором: " << str3 << endl << endl;

    String str4;       //создаем 4 обьект и вызываем оператор переноса 
    str4 = str3;
    cout << "Строка 4 после переноса оператором: " << str4 << endl << endl;

    system("pause");
    return 0;
}

