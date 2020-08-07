#pragma once
/**
 * @brief ����һ����������
 */

class LinkList
{
public:
	LinkList();
	~LinkList();

	int GetLength(); // ���ص�����ĳ���
	bool GetElemByPosition(int pos, ElemType& val); // ����λ�÷��ص������Ԫ��
	bool CreateLinkListByInsertAtEnd(int len); // β�巨����������
	bool CreateLinkListByInsertAtBeg(int len); // ͷ�巨����������
	bool InsertElemBeforePosition(int pos, ElemType val); // �ڵ�pos�����ǰ����ֵΪval�Ľ��
	bool FindElemByValue(int& pos, ElemType val); // ���ص�������ֵΪval��Ԫ��λ��
	bool DeleteElemByPosition(int pos); // ����λ��ɾ���������Ԫ��
	bool InsertElemInOrder(ElemType val); // ��һ�����������в���Ԫ��,����֤�����������
	bool SplitLinkListByParityOfVal(LinkList*& l_odd, LinkList*& l_even); // ����Ԫ�ص���ż�Է��뵥����
	void PrintLinkList(); // ��ӡ������ĳ��Ⱥ�Ԫ��



private:
	ListNode* head_; // ��������ƽ��
	int length_; // ������ĳ���
};
