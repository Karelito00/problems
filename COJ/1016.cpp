#include <bits/stdc++.h>

using namespace std;
vector < pair < float , pair < int , int > > > nodos;
pair < int , pair < float , float > > z[100];
int p[100];
int find_set(int x){
    if(x!=p[x])
        return p[x]=find_set(p[x]);
    return p[x];
}
int main()
{
    int a,costo,n=1;
    cin>>a;
    for(int i=0;i<a;i++){
        float n1,n2;
        cin>>n1>>n2;
        z[i].second.first=n1,z[i].second.second=n2;
        z[i].first=n;
        n++;
    }

    for(int i=0;i<a;i++){
        for(int j=i+1;j<a;j++){
            float k=sqrt(((z[i].second.first-z[j].second.first)*(z[i].second.first-z[j].second.first))+((z[i].second.second-z[j].second.second)*(z[i].second.second-z[j].second.second)));
                nodos.push_back(make_pair(k,make_pair(z[i].first,z[j].first)));
        }
    }
    for(int l=0;l<a;l++){
        p[l]=l;
    }
    sort(nodos.begin(),nodos.end());
    float suma=0;
    int cnt=0;
    for(int k=0; k<nodos.size() && cnt < a-1 ;k++){
        int n1=nodos[k].second.second;
        int n2=nodos[k].second.first;
        float w=nodos[k].first;
        int set1=find_set(n1),set2=find_set(n2);
        if(set1!=set2){
            suma+=w;
            cnt++;
            p[set1]=set2;
        }
    }
        printf("%.2f",suma);
    return 0;
}
