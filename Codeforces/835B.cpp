#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long k;
    cin>>k;
    string s;
    cin>>s;
    long long sum = 0;
    for(int i=0;i<(int)s.size();i++)
        sum += (s[i] - '0');
    if(sum >= k){
        cout<<0;
        return 0;
    }
    sum = k - sum;
    sort(s.begin(),s.end());
    int con = 0;
    for(int i=0;i<(int)s.size();i++){
        if(sum <= 0)
            break;
        sum -= 9 - (s[i] - '0');
        con++;
    }
    cout<<con;
    return 0;
}
