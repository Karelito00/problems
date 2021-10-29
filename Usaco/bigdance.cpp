#include <bits/stdc++.h>

using namespace std;
long long rec(int left,int right){
    if(right-left==1)
        return left*right;
    if(right-left==0)
        return 0;
    int mid=(left+right)/2;
    int h=rec(left,mid);
    int h1=rec(mid+1,right);
    return h+h1;
}
int main()
{
    freopen("bigdance.in","r",stdin);
    freopen("bigdance.out","w",stdout);
    int a;
    cin>>a;
    cout<<rec(1,a);
    return 0;
}
