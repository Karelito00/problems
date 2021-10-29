#include <bits/stdc++.h>

using namespace std;

map < char , int > mapa;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n;
    cin>>n;
    for(int i = 0; i < (int)s.size(); i++)
        mapa[s[i]]++;
    int con = 0;
    for(auto x: mapa)
        con++;
    if(con >= n){
        cout<<0;
    }
    else{
        int sol = 0;
        for(auto x: mapa){
            sol += min(n - con, x.second - 1);
            con += min(n - con, x.second - 1);
        }
        if(con >= n)
            cout<<sol;
        else
            cout<<"impossible";
    }
    return 0;
}
