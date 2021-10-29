#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int y = n;
    vector < int > num;
    while(y > 0){
        num.push_back(y%10);
        y/=10;
    }
    sort(num.begin(),num.end());
    int best = 100000000;
    do{
        int newn = 0;
        for(int i=0;i<(int)num.size();i++)
            newn = (newn *10) + num[i];
        if(newn > n)
            best = mn(best,newn);
    }while(next_permutation(num.begin(),num.end()));
    if(best != 100000000)
        cout<<best;
    else
        cout<<0;
    return 0;
}
