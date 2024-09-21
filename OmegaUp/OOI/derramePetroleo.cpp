#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure to represent data with coordinates x, y and the number of days.
struct dato{
    int x, y, days;
};

// Arrays to represent movement directions (up, down, left, right)
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

// Global variables for the ocean's dimensions
int n, m;

// Function to check if a position (x, y) is valid within the matrix limits
bool isValid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

// Function to simulate the oil spill
void oilSpill(vector<vector<char>> &ocean, int x, int y, int days){
    queue<dato> q; // Queue to perform Breadth-First Search (BFS)

    // Initialize the starting point
    dato start; 
    start.x = x;
    start.y = y;
    start.days = 1;

    q.push(start); // Add the starting point to the queue
    ocean[x][y] = '$'; // Mark the starting position with the oil spill symbol

    // Perform BFS
    while(!q.empty()){
        dato current = q.front();
        q.pop();
        
        // Condition to stop the search if the maximum number of days is reached
        if(current.days > days) continue;

        // Explore the 4 directions
        for(int i=0; i<4; i++){
            dato next;
            next.x = current.x + dx[i];
            next.y = current.y + dy[i];
            next.days = current.days + 1;

            /* Conditions that make the next cell invalid:
            1. We go out of the matrix bounds
            2. We find the oil spill symbol ('$')
            3. We encounter a barrier ('#')
            4. We encounter contaminated water ('*')
            */
            if(!isValid(next.x, next.y)){
                continue;
            }
            // If the next cell is an empty space ('.'), we contaminate it with oil ('*')
            if(ocean[next.x][next.y] == '.'){
                q.push(next);
                ocean[next.x][next.y] = '*';
            }
        }
    }
}

int main(){
    int days; 
    cin >> n >> m >> days; // Read the ocean's dimensions and number of days
    vector<vector<char>> ocean(n, vector<char>(m, '.')); // Initialize the ocean matrix

    // Read the ocean representation
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> ocean[i][j];
    }

    // Find where the oil spill starts
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ocean[i][j] == '$'){
                oilSpill(ocean, i, j, days); // Start the simulation
                break;
            }
        }
    }

    // Print the final simulation of the ocean
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) 
            cout << ocean[i][j];
        cout << endl;
    }

    return 0;
}

/*
Example input:
4 6 4
###...
.$....
...###
#.#..#

Example output:
###***
*$***#
***###
#*#**#
*/
