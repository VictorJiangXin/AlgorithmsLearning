#include <iostream>
#include <cstring>

#define N 1024

float a[N];
using namespace std;

template <typename T>
void sort_insert(T *a, int array_len);

int main()
{
    memset((char*)a, 0, sizeof(a));
    int array_len;
    cin >> array_len;
    for(int i = 0; i < array_len; i++)
        cin >> a[i];
    sort_insert(a, array_len);
    for(int i = 0; i < array_len; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}

/*
	插入排序，依次将每个元素插入合适的位置，
	从1个元素开始，依次插入其他元素，则插完
	所有的元素后，完成排序
	
	最坏情况：
	当数组本身是 完全逆序的，则需要移动
	1+2+3+...+n = o(n^2)

*/
template <typename T>
void sort_insert(T *a, int array_len){
    int i, j;
    for(i = 1; i < array_len; i++){
        T key = a[i];
        j = i - 1;
        while(key < a[j] && j >= 0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
