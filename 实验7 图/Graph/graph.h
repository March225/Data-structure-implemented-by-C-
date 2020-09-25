#pragma once
#include "stdafx.h"

/**
 * @brief ����һ��graph��
 */
class Graph {

private:
	VertexType* vexs_; // ��������
	EdgeType** arc_;   // �ڽӾ�������
	int nVertexes_, nEdges_; // ͼ�е�ǰ�Ķ������ͱ���
	GraphKind graphType_; // ͼ������

	VertexNode* adjList_; // ��Ŷ�����������
	bool* visited_; // ���ʱ�־������

public:
	Graph(); // ���캯��
	~Graph(); // ��������
	bool createAdjMatrixGraph(string fileName); // ��ͼ���ڽӾ��󴴽�ͼ
	bool createAdjListGraph(string fileName); // ��ͼ���ڽӱ���ͼ
	void strTrim(string& s); // ɾ���ַ���s��ߺ��ұߵĿո�
	void printAdjMatrixGraph(); // ��ӡͼ�����͡�������ڽӾ���
	void printAdjListGraph(); // ��ӡͼ�����͡�������ڽӱ�
	void DFSAdjMatTraverse(); // �ڽӾ����������ȱ���
	void DFSAdjListTraverse(); // �ڽӱ��������ȱ���
	void BFSAdjMatTraverse(); // �ڽӾ���Ĺ�����ȱ���
	void BFSAdjListTraverse(); // �ڽӱ�Ĺ�����ȱ���

protected:
	void DFSAdjMat(int i); // �ڽӾ����������ȵݹ��㷨
	void DFSAdjList(int i); // �ڽӱ��������ȵݹ��㷨
};
