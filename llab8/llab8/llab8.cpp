#include "StdAfx.h"
#include <iostream>
#include <queue> 
#include "time.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	//const int size = 7;
  queue<int> Queue;
  int size;
  printf("������� ������ �������: ");
  scanf("%d", &size);
  int** mas = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        mas[i] = (int*)malloc(sizeof(int) * size);
    }
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mas[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                mas[i][j] = 0;
            }
            if (mas[i][j] = mas[j][i]) {
                mas[i][j] = mas[j][i];
            }
        }
    }
	for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j)
                    printf("%3d", mas[i][j]);
                printf("\n");
            }
  int *nodes = new int [size];
  for (int i = 0; i < size; i++)
    nodes[i] = 0; 
  int start = clock();
  Queue.push(0); 
  printf("����� � ������: ");
  while (!Queue.empty())
  { 
    int node = Queue.front(); 
    Queue.pop();
    nodes[node] = 2; 
    for (int j = 0; j < size; j++)
    { 
      if (mas[node][j] == 1 && nodes[j] == 0)
      { // ���� ������� ������� � �� ����������
        Queue.push(j); 
        nodes[j] = 1; 
      }
    }
	printf(" ");
	printf("%d", node + 1);
  }
  int end = clock();
  double time = (end-start) / 1000.0;
	printf("\nTime: %lf", time);
  cin.get();
  return 0;
}
