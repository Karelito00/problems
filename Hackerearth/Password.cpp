    #include <bits/stdc++.h>
    using namespace std;
     
    string z[101];
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>z[i];
        }
        for(int i=0;i<n;i++){
            string s = z[i];
            reverse(s.begin(),s.end());
            for(int j=i+1;j<n;j++){
                if(s == z[j]){
                    cout<<s.size()<<" "<<s[(int)(s.size())/2];
                    return 0;
                }
            }
        }
        return 0;
    }
