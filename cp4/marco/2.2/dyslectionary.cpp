#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip> // For std::setw

using namespace std;

int main() {
    vector<vector<string>> groups;
    vector<string> currentGroup;       
    string line;

    while (getline(cin, line)) {
        if (line.empty()) {
            if (!currentGroup.empty()) {         
                groups.push_back(currentGroup);  
                currentGroup.clear();            
            }
            continue;
        }
        currentGroup.push_back(line);           
    }

    if (!currentGroup.empty()) {
        groups.push_back(currentGroup);
    }
    for (int i = 0; i < groups.size(); ++i) {
        int maxWordLength = 0;
        for (const auto& word : groups[i]) {
            if (word.size() > maxWordLength) {
                maxWordLength = word.size();
            }
        }
        
        sort(groups[i].begin(), groups[i].end(), [](const string& a, const string& b) {
            string revA = a;
            string revB = b;
            reverse(revA.begin(), revA.end());
            reverse(revB.begin(), revB.end());
            return revA < revB;
        });

        for (const auto& word : groups[i]) {
            // cout << word << '\n';
            cout << setw(maxWordLength) << word << '\n';
        }
        if(i < groups.size()-1) cout << '\n';
    }

    return 0;
}
