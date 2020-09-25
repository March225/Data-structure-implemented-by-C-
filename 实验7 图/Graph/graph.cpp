#include "graph.h"

// ���캯��
Graph::Graph() : nVertexes_(0), nEdges_(0), graphType_(GraphKind::None) {
	vexs_ = new VertexType[kMAXVEX]; // ��������
	arc_ = new EdgeType * [kMAXVEX]; // �ڽӾ�������
	for (int i = 0; i < kMAXVEX; ++i) {
		arc_[i] = new EdgeType[kMAXVEX](); // ��ʼ��Ϊ0
	}

	adjList_ = new VertexNode[kMAXVEX](); // ��Ŷ�����������
	visited_ = new bool[kMAXVEX]; // ���ʱ�־������
};

// ��������
Graph::~Graph() {
	delete[]vexs_;
	for (int i = 0; i < kMAXVEX; ++i) {
		delete[]arc_[i];
	}
	delete[]arc_;

	delete[]adjList_;
};

// ɾ���ַ���s��ߺ��ұߵĿո�
void Graph::strTrim(string& s) {
	if (!s.empty()) {
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}

// ��ͼ���ڽӾ��󴴽�ͼ
bool Graph::createAdjMatrixGraph(string fileName) {
	string str;		     // ��Ŷ���һ���ı����ַ���
	string strTemp;      // �ж��Ƿ�ע����
	EdgeType eWeight;    // �ߵ���Ϣ����Ϊ�ߵ�Ȩֵ

	ifstream fin(fileName.c_str());
	if (!fin)
	{
		cout << "�����ļ�" << fileName << "��ʧ�ܡ�" << endl;
		return false;
	}

	while (!fin.eof())
	{
		getline(fin, str);
		strTrim(str); // ɾ���ַ�����ߺ��ұߵĿո�����һ���Զ���ĺ���
		if (str.empty()) continue;	   // ���У�������ȡ��һ��
		strTemp = str.substr(0, 2);
		if (strTemp == "//") continue; // ����ע����
		else break;	 // ��ע���С��ǿ��У�����ѭ��
	}

	// ѭ��������str��Ӧ���Ѿ���ͼ�ı�ʶGraph���жϱ�ʶ�Ƿ���ȷ
	if (str.find("Graph") == string::npos)
	{
		cout << "���󣺴򿪵��ļ���ʽ����" << endl;
		fin.close(); // �ر��ļ�
		return false;
	}

	// ��ȡͼ�����ͣ���������
	while (!fin.eof())
	{
		getline(fin, str);
		strTrim(str); // ɾ���ַ�����ߺ��ұ߿ո�����һ���Զ��庯��
		if (str.empty()) continue;	   // ���У�������ȡ��һ��
		strTemp = str.substr(0, 2);
		if (strTemp == "//") continue; // ����ע����
		else break;	 // �ǿ��У�Ҳ��ע���У���ͼ�����ͱ�ʶ
	}

	// ����ͼ������
	if (str.find("UDG") != string::npos)
		graphType_ = GraphKind::UDG; // ����ͼ
	else if (str.find("UDN") != string::npos)
		graphType_ = GraphKind::UDN; // ������
	else if (str.find("DG") != string::npos)
		graphType_ = GraphKind::DG;  // ����ͼ
	else if (str.find("DN") != string::npos)
		graphType_ = GraphKind::DN;  // ������
	else
	{
		cout << "���󣺶�ȡͼ�����ͱ��ʧ��" << endl;
		fin.close(); // �ر��ļ�
		return false;
	}

	// ��ȡ���������ݵ�str����������
	while (!fin.eof())
	{
		getline(fin, str);
		strTrim(str); // ɾ���ַ�����ߺ��ұ߿ո�����һ���Զ��庯��
		if (str.empty()) continue;	   // ���У�������ȡ��һ��
		strTemp = str.substr(0, 2);
		if (strTemp == "//") continue; // ����ע����
		else break;	 // �ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
	}

	// �������ݴ���ͼ�Ķ�������
	VertexType ver;
	stringstream ss(str);
	unordered_map<VertexType, int> vex_map; // ��������������ϣ�������������
	nVertexes_ = 0;
	while (ss >> ver) {
		vex_map[ver] = nVertexes_;
		// nVertexes_Ϊͼ�Ķ�����
		vexs_[nVertexes_++] = ver;
	}

	// ͼ���ڽӾ����ʼ��
	int nRow = 0; // �������±�
	int nCol = 0; // �������±�
	if (graphType_ == GraphKind::UDN || graphType_ == GraphKind::DN) // �������
	{
		for (nRow = 0; nRow < kMAXVEX; nRow++)
			for (nCol = 0; nCol < kMAXVEX; nCol++)
				arc_[nRow][nCol] = INF; // INF��ʾ�����
	}

	// ѭ����ȡ�ߵ����ݵ��ڽӾ���
	int edgeNum = 0;   // �ߵ�����
	VertexType Vf, Vs; // �߻򻡵�2�����ڶ���
	while (!fin.eof())
	{
		getline(fin, str);
		strTrim(str); // ɾ���ַ�����ߺ��ұ߿ո�����һ���Զ��庯��
		if (str.empty()) continue;	   // ���У�������ȡ��һ��
		strTemp = str.substr(0, 2);
		if (strTemp == "//") continue; // ����ע����

		// �ָ�ߵ�����
		stringstream ss(str);

		// ��ȡ�ߵĵ�һ���������������������
		if (ss >> Vf) {
			nRow = vex_map[Vf];
		}
		else {
			cout << "���󣺶�ȡͼ�ı�����ʧ�ܣ�" << endl;
			fin.close(); // �ر��ļ�
			return false;
		}

		// ��ȡ�ߵĵڶ����������������������
		if (ss >> Vs) {
			nCol = vex_map[Vs];
		}
		else {
			cout << "���󣺶�ȡͼ�ı�����ʧ�ܣ�" << endl;
			fin.close(); // �ر��ļ�
			return false;
		}

		// ���Ϊ������ȡȨֵ
		if (graphType_ == GraphKind::UDN || graphType_ == GraphKind::DN)
		{   // ��ȡ��һ���Ӵ������ߵĸ�����Ϣ����Ϊ�ߵ�Ȩ��
			string edgeTmp;
			if (ss >> edgeTmp) {
				eWeight = stoi(edgeTmp);
			}
			else {
				cout << "���󣺶�ȡͼ�ı�����ʧ�ܣ�" << endl;
				fin.close(); // �ر��ļ�
				return false;
			}
		}

		// ���Ϊ�����ڽӾ����ж�Ӧ�ı�����Ȩֵ��������Ϊ1
		if (graphType_ == GraphKind::UDN || graphType_ == GraphKind::DN)
			arc_[nRow][nCol] = eWeight;
		else
			arc_[nRow][nCol] = 1;
		edgeNum++; // ������1
	}

	if (graphType_ == GraphKind::UDG || graphType_ == GraphKind::UDN)
		nEdges_ = edgeNum / 2; // ����ͼ���������ı�������ͳ�Ƶ����ֳ�2
	else
		nEdges_ = edgeNum;

	fin.close(); // �ر��ļ�
	return true;
}

// ��ͼ���ڽӱ���ͼ
bool Graph::createAdjListGraph(string fileName) {
	string str;          // ��Ŷ���һ���ı����ַ���
	string strTemp;      // �ж��Ƿ�ע����
	EdgeType eWeight;    //�ߵ���Ϣ����Ϊ�ߵ�Ȩֵ

	ifstream fin(fileName.c_str());
	if (!fin)
	{
		cout << "�����ļ�" << fileName << "��ʧ�ܡ�" << endl;
		return false;
	}

	while (!fin.eof())
	{
		getline(fin, str);
		strTrim(str); // ɾ���ַ�����ߺ��ұߵĿո�����һ���Զ���ĺ���
		if (str.empty()) continue;     // ���У�������ȡ��һ��
		strTemp = str.substr(0, 2);
		if (strTemp == "//") continue; // ����ע����
		else break;  // ��ע���С��ǿ��У�����ѭ��
	}

	// ѭ��������str��Ӧ���Ѿ���ͼ�ı�ʶGraph���жϱ�ʶ�Ƿ���ȷ
	if (str.find("Graph") == string::npos)
	{
		cout << "���󣺴򿪵��ļ���ʽ����" << endl;
		fin.close(); // �ر��ļ�
		return false;
	}

	// ��ȡͼ�����ͣ���������
	while (!fin.eof())
	{
		getline(fin, str);
		strTrim(str); // ɾ���ַ�����ߺ��ұ߿ո�����һ���Զ��庯��
		if (str.empty()) continue;     // ���У�������ȡ��һ��
		strTemp = str.substr(0, 2);
		if (strTemp == "//") continue; // ����ע����
		else break;  // �ǿ��У�Ҳ��ע���У���ͼ�����ͱ�ʶ
	}

	// ����ͼ������
	if (str.find("UDG") != string::npos)
		graphType_ = GraphKind::UDG; // ����ͼ
	else if (str.find("UDN") != string::npos)
		graphType_ = GraphKind::UDN; // ������
	else if (str.find("DG") != string::npos)
		graphType_ = GraphKind::DG;  // ����ͼ
	else if (str.find("DN") != string::npos)
		graphType_ = GraphKind::DN;  // ������
	else
	{
		cout << "���󣺶�ȡͼ�����ͱ��ʧ��" << endl;
		fin.close(); // �ر��ļ�
		return false;
	}

	// ��ȡ���������ݵ�str����������
	while (!fin.eof())
	{
		getline(fin, str);
		strTrim(str); // ɾ���ַ�����ߺ��ұ߿ո�����һ���Զ��庯��
		if (str.empty()) continue;     // ���У�������ȡ��һ��
		strTemp = str.substr(0, 2);
		if (strTemp == "//") continue; // ����ע����
		else break;  // �ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
	}

	// �������ݴ��붥�����
	VertexType ver;
	stringstream ss(str);
	unordered_map<VertexType, int> vex_map; // ��������������ϣ�������������
	nVertexes_ = 0;
	while (ss >> ver) {
		vex_map[ver] = nVertexes_;
		// nVertexes_Ϊͼ�Ķ�����
		adjList_[nVertexes_].data = ver;
		++nVertexes_;
	}

	//ѭ����ȡ�ߣ�����ԣ�����
	int nRow = 0;      //�������±�
	int nCol = 0;      //�������±�
	int edgeNum = 0;   // �ߵ�����
	VertexType Vf, Vs; // �߻򻡵�2�����ڶ���
	while (!fin.eof())
	{
		getline(fin, str);
		strTrim(str); // ɾ���ַ�����ߺ��ұ߿ո�����һ���Զ��庯��
		if (str.empty()) continue;     // ���У�������ȡ��һ��
		strTemp = str.substr(0, 2);
		if (strTemp == "//") continue; // ����ע����

		// �ָ�ߵ�����
		stringstream ss(str);

		// ��ȡ�ߵĵ�һ���������������������
		if (ss >> Vf) {
			nRow = vex_map[Vf];
		}
		else {
			cout << "���󣺶�ȡͼ�ı�����ʧ�ܣ�" << endl;
			fin.close(); // �ر��ļ�
			return false;
		}

		// ��ȡ�ߵĵڶ����������������������
		if (ss >> Vs) {
			nCol = vex_map[Vs];
		}
		else {
			cout << "���󣺶�ȡͼ�ı�����ʧ�ܣ�" << endl;
			fin.close(); // �ر��ļ�
			return false;
		}

		// ���Ϊ������ȡȨֵ
		if (graphType_ == GraphKind::UDN || graphType_ == GraphKind::DN)
		{   // ��ȡ��һ���Ӵ������ߵĸ�����Ϣ����Ϊ�ߵ�Ȩ��
			string edgeTmp;
			if (ss >> edgeTmp) {
				eWeight = stoi(edgeTmp);
			}
			else {
				cout << "���󣺶�ȡͼ�ı�����ʧ�ܣ�" << endl;
				fin.close(); // �ر��ļ�
				return false;
			}
		}
		auto p = new EdgeNode; // �����µı߽��
		p->adjvex = nCol; // �ڶ������������

		//�ߵĸ�����Ϣ��Ȩֵ��������Ȩͼ����Ȩֵ����ȨͼΪ1
		if (graphType_ == GraphKind::UDN || graphType_ == GraphKind::DN)
			p->info = eWeight;
		else
			p->info = 1;
		p->next = NULL;

		EdgeNode* eR = adjList_[nRow].firstEdge; // �߱�βָ��
		if (eR == nullptr) adjList_[nRow].firstEdge = p;
		else {
			while (eR && eR->next)
			{
				eR = eR->next; // ���Ʊ߱�ָ�룬ֱ��β�ڵ�
			}
			eR->next = p;
		}
		edgeNum++; //������1
	}
	if (graphType_ == GraphKind::UDG || graphType_ == GraphKind::UDN)
		nEdges_ = edgeNum / 2;   //����ͼ�����ı�������ͳ�Ƶ����ֳ�2
	else
		nEdges_ = edgeNum;
	fin.close(); // �ر��ļ�
	return true;
}

// ��ӡͼ�����͡�������ڽӾ���
void Graph::printAdjMatrixGraph() {
	cout << "/*******��ӡͼ�����͡�������ڽӾ���*******/" << endl << endl;
	string graphType;
	switch (graphType_) {
	case(GraphKind::DG):graphType = "DG"; break;
	case(GraphKind::DN):graphType = "DN"; break;
	case(GraphKind::UDG):graphType = "UDG"; break;
	case(GraphKind::UDN):graphType = "UDN"; break;
	default:cout << "����ͼΪ�գ�"; return;
	}
	cout << "ͼ�����ͣ�" << graphType << endl << endl;
	cout << "���������" << nVertexes_ << "���߸�����" << nEdges_ << endl << endl;

	cout << "���㣺";
	for (int i = 0; i < nVertexes_; ++i) cout << vexs_[i] << " ";
	cout << endl << endl;

	cout << "�ڽӾ���" << endl;
	cout << "  ";
	for (int i = 0; i < nVertexes_; ++i) cout << setw(2) << vexs_[i] << " ";
	cout << endl;
	for (int i = 0; i < nVertexes_; ++i) {
		cout << vexs_[i] << " ";
		for (int j = 0; j < nVertexes_; ++j) {
			if (arc_[i][j] == INF) cout << setw(2) << "��" << " ";
			else cout << setw(2) << arc_[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// ��ӡͼ�����͡�������ڽӱ�
void Graph::printAdjListGraph() {
	cout << "/*******��ӡͼ�����͡�������ڽӱ�*******/" << endl << endl;
	string graphType;
	switch (graphType_) {
	case(GraphKind::DG):graphType = "DG"; break;
	case(GraphKind::DN):graphType = "DN"; break;
	case(GraphKind::UDG):graphType = "UDG"; break;
	case(GraphKind::UDN):graphType = "UDN"; break;
	default:cout << "����ͼΪ�գ�"; return;
	}
	cout << "ͼ�����ͣ�" << graphType << endl << endl;
	cout << "���������" << nVertexes_ << "���߸�����" << nEdges_ << endl << endl;

	cout << "���㣺";
	for (int i = 0; i < nVertexes_; ++i) cout << adjList_[i].data << " ";
	cout << endl << endl;

	cout << "�ڽӱ�" << endl;
	for (int i = 0; i < nVertexes_; ++i) {
		auto VNode = adjList_[i];
		auto p = VNode.firstEdge;
		cout << setw(2) << i << " " << VNode.data << "->";
		while (p) {
			cout << setw(2) << p->adjvex << "(" << setw(2) << p->info << ")";
			if (p->next) cout << "->";
			p = p->next;
		}
		cout << endl;
	}
	cout << endl;
}

// �ڽӾ����������ȱ���
void Graph::DFSAdjMatTraverse() {
	if (graphType_ == GraphKind::None) {
		cout << "����ͼΪ�գ�"; return;
	}
	cout << "�ڽӾ����������ȱ�����" << endl;
	int i;
	for (i = 0; i < nVertexes_; ++i)
		visited_[i] = false;
	for (i = 0; i < nVertexes_; ++i) {
		if (!visited_[i])
			DFSAdjMat(i);
	}
	cout << endl << endl;
}

// �ڽӾ����������ȵݹ��㷨
void Graph::DFSAdjMat(int i) {
	int j;
	visited_[i] = true;
	cout << vexs_[i] << " ";
	for (j = 0; j < nVertexes_; ++j) {
		// ���ͼ����������
		if (graphType_ == GraphKind::DN || graphType_ == GraphKind::UDN) {
			if (arc_[i][j] != INF && !visited_[j])
				DFSAdjMat(j);
		}
		// ���ͼ�����Ͳ�����
		else {
			if (arc_[i][j] == 1 && !visited_[j])
				DFSAdjMat(j);
		}
	}
}

// �ڽӱ��������ȱ���
void  Graph::DFSAdjListTraverse() {
	if (graphType_ == GraphKind::None) {
		cout << "����ͼΪ�գ�"; return;
	}
	cout << "�ڽӱ��������ȱ�����" << endl;
	int i;
	for (i = 0; i < nVertexes_; ++i)
		visited_[i] = false;
	for (i = 0; i < nVertexes_; ++i) {
		if (!visited_[i])
			DFSAdjList(i);
	}
	cout << endl << endl;
}

// �ڽӱ��������ȵݹ��㷨
void  Graph::DFSAdjList(int i) {
	EdgeNode* p = nullptr;
	visited_[i] = true;
	cout << adjList_[i].data << " ";
	p = adjList_[i].firstEdge;
	while (p) {
		if (!visited_[p->adjvex])
			DFSAdjList(p->adjvex);
		p = p->next;
	}
}

// �ڽӾ���Ĺ�����ȱ���
void Graph::BFSAdjMatTraverse() {
	if (graphType_ == GraphKind::None) {
		cout << "����ͼΪ�գ�"; return;
	}
	cout << "�ڽӾ���Ĺ�����ȱ�����" << endl;
	for (int i = 0; i < nVertexes_; ++i)
		visited_[i] = false;

	queue<int> q;
	for (int i = 0; i < nVertexes_; ++i) {
		if (!visited_[i]) {
			visited_[i] = true;
			cout << vexs_[i] << " ";
			q.push(i);
			while (!q.empty()) {
				int k = q.front(); q.pop();
				for (int j = 0; j < nVertexes_; ++j) {
					// ���ͼ����������
					if (graphType_ == GraphKind::DN || graphType_ == GraphKind::UDN) {
						if (arc_[k][j] != INF && !visited_[j]) {
							visited_[j] = true;
							cout << vexs_[j] << " ";
							q.push(j);
						}
					}
					// ���ͼ�����Ͳ�����
					else {
						if (arc_[k][j] == 1 && !visited_[j]) {
							visited_[j] = true;
							cout << vexs_[j] << " ";
							q.push(j);
						}
					}
				}
			}
		}
	}
	cout << endl << endl;
}

// �ڽӱ�Ĺ�����ȱ���
void Graph::BFSAdjListTraverse() {
	if (graphType_ == GraphKind::None) {
		cout << "����ͼΪ�գ�"; return;
	}
	cout << "�ڽӱ�Ĺ�����ȱ�����" << endl;
	for (int i = 0; i < nVertexes_; ++i)
		visited_[i] = false;

	queue<EdgeNode*> q;
	for (int i = 0; i < nVertexes_; ++i) {
		if (!visited_[i]) {
			visited_[i] = true;
			cout << adjList_[i].data << " ";
			auto p = adjList_[i].firstEdge;
			q.push(p);
			while (!q.empty()) {
				p = q.front(); q.pop();
				while (p) {
					int j = p->adjvex;
					if (!visited_[j]) {
						visited_[j] = true;
						cout << adjList_[j].data << " ";
						q.push(adjList_[j].firstEdge);
					}
					p = p->next;
				}
			}
		}
	}
	cout << endl << endl;
}
