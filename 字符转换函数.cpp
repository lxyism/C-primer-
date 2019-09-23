string &trans(string &s)
{
    for(int p = 0; p < s.size(); p++){
        if(s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');
        else if(s[p] == ',' || s[p] == '.')
            s.erase(p, 1);
    }
    return s;
}