#include <bits/stdc++.h>

using namespace std;

long long z[(int)(1e5)+10];

int n,d;

long long SOLVE(){
    long long num = 0;
    for(int i = 0; i < d; i++){
        long long suma = 0;
        long long con = 0;
        for(int j = i; j < n; j+=d){
            suma += z[j];
            con++;
        }
        if(suma % con != 0)
            return -1;
        if(i > 0 && suma / con != num)
            return -1;
        num = suma/con;
    }
    long long sol = 0;
    for(int i = 0; i < d; i++){
        for(int j = i; j < n;j+=d){
            if(j + d >= n) break;
            if(z[j] > num)
                z[j + d] += z[j] - num;
            else
                z[j + d] -= num - z[j];
            sol += abs(z[j] - num);
            z[j] = num;
        }
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;i++)
            cin>>z[i];
        cout<<SOLVE()<<"\n";
    }
    return 0;
}
