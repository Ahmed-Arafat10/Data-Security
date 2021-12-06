#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char Matrix[5][5];
unordered_map<char,ll> KeywordFreq;
unordered_map<char,pair<ll,ll>> CharCoordinate;
string ToLowChar(string str, ll sz)
{
    for(ll i = 0; i<sz; i++) str[i] = tolower(str[i]);
    return str;
}

int main()
{
    string Keyword, PlainText;
    char Type;// e -> Encryption    d -> Decryption
    getline(cin,Keyword);
    getline(cin,PlainText);
    cin>>Type;
    Keyword = ToLowChar(Keyword,(ll)Keyword.size());
    PlainText = ToLowChar(PlainText,(ll)PlainText.size());
    ll idx = 0;
    char c = 'a';
    bool IsItIorJ = false;
    for(ll i = 0; i<5; i++)
    {
        for(ll j = 0; j<5;)
        {
            if(idx < Keyword.size())
            {
                KeywordFreq[Keyword[idx]]++;
                if(KeywordFreq[Keyword[idx]] == 1 &&  Keyword[idx] != ' ')
                {
                    if(!IsItIorJ)  Matrix[i][j] = Keyword[idx] ;
                    else if(Keyword[idx] != 'i' && Keyword[idx] != 'j') Matrix[i][j] = Keyword[idx];
                    if(Keyword[idx] == 'i' || Keyword[idx] =='j' ) IsItIorJ = true;
                    idx++,j++;
                }
                else idx++;
            }
            else
            {
                bool flag = true;
                while(flag)
                {
                    if(KeywordFreq[c] == 0)
                    {
                        if(!IsItIorJ)  Matrix[i][j] = c;
                        else if(c != 'i' && c != 'j') Matrix[i][j] = c;
                        else Matrix[i][j] = ++c;
                        if(c == 'i' || c =='j' ) IsItIorJ = true;
                        flag = false;
                    }
                    c+=1;
                }
                j++;
            }
        }
    }
//-------------------------
    //Debug -> Print
    for(ll i = 0; i<5; i++)
    {
        for(ll j = 0; j<5; j++)
        {
            printf("%c ",Matrix[i][j]);
            CharCoordinate[Matrix[i][j]] = {i,j};
            if(Matrix[i][j] == 'i') CharCoordinate['j'] = {i,j};
            else if(Matrix[i][j] == 'j') CharCoordinate['i'] = {i,j};
        }
        puts("");
    }
    puts("");
    ll cnt_spaces = 0, cnt_extension = 0;
    if(Type == 'e')
    {
        for(ll i = 0; i<PlainText.size();)
        {
            ll l = i, r = i+1;
            if(r >= PlainText.size()) break;
            if(PlainText[r] == PlainText[l])
            {
                if(PlainText[r] == 'x') PlainText.insert(PlainText.begin()+r,'z');
                else PlainText.insert(PlainText.begin()+r,'x');
                //cnt_extension++;
            }
            if(PlainText[r] == ' ' || PlainText[l] == ' ') cnt_spaces++,i++;
            i+=2;
        }
        ll char_sz = (PlainText.size()) - cnt_spaces;
        if(char_sz & 1)
        {
            if(PlainText[PlainText.size()-1] != 'x')PlainText+= 'x';
            else PlainText+= 'z';
        }
        //Debug
        cout<<"PlainText:    "<<PlainText<<"\n";
    }
    for(ll i = 0; i<PlainText.size();)
    {
        ll l = i, r = i+1;
        if(r >= (PlainText.size() + cnt_extension) ) break;
        if(PlainText[r] == ' ' || PlainText[l] == ' ')
        {
            cout<<" ";
            i++;
            continue;
        }
        //cout<<PlainText[l]<<" "<<PlainText[r]<<"\n";
        pair<ll,ll> C1 = CharCoordinate[ PlainText[l] ] ;
        pair<ll,ll> C2 = CharCoordinate[ PlainText[r] ];
        //------Encryption------------
        if(Type == 'e')
        {
            if(C1.first == C2.first)
            {
                if(C1.second == 4) cout<<Matrix[C1.first][0];
                else cout<<Matrix[C1.first][C1.second+1];
                if(C2.second == 4) cout<<Matrix[C2.first][0];
                else cout<<Matrix[C2.first][C2.second+1];
            }
            else if(C1.second == C2.second)
            {
                if(C1.first == 4) cout<<Matrix[0][C1.second];
                else cout<<Matrix[C1.first+1][C1.second];
                if(C2.first == 4) cout<<Matrix[0][C2.second];
                else cout<<Matrix[C2.first+1][C2.second];
            }
            else
            {
                ll DiffOfCol = abs(C1.second - C2.second);
                if(C1.second > C2.second)
                {
                    cout<<Matrix[C1.first][C1.second-DiffOfCol];
                    cout<<Matrix[C2.first][C2.second+DiffOfCol];
                }
                if(C1.second < C2.second)
                {
                    cout<<Matrix[C1.first][C1.second+DiffOfCol];
                    cout<<Matrix[C2.first][C2.second-DiffOfCol];
                }
            }
            i+=2;
        }
        //------Decryption------------
        if(Type == 'd')
        {
            if(C1.first == C2.first)
            {
                if(C1.second == 0) cout<<Matrix[C1.first][4];
                else cout<<Matrix[C1.first][C1.second-1];

                if(C2.second == 0) cout<<Matrix[C2.first][4];
                else cout<<Matrix[C2.first][C2.second-1];
            }
            else if(C1.second == C2.second)
            {
                if(C1.first == 0) cout<<Matrix[4][C1.second];
                else cout<<Matrix[C1.first-1][C1.second];
                if(C2.first == 0) cout<<Matrix[4][C2.second];
                else cout<<Matrix[C2.first-1][C2.second];
            }
            else
            {
                ll DiffOfCol = abs(C1.second - C2.second);
                if(C1.second > C2.second)
                {
                    cout<<Matrix[C1.first][C1.second-DiffOfCol];
                    cout<<Matrix[C2.first][C2.second+DiffOfCol];
                }
                if(C1.second < C2.second)
                {
                    cout<<Matrix[C1.first][C1.second+DiffOfCol];
                    cout<<Matrix[C2.first][C2.second-DiffOfCol];
                }
            }
            i+=2;
        }
    }
}

/*
I/P:
MONARCHY
HELP ME
e

O/P:
cfpq cl
--------
I/P:

MONARCHY
cfpq cl
d

O/P:
help me
--------
I/P:

playfair example
modlajoqyg
d

O/P:
escapenowx

--------
I/P:
integrity
hidden
e

O/P:
dtkukive
--------
I/P:
integrity
osopwijb
d

O/P:
mqmouter

*/
