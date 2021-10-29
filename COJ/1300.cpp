#include <bits/stdc++.h>

using namespace std;

int n[15];
int c =0;

void eli(int a, int pos){
   for(int b=0;b<10;b++){
       if (n[b]==a && pos != b && n[b]!= -1){
          n[b] = -1;
       }
   }
}

int main()
{

   for(int b=0;b<10;b++){
   int d;
   cin>>d;
   n[b]=d%42;
   eli(n[b], b);
   //cout<<b%42<<endl;
   }
   for(int b=0;b<10;b++){
       if (n[b] != -1)
          c++;
   }
   cout<<c;
    return 0;
}