#include <iostream>
#include <cmath>

// класс, описывающий точку
class point {
    public:
    //координаты точки
    int x;
    int y;

    //конструктор, инициализирующий точку с координатами (x,y)
    point(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
};
 
// перегруженный оператор вывода точки
std::ostream& operator << (std::ostream &s, point *p)
{
    s << '(' << p -> x << "; " << p -> y << ')';
    return s;
}
 
// функция печати массива точек
void print(point **p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}
 
// вычисление расстояния между двумя точками
double length(point *A, point *B) {
    return hypot(A -> x - B -> x, A -> y - B -> y);
}
 
// вычисление периметра треугольника
double perimeter(point *A, point *B, point *C) {
    return length(A, B) + length(B, C) + length(A, C);
}

using namespace std;

int main()
{
    /*
    n - количество точек
    a[i] - массив точек класса point
    x, y - координаты точки
    minPerimeter - минимальный периметр
    tmpPerimeter - периметр произвольного треугольника
    A, B, C - точки, образующие наименьший треугольник
    */
    int n;
    cout << "Enter the number of points: ";
    cin >> n;
    point *a[n];
    int x, y;
    double minPerimeter = __DBL_MAX__;  
    double tmpPerimeter = 0;  
    int A, B, C;

    //ввод данных с консоли
    for (int i = 0; i < n; i++) {
        cout << "Enter the x and y coordinates for " << i + 1;
        if (i == 0)
            cout << "st";
        else if (i == 1)
            cout << "nd";
        else if (i == 2)
            cout << "rd";
        else
            cout << "th";
        cout << " point: ";
        cin >> x >> y; 
        a[i] = new point(x, y);
    }

    //вывод всех точек в удобном формате
    print(a, n);              

    //перебор всех возможных троек точек, высчитывание периметра и сравнение с minPerimeter
    for (int i = 0; i < n-2; i++) {
        for (int j = i + 1; j < n-1; j++) {
            for (int k = j + 1; k < n; k++) {
                tmpPerimeter = perimeter(a[i],a[j],a[k]);
                if (tmpPerimeter < minPerimeter) {
                    minPerimeter = tmpPerimeter;
                    A = i + 1;
                    B = j + 1;
                    C = k + 1;
                }
            }
        }
    }
    //Вывод нужных точек
    cout << "Triangle with vertices at points " << A << ", " << B << " and " << C <<
                 " has the least perimeter.";    
}