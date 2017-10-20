//
//  linktable.h
//  lab5
//
//  Created by 高旭 on 2017/10/20.
//  Copyright © 2017年 高旭. All rights reserved.
//
#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_
#define SUCCESS 0
#define FAILURE -1
/*Linktable Node  Type*/
typedef struct LinkTableNode
{
    struct LinkTableNode* next;
}tLinkTableNode;
/*LinkTable Type*/
typedef struct LinkTable tLinkTable;
/*Create a LinkTable*/
tLinkTable* CreateLinkTable(void);
/*Delete a LinkTable*/
int DeleteLinkTable(tLinkTable* pLinkTable);
/*Add a LinkTableNode to LinkTable*/
int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);
/*Delete a LinkTableNode from LinkTable*/
int DelLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);
/*Search a LinkTableNode from LinkTable*/
tLinkTableNode* SearchLinkTableNode(tLinkTable* pLinkTable, int Condition(tLinkTableNode* pNode,void* args),void* args)
/*Get LinkTableHead*/
tLinkTableNode* GetLinkTableHead(tLinkTable* pLinkTable);
/*Get next LinkTableNode*/
tLinkTableNode* GetNextLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);
#endif /* linktable_h */

