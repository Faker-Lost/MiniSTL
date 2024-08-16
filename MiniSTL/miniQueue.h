#pragma once
//队列queue的实现
//队列是STL中的容器适配器，提供队列FIFO的功能

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <stdexcept> // 用于异常处理
#include <sstream>
#include <string>
using namespace std;
template<typename T, typename Contanier = deque<T>>
class Queue
{
private:
	Contanier c;

public:
	//插入元素
	void push(const T& val)
	{
		c.push_back(val);
	}
	//移除队头元素
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
	//访问队头元素
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
	//访问队尾元素
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
	//判断为空
	bool empty()
	{
		return c.empty();
	}
	//返回size
	size_t size()
	{
		return c.size();
	}
};
