//
//  main.c
//  v21-5
//
//  Created by Артём Кириенко on 03.12.12.
//  Copyright (c) 2012 Артём Кириенко. All rights reserved.
//
//  Задана система двусторонних дорог, где для любой пары городов есть
//  соединяющий их путь. Найти город с минимальной суммой расстояний до остальных
//  городов.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    //С динамикой.
    int **k, *l, p, q, dmins, dmini, n, temp;

    printf("Введите количество вершин графа.\n");
    scanf("%d",&n);
    l=(int *)malloc(n*sizeof(int));

    //Обнуление динамического массива сумм.
    for (p=0; p<n; p++) l[p]=0;

    //Создание динамического массива для цен графа.
    k=(int **)malloc(n*sizeof(int *));
    for (p=0; p<n; p++){
        k[p]=(int *)malloc(n*sizeof(int));
    }

    //Ввод матрицы цен графа для динамики.
    for (p=0; p<n; p++){
        for (q=0; q<n; q++){
            scanf("%d",&temp);
            k[p][q]=temp;
        }
    }
    printf("\n");

    for (p=0; p<n; p++){
        for (q=0; q<n; q++){
            printf("%d ",k[p][q]);
        }
        printf("\n");
    }

    //Подсчёт сумм для динамического массива.
    for (p=0; p<n; p++){
        for (q=0; q<n; q++){
            l[p]=l[p]+k[p][q];
        }
    }

    //Поиск минимальной суммы в динамике.
    //Что если несколько сумм? Если все одинаковые?
    dmins=l[0];
    dmini=0;
    for (p=1; p<n; p++){
        if (l[p] < dmins){
            dmins=l[p];
            dmini=p;
        }
    }

    printf("Ответ.\n");
    printf("Город #%d является городом с минимальной суммой расстояний до других городов.\n",dmini+1);
    printf("Сумма расстояний от этого города до других городов: %d\n",dmins);
    return 0;
}

