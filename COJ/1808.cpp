#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        string s,c;
        cin>>s;
        if(s=="X")
            break;
        cin>>c;
        int suma=0;
        for(int i=0;i<s.size();i++)
            if(s[i]!=c[i])
            suma++;
        cout<<"Hamming distance is "<<suma<<".\n";
    }
    return 0;
}
