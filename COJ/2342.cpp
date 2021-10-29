#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>>m;
    for(int u=0;u<m;u++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int bests=-100000,sum1=0,men=0;
        for(int y=0;y<n;y++){
            int t;
            cin>>t;
            sum1+=t;
            bests=max(bests,sum1-men);
            men=min(men,sum1);
        }
        string k;
        cin>>k;
        int bests2=-100000,sum2=0,men2=0;
        for(int y=0;y<n;y++){
            int t;
            cin>>t;
            sum2+=t;
            bests2=max(bests2,sum2-men2);
            men2=min(men2,sum2);
        }
        if(bests2>bests)
            cout<<k<<" "<<bests2<<"\n";
        else if(bests2<bests)
            cout<<s<<" "<<bests<<"\n";
        else
            cout<<"Tied "<<bests<<"\n";
    }
    return 0;
}
