#include <bits/stdc++.h>

using namespace std;

vector < long long > numer;

int main(){

    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    string s;
    getline(cin,s);
    while(t--){
        getline(cin,s);
        long long num = 0;
        for(int i=0;i<(int)s.size();i++){
            if(s[i] == ' '){
                if(num != 0)
                    numer.push_back(num);
                num = 0;
            }
            else if(s[i] >= '0' && s[i] <= '9')
                num = (num * 10) + (long long)(s[i] - '0');
        }
        long long sol = 0;
        if(num != 0)
            numer.push_back(num);
        sort(numer.begin(),numer.end());
        int n = lower_bound(numer.begin(),numer.end(),numer.size()-1) - numer.begin();
        for(int i=0;i<(int)numer.size();i++)
            if(i != n)
                sol = max(sol,numer[i]);
        cout<<sol<<"\n";
        numer.clear();
    }
    return 0;
}
