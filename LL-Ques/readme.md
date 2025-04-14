1. Head pointer not given -- Just the node which has to be deleted
node->data=node->next->data;
node->next=node->next->next;