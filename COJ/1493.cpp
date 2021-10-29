#include <bits/stdc++.h>

using namespace std;

int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a;
  cin>>a;
  double b,c;
  if(a=="circle"){
    cin>>b;
    printf("%.2f",3.14*(b*b));
  }
  if(a=="triangle"){
    cin>>b>>c;
    printf("%.2f",b*c/2);
  }
  if(a=="rhombus"){
    cin>>b>>c;
    printf("%.2f",(b*c)/2);
  }
    return 0;
}
