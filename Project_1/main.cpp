#include <iostream>
#include <vector>

#include "solve.cpp" 

using namespace std;


int main () {
    cout << endl;
    cout << "Welcome to my 8-puzzle solver." << endl;
    cout << "-------------Choose one---------------------" << endl;
    cout << "---------1. Default puzzle------------------" << endl;
    cout << "---------2. Create Your Own Puzzle----------" << endl;
    cout << "---------3. Exit ---------------------------\n";

    int input;

    cin >> input; 

    if (input == 1) {

        vector<vector<int> > initialState = {
            {1, 3, 0},
            {5, 2, 6},
            {4, 7, 8}
        };

        vector<vector<int> > goalState = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };

        cout << "Your puzzle: \n";

        for (int i = 0; i < initialState.size(); ++i) {

            for(int j = 0; j < initialState.size(); ++j) {

                cout << initialState[i][j] << " ";
            }

            cout << endl;
        }

        SolvePuzzle puzzle (initialState, goalState);

        cout << "Choose a search Algorithm: " << endl;
        cout << "1. A* with Manhattan Distance " << endl;
        cout << "2. A* wiht Misplaced Tile" << endl;
        cout << "3. Uniform Cost Search" << endl;

        int choice;
        cin>> choice;

        if (choice == 1) {
            cout << "Solving using A* Manhattan Distance: " << endl;
            cout << endl;
            puzzle.AstarManhattanDistance(initialState);
            cout << endl;
        }

        else if (choice == 2) {
            cout << "Solving using A* Misplaced Tile: " << endl;
            cout << endl;
            puzzle.AstarMisplaceTile(initialState);
            cout << endl;
        }

        else {
            cout << "Solving using Uniform Cost Search: " << endl;
            cout << endl;
            puzzle.UniformCostSearch(initialState);
            cout << endl;
        }

    }

    else if (input == 2) {

        int row = 3;
        int col = 3;

        vector<vector<int> > goalState = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };

        vector<vector<int>> initialState(row, vector<int>(col));

        cout << "Enter your puzzle(one number at a time): \n";

        for (int i = 0; i < row; ++i) {

            for(int j = 0; j < col; ++j) {

                cin >> initialState[i][j];
            }
        }

        cout << "Your puzzle: \n";

        for (int i = 0; i < row; ++i) {

            for(int j = 0; j < col; ++j) {

                cout << initialState[i][j] << " ";
            }

            cout << endl;
        }

        SolvePuzzle puzzle (initialState, goalState);

        cout << "Choose a search Algorithm: " << endl;
        cout << "1. A* with Manhattan Distance " << endl;
        cout << "2. A* wiht Misplaced Tile" << endl;
        cout << "3. Uniform Cost Search" << endl;

        int choice;
        cin>> choice;

        if (choice == 1) {
            cout << "Solving using A* Manhattan Distance: " << endl;
            cout << endl;
            puzzle.AstarManhattanDistance(initialState);
            cout << endl;
        }

        else if (choice == 2) {
            cout << "Solving using A* Misplaced Tile: " << endl;
            cout << endl;
            puzzle.AstarMisplaceTile(initialState);
            cout << endl;
        }

        else {
            cout << "Solving using Uniform Cost Search: " << endl;
            cout << endl;
            puzzle.UniformCostSearch(initialState);
            cout << endl;
        }
   
    }

    else {

        cout << "Exiting program! Goodbye!" << endl;
    }

    

//     vector<vector<int> > goalState = {
//             {1, 2, 3},
//             {4, 5, 6},
//             {7, 8, 0}
//     };

//     vector<vector<int> > stateDepth1 = {
//             {1, 2, 3},
//             {4, 5, 0},
//             {7, 8, 6}
//     };

//     SolvePuzzle puzzle1 (stateDepth1, goalState);

//     cout << "Solving Depth 1 using A* Manhattan Distance: " << endl;
//         puzzle1.AstarManhattanDistance(stateDepth1);
//         cout << endl;

//         cout << "Solving Depth 1 using A* Misplaced Tile: " << endl;
//         puzzle1.AstarMisplaceTile(stateDepth1);
//         cout << endl;

//         cout << "Solving Depth 1 using Uniform Cost Search: " << endl;
//         puzzle1.UniformCostSearch(stateDepth1);
//         cout << endl;

//         cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth2 = {
//             {1, 2, 0},
//             {4, 5, 3},
//             {7, 8, 6}
//     };

//     SolvePuzzle puzzle2 (stateDepth2, goalState);

//     cout << "Solving Depth 2 using A* Manhattan Distance: " << endl;
//         puzzle2.AstarManhattanDistance(stateDepth2);
//         cout << endl;

//         cout << "Solving Depth 2 using A* Misplaced Tile: " << endl;
//         puzzle2.AstarMisplaceTile(stateDepth2);
//         cout << endl;

//         cout << "Solving Depth 2 using Uniform Cost Search: " << endl;
//         puzzle2.UniformCostSearch(stateDepth2);
//         cout << endl;

//         cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth3 = {
//             {1, 0, 2},
//             {4, 5, 3},
//             {7, 8, 6}
//     };

//     SolvePuzzle puzzle3 (stateDepth3, goalState);

//     cout << "Solving Depth 3 using A* Manhattan Distance: " << endl;
//         puzzle3.AstarManhattanDistance(stateDepth3);
//         cout << endl;

//         cout << "Solving Depth 3 using A* Misplaced Tile: " << endl;
//         puzzle3.AstarMisplaceTile(stateDepth3);
//         cout << endl;

//         cout << "Solving Depth 3 using Uniform Cost Search: " << endl;
//         puzzle3.UniformCostSearch(stateDepth3);
//         cout << endl;

//         cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth4 = {
//             {0, 1, 2},
//             {4, 5, 3},
//             {7, 8, 6}
//     };

//     SolvePuzzle puzzle4 (stateDepth4, goalState);

//     cout << "Solving Depth 4 using A* Manhattan Distance: " << endl;
//         puzzle4.AstarManhattanDistance(stateDepth4);
//         cout << endl;

//         cout << "Solving Depth 4 using A* Misplaced Tile: " << endl;
//         puzzle4.AstarMisplaceTile(stateDepth4);
//         cout << endl;

//         cout << "Solving Depth 4 using Uniform Cost Search: " << endl;
//         puzzle4.UniformCostSearch(stateDepth4);
//         cout << endl;

//          cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth5 = {
//             {4, 1, 2},
//             {0, 5, 3},
//             {7, 8, 6}
//     };

//     SolvePuzzle puzzle5 (stateDepth5, goalState);

//     cout << "Solving Depth 5 using A* Manhattan Distance: " << endl;
//         puzzle5.AstarManhattanDistance(stateDepth5);
//         cout << endl;

//         cout << "Solving Depth 5 using A* Misplaced Tile: " << endl;
//         puzzle5.AstarMisplaceTile(stateDepth5);
//         cout << endl;

//         cout << "Solving Depth 5 using Uniform Cost Search: " << endl;
//         puzzle5.UniformCostSearch(stateDepth5);
//         cout << endl;

//          cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth6 = {
//             {1, 3, 0},
//             {5, 2, 6},
//             {4, 7, 8}
//     };

//     SolvePuzzle puzzle6 (stateDepth6, goalState);

//     cout << "Solving Depth 6 using A* Manhattan Distance: " << endl;
//         puzzle6.AstarManhattanDistance(stateDepth6);
//         cout << endl;

//         cout << "Solving Depth 6 using A* Misplaced Tile: " << endl;
//         puzzle6.AstarMisplaceTile(stateDepth6);
//         cout << endl;

//         cout << "Solving Depth 6 using Uniform Cost Search: " << endl;
//         puzzle6.UniformCostSearch(stateDepth6);
//         cout << endl;

//         cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth7 = {
//             {1, 3, 6},
//             {5, 2, 0},
//             {4, 7, 8}
//     };

//     SolvePuzzle puzzle7 (stateDepth7, goalState);

//     cout << "Solving Depth 7 using A* Manhattan Distance: " << endl;
//         puzzle7.AstarManhattanDistance(stateDepth7);
//         cout << endl;

//         cout << "Solving Depth 7 using A* Misplaced Tile: " << endl;
//         puzzle7.AstarMisplaceTile(stateDepth7);
//         cout << endl;

//         cout << "Solving Depth 7 using Uniform Cost Search: " << endl;
//         puzzle7.UniformCostSearch(stateDepth7);
//         cout << endl;

//          cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth8 = {
//             {1, 3, 6},
//             {5, 0, 2},
//             {4, 7, 8}
//     };

//     SolvePuzzle puzzle8 (stateDepth8, goalState);

//     cout << "Solving Depth 8 using A* Manhattan Distance: " << endl;
//         puzzle8.AstarManhattanDistance(stateDepth8);
//         cout << endl;

//         cout << "Solving Depth 8 using A* Misplaced Tile: " << endl;
//         puzzle8.AstarMisplaceTile(stateDepth8);
//         cout << endl;

//         cout << "Solving Depth 8 using Uniform Cost Search: " << endl;
//         puzzle8.UniformCostSearch(stateDepth8);
//         cout << endl;

//          cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth9 = {
//             {1, 3, 6},
//             {5, 7, 2},
//             {4, 0, 8}
//     };

//     SolvePuzzle puzzle9 (stateDepth9, goalState);

//     cout << "Solving Depth 9 using A* Manhattan Distance: " << endl;
//         puzzle9.AstarManhattanDistance(stateDepth9);
//         cout << endl;

//         cout << "Solving Depth 9 using A* Misplaced Tile: " << endl;
//         puzzle9.AstarMisplaceTile(stateDepth9);
//         cout << endl;

//         cout << "Solving Depth 9 using Uniform Cost Search: " << endl;
//         puzzle9.UniformCostSearch(stateDepth9);
//         cout << endl;

//          cout << "--------------------------------------------------------\n";   

//     vector<vector<int> > stateDepth10 = {
//             {1, 3, 6},
//             {5, 7, 2},
//             {4, 8, 0}
//     };

//     SolvePuzzle puzzle10 (stateDepth10, goalState);

//     cout << "Solving Depth 10 using A* Manhattan Distance: " << endl;
//         puzzle10.AstarManhattanDistance(stateDepth10);
//         cout << endl;

//         cout << "Solving Depth 10 using A* Misplaced Tile: " << endl;
//         puzzle10.AstarMisplaceTile(stateDepth10);
//         cout << endl;

//         cout << "Solving Depth 10 using Uniform Cost Search: " << endl;
//         puzzle10.UniformCostSearch(stateDepth10);
//         cout << endl;

//          cout << "--------------------------------------------------------\n";   

//     vector<vector<int> > stateDepth11 = {

//             {1, 3, 6},
//             {5, 7, 0},
//             {4, 8, 2}
//     };

//     SolvePuzzle puzzle11 (stateDepth11, goalState);

//     cout << "Solving Depth 11 using A* Manhattan Distance: " << endl; 
//         puzzle11.AstarManhattanDistance(stateDepth11);
//         cout << endl;

//         cout << "Solving Depth 11 using A* Misplaced Tile: " << endl;
//         puzzle11.AstarMisplaceTile(stateDepth11);
//         cout << endl;

//         cout << "Solving Depth 11 using Uniform Cost Search: " << endl; 
//         puzzle11.UniformCostSearch(stateDepth11);
//         cout << endl;

//         cout << "--------------------------------------------------------\n";


//     vector<vector<int> > stateDepth12 = {

//             {1, 3, 6},
//             {5, 0, 7},
//             {4, 8, 2}
//     };

//     SolvePuzzle puzzle12 (stateDepth12, goalState);

//     cout << "Solving Depth 12 using A* Manhattan Distance: " << endl; //36
//         puzzle12.AstarManhattanDistance(stateDepth12);
//         cout << endl;

//         cout << "Solving Depth 12 using A* Misplaced Tile: " << endl;
//         puzzle12.AstarMisplaceTile(stateDepth12);
//         cout << endl;

//         cout << "Solving Depth 12 using Uniform Cost Search: " << endl; //1885
//         puzzle12.UniformCostSearch(stateDepth12);
//         cout << endl;

//         cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth13 = {

//             {1, 0, 6},
//             {5, 3, 7},
//             {4, 8, 2}
//     };

//     SolvePuzzle puzzle13 (stateDepth13, goalState);

//     cout << "Solving Depth 13 using A* Manhattan Distance: " << endl; //36
//         puzzle13.AstarManhattanDistance(stateDepth13);
//         cout << endl;

//         cout << "Solving Depth 13 using A* Misplaced Tile: " << endl;
//         puzzle13.AstarMisplaceTile(stateDepth13);
//         cout << endl;

//         cout << "Solving Depth 12 using Uniform Cost Search: " << endl; //1885
//         puzzle13.UniformCostSearch(stateDepth13);
//         cout << endl;

//         cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth14 = {

//             {1, 6, 0},
//             {5, 3, 7},
//             {4, 8, 2}
//     };

//     SolvePuzzle puzzle14 (stateDepth14, goalState);

//     cout << "Solving Depth 14 using A* Manhattan Distance: " << endl; //36
//         puzzle14.AstarManhattanDistance(stateDepth14);
//         cout << endl;

//         cout << "Solving Depth 13 using A* Misplaced Tile: " << endl;
//         puzzle14.AstarMisplaceTile(stateDepth14);
//         cout << endl;

//         cout << "Solving Depth 14 using Uniform Cost Search: " << endl; //1885
//         puzzle14.UniformCostSearch(stateDepth14);
//         cout << endl;

//         cout << "--------------------------------------------------------\n";

//     vector<vector<int> > stateDepth15 = {

//         //     {1, 6, 7},
//         //     {5, 3, 0},
//         //     {4, 8, 2}
//              {8, 6, 7},
//              {2, 5, 4},
//              {3, 0, 1}
//     };

//     SolvePuzzle puzzle15 (stateDepth15, goalState);

//     cout << "Solving Depth 15 using A* Manhattan Distance: " << endl; //36
//         puzzle15.AstarManhattanDistance(stateDepth15);
//         cout << endl;

//         cout << "Solving Depth 15 using A* Misplaced Tile: " << endl;
//         puzzle15.AstarMisplaceTile(stateDepth15);
//         cout << endl;

//         cout << "Solving Depth 15 using Uniform Cost Search: " << endl; //1885
//         puzzle15.UniformCostSearch(stateDepth15);
//         cout << endl;

//         cout << "--------------------------------------------------------\n";

}