#include <bits/stdc++.h>

using namespace std;
int dist[100001];
int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>dist[i];
    }
    sort(dist,dist+a);
    int best=99999999;
    for(int b=0,i=a-1;b<a/2;i--,b++){
        best=min(best,dist[b]+dist[i]);
    }
    cout<<best;
    return 0;
}
