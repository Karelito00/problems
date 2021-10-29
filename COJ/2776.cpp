#include <bits/stdc++.h>

using namespace std;
int notas[10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,q;
    cin>>a>>q;
    int beg=0;
    for(int j=0;j<a;j++){
        int dur;
        cin>>dur;
        while(dur>0){
            notas[beg]=j+1;
            dur--;
            beg++;
        }
    }
    for(int y=0;y<q;y++){
        int qq;
        cin>>qq;
        cout<<notas[qq]<<"\n";
    }
    return 0;
}
