//
// Created by 24887 on 2023/10/20.
//

#include "OrthogonallistGraph.h"
#include <iostream>
using namespace std ;


void Graph4::InitOLGrpah(OLGraph &G) {
    G.numVertexs = 0 ;
    G.numArcs = 0 ;
    G.vertexList4 = new VertexNode4 [MaxSize4] ;

    int i ;
    for (i = 0 ; i < MaxSize4 ; i ++){
        //��ͬͷ����Ļ�
        G.vertexList4[i].headList = new ArcNode  ;
        G.vertexList4[i].headList->nextHeadArc = nullptr ;
        G.vertexList4[i].headList->nextTailArc = nullptr ;

        //��ͬβ����Ļ�
        G.vertexList4[i].tailList = new ArcNode ;
        G.vertexList4[i].tailList->nextTailArc = nullptr ;
        G.vertexList4[i].tailList->nextHeadArc = nullptr ;
    }

    cout << "�Ѿ���ʼ��ʮ������" << endl ;
}

void Graph4::CreateOLGraph(OLGraph &G) {
    printf("�����붥�����ͻ���:");
    cin >> G.numVertexs >> G.numArcs ;

    //���붥������
    int i , j , k ;
    for (i = 0 ; i < G.numVertexs ; i ++){
        fflush(stdin) ;
        printf("�������%d��������Ϣ:", i + 1);
        cin >> G.vertexList4[i].vertexData ;

    }

    int w ;

    for (k = 0 ; k < G.numArcs ; k ++){
        printf("�����뻡(Ai, Aj)��ͷ��β���㼰��Ȩֵ:");
        cin >> i >> j >> w ;

        //���������
        ArcNode * s ;
        s = new ArcNode  ;
        s->arcData = w ;
        s->headVertex = i -1 ;
        s->tailVertex = j -1 ;

        //ͷ�巨
        s->nextHeadArc = G.vertexList4[i-1].headList->nextHeadArc ;
        G.vertexList4[i-1].headList->nextHeadArc = s ;

        //ͷ�巨������ͬ��β���
        s->nextTailArc =  G.vertexList4[j-1].tailList->nextTailArc ;
        G.vertexList4[j-1].tailList->nextTailArc = s ;


    }
}

void Graph4::DisplayOLGraph(OLGraph G) {
    int i;
    ArcNode *p;
    for (i = 0; i < G.numVertexs; i++)
    {
        printf("����:%c\n", G.vertexList4[i].vertexData);
        // ��ͬͷ����Ļ�����
        printf("\t��ͬͷ����Ļ�:");
        p = G.vertexList4[i].headList;
        while (p->nextHeadArc)
        {
            p = p->nextHeadArc;
            printf("(%c)%d(%c) => ",
                   G.vertexList4[p->headVertex].vertexData,
                   p->arcData,
                   G.vertexList4[p->tailVertex].vertexData);
        }
        printf("NULL\n");
        // ��ͬβ����Ļ�����
        printf("\t��ͬβ����Ļ�:");
        p = G.vertexList4[i].tailList;
        while (p->nextTailArc)
        {
            p = p->nextTailArc;
            printf("(%c)%d(%c) => ",
                   G.vertexList4[p->headVertex].vertexData,
                   p->arcData,
                   G.vertexList4[p->tailVertex].vertexData);
        }
        printf("NULL\n");
    }

}
