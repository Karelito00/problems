#include <bits/stdc++.h>

using namespace std;

vector < int > num;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ls,lt;
    cin>>ls>>lt;
    string s;
    string t;
    cin>>s>>t;
    int best = 99999999;
    for(int i=0;i<=lt-ls;i++){
        int con = 0;
        for(int j=0;j<ls;j++){
            if(s[j] == t[i+j]){
                con++;
            }
        }
        if(best > ls - con){
            num.clear();
            for(int j=0;j<ls;j++){
                if(s[j] != t[i+j]){
                    num.push_back(j+1);
                }
            }
            best = ls - con;
        }
    }
    cout<<best<<"\n";
    for(auto x: num){
        cout<<x<<" ";
    }
    return 0;
}
