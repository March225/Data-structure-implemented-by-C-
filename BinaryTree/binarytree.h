#pragma once
#include"stdafx.h"

/**
 * @brief ����һ����������
 */
template <typename ElemType>
class BinaryTree
{
private:
	BiTNode<ElemType>* root_;

public:
	BinaryTree() :root_(nullptr) {};
	~BinaryTree() { Destroy(); };

	void CreatByPreOrderOfExtBiT() { CreatByPreOrderOfExtBiT(root_); } // ����������
	void Destroy() { Destroy(root_); }; // ���ٶ�����
	void PreOrderTraverse(char mode) { mode == 0 ? PreOrderByRecur(root_) : PreOrderByNonRecur(root_); cout << endl; }; // ǰ�������mode��0�ݹ飬1�ǵݹ飩
	void InOrderTraverse(char mode) { mode == 0 ? InOrderByRecur(root_) : InOrderByNonRecur(root_); cout << endl; }; // ���������mode��0�ݹ飬1�ǵݹ飩
	void PostOrderTraverse(char mode) { mode == 0 ? PostOrderByRecur(root_) : PostOrderByNonRecur(root_); cout << endl; }; // ���������mode��0�ݹ飬1�ǵݹ飩
	void LevelOrderTraverse(char mode) { mode == 0 ? LevelOrderByRecur() : LevelOrderByNonRecur(root_); cout << endl; }; // ��α�����mode��0�ݹ飬1�ǵݹ飩
	void PrintLeveInOrderTra() { PrintLeveInOrderTra(root_, 1); cout << endl; }; // ����������������ֵ����Ӧ���
	void ExchangeValOfLAndRChild() { ExchangeValOfLAndRChild(root_); }; // ����ÿ�����������ӽ��

	bool isEmpty() { return root_ == nullptr; }; // �ж϶������Ƿ�Ϊ��
	int GetHeight() { return GetHeight(root_); }; // ���ض������ĸ߶�
	int GetLevelByVal(ElemType val) { return GetLevelByVal(root_, val, 1); }; // ���ض�������ֵΪval�Ľ��Ĳ��
	int NumberOfBiTNode() { return NumberOfBiTNode(root_); }; // ���ض������������
	int NumberOfBiTLeafNode() { return NumberOfBiTLeafNode(root_); } // ���ض�����Ҷ�ӽ����
	int NumberOfNodeWithTwoDeg() { return NumberOfNodeWithTwoDeg(root_); }; // ���ض������ж�Ϊ2�Ľ����

	BiTNode<ElemType>* GetRoot() { return root_; }; // ���ض������ĸ����
	BiTNode<ElemType>* GetParent(ElemType val) { return GetParent(root_, val); }; // ����ֵΪval�Ľ��ĸ����
	BiTNode<ElemType>* GetSibling(ElemType val) { bool isExist = false; return GetSibling(root_, val, isExist); }; // ����ֵΪval�Ľ����ֵܽ��
	BiTNode<ElemType>* GetLeftChild(ElemType val) { bool isExist = false; return GetLeftChild(root_, val, isExist); }; // ����ֵΪval�Ľ������ӽ��
 
protected:
	// ͨ����չ��������ǰ���������������
	void CreatByPreOrderOfExtBiT(BiTNode<ElemType>*& root)
	{
		ElemType val;
		cin >> val;
		if (val != '#') {
			root = new BiTNode<ElemType>(val);
			if (!root) exit(OVERFLOW);
			CreatByPreOrderOfExtBiT(root->left);
			CreatByPreOrderOfExtBiT(root->right);
		}
		else root = nullptr;
	}

	// ���ٶ�����
	void Destroy(BiTNode<ElemType>*& root)
	{
		if (root) {
			Destroy(root->left);
			Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}

	// ǰ��������ݹ飩
	void PreOrderByRecur(BiTNode<ElemType>*& root)
	{
		if (root) {
			cout << root->val << " ";
			PreOrderByRecur(root->left);
			PreOrderByRecur(root->right);
		}
	}

	// ǰ��������ǵݹ飩
	void PreOrderByNonRecur(BiTNode<ElemType>*& root)
	{
		if (!root) return;
		stack<BiTNode<ElemType>*> st;
		st.push(root);
		while (!st.empty()) {
			BiTNode<ElemType>* cur = st.top(); st.pop();
			cout << cur->val << " ";
			if (cur->right) st.push(cur->right);
			if (cur->left) st.push(cur->left);
		}
	}

	// ����������ݹ飩
	void InOrderByRecur(BiTNode<ElemType>*& root)
	{
		if (root) {
			InOrderByRecur(root->left);
			cout << root->val << " ";
			InOrderByRecur(root->right);
		}
	}

	// ����������ǵݹ飩
	void InOrderByNonRecur(BiTNode<ElemType>*& root)
	{
		stack<BiTNode<ElemType>*> st;
		BiTNode<ElemType>* cur = root;
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

	// ����������ݹ飩
	void PostOrderByRecur(BiTNode<ElemType>*& root)
	{
		if (root) {
			PostOrderByRecur(root->left);
			PostOrderByRecur(root->right);
			cout << root->val << " ";
		}
	}

	// ����������ǵݹ飩
	void PostOrderByNonRecur(BiTNode<ElemType>*& root)
	{
		if (!root) return;
		stack<BiTNode<ElemType>*> st;
		BiTNode<ElemType>* pre = nullptr, * cur = root;
		st.push(cur);
		while (!st.empty()) {
			cur = st.top();
			if ((!cur->left && !cur->right) ||
				(pre && (pre == cur->left || pre == cur->right))) {
				cout << cur->val << " "; st.pop();
				pre = cur;
			}
			else {
				if (cur->right) st.push(cur->right);
				if (cur->left) st.push(cur->left);
			}
		}
	}

	// ��α������ݹ飩
	void LevelOrderByRecur()
	{
		int h = GetHeight();
		for (int i = 0; i < h; ++i)
			LevelOrder(root_, i);
	}

	// ��α����ݹ��ӳ���
	void LevelOrder(BiTNode<ElemType>*& root, int h)
	{
		if (root == nullptr) return;
		if (h == 0) {
			cout << root->val << " "; return;
		}
		LevelOrder(root->left, h - 1);
		LevelOrder(root->right, h - 1);
	}

	// ��α������ǵݹ飩
	void LevelOrderByNonRecur(BiTNode<ElemType>*& root)
	{
		if (!root) return;
		queue<BiTNode<ElemType>*> q;
		q.push(root);
		while (!q.empty()) {
			if (q.front()->left) q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			cout << q.front()->val << " "; q.pop();
		}
	}

	// ����������������ֵ����Ӧ���
	void PrintLeveInOrderTra(BiTNode<ElemType>*& root, int n)
	{
		if (root) {
			PrintLeveInOrderTra(root->left, n + 1);
			cout << "��㣺" << root->val << "  �ýڵ��Σ�" << n << endl;
			PrintLeveInOrderTra(root->right, n + 1);
		}
	}

	// ����ÿ�����������ӽ��
	void ExchangeValOfLAndRChild(BiTNode<ElemType>*& root)
	{
		BiTNode<ElemType>* cur = root;
		if (cur && (cur->left || cur->right)) {
			BiTNode<ElemType>* tmp = cur->left;
			cur->left = cur->right;
			cur->right = tmp;
		}
		else return;
		ExchangeValOfLAndRChild(cur->left);
		ExchangeValOfLAndRChild(cur->right);
	}

	// ���ض������ĸ߶�
	int GetHeight(BiTNode<ElemType>*& root)
	{
		if (!root) return 0;
		else {
			int LeftTHeight = GetHeight(root->left);
			int RightTHeight = GetHeight(root->right);
			return LeftTHeight > RightTHeight ? LeftTHeight + 1 : RightTHeight + 1;
		}
	}

	// ���ض�������ֵΪval�Ľ��Ĳ��
	int GetLevelByVal(BiTNode<ElemType>*& root, ElemType val, int n)
	{
		if (!root) return -1;
		else {
			if (root->val == val) return n;
			int level = GetLevelByVal(root->left, val, n + 1);
			return level == -1 ? GetLevelByVal(root->right, val, n + 1) : level;
		}
	}

	// ���ض������������
	int NumberOfBiTNode(BiTNode<ElemType>*& root)
	{
		if (!root) return 0;
		else {
			int num_left = NumberOfBiTNode(root->left);
			int num_right = NumberOfBiTNode(root->right);
			return num_left + num_right + 1;
		}
	}

	// ���ض�����Ҷ�ӽ����
	int NumberOfBiTLeafNode(BiTNode<ElemType>*& root)
	{
		if (!root) return 0;
		else if (root && (!root->left && !root->right)) return 1;
		else {
			int num_left = NumberOfBiTLeafNode(root->left);
			int num_right = NumberOfBiTLeafNode(root->right);
			return num_left + num_right;
		}
	}

	// ���ض������ж�Ϊ2�Ľ����
	int NumberOfNodeWithTwoDeg(BiTNode<ElemType>*& root)
	{
		if (!root) return 0;
		else {
			int num_left = NumberOfNodeWithTwoDeg(root->left);
			int num_right = NumberOfNodeWithTwoDeg(root->right);
			if (root->left && root->right)
				return num_left + num_right + 1;
			else
				return num_left + num_right;
		}
	}

	// ����ֵΪval�Ľ��ĸ����
	BiTNode<ElemType>* GetParent(BiTNode<ElemType>*& root, ElemType val)
	{
		if (!root || root->val == val) return nullptr;
		if ((root->left && root->left->val == val) || (root->right && root->right->val == val))
			return root;
		else
			return GetParent(root->left, val) == nullptr ? GetParent(root->right, val) : GetParent(root->left, val);
	}

	// ����ֵΪval�Ľ����ֵܽ��
	BiTNode<ElemType>* GetSibling(BiTNode<ElemType>*& root, ElemType val, bool& isExist)
	{
		if (!root || root->val == val) return nullptr;
		if (root->left && root->left->val == val) {
			isExist = true;
			return root->right;
		}
		else if (root->right && root->right->val == val) {
			isExist = true;
			return root->left;
		}
		else {
			BiTNode<ElemType>* left_half = GetSibling(root->left, val, isExist);
			if (isExist) return left_half;
			return GetSibling(root->right, val, isExist);
		}
	}

	// ����ֵΪval�Ľ������ӽ��
	BiTNode<ElemType>* GetLeftChild(BiTNode<ElemType>*& root, ElemType val, bool& isExist)
	{
		if (!root) return nullptr;
		if (root->val == val) {
			isExist = true;
			return root->left;
		}
		else {
			BiTNode<ElemType>* left_half = GetLeftChild(root->left, val, isExist);
			if (isExist) return left_half;
			return GetLeftChild(root->right, val, isExist);
		}
	}
};


