// You are using GCC
#include <iostream>
using namespace std;

int moveDisks(int n, char src, char aux, char dest) {
    static int moves = 0; 
    if(n == 1) {
        cout << "move disk "<< n << " from rod " << src << " to rod " <<  dest << endl;
        moves++;
        return moves;
    }
    
    moves = moveDisks(n-1, src, dest, aux);
    cout << "move disk "<< n << " from rod " << src << " to rod " <<  dest << endl;
    moves++;
    
    moves = moveDisks(n-1, aux, src, dest);
    
    return moves;
}

int main() {
    int n;
    cin >> n;
    
    int totalMoves = moveDisks(n, '1', '2', '3');
    
    cout << totalMoves << endl;
    
    return 0;
}