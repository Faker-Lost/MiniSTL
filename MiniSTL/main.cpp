#define _CRT_SECURE_NO_WARNINGS
#include"miniList.h"
#include"miniDeque.h"
#include"miniHashTable.h"

void testList()
{
	List<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);

	/*list<int>::const_iterator it = ls.begin();
	while (it != ls.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;*/
	List<int>::iterator it = ls.begin();
	while (it != ls.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}

void testDeque()
{
	Deque<int> deq;
	deq.push_front(1);
	deq.push_front(2);
	deq.push_front(3);
	deq.getSize();
	deq.push_back(4);
	deq.push_back(5);
	deq.printElements();
	deq.pop_front();
	deq.pop_back();
	deq.printElements();
	//清空元素
	deq.clear();
	deq.getSize();

}
void testHashTable()
{
    // 创建一个哈希表实例
    HashTable<int, int> hashTable;

    int N;
    std::cin >> N;
    getchar();

    std::string line;
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int key;
        int value;

        if (command == "insert") {
            iss >> key >> value;
            hashTable.insert(key, value);
        }

        if (command == "erase") {
            if (hashTable.size() == 0) {
                continue;
            }
            iss >> key;
            hashTable.erase(key);
        }

        if (command == "find") {
            if (hashTable.size() == 0) {
                std::cout << "not exist" << std::endl;
                continue;
            }
            iss >> key;
            int* res = hashTable.find(key);
            if (res != nullptr) {
                std::cout << *res << std::endl;
            }
            else {
                std::cout << "not exist" << std::endl;
            }
        }

        if (command == "print") {
            if (hashTable.size() == 0) {
                std::cout << "empty" << std::endl;
            }
            else {
                hashTable.print();
            }
        }

        if (command == "size") {
            std::cout << hashTable.size() << std::endl;
        }

        if (command == "clear") {
            hashTable.clear();
        }
    }
}
int main()
{
	//testList();
	//testDeque();
    testHashTable();
	return 0;
}
