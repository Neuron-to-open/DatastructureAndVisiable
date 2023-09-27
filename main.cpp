//
// Created by 24887 on 2023/7/13.
//

#include <iostream>
#include "Sequence.h"
#include "SingleList.h"
#include "DoubleLinkedList.h"
#include "BST.h"
#include "sort.h"
using namespace std ;

//˳���
void OpSeq(){
    Sequence sequence(10) ; // ����һ��sizeΪ10˳����ʵ��
    sequence.InitTable() ;       //ʵ���г�ʼ�������������
    sequence.ShowTable() ;       // ����
    cout << "-------------" << endl ;
    sequence.InsertTable(6, 99) ;
    sequence.InsertTable(1, 90) ;
    sequence.InsertTable(4 , 88) ;
    sequence.InsertTable(3 , 520) ;
    sequence.ShowTable() ;       // ����
    cout << "-------------" << endl ;

    sequence.addLength() ;
    cout << sequence.seq.size << endl ;
    cout << "-------------" << endl ;

    int data ;
    sequence.DeleteTable(2 , data) ;
    cout << "Delete the data :" << data << endl ;
    sequence.ShowTable() ;       // ����
    cout << "-------------" << endl ;
    if (sequence.DestroyTable()){
        cout << "Delete Success" << endl ;
    }
}


//������
void OpSlL(){
    SingleList singleList ;
    singleList.InitList_L() ;
    singleList.CreateList_R(6) ;
    singleList.ListPrint() ;
    if(singleList.DestroyList()){
        cout << "Having Deleting !!!" << endl ;
    }
    cout << "-----------" << endl ;
    SingleList singleList1 ;
    singleList1.InitList_L() ;
    singleList1.CreateList_H(6) ;
    singleList1.ListPrint() ;
    cout << "-----------" << endl ;
    singleList1.ListInsert_L(2,56);
    singleList1.ListPrint() ;
    singleList1.ListInsert_L(6, 90) ;
    singleList1.ListPrint() ;
    singleList1.ListInsert_L(1,67) ;
    singleList1.ListPrint() ;
    cout << "-----------" << endl ;
    if(singleList1.DestroyList()){
        cout << "Having Deleting !!!" << endl ;
    }
}


//˫����
void OpDll(){
    DoubleLinkedList doubleLinkedList ;
    if(doubleLinkedList.InitTDoubleList()){
        cout << "Create a doublelinkedlist successfully" << endl ;
    }

    doubleLinkedList.CreateList_H(10) ;
    doubleLinkedList.DisplayLink() ;

    DoubleLinkedList doubleLinkedList1 ;
    if(doubleLinkedList1.InitTDoubleList()){
        cout <<"Create an another doubleLinkedList successfully" << endl ;
    }
    doubleLinkedList1.CreateList_T(10) ;
    doubleLinkedList1.DisplayLink() ;
}

void BST() {
    bst bstTree ;
    int n ;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bstTree.root = bstTree.InsertNode(bstTree.root, x);
    }
    bstTree.InOrderTraversal() ;

}

int main()
{

    cout << "The Function is created to show relevant basic operation in these chapters from Table to sorting !!!" <<endl ;
    int Chapter = -1 ;
    cout << "Please input the number for the Chapter:" ;
    cin >> Chapter ;

    while (Chapter != -1){
        switch (Chapter) {
            case 1:{
                break;
            }
            case 2: {

                cout << "1~6 �ֱ����̬˳������������˫������ѭ��������ѭ��˫������̬����" << endl ;
                int num = -1 ;
                cout << "Please input the number :" ;
                cin >> num ;
                switch (num) {
                    case 1 :{
                        OpSeq() ;
                        break ;
                    }
                    case 2:{
                        OpSlL() ;
                        break;
                    }
                    case 3:{
                        OpDll() ;
                        break ;
                    }
                }

                break;

            }
            case 3:{
                //ջ�����
                break ;
            }
            case 4:{
                //��
                break ;
            }
            case 5:{
                // ��
                break;
            }
            case 6:{
                //ͼ
                break ;
            }
            case 7:{
                BST() ;
                break;
            }
            case 8:{
                cout << "Insertion Sort" << endl ;
                cout << "Please ensure the length of the arr :" ;
                int num = -1 ;
                cin >> num ;
                ElemType arr[num] ;
                for (int i = 0 ; i < num ; ++ i){
                    cin >> arr[i] ;
                }
                DirectInsertSort(arr , num) ;

                break;
            }
            default:{
                break;
            }

        }
        cout << "Please again input the number for the Chapter:" ;
        cin >> Chapter ;
    }

    cout << "The All process has stopped!" << endl ;
    cout << "Thanks for using !" << endl ;
    return 0 ;
}