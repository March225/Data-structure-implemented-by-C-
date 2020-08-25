/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   ������������C++ʵ�����ļ�
 *  @version   1.0
 *  @date	   2020-08-25
 */

#include "stdafx.h"
#include "bstree.h"
#include "binsearch.h"

int main() {
	ios::sync_with_stdio(false); // ��c���������������c++������������ֿ�,ʹcin����ĸ���
	FILE* stream1;
	freopen_s(&stream1, "2.in", "r", stdin); // ֱ�Ӵ��ĵ��ж�ȡ����������ݣ���ͬ�ĵ�����ͬʵ�����������
	
	string s = "", num = "";
	stringstream ss;

// 	// ʵ������(1)�����ֲ��ң����д˶γ���Ҫע�͵�ʵ������(2)~(5)�ĳ���
// 	vector<int> nums;
// 	while (1) {
// 		if (getline(cin, s)) {
// 			ss << s;
// 			cout << "��������Ϊ��";
// 			while (getline(ss, num, ',')) {
// 				nums.push_back(stoi(num));
// 				cout << num << ",";
// 			}
// 			cout << endl;
// 		}
// 
// 		if (getline(cin, s)) {
// 			ss.clear();
// 			ss << s;
// 			while (getline(ss, num, ','))
// 				cout << setw(3) << num << " ������" << setw(2) << BinarySearch(nums, stoi(num)) << endl;
// 			cout << endl;
// 			ss.clear();
// 		}
// 		else break;
// 	}

	// ʵ������(2)������BST
	BSTree<int>* BST1 = new BSTree<int>();
	getline(cin, s);
	ss << s;
	cout << "������BST���������У�" << endl;
	vector<int> nums1;
	while (getline(ss, num, ',')) {
		cout << num << " " ;
		nums1.push_back(stoi(num));
	}
	cout << endl;

	BST1->CreateBSTree(nums1);
	cout << "BST�����ɹ������������������Ϊ��";
	BST1->InOrderTraverse(0);
	cout << endl;

	// ʵ������(3)����BST�в���Ԫ�أ������������Ԫ�صĸ�����Ǳ�ڸ����(������Բ���BST������֮��ĸ����)
	getline(cin, s);
	ss.clear();
	ss << s;
	BSTNode<int>* node = nullptr, * father = nullptr;
	while (getline(ss, num, ',')) {
		int w_num = stoi(num);
		node = BST1->SearchByIter(w_num, father);
		if (node) cout << setw(3) << w_num << " ��BST�д��ڣ�ֵΪ��" << setw(3) << node->val;
		else cout << setw(3) << w_num << " ��BST�в�����" ;
		if (father) cout << " ������Ǳ�ڵĸ����Ϊ��" << setw(3) << father->val << endl;
		else cout<< " ��Ϊ����㣬�����ڸ����" << endl;
	}
	cout << endl;
	
	// ʵ������(4)��ɾ��BST�еĽ��
	getline(cin, s);
	ss.clear();
	ss << s;
	while (getline(ss, num, ',')) {
		int w_num = stoi(num);
		if (BST1->Delete(w_num)) {
			cout << setw(3) << w_num << " �Ѵ�BST��ɾ��" << endl;
			cout << "ɾ����BST�����������ӦΪ���򣩣�";
			BST1->InOrderTraverse(0);
		}
	}
	cout << endl;

	// ʵ������(5)������AVL��
	BSTree<int>* BST2 = new BSTree<int>();
	getline(cin, s);
	ss.clear();
	ss << s;
	cout << "������AVL�����������У�" << endl;
	vector<int> nums2;
	while (getline(ss, num, ',')) {
		cout << num << " ";
		nums2.push_back(stoi(num));
	}
	cout << endl;
	BST2->CreateAVL(nums2);
	cout << "AVL�������ɹ������������������Ϊ��" << endl;
	BST2->InOrderTraverse(0);

	delete BST1,BST2;
}