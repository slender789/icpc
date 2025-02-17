#include <iostream>
#include <string>
#include <algorithm>  // For sort, reverse, etc. // For next_permutation
#include <sstream>    // For stringstream (to convert between string and int)
#include <vector>     // For splitting a string
#include <cctype>     // For isdigit()

using namespace std;

// Convert string to integer
int stringToInt(const string& str) {
    return stoi(str);  // stoi - string to integer
}

// Convert integer to string
string intToString(int num) {
    return to_string(num);  // to_string - integer to string
}

// Convert char to integer (ASCII value)
int charToInt(char ch) {
    return ch - '0';  // Convert character to digit
}

// Convert integer to char
char intToChar(int num) {
    return num + '0';  // Convert digit to character
}

// Sort a string
string sortString(string str) {
    sort(str.begin(), str.end());
    return str;
}

// Reverse a string
string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

// Search a substring in a string
bool searchString(const string& str, const string& sub) {
    return str.find(sub) != string::npos;  // npos means not found
}

// Split a string by a delimiter
vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);  // Use stringstream to tokenize

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
`
vector<string> splitString(const string& str, const string& delimiter) {
    vector<string> tokens;
    size_t start = 0; // Start position of the substring
    size_t end;       // End position where the delimiter is found

    while ((end = str.find(delimiter, start)) != string::npos) {
        // Extract the substring from start to the position of the delimiter
        tokens.push_back(str.substr(start, end - start));
        // Move the start position past the delimiter
        start = end + delimiter.length();
    }
    // Add the last substring after the last delimiter
    tokens.push_back(str.substr(start));

    return tokens;
}

// Check if a string contains only digits
bool isNumeric(const string& str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

bool hasPrefix(const string& str, const string& prefix) {
    if (str.size() < prefix.size()) {
        return false;
    }
    return str.compare(0, prefix.size(), prefix) == 0;
}

bool hasSuffix(const string& str, const string& suffix) {
    if (str.size() < suffix.size()) {
        return false;
    }
    return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

// O(m x n), KMT is O(m + n)
vector<int> findAllOccurrences(const string& str, const string& sub) {
    vector<int> positions;
    size_t pos = str.find(sub);
    while (pos != string::npos) {
        positions.push_back(pos);
        pos = str.find(sub, pos + 1);  // Search from the next position
    }
    return positions;
}

vector<int> countCharFrequency(const string& str) {
    vector<int> freq(256, 0);  // For all ASCII characters
    for (char ch : str) {
        freq[ch]++;
    }
    return freq;
}

void generateSubsets(const string& str) {
    int n = str.size();
    for (int i = 0; i < (1 << n); ++i) {  // 2^n possible subsets
        string subset = "";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset += str[j];
            }
        }
        cout << subset << endl;
    }
}

bool isPalindrome(const string& str) {
    int n = str.size();
    for (int i = 0; i < n / 2; ++i) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

// =========================================================================== 

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);  // Reduce the prefix
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

int main() {
    string str = "hello world";
    str.erase(0, 6);  // Removes the first 6 characters, str becomes "world"

    string str = "hello world";
    str.replace(0, 5, "hi");  // Replaces "hello" with "hi", resulting in "hi world"

    string str = "abc";
    sort(str.begin(), str.end());  // Sort to start with the lexicographically smallest permutation
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
    // ================================================================

    // String to integer and vice versa
    string strNum = "12345";
    int num = stringToInt(strNum);
    cout << "String to integer: " << num << endl;

    string strFromInt = intToString(num);
    cout << "Integer to string: " << strFromInt << endl;

    // Char to integer and vice versa
    char ch = '7';
    int chToInt = charToInt(ch);
    cout << "Char to integer: " << chToInt << endl;

    char intToCh = intToChar(9);
    cout << "Integer to char: " << intToCh << endl;

    // Sorting a string
    string unsorted = "dcba";
    string sorted = sortString(unsorted);
    cout << "Sorted string: " << sorted << endl;

    // Reversing a string
    string original = "hello";
    string reversed = reverseString(original);
    cout << "Reversed string: " << reversed << endl;

    // Searching a substring
    string mainString = "C++ string manipulation";
    string subString = "string";
    bool found = searchString(mainString, subString);
    cout << "Substring found: " << (found ? "Yes" : "No") << endl;

    // Splitting a string
    string sentence = "C++ is awesome!";
    vector<string> words = splitString(sentence, ' ');
    cout << "Splitting sentence: ";
    for (size_t i = 0; i < words.size(); ++i) {
        cout << words[i] << " ";
    }
    cout << endl;

    // Checking if a string is numeric
    string numericStr = "123456";
    cout << "Is the string numeric? " << (isNumeric(numericStr) ? "Yes" : "No") << endl;

    return 0;
}
