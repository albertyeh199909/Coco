// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by YOUR-NAME-HERE (z5236552)
// on 25/03/2019
//

#include <stdio.h>
#include <assert.h>


#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49


// IF YOU NEED MORE #defines ADD THEM HERE


void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
void choosing_first_card(int tablePosition, int amountInHand, int currentHand[amountInHand]);
void cocomposite(int amountInHand, int cardsPlayed[], int currentHand[]);

// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {

    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME

    printf("Don't let your memes be dreams");

}

void choose_discards() {

    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
    int initialHand[N_CARDS_INITIAL_HAND];
    int i = 0;
    while (i < N_CARDS_INITIAL_HAND) {
        scanf("%d",&initialHand[i]);
        i++;
    }
    
    /*
    int x = 0;
    
    while (x < N_CARDS_INITIAL_HAND) {    
        int y = 0;
        while (y < N_CARDS_INITIAL_HAND) {
            if (array[x] > array[y]) {
                int temp = array[x];
                array[x] = array[y];
                array[y] = temp;
                
            }
            y++;
        }
        i++;
    }
    */
    int discardCount = 0;
    int counter = 0;
    //discards card 42
    while (counter < N_CARDS_INITIAL_HAND) {     
        if (initialHand[counter] == 42) {
            printf("42 ");
            discardCount++;
        }
        counter++;
    }
    // array is sorted ascending order, so start checking from highest number
    int counter1 = N_CARDS_INITIAL_HAND - 1 ;
    while (counter1 >= 0) {                      
        if (discardCount < 3) {
            if (initialHand[counter1] == 47 || initialHand[counter1] == 43 || initialHand[counter1] == 41 || initialHand[counter1] == 37 || 
            initialHand[counter1] == 31) {
                printf("%d ", initialHand[counter1]);
                discardCount++;
            }
        }
        counter1--;
    }
    int counter2 = N_CARDS_INITIAL_HAND - 1 ;
    while (counter2 >= 0) {
        if (discardCount < 3) {
            if (initialHand[counter2] != 47 && initialHand[counter2] != 43 && initialHand[counter2] != 41 && initialHand[counter2] != 37 && 
            initialHand[counter2] != 31) { 
                printf("%d ", initialHand[counter2]);
                discardCount++;
            }   
        }
        counter2--;
    }   
       
    
    // NOTE: THE PROVIDED CODE PROBABLY DISCARDS CARDS NOT IN YOUR HAND
    // WHICH IS NOT LEGAL AND WILL RECEIVE PENALTY POINTS
    // YOU MUST CHANGE IT TO DISCARD CARDS FROM YOUR HAND.
}


void choose_card_to_play(void) {

    // ADD CODE TO READ THE FIRST THREE NUMBERS WHICH ARE:
    // NUMBER OF CARDS IN YOUR HAND,  NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION
    int amountInHand = 0;
    int amountPlayed = 0;
    int tablePosition = 0;
    scanf("%d", &amountInHand);
    scanf("%d",&amountPlayed);
    scanf("%d",&tablePosition);
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int currentHand[amountInHand];
    int i = 0;
    while (i < amountInHand) {
        scanf("%d", &currentHand[i]);
        i++;
    }
    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    // I am stupid
    if (amountPlayed != 0) {
        int cardsPlayed[amountPlayed];
        int counter = 0;
        while (counter < amountPlayed) {
            scanf("%d", &cardsPlayed[counter]);
            counter++;
        }
    }
    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int arraySize = (N_CARDS_INITIAL_HAND - amountInHand)*4;
    if(arraySize != 0) {
        int cardHistory[arraySize];
        int counter1 = 0;
        while (counter1 < arraySize) {
            scanf("%d", &cardHistory[counter1]);
            counter1++;
        }
    }
    // Code for scanning discarded cards
    int discards[3];
    int counter2 = 0;
    while (counter2 < 3) {
        scanf("%d", &discards[counter2]);
        counter2++;
    }
    // Code for scanning cards received from previous player
    int receivedCards[3];
    int counter3 = 0;
    while (counter3 < 3) {
        scanf("%d", &receivedCards[counter3]);
        counter3++;
    }
    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
    choosing_first_card(tablePosition, amountInHand, currentHand);
    

}

// ADD YOUR FUNCTIONS HERE
void choosing_first_card(int tablePosition, int amountInHand, int currentHand[]) {
    if (tablePosition == 0 && amountInHand == 10) {
        int i = 0;
        while (i < amountInHand) {
            if (currentHand[i] == 11 || currentHand[i] == 13 || currentHand[i] == 17 || currentHand[i] == 19
            || currentHand[i] == 23 || currentHand[i] == 29) {
                printf("%d", currentHand[i]);
            }
            i++;
        }
    }

}

void cocomposite(int amountInHand, int cardsPlayed[], int currentHand[]) { 
    int first_card = cardsPlayed[0];
    int counter1 = 0;
    int arrayLength = 0;
    //figure out array length of cocomposite array to be able to declare it
    while (counter1 < amountInHand) {
        int counter2 = 2;
        while (counter2 <= 9) {
            if( currentHand[counter1] % counter2 == 0 && first_card % counter2 == 0) {
                arrayLength++;
                break;
            }
            counter2++;
        }
        counter1++;
    }
    int cocomposite[arrayLength];
    int counter3 = 0;
    int arrayPosition = 0;
    while (counter3 < amountInHand) {
        int counter4 = 2;
        while (counter4 <= 9) {
            if( currentHand[counter3] % counter4 == 0 && first_card % counter4 == 0) {
                cocomposite[arrayPosition] = currentHad[counter3];
                arrayPosition++;
                break;
            }
            counter4++;
        }
        counter3++;
    }
      
         
}
/*void sort_array(int arrayLength, int cocomposite[]) {
    int i = 0;
    while(i < 6) {
        int y = 0;
        while(y < 6) {
            if(array[i] > array[y]) {
                int temp = array[i];
                array[i] = array[y];
                array[y] = temp;
                
            }
            y++;
        }
        i++;
    }
    
    int z = 0;
    while(z < 6) {
        printf("%d ", array[z]);
        z++;
    }
} 
*/    
