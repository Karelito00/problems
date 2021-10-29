#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        string s;
        cin>>s;
        if(s=="0")
            exit(0);
        sort(s.begin(),s.end());
        string k,n;
        int con=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                con=i;
                break;
            }
            k.push_back('0');
        }
        n.push_back(s[con]);
        n+=k;
        for(int u=con+1;u<s.size();u++)
            n.push_back(s[u]);
        long long suma=0;
        do{
            long long num=n[0]-'0';
            for(int i=1;i<n.size();i++)
                num=(num*10)+n[i]-'0';
            suma+=num;
        }while(next_permutation(n.begin(),n.end()));
        cout<<suma<<"\n";
    }
    return 0;
}
