#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int tm = s.size();
        int sol = 0;
        for(int i = 0; i + 3 < tm; i++){
            int c = 0, e = 0, f = 0, h = 0;
            for(int j = i; j < i + 4; j++){
                if(s[j] == 'c') c++;
                else if(s[j] == 'h') h++;
                else if(s[j] == 'e') e++;
                else if(s[j] == 'f') f++;
            }
            if(c == f && f == e && e == h && h == 1)
                sol++;
        }
        if(!sol)
            cout<<"normal";
        else
            cout<<"lovely "<<sol;
        cout<<"\n";
    }
    return 0;
}
