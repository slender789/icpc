#include <iostream>
#include <bitset> // For bitset representation

using namespace std;

// Function to demonstrate basic bit manipulation operations
void basicBitManipulation() {
    int num = 29; // Example number: 29 in binary is 11101
    int k = 3;    // Bit position to manipulate (0-indexed)

    // AND operation
    int andResult = num & (1 << k);
    cout << "AND: " << (num & (1 << k)) << " (Is k-th bit set? " << (andResult != 0) << ")" << endl;

    // OR operation
    int orResult = num | (1 << k);
    cout << "OR: " << orResult << " (Set k-th bit)" << endl;

    // XOR operation
    int xorResult = num ^ (1 << k);
    cout << "XOR: " << xorResult << " (Toggle k-th bit)" << endl;

    // NOT operation
    int notResult = ~num;
    cout << "NOT: " << notResult << " (Invert all bits)" << endl;

    // Left shift
    int leftShiftResult = num << 1; // Multiply by 2
    cout << "Left Shift: " << leftShiftResult << endl;

    // Right shift
    int rightShiftResult = num >> 1; // Divide by 2
    cout << "Right Shift: " << rightShiftResult << endl;
}

// Function to demonstrate checking, setting, and clearing bits
void checkSetClearBits() {
    int num = 29; // 11101
    int k = 2;    // Check and manipulate the k-th bit

    // Check if the k-th bit is set
    bool isSet = (num & (1 << k)) != 0;
    cout << "Is k-th bit set? " << (isSet ? "Yes" : "No") << endl;

    // Set the k-th bit
    num = num | (1 << k);
    cout << "Set k-th bit: " << num << endl;

    // Clear the k-th bit
    num = num & ~(1 << k);
    cout << "Clear k-th bit: " << num << endl;

    // Toggle the k-th bit
    num = num ^ (1 << k);
    cout << "Toggle k-th bit: " << num << endl;
}

// Function to demonstrate counting bits
void countBits() {
    int num = 29; // 11101

    // Count set bits
    int count = 0;
    for (int i = 0; i < 32; i++) {
        count += (num >> i) & 1; // Check each bit
    }
    cout << "Number of set bits: " << count << endl;

    // Using bitset for representation
    bitset<32> b(num);
    cout << "Binary representation: " << b << endl;
}

int main() {
    cout << "Basic Bit Manipulation Operations:" << endl;
    basicBitManipulation();
    
    cout << "\nChecking, Setting, and Clearing Bits:" << endl;
    checkSetClearBits();
    
    cout << "\nCounting Bits:" << endl;
    countBits();
    
    return 0;
}
