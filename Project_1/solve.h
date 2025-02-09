#ifndef SOLVE_H
#define SOLVE_H

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> possibleMoves = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

class Node {

    public:

        vector<vector<int> > state;
        int gCost;
        int hCost;
        int totalCost;
        Node* prevState;

        Node(vector<vector<int>> state, int gCost, int hCost, int totalCost, Node* prevState)
                : state(state), gCost(gCost), hCost(hCost), totalCost(totalCost), prevState(prevState) {}

};

class SolvePuzzle {

    private:

        vector<vector<int> > initialState;
        vector<vector<int> > goalState;


    public:

        SolvePuzzle(vector<vector<int> > initialState, vector<vector<int>> goalState) :
                initialState(initialState),
                goalState(goalState) {}

        pair<int, int> FindEmptyPosition(vector<vector<int> > initialState);
        bool isGoalState(vector<vector<int> > intialState);
        bool isValidMove(vector<vector<int> > initalState, pair<int, int> move);
        vector<vector<int> > NewStateAfterMove(vector<vector<int> > initalState, pair<int, int> move);

        void generalSearch(vector<vector<int> > intialState, function<int(vector<vector<int>>)> f);
        int manhattanDistance(vector<vector<int> > initalState);
        int misplacedTile(vector<vector<int> > initalState);
        void SolutionPath(vector<vector<int>> initalState, Node* goalState);

        void AstarManhattanDistance(vector<vector<int>> initalState);
        void AstarMisplaceTile(vector<vector<int>> initalState);
        void UniformCostSearch(vector<vector<int>> initalState);
};

class Comapre {
    
    public:
        
        bool operator() (Node* node1, Node* node2) {

            // Tie-breaker: If they have the same totalCost choose the node with the lowest h cost

            if (node1->totalCost == node2->totalCost) {

                return node1->hCost > node2->hCost;
            }
            
            return node1->totalCost > node2->totalCost;
        }
};

#endif
