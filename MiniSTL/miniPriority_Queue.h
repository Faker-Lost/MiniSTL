#pragma once
//���ȼ����� �ײ�ʵ���Ƕ�
//c++ֱ��ʹ�� make_heap,push_heap,pop_heap ʵ��
//�Լ�ʵ�ֶ�
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T, typename Container = vector<T>>
class PriorityQueue 
{
private:
	Container c;

	//��������,���ϵ���Ԫ��ά��
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
	//���µ�����
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
	//Ĭ�Ϲ���
	PriorityQueue() {
	}
	//���캯��
	PriorityQueue(const Container& data): c(data){
		int size = c.size();
		for (int i = (size / 2) - 1; i >= 0; i--)
		{
			heapifyDown();
		}
	}

	// ��Ԫ����ӵ����ȶ���
	void push(const T& val)
	{
		c.push_back(val);
		heapifyUp();
	}
	//�������ȶ������Ԫ��
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
	//������ȼ������Ƿ�Ϊ��
	bool empty()
	{
		return c.empty();
	}

	//�������ȼ�����size
	size_t size()
	{
		return c.size();
	}
	
};