#include <bits/stdc++.h>

using namespace std;
int obj1[101];
int obj2[101];
int dp1[100001];
int dp2[100001];
int main()
{
    int suma=0;
    int n1;
    cin>>n1;
    dp1[0]=1;
    for(int y=0;y<n1;y++){
        cin>>obj1[y];
        suma+=obj1[y];
    }
    int suma2=0;
    int n2;
    cin>>n2;
    dp2[0]=1;
    for(int y=0;y<n2;y++){
        cin>>obj2[y];
        suma2+=obj2[y];
    }
    for(int y=0;y<n1;y++){
        int ob=obj1[y];
        for(int h=suma;h>=ob;h--){
            if(dp1[h]==0){
                if(dp1[h-ob]!=0)
                    dp1[h]=dp1[h-ob]+1;
            }
            else{
                if(dp1[h-ob]!=0)
                    dp1[h]=min(dp1[h],dp1[h-ob]+1);
            }
                if(h==ob)
                    dp1[h]=1;
        }
    }
    for(int y=0;y<n2;y++){
        int ob=obj2[y];
        for(int h=suma2;h>=ob;h--){
            if(dp2[h]==0){
                if(dp2[h-ob]!=0)
                    dp2[h]=dp2[h-ob]+1;
            }
            else{
                if(dp2[h-ob]!=0)
                    dp2[h]=min(dp2[h],dp2[h-ob]+1);
            }
                if(h==ob)
                    dp2[h]=1;
        }
    }
    int sol=INT_MAX;
    if(suma>suma2){
        for(int u=1;u<=suma2;u++){
            if(dp1[u]!=0 && dp2[u]!=0)
                sol=min(sol,dp1[u]+dp2[u]);
        }
    }
    else{
        for(int u=1;u<=suma;u++){
            if(dp1[u]!=0 && dp2[u]!=0)
                sol=min(sol,dp1[u]+dp2[u]);
        }
    }
    if(sol!=INT_MAX)
        cout<<sol;
    else
        cout<<"imposible";
    return 0;
}