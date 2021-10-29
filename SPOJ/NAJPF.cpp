#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)

using namespace std;

int const MAXn = 1e6 + 10;

string s, p;
int TF[MAXn];
vector < int > matching;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>s>>p;
        int ts = s.size(), tp = p.size();
        s = " " + s;
        p = " " + p;
        for(int i = 2; i <= tp; i++){
            int aux = TF[i - 1];
            while(aux > 0 && p[aux + 1] != p[i])
                aux = TF[aux];
            if(p[aux + 1] == p[i])
                aux++;
            TF[i] = aux;
        }
        int aux = 0;
        for(int i = 1; i <= ts; i++){
            while(aux > 0 && p[aux + 1] != s[i])
                aux = TF[aux];
            if(p[aux + 1] == s[i])
                aux++;
            if(aux == tp)
                matching.push_back(i - tp);
        }
        if((int)matching.size() == 0)
            cout<<"Not Found\n";
        else{
            cout<<matching.size()<<"\n";
            for(auto x: matching)
                cout<<x + 1<<" ";
            cout<<"\n";
            matching.clear();
        }
        if(t)
            cout<<"\n";
        for(int i = 0; i < mx(ts,tp); i++)
            TF[i] = 0;
    }
    return 0;
}
