// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class OptimalBST {
private:
    vector<vector<double>> cost; // Cost table
    vector<vector<int>> root;    // Root table
    vector<double> cumulativeProb; // Cumulative probabilities for quick sum calculation

    // Helper function to calculate the sum of probabilities in range [i, j]
    double sumProbabilities(int i, int j) {
        return cumulativeProb[j + 1] - cumulativeProb[i];
    }

public:
    void constructOBST(const vector<int>& keys, const vector<double>& probabilities) {
        int n = keys.size();
        cost.resize(n, vector<double>(n, 0));
        root.resize(n, vector<int>(n, 0));
        cumulativeProb.resize(n + 1, 0);

        // Compute cumulative probabilities
        for (int i = 0; i < n; i++) {
            cumulativeProb[i + 1] = cumulativeProb[i] + probabilities[i];
        }

        // Base case: cost of a single key
        for (int i = 0; i < n; i++) {
            cost[i][i] = probabilities[i];
            root[i][i] = i;
        }

        // Fill the cost table for chains of length 2 to n
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                cost[i][j] = INT_MAX;

                // Try making each key in range [i, j] the root
                for (int r = i; r <= j; r++) {
                    double leftCost = (r > i) ? cost[i][r - 1] : 0;
                    double rightCost = (r < j) ? cost[r + 1][j] : 0;
                    double totalCost = leftCost + rightCost + sumProbabilities(i, j);

                    if (totalCost < cost[i][j]) {
                        cost[i][j] = totalCost;
                        root[i][j] = r;
                    }
                }
            }
        }

        // Print the minimum cost
        cout << "Minimum cost of Optimal BST: " << cost[0][n - 1] << endl;

        // Print the structure of the OBST
        cout << "Structure of the Optimal BST:" << endl;
        printOBST(0, n - 1, keys, "Root");
    }

    void printOBST(int i, int j, const vector<int>& keys, const string& relation) {
        if (i > j) return;

        int r = root[i][j];
        cout << relation << ": " << keys[r] << endl;

        printOBST(i, r - 1, keys, "Left child of " + to_string(keys[r]));
        printOBST(r + 1, j, keys, "Right child of " + to_string(keys[r]));
    }
};

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    vector<int> keys(n);
    vector<double> probabilities(n);

    cout << "Enter the keys (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "Enter the search probabilities for each key: ";
    for (int i = 0; i < n; i++) {
        cin >> probabilities[i];
    }

    OptimalBST obst;
    obst.constructOBST(keys, probabilities);

    return 0;
}
