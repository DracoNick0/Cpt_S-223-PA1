#include "header.h"

void game_rules()
{
    cout << "Rules of this game: this game is a matching game, meant to help you learn a few of the many linux commands. When you play the game a command will be displayed on the top, all you have to do is select the correct choice out of the three options below it by typing either 1, 2, or 3 and entering. Upon each correct answer, you are awarded 1 point and with each incorrect answer you are deducted a point. Be careful to guess correctly or you might end up with a negative score.\n\n";
    system("pause");
}

void clear_string(char line[])
{
    int i = 0;
    while (line[i] != -52)
    {
        line[i] = (char)-52;
        i++;
    } 
}

Node* make_cmd_list()
{
    char line[200], command[10], desc[190];
    FILE* infile = fopen("commands.csv", "r");

    fgets(line, 200, infile);
    strcpy(command, strtok(line, ","));
    strcpy(desc, strtok(NULL, "\n"));

    Node* pHead = new Node(command, desc), * tempNode;

    while (!feof(infile))
    {
        clear_string(line);
        fgets(line, 200, infile);
        strcpy(command, strtok(line, ","));
        strcpy(desc, strtok(NULL, "\n"));

        tempNode = new Node(command, desc);

        tempNode->nextPtr = pHead;
        pHead = tempNode;
    }
    clear_string(line);
    fclose(infile);
    return pHead;
}

void make_profiles_list(char* profile[])
{
    char line[25];
    FILE* infile = fopen("profiles.csv", "r");
    if (infile != NULL)
    {
        while (!feof(infile))
        {
            fgets(line, 25, infile);
            for (int i = 0; i < 23; i++)
            {
                profile[i + 1] = profile[i];
            }
            profile[0] = line;
        }
    }
}

int play_game(Node* pHead)
{
    int temp = 0, temp2 = 0, which, score = 0, numAnswers = 1, counter = 0;
    Node* correctNode = pHead, *fakeNode;
    char fake1[200], fake2[200];
    for (int i = 0; 1; i++)
    {
        if (correctNode->nextPtr != nullptr)
        {
            correctNode = correctNode->nextPtr;
            ++numAnswers;
        }
        else
        {
            break;
        }
    }

    while (counter < 5 || counter > 30) // how many questions?
    {
        cout << "There are " << numAnswers << " commands.\n";
        cout << "How many commands would you like to be quized on? (least 5, max 30)\n";
        cin >> counter;
    }
    system("cls");
    for (int i = 0; i < counter; i++) // goes through all questions.
    {
        temp = 0, temp2 = 0;
        correctNode = pHead;
        which = rand() % numAnswers;
        for (int j = 0; j < which; j++) // gets the correct answer
        {
            correctNode = correctNode->nextPtr;
        }
        temp = which;

        fakeNode = pHead; // gets first fake answer
        do {
            which = rand() % numAnswers;
        } while (which == temp);
        for (int j = 0; j < which; j++)
        {
            fakeNode = fakeNode->nextPtr;
        }
        strcpy(fake1, fakeNode->desc);
        temp2 = which, which = -1;

        fakeNode = pHead; // gets second fake answer
        do {
            which = rand() % numAnswers;
        } while (which == temp || which == temp2);
        for (int j = 0; j < which; j++)
        {
            fakeNode = fakeNode->nextPtr;
        }
        strcpy(fake2, fakeNode->desc);

        cout << "Which is the correct description for the command: "; // asks question
        cout << correctNode->command << endl;
        which = rand() % 3;
        temp = 0;
        for (int j = 0; j < 3; j++)
        {
            cout << j + 1 << ".";
            if (which == j)
            {
                cout << correctNode->desc << endl;
            }
            else
            {
                if (temp == 0)
                {
                    cout << fake1 << endl;
                }
                else
                {
                    cout << fake2 << endl;
                }
                temp++;
            }
        }
        cin >> temp;
        if (temp == which + 1)
        {
            cout << "Correct! +1 point\n\n";
            ++score;
        }
        else
        {
            cout << "Incorrect, -1 point\n\n";
            --score;
        }
    }
    cout << score;
    return score;
}

int getScores()
{
    int score = 0;
    return score;
}

int main_menu()
{
    int choice;
    char name[25], * profile[25];
    Node* pHead;
    pHead = make_cmd_list();
    while (true)
    {
        cout << "Please select and option listed below:\n";
        cout << " 1. Game Rules\n 2. Play Game\n 3. Load Previous Game\n 4. Add Command\n 5. Remove Command\n 6. Exit\n";
        do 
        {
            cin >> choice;
            cout << " Option not valid, enter again: ";
        } while (choice < 1 || choice > 6);
        system("cls");
        switch (choice)
        {
        case 1:
            game_rules();
            break;
        case 2:
            make_profiles_list(profile);
            cout << "What is your name?(less than 20 characters) ";
            cin >> name;
            for (int i = 0; i < 23; i++)
            {
                profile[i + 1] = profile[i];
            }
            /*for (int i = 0; i < 25; i++)
            {
                if (name[i] == '\0')
                {
                    name[i] = ',';
                    name[i + 1] = ;
                }
            }*/
                
            play_game(pHead);
            //profile[0] = (char*)name;

            break;
        case 3:
            // load game
            break;
        case 4:
            // add command
            break;
        case 5:
            // remove command
            break;
        case 6: // exit
            return 0;
            break;
        }
    }
}