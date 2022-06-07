
//   AUGUSTO ESTEVES CARRERA - 32114842
//   GUSTAVO FERNANDES COSTA - 32161093

#include "LinkedList.h"
#include <clocale>
#include <iostream>
using namespace std;
void Print(const LinkedList* list)
{
    int i;
    Node* node = list->head;
    for (i=0; i<list->count; i++)
    {
        cout <<'[' << node->data <<']' << ' ' << node->nome << ' ' << '\n';
        node = node->prev;
    }
    cout << '\n';
}
void PrintReverse(const LinkedList* list)
{
    int i;
    Node* node = list->tail;
    for (i=0; i<list->count; i++)
    {
        cout <<'[' << node->data <<']' << ' ' << node->nome << ' ' << '\n';
        node = node->next;
    }
    cout << '\n';
}
void PrintDoubleListInfo(const LinkedList *list) {
  if (IsEmpty(list)) {
    cout << "Lista vazia!\n";
  } else {
    cout << "Lista:\n";
    Print(list);
    cout << "Lista invertida:\n";
    PrintReverse(list);
  }
}
int main() {
  setlocale(LC_CTYPE, "Portuguese");
  cout
      << "*** Lista Circular Duplamente Ligada/Encadeada (Double Circular Linked List)***\n ";
      LinkedList *list = Create();

  PrintDoubleListInfo(list);
  Insert(list, 1, "Carol");
  Insert(list, 2, "Eric");
  Insert(list, 3, "John");
  Append(list, 4, "Leo");
  Append(list, 5, "Julia");
  Append(list, 6, "Lisa");
  PrintDoubleListInfo(list);
  Clear(list);
  PrintDoubleListInfo(list);
  Insert(list, 11, "Paulo");
  Append(list, 22, "Thomas");
  Insert(list, 33, "Olga");
  Append(list, 44, "Bia");
  Insert(list, 55, "Angela");
  Append(list, 66, "Karen");
  Insert(list, 77, "Adauto");
  PrintDoubleListInfo(list);
  Node *temp = RemoveNode(list, 44);
  cout << "Nó removido -> id: " << temp->data << ", name: " << temp->nome << '\n';
  DestroyNode(temp);
  PrintDoubleListInfo(list);
  temp = RemoveHead(list);
  cout << "Nó removido -> id: " << temp->data << ", name: " << temp->nome << '\n';
  DestroyNode(temp);
  PrintDoubleListInfo(list);
  temp = RemoveTail(list);
  cout << "Nó removido -> id: " << temp->data << ", name: " << temp->nome << '\n';
  DestroyNode(temp);
  PrintDoubleListInfo(list);
  Destroy(list);
  cout << "Fim.\n";
}