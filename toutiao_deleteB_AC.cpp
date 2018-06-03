#include<iostream>
#include<string>
#include<vector>

using namespace std;

string deleteB_AC(string& str) {
    vector<char> res;

    for (int i = 0; i < str.size(); ++i) {
        if (!res.empty()) {
            if (str[i] == 'c' && res.back() == 'a') res.pop_back();
            else res.push_back(str[i]);
        }
        else res.push_back(str[i]);

    }

    string resStr;
    for (auto ch : res)
        resStr.push_back(ch);

    return resStr;
}

void Print(string& str) {
    cout << str << "->" << deleteB_AC(str) << endl;
}

int main() {
    string test1 = "aaabccc";   //""
    string test2 = "acacacbbaccb";  //"c"
    string test3 = "caca";

    Print(test1);
    Print(test2);
    Print(test3);

    return 0;
}
