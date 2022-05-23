#include <string>

class Solution {

public:
    int str_str(std::string haystack, std::string needle) {

        const size_t needle_len { needle.length() };

        if (needle_len == 0) return 0;
        if (haystack.length() < needle_len) return -1;

        const size_t last_haystack { 
            haystack.length() - needle_len
        };

        for (int h { 0 }; h <= last_haystack; h++) {
            if (haystack.at(h) != needle.at(0)) continue;

            for (int n { 0 }; n < needle_len; n++) {
                if (haystack.at(h + n) != needle.at(n)) {
                    h += n;
                    break;
                }

                if (n == needle_len - 1) return h;
            }
        }

        return -1;

    }

};