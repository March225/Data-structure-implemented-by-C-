/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   ���е�C++ʵ�����ļ�
 *  @version   1.0
 *  @date	   2020-08-10
 */

#include "stdafx.h"
#include "circlequeue.h"
#include "linkqueue.h"

int main()
{
	ios::sync_with_stdio(false); // ��c���������������c++������������ֿ�,ʹcin����ĸ���

// 	// ʾ��һ����ѭ����ʽ��0��98��99��Ԫ����ӣ�ͬʱ�ж��Ƿ������LinkQueue��CircleQueue������ʵ�֣���ͬ����
// 	LinkQueue<int>* Q1 = new LinkQueue<int>();
// 	for (int i = 0; i < 101; ++i) {
// 		if (!Q1->isFull()) {
// 			Q1->EnQueue(i);
// 			cout << "����δ����" << i << "�����У�" << endl;
// 		}
// 		else {
// 			cout << "����������"<< endl;
// 			cout << Q1 << endl;
// 			break;
// 		}
// 	}
// 	delete Q1;

// 	// ʾ������Ԫ�ص���ӳ��Ӳ�������ӡԪ�ظ�������ͷԪ�غ�ȫ��Ԫ�ء�
// 	LinkQueue<char>* Q1 = new LinkQueue<char>();
// 	Q1->EnQueue('a');
// 	Q1->EnQueue('b');
// 	Q1->EnQueue('c');
// 	Q1->EnQueue('d');
// 	cout << Q1 << endl;
// 
// 	char ch;
// 	Q1->DeQueue(ch);
// 	cout << endl << Q1 << endl;
// 	Q1->DeQueue(ch);
// 	cout << Q1 << endl;
// 	Q1->DeQueue(ch);
// 	cout << Q1 << endl;
// 	Q1->DeQueue(ch);
// 	cout << Q1 << endl;
// 	delete Q1;

	// ʾ�������������룺����������ӣ�ż��������ͷ���ӣ�0����������ÿ����������󣬴�ӡ���С�
	LinkQueue<int>* Q1 = new LinkQueue<int>();
	int num = 0;
	while (cin >> num) {
		if (num == 0) {
			cout << "����Ϊ0�����������" << endl;
			break;
		}
		Q1->OddOrEven(num);
		cout << Q1 << endl;
	}
	delete Q1;

	return 0;
}