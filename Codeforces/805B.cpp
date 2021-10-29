#include <iostream>

using namespace std;

string comp(int n){
    if(n==1)
        return "a";
    if(n==2)
        return "aa";
    string s = "bba";
    while(s.size() < n){
        if(s[s.size()-1]=='a' && s[s.size()-2]=='b')
            s.push_back('a');
        else if(s[s.size()-1]=='b' && s[s.size()-2]=='b')
            s.push_back('a');
        else if(s[s.size()-1]=='a' && s[s.size()-2]=='a')
            s.push_back('b');
        else if(s[s.size()-1]=='b' && s[s.size()-2]=='a')
            s.push_back('b');
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    cout<<comp(n);
    return 0;
}
