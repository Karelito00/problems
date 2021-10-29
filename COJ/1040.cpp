#include <bits/stdc++.h>

using namespace std;
int grade[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(1){
        cin>>n>>m;
        vector <int> adya[100001];
        if(n==m && n==0)
            break;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            a--; b--;
            adya[b].push_back(a);
            grade[a]++;
        }
        queue <int> cola;
        for(int i=0;i<n;i++){
            if(grade[i]==0)
                cola.push(i);
        }
        vector <int> cam;
        while(!cola.empty()){
            int v=cola.front();
            cola.pop();
            cam.push_back(v);
            for(int u=0;u<adya[v].size();u++){
                grade[adya[v][u]]--;
                if(grade[adya[v][u]]==0)
                    cola.push(adya[v][u]);
            }
        }
        if(cam.size() < n){
            cout<<"IMPOSSIBLE\n";
        }else
        for(int g=cam.size()-1;g>=0;g--)
            cout<<cam[g]+1<<"\n";
        memset(grade,0,sizeof grade);
    }
    return 0;
}
