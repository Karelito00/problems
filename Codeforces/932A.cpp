#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    deque < char > sol;
    sol.push_back(s[0]);
    for(int i = 1; i < (int)s.size(); i++){
        sol.push_back(s[i]);
        sol.push_front(s[i]);
    }
    while(!sol.empty()){
        cout<<sol.front();
        sol.pop_front();
    }
    return 0;
}
