#include <bits/stdc++.h>

using namespace std;

class Palab{
public:
    string n;
    Palab(string s){
        n=s;
    }
    Palab(){}
    bool operator < (const Palab& str)const{
     return n > str.n;
    }
};
Palab z[50];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            string k;
            cin>>k;
            z[j].n=k;
        }
       sort(z,z+n);
        string s;
        while(z[0].n!=""){
            s.push_back(z[0].n[0]);
            z[0].n.erase(0,1);
            sort(z,z+n);
        }
        cout<<s<<"\n";
    }
    return 0;
}
