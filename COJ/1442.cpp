#include <bits/stdc++.h>
#define base 71
#define mx(x,y) (x > y) ? x : y

using namespace std;

typedef unsigned long long ull;
ull hashing[10000];
ull arr[10000];
ull funt(int a,int b){
    return hashing[b] - (hashing[a-1] * arr[b-a+1]);
}
map <ull,int> mapa;
int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(1){
        getline(cin,s);
        if(s.empty())
            break;
        int con=1;
        arr[0]=1;
        for(int i=0;i<(int)s.size();i++){
            if(s[i]==' ')
                continue;
            hashing[con]=(hashing[con-1]*base)+(s[i]);
            arr[con]=arr[con-1]*base;
            con++;
        }
        for(int i=1;i<=con;i++){
            mapa.clear();
            for(int j=i;j<=con;j++){
                ull t = funt(j-i+1,j);
                mapa[t]++;
            }
            int best=0;
            for(auto x: mapa){
                best = mx (best,x.second);
            }
            if(best<=1)
                break;
            cout<<best<<"\n";
        }
        cout<<"\n";
        s.clear();
    }
    return 0;
}