#pragma once
#include<iostream>
#include"MiniRBTree.h"
#include<cstddef>
#include<stdexcept>

template <typename Key>
class MultiSet
{
private:
	RedBlackTree<Key, size_t> rbtree;
	size_t size;


};