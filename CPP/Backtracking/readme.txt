Backtracking is a problem-solving technique that involves trying out different possibilities to solve a problem and undoing ("backtracking") those choices if they don't lead to a solution. It's like exploring a maze:

1./ Start at the Beginning: You start from a certain point and make a choice about which direction to go.
2./ Explore the Path: You move in that direction and see where it takes you.
3./ Check for Success: If you reach the goal, you’re done.
4./ Backtrack if Necessary: If you hit a dead end (a path that doesn't work), you go back to the last decision point and try a different direction.
5./ Repeat Until Success: You keep doing this until you find the right path that leads to the solution.


##Pseudocode for Backtracking##
The best way to implement backtracking is through recursion, and all backtracking code can be summarised as per the given Pseudocode:

void FIND_SOLUTIONS( parameters):
  if (valid solution):
    store the solution
    Return
  for (all choice):
    if (valid choice):
      APPLY (choice)
      FIND_SOLUTIONS (parameters)
      BACKTRACK (remove choice)
  Return
