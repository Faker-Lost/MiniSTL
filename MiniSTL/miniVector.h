#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include <sstream>
#include <stdexcept>
using namespace std;
template<class T>
class Vector
{
private:
	T* elements;
	size_t capacity;
	size_t size;
public:
	Vector() :elements(nullptr), capacity(0), size(0) {}

	~Vector()
	{
		delete[] elements;
	}
	//�������캯��
	Vector(const Vector& other) :capacity(other.capacity), size(other.size)
	{
		elements = new T[capacity];
		copy(other.elements, other.elements + size, elements);
	}
	//������ֵ������
	Vector& operator=(const Vector& other)
	{
		if (this != &other) {
			delete[] elements;
			capacity = other.capacity;
			size = other.size;
			elements = new T[capacity];
			copy(other.elements, other.elements + size, elements);
		}
		return *this;
	}

	//push_back����
	void push_back(const T& val)
	{
		if (size == capacity)
		{
			reserve(capacity == 0 ? 1 : 2 * capacity);
		}
		elements[size++] = val;
	}
	size_t getsize() const {
		return size;
	}
	size_t getcapacity() const {
		return capacity;
	}
	//�����±��ʶ��
	T& operator[](size_t index)
	{
		if (index >= size)
		{
			throw out_of_range("Index out of range");
		}
		return elements[index];
	}

	const T& operator[](size_t index) const
	{
		if (index >= size)
		{
			throw out_of_range("Index out of range");
		}
		return elements[index];
	}
	//insert ����
	void insert(size_t index, const T& val)
	{
		if (index >= size)
		{
			throw out_of_range("Index out of range");
		}
		if (size == capacity)
		{
			reserve(capacity == 0 ? 1 : capacity * 2);
		}
		for (size_t i = size; i > index; i--)
		{
			elements[i] = elements[i - 1];
		}
		elements[index] = val;
		size++;
	}
	//pop_back����
	void pop_back()
	{
		if (size > 0)
		{
			size--;
		}
	}
	//clear����
	void clear()
	{
		size = 0;
	}
	//������
	T* begin()
	{
		return elements;
	}
	const T* begin() const
	{
		return elements;
	}
	T* end()
	{
		return elements + size;
	}
	const T* end() const
	{
		return elements + size;
	}
	//��ӡԪ��
	void printElements() const
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << elements[i] << " ";
		}
		cout << endl;
	}
	//�ж��Ƿ�Ϊ��
	bool empty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}
	void reserve(size_t newCapacity)
	{
		if (newCapacity > capacity)
		{
			T* newElements = new T[newCapacity];
			copy(elements, elements + size, newElements);
			delete[] elements;
			elements = newElements;
			capacity = newCapacity;
		}
	}
};