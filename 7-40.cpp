#include<iostream>
#include<string>

using namespace std;

class Book
{
private:
    string Name,ISBN, Author, Publisher;
    double Price = 0;
public:
    Book() = default;
    Book(const string &n, const string &I, double pr,
        const string &a, const string &p)
    {
        Name = n;
        ISBN = I;
        Price = pr;
        Author = a;
        Publisher = p;
    }
    Book(std::istream &is) {is >> *this;}
};

class Tree
{
private:
    string Name;
    unsigned Age = 0;
    double Height = 0;
public:
    Tree() = default;
    Tree(const string &n, unsigned a,double h):Name(n),
        Age(a), Height(h);
};
