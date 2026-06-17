#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstdlib>
class Array
{
    private:
        int *mpArr; //指向可扩容的数组内存
        int mcap;   //数组的容量
        int mcur;   //数组有效元素个数

        //内部数组扩容
        void expand(int size)
        {
            int *p = new int[size];
            std::copy(mpArr,mpArr+mcap,p);
            delete[] mpArr;
            mpArr = p;
            mcap = size;
        }
    public:
        Array(int size = 10) : mcap(size), mcur(0)
        {
            mpArr = new int[mcap]();
        }
        ~Array()
        {
            delete []mpArr;
            mpArr = nullptr;
        }
    public:
    //末尾增加元素
    void push_back(int val)
    {
        if(mcur == mcap)
        {
            expand(2 * mcap);
        }
        mpArr[mcur++] = val;
    }
    //末尾删除元素
    void pop_back()
    {   
        if(mcur == 0)
        {
            return;
        }
        mcur --;
    }
    //按位置增加元素
    void insert(int pos,int val)
    {
        if(pos < 0|| pos > mcur)
        {
            return;  //throw "pos invalid!";
        }
        if(mcur == mcap)
        {
            expand(2 * mcap);
        }
        for(int i = mcur - 1;i >= pos;i--)
        {
            mpArr[i+1] = mpArr[i];
        }
        mpArr[pos] = val;
        mcur++;
    }
    //按元素位置删除
    void erase(int pos)
    {
        if(pos < 0 || pos >= mcur)
        {
            return;
        }
        for(int i = pos+1;i < mcur;i++)
        {
            mpArr[i-1] = mpArr[i];
        }
        mcur--;
    }
    //元素查询
    int find(int val)
    {
        for(int i = 0;i < mcur; i++)
        {
            if(mpArr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    //打印数据
    void show()const
    {
        for(int i = 0;i < mcur;i ++)
        {
            std::cout<< mpArr[i] <<" ";
        }
        std::cout<< std::endl;
    }
};

int main()
{
    Array arr;

    std::srand(time(0));
    for(int i = 0;i < 10;i++)
    {
        arr.push_back(rand()%100);
    }
    arr.show();
    arr.pop_back();
    arr.show();
    return 0;
} 