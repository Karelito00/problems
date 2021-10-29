#include <bits/stdc++.h>

using namespace std;

priority_queue < pair <long long ,long long> > z;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long y,x;
        cin>>y>>x;
        z.push(make_pair(y,x));
    }
    long long my=z.top().first,mx=z.top().second;
    long long area=z.top().first*z.top().second;
    z.pop();
    while(!z.empty()){
        int n1=z.top().first,n2=z.top().second;
        z.pop();
        long long resy = n1 - my;
        long long resx = n2 - mx;
        if(resy>=0 && resx!=0){
            area += resy * n2;
            my = n1;
            if(n2 > mx)
                mx = n2;
        }
        else if(resx>=0 && resx!=0){
            area += resx * n1;
            mx = n2;
            if(n1 > my)
                my = n1;
        }
    }
    cout<<area;
    return 0;
}