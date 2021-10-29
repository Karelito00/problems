#include <bits/stdc++.h>

using namespace std;
int z[12];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int g;
        string s;
        cin>>g>>s;
        for(int j=1;j<s.size();j++){
            if(s[j]=='/'){
                    j+=1;
                    int t=s[j]-'0';
                    j+=1;
            while(s[j]!='/'){
                  t*=10+(s[j]-'0');
                  j++;
            }
            z[t-1]++;
            break;
        }
    }
    }
    for(int i=0;i<12;i++){
        cout<<i+1<<" "<<z[i]<<"\n";
    }
    return 0;
}
