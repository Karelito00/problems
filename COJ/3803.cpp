#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)

using namespace std;

int n, arr[100001];
set<int> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        s.clear();
        cin >> n;
        for(int i = 0;i < n;i++)
            cin >> arr[i];
        int l = 0, ans = 0;
        for(int i = 0;i < n;i++){
            while( s.find( arr[i] ) != s.end() )
                s.erase( arr[l++] );
            s.insert( arr[i] );
            ans = mx( ans, i - l + 1 );
        }
        cout << ans << '\n';
    }
    return 0;
}

