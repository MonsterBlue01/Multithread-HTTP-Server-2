# NOTE

## Previous Work

- Read the file and build a graph from the information in the file

## Future Work

- Since in this problem it doesn't make sense for a node to connect itself, two things need to change:
    + When the program finds that there are nodes connected to itself in the input file, it skips directly, and at the end prompts the user that this has no meaning and has been skipped
    + When printingMatrix, replace all the numbers in the opposite sides from the upper left to the lower right with -1 (that is, invalid)

## Cancelled Work

- Add function to delete nodes

## Important things to note:

- The input document must follow a fixed format, otherwise the program will not have normal, expected results