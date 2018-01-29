// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Vertex
{
	int number;
	int weight;
	vector<Vertex*> nearVertexes;
	vector<int> edgeWeight;

	bool free = false;
};

void criticalWay(vector<int>* path, int* length, Vertex top);
void copyVector(vector<int>* dest, vector<int> source);
bool condition(vector<Vertex*> tops);

int main()
{
	//вводим количество вершин и ребер между ними
	int nTops, nEdges;
	cin >> nTops >> nEdges;
	vector<int> weightTops;

	int** adjacencyMatrix = new int*[nTops];
	for (int i = 0; i < nTops; i++)
	{
		adjacencyMatrix[i] = new int[nTops];

		for (int j = 0; j < nTops; j++)
		{
			adjacencyMatrix[i][j] = -1;
		}
	}

	//вводим вершини, величину ребра и соседнюю вершину
	for (int i = 0; i < nEdges; i++)
	{
		int num, weightEdge, neightbour;
		cin >> num >> weightEdge >> neightbour;
		adjacencyMatrix[num][neightbour] = weightEdge;
	}

	//вводим вес вершины
	for (int i = 0; i < nTops; i++)
	{
		int weight;
		cin >> weight;
		weightTops.push_back(weight);
	}

	vector<Vertex*> tops(nTops);

	for (int i = 0; i < nTops; i++)
	{
		for (int j = 0; j < nTops; j++)
		{
			if (tops[i] == nullptr)
				tops[i] = new Vertex();

			tops[i]->number = i;
			tops[i]->weight = weightTops[i];

			if (adjacencyMatrix[i][j] > -1)
			{
				if (tops[j] == nullptr)
					tops[j] = new Vertex();

				tops[i]->nearVertexes.push_back(tops[j]);
				tops[i]->edgeWeight.push_back(adjacencyMatrix[i][j]);
			}
		}
	}


	while (condition(tops))
	{
		vector<int> criticalPath;
		int maxLength = 0;

		//для каждой вершиный находим путь
		for (int i = 0; i < nTops; i++)
		{
			if (tops[i]->free)
				continue;

			vector<int> path;
			int length = 0;
			//углубляемся рекурсивно в поиск пути
			criticalWay(&path, &length, *tops[i]);

			//если нашли путь с больший путь, то копируем его в критический
			if (length > maxLength)
			{
				maxLength = length;
				copyVector(&criticalPath, path);
			}
		}

		//производим операцию однуления
		for (int i = 0; i < criticalPath.size(); i++)
		{
			tops[criticalPath[i]]->free = true;
		}

		for (int i = 1; i < criticalPath.size(); i++)
		{
			int numEdge;
			for (int j = 0; j < tops[criticalPath[i - 1]]->nearVertexes.size(); j++)
			{
				if (tops[criticalPath[i - 1]]->nearVertexes[j]->number == criticalPath[i])
				{
					numEdge = j;
				}
			}
			tops[criticalPath[i - 1]]->edgeWeight[numEdge] = 0;
		}
	}

	for (int i = 0; i < nTops; i++)
	{
		tops[i]->free = false;
	}

	vector<int> criticalPath;
	int maxLength = 0;

	for (int i = 0; i < nTops; i++)
	{
		if (tops[i]->free)
			continue;

		vector<int> path;
		int length = 0;
		criticalWay(&path, &length, *tops[i]);

		if (length > maxLength)
		{
			maxLength = length;
			copyVector(&criticalPath, path);
		}
	}

	for (int i = 0; i < criticalPath.size(); i++)
	{
		cout << criticalPath[i] << " ";
	}

	cout << endl;

	//getch();
	system("pause");
}

//рекурсивная функция поиска критического пути
void criticalWay(vector<int>* path, int* length, Vertex top)
{
	path->push_back(top.number);
	*length += top.weight;

	if (top.nearVertexes.size() == 0)
		return;

	if (top.nearVertexes.size() > 1)
	{
		int myMax = 0;
		int maxI;
		vector<vector<int>> myPathes;

		for (int i = 0; i < top.nearVertexes.size(); i++)
		{
			if (top.nearVertexes[i]->free)
				continue;

			vector<int> myPath;

			copyVector(&myPath, *path);
			int myLength = top.edgeWeight[i];

			criticalWay(&myPath, &myLength, *top.nearVertexes[i]);

			myPathes.push_back(myPath);

			if (myLength >= myMax)
			{
				myMax = myLength;
				maxI = myPathes.size() - 1;
			}
		}

		*length += myMax;
		copyVector(path, myPathes[maxI]);

		return;
	}

	if (top.nearVertexes[0]->free)
		return;

	criticalWay(path, length, *top.nearVertexes[0]);
	*length += top.edgeWeight[0];
}

//копирование вектора
void copyVector(vector<int>* dest, vector<int> source)
{
	dest->clear();

	for (int i = 0; i < source.size(); i++)
	{
		dest->push_back(source[i]);
	}
}

//условие цикла
bool condition(vector<Vertex*> tops)
{
	for (int i = 0; i < tops.size(); i++)
	{
		if (!tops[i]->free)
			return true;
	}

	return false;
}