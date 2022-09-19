#include "List.h";

Node::Node(char command[], char desc[])
{
    int i = 0;
    while (command[i] != '\0')
    {
        this->command[i] = command[i];
        i++;
    }
    i = 0;
    while (desc[i] != '\0')
    {
        this->desc[i] = desc[i];
        i++;
    }
    this->nextPtr = nullptr;
}