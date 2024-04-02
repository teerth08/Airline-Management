#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char *strremove(char *str, const char *sub);
int check_file_empty(FILE *fp);
int delete_line(char *filename, int line_to_delete);
int comp_str(char str1[], char str2[]);
int add_line(char filename[20], int line, char newline[20]);
int seat_checker(char seat_type[10], int line_num);
int pricing(int dep_month, int dep_date, int curr_month, int curr_date, int base_price, char flight[]);
int line_link(char name[], int date, int month, FILE *des, FILE *dates, FILE *months);
int check_date(int date, int month);
void enterflight(int Flight_No, char Destination[20], int Date, int Month, char Airline[20], int Seats_Eco, int Seats_Bus, int Price_Eco, int Price_Bus);
int get_line_flight(int num);
int delete_flight(int num);
void book_ticket(int line, int count, char Destination[], char Name[], char Gender[], char seattype[], int Age, int travel_date, int travel_month, int final_price);
int delete_booking(int num);
char *int_to_string(int num);
int seat_increase(char seat_type[10], int line_num);

