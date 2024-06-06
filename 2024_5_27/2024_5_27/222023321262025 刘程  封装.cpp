
#define _CRT_SECURE_NO_WARNINGS
//vs2022
// 
//  main.c
//  LinkedList
//
//  Created by Eason on 2020/7/29.
//  Copyright ? 2020 Eason. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "string.h"


class LinkList {

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int State;
typedef int ElemType;

private:
    ElemType data;   //�������ݲ���
    LinkList* L;   //ָ�������һ���
public:
    LinkList() {
        InitLinkList();
    }
    LinkList(LinkList& p) {

        this->data = p.data;
        if (p.L == NULL) {
            this->L = (LinkList*)malloc(sizeof(LinkList));
        }
        else {
            L = p.L;
        }
    }
    LinkList& operator=(LinkList& p) {
        this->data = p.data;
        L = p.L;//ֱ�ӽ���һ�������ַ

        return *this;//������
    }

    ~LinkList() {
        clearList();
    }
    //��ʼ��������
    State InitLinkList() {
        L = (LinkList*)malloc(sizeof(LinkList));   //Ϊͷ�������ڴ�
        if (!L) {   //���ͷ��㲻���ڣ��������ڴ�ʧ���򷵻�ERROR
            return ERROR;
        }
        else {   //���ͷ��������˵����ʼ���ɹ�
            return OK;
        }
        L = NULL;   //��ʼ������ͷ����ָ����Ϊ��
    }

    //�������Ƿ�Ϊ��
    State isEmpty() {
        if (L) {   //�ж�ͷ����ָ�����Ƿ�Ϊ��
            return FALSE;   //ͷ����ָ����ǿ��򷵻�FALSE��
        }
        else {
            return TRUE;   //ͷ���ָ����Ϊ���򷵻�TRUE��
        }
    }

    //��õ�����ĳ���
    State listLength() {
        int i = 0;  //����������ʼΪ0
        LinkList* p;  //������ʱ���
        p = L;  //��������׸����
        while (p) {   //����˽������������+1������ָ����һ��㣬ѭ������
            i++;
            p = p->L;
        }
        return i;  //���ص�����ĳ���
    }

    //������Ĳ���
    State insertList(int i, ElemType e) {
        LinkList* p;  //������ʱ���
        p = L;   //��ʱ���ָ��ͷ���
        int j = 1;   //λ�ü�����
        while (p && j < i) {  //��Ϊ������Ĳ�����Ҫ���뵽��ǰ���ĺ󷽣����Լ�������ʼΪ1
            p = p->L;  //�����û�е�ָ��λ�õ�ǰ������������½���
            j++;  //λ�ü�����+1
        }
        if (!p) {  //���p��������˵�������еĽ�����ﲻ����������������޷����룬���������������½���
            return ERROR;
        }
        LinkList* q;  //������q
        q = (LinkList*)malloc(sizeof(LinkList));  //Ϊ���q�����ڴ�ռ�
        q->data = e;  //Ϊq����������ָ��ֵ
        q->L = p->L;  //������ľ��䷽ʽ���ֽ������Lָ��ǰ����L���
        p->L = q;  //��������Ϊǰ����L���
        return OK;
    }

    //�������ɾ��
    State deleteList(int i, ElemType* e) {
        LinkList* p;  //������ʱ���
        p = L;  //����ʱ���ָ��ͷ���
        int j = 1;  //������
        while (p && j < i) {  //�ж�p����Ƿ���ڣ����Ҽ��������ܴ���Ҫɾ������λ��
            p = p->L;  //��������������������
            j++;  //������+1
        }
        if (!p) {   //���p������˵��������Ľ����������Ҫɾ����λ�ã��޷�ɾ�������������������½���
            return ERROR;
        }
        LinkList* q;  //������ʱ���
        q = p->L;  //��Ҫɾ���Ľ�㸳��q
        p->L = q->L;  //��Ҫɾ��������һ��㸳��Ҫɾ��������һ��㣬�����ͱܿ���Ҫɾ���Ľ��
        *e = q->data;  //��Ҫɾ���Ľ���������ֵ��e���Ա��ݷ���
        free(q);  //�ͷ�q�����ڴ����򣬼�ɾ����ָ���Ľ��
        return OK;
    }

    //���������
    State clearList() {
        LinkList* p, *q;  //����������ʱ���
        p = L;  //��p��ǰ��Ϊͷ������һ���
        while (p) {  //���p���ڣ�����û��ɾ����ɣ�
            q = p->L;  //��q��Ϊp������һ��㣬Ȼ��pɾ�����ٽ�q����p�����Ļ����൱��pһֱ�����ɾ��
            free(p);
            p = q;
        }
        L = NULL;  //ȫ��ɾ���󣬽�ͷ����ָ�����ÿգ������������Ϊ����
        return OK;
    }

    //��ȡ��������ĳ��λ�õ�Ԫ��
    State getElem(int i, ElemType* e) {
        LinkList* p;  //������ʱ���
        p = L;   //��p����Ϊ�׸����
        int j = 1;  //������
        while (p && j < i) {   //�ڻ�������Ӧ��λ����p���ڵ�����¼���ѭ��
            p = p->L;   //�����������½���
            j++;   //������+1
        }
        if (!p) {   //�������ѭ������Ϊp�������ˣ���˵����λ��û�н�㣬����ERROR
            return ERROR;
        }
        *e = p->data;   //����Ӧλ���ϵ�Ԫ�صĸ�ֵ��e���ڷ���
        return *e;   //����ָ��λ���ϵ�������
    }

    //�жϵ��������Ƿ���ĳ��Ԫ��,����У����������ڵ�λ����Ϣ
    State localElem(ElemType e) {
        LinkList* p;  //������ʱ���
        p = L;  //����ʱ�����Ϊ�׸����
        int j = 1;  //����������Ϊ��ǰΪ�׸���㣬���Լ������ĳ�ʼֵΪ1
        while (p) {   //���p������ѭ�����½����ж�
            if (p->data == e) {   //����ҵ��˶�Ӧ����ֵ�򽫶�Ӧ�ļ�������ֵ���ؼ�Ϊ��Ӧλ����Ϣ
                return j;
            }
            p = p->L;  //������Ƕ�Ӧ��ֵ���������Ѱ��
            j++;  //������+1
        }
        return ERROR;  //һֱpΪ��������ѭ������˵��û�ж�Ӧ����ֵ
    }

    //����������ǰ�巨��
    State headCreatList() {
        L = (LinkList*)malloc(sizeof(LinkList));  //��������������Ϊͷ�������ڴ�
        L = NULL;   //������ͷ����ָ����Ϊ��
        for (int i = 1; i < 9; i++) {   //��1-9����ǰ�巨�ķ�ʽ���뵥����
            LinkList* p = (LinkList*)malloc(sizeof(LinkList));  //�½������Ϊ������ڴ�
            p->data = i; //���½���������������Ϊi��ֵ
            p->L = L;  //��ӵ�ͷ������һ��㣬��ͷ�巨
            L = p;  //��ͷ����ָ��������Ϊ���½�㣬ͷ�����
        }
        return OK;
    }

    //������������巨��
    State tailCreatList() {
        (L) = (LinkList*)malloc(sizeof(LinkList));  //��������������Ϊͷ�������ڴ�
        LinkList* t;  //������ʱ����ʾβָ��
        t = (L);  //βָ��ָ��ͷ��㣬˵����ʱ��Ϊ������
        for (int i = 5; i < 14; i++) {   //��5-14��ֵ����β�巨���뵥����
            LinkList* p = (LinkList*)malloc(sizeof(LinkList));  //�½���㲢�����ڴ�
            p->data = i;  //���½���������������Ϊ��ǰiֵ
            t->L = p;  //βָ��ָ���½����
            t = p;  //���½��������Ϊβ���
        }
        t->L = NULL;  //β����ָ����Ϊ��
        return OK;
    }
    //������Ĵ�ӡ
    State printLinkList() {
        LinkList* p;  //������ʱ���
        p = L;  //��p����Ϊ�׸����
        int i = 1;  //������
        while (p) {  //�жϵ�ǰ����Ƿ����
            printf("��%d������Ԫ��ֵΪ%d\n", i, p->data);  //�����������������д�ӡ
            p = p->L;  //���¼�������
            i++;  //������+1
        }
        return OK;
    }
};
