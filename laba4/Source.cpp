#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stack>
#include <vector>
using namespace std;
void dfs_spis(int, const vector<vector<int>>&);
vector<bool> vis(0);

void DFS_f(int** graph, bool* visited, int st, int n)
{
	int r;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= n; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS_f(graph, visited, r, n);
}

void Create_matrix() {
	int start, n, t = clock();

	cout << "Задание 1" << endl;

	cout << "Количество вершин > "; cin >> n;

	bool* visited = new bool[n];

	int** matrix;
	matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; ++i) {
		//matrix[i] = new int[n];
		visited[i] = false;
	}

	int s = 1;
	srand(time(NULL));
	for (int i = 0; i < n; i++) // создание матрицы
	{
		matrix[i] = (int*)malloc(n * sizeof(int));
		matrix[i][i] = 0;
		for (int j = s; j < n; j++)
		{
			if (rand() % 100 > 10)
			{
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = 1;
			}
		}
		s++;
	}
	s = 1;
	for (int i = 0; i < n; i++) // неориентированный граф
	{
		for (int j = s; j < n; j++)
			matrix[j][i] = matrix[i][j];
		s++;
	}
	cout << "Matrix"; // вывод матрицы на экран
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}
	cout << endl;
	cout << "Стартовая вершина > "; cin >> start;
	cout << "Порядок обхода: ";
	DFS_f(matrix, visited, start - 1, n);

	delete[]visited;

	//DFS_stack(matrix, visited, start - 1, n);

	cout << "\nТакты:" << ((float)t / CLOCKS_PER_SEC) << "\n";
	system("pause");
}

void sp_smej() {
	int n, m;
	cout << "Списки смежности" << endl;
	cin >> n >> m; // строки и столбцы

	//иницилизируем список смежности и массив посещенных вершин
	vector<vector<int>> adj_list(n, vector<int>());
	vis.resize(n, false);

	//ввод ребер
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj_list[x - 1].push_back(y - 1);
		adj_list[y - 1].push_back(x - 1);
	}
	cout << endl;

	dfs_spis(0, adj_list); //поиск в глубину

}

void dfs_spis(int u, const vector<vector<int>>& matrix_adjacency) {
	vis[u] = true;
	cout << "in " << u + 1 << endl;
	for (auto i : matrix_adjacency[u])
		if (!vis[i]) dfs_spis(i, matrix_adjacency);
	cout << "out " << u + 1 << endl;
}

/*void vector_matrix() {

	int n;

	vector<vector<int>> mainV;

	cout << "Количество вершин > "; cin >> n;
	cout << endl;

	mainV.resize(n);
	int s = 1;
	for (int i = 0; i < n; i++) {
		mainV[i].resize(n);
		for (int j = s; j < n; j++) {
			if ((rand() % 100) > 10) {
				int temp = 0;
				mainV[i][j] = temp;
			}
			else {
				int temps = 1;
				mainV[i][j] = temps;
			}
		}
		s++;
	}
	s = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = s; j < n; j++) {
			mainV[j][i] = mainV[i][j];
		}
		s++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mainV[i][j] << " ";
		}
		cout << endl;
	}
}*/

/*void DFS_stack(int** graph, bool* visited, int st, int n)
{
	stack<int> S;
	vector<int> v(n);
	int t;
	S.push(n);
	v[n]++;
	cout << n + 1 << " ";
	while (!S.empty())
	{
		t = S.top();
		S.pop();
		for (int i = n - 1; i > 0; i--)
			if (graph[t][i] && !v[i])
			{
				S.push(i);
				v[i]++;
				cout << i + 1 << " ";
			}
	}
}*/

void main()
{
    system("chcp 1251"); system("cls");
	Create_matrix();
	//vector_matrix();
	sp_smej();
}