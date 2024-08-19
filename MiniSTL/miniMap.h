#pragma once
#include "MiniRBTree.h" // 之前实现的红黑树
#include <iostream>
#include <utility> // For std::pair

// 假设RedBlackTree已经定义，其中Key为map的key类型，Value为map的value类型

template <typename Key, typename Value> class Map {
public:
    Map() : rbTree() {}

    void insert(const Key& key, const Value& value) { rbTree.insert(key, value); }

    void erase(const Key& key) { rbTree.remove(key); }

    size_t size() { return rbTree.getSize(); }

    bool empty() const { return rbTree.empty(); }

    bool contains(const Key& key) { return rbTree.at(key) != nullptr; }

    Value& at(const Key& key) {
        Value* foundVal = rbTree.at(key);
        if (foundVal) {
            return *foundVal;
        }
        else {
            throw std::out_of_range("Key not found");
        }
    }

    Value& operator[](const Key& key) {
        Value* foundVal = rbTree.at(key);
        if (foundVal) {
            // 如果键存在，返回关联的值
            return *foundVal; // 或者，返回与找到的键关联的值
        }
        else {
            // 如果键不存在，插入新键值对，并返回新插入的值的引用
            Value defaultValue;
            rbTree.insert(key, defaultValue);
            return *rbTree.at(key);
        }
    }

private:
    RedBlackTree<Key, Value> rbTree;
};
