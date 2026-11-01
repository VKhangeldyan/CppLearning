DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    
    if(llist == nullptr) {
        return nullptr;
    }
    
    DoublyLinkedListNode* list1 = llist;
    DoublyLinkedListNode* list2 = nullptr;
    
    while(list1 != nullptr) {
        list2 = list1->prev;
        list1->prev = list1->next;
        list1->next = list2;
        
        llist = list1;
        list1 = list1->prev;
    }
    return llist;
    
}