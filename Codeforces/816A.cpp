#include <bits/stdc++.h>

using namespace std;

bool comp(int hrs,int minm){
    string total;
    string hr;
    if(hrs < 10){
        hr.push_back('0');
        hr.push_back(char(hrs+'0'));
    }
    else{
        while(hrs>0){
            hr.push_back(char((hrs%10)+'0'));
            hrs/=10;
        }
        reverse(hr.begin(),hr.end());
    }
    string mn;
    if(minm < 10){
        mn.push_back('0');
        mn.push_back(char(minm+'0'));
    }
    else{
        while(minm>0){
            mn.push_back(char((minm%10)+'0'));
            minm/=10;
        }
        reverse(mn.begin(),mn.end());
    }
    total = hr + ':' + mn;
    string k = total;
    reverse(k.begin(),k.end());
    if(k == total)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int hrs = 0;
    int minm = 0;
    for(int i=0;i<2;i++){
        hrs = (hrs * 10) + (s[i] - '0');
    }
    for(int i=3;i<=4;i++){
        minm = (minm * 10) + (s[i] - '0');
    }
    int con = 0;
    while(1){
        if(comp(hrs,minm))
            break;
        con++;
        minm++;
        if(minm == 60){
            minm = 0;
            hrs++;
        }
        if(hrs == 24)
            hrs = 0;
    }
    cout<<con;
    return 0;
}
