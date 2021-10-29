#include <bits/stdc++.h>

using namespace std;

int main()
{
int A,B,C;
  while(scanf("%d %d %d", &A, &B, &C)!=EOF){
    if(A!=B && A!=C )
        cout<<"A\n";
    if(B!=A && B!=C)
        cout<<"B\n";
    if(C!=A && C!=B)
        cout<<"C\n";
    if(A==B && A==C)
        cout<<"*\n";
  }
    return 0;
}
