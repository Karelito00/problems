#include <bits/stdc++.h>

using namespace std;
typedef pair < int, pair <int,int> > pii;
vector <pii> edge;
int p[1000];
int find_set(int x){
    if(x != p[x])
        return p[x]=find_set(p[x]);
    return p[x];
}
int main()
{
    freopen("cowtract.in","r",stdin);
    freopen("cowtract.out","w",stdout);
    int a,m;
    cin>>a>>m;
    for(int k=0;k<m;k++){
        int n1,n2,w;
        cin>>n1>>n2>>w;
        edge.push_back(make_pair(w, make_pair(n1,n2)));
    }
    for(int k=0;k<a;k++){
        p[k]=k;
    }
    sort(edge.begin(),edge.end());
    reverse(edge.begin(),edge.end());
    int cnt=0;
    long long suma=0;
    for(int i=0;i<edge.size() && cnt < a-1;i++){
        int n1=edge[i].second.first;
        int n2=edge[i].second.second;
        int w=edge[i].first;
        int set1=find_set(n1),set2=find_set(n2);
        if(set1!=set2){
            p[set1]=set2;
            suma+=w;
            cnt++;
        }
    }
    if(cnt==a-1)
        cout<<suma;
    else
        cout<<-1;
    return 0;
}
