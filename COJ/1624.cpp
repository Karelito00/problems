#include <bits/stdc++.h>

using namespace std;
class par{
public:
    int ini=0,fin=0;
    par(int ini1,int fin1){
        ini=ini1;
        fin=fin1;
    }
    par(){}
    bool operator < (const par& hola)const{
        return hola.ini > ini;
    }
};
int con;
par z[1000001];
bool flag[1002];
int dp[1002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int tam=s.size();
        for(int i=0;i<tam;i++){
            z[con]=par(i,i);
            con++;
            if(s[i]==s[i+1] && i!=tam-1){
                z[con]=par(i,i+1);
                con++;
                for(int j=i+2,k=i-1;j<tam && k>=0;j++,k--){
                    if(s[j]==s[k]){
                        z[con]=par(k,j);
                        con++;
                    }
                    else
                        break;
                }
            }
            for(int j=i+1,k=i-1;j<tam && k>=0;j++,k--){
                if(s[j]==s[k]){
                    z[con]=par(k,j);
                    con++;
                }
                else
                    break;
            }
        }
    sort(z,z+con);
    int best=10001;
    for(int u=0;u<con;u++){
        if(z[u].ini==0){
            flag[z[u].fin+1]=true;
            dp[z[u].fin+1]=1;
        }
        else if(flag[z[u].ini]==true){
            if(flag[z[u].fin+1]==true){
                dp[z[u].fin+1]=min(dp[z[u].fin+1],dp[z[u].ini]+1);
            }
            else{
                dp[z[u].fin+1]=dp[z[u].ini]+1;
                flag[z[u].fin+1]=true;
            }
        }
        if(z[u].fin+1==tam) best=min(best,dp[z[u].fin+1]);
    }
    cout<<best;
    return 0;
}
