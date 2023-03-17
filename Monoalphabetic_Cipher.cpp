#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

string ToLowChar(string str, ll sz) {
    for (ll i = 0; i < sz; i++) str[i] = tolower(str[i]);
    return str;
}

string RandCipherPlain() {
    srand((unsigned) time(NULL));
    vector<char> v1;
    for (char c = 'a'; c <= 'z'; c++) v1.push_back(c);
    string Cipher = "";
    while (!v1.empty()) {
        ll Random = rand() % v1.size();
        //Debug
        //cout<<Random<<" ";
        auto it = v1.begin() + Random;
        Cipher += v1[Random];
        swap(v1[v1.size() - 1], v1[Random]);
        v1.erase(v1.end() - 1);
    }
    return Cipher;
}

void solve(string txt, bool IsEnc, string CipherPlain) {
    if (IsEnc) {
        cout << "Plain: " << txt << endl;
        cout << "Cipher: " << CipherPlain << endl;
        for (ll i = 0; i < txt.size(); i++) {
            if (txt[i] != ' ') {
                ll __x = txt[i] - 'a';
                cout << txt[__x];
            } else cout << " ";
        }
    } else {
        unordered_map<char, ll> temp;
        for (ll i = 0; i < CipherPlain.size(); i++) {
            temp[CipherPlain[i]] = i;
        }
        for (ll i = 0; i < txt.size(); i++) {
            char __x = 'a' + temp[txt[i]];
            cout << __x;
        }
    }
}

int main() {
    cout << "Please enter a text \n";
    string txt;
    getline(cin, txt);
    txt = ToLowChar(txt, (ll) txt.size());
    bool IsEnc;
    cout << "Do you want to encrypt or decrypt 1 or 0";
    cin >> IsEnc;
    if (IsEnc) solve(txt, IsEnc, RandCipherPlain());
    else {
        cout << "please enter CipherPlain\n";
        string RandCipherPlain;
        cin >> RandCipherPlain;
        solve(txt, IsEnc, RandCipherPlain);
    }
}
