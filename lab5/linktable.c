//
//  linktable.c
//  lab5
//
//  Created by 高旭 on 2017/10/20.
//  Copyright © 2017年 高旭. All rights reserved.
//

#include"linktable.h"
#include<stdlib.h>
#include<stdio.h>
/*LinkTable Type*/
typedef struct LinkTable
{
    tLinkTableNode *head;
    tLinkTableNode *tail;
    int nodeCount;
}tLinkTable;
/*Create a LinkTable*/
tLinkTable* CreateLinkTable()
{
    tLinkTable* pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkTable==NULL)
    {
        return NULL;
    }
    pLinkTable->head = NULL;
    pLinkTable->tail =NULL;
    pLinkTable->nodeCount = 0;
    return pLinkTable;
}
/*Delete a LinkTable*/
int DeleteLinkTable(tLinkTable* pLinkTable)
{
    if(pLinkTable==NULL)
    {
         return  FAILURE;
    }
    while(pLinkTable->head!=NULL)
    {
        tLinkTableNode *tmp = pLinkTable->head;
        pLinkTable->head = pLinkTable->head->next;
        free(tmp);
    }
    pLinkTable->head = NULL;
    pLinkTable->tail=NULL;
    pLinkTable->nodeCount = -1;
    free(pLinkTable);
    return SUCCESS;
}
/*Add a LinkTableNode*/
int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
    {
        return  FAILURE;
    }
    if(pLinkTable->head ==  NULL)
    {
        pLinkTable->head = pNode;
        pLinkTable->tail = pNode;
        pLinkTable->nodeCount = 1;
    }
    else
    {
        pLinkTable->tail->next = pNode;
        pLinkTable->tail = pNode;
        pLinkTable->nodeCount++;    
    }
    return SUCCESS;
}
int DelLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
    {
       return  FAILURE;
    }
    if(pLinkTable->head == pNode)
    {
        tLinkTableNode *tmp  = pLinkTable->head;
        pLinkTable->head = pLinkTable->head->next;
        free(tmp);
        pLinkTable->nodeCount--;
    }
    if(pLinkTable->nodeCount== 0)
    {
        pLinkTable->tail = NULL;
        return     FAILURE;
    }
    tLinkTableNode *tmp = pLinkTable->head;
    while(tmp!=NULL)
    {
    if(tmp->next == pNode)
    {    
        tmp->next = pNode->next;
        pLinkTable->nodeCount--;
        if(pLinkTable->nodeCount == 0)
        {
            pLinkTable->tail = NULL;
        }
         return SUCCESS;
     }
    tmp = tmp->next;
    }
    return FAILURE;
}
/*Search a LinkTableNode from LinkTable*/
tLinkTableNode* SearchLinkTableNode(tLinkTable* pLinkTable, int Condition(tLinkTableNode* pNode,void* args),void* args)
{
    if(pLinkTable==NULL||Condition==NULL)
    {
        return NULL;
    }
    tLinkTableNode*pNode=pLinkTable->head;
    //while(pNode!=pLinkTable->tail)
    while(pNode!=NULL)
    {
        if(Condition(pNode,args)==SUCCESS)
        {
            return pNode;
        }
        pNode=pNode->next;
    }
    return NULL;
}
/*get LinkTableHead*/  
tLinkTableNode* GetLinkTableHead(tLinkTable* pLinkTable)
{
    if(pLinkTable == NULL || pLinkTable->head == NULL)
    {
        return NULL;
    }
    return pLinkTable->head;
}
/*get NextLinkTableNode*/ 
tLinkTableNode* GetNextLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    return NULL;

    tLinkTableNode *tmp  =  pLinkTable->head;
    while(tmp!=NULL)
    {
    if(tmp == pNode)
    {
        return tmp->next;
    }
    tmp = tmp->next;
    }
    return NULL;
}

