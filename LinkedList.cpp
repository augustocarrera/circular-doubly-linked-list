#include "LinkedList.h"
#include <iostream>

LinkedList* Create()
{
	LinkedList* list = new LinkedList;
	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;

	return list;
}

void Destroy(LinkedList* list)
{
	Clear(list);

	delete list;
	list = nullptr;
}

void Insert(LinkedList* list, int data, std::string nome) 
{
	Node* node = CreateNode(data, list->head, list->tail, nome); 
	if (IsEmpty(list))
	{
		list->head = node;
    list->tail = node;
	}
  else
  {
	  list->head->next = node;
    node->prev = list->head;
  }
  list->head= node;
  node->next = list->tail;
  list->tail->prev= node;
  ++list->count;
}

void Append(LinkedList* list, int data, std::string nome)
{
	Node* node = CreateNode(data, list->head, list->tail, nome);

	if (IsEmpty(list))
	{
		list->tail = node;
		list->head = node;
	}
	else
	{
		list->tail->prev= node;
    node->next = list->tail;
	}
  list->tail= node;
  node->prev = list->head;
  list->head->next = node;
  ++list->count;
}

Node* RemoveHead(LinkedList* lista)
{
    if (lista->head == nullptr) {
        std::cout<<"Lista vazia!";
    }
    Node *node = lista->head;
    Node *aux = lista->head->prev;
    lista->head= aux;
    aux->next = lista->tail;
    lista->tail->prev = aux;
    node->next= nullptr;
    --lista->count; 
    return node;
}

Node* RemoveTail(LinkedList* list)
{
    Node* filhao = list->head;
    if (list->head == nullptr) {
        std::cout<<"Lista vazia!";
    }
    Node *node = list->tail;
    Node *aux = list->tail->next;
    list->tail = aux;
    aux -> prev = list->head;
    list->head->next = aux;
    node->next = nullptr;
    --list->count;
    return node;
}

Node* RemoveNode(LinkedList* list, int data)
{
    if (list->head == nullptr) {
        std::cout<<"Lista vazia!";
    }

    Node* vitima = list->head;
    Node* anterior = nullptr;

    while (vitima->data != data)
    {
        anterior = vitima;
        vitima = vitima->next;
    }
    if (vitima == nullptr) {
        return nullptr;
    }
    if (vitima == list->head) {
        return RemoveHead(list);
    }
    else {
        anterior->next = vitima->next;
        vitima->next->prev = anterior;
        vitima->next = nullptr;
        --list->count;
        return vitima;
        
    }
}
Node* GetHead(const LinkedList* list)
{
	return list->head;
}

Node* GetTail(const LinkedList* list)
{
	return list->tail;
}

Node* GetNode(const LinkedList* list, int data)
{
	Node* node = list->head;
	while (node != nullptr)
	{
		if (node->data == data)
		{
			return node;
		}
		node = node->next;
	}

	return nullptr;
}

int Count(const LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
	return list->head == nullptr && list->tail == nullptr;
}

void Clear(LinkedList *list) 
{
    Node* filhao = list->head;
  
    while (list->count != 0)
    {
        Node* cobaia = filhao;
        filhao = filhao->next;
        delete cobaia;
        --list->count;
    }
    list->head = nullptr;  
    list->tail = nullptr;
    list-> count = 0;
}

Node* CreateNode(int data, Node* next, Node* prev, std::string nome)
{
	Node* node = new Node;
	node->nome = nome;
  node->data = data;
	node->next = next;
  node->prev = prev;
	return node;
}

void DestroyNode(Node* node)
{
	delete node;
	node = nullptr;
}
