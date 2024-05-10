#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class NQueens {
private:
    int N;
    int solution;
    vector<int> board;
    vector<bool> rowTaken;
    vector<bool> diag1Taken;
    vector<bool> diag2Taken;

public:
    NQueens(int n) : N(n), solution(0) {
        board.resize(N);
        rowTaken.resize(N, false);
        diag1Taken.resize(2 * N - 1, false);
        diag2Taken.resize(2 * N - 1, false);
    }

    void solve(int col) {
        if (col == N) {
            solution++;
            printBoard();
            return;
        }

        for (int row = 0; row < N; row++) {
            if (!rowTaken[row] && !diag1Taken[row + col] && !diag2Taken[N - 1 + col - row]) {
                board[col] = row;
                rowTaken[row] = true;
                diag1Taken[row + col] = true;
                diag2Taken[N - 1 + col - row] = true;

                solve(col + 1);

                rowTaken[row] = false;
                diag1Taken[row + col] = false;
                diag2Taken[N - 1 + col - row] = false;
            }
        }
    }

    void printBoard() {
        cout << "Solution: " << solution << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[j] == i) cout << "Q ";
                else cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    NQueens nQueens(N);
    nQueens.solve(0);

    return 0;
}