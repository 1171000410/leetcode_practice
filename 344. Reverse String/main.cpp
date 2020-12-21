#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverse(string s) {
        int i = 0, j = s.size() - 1;
        char temp = ' ';
        while(i < j){
            // swap(s[i++], s[j--]);
            temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string p = s.reverse("abcdefghi");
    cout << p << endl;
    return 0;
}
