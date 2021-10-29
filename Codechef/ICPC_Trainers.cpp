#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)

using namespace std;

long long n,d;

struct karel{
    long long day, lect, s;
    bool operator < (const karel &hola)const{
            return hola.day > day;
    }
}z[100001];

struct par{
    long long lect, s;
    bool operator < (const par &hola)const{
            return hola.s > s;
    }
};

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>d;
        priority_queue < par > cola;
        long long cont = 0;
        for(int i=0;i<n;i++){
            long long dy,le,s;
            cin>>dy>>le>>s;
            long long u = mn(le,d-dy+1);
            cont += ((le-u)*s);
            le = u;
            cont += le * s;
            z[i] = karel{dy,le,s};
        }
        sort(z,z+n);
        int ult = 0;
        for(int i=1;i<=d;i++){
            while(z[ult].day == i && ult < n){
                cola.push(par{z[ult].lect,z[ult].s});
                ult++;
            }
            while(!cola.empty()){
                par p = cola.top();
                cont -= p.s;
                p.lect--;
                cola.pop();
                if(p.lect > 0)
                    cola.push(p);
                break;
            }
        }
        cout<<cont<<"\n";
    }
    return 0;
}
