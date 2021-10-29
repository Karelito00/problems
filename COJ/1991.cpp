#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int p=s.size();
        int TTT=0, TTH=0, THT=0, THH=0, HTT=0, HTH=0, HHT=0, HHH=0;
        for(int h=0;h<p-2;h++){
            string g=s.substr(0,3);
            if(g=="TTT")
                TTT++;
            else if(g=="TTH")
                TTH++;
            else if(g=="THT")
                THT++;
            else if(g=="THH")
                THH++;
            else if(g=="HTT")
                HTT++;
            else if(g=="HTH")
                HTH++;
            else if(g=="HHT")
                HHT++;
            else if(g=="HHH")
                HHH++;
            s.erase(0,1);
        }
        cout<<n<<" "<<TTT<<" "<<TTH<<" "<<THT<<" "<<THH<<" "<<HTT<<" "<<HTH<<" "<<HHT<<" "<<HHH<<"\n";
    }
    return 0;
}
