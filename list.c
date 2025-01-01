#include"list.h"

// Function to clear the screen
void clearScreen(int clearAll) {
    if (clearAll) {
        printf("\033[H\033[J");  
    }
}

// Global initalization of all color in case user dont give any color.
const char* headingColor = GRAY;
const char* selectionColor = RED;
const char* notSelectedColor = GREEN;
const char* lineColor = WHITE;

// Function to set heading color
void setHeadingColor(const char* color) {
    headingColor = color;
}

// Function to set selection highlight color
void setSelectionColor(const char* color) {
    selectionColor = color;
}

// Function to set not selected color
void setNotSelectedColor(const char* color) {
    notSelectedColor = color;
}

// Function to display the list with highlighting
void displayMenu(const char *options[], int numOptions, int highlight) {
    printf("\33[?25l"); // Hide cursor
    printf("%s%s\nUse arrow keys to navigate, press ENTER to select.\n%s",ITALIC, headingColor, RESET);

    for (int i = 0; i < numOptions; i++) {
        if (i == highlight) {
            printf("%s-> %s%s\n", selectionColor, options[i], RESET);  // Highlight selected option
        } else {
            printf("%s   %s%s\n",notSelectedColor,options[i],RESET);  
        }
    }
}

// Function to return the selected index
int displayList(const char *options[], int totalOption) {
    int highlight = 0;  // Tracks the current highlighted option
    int ch;
    int previousLines = totalOption + 2;  

    // Display the initial menu
    displayMenu(options, totalOption, highlight);  // Pass totalOption

    while (1) {
       
        ch = getch();  
              
        if (ch == 224) {
            ch = getch();  // Get arrow key code
            switch (ch) {
                case 72:    // UP arrow
                    if (highlight > 0) highlight--;
                    break;
                case 80:    // DOWN arrow
                    if (highlight < totalOption - 1) highlight++;
                    break;
                case 75:    // LEFT arrow
                    return -1; // -1 will be used to to move to previous menu
                    break;
                case 77:    // RIGHT arrow
                    if (highlight < totalOption) 
                    return highlight; //Its an alternative for Enter key 
                    break;
            }
        } else if (ch == 13) {  // Enter key 
            return highlight;   // Return the selected index
        }

        // Refresh the menu after each key press
        MOVE_CURSOR_UP(previousLines);
        displayMenu(options, totalOption, highlight);  // Pass totalOption
    }
}

// A function with predefined list to suggest user what to do next
int exitMenu() {
    const char *options[] = {"Re-calculate", "Previous Menu", "Main Menu", "Exit"};
    
    int selectedOption = displayList(options, 4);
    return selectedOption;
}
