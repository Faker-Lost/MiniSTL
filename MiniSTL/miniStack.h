#pragma once
//默认情况下，stack使用deque作为底层容器
//不同底层容器，性能不同

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept> // 用于异常处理
#include <sstream>
#include <string>
using namespace std;

template<typename T, typename Container = deque<T>>
class Stack {
private:
	Container c;// 使用底层容器存储栈的元素
public:

	//插入元素
	void push(const T& val)
	{
		c.push_back(val);
	}
	//弹出栈顶元素
	void pop()
	{
		if (!c.empty())
		{
			c.pop_back();
		}
	}
	//返回栈顶元素
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
	//检查是否为空
	bool empty()
	{
		return c.empty();
	}
	//返回栈的大小
	size_t size()
	{
		return c.size();
	}
};