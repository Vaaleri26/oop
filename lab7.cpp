#include <iostream>;
#include <string>;
#include <string.h>
#include <iomanip>
//using namespace std;
//1.1
//верные объявления:
//template<class t1,class t2> void f(t1 x, t2 x2){}
//(если в мейн у x x2 разные типы)
//template<class t> void f(t x, t x2){}
//(если в мейн у х и х2 одинаковые типы)
//1.2
template <class T>
T swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;

    return temp;
}



//1.3
template <class T>
T max(T a, T b) {
    std::cout << "шаблонная" << std::endl;
    return (a > b) ? a : b;
}
const char* max(const char* a, const char* b) {
    std::cout << "специализированная" << std::endl;
    return (a > b) ? a : b;
}


//2.1
class Complex {
private:

    double m_d, m_m;//действительное и мнимое

public:

    Complex();
    Complex(double d = 0, double m = 0);


    Complex operator+(const Complex& a) {
        return Complex((m_d + a.m_d) + (m_m + a.m_m));
    }
    Complex operator-(const Complex& a) {
        return Complex((m_d - a.m_d) + (m_m - a.m_m));
    }

    friend std::ostream& operator<< (std::ostream& out, const Complex& x)//out
    {
        return (out << "(" << x.m_d << "," << x.m_m << ")");
    }


};

//2.2
template <class T>//шаблон класса матриц
class Matrix {

private:
    T** Mat;
    int a;
    int b;

public:


    Matrix()
    {
        a = b = 0;
    }
    Matrix(int _a,int _b)
    {
        a = _a;
        b = _b;
    
        Mat = (T**) new T * [a];


        for (int i = 0; i < a; i++)//cоздание массива
            Mat[i] = (T*)new T[b];

        for (int i = 0; i < b; i++)
            for (int j = 0; j < b; j++)
                Mat[i][j] = 0;
    }

    void SetMat(int i, int j, T value)//заполняем конкретный столбец
    {
        if ((i < 0) || (i >= b))
            return;
        if ((j < 0) || (j >= a))
            return;
        Mat[i][j] = value;
    }

    void Print(const char* ObjName)//вывод всей матрицы
    {
        std::cout << "Object: " << ObjName << std::endl;
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < b; j++)
                std::cout << Mat[i][j] << "\t";
            std::cout << std::endl;
        }

    }

    Matrix operator=(const Matrix& _Mat)//
    {
        if (a > 0)
        {

            for (int i = 0; i < b; i++)
                delete[] Mat[i];
        }

        if (b > 0)
        {
            delete[] Mat;
        }
        a = _Mat.a;
        b = _Mat.b;//присваиваем нашей матрице  из _мат



        Mat = (T**) new T * [b];//заполняю из одной матрицы в другую(копирую)
        for (int i = 0; i < b; i++)
            Mat[i] = (T*) new T[a];


        for (int i = 0; i < b; i++)
            for (int j = 0; j < a; j++)
                Mat[i][j] = _Mat.Mat[i][j];
        return *this;
    }

    ~Matrix() = default;
};
//3.1
template <typename T> class Stack
{
    T* stackPtr;//стек
    int n;
    T top;//верх,кто первый уйдет

public:
    Stack(int = 10);

    ~Stack();

    bool push(const T);
    bool pop();
    void printStack();
};

template <typename T> Stack<T>::Stack(int s)
{
    n = s > 0 ? s : 10;
    stackPtr = new T[n];
    top = -1;
}

template <typename T> Stack<T>::~Stack()
{
    delete[] stackPtr;
}

template <typename T> bool Stack<T>::push(const T value)//вставка элемента в вершину стека
{
    if (top == n - 1)
        return false;

    top++;
    stackPtr[top] = value;

    return true;
}

template <typename T> bool Stack<T>::pop()//удаления элемента с вершины стека
{
    if (top == -1)
        return false;

    stackPtr[top] = 0;
    top--;

    return true;
}

template <typename T> void Stack<T>::printStack()
{
    for (int ix = n - 1; ix >= 0; ix--)
        std::cout << stackPtr[ix] << std::endl;
}


int main() {
    setlocale(LC_ALL, "rus");
    int x = 6;
    int y = 1;
    std::cout << swap(x, y) << std::endl;

    std::cout << max('a', '1') << std::endl;
    std::cout << max(0, 1) << std::endl;
    std::cout << max("hello", "world") << std::endl;

   
   int n, c = 0;
    std::cout << "Введите размер стэка: ";
    std::cin >> n;
    Stack<int> myStack(n);
    std::cout << "Записываем элементы в стэк: ";
    while (c++ != n) 
    {
        int temp;
        std::cin >> temp;
        myStack.push(temp);
    }
    myStack.printStack();

    Matrix<int> in(2,2);
    in.SetMat(2,6,3);
    in.SetMat(6,2,2);
   
   
    
}
