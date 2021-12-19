#include <iostream>
#include <iomanip>
#include <cstdio>
#define pages 2 
using namespace std;


//4.1
ostream& endp(ostream& out)
{
    static int num = 0; 
   out << endl;
    num++;// число выведенных строк
  
    if (num == pages)//при заполнении переход 
    {
       out << "--------------" << endl; // при переходе на новую страницу
        num = 0;                        
    }
    return out; 
}
// 4.2
ostream& endp(ostream& out, int n)
{
    static int numb = 0;
    out << endl;
    numb++;
    if (numb == n)
    {
        out << "--------------" << endl; 
        numb = 0;                    
    }
    return out; 
}
// 4.3
ostream& fendp(ostream& out, int n, char* s)
{
    static int number = 0; 
    out << endl;
    number++;
    if (number == n)
    {
        out << s << endl; //строка приглашение в конце страницы
        number = 0;        
    }
    return out;
}

int main()
{
    setlocale(LC_ALL, "rus");
    //4.1
    int i = 0;
    for (i = 0; i < 5; i++)            
        cout << i + 1 << endp;

    //4.2
    for (int i = 0; i < 5; i++)                       
    {
        endp(cout << i, 2); 
    }

    char s[10], s1;
    do
    {
        cin.clear(); // очистка
        cout << "Введите строку >> " << endl;
        cin.ignore(10, '&'); // игнор ввода до &
        s1 = cin.peek(); // извлекает 1 символ 
        cin.putback('#');// вставляем в начало #
        cin.getline(s, 11);
    } while (cin.gcount() - 1 > 10); 
    cout << "s=" << s << endl;       
    cout << "s1= " << s1 << endl; 
}
