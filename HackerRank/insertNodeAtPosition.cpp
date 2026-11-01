SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    
     SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
     
     if(position == 0) {
        newNode->next = llist;
        return newNode;
     }
     
     SinglyLinkedListNode* current = llist;
     
     for(int i = 0; i < position - 1; i++) {
        current = current->next;
     }
     
     newNode->next = current->next;
     current->next = newNode;
     
     return llist;

}