//
//  main.cpp
//  v21-5
//
//  Created by Артём Кириенко on 04.07.13.
//  Copyright (c) 2013 Артём Кириенко. All rights reserved.
//
//  Задана система двусторонних дорог, где для любой пары городов есть
//  соединяющий их путь. Найти город с минимальной суммой расстояний до остальных
//  городов.
//

#include <iostream>
#include <stdio.h>

using namespace std;

const int VERT = 10001;
const int EDGE = 200001;
const int maxv = 10000000;

int ft[VERT], col[VERT], d[VERT];
int nx[EDGE], v[EDGE], w[EDGE];
int i, n, m, k, sum, city;
FILE *f;

void init(int &p, int k, int val){
    int* a=&p;
    for (int i=0; i<=k; i++) a[i]=val;
}

//Алгоритм Дейкстры.
int Djikstra(int x){
    init(*d, VERT, maxv);
    init(*col, VERT, 0);
    int ed;
    d[x] = 0;
    int s = 0;
    for (int j=1; j<=n; j++) {
        ed = ft[x];
        col[x] = 1;
        s += d[x];
        while (ed != 0){
            if (d[x]+w[ed] < d[v[ed]]) d[v[ed]] = d[x]+w[ed];
            ed = nx[ed];
        }
        int dest = maxv;
        for (int l=1; l<=n; l++)
            if ((col[l] == 0)&&(d[l] < dest)){
                dest = d[l];
                x = l;
            }
    }
    return s;
}

int main()
{
    int v1;
    int v2;
    int wt;
    cout << "Города вводятся из файла" << endl;
    printf("Введите количество вершин и количество рёбер графа.\n");
    scanf("%d%d", &n, &m);
    init(*ft, VERT, 0);
    init(*v, EDGE, 0);
    init(*nx, EDGE, 0);
    init(*w, EDGE, 0);
    sum = maxv;
    printf("Введите цены рёбер графа.\n");
    for (i=1; i<=m*2; i+=2) {
        scanf("%d%d%d", &v1, &v2, &wt); 
        v[i] = v2;
        v[i+1] = v1;
        nx[i] = ft[v1];
        ft[v1] = i;
        nx[i+1] = ft[v2];
        ft[v2] = i+1;
        w[i] = w[i+1] = wt;
    }
    k = 0;
    for (i=1; i<=n; i++){
        k = Djikstra(i);
        if (k<sum) {city = i; sum = k;}
    }
    cout << "Нужный город: " << city << " " << sum << endl;
    return 0;
}
