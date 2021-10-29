#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
long long z[21],m;
int n;
bool cp[21][21];
map <ull,bool> mapa;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>z[i];
    }
    for(int i=0;i<n;i++){
        if(__gcd(m,z[i])==1)
            cp[0][i+1]=true,cp[i+1][0]=true;
        for(int j=i+1;j<n;j++){
            if(__gcd(z[i],z[j])==1)
                cp[i+1][j+1]=true,cp[j+1][i+1]=true;
        }
    }
    int con=0;
    for(int mask=1;mask<(1<<n);mask++){
        bool flag=false;
        ull hj=1;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                hj*=z[i];
                if(cp[i+1][0]==false){
                    flag=true;
                    break;
                }
                for(int j=i-1;j>=0;j--){
                    if(mask&(1<<j)){
                        if(cp[j+1][i+1]==false){
                            flag=true;
                            break;
                        }
                    }
                }
                if(flag)
                    break;
            }
        }
        if((!flag) && mapa[hj]==false){
            mapa[hj]=true;
            con++;
        }
    }
    cout<<con;
    return 0;
}
