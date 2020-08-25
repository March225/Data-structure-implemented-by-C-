#pragma once
#include "stdafx.h"

/**
 * @brief ����һ��ѭ��������
 */
template <typename ElemType>
class CircleQueue
{
public:
	CircleQueue();
	~CircleQueue();

	bool isEmpty(); // �ж϶����Ƿ�Ϊ��
	bool isFull(); // �ж϶����Ƿ�����
	int GetLength(); // ���ض��г���

	bool EnQueue(ElemType elem); // ���
	bool DeQueue(ElemType& elem); // ��ͷ����
	bool GetFront(ElemType& elem); // �õ���ͷԪ��
	void OddOrEven(ElemType elem); // ���룺����������ӣ�ż��������ͷ���ӡ�

	template <typename ElemType>
	friend ostream& operator << (ostream& os, CircleQueue<ElemType>*& cq); // ���� << ��������������Ԫ�ظ�������ͷԪ�أ�ȫ��Ԫ�ص���Ϣ

private:
	ElemType* elem_; // ����ѭ�����еĻ���ַ
	int front_; // ������ͷָ��
	int rear_; // ������βָ��
};

// ���캯������ʼ������
template <typename ElemType>
CircleQueue<ElemType>::CircleQueue() :front_(0), rear_(0)
{
	elem_ = new ElemType[kMaxSize];   // ���ٿռ�
	if (!elem_) {                     // �����ʱ���쳣
		exit(OVERFLOW);
	}
}

// �������������ٶ���
template <typename ElemType>
CircleQueue<ElemType>::~CircleQueue()
{
	delete[] elem_;
	elem_ = nullptr;
}

// �ж϶����Ƿ�Ϊ��
template <typename ElemType>
bool CircleQueue<ElemType>::isEmpty()
{
	return front_ == rear_;
}

// �ж϶����Ƿ�����
template <typename ElemType>
bool CircleQueue<ElemType>::isFull()
{
	return (rear_ + 1) % kMaxSize == front_;
}

// ���ض��г���
template <typename ElemType>
int CircleQueue<ElemType>::GetLength()
{
	return (rear_ - front_ + kMaxSize) % kMaxSize;
}

// ���
template <typename ElemType>
bool CircleQueue<ElemType>::EnQueue(ElemType elem)
{
	if (isFull()) return false;

	elem_[rear_] = elem;
	rear_ = (rear_ + 1) % kMaxSize;
	return true;
}

// ��ͷ����
template <typename ElemType>
bool CircleQueue<ElemType>::DeQueue(ElemType& elem)
{
	if (isEmpty()) return false;

	elem = elem_[front_];
	front_ = (front_ + 1) % kMaxSize;
	return true;
}

// �õ���ͷԪ��
template <typename ElemType>
bool CircleQueue<ElemType>::GetFront(ElemType& elem)
{
	if (isEmpty()) return false;
	elem = elem_[front_];
	return true;
}

// ���룺����������ӣ�ż��������ͷ���ӡ�
template <typename ElemType>
void CircleQueue<ElemType>::OddOrEven(ElemType elem)
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
ostream& operator << (ostream& os, CircleQueue<ElemType>*& cq) {
	if (cq->isEmpty()) {
		os << "����Ԫ�ظ�����" << 0 << "����ͷԪ�أ���"  << "��front = " << cq->front_ << ", rear = " << cq->rear_ << endl;
		cout << "����Ϊ�գ���ӡԪ��ʧ�ܣ�" << endl;
		return os;
	}

	// ���������Ԫ�ص����ز��� <<
	ElemType elem_front;
	cq->GetFront(elem_front);
	os << "����Ԫ�ظ�����" << cq->GetLength() << "����ͷԪ�أ�" << elem_front << "��front = " << cq->front_ << ", rear = " << cq->rear_ << endl;
	os << "����Ԫ�أ�" << endl;

	int col = 0;
	for (int i = cq->front_; i % kMaxSize != cq->rear_; i = (i + 1) % kMaxSize)
	{
		os << setw(3) << cq->elem_[i] << " ";
		if (++col % 10 == 0) os << endl;
	}
	os << endl;
	return os;
};