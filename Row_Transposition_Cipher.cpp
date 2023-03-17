#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    string Key;
    string Text;
    char Type;
    cout << "Please Enter Key: ";
    cin >> Key;
    ll KeySz = Key.size();
    cout << "Please Enter Text : ";
    cin.ignore();
    getline(cin, Text);
    cout << "Please Enter (e) to encrypt, (d) to decrypt : ";
    cin >> Type;
    if (Type == 'e') {
        ll Spaces = 0;
        for (ll i = 0; i < Text.size(); i++) {
            if (Text[i] == ' ') Spaces++;
        }
        ll TextSz = Text.size() - Spaces;
        ll Row = ceil(TextSz * 1.0 / KeySz);
        //Debug
        //cout<<"This row:"<<Row;
        char Grid[Row][KeySz];
        ll idx = 0;
        for (ll i = 0; i < Row; i++) {
            for (ll j = 0; j < KeySz; j++) {
                if (idx < Text.size()) {
                    if (Text[idx] != ' ') Grid[i][j] = Text[idx], idx++;
                    else Grid[i][j] = Text[++idx], idx++;
                } else Grid[i][j] = 'z';
            }
        }
        //Debug
        for (ll i = 0; i < Row; i++) {
            for (ll j = 0; j < KeySz; j++) {
                cout << Grid[i][j] << " ";
            }
            puts("");
        }
        string CipherText = "";
        for (ll i = 0; i < Row; i++) {
            map<ll, char> mp;
            for (ll j = 0; j < KeySz; j++) {
                mp[Key[j] - '0'] = Grid[i][j];
            }
            for (auto &it: mp)CipherText += it.second;
        }
        cout << "CipherText Is: " << CipherText;
    } else {
        map<ll, ll> mp;
        ll Row = Text.size() / KeySz;
        char Grid[Row][KeySz];
        for (ll i = 0; i < Key.size(); i++) {
            mp[Key[i] - '0'] = i;
        }
        //Debug
        //for(auto &it: mp)
        //{
        //    cout<< it.first <<"->"<<it.second<<"\n";
        //}
        ll R = 0;
        auto cur = mp.begin();
        ll cnt = 0;
        for (ll i = 0; i < Text.size(); i++) {
            if (cnt == KeySz) R++, cur = mp.begin(), cnt = 0;
            ll refer = cur->second;
            Grid[R][refer] = Text[i];
            cur++, cnt++;
        }
        string PlainText;
        for (ll i = 0; i < Row; i++) {
            for (ll j = 0; j < KeySz; j++) {
                cout << Grid[i][j] << " ";
                PlainText += Grid[i][j];
            }
            puts("");
        }
        cout << "PlainText Is: " << PlainText;
    }
}
/*
I/P:
3412567
attack postponed until two am
taatckptposonentduiltamwozzz
e

O/P:
a t t a c k p
o s t p o n e
d u n t i l t
w o a m z z z
CipherText Is: ttnaaptmaodwtsuocoizknlzpetz
-----------
-----------
I/P:
83674215
fire on my order
e

O/P:
f i r e o n m y
o r d e r z z z
CipherText Is: mnioyrefzzrrzdeo
-----------------
-----------------
I/P:
83674215
MRNSIRORYSRDEEFO
d

O/P:
R N R O S R M I
O R E F D S Y E
PlainText Is: RNROSRMIOREFDSYE
------------------
------------------
I/P:
58792
sizdettuxacyary
d

O/P:
i d z e s
t x u a t
y r a y c
PlainText Is: idzestxuatyrayc
-------------
-------------
I/P:
58792
sdtaaieucrztxyy
d

O/P:
d a t a s
e c u r i
t y x y z
PlainText Is: datasecurityxyz
*/
