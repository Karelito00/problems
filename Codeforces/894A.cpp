#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sol = 0;
    string s;
    cin>>s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == 'Q'){
            for(int j = i + 1; j < n; j++){
                if(s[j] == 'A'){
                    for(int k = j + 1; k < n; k++){
                        if(s[k] == 'Q') sol++;
                    }
                }
            }
        }
    }
    cout<<sol;
    return 0;
}
