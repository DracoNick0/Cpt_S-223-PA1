class Node
{
public:
    Node(char command[10], char desc[200]);
    char command[10];
    char desc[200];
    class Node* nextPtr;
};