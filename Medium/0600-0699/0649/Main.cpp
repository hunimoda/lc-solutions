#include <string>
#include <queue>

using namespace std;

class Solution {
 public:
  string predictPartyVictory(const string &senate) {
    // Frontmost banner bans the frontmost bannee.
    queue<char> banner, bannee;
    for (char senator : senate) {
      bannee.push(senator);  // Initially, put all the senators in bannee.
    }

    while (true) {
      if (bannee.empty()) break;  // The banner group is victorious!
      
      // Fill the banner with senators of the same party.
      // Do this until the frontmost bannee is not in the party.
      if (banner.empty() || banner.front() == bannee.front()) {
        banner.push(bannee.front());
        bannee.pop();
      }
      // Banner bans bannee.
      else {
        bannee.pop();
        bannee.push(banner.front());
        banner.pop();
      }
    }
    return (banner.front() == 'R') ? "Radiant" : "Dire";
  }
};