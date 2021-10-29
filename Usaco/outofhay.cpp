#include <bits/stdc++.h>

using namespace std;
vector < pair <int , pair <int,int> > > edge;
int p[2000];
int find_set(int x){
    if(x != p[x])
        return p[x]=find_set(p[x]);
    return p[x];
}
int main()
{
    freopen("outofhay.in","r",stdin);
    freopen("outofhay.out","w",stdout);
    int a,m;
    cin>>a>>m;
    for(int i=0;i<m;i++){
        int n1,n2,w;
        cin>>n1>>n2>>w;
        edge.push_back(make_pair(w,make_pair(n1,n2)));
    }
    for(int k=0;k<a;k++)
        p[k]=k;
    sort(edge.begin(),edge.end());
    int cnt=0,maxm=0;
    for(int j=0;j<edge.size() && cnt < a-1;j++){
        int n1=edge[j].second.first;
        int n2=edge[j].second.second;
        int w=edge[j].first;
        int set1=find_set(n1),set2=find_set(n2);
        if(set1!=set2){
            if(maxm<w)
                maxm=w;
            cnt++;
            p[set1]=set2;
        }
    }
    cout<<maxm;
    return 0;
}
