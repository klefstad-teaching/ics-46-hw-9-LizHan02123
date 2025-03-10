#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "Error: " << msg << word1 << "to" << word2 << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int length1 = str1.size();
    int length2 = str2.size();
    if ((length1 - length2) > d)
        return false;
    if ((length2 - length1) > d)
        return false;

    int count = 0;
    int i = 0, j = 0;
    while (i < length1 && j < length2) {
        if (str1[i] == str2[j]) {    //when match
            i++;
            j++;
            continue;
        }

        count++;               //when not match
        if (count > d) 
            return false;

        if (length1 > length2)
            i++;
        else if (length1 < length2)
            j++;
        else{
            i++;
            j++;
        }
    }
    count += (length1 - i) + (length2 - j);
    return count <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        
        string last_word = ladder.back();

        for (const string& word : word_list) {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
                vector<string> new_ladder = ladder;
                new_ladder.push_back(word);

                if (word == end_word)
                    return new_ladder;
                ladder_queue.push(new_ladder);
                visited.insert(word);
            }
        }
    }
    return {}; 
}