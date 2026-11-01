bool has_cycle(Node* head) {
    
    if(head == nullptr) {
        return false;
    }
    
    Node* node1 = head;
    Node* node2 = head;
    
    while(node2 != nullptr && node2->next != nullptr) {
        node2 = node2->next->next;
        node1 = node1->next;
        
        if(node1 == node2) {
            return true;
        }
    }
    return false;
}