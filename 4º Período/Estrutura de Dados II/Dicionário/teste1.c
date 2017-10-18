
#include "iDictionary.h"
#include "iDoublyCircularLinkedList.h"
#include <string.h>

void main() {
    iLinkedList list;
    Dictionary dictionary;

    init(&list);
    dInit(&dictionary);

    put(&dictionary, "Nome 2", add(&list, 16));
    put(&dictionary, "Nome 1", addFirst(&list, 13));

    setFirstValue(&dictionary, "Nome 2");

    node *keys = getKeys(&dictionary);
    Node *fValue = (Node*) getValues(&dictionary);
    show(&list);

    printf("Dictionary 0: %d", getKeys(&dictionary)->value);
    printf("Dictionary 1: %d", getKeys(&dictionary)->next->value);
}