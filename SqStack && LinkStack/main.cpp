/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   ˳��ջ����ջ��C++ʵ�����ļ�
 *  @version   1.0
 *  @date	   2020-07-31
 */

#include "stdafx.h"
#include "solution.h"


int main()
{
	FILE* stream1;
	ios::sync_with_stdio(false); // ��c���������������c++������������ֿ�,ʹcin����ĸ���
	freopen_s(&stream1, "1.in", "r", stdin); // ֱ�Ӵ��ĵ��ж�ȡ�����������

	// ����˳��ջ����ջ��10������ת��Ϊ16�������������ļ�Ϊ��1.in��
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num = 0;
		cin >> num;
		cout << num << " ת��Ϊ16����Ϊ��" << Solution().DecToHex(num) << endl;
	}

// 	// ����˳��ջ����ջ�ж�һ�����ʽ�Ƿ���Ч���������������Ƿ�ƥ�䣩�������ļ�Ϊ��2.in��
// 	string s = "";
// 	int cnt = 0;
// 	while (getline(cin, s)) {
// 		if (Solution().isValidOfExpression(s))
// 			cout << ++cnt << ": yes��" << endl;
// 		else
// 			cout << ++cnt << ": no��" << endl;
// 	}

	return 0;
}