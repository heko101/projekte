#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

int main() {

    char input[MAX_LENGTH];
    int benutzer = 0;

    printf(">>> Hier befindet sich der Chat-Simulator (^.^) <<<\n");
    printf("Hier kann man selber eingeben was der User sagen kann (in einem simplen Format).\n");
    printf("Gib ein was du schreiben willst.\n");
    printf("Gib 'exit' ein wenn du den Chat beenden willst.\n");

    while(1) {
        if (benutzer ==  0){
           printf("[User (^v^)]: "); 
        } else {
            printf("[User (°v°)]: ");
        }

        fgets(input, MAX_LENGTH, stdin);
        
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Chat wird beendet...byeee\n");
            break;
        }
        
        if (benutzer == 0){
        printf("-> (^v^) schrieb: %s\n\n", input);
        } else {
            printf("-> (°v°) schrieb: %s\n\n", input);
        }

        benutzer = 1 - benutzer;
    }

    return 0;    
       


}
