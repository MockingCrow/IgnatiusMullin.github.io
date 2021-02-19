#include "util.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;
std::string convToLower(std::string src) {
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords) {
    int temp = 0;
    set<string> splitWords;

    for (unsigned int i = 0; i <= rawWords.size(); i++) {

        if (rawWords[i] == ',' || rawWords[i] == '.' || rawWords[i] == '\'' || rawWords[i] == ' '
            || i == rawWords.size()) {
            string tempStr = rawWords.substr(temp, i - temp);

            if (tempStr.size() >= 2) {
                splitWords.insert(tempStr);
            }

            temp = i;
            while (rawWords[temp] == ' ' || rawWords[temp] == '\'' || rawWords[temp] == '.' || rawWords[temp] == ',') {
                temp++;
            }
        }
    }

    return splitWords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string& ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string& rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
std::string& trim(std::string& s) { return ltrim(rtrim(s)); }
