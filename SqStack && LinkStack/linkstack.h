#pragma once
#include "stdafx.h"

/**
 * @brief ����һ����ջ��
 */
template <typename ElemType>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();

	bool isEmpty(); // �ж���ջ�Ƿ�Ϊ��
	bool push(ElemType val); // ����ջѹ��һ��Ԫ��
	bool pop(); // ɾ����ջ���˵�Ԫ��
	ElemType top(); // ������ջ���˵�Ԫ�ص���ɾ��

private:
	StackNode<ElemType>* top_; // ������ջ��ͷ���
	int length_; // ������ջ�ĳ���
};

// ���캯������ʼ����ջ��ͷ���
template <typename ElemType>
LinkStack<ElemType>::LinkStack()
{
	top_ = new StackNode<ElemType>();
	if (!top_)
		cerr << "Space allocating falied! Error in LinkStack<ElemType>::LinkStack()!" << endl;
	length_ = 0;
}

// ����������������ջ
template <typename ElemType>
LinkStack<ElemType>::~LinkStack()
{
	while (top_)
	{
		StackNode<ElemType>* cur = top_;
		top_ = top_->next;
		delete cur;
	}
}

// �ж���ջ�Ƿ�Ϊ��
template <typename ElemType>
bool LinkStack<ElemType>::isEmpty()
{
	return top_->next == nullptr;
}

// ����ջѹ��һ��Ԫ��
template <typename ElemType>
bool LinkStack<ElemType>::push(ElemType val)
{
	StackNode<ElemType>* new_node = new StackNode<ElemType>(val);
	if (!new_node) {
		cerr << "Space allocating falied!" << endl;
		return false;
	}
	else {
		new_node->next = top_;
		top_ = new_node;
		++length_;
	}
	return true;
}

// ɾ����ջ���˵�Ԫ��
template <typename ElemType>
bool LinkStack<ElemType>::pop()
{
	if (isEmpty())
		return false; 
	else {
		StackNode<ElemType>* tmp = top_;
		top_ = top_->next;
		delete tmp;
		--length_;
	}
	return true;
}

// ������ջ���˵�Ԫ�ص���ɾ��
template <typename ElemType>
ElemType LinkStack<ElemType>::top()
{
	if (isEmpty()) {
		return NULL;
	}
	else
		return top_->val;
}
