#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<string> diction;
vector<string> answer;

char boggle_board[4][4];
int visited[4][4];
int find_bool[300010];
int find_index = 0;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void dfs(string find_word, int word_index, int x, int y){
    
    if(find_word.length() == word_index && find_bool[find_index] == 0){
        find_bool[find_index] = 1;
        answer.push_back(find_word);
    }
    
    for(int i =0; i < 8; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        if(visited[xx][yy] == 0 && boggle_board[xx][yy] == find_word[word_index] && xx >= 0 && yy >= 0 && xx < 4 && yy < 4){
            visited[xx][yy] = 1;
            dfs(find_word, word_index+1, xx, yy);
            visited[xx][yy] = 0;
        }
    }
    
    visited[x][y] = 0;
}

int score_cal(){
    int score = 0;
    
    for(int i =0; i< answer.size(); i++){
        if(answer[i].length() >= 3 && answer[i].length() <= 4){
            score += 1;
        }
        else if(answer[i].length() == 5){
            score += 2;
        }
        else if(answer[i].length() == 6){
            score += 3;
        }
        else if(answer[i].length() == 7){
            score += 5;
        }
        else if(answer[i].length() == 8){
            score += 11;
        }
    }
    
    return score;
}

bool cmp(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }else{
        return a.length() > b.length();
    }
}

int main(){
    
    int word_num, boggle_num;
    
    cin >> word_num;
    
    for(int i =0; i< word_num; i++){
        string word;
        
        cin >> word;
        
        diction.push_back(word);
    }
    
    cin >> boggle_num;
    
    for(int b = 0; b < boggle_num; b++){
        
        find_index = 0;
        
        answer.clear();
        
        for(int i =0; i < 300010; i++){
            find_bool[i] = 0;
        }
        
        for(int i=0; i < 4; i++){
            for(int j =0; j < 4; j++){
                cin >> boggle_board[i][j];
            }
        }
        
        for(int w = 0; w < diction.size(); w++){
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    if(boggle_board[i][j] == diction[w][0] && find_bool[w] == 0){
                        visited[i][j] = 1;
                        dfs(diction[w], 1, i, j);
                    }
                }
            }
            find_index++;
        }
        
        sort(answer.begin(), answer.end(), cmp);
        answer.erase(unique(answer.begin(), answer.end()), answer.end());
        
        int score = score_cal();
        
        // check
        /*
        cout << "\n# " << b+1 << "\n";
        
        for(int i =0; i< answer.size(); i++){
            cout << "answer: " << answer[i] << "\n";
        }
        */
        cout << score << " " << answer[0] << " " << answer.size() << "\n";
    }
    
}
