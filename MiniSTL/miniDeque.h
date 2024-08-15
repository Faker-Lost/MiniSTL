#pragma once
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//ģ����
template<class T>
class Deque
{
private:
	T* elements; 
	size_t capacity; //������
	size_t frontIndex;//ǰ������
	size_t backIndex;//�������
	size_t size;
public:
	//���캯��
	Deque( ):elements(nullptr),capacity(0),frontIndex(0), backIndex(0), size(0){}
	//��������
	~Deque()
	{
		clear();
		delete[] elements;
	}
	//ǰ�˲���Ԫ��
	void push_front(const T& value)
	{
		if (size == capacity)
		{
			resize();
		}
		//��ֹ��������Ϊ����ָ��β��
		frontIndex = (frontIndex - 1 + capacity) % capacity;
		elements[frontIndex] = value;

		size++;
	}
	//��˲���Ԫ��
	void push_back(const T& value)
	{
		if (size == capacity)
		{
			resize();
		}
		elements[backIndex] = value;
		backIndex = (backIndex + 1) % capacity;
		size++;
	}
	//ǰ���Ƴ�Ԫ��
	void pop_front()
	{
		if (size == 0)
		{
			throw out_of_range("Deque is empty");
		}
		frontIndex = (frontIndex + 1) % capacity;
		size--;
	}
	//�Ӻ���Ƴ�Ԫ��
	void pop_back()
	{
		if (size == 0)
		{
			throw out_of_range("Deque is empty");
		}
		backIndex = (backIndex - 1 + capacity) % capacity;
		size--;

	}
	//��д�������Ԫ��
	T& operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw out_of_range("Index out of range");
		}
		return elements[(frontIndex + index) % capacity];
	}
	//��ȡԪ������
	size_t getSize() const {
		cout << size << endl;
		return size;
	}

	void clear()
	{
		while (size > 0)
		{
			pop_front();
		}
	}

	//��ӡdequeԪ��
	void printElements() const {
		size_t index = frontIndex;
		for (size_t i = 0; i < size; i++)
		{
			cout << elements[index] << " ";
			index = (index + 1) % capacity;
		}
		cout << endl;
	}
private:
	void resize()
	{
		//�����µ�����
		size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;

		//�����µ� ������
		T* newElements = new T[newCapacity];
		//��ֵԪ��
		size_t index = frontIndex;
		for (size_t i = 0; i < size; i++)
		{
			newElements[i] = elements[index];
			index = (index + 1) % capacity;
		}
		//ɾ����������ڴ�
		delete[] elements;

		//���³�Ա����
		elements = newElements;
		capacity = newCapacity;
		frontIndex = 0;
		backIndex = size;
	}

};