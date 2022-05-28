class Solution {
 public:
  int FindComplement(int num) {
    int complement = 0;
    for (int i = 0; num >> i; i++)
      complement |= (~(num >> i & 1) & 1) << i;
    return complement;
  }
};