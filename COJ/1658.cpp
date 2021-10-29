#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
int num[MAX];
int catc[MAX];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n,ma=1;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>num[i];
            catc[i]=1;
            for(int j=i-1;j>=0;j--){
                if(num[i]>num[j]){
                    if(catc[j]+1>catc[i]){
                        catc[i]=catc[j]+1;
                        ma=max(ma,catc[i]);
                    }
                }
            }
        }
        cout<<ma<<"\n";
    }
    return 0;
}
