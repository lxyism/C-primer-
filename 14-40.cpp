#include<iostream>
#include<string>
#include<vector>
#include"make_plural.h"
#include<algorithm>

using namespace std;
class IsShorter{
public:
    bool operator()(const string &s1, const string &s2) {return s1.size() < s2.size();}
};

class NotShorterThan{
public:
    NotShorterThan(int len):minLen(len) {}
    bool operator()(const string &str)
    {
        return str.size() >= minLen;
    }
private:
    int minLen;
};
class PrintString{
public:
    void operator()(const string &str)
    {
        cout<<str<<" ";
    }
};

void elimDups (vector<string> &word){
    sort(word.begin(), word.end());
    /*unique��������STL�бȽϳ��ú��������Ĺ�����Ԫ��ȥ�ء�����ɾ�����������������ڵ��ظ�Ԫ��(ֻ����һ��)��
    �˴���ɾ�������������ɾ��������ָ�ظ�Ԫ�ص�λ�ñ����ظ���Ԫ�ظ�ռ����(��ϸ���������ὲ)��
    ��������ɾ�����������ڵ��ظ�Ԫ�أ�������ʹ��unique����֮ǰ��һ�㶼�ὫĿ�����н�������*/
    auto unique_end = unique(word.begin(), word.end());  
    word.erase(unique_end, word.end());//��ȥ���������ظ����е����һ��Ԫ�ص���һ��Ԫ�ص�����Ԫ��ɾ��
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    IsShorter is;
    stable_sort(words.begin(), words.end(), is); //stable_sort()���Զ�vector��ĳ����Ա�������򣬶��ҿɱ�֤���Ԫ�ص�ԭ����Դ���������󱣳ֲ��䡣

    NotShorterThan nst(sz);
    auto wc = find_if(words.begin(), words.end(), is);

    auto count = words.end() - wc;
    cout<<count<<" "<<make_plural(count, "word", "is")<<"of length"<<sz<<"or longer"<<endl;
}