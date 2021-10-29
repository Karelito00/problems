#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)

using namespace std;

bool arr[26];
vector < int > num;
bool mat[26][26];
int best;
int pt;

bool primo(int n){
    if(n % 2 == 0)
        return false;
    for(int i=3;i*i<=n;i++)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x == 1){
            pt++;
            continue;
        }
        if(!arr[x]){
            arr[x] = true;
            if(x >= 13 && primo(x))
                pt++;
            else
                num.push_back(x);
        }
    }
    int l = num.size();
    for(int i=0;i<l;i++)
        for(int j=i+1;j<l;j++)
            if(__gcd(num[i],num[j]) == 1)
                mat[num[i]][num[j]] = true, mat[num[j]][num[i]] = true;

    for(int mask=0;mask<(1<<l);mask++){
        bool flag = false;
        int con = 0;
        for(int i=0;i<l;i++){
            if(mask&(1<<i)){
                con++;
                for(int j=i+1;j<l;j++){
                    if(mask&(1<<j)){
                        if(!mat[num[i]][num[j]]){
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag)
                    break;
            }
        }
        if(!flag)
            best = mx(best,con);
    }
    cout<<best+pt;
    return 0;
}
