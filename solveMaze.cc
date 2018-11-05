/*******************************************************************
* Name: Hayden Ivatts
* Date: 11-4-18
* Course: CSCI 132
* Assignment: Assignment 5
* Program: solveMaze.cc
* Purpose:  A program to generate a random maze and solve it.
***************************************************************************/
 
#include "maze.h"

bool solve(Maze &, int, int);
bool isWallAbove(Maze &, int, int);
bool isWallBelow(Maze &, int, int);
bool isWalltoLeft(Maze &, int, int);
bool isWalltoRight(Maze &, int, int);

int main()  {
    /*Post: Ask the user if they would like to see a maze, solve the maze, and
     *show the solved maze.
     */ 
	int width, height;
	char answer;
	
	cout << "Do you want me to solve a maze (y/n)? ";
	cin >> answer;

	while (answer == 'y') {
		cout << "Enter number for width of maze: " ;
		cin >> width;
		cout  << "Enter number for height of maze: ";
		cin >> height;

		Maze myMaze(width, height);
		cout << "Maze to be solved: " << endl;
		myMaze.print_maze();
		if (!solve(myMaze, 0, 0)) {
			cout << "Couldn't solve this maze!" << endl;
		} //if maze not solved
		
		cout << "Do you want me to solve another maze (y/n)? ";
		cin >> answer;
                cout << answer << endl;
	} // while solving another maze
		
	return 0;
} //end main program

bool solve(Maze &theMaze, int x, int y) {
    /*Pre: The maze class has been implemented correctly.
     *Post: Use recursion with backtracking to solve a maze.
     */ 
	//Recursively solve theMaze from position x, y

	if(theMaze.get_position(x, y) == 2) {
        theMaze.print_maze();
        return true;
    } else if(theMaze.get_position(x, y) == 1) {
        return false;
    } else {
        
        if(!isWallBelow(theMaze, x, y)) {
            
            theMaze.set_position(x, y, 1);
            solve(theMaze, x, y+1);
        }

        if(!isWallAbove(theMaze, x, y)) {
            theMaze.set_position(x, y, 1);
            solve(theMaze, x, y-1);
        }

        if(!isWalltoLeft(theMaze, x, y)) {
            theMaze.set_position(x, y, 1);
            solve(theMaze, x-1, y);  
        }

        if(!isWalltoRight(theMaze, x, y)) {
            theMaze.set_position(x, y, 1);
            solve(theMaze, x+1, y);
        }
        theMaze.set_position(x, y, 0);
    }
        
        
} //end solve

bool isWallAbove(Maze &theMaze, int x, int y) {
/*Pre: Maze class is correctly implemented
 *Post: Returns a boolean representing if there is a wall above cell x,y
 */
    
    return theMaze.is_horizontal_wall(x, y);
    
} //end isWallAbove

bool isWallBelow(Maze &theMaze, int x, int y) {
/*Pre: Maze class is correctly implemented
 *Post: Returns a boolean representing if there is a wall below cell x,y
 */
	return theMaze.is_horizontal_wall(x, y+1);
    
} //end isWallBelow

bool isWalltoLeft(Maze &theMaze, int x, int y) {
/*Pre: Maze class is correctly implemented
 *Post: Returns a boolean representing if there is a wall left of cell x,y
 */
	return theMaze.is_vertical_wall(x, y);
    
} //end isWalltoLeft

bool isWalltoRight(Maze &theMaze, int x, int y) {
/*Pre: Maze class is correctly implemented
 *Post: Returns a boolean representing if there is a wall right cell x,y
 */
	return theMaze.is_vertical_wall(x+1, y);
} //end isWalltoRight
