#include <bits/stdc++.h>

using namespace std;
class Elements{
public:
    int p,no1,no2;
    Elements(int p1,int no11,int no21){
        p=p1;
        no1=no11;
        no2=no21;
    }
    Elements(){}
    bool operator < (const Elements& hola)const{
        return hola.p > p;
    }
};
int p[10001];
Elements z[10001];
int find_set(int x){
    if(x==p[x])
        return x;
    return p[x]=find_set(p[x]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int n,m;
        cin>>n>>m;
        for(int u=0;u<m;u++){
            int n1,n2,p;
            cin>>n1>>n2>>p;
            z[u]=Elements(p,n1,n2);
        }
        for(int o=1;o<=n;o++)
            p[o]=o;
        sort(z,z+m);
        vector <Elements> arist;
        int suma=0;
        for(int u=0;u<m;u++){
            int w=z[u].p,n1=z[u].no1,n2=z[u].no2;
            int set1=find_set(n1);
            int set2=find_set(n2);
            if(set1!=set2){
                arist.push_back(Elements(w,n1,n2));
                suma+=w;
                p[set1]=set2;
            }
        }
        pair <int,int> best;
        best.first=0;
        best.second=99999999;
        for(int k=0;k<arist.size();k++){
            int p1=arist[k].p,nodo1=arist[k].no1,nodo2=arist[k].no2;
            for(int u=1;u<=n;u++)
                p[u]=u;
            int h=0,con=0;
            for(int y=0;y<m;y++){
                int p2=z[y].p,nodo3=z[y].no1,nodo4=z[y].no2;
                if(p2==p1 && nodo1==nodo3 && nodo2==nodo4)
                    continue;
                int set1=find_set(nodo3);
                int set2=find_set(nodo4);
                if(set1!=set2){
                    h+=p2;
                    p[set1]=set2;
                    con++;
                }
            }
            if(best.first<con){
                best.second=h;
                best.first=con;
            }
            else if(best.first==con){
                if(best.second>h){
                    best.second=h;
                }
            }
        }
        cout<<suma<<" "<<best.second<<"\n";
    }
    return 0;
}
