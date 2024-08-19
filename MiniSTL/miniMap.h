#pragma once
#include "MiniRBTree.h" // ֮ǰʵ�ֵĺ����
#include <iostream>
#include <utility> // For std::pair

// ����RedBlackTree�Ѿ����壬����KeyΪmap��key���ͣ�ValueΪmap��value����

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
            // ��������ڣ����ع�����ֵ
            return *foundVal; // ���ߣ��������ҵ��ļ�������ֵ
        }
        else {
            // ����������ڣ������¼�ֵ�ԣ��������²����ֵ������
            Value defaultValue;
            rbTree.insert(key, defaultValue);
            return *rbTree.at(key);
        }
    }

private:
    RedBlackTree<Key, Value> rbTree;
};
