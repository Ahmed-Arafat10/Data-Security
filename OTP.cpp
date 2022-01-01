#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<string> solve(vector<string>&v1,string Text, ll NoOfRows, bool is_print)
{
    ll cnt = 1;
    bool Dir = true, limit = true;
    unordered_map<ll,ll>mp;
    for(ll i = 0; i<Text.size(); i++)
    {
        if(limit) mp[cnt-1] = 0;
        if(Text[i] == ' ') continue;
        if(Dir)
        {
            if(is_print)
            {
                cout<<v1[cnt-1][mp[cnt-1]];
                mp[cnt-1]++;
            }
            else v1[cnt-1] += Text[i];
            cnt++;
        }
        else
        {
            if(is_print)
            {
                cout<<v1[cnt-1][mp[cnt-1]];
                mp[cnt-1]++;
            }
            else v1[cnt-1] += Text[i];
            cnt--;
        }
        if(cnt == (NoOfRows+1)) Dir = false, cnt-=2, limit = false;
        else if(cnt == 0 && i != 0) Dir = true, cnt+=2 ;
    }
    return v1;
}
string ToLower(string Text)
{
    for(ll i =0; i<Text.size(); i++)
    {
        Text[i] = tolower(Text[i]);
    }
    return Text;
}
int main()
{

    ll NoOfRows;
    cout<<"Please Enter Number Of Rows : ";
    cin>>NoOfRows;
    string Text;
    cout<<"Please Enter Text : ";
    cin.ignore();
    getline(cin,Text);
    //Text = ToLower(Text);
    char Type;
    cout<<"please Enter (e) To Encrypt , (d) to Decrypt : ";
    cin>>Type;
    vector<string> v1(NoOfRows);
    v1 = solve(v1,Text,NoOfRows,0);
    if(Type == 'e')
    {
        cout<<"CipherText Is : ";
        for(auto &it:v1) cout<<it;
    }
    else
    {
        ll idx = 0;
        for(ll i =0; i<v1.size(); i++)
        {
            for(ll j = 0; j<v1[i].size(); j++)
            {
                v1[i][j] = Text[idx++];
            }
        }
        //for(auto &it:v1) cout<<it<<" ";
        cout<<"PlainText Is : ";
        v1 = solve(v1,Text,NoOfRows,1);
    }
}
/*
I/P:
2
help us
e

O/P:
hlueps
-------
-------
I/P:
2
hlueps
d

O/P:
helpus
-------
-------
I/P:
2
ecytonrpin
d

O/P:
encryption
-------
-------
I/P:
3
rwouaanwny
d

O/P:
runawaynow
-------
-------
I/P:
3
dlneperigean
d

O/P:
deeplearning
-------
-------
I/P:
3
think positively
e

O/P:
tkiehnpstvlioiy
-------
-------
*/
