#include <iostream>
#include <vector>

using namespace std;

void adjustHeap(vector<int>& vec, int p, int len) {
    int curParent = vec[p];
    int child = 2*p+1;  //左孩子
    while (child < len) {   //有孩子
        if (child + 1 < len && vec[child] < vec[child+1]) {     //比较左右孩子
            child++;    //变为右孩子
        }
        if (curParent < vec[child]) {
            //没有讲curParent赋值给孩子是因为还要迭代子树
            //如果其孩子中有大的，会上移，curParent还要继续下移
            vec[p] = vec[child];
            p = child;  //向下迭代
            child = 2*p + 1;    //更新迭代坐标
        }
        else break;
    }
    vec[p] = curParent;
}


void heapSort(vector<int>& vec, int len) {
    //建立堆，从最底层的父结点开始，逐个遍历结点
    for (int i = len/2-1; i >= 0; --i)
        adjustHeap(vec, i, len);

    //进行排序
    for (int i = len - 1; i >=0; --i) {
        swap(vec[0], vec[i]);

        adjustHeap(vec, 0, i);  //调整剩余元素的建堆

    }
}

int main()
{
    vector<int> vec = {6,3,4,5,1,7};
    heapSort(vec, vec.size());
    for (auto i : vec)
        cout << i << ",";

    return 0;
}
