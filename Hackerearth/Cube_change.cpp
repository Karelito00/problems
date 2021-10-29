    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            long long n;
            cin>>n;
            long long suma = n * n;
            if(n==1 || n==2){
                cout<<n<<"\n";
                continue;
            }
            suma += 2*((n-2)*(n-2));
            suma += (n-1) * (n) * 2;
            suma += (n-2) * n;
            cout<<suma<<"\n";
        }
        return 0;
    }
