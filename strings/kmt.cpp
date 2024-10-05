#include <iostream>
#include <string>
#include <algorithm>  // For sort, reverse, etc. // For next_permutation
#include <sstream>    // For stringstream (to convert between string and int)
#include <vector>     // For splitting a string
#include <cctype>     // For isdigit()

using namespace std;

void computeLPSArray(const string& pattern, vector<int>& lps) {
    int M = pattern.size();
    int length = 0; // length of the previous longest prefix suffix
    lps[0] = 0;     // LPS[0] is always 0
    int i = 1;      // i starts from 1 since lps[0] is already known

    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {  // (pattern[i] != pattern[length])
            if (length != 0) {
                length = lps[length - 1];
                // do not increment i here
            } else { 
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string& text, const string& pattern) {
    int N = text.size();
    int M = pattern.size();
    
    // Create the LPS table
    vector<int> lps(M);
    computeLPSArray(pattern, lps);
    
    int i = 0;  // index for text[]
    int j = 0;  // index for pattern[]
    
    while (i < N) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        // A match is found
        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  // Prepare for the next match, using LPS
        }

        // Mismatch after j matches
        else if (i < N && text[i] != pattern[j]) {
            // Don't match lps[0..lps[j-1]] characters, they will match anyway
            if (j != 0) {
                j = lps[j - 1];  // Fall back using LPS
            } else {
                i++;  // Move to the next character in the text
            }
        }
    }
}

