#include <bits/stdc++.h>

using namespace std;

bool criba[1000020];
vector <long long> nump;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=2;i<=1000005;i++){
        for(int j=i;j<=1000005;j+=i){
            if(j==i && !criba[j])
                nump.push_back(j);
            if(j!=i)
                criba[j]=true;
        }
    }
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long kk = n;
        long long suma = 1;
        long long suma1 = 0;
        for(int i=1;1ll*i*i<=n;i++){
            if(n%i==0){
                suma1 += i;
                if(n/i != i){
                    suma1 += n/i;
                }
            }
        }
        vector < pair < long long , long long > > v;
        for(int i=0;i<(int)nump.size();i++){
            if(n < nump[i])
                break;
            int con = 0;
            while(n % nump[i] == 0){
                n /= nump[i];
                con++;

            }
            if(con != 0)
                v.push_back(make_pair(nump[i],con));
        }
        if(n!=1)
            v.push_back(make_pair(n,1));
        for(auto y: v){
            long long x = 1, sum = 1;
            //cout<<y.first<<" "<<y.second<<" ";
            for(int i=0;i<=y.second;i++){
                x *= y.first;
            }
            x -= 1;
            x /= (y.first-1);
            suma *= x;
        }
        //cout<<suma<<" "<<suma1<<"\n";
        if(suma-kk > kk)
            cout<<"abundant\n";
        else if(suma-kk < kk)
            cout<<"deficient\n";
        else
            cout<<"perfect\n";
    }
    return 0;
}
