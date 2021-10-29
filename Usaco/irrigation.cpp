#include <bits/stdc++.h>

using namespace std;
vector < pair <int, pair <int,int> > > nodos;
pair < int , pair<int,int> > z[2000];
int p[2000];
int find_set(int x){
    if(x!=p[x])
        return p[x]=find_set(p[x]);
    return p[x];
}
int main()
{
    freopen("irrigation.in","r",stdin);
    freopen("irrigation.out","w",stdout);
    int a,costo,n=1;
    cin>>a>>costo;
    for(int i=0;i<a;i++){
        cin>>z[i].second.first>>z[i].second.second;
        z[i].first=n;
        n++;
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(i!=j){
            float k=(((z[i].second.first)-(z[j].second.first))*((z[i].second.first)-(z[j].second.first)))+(((z[i].second.second)-(z[j].second.second))*((z[i].second.second)-(z[j].second.second)));
            if(k>=costo){
                nodos.push_back(make_pair(k,make_pair(z[i].first,z[j].first)));
            }
        }
        }
    }
    for(int l=0;l<a;l++){
        p[l]=l;
    }
    sort(nodos.begin(),nodos.end());
    int suma=0,cnt=0;
    for(int k=0; k<nodos.size() && cnt < a-1 ;k++){
        int n1=nodos[k].second.second;
        int n2=nodos[k].second.first;
        int w=nodos[k].first;
        int set1=find_set(n1),set2=find_set(n2);
        if(set1!=set2){
            suma+=w;
            cnt++;
            p[set1]=set2;
        }
    }
    if(cnt<a-1){
        cout<<-1;
    }
    else
        cout<<suma;
    return 0;
}
