    #include <bits/stdc++.h>
    #define MOD 1000000007
     
    using namespace std;
     
    long long exponent(long long b,long long e){
        if(e == 1)
            return b;
        if(e % 2 == 0){
            b =  exponent(b,e/2);
            return b*b % MOD;
        }
        return exponent(b,e - 1) * b % MOD;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long a,b;
        cin>>a>>b;
        cout<<exponent(a,b);
        return 0;
    }
