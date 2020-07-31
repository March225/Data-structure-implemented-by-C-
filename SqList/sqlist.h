#pragma once
/**
 * @brief ����һ��˳�����
 */

class SqList
{
public:
	SqList();
	~SqList();

	void CreatSqList(int len); // ����һ��˳���
	ElemType GetElemByIdx(int idx); // �����±����˳����е�Ԫ��
	void PrintSqList(); // ��ӡ˳���
	void SortSqList(); // ����˳���
	void SplitSqListByParityOfVal(SqList*& l_odd, SqList*& l_even); // ����˳���Ԫ�ص���ż�Է���˳���
	void GetCommonElem(const SqList* const& l, SqList*& l_com); // ��������˳���Ĺ�ͬԪ��,�����ڵ�����˳�����
	void DeleteRepeatedElem(); // ɾ��˳�������ظ�Ԫ��
	int GetLength(); // ����˳���ĳ���
	bool isEmpty(); // �ж�˳����Ƿ�Ϊ��
	bool isFull(); // �ж�˳����Ƿ�����
	bool InsertSqListAtEnd(ElemType data); // ��β������Ԫ��
	bool InsertSqListBeforeIdx(int idx, ElemType data); // ��idxλ��ǰ����Ԫ��
	bool InsertSqListInOrder(ElemType data); // ����Ԫ��,����֤˳����������
	bool DeleteElem(int idx); // ɾ��idxλ�ô���Ԫ��

private:
	ElemType* elem_; // ˳���Ļ���ַ
	int length_; // ˳���ĳ���
};