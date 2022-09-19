/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;


// devlope a single player matching game
// if right, +1, if wrong, -1

// commands are stored in commands.csv as - command, "desc"
// commands to be added are in a list on the website

// player profiles are in profiles.csv to store names and current points


// commands.csv is loaded into a singly linked list that store 2 parameters per Node
// user inputed name and poins are loaded from profiles.csv into a profiles array, all pairs will be loaded at the front(index 0)

// display a main menu options being:
// 1. Game rules, 2. Play Game, 3. Load Previous Game, 4. Add Command, 5. Remove Command, 6. Exit
// each option returns to main menu after done


void game_rules()
{
    cout << "Rules of this game: this game is a matching game, meant to help you learn a few of the many linux commands. When you play the game a command will be displayed on the top, all you have to do is select the correct choice out of the three options below it by typing either 1, 2, or 3 and entering. Upon each correct answer, you are awarded 1 point and with each incorrect answer you are deducted a point. Be careful to guess correctly or you might end up with a negative score.\n\n";
    system("pause");
}

class Node
{
public:
    Node(char* command, char* desc);
    char command[10];
    char desc[90];
    class Node* nextPtr;
};

Node::Node(char command[10], char desc[90])
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

int play_game(Node* pHead)
{
    int temp = 0, which, score = 0;
    Node* tempNode = pHead;
    while (temp < 4 && temp > 30)
    {
        cout << "How many commands would you like to be quized on? (5 - 30)\n";
        cin >> temp;
    }
    for (int i = 0; i < temp; i++)
    {
        which = rand() % 30;
        for (int i = 0; i < which; i++)
        {
            if (i == 0)
            {
                tempNode = pHead->nextPtr;
            }
            else
            {
                tempNode = tempNode->nextPtr;
            }
        }


    }

    return score;
}

int main_menu()
{
    srand(time(NULL));

    char line[100], command[10], desc[90];
    for (int i = 0; i < 100; i++)
    {
        line[i] = '\0';
        i++;
    }
    FILE* infile = fopen("commands.csv", "r");

    fgets(line, 100, infile);
    strcpy(command, strtok(line, ","));
    strcpy(desc, strtok(NULL, "\n"));

    Node* pHead = new Node(command, desc);
    Node* tempNode;

    while (!feof(infile))
    {
        for (int i = 0; i < 100; i++)
        {
            line[i] = '\0';
            i++;
        }

        fgets(line, 100, infile);
        strcpy(command, strtok(line, ","));
        strcpy(desc, strtok(NULL, "\n"));

        tempNode = new Node(command, desc);

        tempNode->nextPtr = pHead;
        pHead = tempNode;
    }
    for (int i = 0; i < 100; i++)
    {
        line[i] = '\0';
        i++;
    }

    Node* now = pHead;
    while (1)
    {
        cout << endl;
        cout << now->command;
        cout << now->desc;
        if (now->nextPtr != nullptr)
        {
            now = now->nextPtr;
        }
        else
        {
            break;
        }
    }



    int choice;
    while (true)
    {
        cout << "Please select and option listed below:\n";
        cout << " 1. Game Rules\n 2. Play Game\n 3. Load Previous Game\n 4. Add Command\n 5. Remove Command\n 6. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            game_rules();
            break;
        case 2:
            play_game(pHead);
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6: // exit
            return 0;
            break;
        }
    }
}

void main()
{
    main_menu();
}
*/