#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   //1.1
    setlocale(LC_ALL, "rus");
    int a = 26;
    // oct Ввод/вывод данных в восьмеричной форме,распространяется до явной отмены

    cout << oct << a << endl;

    //hex Ввод/вывод данных в шестнадцатиричной системе,распространяется до явной отмены

    cout << hex << a << endl;

    //dec Ввод/вывод данных в десятичной форме,распространяется до явной отмены
    cout << dec << a << endl;

    //	setfill Устанавливает символ заполнения равным ch,распространяется до явной отмены(взаимодействует с setw)
    cout << setfill('&') << a << endl;

    //setw Устанавливает ширину поля равной w, распространяются на ближайший операнд
    cout << setw(10) << a << endl;

    //setprecision Устанавливает число цифр после запятой
    cout <<  setprecision(2) << a << endl;

    //1.2

    // определяет число значащих цифр,происходит округление результата
    double b = 26.99;                                       
    cout << setprecision(2) << b << endl; 

    //1.3

    cout << setprecision(3); // сброс к параметру по умолчанию (3 знака после запятой)
    float с = 26.9999999;
    cout << setw(12) << scientific << с << endl;   
    cout.unsetf(ios::scientific);// сброс флага
    cout.setf(ios::fixed);// установка флага 
    cout  << right << setw(12) << setfill('-') << с << endl; 
    cout << left << setw(12) << с<< endl;

    //2

    int d=1,e=2,f=3;
   
    cout.fill('&'); 
    cout.width(1);  
    cout << d << endl;
    cout.width(2);
    cout << e << endl;
    cout.width(3);
    cout << f << endl;

    float g=4.1111;
   
    cout.setf(ios::fixed); 
    cout.precision(2);     
    cout  << g << endl;
  
    //3

    cout << endl << endl << setfill('&') << setw(12) << endl;

    cout.setf(ios::hex);//установка флага
    cout << 12 << endl;
    cout.unsetf(ios::hex);//сброс флага

   


}
