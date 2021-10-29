#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int t;
        cin>>t;
        vector <int> num;
        for(int i=0;i<t;i++){
            int n;
            cin>>n;
            num.push_back(n);
        }
        sort(num.begin(),num.end());
        int cost=0;
        if(num.size()==1)
            cost=num[0];
        for(int y=0;y<num.size()-1;y++)
            cost+=num[y];
        cout<<cost<<"\n";
    }
    return 0;
}