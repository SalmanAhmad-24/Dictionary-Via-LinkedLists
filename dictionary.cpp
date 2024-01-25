#include <iostream>
#include <string>
using namespace std;
class wordnode
{
public:
    string word;
    string meaninig;
    wordnode *nextword;
    wordnode(string s1, string s2)
    {
        word = s1;
        meaninig = s2;
        nextword = NULL;
    }
};
class alphanode
{
public:
    char alpha;
    wordnode *wordptr;
    alphanode *nextalpha;
    alphanode(char c)
    {
        alpha = c;
        wordptr = NULL;
        nextalpha = NULL;
    }
};
class dict
{
public:
    alphanode *head = NULL;
    bool already_present(char c)
    {
        if (head == NULL)
        {
            return false;
        }
        alphanode *temp = head;
        while (temp != NULL)
        {
            if (temp->alpha == c)
            {
                return true;
            }
            temp = temp->nextalpha;
        }
        return false;
    }
    void create_alpha_node(char alphaval)
    {
        if (head == NULL)
        {
            alphanode *n = new alphanode(alphaval);
            head = n;
            return;
        }
        if (already_present(alphaval) == true)
        {

            return;
        }
        alphanode *n = new alphanode(alphaval);
        alphanode *temp = head;
        alphanode *tempnext = temp->nextalpha;
        if (temp->alpha > alphaval)
        {
            head = n;
            n->nextalpha = temp;
            return;
        }
        while (temp->nextalpha != NULL)
        {
            // down
            if (tempnext->alpha > alphaval)
            {
                temp->nextalpha = n;
                n->nextalpha = tempnext;
                return;
            }
            // down
            temp = temp->nextalpha;
            tempnext = tempnext->nextalpha;
        }
        temp->nextalpha = n;
    }
    bool find_word(string word, string mean, alphanode *index)
    {
        bool found = false;
        if (index->wordptr == NULL)
        {
            cout << "The list is empty " << endl;
            return false;
        }
        wordnode *wordhead = index->wordptr;
        wordnode *temp = wordhead; ///////
        while (temp->nextword != NULL)
        {
            if (temp->word == word)
            {
                if (found = false)
                {
                    cout << "The word is already present with meanings as follows " << endl;
                    found = true;
                }
                cout << "word :" << temp->word << "Meaning :" << temp->meaninig;
            }
            temp = temp->nextword;
        }
        bool option = false;
        if (found == true)
        {
            cout << "Do you want to enter another meaning of the same word enter y for yes and n for no " << endl;
            char ch;
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                option = false;
            }
            else if (ch == 'n' || ch == 'N')
            {
                option = true;
            }
        }
        return option;
    }
    bool checkword(string word, string mean, alphanode *index)
    {
        wordnode *n = new wordnode(word, mean);
        wordnode *wordhead = index->wordptr;
        wordnode *wordtemp = wordhead;
        wordnode *wordtempnext = wordtemp->nextword;
        if (find_word(word, mean, index))
        {
            return true;
        }
        if (wordtemp->word == word && wordtemp->meaninig > mean)
        {
            index->wordptr = n;
            n->nextword = wordtemp;
            return true;
        }
        while (wordtemp->nextword != NULL)
        {
            if (wordtempnext->word == word)
            {
                if (wordtempnext->meaninig > mean)
                {
                    wordtemp->nextword = n;
                    n->nextword = wordtempnext;
                    return true;
                }
            }
            wordtemp = wordtemp->nextword;
            wordtempnext = wordtempnext->nextword;
        }
        return false;
    }
    void create_word_node(string word, string mean)
    {
        alphanode *index = head;
        while (index != NULL)
        {
            if (index->alpha == word[0])
            {
                break;
            }
            index = index->nextalpha;
        }
        wordnode *n = new wordnode(word, mean);

        if (index->wordptr == NULL)
        {
            index->wordptr = n;
            return;
        }
        if (checkword(word, mean, index) == true)
        {
            return;
        }
        wordnode *wordhead = index->wordptr;
        wordnode *wordheadtemp = wordhead;
        wordnode *wordheadtempnext = wordheadtemp->nextword;
        if (index->wordptr->word > word)
        {
            index->wordptr = n;
            n->nextword = wordhead;
            return;
        }
        while (wordheadtemp != NULL)
        {
            if (wordheadtempnext->word > word)
            {
                index->wordptr = n;
                n->nextword = wordheadtempnext;
            }
            wordheadtemp = wordheadtemp->nextword;
            wordheadtempnext = wordheadtempnext->nextword;
        }
        wordheadtemp->nextword = n;
    }
    void insert(string word, string meaning)
    {
        char alpha = word[0];
        create_alpha_node(alpha);
        create_word_node(word, meaning);
    }
    void search(string word)
    {
        alphanode *temp = head;
        alphanode *index;
        bool found = false;
        if (head == NULL)
        {
            cout << "The dictionary is empty " << endl;
            return;
        }
        while (temp != NULL)
        {
            if (temp->alpha == word[0])
            {
                index = temp;
                found = true;
            }
            temp = temp->nextalpha;
        }
        if (index->wordptr == NULL || found == false)
        {
            cout << "The word is not present in the dictionary " << endl;
            return;
        }
        wordnode *wordtemp = index->wordptr;
        bool wordfound = false;
        if (temp == NULL)
        {
            cout << "The word is not present in the dictionary " << endl;
            return;
        }
        while (wordtemp != NULL)
        {
            if (wordtemp->word == word)
            {
                if (wordfound == false)
                {
                    cout << "Word is present in the dictionary with the following meaning " << endl;
                    wordfound = true;
                }
                cout << wordtemp->meaninig << " ";
            }
            wordtemp = wordtemp->nextword;
        }
        if (wordfound == false)
        {
            cout << "Word not present in the dictionary " << endl;
            return;
        }
    }
    int count(string word, alphanode *index)
    {
        int count = 0;
        wordnode *temp = index->wordptr;
        while (temp != NULL)
        {
            if (temp->word == word)
            {
                count++;
            }
            temp = temp->nextword;
        }
        return count;
    }
    void clearalpha()
    {
        alphanode *temp = head;
        while (temp != NULL)
        {
            if (temp->wordptr == NULL)
            {
                head = head->nextalpha;
                return;
            }

            if (temp->nextalpha->wordptr == NULL)
            {
                temp->nextalpha = temp->nextalpha->nextalpha;
            }
            temp = temp->nextalpha;
        }
    }
    void delete_word(string word)
    {
        alphanode *temp = head;
        alphanode *index;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->alpha == word[0])
            {
                index = temp;
                found = true;
            }
            temp = temp->nextalpha;
        }
        int counter = count(word, index);
        if (index->wordptr == NULL || found == false || counter == 0)
        {
            cout << "Word is not present in the ddictionary " << endl;
            return;
        }
        wordnode *wordtemp = index->wordptr;
        if (counter == 1)
        {
            while (wordtemp != NULL)
            {
                if (wordtemp->word == word)
                {
                    index->wordptr = index->wordptr->nextword;
                    clearalpha();
                    cout << "The word has been deleted " << endl;
                    return;
                }
                if (wordtemp->nextword->word == word)
                {
                    wordtemp->nextword = wordtemp->nextword->nextword;
                    clearalpha();
                    cout << "The word has been deleted " << endl;
                    return;
                }
                wordtemp = wordtemp->nextword;
            }
        }
        else
        {
            string meaning;
            search(word);
            cout << "Enter meaning of the word which you want to delete " << endl;
            cin >> meaning;
            while (wordtemp != NULL)
            {
                if (wordtemp->word == word && wordtemp->meaninig == meaning)
                {
                    index->wordptr = index->wordptr->nextword;
                    cout << "The word has been deleted " << endl;
                    return;
                }
                if (wordtemp->nextword->word == word && wordtemp->nextword->word == meaning)
                {
                    wordtemp->nextword = wordtemp->nextword->nextword;
                    cout << "The word has been deleted " << endl;
                    return;
                }
                wordtemp = wordtemp->nextword;
            }
        }
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "Dictionary is empty " << endl;
        }
        alphanode *temp = head;
        while (temp != NULL)
        {
            cout << temp->alpha << "->";
            temp = temp->nextalpha;
        }
        cout << "NULL" << endl;
    }
    void display_wordnodes()
    {
        alphanode *temp = head;
        if (temp == NULL)
        {
            cout << "Dictionary is empty " << endl;
        }

        while (temp != NULL)
        {
            cout << temp->alpha << "------->";
            wordnode *tempword = temp->wordptr;
            while (tempword != NULL)
            {
                cout << tempword->word << ":" << tempword->meaninig << "-->";
                tempword = tempword->nextword;
            }
            temp = temp->nextalpha;
            cout << endl;
        }
    }
};
int main()
{
    dict d;
    bool exit = 1;
    while (exit)
    {
        int choice;
        cout << "Dictionary: " << endl
             << "1. Enter a new word" << endl
             << "2. Display the dictionary" << endl
             << "3. Exit" << endl;
        cin >> choice;

        string word;
        string meaning;

        switch (choice)
        {
        case 1:
            cout << "Please enter the word you want to add(in lowercase letters): " << endl;
            cin.ignore(); // Ignore any leftover newline characters
            getline(cin, word);
            cout << "Please enter meaning of the word you entered: " << endl;
            getline(cin, meaning);
            d.insert(word, meaning);
            break;
        case 2:
            d.display_wordnodes();
            char c;
            cout << "To continue enter y." << endl;
            cin >> c;
            break;
        case 3:
            exit = 0;
            break;
        default:
            cout << "Please enter a correct option." << endl;
            break;
        }
    }

    return 0;
}