#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
    // Seed for random number generation
    srand(time(0));

    // Change the path to the desired location
    ofstream outfile("/home/chandu/Downloads/CP/CP_/testcase.txt");

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Generate random n in the range [2, 2e5]
    int n = 2 + rand() % (200000 - 2 + 1);
    outfile << n << endl;

    // Generate n random integers in the range [-1e9, 1e9]
    for (int i = 0; i < n; ++i) {
        int num = -1000000000 + rand() % (2000000000 + 1);
        outfile << num << " ";
    }

    outfile << endl;

    // Close the file
    outfile.close();

    cout << "Test case written to /home/your_username/testcase.txt" << endl;
    return 0;
}
