#include <bits/stdc++.h>

using namespace std;

bool z[32];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        unsigned long long n;
        cin>>n;
        n = n + (1ll<<32) * n;
        if(n == 0){
            cout<<"no\n";
            continue;
        }
        unsigned long long tmp;
        int con = 0;
        for(int i=0;i<32;i++){
            tmp = n >> i;
            if(!z[tmp % 32])
                z[tmp % 32] = true, con++;
        }
        (con == 32 ? cout<<"yes\n" : cout<<"no\n");
        for(int i=0;i<32;i++)
            z[i] = false;
    }
    return 0;
}
