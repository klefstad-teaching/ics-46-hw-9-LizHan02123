#include "ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "words.txt"); 

    string start_word, end_word;
    cout << "Enter the start word: ";
    cin >> start_word;
    cout << "Enter the end word: ";
    cin >> end_word;

    if (start_word == end_word) {
        cout << "Error: Start and end words the same" << endl;
        return 1;
    }

    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
    print_word_ladder(ladder);

    return 0;
}