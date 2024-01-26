/********************************************************************************
 * Л А Б О Р А Т О Р Н А Я   Р А Б О Т А  №2  З А   5   С Е М Е С Т Р   С  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab2                                               *
 * File Name     : Lab2. CPP                                                    *
 * Programmer(s) : Викулов Д.Г.                                                 *
 * Modifyed By   :                                                              *
 * Created       : 19/09/23                                                     *
 * Last Revision : 29/09/23                                                     *
 * Comment(s)    : Программа, определяющая связность. Для графа – связность,    *
 *                 а также количество и состав компонент связности. Для орграфа *
 *                 - сильную, слабую связность, или несвязность. А также        *
 *                 и состав компонент связности и сильной связности.            *
 *                 Для определения используется поиск в ширину. Для алгоритма   *
 *                 Косарайо - поиск в глубину.                                  *
 ********************************************************************************/


#include <iostream>              // стандартные потоки ввода/вывода
#include <vector>                // работа с векторами для удобства быстрого извлечения и удаления элементов
#include <fstream>               // работа с потоками ввода/вывода для файла
#include <iomanip>               // библиотека с модификатором setw
#include <graphviz/gvc.h>        // библиотека Graphviz для графического изображения графа по матрице смежности
#include <opencv2/opencv.hpp>    // заголовок, подтягивающий все функции OpenCv

using namespace std;             // используем пространство имён std



/*******************************************************************/
/*            Г Л О Б А Л Ь Н Ы Е    К О Н С Т А Н Т Ы             */
/*******************************************************************/

// путь к файлу через константный указатель
// Входные файлы
// ТЕСТЫ ДЛЯ МАТРИЦЫ СМЕЖНОСТИ
//const char* FNAMEIN = "matrix_t2_001.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_002.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_003.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_004.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_005.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_006.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_007.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_008.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_009.txt";                // файл с матрицей смежности
const char* FNAMEIN = "matrix_t2_010.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_011.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_012.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_013.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t2_014.txt";                // файл с матрицей смежности

// ТЕСТЫ ДЛЯ СПИСКА РЕБЕР
//const char* FNAMEIN = "list_of_edges_t2_001.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_002.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_003.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_004.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_005.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_006.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_007.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_008.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_009.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_010.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_011.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_012.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_013.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t2_014.txt";         // файл со списком рёбер

// ТЕСТЫ ДЛЯ СПИСКА СМЕЖНОСТИ
//const char* FNAMEIN = "list_of_adjacency_t2_001.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_002.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_003.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_004.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_005.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_006.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_008.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_009.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_011.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_013.txt";     // файл со списком смежности
//const char* FNAMEIN = "list_of_adjacency_t2_014.txt";     // файл со списком смежности

// ВЫХОДНЫЕ ФАЙЛЫ
const char* FNAMEOUT = "Output_File.txt";

// бесконечность для матрицы расстояний
const int INF = 10000;




/*******************************************************************/
/*      Г Л О Б А Л Ь Н Ы Е    Ф А Й Л О В Ы Е    П О Т О К И      */
/*******************************************************************/

 // объявление объекта для потокового ввода данных из файла
ifstream fin;
// объявление объекта для потокового вывода данных в файл
ofstream fout;




/*******************************************************************/
/*                 И Е Р А Р Х И Я   К Л А С С О В                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // граф в программе представлен матрицей смежности
	int m_size;                                               // размер матрицы смежности (количество вершин в графе)

public:
	// конструктор
	Graph();
	// деструктор
	~Graph();
	// константный геттер для получения значения размера
	const int GetSize();
	// функция возвращающая True, если граф ориентированный, False, если граф простой;
	bool is_directed();
	// функция, возвращающая матрицу смежности
	vector<vector<int>> adjacency_matrix();
	// весовая функция, принимает номера вершин, возвращает вес ребра, связывающего их;
	int Weight(int Vi, int Vj);
	// функция, принимающая номера вершин и возвращает True, если в графе есть соответствующее ребро / дуга, False, если ребра нет;
	bool is_edge(int Vi, int Vj);
	// функция, возвращающая список вершин, смежных вершине v;
	vector<int> adjacency_list(int v);
	// функция, возвращающая список всех рёбер графа;
	vector<pair<int, int>> list_of_edges_pairs();
	// – функция, возвращающая список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              П Р О Т О Т И П Ы    Ф У Н К Ц И Й                 */
/*******************************************************************/

// сохранение графа как фотографии
string drawGraph(const vector<vector<int>>& adjacencyMatrix);     // объявление константной ссылки на двумерный вектор adjacencyMatrix, содержащий целочисленные значения 

// вывод графа на экран в виде картинки
void OpenImage(const vector<vector<int>>& adjacencyMatrix);       // объявление константной ссылки на двумерный вектор adjacencyMatrix, содержащий целочисленные значения 

// вывод матрицы смежности на экран
void PrintMatrix(vector<vector<int>> matrix);                     // матрица, которую необходимо вывести на экран. Передача по значению

// печать справки и авторов работы
void Usloviya();

// обход в ширину
void Breadth_First_Search(vector<vector<int>> matrix,             // матрица смежности, с которой будем работать
	                      int StartVertex,                        // стартовая вершина обхода
	                      vector<bool>& Is_Visited,               // вектор посещённых вершин для обхода
	                      vector<int>& component);                // очередная компонента, которую получили при обходе в ширину

// обход в глубину
void DFS(vector<vector<int>> matrix,                              // матрица смежности, с которой будем работать
	     int StartVertex,                                         // стартовая вершина обхода
	     vector<bool>& Visited,                                   // вектор посещённых вершин для обхода
	     vector<int>& obx,                                        // вектор, содержащий все вершины в порядке работы алгоритма
	     vector<int>& component);                                 // очередная компонента, которую получили при обходе в ширину

// компоненты связности графа
int Connectivity_Components(vector<vector<int>> matrix,           // матрица смежности, с которой будем работать
	                        bool print);                          // флаг вывода в файл

// преобразование ориентированного графа в соотнесённый ему
void convertToUndirected(vector<std::vector<int>>& matrix);       // матрица смежности по ссылке для её изменения

// инвертируем ориентированный граф
void Reverse_Direction(vector<vector<int>>& matrix);              // матрица смежности по ссылке для её изменения

// алгоритм Касарайо
int Kasai(vector<vector<int>>matrix,                              // матрица смежности, с которой будем работать
	      vector<vector<int>>reverse,                             // матрица инвертированного графа
	      vector<int>& recursion,                                 // вектор рекурсии вершин для установления времени их выхода
          bool print);                                            // надо ли печатать в файл клмпоненту

// вывод матрицы  в файл
void PrintMatrToFile(vector<vector<int>> matrix);                 // матрица, которую необходимо вывести в файл. Передача по значению



// конструктор - считывание матрицы из файла
Graph::Graph()
{
	fin.open(FNAMEIN);            // связываем объект с файлом
	if (!fin.is_open())           // файл не найден
	{
		cout << "Файла с таким именем нет. Невозможно осуществить чтение";
		fin.close();              // закрыть файл для чтения
		system("pause");
		exit(0);                  // возвращаем значение, соответствующее типу в caller
	}// if (!fin.is_open())

	int value;                    // очередной считываемый символ
	char key;                     // ключ для указания пользователем варианта задания графа в файле
	bool spravka = true;          // ключ для вывода справки на экран
	vector<int> row;              // вектор для считывания промежуточных значений из файла построчно
	vector<vector<int>> matrix;   // вспомогательная матрица смежности

	// повтор ввода задания графа, когда пользователь захотел вывести на экран справку
	while (spravka)
	{
		cout << "\x1b[30m В В Е Д И Т Е   К Л Ю Ч   И Л И   <h>   Д Л Я   В Ы З О В А   П О Д С К А З К И : \x1b[30m";
		// пользователь ввёл ключ для того, чтобы явно указать, каким способом он задал граф
		cin >> key;
		cout << "\n Вы ввели: " << key << endl;

		// в зависимости от значения ключа
		switch (key)
		{
			// работа с матрицей смежности
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   М А Т Р И Ц А   С М Е Ж Н О С Т И\n\n\x1b[30m\n";
			// считываем очередное число из файла
			while (fin >> value)
			{
				// после считывания каждой строки очищаем вектор строки
				row.clear();
				// загоняем в вектор первый считанный элемент от первого while (fin >> value)
				row.push_back(value);
				// считываем все остальные элементы строки, пока не нашли символ её окончания - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// кладем в матрицу считанную строку. Все строки имеют одинаковый размер, так как работаем с матрицей смежности
				m_matrix.push_back(row);

			}// while (fin >> value)

			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// работа со списком рёбер
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   С П И С О К   Р Ё Б Е Р\n\n\x1b[30m\n";

			// считываем значения из файла в вектор
			// в векторе будут находиться с чередованием через три элементы: начальная вершина, конечная вершина и вес ребра
			while (fin >> value)
			{
				// после считывания каждой строки очищаем вектор строки
				row.clear();
				// загоняем в вектор первый считанный элемент от первого while (fin >> value)
				row.push_back(value);
				// считываем все остальные элементы строки, пока не нашли символ её окончания - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// кладем в матрицу считанную строку. Все строки имеют одинаковый размер, так как работаем с матрицей смежности
				m_matrix.push_back(row);
			}// while (fin >> value)

			// закрыть файл чтения
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // размер матрицы смежности
			vector<vector<int>> vec_1(size_m);                // матрица смежности

			for (int i = 0; i < size_m; i++)                  // задаём размер каждой ячейки vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// заполняем матрицу смежности
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 элемент - это вес ребра, если он не указан, то значит он = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// запоминаем матрицу смежности
			m_matrix = vec_1;
			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// работаем со списками смежности
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   С П И С О К   С М Е Ж Н О С Т И\n\n\x1b[30m\n";

			                              // чтение из файла построчно
			string line;
			int rowNumber = 0;            // номер текущей строки

			// чтение построчное
			while (getline(fin, line)) 
			{
				// Если строка пустая, заполняем текущую строку нулями
				if (line.empty()) 
				{
					matrix.push_back(vector<int>(m_size, 0));
				}
				// строка не пустая
				else
				{
					// вектор строки
					vector<int> row;
					// создает поток для чтения значений из строки line. Затем мы можем использовать iss вместе с оператором >> для извлечения значений из строки.
					istringstream iss(line);
					// очередная величина для чтения
					int value;

					// читаем значение из файла и помещаем его в вектор строки
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// помещаем строку в матрицу
					matrix.push_back(row);
				}// if (line.empty()) 

				// увеличиваем номер строки
				rowNumber++;
			}// while (getline(fin, line)) 

			// файл прочитан - закрываем его
			fin.close();

			m_size = matrix.size();                         // размер матрицы смежности

			vector<vector<int>> vec_1(m_size);              // доп матрица смежности размером m_size

			for (int i = 0; i < m_size; i++)                // задаём размер каждой ячейки доп матрицы смежности
			{
				// заполняем вспомогательную матрицу нулями по всему размеру
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // заполняем доп матрицу смежности 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// единица в тех столбцах, которые перечислены для данной в файле
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// загоняем значения в основную матрицу смежности
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// пользователь выбрал справку
		case('h'):
		case('H'):
		{
			// повторить ввод после появления мправки на экране
			spravka = true;
			// выводим условия
			Usloviya();
			break;
		}

		// иначе - пользователь ввёл не тот ключ. Заканчиваем программу с ошибкой
		default:
			cout << "\n\x1b[31m ПЕРЕЗАПУСТИТЕ ПРОГРАММУ И ВВЕДИТЕ ЗНАЧЕНИЕ ИЗ СПИСКА КЛЮЧЕЙ!!!\n\x1b[30m";
			// закрываем файл считывания
			fin.close();
			exit(0);
		}
	}
	// закрываем файл считывания
	fin.close();
	// запоминаем размер считанной/ преобразованной матрицы смежности
	m_size = m_matrix.size();
}

// деструктор
Graph::~Graph()
{
	// пустое тело - векторы уничтожаются автоматически
}

// геттер для получения значения размера
const int Graph::GetSize()
{
	return(m_size);
}


// функция возвращающая True, если граф ориентированный, False, если граф простой;
bool Graph::is_directed()
{
	// идём по строкам
	for (int i = 0; i < m_size; i++)
	{
		// идём по столбцам
		for (int j = 0; j < m_size; j++)
		{
			// если граф неориентированный, то матрица симметрична, так как по ребру можно пройти подвум направлениям
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // Найдено направленное ребро - граф ориентированный
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // Не найдено направленных ребер - граф неориентированный
}


// функция, возвращающая матрицу смежности
vector<vector<int>> Graph::adjacency_matrix()
{
	return(m_matrix);
}


// весовая функция, принимает номера вершин, возвращает вес ребра, связывающего их;
int Graph::Weight(int Vi, int Vj)

{
	// номера вершин вышли за диапазоны допустимых значений
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "Ошибка! Такой вершины не существует\n";
		// вернули ошибку
		return(-1);
	}

	// если путь существует(в матрице смежности не 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "Вес ребра между вершинами " << Vi << " и " << Vj << " равен" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// возвращаем вес ребра между вершинами
		return(m_matrix[Vi][Vj]);
	}

	// граф ориентированный. Выводим вес дуги
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "Граф ориентированный. Дуга есть. Направление учитывается. Вес дуги между вершинами " << Vi << " и " << Vj << " равен" << m_matrix[Vi][Vj] << endl;
		// возвращаем вес дуги
		return(m_matrix[Vi][Vj]);
	}

	// ребра между вершинами нет - элемент матрицы смежности равен 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "Ребра между вершинами " << Vi << " и " << Vj << "нет\n";
		// Вернули нулевое значение
		return(m_matrix[Vi][Vj]);
	}

	return(0);
}


// функция, принимающая номера вершин и возвращает True, если в графе есть соответствующее ребро / дуга, False, если ребра нет;
bool Graph::is_edge(int Vi, int Vj)
{
	// номера вершин вышли за диапазоны допустимых значений - дуги нет
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// вернули, что дуги нет
		return(false);
	}

	// элемент матрицы смежности не равен 0 - ребро есть
	if (m_matrix[Vi][Vj] != 0)
	{
		// подтверждаем, что ребро есть
		return(true);
	}

	// элемент матрицы смежности нулевой - ребра нет
	if (m_matrix[Vi][Vj] == 0)
	{
		// подтверждаем, что ребра нет
		return(false);
	}

}


// функция, возвращающая список вершин, смежных вершине v;
vector<int> Graph::adjacency_list(int v)
{
	// список вершин
	vector<int> adjList;

	// Проходим по всем вершинам и проверяем, есть ли ребро между вершиной v и текущей вершиной
	for (int i = 0; i < m_size; i++)
	{
		// путь есть - элемент матрицы не нулевой
		if (m_matrix[v][i] != 0)
		{
			// помещаем вершину в список
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// Возвращаем список смежных вершин
	return adjList;
}


// функция, возвращающая список всех рёбер графа;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// вектор пар, содержащий ребро в виде двух инцидентных ему вершин
	vector<pair<int, int>> edges_pairs;
	// идём по всем элементам строки
	for (int i = 0; i < m_size; i++)
	{
		// идём по всем элементам столбца
		for (int j = 0; j < m_size; j++)
		{
			// если элемент не нулевой
			if (m_matrix[i][j] != 0)
			{
				// загрузили пару вершин
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i

	// вернули вектор рёбер (пар вершин)
	return(edges_pairs);
}


// функция, возвращающая список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // вектор пар вершин(вектор рёбер)
	vector<pair<int, int>> edges_inc;     // вектор рёбер инцидентных вершине v / исходящих из вершины v
	edges = list_of_edges_pairs();        // получаем все пары вершин графа

	// обходим эти пары. Если граф неориентированный, то там будет пара (v,n) и (n, v) - достаточно рассмотреть для инцидентности первый элемент. В орграфе - исходящий элемент всегда первый
	for (int i = 0; i < edges.size(); i++)
	{
		// рассматриваем первый элемент пары
		if (edges[i].first == v)
		{
			// помещаем в списо ребер, инцидентных вершине данное ребро
			edges_inc.push_back(edges[i]);
			// увеличиваем счётчик
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// возвращаем  список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                Функции               */
/*--------------------------------------*/

// сохранение графа как фотографии
string drawGraph(const vector<vector<int>>& adjacencyMatrix)
{
	// Проверяем размер матрицы смежности. Если больше 19, то считаем ее слишком большой
	if (adjacencyMatrix.size() <= 19)
	{
		bool key = false;
		// Проверяем наличие весов на ребрах, чтобы понять, нужно ли указывать их при выводе
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// Если вес ребра больше 1 или отрицательный, значит, нужно указывать вес в выводе
				if (adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
					key = true;
			}
		}

		// Открываем файл для записи графа в формате DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// Выводим граф с указанием весов ребер
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Проверяем, что вес ребра не равен 0, чтобы не выводить ненужные ребра
					if (adjacencyMatrix[i][j] != 0)
					{
						// Выводим ребро с указанием веса в формате DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// Выводим граф без указания весов ребер
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Проверяем, что вес ребра равен 1, чтобы не выводить ненужные ребра
					if (adjacencyMatrix[i][j] == 1)
					{
						// Выводим ребро без указания веса в формате DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// Закрываем файл и сохраняем результаты
		file << "}" << std::endl;
		file.close();

		// Генерируем изображение графа в формате PNG с помощью утилиты DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\nGraph image saved as graph.png" << endl;
	}

	// Выводим, что граф большой для рисования
	else
	{
		cout << "\n\nGraph image is not saved as graph.png. It is too big" << endl;
	}
	// возвращаем картинку для открытия силами OpenCV
	return "graph.png";
}


// вывод графа на экран
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// Проверяем размерность матрицы смежности
	if (adjacencyMatrix.size() <= 19)
	{
		// Получаем путь к изображению, созданному с помощью функции drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// Загружаем изображение с помощью OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// Проверяем, удалось ли загрузить изображение
		if (img.empty()) {
			cout << "Could not open or find the image" << endl;
			return;
		}

		// Создаем окно с названием "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// Показываем изображение в окне
		cv::imshow("Graph", img);
		// Ждем, пока пользователь нажмет любую клавишу
		cv::waitKey(0);
		// Закрываем окно
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
}


// вывод матрицы смежности на экран
void PrintMatrix(vector<vector<int>> matrix)
{
	// отключаем русский язык
	setlocale(0, "C");            // выводим массив в красивых скобках
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // вывод верхних квадратных скобок

	// идём по строкам
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// идём по столбцам
		for (int j = 0; j < matrix.size(); j++)
		{
			// выводим элемент матрицы
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // вывод верхних квадрат
	// подключаем русский язык
	setlocale(LC_ALL, "Russian");

	// возвращаем обещанное значение
	return;
}


// печать справки и авторов работы
void Usloviya()
{
	cout << "\n\t\t\t\t/********************************************************************************\n";
	cout << "\t\t\t\t* Л А Б О Р А Т О Р Н А Я   Р А Б О Т А  №2  З А   5   С Е М Е С Т Р   С  +  +  *\n";
	cout << "\t\t\t\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                     *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab2                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab2. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : Викулов Д.Г.                                                  *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                               *\n";
	cout << "\t\t\t\t* Created       : 19/09/23                                                      *\n";
	cout << "\t\t\t\t* Last Revision : 28/09/23                                                      *\n";
	cout << "\t\t\t\t********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   С П Р А В К А : \n\n\x1b[30m";
	// Выводим условия в таблице
	setlocale(0, "C");                       // отключаем русский язык
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // выводим верхнюю строку шапки
	setlocale(LC_ALL, "Rus");                // подключаем русский язык
	cout << " Выберите одно значние из списка:      ";
	setlocale(0, "C");                       // отключаем русский язык
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // выводим нижнюю строку шапки с разделителем между номером и названием алгоритма
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // выводим условия выбора и нижнюю с боковыми строчками таблицы
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // подключаем русский язык
	
	return;                                 // возвращаем обещанное значение
}


// поиск в ширину
void Breadth_First_Search(vector<vector<int>> matrix,             // матрица смежности, с которой будем работать
	                      int StartVertex,                        // стартовая вершина обхода
	                      vector<bool>& Is_Visited,               // вектор посещённых вершин для обхода
	                      vector<int>& component)                 // очередная компонента, которую получили при обходе в ширину

{
	vector<int> queque;                                           // отработанные вершины в очереди
	int CurVert = 0;                                              // текущая рассматриваемая вершина
	component.clear();                                            // при каждом новом вызове очищаем компоненту связности
	
	// помещаем вершину, с которой начали обход, в очередь
	queque.push_back(StartVertex);

	// первая вершина - посещена
	Is_Visited[StartVertex] = true;
	
	// пока очередь из вершин не пуста
	while (!queque.empty())
	{
		CurVert = queque.front();              // получаем очередной первый элемент очереди
		component.push_back(CurVert);          // помещаем его в компоненту - он в неё входит
		queque.erase(queque.begin());          // Удаляем очередной первый элемент из очереди

		// идём по всем столбцам строки CurVert
		for (int j = 0; j < matrix.size(); j++)
		{
			// если существует путь из данной вершины в соседнюю, и эта соседняя вершина - не посещена
			if (matrix[CurVert][j] != 0 && Is_Visited[j] == false)
			{
				// добавляем её в очередь
				queque.push_back(j);
				// помечаем эту вершину как посещённую
				Is_Visited[j] = true;
			}// if (matrix[CurVert][j] != 0 && Is_Visited[j] == false)
		}// for j
	}// while (!queque.empty())

	// возвращаем обещанное значение
	return;
}


// обход в глубину
void DFS(vector<vector<int>> matrix,                              // матрица смежности, с которой будем работать
	     int StartVertex,                                         // стартовая вершина обхода
	     vector<bool>& Visited,                                   // вектор посещённых вершин для обхода
	     vector<int>& obx,                                        // вектор, содержащий все вершины в порядке работы алгоритма
	     vector<int>& component)                                  // очередная компонента, которую получили при обходе в ширину
{
	Visited[StartVertex] = true;                                  // отмечаем вершину как посещённую
	component.push_back(StartVertex);                             // заносим вершину в вектор посещённых
	obx.push_back(StartVertex);                                   // отмечаем текущую вершину, в которой находимся как очередную вершину в пути обхода по прямому пути ребра

	// проходимся по всем столбцам строки StartVertex
	for (int i = 0; i < matrix.size(); i++)
	{
		// если есть путь в другую непосещённую вершину
		if (matrix[StartVertex][i] != 0 && Visited[i] == false)
		{
			// рекурсивно вызываем обход для дочерней вершины
			DFS(matrix, i, Visited, obx, component);
			// заносим вершины на обратном пути по ребру в порядке рекурсии
			obx.push_back(StartVertex);
		}// if (matrix[StartVertex][i] != 0 && Visited[i] == false)

	}// for i

	// возвращаем обещанное значение
	return;
}


// компоненты связности графа
// компоненты связности графа
int Connectivity_Components(vector<vector<int>> matrix,           // матрица смежности, с которой будем работать
	                        bool print)                           // флаг вывода в файл
{
	vector<int> component;                                       // очередная компонента связности
	vector<bool> Is_Visited(matrix.size());                      // посещённость вершины. Размер совпадает с количеством вершин 
	int CountComponents = 0;                                     // подсчёт компонент связности
	
	// изначально не посещена ни одна вершина
	for (int i = 0; i < matrix.size(); i++)
	{
		// ни одна вершина ещё не посещена. Этап подготовки
		Is_Visited[i] = false;
	}

	// проверяем для каждой вершины графа
	for (int i = 0; i < matrix.size(); i++)
	{
		// начальной вершиной для обхода выбирается та вершина, в которой алгоритм не побывал при предыдущем выполнении
		if (Is_Visited[i] == false)
		{
			// Обходим в ширину граф с вершины i, которая при предыдущем обходе не была посещена
			Breadth_First_Search(matrix, i, Is_Visited, component);
			// после обхода увеличиваем число компонент связности
			CountComponents = CountComponents + 1;
			// отсортируем вершины в компоненте связности
			sort(component.begin(), component.end());

			// выведем их на экран
			cout << " [ ";
			if (print)
			{
				fout << " [ ";
			}// if(print)

			// выводим все элементы очередой компоненты
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

	// возвращаем количество компонент связности
	return(CountComponents);
}


// преобразование ориентированного графа в соотнесённый ему
void convertToUndirected(vector<std::vector<int>>& matrix)        // матрица смежности по ссылке для её изменения
{
	// Проходим по каждому элементу матрицы и делаем ее симметричной
	int size = matrix.size();
	// идём по строкам
	for (int i = 0; i < size; i++) 
	{
		// по столбцам, начиная с i+1-го
		for (int j = i + 1; j < size; j++)
		{
			if (matrix[i][j] != 0) 
			{
				// Если есть ребро из i в j, создаем ребро из j в i
				matrix[j][i] = matrix[i][j];
			}// if (matrix[i][j] != 0) 

			else if (matrix[j][i] != 0) 
			{
				// Если есть ребро из j в i, создаем ребро из i в j
				matrix[i][j] = matrix[j][i];
			}// else if (matrix[j][i] != 0) 
		}// for j
	}// for i

	// возвращаем обещанное значение
	return;
}


// инвертируем ориентированный граф
void Reverse_Direction(vector<vector<int>>& matrix)              // матрица смежности по ссылке для её изменения
{
	int vertices = matrix.size();
	// чтобы инвертировать матрицу смежности, достаточно её транспонировать
	// создаём вспомогательную матрицу размера как матрица смежности и заполняем её нулями
	vector<vector<int>> transposedMatrix(vertices, vector<int>(vertices, 0));

	// проходимся по всем элементам обеих матриц 
	for (int i = 0; i < vertices; i++) 
	{
		for (int j = 0; j < vertices; j++) 
		{
			// очередному элементу j-ой строки i-го столбца первой матрицы устанавливаем элемент i-ой строки j-го столбца матрицы смежности
			transposedMatrix[j][i] = matrix[i][j];
		}// for j
	}// for i

	// устанавливаем в качестве основной матрицы вспомогательную
	matrix = transposedMatrix;

	// возвращаем обещанное значение
	return;
}


// алгоритм Касарайо
int Kasai(vector<vector<int>>matrix,                              // матрица смежности, с которой будем работать
	      vector<vector<int>>reverse,                             // матрица инвертированного графа
	      vector<int>& recursion,                                 // вектор рекурсии вершин для установления времени их выхода
	      bool print)                                             // надо ли печатать в файл клмпоненту
{
	// количество вершин в графе
	int size = matrix.size();
	// компонента связности для DFS
	vector<int> component;
	// порядок обхода вершин DFS для определения времени выхода из рекурсии
	vector<int> obx;
	// посещённость вершины
	vector<bool> Is_Visited(size);
	// подсчёт компонент связности
	int CountComponent = 0;

	// заполняем нулями массив рекурсии
	recursion.resize(size, 0);

	// вектор посещённости вершин
	for (int i = 0; i < matrix.size(); i++)
	{
		// ни одна вершина ещё не посещена. Этап подготовки
		Is_Visited[i] = false;
	}// for i
	
	// Стартовая вершина выбирается в порядке возрастания индексов
	// проверяем для каждой вершины графа
	for (int i = 0; i < matrix.size(); i++)
	{

		// начальной вершиной для обхода выбирается та вершина, в которой алгоритм не побывал при выполнении. В obx накопится полный путь обхода
		if (Is_Visited[i] == false)
		{
			// определяем компоненту связности
			DFS(matrix, i, Is_Visited, obx, component);
		}// if (Is_Visited[i] == false)
	}// for i

	// заполняем вектор рекурсии. Ищем последнее вхождение каждой вершины в наш путь. Индекс этого вхождения и будет номер выхода из рекурсии
	// Создается цикл, который итерируется по индексам i от 0 до matrix.size() - 1.
	for (int i = 0; i < matrix.size(); i++)
	{
		// В каждой итерации цикла, текущий индекс i присваивается переменной target
		int target = i;
		// Затем выполняется поиск значения target в обратном диапазоне obx. obx представляет собой вектор, и поиск выполняется в обратном порядке.
		auto iter = find(obx.rbegin(), obx.rend(), target);

		// Если значение target найдено в контейнере obx, то переменной iter присваивается итератор, указывающий на соответствующий элемент в контейнере
		// Если iter не равен обратному итератору obx.rend(), это означает, что значение target было найдено в контейнере.
		if (iter != obx.rend())
		{
			// В таком случае, вычисляется индекс последнего вхождения значения target в obx, а затем этот индекс присваивается соответствующему элементу в массиве recursion по индексу i
			int lastIndex = obx.rend() - iter;
			recursion[i] = lastIndex;
		}// if (iter != obx.rend())
	}// for i

	// Вектор рекурсии заполнен. Работаем с инвертированным графом через матрицу Strong
	// Работаем в порядке убывания пометок вершин
	// рассматриваем худший случай - все вершины в отдельности образуют компоненты сильной связности. Тогда их количество - размер матрицы

	for (int i = 0; i < matrix.size(); i++)
	{
		// ни одна вершина ещё не посещена. Этап подготовки
		Is_Visited[i] = false;
	}

	// Количество компонент сильной связности
	CountComponent = 0;
	// флаг продолжения обхода для определения случая, когда все вершины нашли свои компоненты сильной связности
	bool flag = true;
	 // смотрим флаг продолжения
	while(flag)
	{
		// используем вектор компоненты связности для хранения компонент сильной связности
		component.clear();
		// очищаем массив вершин в пути
		obx.clear();
		// для поиска максимальной степени выхода, с которой будем начинать данный обход и её индекса
		int Max = 0;
		int index = 0;

		// Идём по всем вершинам
		for (int i = 0; i < recursion.size(); i++)
		{
			// если нашли непосещённую вершину - имеет смысл продолжать алгоритм
			if (Is_Visited[i] == false)
			{
				flag = true;
				break;
			}

			else
			{
				// если все вершины посещены, то цикл завершается
				flag = false;
			}// if (Is_Visited[i] == false)
		}// for i

		// ищем максимальную степень выхода из рекурсии из непосещённых вершин
		for (int j = 0; j < recursion.size(); j++)
		{
			if (Max < recursion[j] && Is_Visited[j] == false)
			{
				Max = recursion[j];
				index = j;
			}// if (Max < recursion[j] && Is_Visited[j] == false)
		}// for j

		// запускаем обход в глубину из этой вершины - в component будет храниться компонента сильной связности
		DFS(reverse, index, Is_Visited, obx ,component);

		// если есть вершины, которые ещё не посещены
		if (flag)
		{
			// отсортируем вершины в компоненте связности
			sort(component.begin(), component.end());
			// увеличиваем количество компонент связности
			CountComponent = CountComponent + 1;
			// выведем их на экран и в файл
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

	// возвращаем количество компонент связности
	return CountComponent;
}


// вывод матрицы  в файл
void PrintMatrToFile(vector<vector<int>> matrix)                 // матрица, которую необходимо вывести в файл. Передача по значению
{
	// идём по строкам матрицы
	for (int i = 0; i < matrix.size(); i++)
	{
		// идём по столбцам матрицы
		for (int j = 0; j < matrix.size(); j++)
		{
			// выводим очередной элемент матрицы в файл
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// возвращаем обещанное значение
	return;
}



/*------------------------------------------------------------------------*/
/*            Главная функция           */
/*--------------------------------------*/
int main()
{
	// подключаем русский язык
	setlocale(LC_ALL, "Russian");
	// цвет консоли - белый
	system("color F0");
	// флаг печати в файл. Изначально - печати нет
	bool print = false;
	// ключ, введённый пользователем для печати
	char letter;
	// количество компонент связности для графа
	int CountComponents = 0;
	// количество компонент слабой связности для орграфа
	int CountLow = 0;
	// количество компонент сильной связности для орграфа
	int CountHi = 0;

	cout << "\t\t\t\t\t\t\x1b[34m    Р А Б О Т А   С   Г Р А Ф А М И\x1b[30m\n\n\n";
	// создали объект графа. Конструктор применился по-умолчанию
	Graph NewGraph;

	// Выбор, хочет ли пользователь выводить в файл вычесленную информацию
	cout << " Хотите ли Вы выводить данные в файл? Введите <o>, если хотите, или любой другой символ - если нет. Введите: ";
	cin >> letter;                             // ввод пользователем
	cout << "\n Вы ввели: " << letter;         // эхо-печать

	// Если пользователь хочет печатать. Устанавливаем флаг
	if (letter == 'o' || letter == 'O')
	{
		print = true;
		fout.open(FNAMEOUT);           // связываем объект с файлом
		if (!fout.is_open())           // файл не найден
		{
			cout << "Файла с таким именем нет. Невозможно осуществить чтение";
			fin.close();               // закрыть файл для чтения
			system("pause");
			exit(0);                   // возвращаем значение, соответствующее типу в caller
		}// if (!fout.is_open())

	}// if (letter == 'o' || letter == 'O')

	// Выводим матрицу смежности по данным из файла на экран
	cout << "\n\n\t\t\t\t\t\x1b[35m М А Т Р И Ц А   С М Е Ж Н О С Т И   П О   И С Х О Д Н Ы М   Д А Н Н Ы М :\x1b[30m\n\n";
	PrintMatrix(NewGraph.adjacency_matrix());

	// выводим данные выше в файл
	if (print)
	{
		fout << "\t\t\t\t\t\t    Р А Б О Т А   С   Г Р А Ф А М И\n\n\n";
		fout << "\n\n М А Т Р И Ц А   С М Е Ж Н О С Т И   П О   И С Х О Д Н Ы М   Д А Н Н Ы М :\n\n";
		// выводим матрицу смежности в файл
		PrintMatrToFile(NewGraph.adjacency_matrix());
	}


	// граф неориентированный - выводим компоненты связности
	if (!NewGraph.is_directed())
	{
		cout << "\n\n\x1b[33m С О С Т А В   К О М П О Н Е Н Т   С В Я З Н О С Т И :\x1b[30m\n";
		cout << " Connected components: \n";
		cout << " [";

		// выводим данные выше в файл
		if (print)
		{
			fout << "\n\n С О С Т А В   К О М П О Н Е Н Т   С В Я З Н О С Т И :\n";
			fout << " Connected components: \n";
			fout << " [";
		}

		// количество компонент вернётся как результат функции их поиска. Сами компоненты выводятся на экран в функции
		CountComponents = Connectivity_Components(NewGraph.adjacency_matrix(), print);

		cout << "]\n";

		// выводим данные выше в файл
		if (print)
		{
			fout << "]\n";
		}

		cout << "\n\n\x1b[36m В Ы В О Д   О   С В Я З Н О С Т И   Г Р А Ф А :\x1b[30m\n";
		// если коспонента связности одна - граф связный
		if (CountComponents == 1)
		{
			cout << " Graph is connected.\n";
			if (print)
			{
				fout << "\n\n В Ы В О Д   О   С В Я З Н О С Т И   Г Р А Ф А :\n";
				fout << " Graph is connected.\n";
			}
		}
		// иначе - граф не связный и количсетво компонент связности отлично от 1
		else
		{
			cout << " Graph is not connected and contains " << CountComponents << " connected components.\n";
			if (print)
			{
				fout << "\n\n В Ы В О Д   О   С В Я З Н О С Т И   Г Р А Ф А :\n";
				fout << " Graph is not connected and contains " << CountComponents << " connected components.\n";
			}
		}// if (CountComponents == 1)

		// выводим количество компонент связности
		cout << "\n\n\x1b[31m К О Л И Ч Е С Т В О   К О М П О Н Е Н Т   С В Я З Н О С Т И :\x1b[30m\n";
		cout << " Number of connected components: " << CountComponents << endl;

		if (print)
		{
			// выводим количество компонент связности
			fout << "\n\n К О Л И Ч Е С Т В О   К О М П О Н Е Н Т   С В Я З Н О С Т И :\n";
			fout << " Number of connected components: " << CountComponents << endl;
		}

	}


	// граф ориентированный
	else
	{
		// компоненты слабой связности
		// ведём вспомогательную матрицу, с помощью которой мы будем делать граф неориентированным. Размер у неё такой же, как у исходной матрицы
		vector<vector<int>> Symmetrical(NewGraph.GetSize());
		// вектор рекурсии
		vector<int> recursion(NewGraph.GetSize());
		// заполняем матрицу симметричности изначально исходной матрицей смежности
		Symmetrical = NewGraph.adjacency_matrix();

		// делаем матрицу Symmetrical симметричной - убираем ориентированность
		convertToUndirected(Symmetrical);
		cout << "\n\n\t\t\t\t\t\x1b[33m М А Т Р И Ц А   С М Е Ж Н О С Т И   С О О Т Н Е С Ё Н Н О Г О   Г Р А Ф А :\x1b[30m\n\n";
		// выводим эту матрицу на экран
		PrintMatrix(Symmetrical);

		if (print)
		{
			// выводим количество компонент связности
			fout << "\n\n\t\t\t\t\t М А Т Р И Ц А   С М Е Ж Н О С Т И   С О О Т Н Е С Ё Н Н О Г О   Г Р А Ф А :\n\n";
			PrintMatrToFile(Symmetrical);
		}

		cout << "\n\n\x1b[36m С О С Т А В   К О М П О Н Е Н Т   С В Я З Н О С Т И   С О О Т Н Е С Ё Н Н О Г О   Г Р А Ф А :\x1b[30m\n";
		cout << " Connected components: \n";
		cout << " [";

		// выводим данные выше в файл
		if (print)
		{
			fout << "\n\n С О С Т А В   К О М П О Н Е Н Т   С В Я З Н О С Т И   С О О Т Н Е С Ё Н Н О Г О   Г Р А Ф А :\n";
			fout << " Connected components: \n";
			fout << " [";
		}

		// ищем компоненты слабой связности - через матрицу связности без направлений
		CountLow = Connectivity_Components(Symmetrical, print);

		cout << "]\n";

		// выводим данные выше в файл
		if (print)
		{
			fout << "]\n";
		}

		// компоненты сильной связности
		// матрица инвертированного графа
		vector<vector<int>> Strong(NewGraph.GetSize());
		// изначально заполняем её элементами исходной матрицы
		Strong = NewGraph.adjacency_matrix();
		// инвертируем эту матрицу
		Reverse_Direction(Strong);
		cout << "\n\n\x1b[35m С О С Т А В   К О М П О Н Е Н Т   С И Л Ь Н О Й   С В Я З Н О С Т И :\x1b[30m\n";
		cout << " Strongly connected components: \n";
		cout << " [";

		// выводим данные выше в файл
		if (print)
		{
			fout << "\n\n С О С Т А В   К О М П О Н Е Н Т   С И Л Ь Н О Й   С В Я З Н О С Т И :\n";
			fout << " Strongly connected components: \n";
			fout << " [";
		}

		// выводим компоненты сильной связности, вычисленные с помощью алгоритма Касарайо
		CountHi = Kasai(NewGraph.adjacency_matrix(), Strong, recursion, print);
		cout << "]\n";

		// выводим данные выше в файл
		if (print)
		{
			fout << "]\n";
		}

		cout << "\n\n\x1b[32m В Ы В О Д Ы   О   С Л А Б О Й   С В Я З Н О С Т И   О Р Г Р А Ф А :\x1b[30m\n";
		// констатация того факта, что орграф является связным - связным является его соотнесённый граф - одна компонента связности в соотнесённом графе
		if (CountLow == 1)
		{
			cout << " Diraph is connected.\n";

			// выводим данные выше в файл
			if (print)
			{
				fout << "\n\n В Ы В О Д Ы   О   С Л А Б О Й   С В Я З Н О С Т И   О Р Г Р А Ф А :\n";
				fout << " Diraph is connected.\n";
			}
		}
		else
		{
			cout << " Diraph is not connected and contains " << CountLow << " connected components.\n";

			// выводим данные выше в файл
			if (print)
			{
				fout << " Diraph is not connected and contains " << CountLow << " connected components.\n";
				fout << " Diraph is connected.\n";
			}
		}// if (CountLow == 1)

		// орграф будет сильно связан, если количество компонент сильной связности рано 1. Иначе - он связан слабо, и количесво компонент сильной связнотсти больльше 1
		cout << "\n\n\x1b[31m В Ы В О Д Ы   О   С И Л Ь Н О Й  С В Я З Н О С Т И   О Р Г Р А Ф А :\x1b[30m\n";
		if (CountHi == 1)
		{
			cout << " Digraph is strongly connected.\n";

			// выводим данные выше в файл
			if (print)
			{
				fout << "\n\n В Ы В О Д Ы   О   С И Л Ь Н О Й  С В Я З Н О С Т И   О Р Г Р А Ф А :\n";
				fout << " Digraph is strongly connected.\n";
			}
		}
		else
		{
			cout << " Digraph is weakly connected and contains " << CountHi << " strongly connected components.";

			// выводим данные выше в файл
			if (print)
			{
				fout << "\n\n В Ы В О Д Ы   О   С И Л Ь Н О Й  С В Я З Н О С Т И   О Р Г Р А Ф А :\n";
				fout << " Digraph is weakly connected and contains " << CountHi << " strongly connected components.";
			}
		}// if (CountHi == 1)

		// вывод матрицы смежности инвертированного графа на экран для проверки
		cout << "\n\n\n\t\t\t\t\t\x1b[35m М А Т Р И Ц А   С М Е Ж Н О С Т И   И Н В Е Р Т И Р О В А Н Н О Г О   Г Р А Ф А :\x1b[30m\n\n";
		cout << "\n Invert matrix: \n";
		PrintMatrix(Strong);

		if (print)
		{
			fout << "\n\n\n\t\t\t\t\t М А Т Р И Ц А   С М Е Ж Н О С Т И   И Н В Е Р Т И Р О В А Н Н О Г О   Г Р А Ф А :\n\n";
			fout << "\nInvert matrix: \n";
			PrintMatrToFile(Strong);
		}

		// вывод вектора рекурсии на экран для проверки
		cout << "\n\x1b[33m В Е К Т О Р   Р Е К У Р С И И   В Е Р Ш И Н   В   И С Х О Д Н О М   Г Р А Ф Е :\x1b[30m\n";
		cout << " Vector of recursion: \n";
		cout << " [ ";

		if (print)
		{
			fout << "\n В Е К Т О Р   Р Е К У Р С И И   В Е Р Ш И Н   В   И С Х О Д Н О М   Г Р А Ф Е :\n";
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

	// Выводим картинку с графом на экран
	OpenImage(NewGraph.adjacency_matrix());

	// возвращаем обещанное значение в функцию
	return 0;
}