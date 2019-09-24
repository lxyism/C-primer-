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
    /*unique函数属于STL中比较常用函数，它的功能是元素去重。即”删除”序列中所有相邻的重复元素(只保留一个)。
    此处的删除，并不是真的删除，而是指重复元素的位置被不重复的元素给占领了(详细情况，下面会讲)。
    由于它”删除”的是相邻的重复元素，所以在使用unique函数之前，一般都会将目标序列进行排序。*/
    auto unique_end = unique(word.begin(), word.end());  
    word.erase(unique_end, word.end());//将去重容器后不重复序列的最后一个元素的下一个元素到最后的元素删掉
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    IsShorter is;
    stable_sort(words.begin(), words.end(), is); //stable_sort()可以对vector的某个成员进行排序，而且可保证相等元素的原本相对次序在排序后保持不变。

    NotShorterThan nst(sz);
    auto wc = find_if(words.begin(), words.end(), is);

    auto count = words.end() - wc;
    cout<<count<<" "<<make_plural(count, "word", "is")<<"of length"<<sz<<"or longer"<<endl;
}