#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2,s3;

    cin >> s1 >> s2 >> s3;

    set<string> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);

    if(!s.count("ABC")) cout << "ABC" << endl;
    if(!s.count("ARC")) cout << "ARC" << endl;
    if(!s.count("AGC")) cout << "AGC" << endl;
    if(!s.count("AHC")) cout << "AHC" << endl;

    return 0;
}