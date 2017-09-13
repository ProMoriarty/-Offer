//
// Created by ProMoriarty on 2017/8/18.
//
//数组在排序数组中出现的次数
/**
 * 统计一个数字在排序数组中出现的次数
 */
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()<=0)
            return 0;
        int length = data.size();
        int first = firstK(data,k,length,0,data.size()-1);
        int last = lastK(data,k,length,0,data.size()-1);

        if(first>=0 && last>=0)
            return last-first+1;
        else
            return 0;
    }
private:
    int firstK(vector<int>& data,int k,int length,int start,int end){
        if(start>end)
            return -1;
        int middle = (start+end)/2;
        int middlenum = data[middle];
        if(middlenum==k){
            if((middle>0&&data[middle-1]!=k)||middle==0)
                return middle;
            else
                end = middle-1;
        }
        else if(middlenum<k){
            start = middle+1;
        }else{
            end = middle-1;
        }
        return firstK(data,k,length,start,end);
    }
    int lastK(vector<int>& data,int k,int length,int start,int end){
        if(start>end)
            return -1;
        int middle = (start+end)/2;
        int middlenum = data[middle];
        if(middlenum==k){
            if((middle<length-1&&data[middle+1]!=k)||middle==length-1)
                return middle;
            else
                start = middle+1;
        }
        else if(middlenum<k){
            start = middle+1;
        }else{
            end = middle-1;
        }
        return lastK(data,k,length,start,end);
    }
};