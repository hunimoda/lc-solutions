#include <array>
#include <vector>
#include <algorithm>
#include <utility>

using std::array;
using std::vector;
using std::find_if;
using std::pair;

class MyHashMap {
 public:
  MyHashMap() = default;

  void Put(int key, int value) {
    auto &bucket = storage[Hash(key)];
    auto it = find_if(bucket.begin(), bucket.end(),
                      [key](pair<int, int> &elem) {
                        return elem.first == key;
                      });
    if (it != bucket.end()) {
      it->second = value;
    } else {
      bucket.push_back({key, value});
    }
  }

  int Get(int key) const {
    const auto &bucket = storage[Hash(key)];
    auto it = find_if(bucket.begin(), bucket.end(),
                      [key](const pair<int, int> &elem) {
                        return elem.first == key;
                      });
    return it != bucket.end() ? it->second : -1;
  }

  void Remove(int key) {
    auto &bucket = storage[Hash(key)];
    auto it = find_if(bucket.begin(), bucket.end(),
                      [key](pair<int, int> &elem) {
                        return elem.first == key;
                      });
    if (it != bucket.end()) bucket.erase(it);
  }

 private:
  static const int kStorageSize = 997;
  static const int kWeirdPrime = 1009;
  array<vector<pair<int, int>>, kStorageSize> storage;

  int Hash(uint32_t key) const {
    return key * kWeirdPrime % kStorageSize;
  }
};

class MyHashMap {
 public:
  MyHashMap() = default;

  void put(int key, int value) {
    Search(key, [=](auto &bucket, auto &it) {
             if (it != bucket.end()) {
               it->second = value;
             } else {
               bucket.push_back({key, value});
             }
           });
  }

  int get(int key) {
    int value = -1;
    Search(key, [&value](auto &bucket, auto &it) {
             if (it != bucket.end()) value = it->second;
           });
    return value;
  }

  void remove(int key) {
    Search(key, [](auto &bucket, auto &it) {
             if (it != bucket.end()) bucket.erase(it);
           });
  }

 private:
  static const int kStorageSize = 997;
  static const int kWeirdPrime = 1009;
  array<vector<pair<int, int>>, kStorageSize> storage;

  int Hash(uint32_t key) {
    return key * kWeirdPrime % kStorageSize;
  }

  template <typename F>
  void Search(int key, F &&callback) {
    auto &bucket = storage[Hash(key)];
    auto it = find_if(bucket.begin(), bucket.end(),
                      [key](pair<int, int> &elem) {
                        return elem.first == key;
                      });
    callback(bucket, it);
  }
};