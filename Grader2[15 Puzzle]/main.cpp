#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

typedef pair<int,int> pii;

class Puzzle;
bool isFind = false;
int ans = -1;
priority_queue<Puzzle> q;
unordered_set<string> visited;

class Puzzle{
    public:
        vector<vector<int>> board;
        int heuristic = 0;
        int count = 0;
        pii yxb;

        Puzzle(){}

        Puzzle(vector<vector<int>> v) {     // Constructor
          board = v;
          findHeuristic();
          visited.insert(boardToString(board));
        }

        void findHeuristic(){
            for(int y = 0; y < 4; y++){
                for(int x = 0; x < 4; x++){
                    int temp = board[y][x];
                    if(temp == 0) {heuristic += abs(y - 3) + abs(x - 3); yxb = {y,x};}
                    else heuristic += abs(y - (temp - 1)/4) + abs(x - (temp - 1)%4);
                }
            }
            if(heuristic == 0) {isFind = true; ans = count;}
        }

        void move(int i){
            int y = yxb.first;
            int x = yxb.second;

            if(i == 0){
                if(x < 3){//right
                    Puzzle temp;
                    vector<vector<int>> newBoard = board;
                    newBoard[y][x] = newBoard[y][x + 1];
                    newBoard[y][x + 1] = 0;
                    temp.board = newBoard;
                    temp.count = count + 1;
                    temp.findHeuristic();
                    if(!isVisited(temp.board)) { // Check if the new board state is visited
                        q.push(temp);
                        visited.insert(boardToString(temp.board)); // Mark the new board state as visited
                    }
                }
            }
            else if(i == 1){
                if(x > 0){//left
                    Puzzle temp;
                    vector<vector<int>> newBoard = board;
                    newBoard[y][x] = newBoard[y][x - 1];
                    newBoard[y][x - 1] = 0;
                    temp.board = newBoard;
                    temp.count = count + 1;
                    temp.findHeuristic();
                    if(!isVisited(temp.board)) { // Check if the new board state is visited
                        q.push(temp);
                        visited.insert(boardToString(temp.board)); // Mark the new board state as visited
                    }
                }
            }
            else if(i == 2){
                if(y < 3){//down
                    Puzzle temp;
                    vector<vector<int>> newBoard = board;
                    newBoard[y][x] = newBoard[y + 1][x];
                    newBoard[y + 1][x] = 0;
                    temp.board = newBoard;
                    temp.count = count + 1;
                    temp.findHeuristic();
                    if(!isVisited(temp.board)) { // Check if the new board state is visited
                        q.push(temp);
                        visited.insert(boardToString(temp.board)); // Mark the new board state as visited
                    }
                }
            }
            else if(i == 3){
                if(y > 0){//up
                    Puzzle temp;
                    vector<vector<int>> newBoard = board;
                    newBoard[y][x] = newBoard[y - 1][x];
                    newBoard[y - 1][x] = 0;
                    temp.board = newBoard;
                    temp.count = count + 1;
                    temp.findHeuristic();
                    if(!isVisited(temp.board)) { // Check if the new board state is visited
                        q.push(temp);
                        visited.insert(boardToString(temp.board)); // Mark the new board state as visited
                    }
                }
            }
        }

        bool operator<(const Puzzle &other) const{
            return count + heuristic > other.count + other.heuristic;
        }

        // Function to convert board to string for hashing
        string boardToString(const vector<vector<int>>& board) {
            string boardStr;
            for(const auto& row : board) {
                for(int num : row) {
                    boardStr += to_string(num);
                }
            }
            return boardStr;
        }

        // Function to check if a board state is visited
        bool isVisited(const vector<vector<int>>& board) {
            string boardStr = boardToString(board);
            return visited.find(boardStr) != visited.end();
        }

        void print_Board(){
            printf("heuristic: %d count: %d \n board: \n", heuristic, count);
            for(const auto& row : board) {
                for(int num : row) {
                    cout << num << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
};

int main()
{
    vector<vector<int>> board(4, vector<int>(4));
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            cin >> board[y][x];
        }
    }
    q.push(Puzzle(board));
    while(!q.empty()){
        Puzzle temp = q.top();
        q.pop();
        temp.print_Board();

        for(int i = 0; i < 4; i++){
            temp.move(i);
            //if(isFind) break;
        }
        //if(isFind) break;
    }
    cout << ans;
    return 0;
}
