//   AUGUSTO ESTEVES CARRERA - 32114842
//   GUSTAVO FERNANDES COSTA - 32161093
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include <iostream>
struct Node
{
	int data;
	Node* next;
  Node* prev;
  std::string nome;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};

LinkedList* Create();
void Destroy(LinkedList* list);
void Insert(LinkedList* list, int data, std::string d);
void Append(LinkedList* list, int data, std::string d);
Node* RemoveHead(LinkedList* list);
Node* RemoveTail(LinkedList* list);
Node* RemoveNode(LinkedList* list, int data); 
Node* GetHead(const LinkedList* list);
Node* GetTail(const LinkedList* list);
Node* GetNode(const LinkedList* list, int data);
int Count(const LinkedList* list);
bool IsEmpty(const LinkedList* list);
void Clear(LinkedList* list);

Node* CreateNode(int data, Node* next, Node* prev, std::string nome);
void DestroyNode(Node* node);

#endif //  __LINKED_LIST_H__