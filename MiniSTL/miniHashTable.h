#pragma once
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <sstream>
#include <string>

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class HashTable {

    class HashNode {
    public:
        Key key;
        Value value;

        // ��Key����ڵ㣬Valueʹ��Ĭ�Ϲ���
        explicit HashNode(const Key& key) : key(key), value() {}

        // ��Key��Value����ڵ�
        HashNode(const Key& key, const Value& value) : key(key), value(value) {}

        // �Ƚ�������أ�ֻ����key���бȽ�
        bool operator==(const HashNode& other) const { return key == other.key; }

        bool operator!=(const HashNode& other) const { return key != other.key; }

        bool operator<(const HashNode& other) const { return key < other.key; }

        bool operator>(const HashNode& other) const { return key > other.key; }

        bool operator==(const Key& key_) const { return key == key_; }

        void print() const {
            std::cout << key << " " << value << " ";
        }
    };

private:
    using Bucket = std::list<HashNode>; // ����Ͱ������Ϊ�洢��������
    std::vector<Bucket> buckets;        // �洢����Ͱ�Ķ�̬����
    Hash hashFunction;                  // ��ϣ��������
    size_t tableSize;                   // ��ϣ��Ĵ�С����Ͱ������
    size_t numElements;                 // ��ϣ����Ԫ�ص�����

    float maxLoadFactor = 0.75; // Ĭ�ϵ����������

    // ������Ĺ�ϣֵ��������ӳ�䵽Ͱ������
    size_t hash(const Key& key) const { return hashFunction(key) % tableSize; }

    // ��Ԫ������������������Ӷ��������ʱ������Ͱ�����������·������м�
    void rehash(size_t newSize) {
        std::vector<Bucket> newBuckets(newSize); // �����µ�Ͱ����

        for (Bucket& bucket : buckets) {      // ������Ͱ
            for (HashNode& hashNode : bucket) { // ����Ͱ�е�ÿ����
                size_t newIndex =
                    hashFunction(hashNode.key) % newSize; // Ϊ�������µ�����
                newBuckets[newIndex].push_back(hashNode); // ������ӵ���Ͱ��
            }
        }
        buckets = std::move(newBuckets); // ʹ���ƶ��������Ͱ����
        tableSize = newSize;             // ���¹�ϣ���С
    }

public:
    // ���캯����ʼ����ϣ��
    HashTable(size_t size = 10, const Hash& hashFunc = Hash())
        : buckets(size), hashFunction(hashFunc), tableSize(size), numElements(0) {
    }

    // ���������ϣ����
    void insert(const Key& key, const Value& value) {
        if ((numElements + 1) > maxLoadFactor * tableSize) { // ����Ƿ���Ҫ�ع�ϣ
            // ���� clear ���ٴβ���Ԫ��ʱ tableSize = 0 �����
            if (tableSize == 0) tableSize = 1;
            rehash(tableSize * 2); // �ع�ϣ��Ͱ��������
        }
        size_t index = hash(key);                     // �����������
        std::list<HashNode>& bucket = buckets[index]; // ��ȡ��Ӧ��Ͱ
        // ���������Ͱ�У�����ӵ�Ͱ��
        if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
            bucket.push_back(HashNode(key, value));
            ++numElements; // ����Ԫ������
        }
    }

    void insertKey(const Key& key) { insert(key, Value{}); }

    // �ӹ�ϣ�����Ƴ���
    void erase(const Key& key) {
        size_t index = hash(key);      // �����������
        auto& bucket = buckets[index]; // ��ȡ��Ӧ��Ͱ
        auto it = std::find(bucket.begin(), bucket.end(), key); // ���Ҽ�
        if (it != bucket.end()) {                               // ����ҵ���
            bucket.erase(it); // ��Ͱ���Ƴ���
            numElements--;    // ����Ԫ������
        }
    }

    // ���Ҽ��Ƿ�����ڹ�ϣ����
    Value* find(const Key& key) {
        size_t index = hash(key);      // �����������
        auto& bucket = buckets[index]; // ��ȡ��Ӧ��Ͱ
        // ���ؼ��Ƿ���Ͱ��
        auto ans = std::find(bucket.begin(), bucket.end(), key);
        if (ans != bucket.end()) {
            return &ans->value;
        };
        return nullptr;
    }

    // ��ȡ��ϣ����Ԫ�ص�����
    size_t size() const { return numElements; }

    // ��ӡ��ϣ���е�����Ԫ��
    void print() const {
        for (size_t i = 0; i < buckets.size(); ++i) {
            for (const HashNode& element : buckets[i]) {
                element.print();
            }
        }
        std::cout << std::endl;
    }
    void clear() {
        this->buckets.clear();
        this->numElements = 0;
        this->tableSize = 0;
    }
};