#ifndef STRING_H
#define STRING_H

#include<cstring>
#include<algorithm>
#include<cstddef>
#include<iostream>
#include<memory>

using namespace std;
class String{
friend String operator+(const String&, const String&);
friend String add(const String&, const String&);
friend ostream &operator<<(ostream&, const String&);
friend ostream &print(ostream&, const String&);

public:
    String(): sz(0), p(0) { }
    String(const char *cp):sz(strlen(cp)), p(a.allocate(sz)) {uninitialized_copy(cp, cp+sz, p);}
    String(const String &s):sz(s.sz), p(a.allocate(s.sz)) { uninitialized_copy(s.p, s.p + sz , p); }
    //移动构造函数
    String(String &&s)noexcept: sz(s.size()), p(s.p) {s.p = 0; s.sz = 0}
    String(size_t n, char c):sz(n), p(a.allocate(n)) {uninitialized_fill_n(p, sz, c);}
    String &operator=(const String &);
    String &String::operator=(String &&rhs) noexcept
    {
        //显式检查自赋值
        if(this != rhs){
            if(p)
                a.deallocate(p.sz); //类似析构函数的工作
            p = rhs.p;          //接管就内存
            sz = rhs.sz;
            rhs.p = 0;          //令rhs析构安全
            rhs.sz = 0;
        }
        return *this;
    }
    ~String() {if(p) a.deallocate(p, sz);}
public:
    String &operator=(const char*);
    String &operator=(char);

    const char *begin() { return p; }
	const char *begin() const { return p; }
	const char *end()   { return p + sz; }
	const char *end() const { return p + sz; }

    size_t size() const {return sz;}
    void swap(String &s)
    {
        char *tmp = p;
        p = s.p;
        p = tmp;
        size_t cnt = sz;
        sz = s.sz;
        s.sz = cnt;
    }
private:
    size_t sz;
    char *p;
    static allocator<char> a;
};
String make_plural(size_t ctr, const String &, const String &);
inline
void swap(String &s1, String &s2)
{
	s1.swap(s2);
}

#endif