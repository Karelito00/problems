#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)

using namespace std;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int l = s.size();
        int con = 1;
        long long best = 0;
        char x;
        int beg = -1;
        for(int k=0;k<l;k++){
            if(s[k] != '='){
                beg = k;
                x = s[k];
                break;
            }
        }
        if(beg == -1){
            cout<<1<<"\n";
            continue;
        }
        for(int j=beg+1;j<l;j++){
            if(s[j] == '=')
                continue;
            if(s[j] == x)
                con++;
            else{
                x = s[j];
                best = mx(best,con);
                con = 1;
            }
        }
        best = mx(best,con);
        cout<<best+1<<"\n";
    }

    return 0;
}
