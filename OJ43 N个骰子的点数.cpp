//
// Created by ProMoriarty on 2017/9/8.
//
/**
 *  n个骰子的点数
 *  题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为S。输入n，打印出S的所有可能的值出现的概率。
 */
//方法一：递归
//        思路：设n个骰子某次投掷点数和为s的出现次数是F(n, s)，那么，F(n, s)等于n - 1个骰子投掷的点数和为
//s - 1、s - 2、s - 3、s -4、s - 5、s - 6时的次数的总和：
//F(n , s) = F(n - 1, s - 1) + F(n - 1, s - 2) + F(n - 1, s - 3) + F(n - 1, s - 4) + F(n - 1, s - 5) + F(n - 1, s - 6)。


#include <iostream>
#include <time.h>
#include <vector>
#include <assert.h>
#include <list>
#include <math.h>
using namespace std;

//计算n个骰子某次投掷点数和为s的出现次数
int CountNumber(int n, int s) {
    //n个骰子点数之和范围在n到6n之间，否则数据不合法
    if(s < n || s > 6*n)
        return 0;
    //当有一个骰子时，一次骰子点数为s(1 <= s <= 6)的次数当然是1
    if(n == 1)
        return 1;
    else
        return CountNumber(n-1, s-6) + CountNumber(n-1, s-5) + CountNumber(n-1, s-4) +
               CountNumber(n-1, s-3) +CountNumber(n-1, s-2) + CountNumber(n-1, s-1);
}
void listDiceProbability(int n) {
    int i=0;
    unsigned int nTotal = pow((double)6, n);
    for(i = n; i <= 6 * n; i++) {
        printf("P(s=%d) = %d/%d\n", i, CountNumber(n,i), nTotal);
    }
}

int main() {
    listDiceProbability(3);
}