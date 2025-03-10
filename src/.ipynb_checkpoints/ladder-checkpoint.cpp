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