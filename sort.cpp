//
// Created by 24887 on 2023/7/18.
//
#include <iostream>
#include <cstring>
#include "sort.h"
using namespace std ;




void PrintArr(int arr[] , int size ){
    for (int i = 0 ; i < size ; i ++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

void DirectInsertSort(int *arr, int n) {
    int i ;
    int key ;
    int j ;
    for (int i = 1 ; i < n ; i ++){
        key = arr[i] ;
        j = i -1 ;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j] ;
            j -- ;
        }
        arr[j+1] = key ;

        cout << "the order" << i << "\t" ;
        for (int k = 0 ; k < n ; k ++){
            cout << arr[k] << " " ;
        }
        cout << endl ;
    }
}


void HalfInsertSort(int arr[] , int size ){
    for (int i = 1 ; i < size ; i ++){
        cout << "the order " << i << ": " << endl ;
        cout << "\t" <<"��������:"  ;
        for (int k = 0 ; k < i ; k ++){
            cout << arr[k] << " " ;
        }
        cout << endl ;
        cout << "\t" << "��Ҫ���������:" << arr[i] << endl ;

        int key = arr[i] ; //��Ǵ�����Ԫ��
        int left = 0 ;
        int right = i -1 ;

        if (arr[i] < arr[i-1]){

            while (left <= right){
                int mid = (left + right)/2 ;
                if (arr[mid] > key){
                    right = mid -1 ;
                }else {
                    left = mid + 1 ;
                }
            }

            for (int j = i -1 ; j > right ; j --){
                arr[j+1] = arr[j] ;
            }
            arr[right+1] = key ;

        }
        cout << "\t" << "�����λ��: " << right+1 << endl ;


        cout << "\t" <<  "�µ��������� :" ;
        for (int k = 0 ; k <= i ; k ++){
            cout << arr[k] << " " ;
        }
        cout << endl ;

    }
}


void BubbleSort(int arr[] , int size ){
    int i , j , count = 0 , round = 0 ,temp  ;
    for(i = 0 ; i < size - 1 ; i ++){
        for (j = 0 ; j < size - i -  1 ; j ++){
            //ÿһ����ѡ����.
            if (arr[j] > arr[j+1]){
                temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
            }
            count ++ ;
        }
        round ++ ;
    }

    PrintArr(arr , size) ;
    cout << "\t�����ܴ���" << round << ",�Ƚ��ܴ���:" << count << endl ;
    return ;
}


// ��������
int GetMinIndex(int *arr , int left , int right){
    int mid = (left + right) / 2;

    if (arr[left] < arr[right])
    {
        if (arr[mid] < arr[left])
        {
            return left;
        }
        else if (arr[mid] <arr[right])
        {
            return mid;
        }
        else
        {
            return right;
        }
    }
    else
    {
        if (arr[mid] < arr[right])
        {
            return right;
        }
        else if (arr[mid] < arr[left])
        {
            return mid;
        }
        else
        {
            return left;
        }
    }
}


void Swap(int &a , int &b){
    int temp = a ;
    a = b ;
    b = temp ;
}


int PartSort(int *arr , int left , int right){
    int key = GetMinIndex(arr, left , right) ;
    Swap(arr[key] , arr[left]) ;

    key = arr[left] ;

    int hole = left ;

    while (left < right)
    {
        while (left < right && arr[right] >= key)
        {
            right--;
        }
        arr[hole] = arr[right];
        hole = right;

        while (left < right && arr[left] <= key)
        {
            left++;
        }
        arr[hole] = arr[left];
        hole = left;
    }

    arr[hole] = key;
    return hole;
}


void QuickSort(int *arr , int begin , int end ){
    if (begin >= end){
        return ;
    }
    int key = PartSort(arr , begin , end) ;
    QuickSort(arr, begin , key -1) ;
    QuickSort(arr, key + 1 , end) ;
}


void SimpleSelectSort(int *arr , int size) {
    int i, j, min, temp;
    for (i = 0; i < size; i++)
    {
        // ��ʼ��Сֵ�±�
        min = i;
        // ���Һ�����Сֵ���±�
        for (j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        // ������Сֵ
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}


//���ѵ���
void Heapify(int *arr , int k , int len){
    if( k < len ){
        int root = k ;
        int lchild = 2*k + 1 ;
        int rchild = 2*k + 2 ;

        //�������к��ӽ���е������
        if ( lchild < len && arr[root] < arr[lchild]){
            root = lchild ;
        }
        if (rchild < len && arr[root] < arr[rchild] ){
            root = rchild ;
        }

        if (root != k ){
            Swap(arr[root] , arr[k]) ;
            Heapify(arr , root , len) ;
        }
    }
}


// ��������
void CreateHeap(int *arr , int len) {
    int i ;
    //���һ������±�
    int last = len -1 ;
    //���һ�����ĸ�����±�
    int parent = (last-1) / 2 ;
    //�����һ�����ĸ���㵽���ڵ�
    for (i = parent; i >= 0 ; i --){
        cout << "�Խ��" << arr[i] << "�����ѵ���" << endl ;
        Heapify(arr, i , len) ;
    }
}


// ������
void HeapSort(int *arr , int len) {
    //���������Ѳ����е���
    CreateHeap(arr , len) ;
    cout << "���ѵ���!\n" << endl ;
    int i ;
    //����ȡ�����ڵ�
    for (i = len-1 ; i >= 0 ; i --){
        Swap(arr[i] , arr[0]) ;
        Heapify(arr, 0, i) ;
    }
}

void DisplayHeapSort(int *arr , int len){
    cout << "**********************" << endl ;
    cout << "       " << arr[0] << endl ;
    cout << "   " <<arr[1] << "       " << arr[2] << endl ;
    cout << " " << arr[3] << " " <<arr[4] << "   " << arr[5] << "   " <<arr[6] << endl ;
    cout << arr[7] << " " <<arr[8] << " " << arr[9] <<endl ;
    cout << "**********************" << endl ;
}

void MergeSort(int *a , int *b , int *c , int la ,int lb){

    int i = 0 , j = 0 , k = 0 ;
    while (i < la && j < lb){
        if( a[i] < b[j]){
            c[k++] = a[i++] ;
        }else {
            c[k++] = b[j++] ;
        }
    }

    while (i < la){
        c[k++] = a[i++] ;
    }
    while ( j < lb){
        c[k++] = b[j++] ;
    }

    PrintArr(c , k ) ;
}


int GetDigit(int M , int i ){
    while (i > 1) {
        M /= 10 ;
        i -- ;
    }
    return M % 10 ;
}

void RadixSort(int *arr , int len) {
    int i , j , k , l , digit ;
    int allot[10][10] ;;

    memset(allot , 0 , sizeof(allot)) ;

    for (i = 1 ; i <= 5 ; i ++) {
        for(j = 0 ; j < len ; j ++){
            //��ȡ��ǰ����num[j]�ĵ�iλ��
            digit = GetDigit(arr[j] , i) ;
            k = 0 ;
            //���Ҳ���λ��
            while (allot[digit][k]){
                k ++ ;
            }
            allot[digit][k] = arr[j] ;
        }

        l = 0 ;

        for (j = 0 ; j < 10 ; j ++){
            k = 0 ;
            while (allot[j][k]){
                arr[l++] = allot[j][k++] ;
            }
        }

        cout << "�Ե�" << i << "λ�����з���" << endl ;
        cout << "��������:" << endl ;
        for(int p = 0 ; p <10 ; p ++){
            cout << "��" << i << "λ=" << p ;
            for (int q =0 ; q < 10 ; q ++){
                cout << "\t" << allot[p][q] ;
            }
            cout << endl ;
        }
        memset(allot , 0 , sizeof(allot)) ;
    }
}
