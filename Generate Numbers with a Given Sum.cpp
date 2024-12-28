#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> generateNumbersWithSum(int n, int S) {
    vector<int> numbers(n, 0);
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        int number = (i == n - 1) ? (S - sum) : rand() % (S - sum + 1);
        numbers[i] = number;
        sum += number;
    }

    return numbers;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int n, S;
    cout << "Enter the number of integers (n): ";
    cin >> n;
    cout << "Enter the sum (S): ";
    cin >> S;

    if (n <= 0 || S < 0) {
        cout << "Invalid input! n must be greater than 0 and S must be non-negative." << endl;
        return 1;
    }

    vector<int> result = generateNumbersWithSum(n, S);

    cout << "Generated numbers with sum " << S << ":\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
