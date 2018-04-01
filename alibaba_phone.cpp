#include <iostream>
#include <vector>

using namespace std;

void Solution(const vector<int>& vec) {
    int length = vec.size();
    vector<int> temp(length,0);
    vector<int>::iterator iter = temp.begin();
    for (int i = 0; i < length; ++i) {
        temp[vec[i]-1] = vec[i];

        if (*iter != 0) {
            while (*iter != 0 && iter != temp.end()) {
                cout << *iter << " ";
                ++iter;
            }
            cout << endl;
        }
    }
}

int main()
{
    vector<int> vec = {2,3,1,10,5,4,7,6,8,9,13,11,12};
    Solution(vec);

    return 0;
}
