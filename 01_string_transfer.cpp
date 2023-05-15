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

    String(const String& str_p) : str(str_p.str) { // Конструктор копирования
        cout << "Конструктор копирования" << endl;
    }

    String(String&& str_p) noexcept : str(move(str_p.str)) { // Конструктор переноса
        cout << "Конструктор переноса" << endl;
    } 

    ~String() {}

    String& operator=(const String& str_p) { // Оператор копирования
        cout << "Оператор копирования" << endl;
        str = str_p.str;
        return *this;
    }

    String& operator=(String&& str_p) noexcept { // Оператор переноса
        cout << "Оператор переноса" << endl;
        str = move(str_p.str);
        return *this;
    }
    string setStr(string tmp) {
        return this->str.append(tmp);
    }
	friend ostream& operator<< (ostream& os, const String& st) { //выводим str в поток вывода
		return os << st.str;
	}

};

String fStr_obj(String& str_p) {
    String newStr {str_p};         //инициализируем через копирование
    newStr.setStr("+fghjk");
    return newStr;
}

String fStr() {
    String newStr;
    newStr.setStr("**zxcvb**"); 
    return newStr;
}

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

    String str3;          //создаем 3 обьект и вызываем оператор копирования 
    str3 = str2;      
    cout << "Строка 3 после копирования оператором: " << str3 << endl << endl;

    String str4{ fStr_obj(str3)};   //создаем 4 обьект и вызываем конструктор переноса - к str3 в поле str добавляем строку +fghjk
    cout << "Строка 4 после переноса конструктором: " << str4 << endl << endl;

    String str5{ fStr() };         //создаем 5 обьект и вызываем оператор переноса - в поле str записываем **zxcvb**
    cout << "Строка 5 после переноса конструктором: " << str5 << endl << endl;

    String str6;
    str6 =  "++просто текст++";        //создаем 6 обьект и вызываем оператор переноса 
    cout << "Строка 6 после переноса оператором: " << str6 << endl << endl;

    system("pause");
    return 0;
}

