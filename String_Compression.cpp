#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string ToString(ll cnt)
{
    string str;
    while(cnt > 0)
    {
        ll digit = cnt % 10;
        str += (digit + '0');
        cnt  /= 10;

    }
    reverse(str.begin(),str.end());
    return str;
}
void solve(string &str)
{
    string res;
    ll cnt = 0;
    char cur ;
    for(ll i =0; i<str.size(); i++)
    {
        if(cnt == 0)
        {
            cur = str[i],cnt++;
        }
        else if(str[i] == cur) cnt++;
        else
        {
            res += cur;
            string c = ToString(cnt);
            res+=c;
            cur = str[i], cnt = 1;
        }
    }
    res += cur;
    string c = ToString(cnt);
    res+=c;
    if(res.size() <= str.size()) cout<<res<<"\n";
    else cout<<"Same Sting : "<<str <<" Instead Of "<<res<<"\n";

}
int main()
{
    while(true)
    {
        string str;
        cin>>str;
        solve(str);
    }
}
