class Node
{
    private:
        int payload;
        Node* nextNode;
        Node* prevNode;

    public:
        Node(int payload);
        int getPayload();
        void setPayload(int c);
        Node* getNextNode();
        Node* getPrevNode();
        void setNextNode(Node* n);
        void setPrevNode(Node* n);
        void display();
};