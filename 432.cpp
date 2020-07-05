//
// Created by bdwms on 2020/7/5.
//
#include <string>
#include <unordered_set>
#include <list>
#include <unordered_map>

using namespace std;

class AllOne {
 public:
  /** Initialize your data structure here. */
  AllOne() {

  }

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(string key) {
    if (!m.count(key)) {  // 如果不存在这个key，分为两种情况
      if (l.empty() || l.back().val != 1) {  // 一种是l为空，或者不存在val为1的这种情况，那么就要新建val=1的Bucket了
        auto newBucket = l.insert(l.end(), {1, {key}});
        m[key] = newBucket;
      } else {  // 存在val=1的Bucket，那么直接将key加入
        l.back().keys.insert(key);
        m[key] = --l.end();
      }
    } else {
      auto curBucket = m[key], lastBucket = (--m[key]);
      if (lastBucket == l.end() || lastBucket->val != curBucket->val + 1) { // 如果不存在 key + 1的Bucket，需要新建它
        auto newBucket = l.insert(curBucket, {curBucket->val + 1, {key}});
        m[key] = newBucket;
      } else {
        lastBucket->keys.insert(key);
        m[key] = lastBucket;
      }
      curBucket->keys.erase(key);  // 从原来的Bucket中删除key
      if (curBucket->keys.empty()) {  // 如果Bucket为空了，从list中删除
        l.erase(curBucket);
      }
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(string key) {
    if (!m.count(key)) return;
    auto curBucket = m[key];
    if (curBucket->val == 1) {  // val=1的时候需要删除key,key空了就需要删除Bucket了
      curBucket->keys.erase(key);
      if (curBucket->keys.empty()) l.erase(curBucket);
      m.erase(key);
      return;
    }
    auto nextBucket = ++m[key];
    if (nextBucket == l.end() || nextBucket->val != curBucket->val - 1) {
      auto newBucket = l.insert(nextBucket, {curBucket->val - 1, {key}});
      m[key] = newBucket;
    } else {
      nextBucket->keys.insert(key);
      m[key] = nextBucket;
    }
    curBucket->keys.erase(key);
    if (curBucket->keys.empty()) l.erase(curBucket);
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    return l.empty() ? "" : *(l.begin()->keys.begin());
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    return l.empty() ? "" : *(l.rbegin()->keys.begin());
  }

 private:
  struct Bucket {
    int val;
    unordered_set<string> keys;
  };
  list<Bucket> l;
  unordered_map<string, list<Bucket>::iterator> m;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
