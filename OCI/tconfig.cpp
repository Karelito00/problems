#include <bits/stdc++.h>

using namespace std;

char pal[5001];
struct trio{
    int conf;
    int cant;
    int nm;
}abc[27];
int n, num;
string car;

int main()
{
    freopen("tconfig.in","r",stdin);
    freopen("tconfig.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        pal[i] = s[i];
        if(pal[i] >= 'A' && pal[i] <= 'Z')
            pal[i] = char(pal[i] + 32);
    }
    for(int i=0;i<26;i++){
        abc[i].cant = 99999;
    }
    int tec;
    cin>>tec;
    for(int u=1;u<=tec;u++){
        for(int i=1;i<=9;i++){
            cin>>num>>car;
            for(int j=0;j<(int)car.size();j++){
                int y = (int)(car[j]-'a');
                if(j + 1 < abc[y].cant){
                    abc[y].cant = j + 1;
                    abc[y].nm = num;
                    abc[y].conf = u;
                }
            }
        }
    }
    int ultconf = -1;
    int cont = 0;
    for(int i=0;i<n;i++)
        cont += abc[pal[i]-'a'].cant;
    cout<<cont<<"\n";
    for(int i=0;i<n;i++){
        int config = abc[pal[i]-'a'].conf;
        if(config != ultconf){
            cout<<"#"<<config<<"\n";
            ultconf = config;
        }
        cout<<s[i]<<" ";
        for(int y=0;y<abc[pal[i]-'a'].cant;y++)
            cout<<abc[pal[i]-'a'].nm;
        cout<<"\n";
    }
    return 0;
}
