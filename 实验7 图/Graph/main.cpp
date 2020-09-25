/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   ͼ��C++ʵ�����ļ�
 *  @version   1.0
 *  @date	   2020-09-23
 */
#include "stdafx.h"
#include "graph.h"

int main() {
	// �ļ����·����������������޸ģ�
	string fileName = "E:\\Program Files (x86)\\Microsoft Visual Studio\\workplace\\Graph\\grpData\\udg8.grp";
	Graph* g = new Graph();

	g->createAdjMatrixGraph(fileName); // ��ͼ���ڽӾ��󴴽�ͼ
	g->printAdjMatrixGraph(); // ��ӡͼ�����͡�������ڽӾ���

	g->createAdjListGraph(fileName); // ��ͼ���ڽӱ���ͼ
	g->printAdjListGraph(); // ��ӡͼ�����͡�������ڽӱ�

	g->DFSAdjMatTraverse(); // �ڽӾ����������ȱ���
	g->DFSAdjListTraverse(); // �ڽӱ��������ȱ���

	g->BFSAdjMatTraverse(); // �ڽӾ���Ĺ�����ȱ���
	g->BFSAdjListTraverse(); // �ڽӱ�Ĺ�����ȱ���

	delete g;
	return 0;
}