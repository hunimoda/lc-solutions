#include <array>
#include <vector>
#include <algorithm>

using std::array;
using std::vector;
using std::find;

class MyHashSet {
 public:
  MyHashSet() = default;
  void Add(int key) {
    if (!Contains(key)) storage[Hash(key)].push_back(key);
  }

  void Remove(int key) {
    const int hash_key = Hash(key);
    auto it = find(storage[hash_key].begin(), storage[hash_key].end(), key);
    if (it != storage[hash_key].end())
      storage[Hash(key)].erase(it);
  }

  bool Contains(int key) {
    const int hash_key = Hash(key);
    return storage[hash_key].end() !=
           find(storage[hash_key].begin(), storage[hash_key].end(), key);
  }

 private:
  static const int kStorageSize = 997;
  static const int kWeirdPrime = 1009;
  array<vector<int>, kStorageSize> storage;

  int Hash(uint32_t key) {
    return key * kWeirdPrime % kStorageSize;
  }
};