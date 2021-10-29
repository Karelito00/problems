#include <bits/stdc++.h>

using namespace std;
int p[100001];
int cont[100001];
int find_set(int x){
    if(x==p[x])
        return x;
    return p[x]=find_set(p[x]);
}
void union_set(int y,int x){
    int v=find_set(y),u=find_set(x);
    if(cont[v]>cont[u]){
        p[u]=v;
        cont[v]+=cont[u];
        cout<<cont[v]<<"\n";
    }
    else{
        p[v]=u;
        cont[u]+=cont[v];
        cout<<cont[u]<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n;
        cin>>n;
        map <string,int> mapa;
        int con=1;
        for(int u=1;u<=100001;u++){
            p[u]=u;
            cont[u]=1;
        }
        for(int j=0;j<n;j++){
            string s1,s2;
            cin>>s1>>s2;
            if(mapa.find(s1)==mapa.end()){
                mapa[s1]=con;
                con++;
            }
            if(mapa.find(s2)==mapa.end()){
                mapa[s2]=con;
                con++;
            }
            int o1=find_set(mapa[s1]);
            int o2=find_set(mapa[s2]);
            if(o1!=o2){
                union_set(mapa[s1],mapa[s2]);
            }
            else
                cout<<cont[o1]<<"\n";
        }
    }
    return 0;
}
