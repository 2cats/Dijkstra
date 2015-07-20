#include <stdio.h>
#include <stdlib.h>

//�������޴�
#define inf 	100000
//��ĸ���
#define V_SIZE	6

//�������
void array_fill(int * array, int len, int val) {
	int i;
	for (i = 0; i < len; i++) {
		array[i] = val;
	}
}
/*�������ܣ�
 * 	dijkstra�㷨������ͼ��̾��룬�����·��
 *���������
 *	graph	Ȩֵ����
 *	n		�����С,����ĸ���
 *	start	���
 *	dist	���յ����е����̾���
 * */
void dijkstra(int graph[][V_SIZE],int n,int start,int dist[]) {
	int* path=(int*)malloc(sizeof(int)*n);
	int* shortest=(int*)malloc(sizeof(int)*n);
	int* mark=(int*)malloc(sizeof(int)*n);
	int min,v,i,j;
	array_fill(mark,n, 0);
	array_fill(dist,n, inf);

	for(i=0;i<n;i++) {
		dist[i]=graph[start][i];
		if(i!=start&&dist[i]<inf)path[i]=start;
		else path[i]=-1;
	}
	mark[start]=1;
	while(1) {
		min=inf;v=-1;
		//�ҵ���С�ľ���
		for(i=0;i<n;i++) {
			if(!mark[i]) {
				if(dist[i]<min) {min=dist[i];v=i;}
			}
		}
		if(v==-1)break; //�Ҳ������̵�·����
		//�������·��
		mark[v]=1;
		for(i=0;i<n;i++) {
			if(!mark[i]&&
					graph[v][i]!=inf&&
					dist[v]+graph[v][i]<dist[i]) {
				dist[i]=dist[v]+graph[v][i];
				path[i]=v;
			}
		}
	}
	//���·��
	printf("���\t�յ�\t��̾���\t��Ӧ·�� \n");
	for(i=0;i<n;i++) {
		if(i==start) continue;
		array_fill(shortest,n, 0);
		printf("%d\t",start);
		printf("%d\t",i);
		printf("%d\t",dist[i]);
		int k=0;
		shortest[k]=i;
		while(path[shortest[k]]!=start) {
			k++;shortest[k]=path[shortest[k-1]];
		}
		k++;shortest[k]=start;
		for(j=k;j>0;j--) {
			printf("%d->",shortest[j]);
		}
		printf("%d\n",shortest[0]);
	}
	free(path);
	free(shortest);
	free(mark);
	return ;
}

int main()
{
	int dist[V_SIZE];
	int W[V_SIZE][V_SIZE] = {
				{  0,   1,   4,  inf,  inf,  inf },
				{  1,   0,   2,   7,    5,  inf },
				{  4,   2,   0,  inf,    1,  inf },
				{ inf,  7,  inf,   0,    3,    2 },
				{ inf,  5,    1,   3,   0,    6 },
				{ inf, inf,  inf,   2,   6,    0 }
	 	 	 };

	 dijkstra(W,V_SIZE,2,dist);
     return 0;
}
