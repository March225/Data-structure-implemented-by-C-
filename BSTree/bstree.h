#pragma once
#include "stdafx.h"

/**
 * @brief ����һ��������������
 */
template <typename ElemType>
class BSTree
{
private:
	BSTNode<ElemType>* root_;

public:
	BSTree() :root_(nullptr) {};
	~BSTree() { Destroy(); };

	void CreateBSTree(vector<ElemType> data) { CreateBSTree(root_, data); } // ����BST
	void CreateAVL(vector<ElemType> data) { CreateAVL(root_, data, 0, int(data.size()) - 1); } // ����AVL
	void Destroy() { Destroy(root_); } // ����BST
	bool Insert(ElemType val) { return Insert(root_, val); } // ������
	bool Delete(ElemType val) { return Delete(root_, val); } // ɾ�����

	// ���������mode��0�ݹ飬1�ǵݹ飩
	void InOrderTraverse(char mode) { mode == 0 ? InOrderByRecur(root_) : InOrderByNonRecur(root_); cout << endl; };
	// �ݹ����(father��������Ԫ�صĸ�����Ǳ�ڸ����(������Բ���BST������֮��ĸ����))
	BSTNode<ElemType>* SearchByRecur(ElemType val, BSTNode<ElemType>*& father) { return SearchByRecur(root_, val, father); }
	// ��������(father��������Ԫ�صĸ�����Ǳ�ڸ����(������Բ���BST������֮��ĸ����))
	BSTNode<ElemType>* SearchByIter(ElemType val, BSTNode<ElemType>*& father) { return SearchByIter(root_, val, father); }
	BSTNode<ElemType>* GetRoot() { return root_; }; // ��ȡ�����


protected:
	// ����BST
	void CreateBSTree(BSTNode<ElemType>*& root, vector<ElemType> data) {
		for (auto num : data) Insert(num);
	}

	// ����AVL
	BSTNode<ElemType>* CreateAVL(BSTNode<ElemType>*& root, vector<ElemType> data, int l, int r) {
		if (l > r) return nullptr;
		int m = l + (r - l) / 2;
		root = new BSTNode<ElemType>(data[m]);
		root->left = CreateAVL(root->left, data, l, m - 1);
		root->right = CreateAVL(root->right, data, m + 1, r);
		return root;
	}

	// ����BST
	void Destroy(BSTNode<ElemType>*& root) {
		if (root) {
			Destroy(root->left);
			Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}

	// ������
	bool Insert(BSTNode<ElemType>*& root, ElemType val) {
		BSTNode<ElemType>* node = new BSTNode<ElemType>(val);
		if (!node) {
			cerr << "�����ڴ�ʧ�ܣ�" << endl;
			return false;
		}

		if (!root) {
			root = node;
			return true;
		}
		BSTNode<ElemType>* father = nullptr;
		if (SearchByIter(root, val, father)) {
			cout << "BST���Ѵ���ֵΪ��" << val << " �Ľ�㣬����ʧ�ܣ�" << endl;
			return false;
		}
		else {
			if (father->val > val) father->left = node;
			else father->right = node;
			return true;
		}
	}

	// ɾ�����
	bool Delete(BSTNode<ElemType>*& root, ElemType val) {
		BSTNode<ElemType>* dele_node = nullptr, * father = nullptr;
		dele_node = SearchByIter(val, father);
		if (dele_node) {
			// ��ɾ�����ֻ��һ�����ӽ��
			if (!dele_node->left || !dele_node->right) {
				if (father->val < dele_node->val)
					father->right = dele_node->left ? dele_node->left : dele_node->right;
				else
					father->left = dele_node->left ? dele_node->left : dele_node->right;
			}
			// ��ɾ��������������ӽ��
			else if (dele_node->left && dele_node->right) {
				if (father) {
					if (father->val > dele_node->val) father->left = dele_node->right;
					else father->right = dele_node->right;
				}
				else root_ = dele_node->right;

				BSTNode<ElemType>* left_node = dele_node->right;
				while (left_node->left) left_node = left_node->left;
				left_node->left = dele_node->left;
			}
			// ɾ�����
			delete dele_node;
			dele_node = nullptr;
			return true;
		}
		else {
			cout << "BST�в�����ֵΪ��" << val << " �Ľ�㣬ɾ��ʧ�ܣ�" << endl;
			return false;
		}
	}

	// ����������ݹ飩
	void InOrderByRecur(BSTNode<ElemType>*& root)
	{
		if (root) {
			InOrderByRecur(root->left);
			cout << root->val << " ";
			InOrderByRecur(root->right);
		}
	}

	// ����������ǵݹ飩
	void InOrderByNonRecur(BSTNode<ElemType>*& root)
	{
		stack<BSTNode<ElemType>*> st;
		BSTNode<ElemType>* cur = root;
		while (!st.empty() || cur) {
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
			cur = st.top(); st.pop();
			cout << cur->val << " ";
			cur = cur->right;
		}
	}

	// �ݹ����(father��������Ԫ�صĸ�����Ǳ�ڸ����(������Բ���BST������֮��ĸ����))
	BSTNode<ElemType>* SearchByRecur(BSTNode<ElemType>*& root, ElemType val, BSTNode<ElemType>*& father) {
		if (!root) return nullptr;
		if (root->val == val) {
			father = nullptr;
			return root;
		}

		father = root;
		if (root->left && root->left->val == val) return root->left;
		if (root->right && root->right->val == val) return root->right;

		if (root->val > val) return SearchByRecur(root->left, val, father);
		else return SearchByRecur(root->right, val, father);
	}

	// ��������(father��������Ԫ�صĸ�����Ǳ�ڸ����(������Բ���BST������֮��ĸ����))
	BSTNode<ElemType>* SearchByIter(BSTNode<ElemType>*& root, ElemType val, BSTNode<ElemType>*& father) {
		BSTNode<ElemType>* cur = root, * pre = nullptr;
		while (cur) {
			if (cur->val == val) {
				father = pre;
				return cur;
			}
			else if (cur->val > val) {
				pre = cur;
				cur = cur->left;
			}
			else {
				pre = cur;
				cur = cur->right;
			}
		}
		father = pre;
		return nullptr;
	}
};

