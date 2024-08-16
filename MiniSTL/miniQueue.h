#pragma once
//����queue��ʵ��
//������STL�е��������������ṩ����FIFO�Ĺ���

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <stdexcept> // �����쳣����
#include <sstream>
#include <string>
using namespace std;
template<typename T, typename Contanier = deque<T>>
class Queue
{
private:
	Contanier c;

public:
	//����Ԫ��
	void push(const T& val)
	{
		c.push_back(val);
	}
	//�Ƴ���ͷԪ��
	void pop()
	{
		if (!c.empty())
		{
			c.pop_front();
		}
		else
		{
			throw ::runtime_error("Queue is empty");
		}
	}
	//���ʶ�ͷԪ��
	T& front()
	{
		if (!c.empty())
		{
			return c.front();
		}
		else
		{
			throw::runtime_error("Queue is empty");
		}
	}
	//���ʶ�βԪ��
	T& back()
	{
		if (!c.empty())
		{
			return c.back();
		}
		else
		{
			throw::runtime_error("Queue is empty");
		}
	}
	//�ж�Ϊ��
	bool empty()
	{
		return c.empty();
	}
	//����size
	size_t size()
	{
		return c.size();
	}
};
