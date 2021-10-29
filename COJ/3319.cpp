#include <bits/stdc++.h>

using namespace std;

int main (){
int P[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

long long a[110];
for (int i=1;i<=100;i++){
        a[i]=1;
    for (int j=0;j<=24;j++){
        if(P[j]<=i)a[i]*=P[j];
    }
}
int niuber;
cin>>niuber;

while (niuber--){
    int h;
    cin>>h;
    cout<<a[h]<<endl;
}
return 0;
} 