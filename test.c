#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define CYAN        "\033[0;36m"
#define WHITE       "\x1b[37m"
#define ORANGE      "\x1b[38;5;202m"
#define MAGENTA     "\033[0;35m"
#define GRAY        "\x1b[38;5;243m"
#define GOLD        "\033[38;2;255;215;0m"
#define INDIGO      "\033[38;2;75;0;130m"
#define VIOLET      "\033[38;2;238;130;238m"
#define BROWN       "\033[38;2;132;60;19m"
#define PINK        "\033[38;2;255;100;180m"
#define OLIVE       "\033[38;2;128;128;0m"
#define TANGERINE   "\033[38;2;255;69;0m"
#define LIME        "\033[38;2;154;205;50m"
#define TURQUOISE   "\033[38;2;72;209;204m"
#define PURPLE      "\033[38;2;130;105;219m"

#define RESET       "\033[0m"

// void print_calculator(int x) {
//     const char *colors[] = {INDIGO,VIOLET,PINK,RED,TANGERINE, ORANGE, YELLOW, BLUE, CYAN, WHITE, GREEN, MAGENTA, GRAY, GOLD, 
//                             BROWN, OLIVE, LIME, TURQUOISE, PURPLE};
//     int total_colors = sizeof(colors) / sizeof(colors[0]);

//     for (int i = 0; i < x; i++) {
//         printf("%sCalculatorX%s ", colors[i % total_colors], RESET);
//     }
//     printf("\n");
// }

void animate_calculators() {
     const char *colors[] = {INDIGO,VIOLET,PINK,RED,TANGERINE, ORANGE, YELLOW, BLUE, CYAN, WHITE, GREEN, MAGENTA, GRAY, GOLD, 
                            BROWN, OLIVE, LIME, TURQUOISE, PURPLE};
    for (int i = 0,j=0; i < 50; i++,j++) { // Loop to create animation
        system("clear");
        if(j>19) {
            j = 0;
        }
        printf("%s",colors[j]);
        printf("CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX C\n");
        printf("alculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Ca\n");
        printf("lculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Cal\n");
        printf("culatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calc\n");
        printf("ulatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcu\n");
        printf("latorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcul\n");
        printf("atorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcula\n");
        printf("torX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculat\n");
        printf("orX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculato\n");
        printf("rX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculator\n");
        printf("X CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX\n");
        printf(" CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX \n");
        printf("CalculatorX CalculatorX Calcul                                                                  CalculatorX CalculatorX CalculatorX C\n");
        printf("alculatorX CalculatorX Calcula      _____      _            _       _              __   __      alculatorX CalculatorX CalculatorX Ca\n");
        printf("lculatorX CalculatorX Calculat     / ____|    | |          | |     | |             \\ \\ / /      lculatorX CalculatorX CalculatorX Cal\n");
        printf("culatorX CalculatorX Calculato    | |     __ _| | ___ _   _| | __ _| |_ ___  _ __   \\ V /       culatorX CalculatorX CalculatorX Calc\n");
        printf("ulatorX CalculatorX Calculator    | |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__|   > <        ulatorX CalculatorX CalculatorX Calcu\n");
        printf("latorX CalculatorX CalculatorX    | |___| (_| | | (__| |_| | | (_| | || (_) | |     / . \\       latorX CalculatorX CalculatorX Calcul\n");
        printf("atorX CalculatorX CalculatorX      \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|    /_/ \\_\\      atorX CalculatorX CalculatorX Calcula\n");
        printf("torX CalculatorX CalculatorX C                                                                  torX CalculatorX CalculatorX Calculat\n");
        printf("orX CalculatorX CalculatorX Ca                                                                  orX CalculatorX CalculatorX Calculato\n");
        printf("rX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculator\n");
        printf("X CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX\n");
        printf(" CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX \n");
        printf("CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX C\n");
        printf("alculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Ca\n");
        printf("lculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Cal\n");
        printf("culatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calc\n");
        printf("ulatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcu\n");
        printf("latorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcul\n");
        printf("atorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcula\n");
        printf("torX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculat\n");
       // printf("orX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculato\n");
        printf("%s",RESET);
        usleep(300000); // 200ms delay
    }
    printf("Press ENTER to continue...\n");
    getchar(); // Wait for ENTER
}

int main() {

    system("clear");
    animate_calculators();
    // printf("CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX C\n");
    // printf("alculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Ca\n");
    // printf("lculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Cal\n");
    // printf("culatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calc\n");
    // printf("ulatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcu\n");
    // printf("latorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcul\n");
    // printf("atorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcula\n");
    // printf("torX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculat\n");
    // printf("orX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculato\n");
    // printf("rX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculator\n");
    // printf("X CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX\n");
    // printf(" CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX \n");
    // printf("CalculatorX CalculatorX Calcul                                                                  CalculatorX CalculatorX CalculatorX C\n");
    // printf("alculatorX CalculatorX Calcula      _____      _            _       _              __   __      alculatorX CalculatorX CalculatorX Ca\n");
    // printf("lculatorX CalculatorX Calculat     / ____|    | |          | |     | |             \\ \\ / /      lculatorX CalculatorX CalculatorX Cal\n");
    // printf("culatorX CalculatorX Calculato    | |     __ _| | ___ _   _| | __ _| |_ ___  _ __   \\ V /       culatorX CalculatorX CalculatorX Calc\n");
    // printf("ulatorX CalculatorX Calculator    | |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__|   > <        ulatorX CalculatorX CalculatorX Calcu\n");
    // printf("latorX CalculatorX CalculatorX    | |___| (_| | | (__| |_| | | (_| | || (_) | |     / . \\       latorX CalculatorX CalculatorX Calcul\n");
    // printf("atorX CalculatorX CalculatorX      \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|    /_/ \\_\\      atorX CalculatorX CalculatorX Calcula\n");
    // printf("torX CalculatorX CalculatorX C                                                                  torX CalculatorX CalculatorX Calculat\n");
    // printf("orX CalculatorX CalculatorX Ca                                                                  orX CalculatorX CalculatorX Calculato\n");
    // printf("rX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculator\n");
    // printf("X CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX\n");
    // printf(" CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX \n");
    // printf("CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX C\n");
    // printf("alculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Ca\n");
    // printf("lculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Cal\n");
    // printf("culatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calc\n");
    // printf("ulatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcu\n");
    // printf("latorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcul\n");
    // printf("atorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calcula\n");
    // printf("torX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculat\n");
    // printf("orX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX CalculatorX Calculato\n");
                                                                                                                                               
    return 0;
}

