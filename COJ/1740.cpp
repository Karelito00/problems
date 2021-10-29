#include <bits/stdc++.h>

using namespace std;

long long suma;
bool dp[2001][2001];
int beg[2001];
int fin[2001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int con = 0;
    int tam = s.size();
    for(int i=0;i<tam;i++){
        dp[i][1]=true;
        beg[i]++;
        fin[i]++;
        con++;
        if(i>=1){
            if(s[i]==s[i-1]){
                dp[i][2] = true;
                beg[i-1]++;
                fin[i]++;
                con++;
            }
        }
    }
    for(int l=3;l<=tam;l++){
        for(int i=0;i<=tam-l;i++){
            if(s[i]==s[i+l-1]){
                if(dp[i+1][l-2]==true){
                    dp[i][l] = true;
                    beg[i]++;
                    fin[i+l-1]++;
                    con++;
                }
            }
        }
    }
    for(int i=1;i<tam;i++){
        beg[i] += beg[i-1];
    }
    for(int i=1;i<tam;i++){
        suma += (fin[i-1]*(beg[tam-1]-beg[i-1])) * 1LL;
    }
    cout<<suma;
    return 0;
}
