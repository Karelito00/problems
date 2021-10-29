#include <bits/stdc++.h>

using namespace std;
int g[10];
int p[10];
int c[100];
int dados[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n,s,d;
        cin>>n>>s>>d;
        memset(g,0,sizeof g);
        memset(p,0,sizeof p);
        for(int k=0;k<s;k++){
            cin>>c[k];
        }
        for(int o=0;o<d;o++){
            cin>>dados[o];
        }
            int c1=0,t=0,h=0;
        while(h<d){
           if(p[c1]!=s-1 && p[c1]!=-1){
             p[c1]+=dados[h];
             if(c[p[c1]]!=0){
                p[c1]+=c[p[c1]];
             }
            h++;
           }
           if(p[c1]==s-1){
             p[c1]=-1;
             g[t]=c1+1;
             t++;
           }
           c1++;
           if(c1==n)
            c1=0;

        }
        if(t!=0){
        for(int y=0;y<t;y++)
            cout<<g[y]<<" ";
        }
        else
            cout<<"-1";
        cout<<"\n";

    }
    return 0;
}
