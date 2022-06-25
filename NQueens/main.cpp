#include <iostream>
#include <vector>
#include <stdio.h>
#include "../../NQueens/NQueens.hpp"
#include <stdio.h>
int main(){
	
	int n;
	std::cout << "Enter N: " << std::endl;
	std::cin >> n;

	NQueensSolver solver = NQueensSolver(n);

	solver.print_N();

	if (solver.can_place_queens()) {    // there is at least 1 way to place the queens
	    std::cout << "Yes" << std::endl;

	    // get the number of solutions
	    size_t num_solutions = solver.num_solutions();
	    std::cout << num_solutions << std::endl;
	    
	    // print the first solution
	    // solver.print_solution();

	    // print all solutions
	    solver.print_all_solutions();

	    // get a solution as a 2D boolean vector
	    Board one_solution = solver.get_solution();

	    // get all solutions as a vector of 2D boolean vectors
	    std::vector<Board> all_solutions = solver.get_solutions();
	}

	return 0;



}

