#include <iostream>
#include <vector>

using namespace std;

void combineHelper(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
    if (k == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i <= n; ++i) {
        current.push_back(i);
        combineHelper(i + 1, n, k - 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    combineHelper(1, n, k, current, result);
    return result;
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<vector<int>> combinations = combine(n, k);

    cout << "All possible combinations of " << k << " numbers from 1 to " << n << " are:\n";
    for (const auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
