#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        int con=1;
        for(int u=1;u<s.size();u++){
            if(s[u]!=s[u-1])
                con++;
        }
        cout<<con<<"\n";
    }
    return 0;
}
