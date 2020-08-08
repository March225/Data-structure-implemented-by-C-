#pragma once
#include "stdafx.h"

/**
 * @brief ����һ��˳��ջ��
 */
template <typename ElemType>
class SqStack
{
public:
	SqStack();
	~SqStack();

	bool isEmpty(); // �ж�˳��ջ�Ƿ�Ϊ��
	bool isFull();	// �ж�˳��ջ�Ƿ�����
	bool push(ElemType val); // ��˳��ջѹ��һ��Ԫ��
	bool pop(); // ɾ��˳��ջ���˵�Ԫ��
	ElemType top(); // ����˳��ջ���˵�Ԫ�ص���ɾ��

private:
	ElemType* elem_; // ����˳��ջ�Ļ���ַ
	int top_; // ����˳��ջ��ջ������
};

// ���캯������ʼ������ַ��ջ������
template <typename ElemType>
SqStack<ElemType>::SqStack():top_(-1)
{
	elem_ = new ElemType[kMaxSize];   // ���ٿռ�
	if (!elem_) {                     // �����ʱ���쳣
		exit(OVERFLOW);
	}
}

// ���캯��������˳��ջ
template <typename ElemType>
SqStack<ElemType>::~SqStack()
{
	delete[] elem_;
}

// �ж�˳��ջ�Ƿ�Ϊ��
template <typename ElemType>
bool SqStack<ElemType>::isEmpty()
{
	return top_ == -1;
}

// �ж�˳��ջ�Ƿ�����
template <typename ElemType>
bool SqStack<ElemType>::isFull()
{
	return top_ == kMaxSize - 1;
}

// ��˳��ջѹ��һ��Ԫ��
template <typename ElemType>
bool SqStack<ElemType>::push(ElemType val)
{
	if (isFull()) {
		return false;
	}
	else {
		elem_[++top_] = val;
		return true;
	}
}

// ɾ��˳��ջ���˵�Ԫ��
template <typename ElemType>
bool SqStack<ElemType>::pop()
{
	if (isEmpty()) {
		return false;
	}
	else {
		top_--;
		return true;
	}
}

// ����˳��ջ���˵�Ԫ�ص���ɾ��
template <typename ElemType>
ElemType SqStack<ElemType>::top()
{
	if (isEmpty()) {
		return NULL;
	}
	else
		return elem_[top_];
}

