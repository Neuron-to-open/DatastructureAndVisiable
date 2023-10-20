//
// Created by 24887 on 2023/10/20.
//

#include "Adjacencymultiplicity.h"
#include <iostream>
using namespace std ;

void Graph::InitAMLGraph(AMLGraph &G) {
    G.numVertexs = 0 ;
    G.numEdges = 0 ;
    G.MutiList = new VertexNode [MaxVex] ;//��ʼ������ͷ���
    int i ;
    for (i = 0 ; i < MaxVex ;i ++){
        G.MutiList[i].edgeList = new EdgeNode ;
        G.MutiList[i].edgeList->nextHeadEdge = nullptr ;
        G.MutiList[i].edgeList->nextTailEdge = nullptr ;
    }

    cout << "�Ѿ���ʼ���ڽӶ��ر�" << endl ;
}

void Graph::CreateAMLGraph(AMLGraph &G) {
    cout << "�����붥�����ͱ���:" << endl ;
    cin >> G.numVertexs ;
    cin >> G.numEdges ;

    int i , j , k ;
    for (i = 0 ;i < G.numVertexs ; i ++){
        cout << "������" << i+1 << "�����������:" ;
        cin >> G.MutiList[i].vertexData ;
    }

    EdgeType w ;
    for (k = 0 ; k < G.numEdges ; k ++){
        cout << "�������(vi, vj)��ͷ��β���㼰��Ȩֵ:" ;
        cin >> i >> j >> w ;

        EdgeNode* s ;
        s = new EdgeNode ;
        s->visitFlag = 0 ;
        s->edgeData = w ;
        s->headVertex = i -1 ;
        s->tailVertex = j - 1 ;

        //ͷ�巨������ͬͷ����ı߽��
        s->nextHeadEdge = G.MutiList[i-1].edgeList->nextHeadEdge ;
        G.MutiList[i-1].edgeList->nextHeadEdge = s ;

        //ͷ�巨������ͬβ����ı߽��
        s->nextTailEdge = G.MutiList[j-1].edgeList->nextTailEdge ;
        G.MutiList[j-1].edgeList->nextTailEdge = s ;


    }
    cout << "������ڽӶ��ر�Ĵ�����" << endl ;
}

void Graph::DisplayAMLGraph(AMLGraph G) {
    int i ;
    EdgeNode  *p ;
    for (i = 0 ; i < G.numVertexs ; i ++){
        p = G.MutiList[i].edgeList->nextHeadEdge ;
        while (p && !p->visitFlag){
            cout << "��: " << G.MutiList[p->headVertex].vertexData << "<->" << G.MutiList[p->tailVertex].vertexData << " (" << p->edgeData << ")" <<  endl ;
            p->visitFlag =1 ;
            p = p->nextHeadEdge ;
        }
    }
}
