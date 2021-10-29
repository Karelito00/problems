#include <bits/stdc++.h>
#define mx(a,b) (a < b ? a : b)

using namespace std;

int Arr[10001];
int RMQ[10001][100];
int a, b,lg, sol;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>Arr[i];
    for(int i=1; i<=N; i++)
        RMQ[i][0]=Arr[i];
    for(int i=N-1; i>=1; i--)
        for(int j=1; j<=20; j++){
        if(i+(1<<j)-1>N)
            break;
        RMQ[i][j]=mx(RMQ[i][j-1],RMQ[i+(1<<(j-1))][j-1]);
    }
    int M;
    cin>>M;
    for(int i=1; i<=M; i++){
        cin>>a>>b;
        if(a>b)swap(a,b);
        lg=log2(b-a+1);
        sol=mx(RMQ[a][lg],RMQ[b-(1<<lg)+1][lg]);
        cout<<sol<<"\n";
    }

    return 0;
}
