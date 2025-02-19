#include <iostream>
using namespace std;

const int size = 3;

char board[size][size] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void diplaytic(){
    cout<<endl;
for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
        cout<<" "<<board[i][j]<<" ";
        if (j < size - 1 ) cout << "|";
    }
    cout<<endl;
    if (i < size - 1) cout << "---+---+---\n";

}
cout<<endl;
return;
}

bool iswin(){
    for(int i=0; i<size; i++){
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]) {
            return true;
        }
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[2][i]){
            return true;
        }
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]) {
        return true;
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
        return true;
    }
    return false;
}

bool draw(){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(board[i][j]!='X' || board[i][j]!='O')return false;
        }
    }
    return true;
}
void makeMove(char player){
    int choice;
    while(true){
        cout<<"Player "<<player<<" Enter a number(1-9): ";
        cin>>choice;

        if(choice<1 || choice>9){
            cout<<"Invalid move Try again!"<<endl;;
            continue;
        }
        int row = (choice -1)/size;
    int col = (choice -1)%size;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Cell already taken! Try again.\n";
    } 
    else {
        board[row][col] = player;
        break;
      
        }  
    }  
}

int main() {

    char currentPlayer = 'X';
    diplaytic();
    
    while (true) {
        makeMove(currentPlayer);
        diplaytic();

        if (iswin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (draw()) {
            cout << "It's a draw!\n";
            break;
        }
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
    }
    


    return 0;
}