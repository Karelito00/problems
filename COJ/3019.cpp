#include <bits/stdc++.h>

using namespace std;

vector < int > vect;
vector < int > vect2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int xx;
            cin>>xx;
            vect.push_back(xx);
            vect2.push_back(xx);
        }
        int suma = 0;
        sort(vect2.begin(),vect2.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vect2[j] == vect[i]){
                    suma += abs(j - i);
                    break;
                }
            }
        }
        cout<<suma<<"\n";
        vect.clear();
        vect2.clear();
    }
    return 0;
}
