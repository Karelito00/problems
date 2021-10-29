#include <bits/stdc++.h>

using namespace std;

int z[120];
bool mark[15];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool no = false;
        for(int i=0;i<n;i++){
            cin>>z[i];
            if(z[i] > 7) no = true;
            mark[z[i]] = true;
        }
        for(int i=1;i<8;i++)
            if(!mark[i]) no = true;
        for(int i=1;i<=n/2;i++){
            if(z[i] - z[i-1] <= 1 && z[i] - z[i-1] >= 0)
                continue;
            no = true;
        }
        for(int i=n/2 + 1; i < n ; i++){
            if(z[i - 1] - z[i] <= 1 && z[i - 1] - z[i] >= 0)
                continue;
            no = true;
        }
        for(int i=0;i<n;i++)
            if(z[i] != z[n-1-i])
                no = true;

        cout<<(no ? "no\n" : "yes\n");
        fill(mark,mark+14,false);
    }
    return 0;
}
