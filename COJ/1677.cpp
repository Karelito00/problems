#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int n,b;
        string s;
        cin>>n>>b>>s;
        vector <int> nume;
        for(int j=0;j<n;j++){
            int h;
            cin>>h;
            nume.push_back(h);
        }
        sort(nume.begin(),nume.end());
        int suma=0;
        if(s=="regular"){
            for(int y=n-1;b>0;b--,y--)
                suma+=nume[y];
        }
        else{
            for(int y=0;y<b;y++)
                suma+=nume[y];
        }
        cout<<suma<<"\n";
    }
    return 0;
}
