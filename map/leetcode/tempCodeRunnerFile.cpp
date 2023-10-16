#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<string> ans;
  vector<string> tmp;
  void search(string s) {
    for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << endl;
    cout << endl;
    if (tmp.size() == 4 && stoi(tmp[3]) <= 255) {
      ans.push_back(tmp[0] + '.' + tmp[1] + '.' + tmp[2] + '.' + tmp[3]);
      return;
    }
    for (int i = 1; i <= 3; i++) {
      string temp = tmp[tmp.size() - 1];
      string l = temp.substr(0, i), r = temp.substr(i);
      if (!r.size() || l.size() > 1 && l[0] == '0') return;
      if (tmp.size() == 3 && r.length() > 1 && r[0] == '0') continue;
      if (temp.length() > (4 - tmp.size() + 1) * 3) return;
      if (stoi(l) > 255) continue;
      tmp.pop_back();
      tmp.push_back(l);
      tmp.push_back(r);
      search(s);
      tmp.pop_back();
      tmp.pop_back();
      tmp.push_back(temp);
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4) return ans;
    tmp.push_back(s);
    search(s);
    return ans;
  }
};
// @lc code=end
int main() {
  Solution so;
  so.restoreIpAddresses("101023");
}