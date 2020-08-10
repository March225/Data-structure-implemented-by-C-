#pragma once
#include "stdafx.h"

/**
 * @brief ����һ����ʽ������
 */
template<typename ElemType>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();

	bool isEmpty(); // �ж϶����Ƿ�Ϊ��
	bool isFull(); // �ж϶����Ƿ�����
	int GetLength(); // ���ض��г���

	bool EnQueue(ElemType elem); // ���
	bool DeQueue(ElemType& elem); // ��ͷ����
	bool GetFront(ElemType& elem); // �õ���ͷԪ��
	void OddOrEven(ElemType elem); // ���룺����������ӣ�ż��������ͷ���ӡ�

	template <typename ElemType>
	friend ostream& operator << (ostream& os, LinkQueue<ElemType>*& lq); // ���� << ��������������Ԫ�ظ�������ͷԪ�أ�ȫ��Ԫ�ص���Ϣ


private:
	int length_; // �������г���
	QueueNode<ElemType>* front_; // ������ͷ���ָ��
	QueueNode<ElemType>* rear_; // ������β���ָ��
};

// ���캯������ʼ������
template <typename ElemType>
LinkQueue<ElemType>::LinkQueue() :length_(0), front_(nullptr), rear_(nullptr) {}

// �������������ٶ���
template <typename ElemType>
LinkQueue<ElemType>::~LinkQueue()
{
	while (front_)
	{
		rear_ = front_->next;
		delete front_;
		front_ = rear_;
	}
}

// �ж϶����Ƿ�Ϊ��
template <typename ElemType>
bool LinkQueue<ElemType>::isEmpty()
{
	return front_ == nullptr;
}

// �ж϶����Ƿ�����
template <typename ElemType>
bool LinkQueue<ElemType>::isFull()
{
	return length_ == kMaxSize;
}

// ���ض��г���
template <typename ElemType>
int LinkQueue<ElemType>::GetLength()
{
	return length_;
}

// ���
template <typename ElemType>
bool LinkQueue<ElemType>::EnQueue(ElemType elem)
{
	if (isFull()) return false;

	QueueNode<ElemType>* new_node = new QueueNode<ElemType>(elem);
	if (isEmpty())
		front_ = new_node;
	else
		rear_->next = new_node;
	rear_ = new_node;
	++length_;
	return true;
}

// ��ͷ����
template <typename ElemType>
bool LinkQueue<ElemType>::DeQueue(ElemType& elem)
{
	if (isEmpty()) return false;

	elem = front_->val;
	QueueNode<ElemType>* tmp = front_->next;
	delete front_;
	front_ = tmp;
	--length_;
	return true;
}

// �õ���ͷԪ��
template <typename ElemType>
bool LinkQueue<ElemType>::GetFront(ElemType& elem)
{
	if (isEmpty()) return false;

	elem = front_->val;
	return true;
}

// ���룺����������ӣ�ż��������ͷ���ӡ�
template <typename ElemType>
void LinkQueue<ElemType>::OddOrEven(ElemType elem)
{
	if (elem % 2 == 1) {
		if (isFull())
			cout << "�������������ʧ�ܣ�" << endl;
		else {
			cout << "����Ϊ��������ӣ�" << endl;
			EnQueue(elem);
		}
	}
	else {
		if (isEmpty())
			cout << "����Ϊ�գ�����ʧ�ܣ�" << endl;
		else {
			cout << "����Ϊż������ͷ���ӣ�" << endl;
			DeQueue(elem);
		}
	}
}

// ���� << ��������������Ԫ�ظ�������ͷԪ�أ�ȫ��Ԫ�ص���Ϣ
template <typename ElemType>
ostream& operator << (ostream& os, LinkQueue<ElemType>*& lq) {
	if (lq->isEmpty()) {
		os << "����Ϊ�գ���ӡԪ��ʧ�ܣ�" << endl;
		return os;
	}

	ElemType elem_front;
	lq->GetFront(elem_front);
	os << "����Ԫ�ظ�����" << lq->GetLength() << "����ͷԪ�أ�" << elem_front << endl;
	os << "����Ԫ�أ�" << endl;
	int col = 0;
	QueueNode<ElemType>* cur = lq->front_;
	while (cur)
	{
		os << setw(3) << cur->val << " ";
		if (++col % 10 == 0) os << endl;
		cur = cur->next;
	}
	os << endl;
	return os;
};