#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::string;
using std::stack;

class Solution {
 public:
  int CalculatePoints(vector<string> &ops) {
    stack<int> s;
    for (const string &op : ops) {
      if (op == "C") s.pop();
      else if (op == "D") s.push(2 * s.top());
      else if (op == "+") AddTopTwo(s);
      else s.push(std::stoi(op));
    }

    int sum = 0;
    while (!s.empty())
      sum += s.top(), s.pop();
    return sum;
  }

 private:
  void AddTopTwo(stack<int> &s) {
    int top1, top2;
    top1 = s.top(), s.pop();
    top2 = s.top();
    s.push(top1), s.push(top1 + top2);
  }
};