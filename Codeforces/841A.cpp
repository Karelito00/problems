#include <bits/stdc++.h>

using namespace std;

map < char , int > mapa;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i = 0; i < n; i++){
        mapa[s[i]]++;
        if(mapa[s[i]] > k){
            cout<<"NO";
            exit(0);
        }
    }
    cout<<"YES";
    return 0;
}
