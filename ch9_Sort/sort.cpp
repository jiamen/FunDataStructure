//
// Created by zlc on 2021/5/6.
//

#include <stdio.h>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE  1
#define FALSE 0

// 用于快速排序时判断是否选用插入排序阈值
#define MAX_LENGTH_INSERT_SORT 7

typedef int Status;

/*
 * 按照算法的复杂度，排序算法分为两大类：
 *      简单算法：冒泡排序、简单选择排序、直接插入排序
 *      改进算法：希尔排序、堆排序、归并排序、快速排序
 * */

#define MAX_SIZE 10000      // 用于要排序数组个数最大值，可根据需要修改
typedef struct
{
    int r[MAX_SIZE + 1];    // 用于存储要排序数组，r[0]用作哨兵或临时变量
    int length;             // 用于记录顺序表的长度
} SqList;

// 交换操作：交换L中数组r的下标为i和j的值
void swap(SqList* L, int i, int j)
{
    int temp = L->r[i];
    L->r[i]  = L->r[j];
    L->r[j]  = temp;
}

// 对数组进行打印
void print(SqList L)
{
    int i = 0;
    for (i=1; i<L.length; i ++)
    {
        printf("%d, ", L.r[i]);
    }
    printf("%d", L.r[i]);       // 最后一个元素，不带", "
    printf("\n");
}

/*=====================================1、冒泡排序：时间复杂度Ｏ(n²)=======================================*/
// 1.1 对顺序表L作交换排序(冒泡排序初级版)
void BubbleSort0(SqList* L)
{
    int i, j;
    for (i=0; i<L->length; i ++)
    {
        for (j=i; j<=L->length; j ++)
        {
            // 从小到大排序，永远拿第i个与后边比，保证第i个是当次排序中最小的，只要大的了就换
            if (L->r[i] > L->r[j])              // 若第i个位置大于后面的j位置， 交换
            {
                swap(L, i, j);
            }
        }
    }
}

// 1.2 对顺序表L作冒泡排序
void BubbleSort1(SqList* L)
{
    int i, j;
    for (i=1; i<L->length; i ++)
    {
        for (j=L->length-1; j>=i; j --)         // 注意j是从后往前循环
        {
            if (L->r[j] > L->r[j+1])            // 若前者大于后者， 交换
            {
                swap(L, j, j+1);
            }
        }
    }
}

// 1.3 对顺序表L作改进冒泡算法
void BubbleSort2(SqList* L)
{
    int i, j;
    Status flag = TRUE;     // int flag=1

    for (i=1; i<L->length && flag; i ++)    // 注意：没有等于
    {
        flag = FALSE;
        for (j=L->length-1; j>=i; j --)
        {
            if (L->r[j] > L->r[j+1])
            {
                swap(L, j, j+1);
                flag = TRUE;                // 只要有数据交换说明，说明还需要进下一次循环进一步判断是否已有序
            }
        }
    }
}


/*=====================================2、选择排序：时间复杂度Ｏ(n²)=======================================*/
void SelectSort(SqList* L)                  // 注意：没有等于
{
    int i, j, min;
    for (i=1; i<L->length; i ++)
    {
        min = i;
        for (j=i+1; j<=L->length; j ++)
        {
            if (L->r[min] > L->r[j])        // 遍历一次找出最小值所在位置的下标
                min = j;
        }
        if (i != min)                       // 第ｉ次循环保证第ｉ个位置就是最小值
            swap(L, i, min);
    }
}


/*=====================================3、直接插入排序：时间复杂度O(n²)=======================================*/
void InsertSort(SqList* L)
{
    int i, j;
    for (i=2; i<=L->length; i ++)
    {
        if (L->r[i] < L->r[i-1])
        {
            L->r[0] = L->r[i];                      // 设置哨兵，作下面插入的判断条件
            for (j=i-1; L->r[j]>L->r[0]; j --)      // 一直在已经排好序的队列中找到小于r[0]的位置为止
            {
                L->r[j+1] = L->r[j];                // 记录后移
            }
            L->r[j+1] = L->r[0];                    // 插入到正确位置
        }
    }
}


/*=====================================4、对顺序表作希尔排序：时间复杂度O(n^(3/2))=======================================*/
void ShellSort(SqList* L)
{
    int i, j, k = 0;
    int increment = L->length;

    do
    {
        increment = increment/3 + 1;        // 增量序列
        for (i=increment+1; i<=L->length; i ++)
        {
            if (L->r[i] < L->r[i-increment])  // 需将L->r[i]插入有序增量字表
            {
                L->r[0] = L->r[i];          // 暂存在L->r[0]
                for (j=i-increment; j>0 && L->r[0]<L->r[j]; j-=increment)
                {
                    L->r[j+increment] = L->r[j];        // 记录后移，查找插入位置
                }
                L->r[j+increment] = L->r[0];            // 插入
            }
        }
        printf("第%d趟排序结果: ", ++ k);
        print(*L);
    } while (increment>1);

}


/* 堆排序 */






#define N   9

int main(int argc, char* *argv)
{
    int i;

    /* int d[N] = {9, 1, 5, 8, 3, 7, 4, 6, 2}; */
    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
    /* int d[N]={9, 8, 7, 6, 5, 4, 3, 2, 1}; */

    SqList l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11;

    // 存储数据，注意从1开始存，0位置是哨兵位置
    for (i=0; i < N; i ++)
        l0.r[i+1] = d[i];
    l0.length = N;

    l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = l10 = l11 = l0;

    printf("排序前:\n");
    print( l0 );

    printf("初级冒泡排序:\n");
    BubbleSort0( &l0 );
    print( l0 );

    printf("冒泡排序:\n");
    BubbleSort1( &l1 );
    print( l1 );

    printf("改进冒泡排序:\n");
    BubbleSort2( &l2 );
    print( l2 );

    printf("简单 选择排序:\n");
    SelectSort( &l3 );
    print( l3 );

    printf("直接 插入排序:\n");
    InsertSort( &l4 );
    print( l4 );

    printf("希尔排序:\n");
    ShellSort( &l5 );
    print( l5 );

    printf("堆排序:\n");
    InsertSort( &l6 );
    print( l6 );



    return 0;

}
