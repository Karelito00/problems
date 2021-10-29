#include <bits/stdc++.h>
using namespace std;

template<typename T> int Int(const T &a) {
	stringstream s;
	s << a;
	int r;
	s >> r;
	return r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    string s;
    cin >> T;
    for(int a=0;a<T;a++){
        cin >> s;
        int N = (s.length() > 2) ? Int(s.substr(s.length()-2,2)) : Int(s);
        if(N%4==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}