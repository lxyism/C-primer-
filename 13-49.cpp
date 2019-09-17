//String的移动构造函数设计如下：
String(String &&s) noexcept: sz(s.size()), p(s.p) {s.p = 0; s.sz = 0;}
//String的移动赋值运算符设计如下：
String & String::operator = (String &&rhs) noexcept{
    //显式检查自赋值
    if(this != &rhs)
    {
        if(p)
            a.deallocate(p, sz);        //类似析构函数的工作
        p = rhs.p;
        sz = rhs.sz;
        rhs.p = 0;              //令rhs析构安全
        rhs.sz = 0;
    }   
    return *this;
}
