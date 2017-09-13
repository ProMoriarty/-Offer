//
// Created by ProMoriarty on 2017/8/18.
//
//顺时针打印矩阵
/**
 * 栈的压入弹出序列
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
 * 序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
 * （注意：这两个序列的长度是相等的）
 */

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool isOverflow = false;
        int nTakeOver = 0;
        int length = strlen(number);
        for(int i=length-1;i>=0;i--){
            int sum = number[i]-'0'+nTakeOver;
            if(i==length-1)
                sum++;
            if(sum>=10){
                if(i==0)
                    isOverflow = true;
                else{
                    sum-=10;
                    nTakeOver = 1;
                    number[i]='0'+sum;
                }
            }
            else{
                number[i]='0'+nSum;
                break;
            }
        }
        return isOverflow;
    }
};