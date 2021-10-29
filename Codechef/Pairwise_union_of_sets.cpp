#include <bits/stdc++.h>
 
using namespace std;
 
bool marc[2501];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector < int > s[2501];
        for(int i=0;i<n;i++){
            int y;
            cin>>y;
            while(y--){
                int l;
                cin>>l;
                s[i].push_back(l);
            }
        }
        int con = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cant = 0;
                if(s[i].size()+s[j].size()<k)
                    continue;
                for(int y=0;y<(int)s[i].size();y++){
                    if(!marc[s[i][y]]){
                        marc[s[i][y]] = true;
                        cant++;
                    }
                }
                for(int y=0;y<(int)s[j].size();y++){
                    if(!marc[s[j][y]]){
                        marc[s[j][y]] = true;
                        cant++;
                    }
                }
                if(cant == k)
                    con++;
                for(int ll=0;ll<=k+5;ll++)
                    marc[ll] = false;
            }
        }
        cout<<con<<"\n";
    }
    return 0;
}
//Brute Force
