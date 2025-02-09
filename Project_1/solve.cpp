#include <queue>
#include <algorithm>
#include "solve.h"

// Returns the position (row and column) of the empty tile by looping through the rows and columns 
pair<int, int> SolvePuzzle:: FindEmptyPosition(vector<vector<int> > initalState) {

    for (int i = 0; i < initalState.size(); ++i) {

        for (int j = 0; j < initalState[i].size(); ++j) {

            if(initalState[i][j] == 0) {

                return {i, j};
            }
        }
    }

    return {-1, -1};
}

// Checks if the current state is the goal state and returns true if it is
bool SolvePuzzle::isGoalState(vector<vector<int> > initalState) {

    for (int i = 0; i < initalState.size(); ++i) {

        for (int j = 0; j < initalState[i].size(); ++j) {

            if(initalState[i][j] != goalState[i][j]) {
                
                return false;
            }
        }
    }
    
    return true;
}

/* Finds the position of the empty tile, calculates the new position after moving the tile,
    Checks if the new position is within the grid (3 x 3)*/ 
bool SolvePuzzle::isValidMove(vector<vector<int> > initalState, pair<int, int> move) {

    pair<int, int> emptyPositon = FindEmptyPosition(initalState);

    int newRow = emptyPositon.first + move.first;
    int newColumn = emptyPositon.second + move.second;


    if (newRow >= 0 && newRow < 3 && newColumn >= 0 && newColumn < 3) {

        return true;
    }

    return false;
}

/* Returns the new state after applying a valid move
    checks if the move is valid, if it is create a copy of the new state, calculate the new position of the empty tile then swap the position*/
vector<vector<int> >SolvePuzzle:: NewStateAfterMove(vector<vector<int> >initalState, pair<int, int> move) {

    if (!isValidMove(initalState, move)) {

        return initalState;
    }

    vector<vector<int> > newState = initalState;

    pair<int, int> empty = FindEmptyPosition(initalState);

    int newRow = empty.first + move.first;
    int newColumn = empty.second + move.second;

    swap(newState[empty.first][empty.second], newState[newRow][newColumn]);
    

    return newState;

}
/* Caluclates how far a state is from a goal state */
int SolvePuzzle:: manhattanDistance(vector<vector<int> > initalState) {

    int distance = 0;

    for (int i = 0; i < initalState.size(); ++i) { // Row 

        for(int j = 0; j < initalState[i].size(); ++j) {  // Column 

            if (initalState[i][j] != 0) { // Exclude the empty tile 

                int goalRow = (initalState[i][j] - 1) / 3;
                int goalCol = (initalState[i][j] - 1) % 3;

                distance += abs(i - goalRow ) + abs (j - goalCol);
            }

        }
    }

    return distance;

}

/*Counts the number of tiles that are in the wrong positon by comparing each tile in 
    the state with the goal state */
int SolvePuzzle:: misplacedTile(vector<vector<int> >initalState) {

    int count = 0;

    for (int i = 0; i < initalState.size(); ++i) {

        for(int j = 0; j < initalState[i].size(); ++j) {

            if ( initalState[i][j] != 0 && initalState[i][j] != goalState[i][j]) { 

                count ++;
            }
        }
    }

    return count;
}

/* General Search algorithm using a priority queue (min-heap)*/
void SolvePuzzle:: generalSearch(vector<vector<int> > initalState, function<int(vector<vector<int>>)> func) { 

    priority_queue <Node*, vector<Node*>, Comapre> q; 

    Node* node = new Node(initalState, 0, func(initalState), func(initalState) + 0, nullptr);

    int maxQueueSize = 0;

    q.push(node);

    // update the queue size each time we add a node to the queue
    maxQueueSize = max(maxQueueSize, (int) q.size());

    // Keep track of the states that it visits and we don't revist the same state
    vector<vector<vector<int> >> visitedStates;

    int nodesExpanded = 0;

    while(!q.empty()) {

        Node* curr = q.top(); // node with the lowest total cost (min-heap)

        q.pop(); // remove the node from the queue before expanding 

        nodesExpanded ++;

        if(isGoalState(curr->state)) {
            SolutionPath(initalState, curr);
            cout << "Nodes Expanded: " << nodesExpanded << endl;
            cout << endl;
            cout << "Depth: " << curr->gCost << endl;
            cout << endl;
            cout << "Maximum Queue Size: " << maxQueueSize << endl;
            cout << endl;
            cout << "Number of nodes in the frontier when solution found: " << q.size() << endl;
            cout << endl;
            cout << "Success!" << endl;
            cout << endl;

            return;
        }

        visitedStates.push_back(curr->state);

        /* Loop through the possible moves, check if the move is valid and then create new state
         and check if the new state if already visited. 
        If it is a visited state we go to the next move, if it's not we create a new node for the new state and push it to the queue
        */ 
        for(int i = 0; i < possibleMoves.size(); ++i) {

            if(isValidMove(curr->state, possibleMoves[i])) {

                vector<vector<int>> newState = NewStateAfterMove(curr->state, possibleMoves[i]);

                if(find(visitedStates.begin(), visitedStates.end(), newState) != visitedStates.end()) {

                    continue; // already visited so we dont add it to the queue 
                }

                int g = curr->gCost + 1;
                int h = func(newState);
                int total = g + h;

                Node* newNode = new Node(newState, g, h, total, curr);

                q.push(newNode);

                maxQueueSize = max(maxQueueSize, (int) q.size()); // update queue size
            }
        }
    }
    cout << "Failed to find a solution!" << endl;
}

// prints out the states for each step by backtracking using the prevState 
void SolvePuzzle::SolutionPath(vector<vector<int>> initalState, Node* goalState){

   vector<vector<vector<int>>> path;
   vector<int> g;
   vector<int> h;

   Node* curr = goalState;

    while(curr != nullptr) {

        path.push_back(curr->state);
        g.push_back(curr->gCost);
        h.push_back(curr->hCost);
        curr = curr -> prevState;
    }

    reverse(path.begin(), path.end());
    reverse(g.begin(), g.end());
    reverse(h.begin(), h.end());

    cout << "Solution: " << endl;

    for(int i = 0; i < path.size(); ++i) {

        cout << "The best state to expand with g(n) = " << g[i] << " and h(n) = " << h[i] << endl;

        for (int j =0; j < path[i].size(); ++j) {

            for (int k = 0; k < path[i][j].size(); ++k) {

                cout << path[i][j][k] << " ";

            }

            cout << endl;
        
        }
        cout << endl;

    }

    cout << endl;
}

// Calls the general search function and uses the manhattan distance as the heruisitic cost 
void SolvePuzzle::AstarManhattanDistance(vector<vector<int>> initialState) {
    generalSearch(initialState, [this](vector<vector<int>> state) -> int {
        return manhattanDistance(state);
    });
}

//Calls the general search function and uses the misplaced tile as the heruisitic cost 
void SolvePuzzle::AstarMisplaceTile(vector<vector<int>> initialState) {
    generalSearch(initialState, [this](vector<vector<int>> state) -> int {
        return misplacedTile(state);
    });
}

//Calls the general search function and sets the heuristic cost to 0 to only use gCost
void SolvePuzzle::UniformCostSearch(vector<vector<int>> initialState) {
    generalSearch(initialState, [this](vector<vector<int>> state) -> int {
        return 0;
    });
}


