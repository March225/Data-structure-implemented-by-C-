#include "stdafx.h"
#include "linklist.h"

// ���캯������ʼ��������
LinkList::LinkList() :head_(nullptr), length_(0)
{
	cout << this << "�������ѱ���ʼ����" << endl;
}

// �������������ٵ�����
LinkList::~LinkList()
{
	while (head_)
	{
		ListNode* cur = head_;
		head_ = head_->next;
		delete cur;
	}
	cout << this << "�������ѱ����٣�" << endl;
}

// ���ص�����ĳ���
int LinkList::GetLength()
{
	return length_;
}

// ����λ�÷��ص������Ԫ��
bool LinkList::GetElemByPosition(int pos, ElemType& val)
{
	if (head_ == nullptr) {
		cout << "������Ϊ�գ���ȡԪ��ʧ�ܣ�" << endl;
		return false;
	}
	else if (pos <= 0 || pos > length_) {
		cout << "λ�� " << setw(2) << pos << " ����" << "��ȡԪ��ʧ��!" << endl;
		return false;
	}
	else {
		ListNode* cur = head_;
		while (cur)
		{
			if (--pos == 0) {
				val = cur->val;
				return true;
			}
			cur = cur->next;
		}
		cout << "δ֪ԭ�򣬻�ȡԪ��ʧ�ܣ�" << endl;
		return false;
	}
}

// β�巨����������
bool LinkList::CreateLinkListByInsertAtEnd(int len)
{
	ListNode* dummy_node = new ListNode(0), * cur = dummy_node;
	for (int i = 0; i < len; ++i)
	{
		ElemType num;
		cin >> num;
		ListNode* new_node = new ListNode(num);
		cur->next = new_node;
		cur = cur->next;
		++length_;
	}
	head_ = dummy_node->next;
	return true;
}

// ͷ�巨����������
bool LinkList::CreateLinkListByInsertAtBeg(int len)
{
	ListNode* cur = nullptr;
	for (int i = 0; i < len; ++i)
	{
		ElemType num;
		cin >> num;
		ListNode* new_node = new ListNode(num);
		new_node->next = cur;
		cur = new_node;
		++length_;
	}
	head_ = cur;
	return true;
}

// �ڵ�pos�����ǰ����ֵΪval�Ľ��
bool LinkList::InsertElemBeforePosition(int pos, ElemType val)
{
	if (head_ == nullptr) {
		cout << "������Ϊ�գ�����Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	else if (pos <= 0 || pos > length_) {
		cout << "λ�� " << setw(2) << pos << " ����" << "����Ԫ��ʧ��!" << endl;
		return false;
	}
	else {
		ListNode* dummy_node = new ListNode(0), * cur = dummy_node;
		dummy_node->next = head_;
		while (cur->next) {
			if (--pos == 0) {
				ListNode* tmp = cur->next;
				cur->next = new ListNode(val);
				cur->next->next = tmp;

				head_ = dummy_node->next;
				++length_;
				return true;
			}
			cur = cur->next;
		}
		cout << "δ֪ԭ�򣬲���Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
}

// ���ص�������ֵΪval��Ԫ��λ��
bool LinkList::FindElemByValue(int& pos, ElemType val)
{
	if (head_ == nullptr) {
		cout << "������Ϊ�գ�����Ԫ��ʧ�ܣ�" << endl;
		return false;
	}

	ListNode* cur = head_;
	int cnt = 1;
	while (cur) {
		if (cur->val == val) {
			pos = cnt;
			return true;
		}
		++cnt;
		cur = cur->next;
	}
	cout << "û�в��ҵ�ֵΪ " << val << " ��Ԫ�أ�" << endl;
	return false;
}

// ����λ��ɾ���������Ԫ��
bool LinkList::DeleteElemByPosition(int pos)
{
	if (head_ == nullptr) {
		cout << "������Ϊ�գ�ɾ��Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	else if (pos <= 0 || pos > length_) {
		cout << "λ�� " << setw(2) << pos << " ����" << "ɾ��Ԫ��ʧ��!" << endl;
		return false;
	}
	else {
		ListNode* dummy_node = new ListNode(0), * cur = dummy_node;
		dummy_node->next = head_;
		while (cur->next) {
			if (--pos == 0) {
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;

				head_ = dummy_node->next;
				--length_;
				return true;
			}
			cur = cur->next;
		}
		cout << "δ֪ԭ��ɾ��Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
}

// ��һ�����������в���Ԫ��,����֤�����������
bool LinkList::InsertElemInOrder(ElemType val)
{
	if (!head_) {
		head_ = new ListNode(val);
		++length_;
		return true;
	}

	ListNode* dummy_node = new ListNode(0);
	dummy_node->next = head_;
	ListNode* pre = dummy_node;
	while (pre->next) {
		if (val <= pre->next->val) {
			ListNode* tmp = pre->next;
			pre->next = new ListNode(val);
			pre->next->next = tmp;
			break;
		}
		else {
			if (!pre->next->next) {
				ListNode* cur = pre->next;
				cur->next = new ListNode(val);
				cur->next->next = nullptr;
				break;
			}
			else
				pre = pre->next;
		}
	}
	head_ = dummy_node->next;
	++length_;
	return true;
}

// ����Ԫ�ص���ż�Է��뵥����
bool LinkList::SplitLinkListByParityOfVal(LinkList*& l_odd, LinkList*& l_even)
{
	ListNode* cur = head_;
	ListNode* dummy_node_odd = new ListNode(0), * dummy_node_even = new ListNode(0);
	ListNode* cur_odd = dummy_node_odd, * cur_even = dummy_node_even;

	while (cur) {
		if (cur->val % 2 == 1) {
			cur_odd->next = cur;
			cur = cur->next;
			cur_odd->next->next = nullptr;
			cur_odd = cur_odd->next;
			++l_odd->length_;
		}
		else {
			cur_even->next = cur;
			cur = cur->next;
			cur_even->next->next = nullptr;
			cur_even = cur_even->next;
			++l_even->length_;
		}
		
	}
	l_odd->head_ = dummy_node_odd->next;
	l_even->head_ = dummy_node_even->next;
	head_ = nullptr;
	length_ = 0;
	return true;
}

// ��ӡ������ĳ��Ⱥ�Ԫ��
void LinkList::PrintLinkList()
{
	ListNode* cur = head_;
	cout << "�������ȣ�" << length_ << endl;
	cout << "������Ԫ�أ�";
	while (cur)
	{
		cout << cur->val << "->";
		cur = cur->next;
	}

	cout << "nullptr" << endl << endl;
}

