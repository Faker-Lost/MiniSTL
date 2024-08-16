#pragma once
//Ĭ������£�stackʹ��deque��Ϊ�ײ�����
//��ͬ�ײ����������ܲ�ͬ

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept> // �����쳣����
#include <sstream>
#include <string>
using namespace std;

template<typename T, typename Container = deque<T>>
class Stack {
private:
	Container c;// ʹ�õײ������洢ջ��Ԫ��
public:

	//����Ԫ��
	void push(const T& val)
	{
		c.push_back(val);
	}
	//����ջ��Ԫ��
	void pop()
	{
		if (!c.empty())
		{
			c.pop_back();
		}
	}
	//����ջ��Ԫ��
	T& top()
	{
		if (!c.empty())
		{
			return c.back();
		}
		else
		{
			throw::runtime_error("Stack is empty");
		}
	}
	//����Ƿ�Ϊ��
	bool empty()
	{
		return c.empty();
	}
	//����ջ�Ĵ�С
	size_t size()
	{
		return c.size();
	}
};