#pragma once
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//模版类
template<class T>
class Deque
{
private:
	T* elements; 
	size_t capacity; //总容量
	size_t frontIndex;//前端索引
	size_t backIndex;//后端索引
	size_t size;
public:
	//构造函数
	Deque( ):elements(nullptr),capacity(0),frontIndex(0), backIndex(0), size(0){}
	//析构函数
	~Deque()
	{
		clear();
		delete[] elements;
	}
	//前端插入元素
	void push_front(const T& value)
	{
		if (size == capacity)
		{
			resize();
		}
		//防止数组索引为负，指向尾端
		frontIndex = (frontIndex - 1 + capacity) % capacity;
		elements[frontIndex] = value;

		size++;
	}
	//后端插入元素
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
	//前端移除元素
	void pop_front()
	{
		if (size == 0)
		{
			throw out_of_range("Deque is empty");
		}
		frontIndex = (frontIndex + 1) % capacity;
		size--;
	}
	//从后端移除元素
	void pop_back()
	{
		if (size == 0)
		{
			throw out_of_range("Deque is empty");
		}
		backIndex = (backIndex - 1 + capacity) % capacity;
		size--;

	}
	//重写随机访问元素
	T& operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw out_of_range("Index out of range");
		}
		return elements[(frontIndex + index) % capacity];
	}
	//获取元素数量
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

	//打印deque元素
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
		//计算新的容量
		size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;

		//创建新的 对数组
		T* newElements = new T[newCapacity];
		//赋值元素
		size_t index = frontIndex;
		for (size_t i = 0; i < size; i++)
		{
			newElements[i] = elements[index];
			index = (index + 1) % capacity;
		}
		//删除旧数组的内存
		delete[] elements;

		//更新成员变量
		elements = newElements;
		capacity = newCapacity;
		frontIndex = 0;
		backIndex = size;
	}

};