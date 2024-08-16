#define _CRT_SECURE_NO_WARNINGS
#include"test.h"
//�����ṹ
#include"miniVector.h"
#include"miniList.h"
#include"miniDeque.h"
#include"miniStack.h"
#include"miniQueue.h"
#include"miniPriority_Queue.h"
//��ϣ�ṹ�ͺ�����ṹ
#include"miniHashTable.h"
#include"MiniRBTree.h"
//���ں��������ϣ��
#include"miniSet.h"
#include"unordered_set.h"


using namespace std;
//����vector ͨ��
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
// List ���� ͨ��
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
//Deque���� ͨ��
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
	//���Ԫ��
	deq.clear();
	deq.getSize();
}
//Stack���� ͨ��
void testStack()
{
	//����һ��ջ
	Stack<int> mystack;
	//��ջ
	mystack.push(1);
	mystack.push(2);
	mystack.push(3);
	mystack.push(4);
	mystack.push(5);

	cout << "size:" << mystack.size() << endl;

	//ѭ��ȡ��ջ��Ԫ��
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
//Queue���� pass  
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
				// �����κδ���
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
//PriorityQueue ���� pass
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

	// ʹ�� vector ��Ϊ�ײ�������ʾ��
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


//HashTable����
void testHashTable()
{
	
}

//���������
//void testBRTree()
//{
//    // ���������ʵ��
//    RedBlackTree<int, int> rbTree;
//
//    int N;
//    std::cin >> N;
//    getchar();
//
//    std::string line;
//    for (int i = 0; i < N; i++)
//    {
//        std::getline(std::cin, line);
//        std::istringstream iss(line);
//        std::string command;
//        iss >> command;
//
//        int key;
//        int value;
//
//        if (command == "insert")
//        {
//            iss >> key >> value;
//            rbTree.insert(key, value);
//        }
//
//        if (command == "size")
//        {
//            std::cout << rbTree.getSize() << std::endl;
//        }
//
//        if (command == "at")
//        {
//            iss >> key;
//            int* res = rbTree.at(key);
//            if (res == nullptr)
//            {
//                std::cout << "not exist" << std::endl;
//            }
//            else
//            {
//                std::cout << *res << std::endl;
//            }
//        }
//
//        if (command == "remove")
//        {
//            iss >> key;
//            rbTree.remove(key);
//        }
//
//        if (command == "print")
//        {
//            if (rbTree.empty())
//            {
//                std::cout << "empty" << std::endl;
//            }
//            else
//            {
//                rbTree.print();
//            }
//        }
//    }
//}

//unordered_set����
//void testUnorder_set()
//{
//    unordered_set<int> un_set;
//
//    un_set.insert(1);
//    un_set.insert(2);
//}