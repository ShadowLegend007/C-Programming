#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct moviedetails 
{
    char name[20];
    unsigned int phone;
    int seat;
    int id;
};

struct moviedetails person[300];
int count = 0;
int id2 = 1000;

int changeprize(int prize);
void reservation(int *array, int price, int slection);
int choice1(void);
void cancel(int *array);
void ticket1(int choice, char name[20], int id2, int price);
void details(void);
int movie(void);
void ticket2(int choice, char name[20], int id2, int price);
int cmovie(void);
void ticket3(int choice, char name[20], int id2, int price);

int main() 
{
    int **seat, choice, price = 500, slection, i;
    seat = (int **)calloc(3, sizeof(int *));
    for (i = 0; i < 3; i++)
        seat[i] = (int *)calloc(101, sizeof(int));

    int x = 0; // Initialize x to 0
    while (x != 5) {
        choice = choice1();
        switch (choice) {
            case 1:
                price = changeprize(price);
                break;
            case 2:
                details();
                break;
            case 3:
                slection = movie();
                reservation(seat[slection - 1], price, slection);
                count++;
                break;
            case 4:
                slection = cmovie();
                cancel(seat[slection - 1]);
                break;
            case 5:
                x = 5;
                break;
            default:
                printf("Choice not available\n");
                break;
        }
    }

    // Free allocated memory
    for (i = 0; i < 3; i++)
        free(seat[i]);
    free(seat);

    return 0;
}

int changeprize(int prize) {
    char pass[10], pak[10] = "admin";
    printf("Enter the password to change price of ticket: ");
    scanf("%s", pass);
    if (strcmp(pass, pak) == 0) {
        printf("Please enter new price: ");
        scanf("%d", &prize);
        system("PAUSE");
        system("CLS");
    } else {
        printf("The entered password is wrong! ");
    }
    return prize;
}

void reservation(int *array, int price, int slection) {
    int i, j;
    printf("\n                                SCREEN\n\n\n");
    for (i = 1; i <= 100; i++) {
        if (array[i] == 0)
            printf("%d\t", i);
        else
            printf("*\t");
        if (i % 10 == 0)
            printf("\n\n");
    }
    printf("Please enter your name: ");
    scanf(" %19[^\n]", person[count].name);
    printf("Please enter your phone number: ");
    scanf("%u", &person[count].phone);
    printf("Which seat number do you want? ");
    scanf("%d", &j);
    
    while (j > 100 || j < 1 || array[j] == 1) {
        if (array[j] == 1) {
            printf("Sorry, this ticket is already booked! Please choose another seat.\n");
        } else {
            printf("Seat number is unavailable in this theater\n");
        }
        printf("Please re-enter seat number: ");
        scanf("%d", &j);
    }

    array[j] = 1;
    person[count].seat = j;

    if (slection == 1)
        ticket1(j, person[count].name, id2, price);
    else if (slection == 2)
        ticket2(j, person[count].name, id2, price);
    else
        ticket3(j, person[count].name, id2, price);
    
    person[count].id = id2++;
}

int choice1(void) {
    int choice;
    printf("                 Simple Movie Ticket Booking System\n");
    printf(" ==================================================================\n");
    printf("||             1- To edit price of ticket (only admin):           ||\n");
    printf("||             2- To view reserved tickets (only admin):          ||\n");
    printf("||             3- To purchase ticket:                             ||\n");
    printf("||             4- To cancel the seat:                             ||\n");
    printf("||             5- Exit system:                                    ||\n");
    printf(" ==================================================================\n");
    printf("  Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void cancel(int *array) {
    int Cseat, i, stop = 0;
    printf("Please enter ID number of ticket: ");
    scanf("%d", &Cseat);
    for (i = 0; i < count; i++) {
        if (Cseat == person[i].id) {
            stop = 1;
            printf("%s, your seat %d has been cancelled.\n", person[i].name, person[i].seat);
            array[person[i].seat] = 0;
            break;
        }
    }
    if (!stop) {
        printf("Ticket ID number is incorrect. Please enter the correct one to cancel the ticket: \n");
    }
}

void ticket1(int choice, char name[20], int id2, int price) {
    system("cls");
    printf("\n\n");
    printf("\t-----------------THEATER BOOKING TICKET----------------\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : Toy Story 6\n", id2);
    printf("\t Customer  : %s\n", name);
    printf("\t\t\t                              Date      : 29-04-2024\n");
    printf("\t                                              Time      : 08:00pm\n");
    printf("\t                                              Hall      : 02\n");
    printf("\t                                              Seat No. : %d  \n", choice);
    printf("\t                                              Price . : %d  \n\n", price);
    person[count].id = id2;
    printf("\t============================================================\n");
}

void details(void) {
    int i;
    char pass[10], pak[10] = "admin";
    printf("Enter the password to see details: ");
    scanf("%s", pass);
    if (strcmp(pass, pak) == 0) {
        for (i = 0; i < count; i++) {
            printf("Seat no: %d is booked by %s, booking ID is %d\n", person[i].seat, person[i].name, person[i].id);
        }
    } else {
        printf("Entered password is wrong.\n");
    }
    system("PAUSE");
    system("CLS");
}

int movie(void) {
    int i;
    system("cls");
    printf("\t\t\tWhich movie do you want to see?\n");
    printf("\t\t\t----------------------------\n\n");
    printf("\t\t\tPress 1 for Toy Story 6\n\n");
    printf("\t\t\tPress 2 for Pokemon\n\n");
    printf("\t\t\tPress 3 for Naruto: Movie 1\n");
    scanf("%d", &i);
    system("cls");
    return i;
}

void ticket2(int choice, char name[20], int id2, int price) {
    system("cls");
    printf("\n\n");
    printf("\t-----------------THEATER BOOKING TICKET----------------\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : Pokemon\n", id2);
    printf("\t Customer  : %s\n", name);
    printf("\t\t\t                              Date      : 15-04-2022\n");
    printf("\t                                              Time      : 09:00pm\n");
    printf("\t                                              Hall      : 03\n");
    printf("\t                                              Seat No. : %d  \n", choice);
    printf("\t                                              Price . : %d  \n\n", price);
    person[count].id = id2;
    printf("\t============================================================\n");
}

int cmovie(void) {
    int i;
    printf("\t\t\tWhich movie ticket do you want to cancel?\n");
    printf("\t\t\t-------------------------------------\n");
    printf("\t\t\tPress 1 for Toy Story 6\n\n");
    printf("\t\t\tPress 2 for Pokemon\n\n");
    printf("\t\t\tPress 3 for Naruto: Movie 1\n");
    scanf("%d", &i);
    return i;
}

void ticket3(int choice, char name[20], int id2, int price) {
    system("cls");
    printf("\n\n");
    printf("\t-----------------SIMPLE TICKETING SYSTEM----------------\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : Naruto: Movie 1\n", id2);
    printf("\t Customer  : %s\n", name);
    printf("\t\t\t                              Date      : 12-05-2021\n");
    printf("\t                                              Time      : 10:00pm\n");
    printf("\t                                              Hall      : 04\n");
    printf("\t                                              Seat No. : %d  \n", choice);
    printf("\t                                              Price . : %d  \n\n", price);
    person[count].id = id2;
    printf("\t============================================================\n");
}