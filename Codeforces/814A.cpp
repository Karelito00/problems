#include <bits/stdc++.h>

using namespace std;

int z[101];
int kk[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>z[i];
    }
    for(int y=0;y<k;y++){
        cin>>kk[y];
    }
    sort(kk,kk+k);
    int con = k-1;
    for(int i=0;i<n;i++){
        if(z[i] == 0){
            z[i] = kk[con];
            con--;
        }
    }
    bool flag = false;
    for(int i=1;i<n;i++){
        if(z[i] < z[i-1]){
            flag = true;
            break;
        }
    }
    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
