#include <bits/stdc++.h>

using namespace std;

vector < long long > y;
vector < long long > x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    while(cin>>n){
        vector < pair < long long , long long > > points;
        for(int i=0;i<n;i++){
            long long x1,y1;
            cin>>x1>>y1;
            y.push_back(y1);
            x.push_back(x1);
            points.push_back(make_pair(y1,x1));
        }
        if(n == 1){
            cout<<0<<"\n";
            x.clear();
            y.clear();
            continue;
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        long long cy = 0,cx = 0;
        if(n % 2 == 0){
            cx = (x[n/2] + x[(n/2)-1]) >> 1;
            cy = (y[n/2] + y[(n/2)-1]) >> 1;
        }
        else{
            cx = x[n/2];
            cy = y[n/2];
        }
        long long suma = 0;
        for(int i=0;i<n;i++){
            suma += abs(cy - y[i]) + abs(cx - x[i]);
        }
        cout<<suma<<"\n";
        x.clear();
        y.clear();
    }
    return 0;
}
