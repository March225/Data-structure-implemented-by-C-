/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   ��������C++ʵ�����ļ�
 *  @version   1.0
 *  @date	   2020-08-14
 */

#include "stdafx.h"
#include "binarytree.h"

int main()
{
	FILE* stream1;
	ios::sync_with_stdio(false); // ��c���������������c++������������ֿ�,ʹcin����ĸ���
	freopen_s(&stream1, "1.in", "r", stdin); // ֱ�Ӵ��ĵ��ж�ȡ�����������

	/************** ����Ϊʾ���������ʵ��û�а���ʵ�������˳�� **************/

	BinaryTree<char>* BiT1 = new BinaryTree<char>;
	BiT1->CreatByPreOrderOfExtBiT(); // ͨ����չ��������ǰ���������������

	// �ݹ����
	cout << "ǰ��������ݹ飩��";
	BiT1->PreOrderTraverse(0);
	cout << "����������ݹ飩��";
	BiT1->InOrderTraverse(0);
	cout << "����������ݹ飩��";
	BiT1->PostOrderTraverse(0);
	cout << "��α������ݹ飩��";
	BiT1->LevelOrderTraverse(0);

	// �ǵݹ����
	cout << endl << "ǰ��������ǵݣ���";
	BiT1->PreOrderTraverse(1);
	cout << "����������ǵݣ���";
	BiT1->InOrderTraverse(1);
	cout << "����������ǵݣ���";
	BiT1->PostOrderTraverse(1);
	cout << "��α������ǵݣ���";
	BiT1->LevelOrderTraverse(1);

	// ����������������ֵ����Ӧ���
	cout << endl << "�������������ֵ����Ӧ��Σ�" << endl;
	BiT1->PrintLeveInOrderTra();

	// ����ÿ�����������ӽ��
	cout << "����ÿ�����������ӽ���" << endl;
	BiT1->ExchangeValOfLAndRChild();
	cout << "��α������ݹ飩��";
	BiT1->LevelOrderTraverse(0);

	// ��ӡ��������ֵΪval�Ľ��Ĳ��
	char val1 = 'C';
	cout << endl << "�������н�� " << val1 << " �Ĳ�Σ�" << BiT1->GetLevelByVal(val1) << endl;

	// ��ӡ�������������
	cout << endl << "���������������" << BiT1->NumberOfBiTNode() << endl;

	// ��ӡ������Ҷ�ӽ����
	cout << endl << "������Ҷ�ӽ������" << BiT1->NumberOfBiTLeafNode() << endl;

	// ��ӡ�������ж�Ϊ2�Ľ����
	cout << endl << "�������ж�Ϊ2�Ľ������" << BiT1->NumberOfNodeWithTwoDeg() << endl;

	// ����ֵΪval�Ľ��ĸ����
	char val2 = 'C';
	BiTNode<char>* parent = BiT1->GetParent(val2);
	if(parent)
		cout << endl << "�������н�� " << val2 << " �ĸ���㣺"  << parent->val << endl;
	else
		cout << endl << "��� " << val2 << " �����ڣ����޸��ڵ�" << endl;

	// ����ֵΪval�Ľ����ֵܽ��
	char val3 = 'E';
	BiTNode<char>* sibling = BiT1->GetSibling(val3);
	if (sibling)
		cout << endl << "�������н�� " << val3 << " ���ֵܽ�㣺" << sibling->val << endl;
	else
		cout << endl << "��� " << val3 << " �����ڣ������ֵܽ��" << endl;

	// ����ֵΪval�Ľ������ӽ��
	char val4 = 'B';
	BiTNode<char>* left_child = BiT1->GetLeftChild(val4);
	if (left_child)
		cout << endl << "�������н�� " << val4 << " �����ӽ�㣺" << left_child->val << endl;
	else
		cout << endl << "��� " << val4 << " �����ڣ��������ӽ��" << endl;

	// ��ӡ�������߶�
	cout << endl << "�������ĸ߶ȣ�" << BiT1->GetHeight() << endl;

	delete BiT1;
	return 0;
}