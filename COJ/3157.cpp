#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long c=0,o=0,w=0;
    for(int y=0;y<(int)s.size();y++){
        if(s[y]=='C'){
            c++;
        }
        else if(s[y]=='O'){
            o+=c;
        }
        else if(s[y]=='W'){
            w+=o;
        }
    }
    cout<<w;
    return 0;
}
