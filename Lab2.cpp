/********************************************************************************
 * � � � � � � � � � � � �   � � � � � �  �2  � �   5   � � � � � � �   �  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab2                                               *
 * File Name     : Lab2. CPP                                                    *
 * Programmer(s) : ������� �.�.                                                 *
 * Modifyed By   :                                                              *
 * Created       : 19/09/23                                                     *
 * Last Revision : 29/09/23                                                     *
 * Comment(s)    : ���������, ������������ ���������. ��� ����� � ���������,    *
 *                 � ����� ���������� � ������ ��������� ���������. ��� ������� *
 *                 - �������, ������ ���������, ��� �����������. � �����        *
 *                 � ������ ��������� ��������� � ������� ���������.            *
 *                 ��� ����������� ������������ ����� � ������. ��� ���������   *
 *                 �������� - ����� � �������.                                  *
 ********************************************************************************/


#include <iostream>              // ����������� ������ �����/������
#include <vector>                // ������ � ��������� ��� �������� �������� ���������� � �������� ���������
#include <fstream>               // ������ � �������� �����/������ ��� �����
#include <iomanip>               // ���������� � ������������� setw
#include <graphviz/gvc.h>        // ���������� Graphviz ��� ������������ ����������� ����� �� ������� ���������
#include <opencv2/opencv.hpp>    // ���������, ������������� ��� ������� OpenCv

using namespace std;             // ���������� ������������ ��� std



/*******************************************************************/
/*            � � � � � � � � � �    � � � � � � � � �             */
/*******************************************************************/

// ���� � ����� ����� ����������� ���������
// ������� �����
// ����� ��� ������� ���������
//const char* FNAMEIN = "matrix_t2_001.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_002.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_003.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_004.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_005.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_006.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_007.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_008.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_009.txt";                // ���� � �������� ���������
const char* FNAMEIN = "matrix_t2_010.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_011.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_012.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_013.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t2_014.txt";                // ���� � �������� ���������

// ����� ��� ������ �����
//const char* FNAMEIN = "list_of_edges_t2_001.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_002.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_003.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_004.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_005.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_006.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_007.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_008.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_009.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_010.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_011.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_012.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_013.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t2_014.txt";         // ���� �� ������� ����

// ����� ��� ������ ���������
//const char* FNAMEIN = "list_of_adjacency_t2_001.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_002.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_003.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_004.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_005.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_006.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_008.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_009.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_011.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_013.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t2_014.txt";     // ���� �� ������� ���������

// �������� �����
const char* FNAMEOUT = "Output_File.txt";

// ������������� ��� ������� ����������
const int INF = 10000;




/*******************************************************************/
/*      � � � � � � � � � �    � � � � � � � �    � � � � � �      */
/*******************************************************************/

 // ���������� ������� ��� ���������� ����� ������ �� �����
ifstream fin;
// ���������� ������� ��� ���������� ������ ������ � ����
ofstream fout;




/*******************************************************************/
/*                 � � � � � � � �   � � � � � � �                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // ���� � ��������� ����������� �������� ���������
	int m_size;                                               // ������ ������� ��������� (���������� ������ � �����)

public:
	// �����������
	Graph();
	// ����������
	~Graph();
	// ����������� ������ ��� ��������� �������� �������
	const int GetSize();
	// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
	bool is_directed();
	// �������, ������������ ������� ���������
	vector<vector<int>> adjacency_matrix();
	// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
	int Weight(int Vi, int Vj);
	// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
	bool is_edge(int Vi, int Vj);
	// �������, ������������ ������ ������, ������� ������� v;
	vector<int> adjacency_list(int v);
	// �������, ������������ ������ ���� ���� �����;
	vector<pair<int, int>> list_of_edges_pairs();
	// � �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              � � � � � � � � �    � � � � � � �                 */
/*******************************************************************/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix);     // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ����� �� ����� � ���� ��������
void OpenImage(const vector<vector<int>>& adjacencyMatrix);       // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix);                     // �������, ������� ���������� ������� �� �����. �������� �� ��������

// ������ ������� � ������� ������
void Usloviya();

// ����� � ������
void Breadth_First_Search(vector<vector<int>> matrix,             // ������� ���������, � ������� ����� ��������
	                      int StartVertex,                        // ��������� ������� ������
	                      vector<bool>& Is_Visited,               // ������ ���������� ������ ��� ������
	                      vector<int>& component);                // ��������� ����������, ������� �������� ��� ������ � ������

// ����� � �������
void DFS(vector<vector<int>> matrix,                              // ������� ���������, � ������� ����� ��������
	     int StartVertex,                                         // ��������� ������� ������
	     vector<bool>& Visited,                                   // ������ ���������� ������ ��� ������
	     vector<int>& obx,                                        // ������, ���������� ��� ������� � ������� ������ ���������
	     vector<int>& component);                                 // ��������� ����������, ������� �������� ��� ������ � ������

// ���������� ��������� �����
int Connectivity_Components(vector<vector<int>> matrix,           // ������� ���������, � ������� ����� ��������
	                        bool print);                          // ���� ������ � ����

// �������������� ���������������� ����� � ����������� ���
void convertToUndirected(vector<std::vector<int>>& matrix);       // ������� ��������� �� ������ ��� � ���������

// ����������� ��������������� ����
void Reverse_Direction(vector<vector<int>>& matrix);              // ������� ��������� �� ������ ��� � ���������

// �������� ��������
int Kasai(vector<vector<int>>matrix,                              // ������� ���������, � ������� ����� ��������
	      vector<vector<int>>reverse,                             // ������� ���������������� �����
	      vector<int>& recursion,                                 // ������ �������� ������ ��� ������������ ������� �� ������
          bool print);                                            // ���� �� �������� � ���� ����������

// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix);                 // �������, ������� ���������� ������� � ����. �������� �� ��������



// ����������� - ���������� ������� �� �����
Graph::Graph()
{
	fin.open(FNAMEIN);            // ��������� ������ � ������
	if (!fin.is_open())           // ���� �� ������
	{
		cout << "����� � ����� ������ ���. ���������� ����������� ������";
		fin.close();              // ������� ���� ��� ������
		system("pause");
		exit(0);                  // ���������� ��������, ��������������� ���� � caller
	}// if (!fin.is_open())

	int value;                    // ��������� ����������� ������
	char key;                     // ���� ��� �������� ������������� �������� ������� ����� � �����
	bool spravka = true;          // ���� ��� ������ ������� �� �����
	vector<int> row;              // ������ ��� ���������� ������������� �������� �� ����� ���������
	vector<vector<int>> matrix;   // ��������������� ������� ���������

	// ������ ����� ������� �����, ����� ������������ ������� ������� �� ����� �������
	while (spravka)
	{
		cout << "\x1b[30m � � � � � � �   � � � �   � � �   <h>   � � �   � � � � � �   � � � � � � � � � : \x1b[30m";
		// ������������ ��� ���� ��� ����, ����� ���� �������, ����� �������� �� ����� ����
		cin >> key;
		cout << "\n �� �����: " << key << endl;

		// � ����������� �� �������� �����
		switch (key)
		{
			// ������ � �������� ���������
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";
			// ��������� ��������� ����� �� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);

			}// while (fin >> value)

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������ �� ������� ����
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � �\n\n\x1b[30m\n";

			// ��������� �������� �� ����� � ������
			// � ������� ����� ���������� � ������������ ����� ��� ��������: ��������� �������, �������� ������� � ��� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);
			}// while (fin >> value)

			// ������� ���� ������
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // ������ ������� ���������
			vector<vector<int>> vec_1(size_m);                // ������� ���������

			for (int i = 0; i < size_m; i++)                  // ����� ������ ������ ������ vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// ��������� ������� ���������
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 ������� - ��� ��� �����, ���� �� �� ������, �� ������ �� = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// ���������� ������� ���������
			m_matrix = vec_1;
			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// �������� �� �������� ���������
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";

			                              // ������ �� ����� ���������
			string line;
			int rowNumber = 0;            // ����� ������� ������

			// ������ ����������
			while (getline(fin, line)) 
			{
				// ���� ������ ������, ��������� ������� ������ ������
				if (line.empty()) 
				{
					matrix.push_back(vector<int>(m_size, 0));
				}
				// ������ �� ������
				else
				{
					// ������ ������
					vector<int> row;
					// ������� ����� ��� ������ �������� �� ������ line. ����� �� ����� ������������ iss ������ � ���������� >> ��� ���������� �������� �� ������.
					istringstream iss(line);
					// ��������� �������� ��� ������
					int value;

					// ������ �������� �� ����� � �������� ��� � ������ ������
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// �������� ������ � �������
					matrix.push_back(row);
				}// if (line.empty()) 

				// ����������� ����� ������
				rowNumber++;
			}// while (getline(fin, line)) 

			// ���� �������� - ��������� ���
			fin.close();

			m_size = matrix.size();                         // ������ ������� ���������

			vector<vector<int>> vec_1(m_size);              // ��� ������� ��������� �������� m_size

			for (int i = 0; i < m_size; i++)                // ����� ������ ������ ������ ��� ������� ���������
			{
				// ��������� ��������������� ������� ������ �� ����� �������
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // ��������� ��� ������� ��������� 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// ������� � ��� ��������, ������� ����������� ��� ������ � �����
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// �������� �������� � �������� ������� ���������
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������������ ������ �������
		case('h'):
		case('H'):
		{
			// ��������� ���� ����� ��������� ������� �� ������
			spravka = true;
			// ������� �������
			Usloviya();
			break;
		}

		// ����� - ������������ ��� �� ��� ����. ����������� ��������� � �������
		default:
			cout << "\n\x1b[31m ������������� ��������� � ������� �������� �� ������ ������!!!\n\x1b[30m";
			// ��������� ���� ����������
			fin.close();
			exit(0);
		}
	}
	// ��������� ���� ����������
	fin.close();
	// ���������� ������ ���������/ ��������������� ������� ���������
	m_size = m_matrix.size();
}

// ����������
Graph::~Graph()
{
	// ������ ���� - ������� ������������ �������������
}

// ������ ��� ��������� �������� �������
const int Graph::GetSize()
{
	return(m_size);
}


// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
bool Graph::is_directed()
{
	// ��� �� �������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ��������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ���� �����������������, �� ������� �����������, ��� ��� �� ����� ����� ������ ������ ������������
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // ������� ������������ ����� - ���� ���������������
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // �� ������� ������������ ����� - ���� �����������������
}


// �������, ������������ ������� ���������
vector<vector<int>> Graph::adjacency_matrix()
{
	return(m_matrix);
}


// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
int Graph::Weight(int Vi, int Vj)

{
	// ������ ������ ����� �� ��������� ���������� ��������
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "������! ����� ������� �� ����������\n";
		// ������� ������
		return(-1);
	}

	// ���� ���� ����������(� ������� ��������� �� 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "��� ����� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����� ����� ���������
		return(m_matrix[Vi][Vj]);
	}

	// ���� ���������������. ������� ��� ����
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "���� ���������������. ���� ����. ����������� �����������. ��� ���� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����
		return(m_matrix[Vi][Vj]);
	}

	// ����� ����� ��������� ��� - ������� ������� ��������� ����� 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "����� ����� ��������� " << Vi << " � " << Vj << "���\n";
		// ������� ������� ��������
		return(m_matrix[Vi][Vj]);
	}

	return(0);
}


// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
bool Graph::is_edge(int Vi, int Vj)
{
	// ������ ������ ����� �� ��������� ���������� �������� - ���� ���
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// �������, ��� ���� ���
		return(false);
	}

	// ������� ������� ��������� �� ����� 0 - ����� ����
	if (m_matrix[Vi][Vj] != 0)
	{
		// ������������, ��� ����� ����
		return(true);
	}

	// ������� ������� ��������� ������� - ����� ���
	if (m_matrix[Vi][Vj] == 0)
	{
		// ������������, ��� ����� ���
		return(false);
	}

}


// �������, ������������ ������ ������, ������� ������� v;
vector<int> Graph::adjacency_list(int v)
{
	// ������ ������
	vector<int> adjList;

	// �������� �� ���� �������� � ���������, ���� �� ����� ����� �������� v � ������� ��������
	for (int i = 0; i < m_size; i++)
	{
		// ���� ���� - ������� ������� �� �������
		if (m_matrix[v][i] != 0)
		{
			// �������� ������� � ������
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// ���������� ������ ������� ������
	return adjList;
}


// �������, ������������ ������ ���� ���� �����;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// ������ ���, ���������� ����� � ���� ���� ����������� ��� ������
	vector<pair<int, int>> edges_pairs;
	// ��� �� ���� ��������� ������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ���� ��������� �������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ������� �� �������
			if (m_matrix[i][j] != 0)
			{
				// ��������� ���� ������
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i

	// ������� ������ ���� (��� ������)
	return(edges_pairs);
}


// �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // ������ ��� ������(������ ����)
	vector<pair<int, int>> edges_inc;     // ������ ���� ����������� ������� v / ��������� �� ������� v
	edges = list_of_edges_pairs();        // �������� ��� ���� ������ �����

	// ������� ��� ����. ���� ���� �����������������, �� ��� ����� ���� (v,n) � (n, v) - ���������� ����������� ��� ������������� ������ �������. � ������� - ��������� ������� ������ ������
	for (int i = 0; i < edges.size(); i++)
	{
		// ������������� ������ ������� ����
		if (edges[i].first == v)
		{
			// �������� � ����� �����, ����������� ������� ������ �����
			edges_inc.push_back(edges[i]);
			// ����������� �������
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// ����������  ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                �������               */
/*--------------------------------------*/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix)
{
	// ��������� ������ ������� ���������. ���� ������ 19, �� ������� �� ������� �������
	if (adjacencyMatrix.size() <= 19)
	{
		bool key = false;
		// ��������� ������� ����� �� ������, ����� ������, ����� �� ��������� �� ��� ������
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// ���� ��� ����� ������ 1 ��� �������������, ������, ����� ��������� ��� � ������
				if (adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
					key = true;
			}
		}

		// ��������� ���� ��� ������ ����� � ������� DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// ������� ���� � ��������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� �� ����� 0, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] != 0)
					{
						// ������� ����� � ��������� ���� � ������� DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// ������� ���� ��� �������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� ����� 1, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] == 1)
					{
						// ������� ����� ��� �������� ���� � ������� DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// ��������� ���� � ��������� ����������
		file << "}" << std::endl;
		file.close();

		// ���������� ����������� ����� � ������� PNG � ������� ������� DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\nGraph image saved as graph.png" << endl;
	}

	// �������, ��� ���� ������� ��� ���������
	else
	{
		cout << "\n\nGraph image is not saved as graph.png. It is too big" << endl;
	}
	// ���������� �������� ��� �������� ������ OpenCV
	return "graph.png";
}


// ����� ����� �� �����
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// ��������� ����������� ������� ���������
	if (adjacencyMatrix.size() <= 19)
	{
		// �������� ���� � �����������, ���������� � ������� ������� drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// ��������� ����������� � ������� OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// ���������, ������� �� ��������� �����������
		if (img.empty()) {
			cout << "Could not open or find the image" << endl;
			return;
		}

		// ������� ���� � ��������� "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// ���������� ����������� � ����
		cv::imshow("Graph", img);
		// ����, ���� ������������ ������ ����� �������
		cv::waitKey(0);
		// ��������� ����
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
}


// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix)
{
	// ��������� ������� ����
	setlocale(0, "C");            // ������� ������ � �������� �������
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // ����� ������� ���������� ������

	// ��� �� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// ��� �� ��������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ������� �������
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // ����� ������� �������
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");

	// ���������� ��������� ��������
	return;
}


// ������ ������� � ������� ������
void Usloviya()
{
	cout << "\n\t\t\t\t/********************************************************************************\n";
	cout << "\t\t\t\t* � � � � � � � � � � � �   � � � � � �  �2  � �   5   � � � � � � �   �  +  +  *\n";
	cout << "\t\t\t\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                     *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab2                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab2. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : ������� �.�.                                                  *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                               *\n";
	cout << "\t\t\t\t* Created       : 19/09/23                                                      *\n";
	cout << "\t\t\t\t* Last Revision : 28/09/23                                                      *\n";
	cout << "\t\t\t\t********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   � � � � � � � : \n\n\x1b[30m";
	// ������� ������� � �������
	setlocale(0, "C");                       // ��������� ������� ����
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // ������� ������� ������ �����
	setlocale(LC_ALL, "Rus");                // ���������� ������� ����
	cout << " �������� ���� ������� �� ������:      ";
	setlocale(0, "C");                       // ��������� ������� ����
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // ������� ������ ������ ����� � ������������ ����� ������� � ��������� ���������
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // ������� ������� ������ � ������ � �������� ��������� �������
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // ���������� ������� ����
	
	return;                                 // ���������� ��������� ��������
}


// ����� � ������
void Breadth_First_Search(vector<vector<int>> matrix,             // ������� ���������, � ������� ����� ��������
	                      int StartVertex,                        // ��������� ������� ������
	                      vector<bool>& Is_Visited,               // ������ ���������� ������ ��� ������
	                      vector<int>& component)                 // ��������� ����������, ������� �������� ��� ������ � ������

{
	vector<int> queque;                                           // ������������ ������� � �������
	int CurVert = 0;                                              // ������� ��������������� �������
	component.clear();                                            // ��� ������ ����� ������ ������� ���������� ���������
	
	// �������� �������, � ������� ������ �����, � �������
	queque.push_back(StartVertex);

	// ������ ������� - ��������
	Is_Visited[StartVertex] = true;
	
	// ���� ������� �� ������ �� �����
	while (!queque.empty())
	{
		CurVert = queque.front();              // �������� ��������� ������ ������� �������
		component.push_back(CurVert);          // �������� ��� � ���������� - �� � �� ������
		queque.erase(queque.begin());          // ������� ��������� ������ ������� �� �������

		// ��� �� ���� �������� ������ CurVert
		for (int j = 0; j < matrix.size(); j++)
		{
			// ���� ���������� ���� �� ������ ������� � ��������, � ��� �������� ������� - �� ��������
			if (matrix[CurVert][j] != 0 && Is_Visited[j] == false)
			{
				// ��������� � � �������
				queque.push_back(j);
				// �������� ��� ������� ��� ����������
				Is_Visited[j] = true;
			}// if (matrix[CurVert][j] != 0 && Is_Visited[j] == false)
		}// for j
	}// while (!queque.empty())

	// ���������� ��������� ��������
	return;
}


// ����� � �������
void DFS(vector<vector<int>> matrix,                              // ������� ���������, � ������� ����� ��������
	     int StartVertex,                                         // ��������� ������� ������
	     vector<bool>& Visited,                                   // ������ ���������� ������ ��� ������
	     vector<int>& obx,                                        // ������, ���������� ��� ������� � ������� ������ ���������
	     vector<int>& component)                                  // ��������� ����������, ������� �������� ��� ������ � ������
{
	Visited[StartVertex] = true;                                  // �������� ������� ��� ����������
	component.push_back(StartVertex);                             // ������� ������� � ������ ����������
	obx.push_back(StartVertex);                                   // �������� ������� �������, � ������� ��������� ��� ��������� ������� � ���� ������ �� ������� ���� �����

	// ���������� �� ���� �������� ������ StartVertex
	for (int i = 0; i < matrix.size(); i++)
	{
		// ���� ���� ���� � ������ ������������ �������
		if (matrix[StartVertex][i] != 0 && Visited[i] == false)
		{
			// ���������� �������� ����� ��� �������� �������
			DFS(matrix, i, Visited, obx, component);
			// ������� ������� �� �������� ���� �� ����� � ������� ��������
			obx.push_back(StartVertex);
		}// if (matrix[StartVertex][i] != 0 && Visited[i] == false)

	}// for i

	// ���������� ��������� ��������
	return;
}


// ���������� ��������� �����
// ���������� ��������� �����
int Connectivity_Components(vector<vector<int>> matrix,           // ������� ���������, � ������� ����� ��������
	                        bool print)                           // ���� ������ � ����
{
	vector<int> component;                                       // ��������� ���������� ���������
	vector<bool> Is_Visited(matrix.size());                      // ������������ �������. ������ ��������� � ����������� ������ 
	int CountComponents = 0;                                     // ������� ��������� ���������
	
	// ���������� �� �������� �� ���� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		// �� ���� ������� ��� �� ��������. ���� ����������
		Is_Visited[i] = false;
	}

	// ��������� ��� ������ ������� �����
	for (int i = 0; i < matrix.size(); i++)
	{
		// ��������� �������� ��� ������ ���������� �� �������, � ������� �������� �� ������� ��� ���������� ����������
		if (Is_Visited[i] == false)
		{
			// ������� � ������ ���� � ������� i, ������� ��� ���������� ������ �� ���� ��������
			Breadth_First_Search(matrix, i, Is_Visited, component);
			// ����� ������ ����������� ����� ��������� ���������
			CountComponents = CountComponents + 1;
			// ����������� ������� � ���������� ���������
			sort(component.begin(), component.end());

			// ������� �� �� �����
			cout << " [ ";
			if (print)
			{
				fout << " [ ";
			}// if(print)

			// ������� ��� �������� �������� ����������
			for (int i = 0; i < component.size(); i++)
			{
				cout << component[i] + 1 << " ";
				if (print)
				{
					fout<< component[i] + 1 << " ";
				}// if(print)

			}// for i
			cout << "] ";

			if (print)
			{
				fout << "] ";
			}// if(print)

		}// if (Is_Visited[i] == false)
	}// for i

	// ���������� ���������� ��������� ���������
	return(CountComponents);
}


// �������������� ���������������� ����� � ����������� ���
void convertToUndirected(vector<std::vector<int>>& matrix)        // ������� ��������� �� ������ ��� � ���������
{
	// �������� �� ������� �������� ������� � ������ �� ������������
	int size = matrix.size();
	// ��� �� �������
	for (int i = 0; i < size; i++) 
	{
		// �� ��������, ������� � i+1-��
		for (int j = i + 1; j < size; j++)
		{
			if (matrix[i][j] != 0) 
			{
				// ���� ���� ����� �� i � j, ������� ����� �� j � i
				matrix[j][i] = matrix[i][j];
			}// if (matrix[i][j] != 0) 

			else if (matrix[j][i] != 0) 
			{
				// ���� ���� ����� �� j � i, ������� ����� �� i � j
				matrix[i][j] = matrix[j][i];
			}// else if (matrix[j][i] != 0) 
		}// for j
	}// for i

	// ���������� ��������� ��������
	return;
}


// ����������� ��������������� ����
void Reverse_Direction(vector<vector<int>>& matrix)              // ������� ��������� �� ������ ��� � ���������
{
	int vertices = matrix.size();
	// ����� ������������� ������� ���������, ���������� � ���������������
	// ������ ��������������� ������� ������� ��� ������� ��������� � ��������� � ������
	vector<vector<int>> transposedMatrix(vertices, vector<int>(vertices, 0));

	// ���������� �� ���� ��������� ����� ������ 
	for (int i = 0; i < vertices; i++) 
	{
		for (int j = 0; j < vertices; j++) 
		{
			// ���������� �������� j-�� ������ i-�� ������� ������ ������� ������������� ������� i-�� ������ j-�� ������� ������� ���������
			transposedMatrix[j][i] = matrix[i][j];
		}// for j
	}// for i

	// ������������� � �������� �������� ������� ���������������
	matrix = transposedMatrix;

	// ���������� ��������� ��������
	return;
}


// �������� ��������
int Kasai(vector<vector<int>>matrix,                              // ������� ���������, � ������� ����� ��������
	      vector<vector<int>>reverse,                             // ������� ���������������� �����
	      vector<int>& recursion,                                 // ������ �������� ������ ��� ������������ ������� �� ������
	      bool print)                                             // ���� �� �������� � ���� ����������
{
	// ���������� ������ � �����
	int size = matrix.size();
	// ���������� ��������� ��� DFS
	vector<int> component;
	// ������� ������ ������ DFS ��� ����������� ������� ������ �� ��������
	vector<int> obx;
	// ������������ �������
	vector<bool> Is_Visited(size);
	// ������� ��������� ���������
	int CountComponent = 0;

	// ��������� ������ ������ ��������
	recursion.resize(size, 0);

	// ������ ������������ ������
	for (int i = 0; i < matrix.size(); i++)
	{
		// �� ���� ������� ��� �� ��������. ���� ����������
		Is_Visited[i] = false;
	}// for i
	
	// ��������� ������� ���������� � ������� ����������� ��������
	// ��������� ��� ������ ������� �����
	for (int i = 0; i < matrix.size(); i++)
	{

		// ��������� �������� ��� ������ ���������� �� �������, � ������� �������� �� ������� ��� ����������. � obx ��������� ������ ���� ������
		if (Is_Visited[i] == false)
		{
			// ���������� ���������� ���������
			DFS(matrix, i, Is_Visited, obx, component);
		}// if (Is_Visited[i] == false)
	}// for i

	// ��������� ������ ��������. ���� ��������� ��������� ������ ������� � ��� ����. ������ ����� ��������� � ����� ����� ������ �� ��������
	// ��������� ����, ������� ����������� �� �������� i �� 0 �� matrix.size() - 1.
	for (int i = 0; i < matrix.size(); i++)
	{
		// � ������ �������� �����, ������� ������ i ������������� ���������� target
		int target = i;
		// ����� ����������� ����� �������� target � �������� ��������� obx. obx ������������ ����� ������, � ����� ����������� � �������� �������.
		auto iter = find(obx.rbegin(), obx.rend(), target);

		// ���� �������� target ������� � ���������� obx, �� ���������� iter ������������� ��������, ����������� �� ��������������� ������� � ����������
		// ���� iter �� ����� ��������� ��������� obx.rend(), ��� ��������, ��� �������� target ���� ������� � ����������.
		if (iter != obx.rend())
		{
			// � ����� ������, ����������� ������ ���������� ��������� �������� target � obx, � ����� ���� ������ ������������� ���������������� �������� � ������� recursion �� ������� i
			int lastIndex = obx.rend() - iter;
			recursion[i] = lastIndex;
		}// if (iter != obx.rend())
	}// for i

	// ������ �������� ��������. �������� � ��������������� ������ ����� ������� Strong
	// �������� � ������� �������� ������� ������
	// ������������� ������ ������ - ��� ������� � ����������� �������� ���������� ������� ���������. ����� �� ���������� - ������ �������

	for (int i = 0; i < matrix.size(); i++)
	{
		// �� ���� ������� ��� �� ��������. ���� ����������
		Is_Visited[i] = false;
	}

	// ���������� ��������� ������� ���������
	CountComponent = 0;
	// ���� ����������� ������ ��� ����������� ������, ����� ��� ������� ����� ���� ���������� ������� ���������
	bool flag = true;
	 // ������� ���� �����������
	while(flag)
	{
		// ���������� ������ ���������� ��������� ��� �������� ��������� ������� ���������
		component.clear();
		// ������� ������ ������ � ����
		obx.clear();
		// ��� ������ ������������ ������� ������, � ������� ����� �������� ������ ����� � � �������
		int Max = 0;
		int index = 0;

		// ��� �� ���� ��������
		for (int i = 0; i < recursion.size(); i++)
		{
			// ���� ����� ������������ ������� - ����� ����� ���������� ��������
			if (Is_Visited[i] == false)
			{
				flag = true;
				break;
			}

			else
			{
				// ���� ��� ������� ��������, �� ���� �����������
				flag = false;
			}// if (Is_Visited[i] == false)
		}// for i

		// ���� ������������ ������� ������ �� �������� �� ������������ ������
		for (int j = 0; j < recursion.size(); j++)
		{
			if (Max < recursion[j] && Is_Visited[j] == false)
			{
				Max = recursion[j];
				index = j;
			}// if (Max < recursion[j] && Is_Visited[j] == false)
		}// for j

		// ��������� ����� � ������� �� ���� ������� - � component ����� ��������� ���������� ������� ���������
		DFS(reverse, index, Is_Visited, obx ,component);

		// ���� ���� �������, ������� ��� �� ��������
		if (flag)
		{
			// ����������� ������� � ���������� ���������
			sort(component.begin(), component.end());
			// ����������� ���������� ��������� ���������
			CountComponent = CountComponent + 1;
			// ������� �� �� ����� � � ����
			if (print)
			{
				fout << " [ ";
			}

			cout << " [ ";
			for (int j = 0; j < component.size(); j++)
			{
				cout << component[j] + 1 << " ";
				if (print)
				{
					fout << component[j] + 1 << " ";
				}

			}// for j
			cout << "] ";

			if (print)
			{
				fout << "] ";
			}
		}// if(flag)

	}// while(flag)

	// ���������� ���������� ��������� ���������
	return CountComponent;
}


// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix)                 // �������, ������� ���������� ������� � ����. �������� �� ��������
{
	// ��� �� ������� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		// ��� �� �������� �������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ��������� ������� ������� � ����
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// ���������� ��������� ��������
	return;
}



/*------------------------------------------------------------------------*/
/*            ������� �������           */
/*--------------------------------------*/
int main()
{
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");
	// ���� ������� - �����
	system("color F0");
	// ���� ������ � ����. ���������� - ������ ���
	bool print = false;
	// ����, �������� ������������� ��� ������
	char letter;
	// ���������� ��������� ��������� ��� �����
	int CountComponents = 0;
	// ���������� ��������� ������ ��������� ��� �������
	int CountLow = 0;
	// ���������� ��������� ������� ��������� ��� �������
	int CountHi = 0;

	cout << "\t\t\t\t\t\t\x1b[34m    � � � � � �   �   � � � � � � �\x1b[30m\n\n\n";
	// ������� ������ �����. ����������� ���������� ��-���������
	Graph NewGraph;

	// �����, ����� �� ������������ �������� � ���� ����������� ����������
	cout << " ������ �� �� �������� ������ � ����? ������� <o>, ���� ������, ��� ����� ������ ������ - ���� ���. �������: ";
	cin >> letter;                             // ���� �������������
	cout << "\n �� �����: " << letter;         // ���-������

	// ���� ������������ ����� ��������. ������������� ����
	if (letter == 'o' || letter == 'O')
	{
		print = true;
		fout.open(FNAMEOUT);           // ��������� ������ � ������
		if (!fout.is_open())           // ���� �� ������
		{
			cout << "����� � ����� ������ ���. ���������� ����������� ������";
			fin.close();               // ������� ���� ��� ������
			system("pause");
			exit(0);                   // ���������� ��������, ��������������� ���� � caller
		}// if (!fout.is_open())

	}// if (letter == 'o' || letter == 'O')

	// ������� ������� ��������� �� ������ �� ����� �� �����
	cout << "\n\n\t\t\t\t\t\x1b[35m � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\x1b[30m\n\n";
	PrintMatrix(NewGraph.adjacency_matrix());

	// ������� ������ ���� � ����
	if (print)
	{
		fout << "\t\t\t\t\t\t    � � � � � �   �   � � � � � � �\n\n\n";
		fout << "\n\n � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\n\n";
		// ������� ������� ��������� � ����
		PrintMatrToFile(NewGraph.adjacency_matrix());
	}


	// ���� ����������������� - ������� ���������� ���������
	if (!NewGraph.is_directed())
	{
		cout << "\n\n\x1b[33m � � � � � �   � � � � � � � � �   � � � � � � � � � :\x1b[30m\n";
		cout << " Connected components: \n";
		cout << " [";

		// ������� ������ ���� � ����
		if (print)
		{
			fout << "\n\n � � � � � �   � � � � � � � � �   � � � � � � � � � :\n";
			fout << " Connected components: \n";
			fout << " [";
		}

		// ���������� ��������� ������� ��� ��������� ������� �� ������. ���� ���������� ��������� �� ����� � �������
		CountComponents = Connectivity_Components(NewGraph.adjacency_matrix(), print);

		cout << "]\n";

		// ������� ������ ���� � ����
		if (print)
		{
			fout << "]\n";
		}

		cout << "\n\n\x1b[36m � � � � �   �   � � � � � � � � �   � � � � � :\x1b[30m\n";
		// ���� ���������� ��������� ���� - ���� �������
		if (CountComponents == 1)
		{
			cout << " Graph is connected.\n";
			if (print)
			{
				fout << "\n\n � � � � �   �   � � � � � � � � �   � � � � � :\n";
				fout << " Graph is connected.\n";
			}
		}
		// ����� - ���� �� ������� � ���������� ��������� ��������� ������� �� 1
		else
		{
			cout << " Graph is not connected and contains " << CountComponents << " connected components.\n";
			if (print)
			{
				fout << "\n\n � � � � �   �   � � � � � � � � �   � � � � � :\n";
				fout << " Graph is not connected and contains " << CountComponents << " connected components.\n";
			}
		}// if (CountComponents == 1)

		// ������� ���������� ��������� ���������
		cout << "\n\n\x1b[31m � � � � � � � � � �   � � � � � � � � �   � � � � � � � � � :\x1b[30m\n";
		cout << " Number of connected components: " << CountComponents << endl;

		if (print)
		{
			// ������� ���������� ��������� ���������
			fout << "\n\n � � � � � � � � � �   � � � � � � � � �   � � � � � � � � � :\n";
			fout << " Number of connected components: " << CountComponents << endl;
		}

	}


	// ���� ���������������
	else
	{
		// ���������� ������ ���������
		// ���� ��������������� �������, � ������� ������� �� ����� ������ ���� �����������������. ������ � �� ����� ��, ��� � �������� �������
		vector<vector<int>> Symmetrical(NewGraph.GetSize());
		// ������ ��������
		vector<int> recursion(NewGraph.GetSize());
		// ��������� ������� �������������� ���������� �������� �������� ���������
		Symmetrical = NewGraph.adjacency_matrix();

		// ������ ������� Symmetrical ������������ - ������� �����������������
		convertToUndirected(Symmetrical);
		cout << "\n\n\t\t\t\t\t\x1b[33m � � � � � � �   � � � � � � � � �   � � � � � � � � � � � � �   � � � � � :\x1b[30m\n\n";
		// ������� ��� ������� �� �����
		PrintMatrix(Symmetrical);

		if (print)
		{
			// ������� ���������� ��������� ���������
			fout << "\n\n\t\t\t\t\t � � � � � � �   � � � � � � � � �   � � � � � � � � � � � � �   � � � � � :\n\n";
			PrintMatrToFile(Symmetrical);
		}

		cout << "\n\n\x1b[36m � � � � � �   � � � � � � � � �   � � � � � � � � �   � � � � � � � � � � � � �   � � � � � :\x1b[30m\n";
		cout << " Connected components: \n";
		cout << " [";

		// ������� ������ ���� � ����
		if (print)
		{
			fout << "\n\n � � � � � �   � � � � � � � � �   � � � � � � � � �   � � � � � � � � � � � � �   � � � � � :\n";
			fout << " Connected components: \n";
			fout << " [";
		}

		// ���� ���������� ������ ��������� - ����� ������� ��������� ��� �����������
		CountLow = Connectivity_Components(Symmetrical, print);

		cout << "]\n";

		// ������� ������ ���� � ����
		if (print)
		{
			fout << "]\n";
		}

		// ���������� ������� ���������
		// ������� ���������������� �����
		vector<vector<int>> Strong(NewGraph.GetSize());
		// ���������� ��������� � ���������� �������� �������
		Strong = NewGraph.adjacency_matrix();
		// ����������� ��� �������
		Reverse_Direction(Strong);
		cout << "\n\n\x1b[35m � � � � � �   � � � � � � � � �   � � � � � � �   � � � � � � � � � :\x1b[30m\n";
		cout << " Strongly connected components: \n";
		cout << " [";

		// ������� ������ ���� � ����
		if (print)
		{
			fout << "\n\n � � � � � �   � � � � � � � � �   � � � � � � �   � � � � � � � � � :\n";
			fout << " Strongly connected components: \n";
			fout << " [";
		}

		// ������� ���������� ������� ���������, ����������� � ������� ��������� ��������
		CountHi = Kasai(NewGraph.adjacency_matrix(), Strong, recursion, print);
		cout << "]\n";

		// ������� ������ ���� � ����
		if (print)
		{
			fout << "]\n";
		}

		cout << "\n\n\x1b[32m � � � � � �   �   � � � � � �   � � � � � � � � �   � � � � � � � :\x1b[30m\n";
		// ����������� ���� �����, ��� ������ �������� ������� - ������� �������� ��� ����������� ���� - ���� ���������� ��������� � ����������� �����
		if (CountLow == 1)
		{
			cout << " Diraph is connected.\n";

			// ������� ������ ���� � ����
			if (print)
			{
				fout << "\n\n � � � � � �   �   � � � � � �   � � � � � � � � �   � � � � � � � :\n";
				fout << " Diraph is connected.\n";
			}
		}
		else
		{
			cout << " Diraph is not connected and contains " << CountLow << " connected components.\n";

			// ������� ������ ���� � ����
			if (print)
			{
				fout << " Diraph is not connected and contains " << CountLow << " connected components.\n";
				fout << " Diraph is connected.\n";
			}
		}// if (CountLow == 1)

		// ������ ����� ������ ������, ���� ���������� ��������� ������� ��������� ���� 1. ����� - �� ������ �����, � ��������� ��������� ������� ���������� �������� 1
		cout << "\n\n\x1b[31m � � � � � �   �   � � � � � � �  � � � � � � � � �   � � � � � � � :\x1b[30m\n";
		if (CountHi == 1)
		{
			cout << " Digraph is strongly connected.\n";

			// ������� ������ ���� � ����
			if (print)
			{
				fout << "\n\n � � � � � �   �   � � � � � � �  � � � � � � � � �   � � � � � � � :\n";
				fout << " Digraph is strongly connected.\n";
			}
		}
		else
		{
			cout << " Digraph is weakly connected and contains " << CountHi << " strongly connected components.";

			// ������� ������ ���� � ����
			if (print)
			{
				fout << "\n\n � � � � � �   �   � � � � � � �  � � � � � � � � �   � � � � � � � :\n";
				fout << " Digraph is weakly connected and contains " << CountHi << " strongly connected components.";
			}
		}// if (CountHi == 1)

		// ����� ������� ��������� ���������������� ����� �� ����� ��� ��������
		cout << "\n\n\n\t\t\t\t\t\x1b[35m � � � � � � �   � � � � � � � � �   � � � � � � � � � � � � � � � �   � � � � � :\x1b[30m\n\n";
		cout << "\n Invert matrix: \n";
		PrintMatrix(Strong);

		if (print)
		{
			fout << "\n\n\n\t\t\t\t\t � � � � � � �   � � � � � � � � �   � � � � � � � � � � � � � � � �   � � � � � :\n\n";
			fout << "\nInvert matrix: \n";
			PrintMatrToFile(Strong);
		}

		// ����� ������� �������� �� ����� ��� ��������
		cout << "\n\x1b[33m � � � � � �   � � � � � � � �   � � � � � �   �   � � � � � � � �   � � � � � :\x1b[30m\n";
		cout << " Vector of recursion: \n";
		cout << " [ ";

		if (print)
		{
			fout << "\n � � � � � �   � � � � � � � �   � � � � � �   �   � � � � � � � �   � � � � � :\n";
			fout << " Vector of recursion: \n";
			fout << " [ ";
		}

		for (int i = 0; i < recursion.size(); i++)
		{
			cout << recursion[i] << " ";
			if (print)
			{
				fout << recursion[i] << " ";
			}
		}// for i
		cout << " ] \n";
		if (print)
		{
			fout << " ] \n";
		}
	}// if (!NewGraph.is_directed())

	// ������� �������� � ������ �� �����
	OpenImage(NewGraph.adjacency_matrix());

	// ���������� ��������� �������� � �������
	return 0;
}