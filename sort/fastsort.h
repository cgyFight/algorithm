#ifndef FASTSORT_H
#define FASTSORT_H

#include <iostream>
#include <functional>
#include <vector>
using namespace std;

/*
 * 快速排序
 * 1. 将左边右边分别排序，最后合并
 */

template<typename T>
class Sort
{
public:
    Sort() {}
    virtual ~Sort(){}

    virtual void sort(vector<T> &data, function<int(T, T)> compare) = 0;
};


template<typename T>
class FastSort : public Sort<T>
{
public:
    FastSort();
    virtual void sort(vector<T> &data, function<int(T, T)> compare){
    }
};

template<typename T>
void Swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/*
 * 将小于基点的放到左边，大于的放到右边
*/
template <typename T>
int partion(T a[], int left, int right)
{
    T middl = a[left];
    int i = left;
    int j = right + 1;
    while(true) {
        do {
            i++;
        } while (a[i] < middl);
        do {
            j--;
        } while(a[j] > middl);
        if (i >= j) break;
        Swap(a[i], a[j]);
    }
//    a[left] = a[right];
//    a[right] = middl;
    Swap(a[left], a[j]);
    return j;
}

template <typename T>
static void fastSort_(T a[], int left, int right)
{
    if (left >= right) return; // 到头了

#if 0
    int i = left, j = right+1;
    cout << "begin " << left << " " << right << endl;

    T midle = a[left];

    while(true) {
        do {
            i++;
        } while (a[i] < midle);
        do {
            j--;
        } while(a[j] > midle);
        if (i >= j) break;
        cout <<"sw " << i << " " <<j <<endl;
        Swap(a[i], a[j]);
    }
    a[left] = a[j];
    a[j] = midle;
#else
    int j =  partion(a, left, right + 1);
#endif
    fastSort_(a, left, j - 1);
    fastSort_(a, j + 1, right);
}

template <typename T>
void fastSort(T* a, int n)
{
    fastSort_(a, 0, n - 1);
}



#endif // FASTSORT_H
