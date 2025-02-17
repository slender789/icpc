#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int tc;
    string aux;
    ostringstream output; // Use an ostringstream to build the final output

    while (cin >> tc) {
        int A = 0;
        int B = 0;
        cin.ignore();
        while (tc--) {
            getline(cin, aux);
            vector<string> tokens = splitString(aux, ' ');
            if (tokens[0] == "DROP") {
                A += stoi(tokens[1]);
                output << "DROP 2 " << stoi(tokens[1]) << endl;
            } else {
                int toTake = stoi(tokens[1]);
                if (B == 0) {
                    output << "MOVE 2->1 " << A << endl;
                    B = A;
                    A = 0;
                    B -= toTake;
                    output << "TAKE 1 " << toTake << endl;
                } else {
                    int diff = toTake - B;
                    if (diff <= 0) {
                        diff *= -1;
                        output << "TAKE 1 " << toTake << endl;
                        B -= toTake;
                    } else {
                        output << "TAKE 1 " << B << endl;
                        B = 0;
                        output << "MOVE 2->1 " << A << endl;
                        B = A;
                        A = 0;
                        output << "TAKE 1 " << diff << endl;
                        B -= diff;
                    }
                }
            }
        }
        output << endl; // Add a newline after each test case
    }

    string result = output.str();
    if (result.size() >= 2) {
        result.erase(result.end() - 2, result.end());
    }
    cout << result;

    return 0;
}
