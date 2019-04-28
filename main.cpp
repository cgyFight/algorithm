#include <iostream>
#include <vector>

using namespace std;

void markTmp(int *a, unsigned int len)
{
    if (a==nullptr || len <= 2) return;

    int *tmp = new int[len]{};

    unsigned int maxIndex = 0;
    int max;
    for (unsigned int i = 0; i < len; ++i) { // 和左边比它是最大得标记为1 ->当前值和左边最大值进行比较
        max = a[maxIndex];
        if (max >= a[i]) {
            // 这个不是最大得
        } else {
            // 这个是最大得
            cout << a[i] << endl;
            maxIndex = i;
            tmp[i] ++;
        }
    }

    auto minIndex = len - 1;
    cout << endl;
    for (auto i = len - 1; i != 0; --i) {
        if (a[minIndex] <= a[i]) {
        } else {
            cout << a[i] << endl;
            minIndex = i;
            tmp[i] ++;
        }
    }

    for (auto i = 0; i < len; i++) {
        if (tmp[i] == 2) {
            cout << a[i] << endl;
        }
    }
}

void markTmp2(vector<int> in_v, vector<int> &out_v)
{
    if (in_v.size() <= 2) return;

    vector<int> tmp(in_v.size());
    int maxIndex = 0;
    cout << "find max\n" << endl;
    for(auto i = 1; i < in_v.size(); ++i) {
        if (in_v[i] <= in_v[maxIndex]) {
            // not left max
        } else {
            cout << in_v[i] << endl;
            maxIndex = i;
            tmp[i]++;
        }
    }
    cout << "find max over\n" << endl;
    int minIndex = in_v.size()-1;
    for(auto i = minIndex-1; i != 0; --i) {
        if (in_v[i] >= in_v[minIndex]) {
        } else {
            cout << in_v[i] << endl;
            minIndex = i;
            tmp[i]++;
        }
    }
    cout << "over 2\n";

    for (int i = 0; i < in_v.size(); ++i) {
        if (tmp.at(i) == 2) out_v.push_back(in_v[i]);
    }
}

#include "sort/fastsort.h"

class A {
public:
    A(int a):_a(a){}
    bool operator < (A a) {return false;}
    bool operator > (A a) {return false;}
private:
    int _a;
};

void trim(const char *in_str, char *out_str)
{
    const char *start = in_str;
    int i = 0;
    while(*start != '\0'){
        if (*start != ' ') {

            out_str[i++] = *start;
            cout << " " << i << " " << out_str[i];
        }
            start++;
    }
}

int main()
{
    A a[] {1,2,3,9,5,6,10,11,13,15,17};

//    markTmp(a, sizeof (a)/sizeof(int));
    vector<int> t {1,2,3,9,5,6,10,11,13,15,17};
    vector<int> ot;
//    markTmp2(t, ot);
    cout << "begin" << endl;
    for(auto i : ot) {
//        cout << i << endl;
    }

    for(auto i : a) {
//        cout << i;
    }
    fastSort(a, 11);
    for(auto i : a) {
//        cout << i << " ";
    }


    cout << "Hello World!" << endl;
    const char *p1 = " hello word! \n";
    char p2[512] = {0x0};
    trim(p1, p2);
    cout << p2;
    cout << endl << "end\n";
    return 0;
}
