#include <iostream>
#include <vector>

using namespace std;

void adjustHeap(vector<int>& vec, int p, int len) {
    int curParent = vec[p];
    int child = 2*p+1;  //����
    while (child < len) {   //�к���
        if (child + 1 < len && vec[child] < vec[child+1]) {     //�Ƚ����Һ���
            child++;    //��Ϊ�Һ���
        }
        if (curParent < vec[child]) {
            //û�н�curParent��ֵ����������Ϊ��Ҫ��������
            //����亢�����д�ģ������ƣ�curParent��Ҫ��������
            vec[p] = vec[child];
            p = child;  //���µ���
            child = 2*p + 1;    //���µ�������
        }
        else break;
    }
    vec[p] = curParent;
}


void heapSort(vector<int>& vec, int len) {
    //�����ѣ�����ײ�ĸ���㿪ʼ������������
    for (int i = len/2-1; i >= 0; --i)
        adjustHeap(vec, i, len);

    //��������
    for (int i = len - 1; i >=0; --i) {
        swap(vec[0], vec[i]);

        adjustHeap(vec, 0, i);  //����ʣ��Ԫ�صĽ���

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
