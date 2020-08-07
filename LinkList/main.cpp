/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   �������C++ʵ�����ļ�
 *  @version   1.0
 *  @date	   2020-08-07
 */

#include "stdafx.h"
#include "linklist.h"

int main()
{
	FILE* stream1;
	ios::sync_with_stdio(false); // ��c���������������c++������������ֿ�,ʹcin����ĸ���
	freopen_s(&stream1, "10_1.in", "r", stdin); // ֱ�Ӵ��ĵ��ж�ȡ�����������


	// ����չʾ���ǰ���Ԫ��ֵ����ż�Էֽⵥ����Ĺ��ܣ�ʵ�ֺ���Ϊ SplitLinkListByParityOfVal()
	LinkList* L1 = new LinkList();
	int len;
	cin >> len;
	L1->CreateLinkListByInsertAtEnd(len);
	L1->PrintLinkList();

	LinkList* L1_odd = new LinkList();
	LinkList* L1_even = new LinkList();

	L1->SplitLinkListByParityOfVal(L1_odd, L1_even); // ʵ�ַ���
	L1_odd->PrintLinkList(); // ��ӡ������������
	L1_even->PrintLinkList(); // ��ӡż����������

	L1->PrintLinkList(); // ��ӡԭ��������ԭ�����Ѿ��ֽ⣬��˴�ӡ����Ϊ�գ�

	delete L1;
	delete L1_odd;
	delete L1_even;

	return 0;
}

