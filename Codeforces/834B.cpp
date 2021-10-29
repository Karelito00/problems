#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)

using namespace std;

int open[(int)(1e6)+5];
int close[(int)(1e6)+5];
pair < int , int > p[27];
int n,k;

string funt(){
    int open_doors = 0;
    for(int i=1;i<=n;i++){
        open_doors += open[i];
        if(open_doors > k)
            return "YES";
        open_doors += close[i];
    }
    return "NO";
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(p[s[i]-'A'].first == 0){
            p[s[i]-'A'].first = i + 1;
            p[s[i]-'A'].second = i + 1;
        }
        else{
            p[s[i]-'A'].second = i + 1;
        }
    }
    for(int i=0;i<26;i++){
        open[p[i].first]++;
        close[p[i].second]--;
    }
    cout<<funt();
    return 0;
}
