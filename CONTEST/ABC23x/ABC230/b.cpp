#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    string t = "";
    while(t.size() < 30){ 
        t += "oxx";
    }

    if(t.find(s) != string::npos){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// バカコード
// int main(){
//     string s;
//     cin >> s;

//     string t;
//     int a = 100000;

//     for(int a = 0; a < 100000; ++a){
//         t += "oxx";
//     }

//     bool same = false;

//     for(int i = 1; i < t.size(); ++i){
//         for(int j = 1; j < t.size(); ++j){
//             if(s == t.substr(i,j)){
//                 same = true;
//                 break;
//             }
//         }
//     }

//     if(same){
//         cout << "Yes" << endl;
//     }else
//     {
//         cout << "No" << endl;
//     }

//     return 0;

// }
