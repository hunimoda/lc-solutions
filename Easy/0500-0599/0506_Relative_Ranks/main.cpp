#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::string;

class Solution {
 public:
  vector<string> FindRelativeRanks(vector<int> &scores) {
    vector<int> copy(scores);
    std::sort(copy.begin(), copy.end(), std::greater<>());

    std::unordered_map<int, string> umap;
    for (int i = 0; i < copy.size(); i++) {
      if (i < kMedals.size()) umap[copy[i]] = kMedals[i];
      else umap[copy[i]] = std::to_string(i + 1);
    }
    
    vector<string> ranks;
    for (const int score : scores)
      ranks.push_back(umap[score]);

    return ranks;
  }

 private:
  const vector<string> kMedals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
};