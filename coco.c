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

#define DUMMY_AVOID_ZERO     20
#define DISCARD_AMOUNT       3
#define FACTORS              9
#define DOUGLAS              42

// IF YOU NEED MORE #defines ADD THEM HERE


void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
void choosing_first_card(int amountPlayed, int amountInHand, 
                         int currentHand[amountInHand], int cardHistory[]);
void cocompositeSelection(int amountInHand, int amountPlayed, int totalPlayed,
                          int cardsPlayed[], int currentHand[], 
                          int cardHistory[], int discards[]);
int check_prime(int arrayLength, int array[]);
int check_douglas(int arrayLength, int array[]);
void sort_array(int arrayLength, int *arr );
void printCocomposite (int arrayLength, int cardsPlayed[], int cocomposite[]);
void no_cocomposite(int amountInHand, int currentHand[]);
void cocomposite_array(int first_card, int amountInHand, 
                       int cocomposite[], int currentHand[]);
int cocomposite_array_length(int amountInHand, int first_card, int currentHand[]);
int discard_large_prime(int card);
void print_non_prime (int amountInHand, int currentHand[]);
int prime_first_card(int card);
void prime_array(int amountInHand, int currentHand[], int prime[]);
int prime_array_length(int amountInHand, int currentHand[]);
void primeSelection (int amountInHand, int amountPlayed, int totalPlayed, 
                    int cardsPlayed[], int currentHand[], int cardHistory[]);
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
    int discardCount = 0;
    int counter = 0;
    //discards card 42
    while (counter < N_CARDS_INITIAL_HAND) {     
        if (initialHand[counter] == DOUGLAS) {
            printf("%d ",DOUGLAS);
            discardCount++;
        }
        counter++;
    }
    // array is sorted ascending order, so start checking from highest number
    int counter1 = N_CARDS_INITIAL_HAND - 1 ;
    while (counter1 >= 0) {                      
        if (discardCount < 3) {   
            if (discard_large_prime(initialHand[counter1]) == 1) {
                printf("%d ", initialHand[counter1]);
                discardCount++;
            }
        }
        counter1--;
    }
    int counter2 = N_CARDS_INITIAL_HAND - 1 ;
    while (counter2 >= 0) {
        if (discardCount < 3) { //!discardCondition1()==1
            if (initialHand[counter2] != 47 && initialHand[counter2] != 43 && 
            initialHand[counter2] != 41 && initialHand[counter2] != 37 &&       
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
    scanf("%d", &amountPlayed);
    scanf("%d", &tablePosition);
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
    if (amountPlayed == 0) {
        amountPlayed = DUMMY_AVOID_ZERO;
    }
    int cardsPlayed[amountPlayed];
    if (amountPlayed != DUMMY_AVOID_ZERO) {
        int counter = 0;
        while (counter < amountPlayed) {
            scanf("%d", &cardsPlayed[counter]);
            counter++;
        }
    }
    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int totalPlayed = (N_CARDS_INITIAL_HAND - amountInHand)*4;
    if (totalPlayed == 0) {
        totalPlayed = DUMMY_AVOID_ZERO;
    }
    int cardHistory[totalPlayed];
    if (totalPlayed != DUMMY_AVOID_ZERO) {
        int counter1 = 0;
        while (counter1 < totalPlayed) {
            scanf("%d", &cardHistory[counter1]);
            counter1++;
        }
    }
    // Code for scanning discarded cards
    int discards[DISCARD_AMOUNT];
    int counter2 = 0;
    while (counter2 < DISCARD_AMOUNT) {
        scanf("%d", &discards[counter2]);
        counter2++;
    }
    // Code for scanning cards received from previous player
    int receivedCards[DISCARD_AMOUNT];
    int counter3 = 0;
    while (counter3 < DISCARD_AMOUNT) {
        scanf("%d", &receivedCards[counter3]);
        counter3++;
    }
    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
    
    if (amountPlayed == DUMMY_AVOID_ZERO) {
        choosing_first_card(amountPlayed, amountInHand, currentHand, cardHistory);
    } 
    else if (amountPlayed != DUMMY_AVOID_ZERO && prime_first_card(cardsPlayed[0]) == 1) {
        primeSelection(amountInHand, amountPlayed, totalPlayed, 
                       cardsPlayed, currentHand, cardHistory);
    }
    else {
        cocompositeSelection(amountInHand, amountPlayed, totalPlayed, cardsPlayed, 
                                              currentHand, cardHistory, discards); 
    }

}

// ADD YOUR FUNCTIONS HERE
void choosing_first_card(int amountPlayed, int amountInHand, int currentHand[], int cardHistory[]) {
    int i = amountInHand - 1;
    int counter1 = amountInHand - 1;
    int first_card = (N_CARDS_INITIAL_HAND - amountInHand)*4 - 1;
    if (amountInHand ==10) {
        print_non_prime(amountInHand,currentHand);
    } 
    else if (amountInHand >= 6) {    //change this function, prime restriction       
        if (prime_first_card(cardHistory[first_card]) == 1) {  //checks first card previous round
            while (i >= 0) {
                if (currentHand[i] == 29 || currentHand[i] == 31 || 
                    currentHand[i] == 37 || currentHand[i] == 41) {
                    printf("%d\n", currentHand[i]);
                    break;
                }
                i--;
            }   
        }
        else {  
            print_non_prime(amountInHand,currentHand); 
        } 
    } 
    
    else if (amountInHand <= 5) {
        if (prime_first_card(cardHistory[first_card]) == 1) {  //checks first card previous round
            while (counter1 >= 0) {
                if (currentHand[counter1] == 11 || currentHand[counter1] == 13 || 
                    currentHand[counter1] == 17 || currentHand[counter1] == 19) {
                    printf("%d\n", currentHand[i]);
                    break;
                }
                counter1--;
            }   
        }
        else {  
            print_non_prime(amountInHand,currentHand); 
        }       
    }     
}

void cocompositeSelection(int amountInHand, int amountPlayed, int totalPlayed, 
                          int cardsPlayed[], int currentHand[], int cardHistory[],
                          int discards[]) { 
    int first_card = cardsPlayed[0];
    //figure out array length of cocomposite array to be able to declare it
    int arrayLength = cocomposite_array_length(amountInHand, first_card, currentHand);
    //if arrayLength is 0 set as dummy value
    if (arrayLength == 0) {
        arrayLength = DUMMY_AVOID_ZERO;
    }
    //list of cocomposites as an array
    int cocomposite[arrayLength];
    if(arrayLength != DUMMY_AVOID_ZERO) {
        cocomposite_array(first_card, amountInHand, cocomposite, currentHand);
    }
    //sort cardsPlayed array to check largest number played so far
    int *p = cardsPlayed;
    sort_array(amountPlayed, p);
    //checks if the number 42 has been played in previous rounds    
    int douglas = 0;
    if (totalPlayed != DUMMY_AVOID_ZERO) {
        douglas = check_douglas(totalPlayed, cardHistory);
    }
    else {
        douglas = 0;
    }
    //if douglas has been played, risk of playing large number lowered
    if(arrayLength != DUMMY_AVOID_ZERO) {
        if (douglas == 1) {
            printf("%d\n", cocomposite[arrayLength - 1]);
        }
        else {
            douglas = check_douglas(amountPlayed, cardsPlayed);
            if (douglas == 1) {
                printf("%d\n", cocomposite[arrayLength - 1]);
                //printCocomposite(arrayLength, cardsPlayed, cocomposite);
            }
            else {
                //checks if next person has douglas
                douglas = check_douglas(DISCARD_AMOUNT, discards);
                if (douglas == 1) {
                    printCocomposite(arrayLength, cardsPlayed, cocomposite);    
                }
                else {
                    printf("%d\n", cocomposite[arrayLength - 1]);
                }
            }           
        }
    }
    else if (check_prime(amountInHand, currentHand) == 1) {
        no_cocomposite(amountInHand, currentHand);
    }
    else {          
        printf("%d\n", currentHand[amountInHand-1]);                            
    }
}
//play small number near the end of the round
void primeSelection (int amountInHand, int amountPlayed, int totalPlayed, 
                    int cardsPlayed[], int currentHand[], int cardHistory[]) {
    int arrayLength = prime_array_length(amountInHand, currentHand);
    if (arrayLength == 0) {
        arrayLength = DUMMY_AVOID_ZERO;
    }
    int prime[arrayLength];
    if (arrayLength != DUMMY_AVOID_ZERO) {
        prime_array(amountInHand, currentHand, prime);
    }
    int *p = cardsPlayed;
    sort_array(amountPlayed, p);
    int primePlayed = 0;
    if (arrayLength != DUMMY_AVOID_ZERO) {
        if (amountPlayed == 1 || amountPlayed == 2) {
            int i = arrayLength - 1;
            while (i >= 0) {
                if (prime[i] < cardsPlayed[0]) {
                    printf("%d\n", prime[i]);
                    primePlayed = 1;
                    break;
                }
                i--;
            }
            if (primePlayed == 0) {
                printf("%d\n",prime[0]);
            }
        }
        else if (amountPlayed == 3) {
            int j = arrayLength - 1;
            while (j >= 0) {
                if (prime[j] < cardsPlayed[0]) {
                    printf("%d\n", prime[j]);
                    primePlayed = 1;
                    break;
                }
                j--;
            }   
            if (primePlayed == 0) {
                printf("%d\n",prime[arrayLength - 1]);
            }
        }
    }
    else {
        printf("%d\n", currentHand[amountInHand-1]);
    }       
}      
                        


//checks if prime number was the first card last round
int prime_first_card(int card) {
    int prime = 0;
    if (card == 11 || card == 13 || card == 17 || card == 19 
     || card == 23 || card == 29 || card == 31 || card == 37 
     || card == 41 || card == 43 || card == 47) {
        prime = 1;
    }
    return prime;
}

//check how many prime numbers in current hand
int prime_array_length(int amountInHand, int currentHand[]) {
    int counter1 = 0;
    int arrayLength = 0;
    while (counter1 < amountInHand) {
        int card = currentHand[counter1];
        if (prime_first_card(card) == 1) {
            arrayLength++;
        }
        counter1++;
    }
            
    return arrayLength;
}
//array for playing prime numbers
void prime_array(int amountInHand, int currentHand[], int prime[]) {
    int counter = 0;
    int arrayPosition = 0;
    while (counter < amountInHand) {
        int card = currentHand[counter];
        if (prime_first_card(card) == 1) {
            prime[arrayPosition] = card  ;
            arrayPosition++;
        }
        counter++;
    }
}              

//check if a prime number is in an array
int check_prime(int arrayLength, int array[]) {
    int i = 0;
    int prime = 0;
    while (i < arrayLength) {
        if (array[i] == 11 || array[i] == 13 || array[i] == 17 || array[i] == 19 
         || array[i] == 23 || array[i] == 29 || array[i] == 31 || array[i] == 37 
         || array[i] == 41 || array[i] == 43 || array[i] == 47) {
            prime = 1;
        }
        i++;
    }
    return prime;
}
//checks if the number 42 is in an array
int check_douglas(int arrayLength, int array[]) {
    int selectCounter = 0;
    int douglas = 0;
    while (selectCounter < arrayLength) {
        if (array[selectCounter] == DOUGLAS) {
            douglas = 1;
            break;      
        }
        selectCounter++;
    }        
    return douglas;
}
//sorts array greatest to least
void sort_array(int arrayLength, int *arr ) {
    int i = 0;
    while (i < arrayLength) {
        int y = 0;
        while (y < arrayLength) {
            if (arr[i] > arr[y]) {
                int temp = arr[i];
                arr[i] = arr[y];
                arr[y] = temp;
            }
            y++;
        }
        i++;
    }  
}
//chooses a cocomposite less than current largest number
void printCocomposite (int arrayLength, int cardsPlayed[], int cocomposite[]) {
    int printCounter = arrayLength - 1;       
    while (printCounter >= 0) {
        if (cocomposite[printCounter] < cardsPlayed[0]) {
            printf("%d ", cocomposite[printCounter]);
            break;
        }
        //no suitable card condition
        else if (printCounter == 0) {
            printf("%d ", cocomposite[arrayLength - 1]);
        }       
        printCounter--;
    }
}

//prints prime number if no cocomposite available
void no_cocomposite(int amountInHand, int currentHand[]) {
int printCounter = amountInHand - 1;
    while (printCounter >= 0) {
        if (currentHand[printCounter] == 47 || currentHand[printCounter] == 43 ||
            currentHand[printCounter] == 41 || currentHand[printCounter] == 37) {
            printf("%d ", currentHand[printCounter]);
            break;
            }
        else if (printCounter == 0) {
            printf("%d ", currentHand[amountInHand-1]);   
        }
        printCounter--;
    }
}

//creates an array of cocomposites
void cocomposite_array(int first_card, int amountInHand, int cocomposite[], 
                       int currentHand[]) { 
    int counter3 = 0;
    int arrayPosition = 0;
    while (counter3 < amountInHand) {
        int counter4 = 2;
        while (counter4 <= FACTORS) {
            if(currentHand[counter3] % counter4 == 0 && first_card % counter4 == 0) {
                cocomposite[arrayPosition] = currentHand[counter3];
                arrayPosition++;
                break;
            }
            counter4++;
        }
        counter3++;
    }
}
//11, 12, 13, 19, 36, 39, 41, 43, 47, 48
//calculate array length of cocomposite array to be able to declare it
int cocomposite_array_length(int amountInHand, int first_card, int currentHand[]) {
    int counter1 = 0;
    int arrayLength = 0;
    while (counter1 < amountInHand) {
        int counter2 = 2;
        while (counter2 <= FACTORS) {
            if (currentHand[counter1] % counter2 == 0 && first_card % counter2 == 0) {
                arrayLength++;
                break;
            }
            counter2++;
        }
        counter1++;
    }
    return arrayLength;
}
int discard_large_prime(int card) {
    int discard = 0;
    if(card == 47 || card == 43 || card == 41 || card == 37 || card == 31) {
        discard = 1;
    }
    return discard;
}
//if possible, prints a number that will not be penalized if another player plays 42
void print_non_prime (int amountInHand, int currentHand[]) {  
    int counter = amountInHand - 1;
    while (counter >= 0) {
        int card = currentHand[counter];
        if (card < DOUGLAS) {
            if(card % 2 == 0 || card % 3 == 0 || card % 5 == 0 || card % 7 == 0){
                printf("%d\n", card);
                break;
            }
        }
        else if (counter == 0) {
            printf("%d ", currentHand[amountInHand-1]);   
        }       
        counter--;
    }
}     
