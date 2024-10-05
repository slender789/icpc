#include <iostream> // For input and output
#include <vector>   // For using the vector container
#include <cmath>    // For the sqrt function
#include <limits>   // For std::numeric_limits

using namespace std;

// Vector to store results of subproblems
vector<int> vec(60000, -1);

// Recursive function to find the minimum number of perfect squares that sum up to 'num'
int recurF(int num, int cont) {
    // Variable to store the result; initialized to a large value
    int res = numeric_limits<int>::max(); // Use a large value to find the minimum

    // Base case: if num is 1, we need one square (1^2)
    if (num == 1) return cont + 1;

    // Base case: if num is 0, we don't need any squares
    if (num == 0) return cont;

    // Calculate the integer square root of num
    int sq = (int)sqrt(num);

    // If num is a perfect square, we can return the count of squares used + 1
    if (num == sq * sq) return cont + 1;

    // Increment count for the current square we're considering
    cont++;

    // Iterate over all perfect squares less than or equal to num
    for (int i = sq; i > 0; i--) {
        // Check if the result for the subproblem (num - i*i) is already computed
        if (vec[num - i * i] != -1) {
            // If it is, use the stored result to update res
            res = min(res, vec[num - i * i] + cont);
        } else {
            // Otherwise, compute the result recursively
            int ans = recurF(num - i * i, cont);
            // Update res with the minimum value found
            res = min(res, ans);
            // Store the computed result for the subproblem
            vec[num - i * i] = ans - cont; // Store only the difference
        }
    }
    
    return res; // Return the minimum count of perfect squares
}

int main() {
    int m; // Variable to hold the input number
    cout << "Enter a number: ";
    cin >> m; // Read the input number

    // Call the recursive function and output the result
    cout << "Minimum number of perfect squares for " << m << " is: " << recurF(m, 0) << endl;

    return 0; // Indicate successful completion of the program
}
