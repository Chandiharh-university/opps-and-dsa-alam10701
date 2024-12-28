#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int val : row) {
            cout << (val ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;
    
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;
    
    for (int i = row, j = col; i < N && j >= 0; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int N, vector<vector<vector<int>>>& solutions) {
    if (col >= N) {
        solutions.push_back(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            res = solveNQueensUtil(board, col + 1, N, solutions) || res;

            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

vector<vector<vector<int>>> solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<vector<int>>> solutions;
    solveNQueensUtil(board, 0, N, solutions);
    return solutions;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<vector<vector<int>>> solutions = solveNQueens(N);

    cout << "Number of solutions: " << solutions.size() << endl;
    for (const auto& solution : solutions) {
        printSolution(solution);
    }

    return 0;
}
