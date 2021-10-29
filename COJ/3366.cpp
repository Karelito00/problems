#include <bits/stdc++.h>

using namespace std;
int z[100];
int p[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,c=0;
    cin>>a;
    for(int i=0;i<a;i++){
        int j;
        cin>>j;
        z[i]=j;
    }
    for(int y=a-1;y>=0;y--){
        for(int h=0;h<y;h++){
            p[c]=z[y]-z[h];
            c++;
        }
    }
    sort(p,p+c);
    if(p[c-1]>=0)
    cout<<p[c-1];
    else
        cout<<"0";
    return 0;
}