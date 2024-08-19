#pragma once
#include "MiniRBTree.h" // 之前实现的红黑树
#include <cstddef>
#include <stdexcept>

template <typename Key> class MultiSet {
    RedBlackTree<Key, size_t> rbTree;
    size_t sz;

public:
    MultiSet() : sz(0) {} // 构造函数
    ~MultiSet() {}        // 析构函数

    // 插入元素
    void insert(const Key& key) {
        auto count = rbTree.at(key);
        if (count != nullptr) {
            (*count)++;
            sz++;

            return;
        }
        rbTree.insert(key, 1);
        sz++;
    }

    // 删除键为key的元素
    void erase(const Key& key) {
        auto count = rbTree.at(key);
        if (count == nullptr) {
            return;
        }
        (*count)--;
        sz--;
        if (*count == 0) {
            rbTree.remove(key);
        }
    }

    // 返回容器中元素的数量
    size_t size() const { return sz; }

    // 判断容器是否为空
    bool empty() const { return sz == 0; }

    // 返回在 multiset 中等于给定值的元素的数量
    size_t count(const Key& key) {
        auto num = rbTree.at(key);
        if (num != nullptr) {
            return *num;
        }

        return 0;
    }

    void clear() {
        sz = 0;
        rbTree.clear();
    }
};