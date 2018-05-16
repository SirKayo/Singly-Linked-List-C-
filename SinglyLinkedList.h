#include<iostream>
class SinglyLinkedList{
    private:
        struct Node{
            int value;
            Node* next;
        };
        Node *head, *tail;
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        void append(int newValue);
        void prepend(int newValue);
        void pop();
        void shift();
        void scroll();

        void findOccurances(int value);

        void insertBefore(int node, int element);
        void insertAfter(int node, int element);
    private:
        void findOccurances(Node* node, int value);
        Node* findSecondLast(Node* node);

        void scroll(Node* node);

        void insertBefore(Node* current, int node, int element);
        void insertAfter(Node* current, int node, int element);

        void destroyer(Node* node);
};

SinglyLinkedList::SinglyLinkedList(){
    head=nullptr;
    tail=nullptr;
}
SinglyLinkedList::~SinglyLinkedList(){
    destroyer(head);
}
void SinglyLinkedList::append(int newValue){
    Node* newNode = new Node;

    newNode->value=newValue;
    newNode->next=nullptr;
    
    if(head==nullptr){
        head=newNode;
    }else{
        tail->next=newNode;
    }
    tail=newNode;
}
void SinglyLinkedList::prepend(int newValue){
    Node* newNode = new Node;
    newNode->value=newValue;

    if(head==nullptr){
        newNode->next=nullptr;
        tail=newNode;
    }else{
        newNode->next=head;
    }
    head=newNode;
}
void SinglyLinkedList::pop(){
    Node* newTail=findSecondLast(head);
    newTail->next=nullptr;

    delete tail;
    tail=newTail;
}
void SinglyLinkedList::shift(){
    Node* newHead=head->next;

    delete head;
    head=newHead;
}
void SinglyLinkedList::scroll(){
    scroll(head);
}

void SinglyLinkedList::insertBefore(int node, int value){
    if(head->value==node){
        prepend(node);
    }else{
        insertBefore(head,node,value);
    }
}
void SinglyLinkedList::insertAfter(int node, int value){
    if(tail->value==node){
        append(node);
    }else{
        insertAfter(head,node,value);
    }
}
void SinglyLinkedList::insertBefore(Node* current, int node, int value){
    if(current->next->value != node){
        insertBefore(current->next,node,value);
    }else{
        Node* newNode= new Node;
        newNode->value = value;
        newNode->next = current->next;
        current->next = newNode;
    }
}void SinglyLinkedList::insertAfter(Node* current, int node, int value){
    if(current->value != node){
        insertAfter(current->next,node,value);
    }else{
        Node* newNode= new Node;
        newNode->value = value;
        newNode->next = current->next;
        current->next = newNode;
    }
}

void SinglyLinkedList::findOccurances(int value){
    findOccurances(head,value);
}
void SinglyLinkedList::findOccurances(Node* node, int value){
    if(node!=nullptr){
        if(node->value==value){
            std::cout<<"Found occurance of "<<value<<" at address: "<<node<<std::endl;
        }
        findOccurances(node->next,value);
    }
}
SinglyLinkedList::Node* SinglyLinkedList::findSecondLast(Node* node){
    if(node->next==tail)
        return node;
    findSecondLast(node->next);
}
void SinglyLinkedList::scroll(Node* node){
    if(node!=nullptr){
        std::cout<<node<<" "<<node->value<<std::endl;
        scroll(node->next);
    }
}
void SinglyLinkedList::destroyer(Node* node){
    if(node!=nullptr){
        destroyer(node->next);
        delete node;
    }
}