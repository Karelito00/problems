#include <bits/stdc++.h>

using namespace std;

vector < int > num;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    num.push_back(0);
    for(int mask=1;mask<(1<<9);mask++){
        int nu = 0;
        for(int i=0;i<9;i++){
            if(mask&(1<<i)){
                nu = (nu * 10) + (i+1);
            }
        }
        num.push_back(nu);
    }
    sort(num.begin(),num.end());

    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a > b) swap(a,b);
        int posf = upper_bound(num.begin(),num.end(),b) - num.begin() - 1;
        int posi = lower_bound(num.begin(),num.end(),a) - num.begin();
        cout<<posf - posi + 1<<"\n";
    }
    return 0;
}
