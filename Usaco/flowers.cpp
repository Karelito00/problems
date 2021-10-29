#include <bits/stdc++.h>

using namespace std;
bool visited[100000];
int main()
{
    freopen("flowers.in","r",stdin);
    freopen("flowers.out","w",stdout);
    int a,t;
    cin>>a>>t;
    int suma=0;
    for(int i=0;i<t;i++){
        int beg,aum;
        cin>>beg>>aum;
        beg--;
        while(beg<=a){
            if(visited[beg]==false){
                visited[beg]=true;
            }
            beg+=aum;
        }
    }
    for(int h=0;h<a;h++)
        if(visited[h]==false)
            suma++;
    cout<<suma;
    return 0;
}
