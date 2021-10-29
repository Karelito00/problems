#include <bits/stdc++.h>

using namespace std;
int z[3];
int main()
{
   int c=0,g=0,h=0,j=0;
   string m;
   while(c<3){
    int a;
    cin>>a;
    z[c]=a;
    c++;
   }
cin>>m;
   for(int y=0;y<=c-1;y++){
    if(z[y]>g)
        g=z[y];
   }
   for(int o=0;o<=c-1;o++){
    if(z[o]<g && z[o]>h)
        h=z[o];
   }

   for(int k=0;k<=c-1;k++){
   if(z[k]<h && z[k]<g)
        j=z[k];
   }
   if(m=="ABC"){
    cout<<j<<" "<<h<<" "<<g;
   }
if(m=="BAC"){
    cout<<h<<" "<<j<<" "<<g;
   }
   if(m=="ACB"){
    cout<<j<<" "<<g<<" "<<h;
   }
if(m=="BCA"){
    cout<<h<<" "<<g<<" "<<j;
   }
if(m=="CAB"){
    cout<<g<<" "<<j<<" "<<h;
   }
   if(m=="CBA"){
    cout<<g<<" "<<h<<" "<<j;
   }


    return 0;
}