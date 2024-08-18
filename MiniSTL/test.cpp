#define _CRT_SECURE_NO_WARNINGS
#include"test.h"
//基础结构
#include"miniVector.h"
#include"miniList.h"
#include"miniDeque.h"
#include"miniStack.h"
#include"miniQueue.h"
#include"miniPriority_Queue.h"
//哈希结构和红黑树结构
#include"miniHashTable.h"
#include"MiniRBTree.h"
//基于红黑树、哈希表
#include"miniSet.h"
#include"unordered_set.h"


using namespace std;
//测试vector 通过
void testVector()
{
	Vector<int> myVec;

	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);
	myVec.push_back(4);

	size_t size = myVec.getsize();
	cout << "size: " << size << endl;

	bool result = myVec.empty();
	cout << "empty result:" << result;

	size_t capacity = myVec.getcapacity();
	cout << "capacity:" << capacity << endl;

	for (auto it = myVec.begin(); it != myVec.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;

	myVec.printElements();
}
// List 测试 通过
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
//Deque测试 通过
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
//Stack测试 通过
void testStack()
{
	//定义一个栈
	Stack<int> mystack;
	//入栈
	mystack.push(1);
	mystack.push(2);
	mystack.push(3);
	mystack.push(4);
	mystack.push(5);

	cout << "size:" << mystack.size() << endl;

	//循环取出栈顶元素
	vector<int> result;
	while(!mystack.empty())
	{
		result.push_back(mystack.top());
		mystack.pop();
	}
	
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}
//Queue测试 pass  
void testQueue()
{
	Queue<int> myQueue;

	int N;
	cin >> N;
	getchar();
	string line;

	for (int i = 0; i < N; i++) {
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string command;
		iss >> command;

		int element;

		if (command == "push") {
			iss >> element;
			myQueue.push(element);
		}

		if (command == "pop") {
			try {
				myQueue.pop();
			}
			catch (const std::runtime_error& e) {
				// 不做任何处理
				continue;
			}
		}

		if (command == "front") {
			try {
				std::cout << myQueue.front() << std::endl;
			}
			catch (const std::runtime_error& e) {
				std::cout << "null" << std::endl;
			}
		}

		if (command == "back") {
			try {
				std::cout << myQueue.back() << std::endl;
			}
			catch (const std::runtime_error& e) {
				std::cout << "null" << std::endl;
			}
		}

		if (command == "size") {
			std::cout << myQueue.size() << std::endl;
		}

		if (command == "empty") {
			std::cout << (myQueue.empty() ? "true" : "false") << std::endl;
		}
	}
	
}
//PriorityQueue 测试 pass
void testPriotyQueue()
{
	PriorityQueue<int,vector<int>> prque;

	/*prque.push(3);
	prque.push(1);
	prque.push(4);
	prque.push(1);*/

	//cout << "Top elements of prque:" << prque.top() << endl;
	//prque.pop();
	//cout << "priority queue prque size after pop:" << prque.size() << endl;

	// 使用 vector 作为底层容器的示例
	vector<int> vec = { 9, 5, 7, 2, 6 };
	PriorityQueue<int, vector<int>> pq2(vec);

	cout << "Top element of pq2: " << pq2.top() << endl;

	pq2.pop();
	cout << "Priority queue pq2 size after pop: " << pq2.size() << endl;
	cout << "Top element of pq2: " << pq2.top() << endl;
	pq2.pop();
	cout << "Top element of pq2: " << pq2.top() << endl;
	pq2.pop();
	cout << "Top element of pq2: " << pq2.top() << endl;
	pq2.pop();
	cout << "Top element of pq2: " << pq2.top() << endl;

}
//HashTable测试 pass
void testHashTable()
{
	HashTable<int, int> hashTable;
	hashTable.insert(1, 10);
	hashTable.insert(2, 20);
	hashTable.insert(3, 30);
	hashTable.insert(4, 40);
	cout << hashTable.size() << endl;
	hashTable.erase(2);
	hashTable.print();
}
////RBTree测试  pass
void testRBTree()
{
	RedBlackTree<int, int> rbTree;

	rbTree.insert(1, 10);
	rbTree.insert(2, 20);
	rbTree.insert(3, 30);
	rbTree.insert(4, 40);
	rbTree.insert(5, 50);
	cout << rbTree.getSize() << endl;
	cout << *rbTree.at(2) << endl;
	rbTree.remove(1);
	rbTree.print();
}
//Set测试  pass 
void testSet()
{
	Set<int> mySet;
	mySet.insert(10);
	mySet.insert(20);
	mySet.insert(30);
	mySet.insert(40);
	mySet.insert(50);
	cout << mySet.size() << endl;
	mySet.erase(10);
	bool result = mySet.contains(30);
	cout << result << endl;
}
//unordered_set 测试 pass
void testUnordered_set()
{
	unordered_set<int> myset;
	myset.insert(1);
	myset.insert(2);
	myset.insert(3);
	myset.insert(4);
	myset.insert(5);

	cout << myset.size() << endl;
	myset.erase(1);

	int result = myset.find(2);
	cout << result << endl;
}