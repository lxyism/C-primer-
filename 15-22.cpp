#include<iostream>
using namespace std;

class Figure{
    public:
    Figure(double, double);
    protected:
    double xSize, ySize;
};

class Figure_2D:public Figure{
    public:
    Figure_2D(double, double);
    virtual double area() = 0;      //求面积的操作：纯虚函数
    virtual double perimeter() = 0;       //求周长操作：纯虚函数
};

class Figure_3D:public Figure{
public:
    Figure_3D(double, double, double);
    virtual double cubage() = 0;
protected:
    Rectangle(double, double);
    virtual double area();
    virtual double perimeter();
};

class Circle:public Figure_2D{
    public:
    Circle(double, double);
    virtual double area();
    virtual double perimeter();
};

class Sphere:public Figure_3D{
    public:
    Sphere(double, double, double);
    virtual double cubage();
};
class Cone:public Figure_3D{
    public:
    Cone(double, double, double);
    virtual double cubage();
};
int main()
{
    return 0;
}