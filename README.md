# Dictionary via Linked Lists
This C++ program implements a dictionary using linked lists, offering efficient organization of words with multiple meanings. The program supports various functionalities such as insertion, deletion, and display.

# Overview
The program organizes words alphabetically in a dictionary structure using linked lists. Each alphabetical section has linked word nodes containing the word and its meanings.

# Classes
1. **wordnode**
   - Represents a node for a word and its meanings.
   - Attributes:
     - `word`: The word.
     - `meaning`: The meaning of the word.
     - `nextword`: Pointer to the next word node.

2. **alphanode**
   - Represents a node for an alphabetical section in the dictionary.
   - Attributes:
     - `alpha`: The alphabet representing the section.
     - `wordptr`: Pointer to the linked list of word nodes.
     - `nextalpha`: Pointer to the next alphabetical section.

3. **dict**
   - Main class managing the dictionary.
   - Attributes:
     - `head`: Pointer to the head of the alphabetical sections.
   - Functions:
     - `insert`: Inserts a new word with its meaning.
     - `search`: Searches for a word and displays its meanings.
     - `delete_word`: Deletes a word from the dictionary.
     - `display_wordnodes`: Displays the entire dictionary.

# Functionalities
1. **Insert Word:**
   - Adds a new word to the dictionary along with its meanings.
2. **Search Word:**
   - Searches for a word and displays its meanings.
3. **Delete Word:**
   - Deletes a word from the dictionary.
4. **Display Dictionary:**
   - Displays the entire dictionary with words organized alphabetically.

## How to Use
1. Compile the program using a C++ compiler.
2. Run the compiled executable.
3. Follow the on-screen prompts to insert, search, or delete words.

## Sample Output
```
Dictionary:
1. Enter a new word
2. Display the dictionary
3. Exit

Please enter the word you want to add(in lowercase letters):
apple
Please enter meaning of the word you entered:
A fruit
To continue enter y.

Dictionary:
a------->apple:A fruit-->
NULL
```

## Contributing
Feel free to contribute to enhance the functionality or improve the code. Create a pull request, and your contributions will be considered.
