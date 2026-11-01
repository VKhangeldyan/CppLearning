int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

     SinglyLinkedListNode* node1 = head1;
     SinglyLinkedListNode* node2 = head2;
     
     while(node1 != node2) {
        
        if(node1 == nullptr) {
            node1 = head2;
        } else {
            node1 = node1->next;
        }
        
        if(node2 == nullptr) {
            node2 = head1;
        } else {
            node2 = node2->next;
        }
     }
     return node1->data;

}