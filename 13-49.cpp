//String���ƶ����캯��������£�
String(String &&s) noexcept: sz(s.size()), p(s.p) {s.p = 0; s.sz = 0;}
//String���ƶ���ֵ�����������£�
String & String::operator = (String &&rhs) noexcept{
    //��ʽ����Ը�ֵ
    if(this != &rhs)
    {
        if(p)
            a.deallocate(p, sz);        //�������������Ĺ���
        p = rhs.p;
        sz = rhs.sz;
        rhs.p = 0;              //��rhs������ȫ
        rhs.sz = 0;
    }   
    return *this;
}
