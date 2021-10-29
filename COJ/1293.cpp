#include <bits/stdc++.h>

using namespace std;
int arr[1000];
int main()
{
    arr[0]=2;
    int n;
    cin>>n;
    if(n==0){
        cout<<1;
        exit(0);
    }
    int maxm=1;
    for(int y=1;y<n;y++){
        int nwm=0;
        for(int u=0;u<maxm;u++){
            arr[u]*=2;
            if(u==maxm-1){
                if(arr[u]>=10){
                    while(arr[u]>=10){
                    arr[u]-=10;
                    u++;
                    arr[u]*=2;
                    arr[u]++;
                    }
                }
            }
            else if(arr[u]>=10){
                while(arr[u]>=10){
                    arr[u]-=10;
                    u++;
                    arr[u]*=2;
                    arr[u]++;
                }
            }
            if(u>=maxm)
                nwm=u;
        }
    maxm+=nwm;
    }
    maxm--;
    while(arr[maxm]==0)
        maxm--;
    for(int y=maxm;y>=0;y--)
        cout<<arr[y];
    return 0;
}
