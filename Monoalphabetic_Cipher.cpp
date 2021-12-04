#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string ToLowChar(string str, ll sz)
{
    for(ll i = 0; i<sz; i++) str[i] = tolower(str[i]);
    return str;
}
int main()
{
    string Plain;
    getline(cin,Plain);
    Plain = ToLowChar(Plain,(ll)Plain.size());
    srand((unsigned) time(NULL));
    vector<char>v1;
    for(char c = 'a'; c<='z'; c++)v1.push_back(c);
    string Cipher = "";
    while(!v1.empty())
    {
        ll Random = rand() % v1.size();
        //Debug
        //cout<<Random<<" ";
        auto it = v1.begin()+Random;
        Cipher += v1[Random];
        swap(v1[v1.size()-1],v1[Random]);
        v1.erase(v1.end()-1);
    }
    cout<<"Plain: "<<Plain<<endl;
    cout<<"Cipher: "<<Cipher<<endl;
    for(ll i =0; i<Plain.size(); i++)
    {
        if(Plain[i] != ' ')
        {
            ll __x = Plain[i] - 'a';
            cout<<Cipher[__x];
        }
        else cout<<" ";
    }

}
