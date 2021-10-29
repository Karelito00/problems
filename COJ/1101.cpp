#include <bits/stdc++.h>

using namespace std;

int ult=2;
bool bin[200001];
void funt(int p){
    for(;ult<=p;ult++){
        bool mar=false;
        int y=0;
        int k=ult;
        while(k>0){
            k/=2;
            y++;
        }
        for(int i=0;i<y/2;i++){
            if((!(ult&(1<<i)) && ult&(1<<(y-i-1))) || (ult&(1<<i) && !(ult&(1<<(y-i-1))))){
                mar=true;
                break;
            }
        }
        if(!mar)
            bin[ult]=true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bin[1]=true;
    int n;
    cin>>n;
    while(n--){
        int n1,n2;
        cin>>n1>>n2;
        if(n2<n1)
            swap(n2,n1);
        if(n2>ult){
            funt(n2);
        }
        for(int i=n1;i<=n2;i++)
            if(bin[i]) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}