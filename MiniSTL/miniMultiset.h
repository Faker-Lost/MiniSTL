#pragma once
#include "MiniRBTree.h" // ֮ǰʵ�ֵĺ����
#include <cstddef>
#include <stdexcept>

template <typename Key> class MultiSet {
    RedBlackTree<Key, size_t> rbTree;
    size_t sz;

public:
    MultiSet() : sz(0) {} // ���캯��
    ~MultiSet() {}        // ��������

    // ����Ԫ��
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

    // ɾ����Ϊkey��Ԫ��
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

    // ����������Ԫ�ص�����
    size_t size() const { return sz; }

    // �ж������Ƿ�Ϊ��
    bool empty() const { return sz == 0; }

    // ������ multiset �е��ڸ���ֵ��Ԫ�ص�����
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