#pragma once
//优先级队列 底层实现是堆
//c++直接使用 make_heap,push_heap,pop_heap 实现
//自己实现堆
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T, typename Container = vector<T>>
class PriorityQueue 
{
private:
	Container c;

	//辅助函数,向上调整元素维护
	void heapifyUp()
	{
		int index = c.size() - 1;
		while (index > 0)
		{
			int parentIndex = (index - 1) / 2;
			if (c[index] > c[parentIndex])
			{
				swap(c[index], c[parentIndex]);
				index = parentIndex;
			}
			else
			{
				break;
			}
		}
	}
	//向下调整堆
	void heapifyDown()
	{
		int index = 0;
		int size = c.size();
		while (true)
		{
			int leftChild = 2 * index + 1;
			int rightChild = 2 * index + 2;
			int largest = index;

			if (leftChild < size && c[leftChild] > c[largest]) {
				largest = leftChild;
			}

			if (rightChild < size && c[rightChild] > c[largest]) {
				largest = rightChild;
			}

			if (largest != index) {
				swap(c[index], c[largest]);
				index = largest;
			}
			else
			{
				break;
			}
		}
	}

public:
	//默认构造
	PriorityQueue() {
	}
	//构造函数
	PriorityQueue(const Container& data): c(data){
		int size = c.size();
		for (int i = (size / 2) - 1; i >= 0; i--)
		{
			heapifyDown();
		}
	}

	// 将元素添加到优先队列
	void push(const T& val)
	{
		c.push_back(val);
		heapifyUp();
	}
	//弹出优先队列最大元素
	void pop() {
		if (!c.empty()) 
		{
			swap(c[0], c[c.size() - 1]);
			c.pop_back();
			heapifyDown();
		}
		else {
			throw runtime_error("Priority queue is empty.");
		}
	}
	//
	T& top()
	{
		if (!c.empty())
		{
			return c[0];
		}
		else
		{
			throw::runtime_error("Priority queue is empty");
		}
	}
	//检查优先级队列是否为空
	bool empty()
	{
		return c.empty();
	}

	//返回优先级队列size
	size_t size()
	{
		return c.size();
	}
	
};