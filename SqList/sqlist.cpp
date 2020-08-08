#include "stdafx.h"
#include "sqlist.h"

/**
 * @brief ���캯��,��ʼ��˳���
 */
SqList::SqList()
{
	elem_ = new ElemType[kMaxSize];   // ���ٿռ�
	if (!elem_) {                     // �����ʱ���쳣
		exit(OVERFLOW);
	}
	length_ = 0;                      // ����˳���ĳ���
}

/**
 * @brief ��������,����˳���
 */
SqList::~SqList()
{
	delete[] elem_;
	cout << this << " ˳��������٣�" << endl;
}

/**
 * @brief	  ������������,����һ��˳���
 * @param[in] len ˳���ĳ���
 */
void SqList::CreatSqList(int len)
{
	if (len < 0) {
		cout << "����ʧ�ܣ�����Ľ���������" << endl;
		exit(EXIT_FAILURE);
	}
	else if (len > kMaxSize) {
		cout << "����ʧ�ܣ�����Ľ������������ֵ��" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		for (int i = 0; i < len; ++i) {
			ElemType num;
			cin >> num;
			InsertSqListAtEnd(num);
		}
		length_ = len;
	}
}

/**
 * @brief	  �����±����˳����е�Ԫ��
 * @param[in] idx ������±�,��1��ʼ
 * @return	  ���ҵ���Ԫ��(ElemType����) 
 * @note	  ��������±겻����,��ǿ���˳�����	
 */
ElemType SqList::GetElemByIdx(int idx) {
	if (idx < 1 || idx > length_) {
		cout << "��ѯ���±겻���ڣ�" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		return elem_[idx - 1];
	}
}

/**
 * @brief ��ӡ˳���ĳ��Ⱥ�Ԫ��
 */
void SqList::PrintSqList()
{
	cout << "˳����ȣ�" << length_ << endl;
	cout << "˳���Ԫ�أ�" << endl;
	for (int i = 0; i < length_; ++i) {
		cout << setw(5) << elem_[i] << " ";
		if ((i + 1) % 10 == 0 || i == length_ - 1)
			cout << endl;
	}
}

/**
 * @brief �����Ա���С�����������
 */
void SqList::SortSqList()
{
	sort(elem_, elem_ + length_);
}

/**
 * @brief	   ����˳���Ԫ�ص���ż�Է���˳���
 * @param[out] l_odd �����������˳���
 * @param[out] l_even ���������ż˳���
 */
void SqList::SplitSqListByParityOfVal(SqList*& l_odd, SqList*& l_even)
{
	for (int i = 0; i < length_; ++i) {
		if (elem_[i] % 2 == 0) {
			l_even->elem_[l_even->length_++] = elem_[i];
		}
		else {
			l_odd->elem_[l_odd->length_++] = elem_[i];
		}
	}
}

/**
 * @brief	   ��������˳���Ĺ�ͬԪ��,�����ڵ�����˳�����
 * @param[in]  l ��������Ա�,�����ҵ�ǰ���Ա�����Ĺ�ͬԪ��
 * @param[out] l_com ��������Ա�,��������˳���Ĺ�ͬԪ��
 */
void SqList::GetCommonElem(const SqList* const& l, SqList*& l_com)
{
	if (length_ == 0 || l->length_ == 0 || elem_[0] > l->elem_[l->length_ - 1] || elem_[length_ - 1] < l->elem_[0]) {
		cout << "û�й�ͬԪ�أ�" << endl << endl;
	}
	else {
		cout << "�й�ͬԪ�أ�" << endl << endl;
		int i = 0, j = 0;
		while (i < length_ && j < l->length_) {
			if (elem_[i] == l->elem_[j]) {
				l_com->elem_[l_com->length_++] = elem_[i];
				++i;
			}
			else if (elem_[i] > l->elem_[j]) {
				++j;
			}
			else {
				++i;
			}
		}
	}
}

/**
 * @brief ɾ��˳�������ظ�Ԫ��
 */
void SqList::DeleteRepeatedElem()
{
	int idx = 0;
	for (int i = 0; i < length_;) {
		elem_[idx++] = elem_[i];
		if (elem_[i] == elem_[i + 1]) {
			int tmp = elem_[i++];
			while (i < length_ && elem_[i] == tmp) {
				++i;
			}
		}
		else {
			++i;
		}
	}
	length_ = idx;
}

/**
 * @brief  ����˳���ĳ���
 * @return length_ ˳���ĳ���
 */
int SqList::GetLength()
{
	return length_;
}

/**
 * @brief  �ж�˳����Ƿ�Ϊ��
 * @return ����˵����
 *         true  ˳���Ϊ��
 *         false ˳���ǿ�
 */
bool SqList::isEmpty()
{
	if (length_ == 0) {
		cout << "˳���Ϊ�գ�" << endl;
		return true;
	}
	else {
		cout << "˳���ǿգ�" << endl;
		return false;
	}
}

/**
 * @brief  �ж�˳����Ƿ�����
 * @return ����˵����
 *         true  ˳�������
 *         false ˳���δ��
 */
bool SqList::isFull()
{
	if (length_ >= kMaxSize) {
		cout << "˳���������" << endl;
		return true;
	}
	else {
		cout << "˳���δ����" << endl;
		return false;
	}
}

/**
 * @brief     ��˳���β������Ԫ��
 * @param[in] data �����������Ԫ��
 * @return    ����˵����
 *            true  Ԫ�ز���ɹ�
 *            false Ԫ�ز���ʧ��
 */
bool SqList::InsertSqListAtEnd(ElemType data)
{
	if (length_ >= kMaxSize) {
		cout << "˳����������޷����룡" << endl;
		return false;
	}
	else {
		elem_[length_++] = data;
		return true;
	}
}

/**
 * @brief     ��˳���idxλ��ǰ����Ԫ��
 * @param[in] idx  ��Ҫ��λ��idx(��1��ʼ)֮ǰ����Ԫ��
 * @param[in] data �����������Ԫ��
 * @return    ����˵����
 *            true  Ԫ�ز���ɹ�
 *            false Ԫ�ز���ʧ��
 */
bool SqList::InsertSqListBeforeIdx(int idx, ElemType data)
{
	if (idx < 1 || idx > length_) {
		cout << "������±겻�Ϸ���" << endl;
		return false;
	}
	else if (length_ >= kMaxSize) {
		cout << "˳����������޷����룡" << endl;
		return false;
	}
	else {
		for (int i = length_; i >= idx; --i) {
			elem_[i] = elem_[i - 1];
		}
		elem_[idx - 1] = data;
		++length_;
		return true;
	}
}

/**
 * @brief     ��˳����в���Ԫ��,����֤�����˳������������
 * @param[in] data �����������Ԫ��
 * @return    ����˵����
 *            true  Ԫ�ز���ɹ�
 *            false Ԫ�ز���ʧ��
 */
bool SqList::InsertSqListInOrder(ElemType data)
{
	SortSqList();

	if (data <= elem_[0]) {
		return InsertSqListBeforeIdx(1, data);
	}
	else if (data >= elem_[length_ - 1]) {
		return InsertSqListAtEnd(data);
	}
	else {
		int l = 0, r = length_ - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (data < elem_[m])
				r = m - 1;
			else
				l = m + 1;
		}
		return InsertSqListBeforeIdx(l + 1, data);
	}
}

/**
 * @brief     ɾ��idxλ�ô���Ԫ��
 * @param[in] idx ��ɾ��������Ԫ��λ��,��1��ʼ
 * @return    ����˵����
 *            true  Ԫ�ز���ɹ�
 *            false Ԫ�ز���ʧ��
 */
bool SqList::DeleteElem(int idx)
{
	if (idx < 1 || idx > length_) {
		cout << "������±겻�Ϸ���" << endl;
		return false;
	}
	else {
		for (int i = idx; i < length_; ++i) {
			elem_[i - 1] = elem_[i];
		}
		elem_[--length_] = NULL;
		return true;
	}
}


