#pragma once
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#if !defined(AFX_STDAFX_H__D36E9D40_3BCB_4A85_9D48_AC876E7A2942__INCLUDED_)
#define AFX_STDAFX_H__D36E9D40_3BCB_4A85_9D48_AC876E7A2942__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <bits/stdc++.h> // ���ܵ�ͷ�ļ�,������Ҫ�ֶ�����include�ļ�����

typedef int ElemType; // ʹ�������������ElemTypeΪint

/**
 * @brief ���嵥����Ľ��
 */
struct ListNode {
	ElemType val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
};

using namespace std;

#endif // !defined(AFX_STDAFX_H__D36E9D40_3BCB_4A85_9D48_AC876E7A2942__INCLUDED_)