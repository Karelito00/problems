    #include <bits/stdc++.h>
    using namespace std;
     
    set <long long> number;
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            int n,m;
            cin>>n>>m;
            for(int i=0;i<n;i++){
                long long y;
                cin>>y;
                number.insert(y);
            }
            for(int u=0;u<m;u++){
                long long n1;
                cin>>n1;
                if(number.find(n1)!=number.end())
                    cout<<"YES\n";
                else{
                    cout<<"NO\n";
                    number.insert(n1);
                }
            }
            number.clear();
        }
        return 0;
    }
