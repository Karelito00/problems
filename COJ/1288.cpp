#include <bits/stdc++.h>

using namespace std;

int main (){
    int p;
    cin>>p;
    for(int x=0;x<p;x++){
    int sum=0,suma=0;
char a[10000];
cin>>a;
int h= strlen (a);

if ((a[h-1]-'0')%2==0)sum++;

for (int i=0;i<h;i++){
suma+=a[i]-'0';
}
if(suma%3==0){
sum++;}
if(sum==2)
cout<<"YES \n";
else
cout<<"NO \n";
    }
return 0;

}