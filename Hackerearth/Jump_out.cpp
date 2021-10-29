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
        int best = 999999;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            if(k >= n - i)
                best = min(best,i);
        }
        cout<<best+1;
        return 0;
    }
