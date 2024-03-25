#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 5
#define MAX_NAME_LENGTH 50

// Structure to represent a flight
typedef struct {
    char name[MAX_NAME_LENGTH];  // Flight name
    char date[20];               // Date of the flight
    char departure[50];          // Departure city
    char destination[50];        // Destination city
    char seatPosition[20];       // Seat position (aisle, window, middle)
    char mealOption[20];         // Meal option (e.g., vegetarian, non-vegetarian)
    char class[20];              // Class (economy, business, first class)
    int passengers;              // Number of passengers (adults + infants)
    int adults;                  // Number of adult passengers
    int infants;                 // Number of infant passengers
    int national;                // 1 if national flight, 0 if international
    float price;                 // Price of the flight
    int baggageCount;            // Number of baggage
    int baggageLimit;            // Baggage limit per passenger
    int bookedSeats;             // Number of seats booked
    int capacity;                // Total capacity of the flight
    
} Flight;

// Function prototypes
void displayMenu();
void displayFlights(Flight flights[], int numFlights);
void bookTicket(Flight *flight);

int main() {
    // Creation of an array of flights
    Flight flights[MAX_FLIGHTS] = {
        {"Air India Express", "2022-03-25", "New Delhi", "Mumbai", "Aisle", "Vegetarian", "Economy", 200, 2, 0, 1, 4000, 2, 20, 0, 100},
        {"Indigo", "2022-03-26", "Mumbai", "Kolkata", "Window", "Non-Vegetarian", "Business", 150, 2, 0, 0, 6000, 2, 25, 0, 150},
        {"SpiceJet", "2022-03-27", "Kolkata", "Chennai", "Middle", "Vegetarian", "First Class", 100, 1, 0, 1, 8000, 2, 30, 0, 200},
        {"Air Asia", "2022-03-28", "Chennai", "Bangalore", "Aisle", "Non-Vegetarian", "Economy", 120, 1, 0, 0, 3500, 1, 15, 0, 120},
        {"Air India", "2022-03-29", "Bangalore", "New Delhi", "Window", "Vegetarian", "Economy", 180, 1, 0, 1, 4500, 1, 20, 0, 180}
    };

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlights(flights, MAX_FLIGHTS);
                break;
            case 2: {
                printf("Enter the flight number to book a ticket: ");
                int flightNumber;
                scanf("%d", &flightNumber);
                if (flightNumber >= 1 && flightNumber <= MAX_FLIGHTS) {
                    bookTicket(&flights[flightNumber - 1]);
                } else {
                    printf("Invalid flight number!\n");
                }
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n===== Flight Ticket Booking System =====\n");
    printf("1. View Available Flights\n");
    printf("2. Book a Ticket\n");
    printf("3. Exit\n");
}

// Function to display available flights
void displayFlights(Flight flights[], int numFlights) {
    printf("\nAvailable Flights:\n");
    printf("Flight No.\tName\t\tDate\t\tDeparture\tDestination\tClass\tPrice\n");
    for (int i = 0; i < numFlights; i++) {
        printf("%d\t\t%s\t%s\t%s\t\t%s\t\t%s\t%.2f\n", i + 1, flights[i].name, flights[i].date, flights[i].departure, flights[i].destination, flights[i].class, flights[i].price);
    }
}

void bookTicket(Flight *flight) {
    char passengerName[MAX_NAME_LENGTH];
    int option;

    printf("Enter your name: ");
    scanf("%s", passengerName);
    
    do {
        printf("\n===== Booking Options =====\n");
        printf("1. Choose Seat Position\n");
        printf("2. Select Meal Option\n");
        printf("3. Confirm Booking\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Choose Seat Position (Aisle, Window, Middle): ");
                scanf("%s", flight->seatPosition);
                break;
            case 2:
                printf("Select Meal Option (Vegetarian, Non-Vegetarian): ");
                scanf("%s", flight->mealOption);
                break;
            case 3:
                strcpy(flight->name, passengerName);
                printf("Booking confirmed!\n");
                printf("Your flight details:\n");
                printf("Flight Name: %s\n", flight->name);
                printf("Date: %s\n", flight->date);
                printf("Departure City: %s\n", flight->departure);
                printf("Destination City: %s\n", flight->destination);
                printf("Seat Position: %s\n", flight->seatPosition);
                printf("Meal Option: %s\n", flight->mealOption);
                printf("Class: %s\n", flight->class);
                printf("Price: %.2f\n", flight->price);
                printf("Thank you for booking with us!\n");
                flight->bookedSeats++;
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 3 && flight->bookedSeats < flight->capacity);
    
    if (flight->bookedSeats >= flight->capacity) {
        printf("Sorry, the flight is fully booked.\n");
    }
}
