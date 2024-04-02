#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"

void enterflight(int Flight_No, char Destination[20], int Date, int Month, char Airline[20], int Seats_Eco, int Seats_Bus, int Price_Eco, int Price_Bus){
	    FILE *fdata;
	    FILE *flightnos;
	    FILE *des;
	    FILE *dates;
	    FILE *months;
	    FILE *seateco;
	    FILE *seatbus;
	    FILE *priceeco;
	    FILE *pricebus;
	    	fdata=fopen("data.txt", "a+");
            	flightnos=fopen("flightnums.txt", "a+");
            	des=fopen("dest.txt", "a+");
            	dates=fopen("date.txt", "a+");
            	months=fopen("month.txt", "a+");
            	seateco=fopen("seat_eco.txt", "a+");
            	seatbus=fopen("seat_bus.txt", "a+");
            	priceeco=fopen("price_eco.txt", "a+");
            	pricebus=fopen("price_bus.txt", "a+");
		fprintf(fdata, "Flight No: %d\n", Flight_No);
                fprintf(fdata, "Destination: %s\n", Destination);
                fprintf(fdata, "Date of Departure: %d/%d\n", Date, Month);
                fprintf(fdata, "Airline: %s\n", Airline);
                fprintf(fdata, "Economy seats: %d\n", Seats_Eco);
                fprintf(fdata, "Business seats: %d\n", Seats_Bus);
                fprintf(fdata, "Base price of Economy seat: %d\n", Price_Eco);
                fprintf(fdata, "Base price of Business seat: %d\n", Price_Bus);
                fprintf(flightnos, "%d\n", Flight_No);
                fprintf(des, "%s\n", Destination);
                fprintf(dates, "%d\n", Date);
                fprintf(months, "%d\n", Month);
                fprintf(seateco, "%d\n", Seats_Eco);
                fprintf(seatbus, "%d\n", Seats_Bus);
                fprintf(priceeco, "%d\n", Price_Eco);
                fprintf(pricebus, "%d\n", Price_Bus);
                fclose(des);
                fclose(dates);
                fclose(fdata);
                fclose(flightnos);
                fclose(months);
                fclose(seateco);
                fclose(seatbus);
                fclose(priceeco);
                fclose(pricebus);
}
		
            	
int delete_flight(int num){

            	char name1[20]="data.txt";
            	char name2[20]="flightnums.txt";
            	char name3[20]="date.txt";
            	char name4[20]="dest.txt";
            	char name5[20]="month.txt";
            	char name6[20]="seat_eco.txt";
            	char name7[20]="seat_bus.txt";
            	char name8[20]="price_eco.txt";
            	char name9[20]="price_bus.txt";
            	int n, line=1, check=0;
		FILE *flightnos=fopen("flightnums.txt", "r");
		char str[50];
		fgets(str, 50, flightnos);
            	while (!feof(flightnos)){
            		n=atoi(str);
            		if (n==num){
            			check=1;
            			break;
            		}
            		line++;
            		fgets(str, 50, flightnos);
            	}
            	fclose(flightnos);
            	if (check==1){
            		check=(8*(line-1))+1;
		    	for (int i=0; i<8; i++){
		    		delete_line(name1, check);
		    	}
		    	delete_line(name2, line);
		    	delete_line(name3, line);
		    	delete_line(name4, line);
		    	delete_line(name5, line);
		    	delete_line(name6, line);
		    	delete_line(name7, line);
		    	delete_line(name8, line);
		    	delete_line(name9, line);
		    	return 1;
		 }
            	else{
		    	printf("No flight found\n");
		}
		return 0;
}
void book_ticket(int line, int count, char Destination[], char Name[], char Gender[], char seattype[], int Age, int travel_date, int travel_month, int final_price){
						printf("\n");
						FILE *flightnos=fopen("flightnums.txt", "r");
						FILE *ptr = fopen("file.txt","a+");
						FILE *ptr1 = fopen("id.txt","a");
						fprintf(ptr,"Ticket ID: %d\n",count);
						fprintf(ptr1,"%d\n",count);
						fprintf(ptr,"Destination: %s\n",Destination);
						fprintf(ptr,"Name: %s\n",Name);
						fprintf(ptr,"Gender: %s\n",Gender);
						fprintf(ptr,"Seat Type: %s\n",seattype);
						fprintf(ptr,"Age: %d\n",Age);
						fprintf(ptr,"Travel Date: %d/%d\n",travel_date, travel_month);
						fprintf(ptr, "Price: %d\n", final_price);
						int line_no=1;
				    		int flight_rep;
				    		char new[50];
				    		while(fgets(new, 50, flightnos)!=NULL){
				    			int flight=atoi(new);
				    			if (line_no==line){
				    				flight_rep=flight;
				    				fprintf(ptr, "Flight No: %d\n", flight_rep);
				    				break;
				    			}
				    			line_no++;
				    		}
				    		line_no=1;
				    		int check=(8*(line-1))+4;
				    		FILE *data=fopen("data.txt", "a+");
				    		while(fgets(new, 50, data)!=NULL){
				    			if (line_no==check){
				    				fprintf(ptr, "%s", new);
				    				break;
				    			}
				    			line_no++;
				    		}
						printf("Congratulation your Ticket was succesfully booked\n");
						printf("The Ticket ID of your booking is %d\n", count);
						fclose(ptr);
						fclose(ptr1);
						fclose(data);
						fclose(flightnos);
}
int delete_booking(int num){
				int line=1;
				FILE *flightnos=NULL;
				flightnos=fopen("id.txt", "r");
				char str[50];
				char ch;
				int n, check=0;
				char name1[20]="id.txt";
				char name2[20]="file.txt";
				fgets(str, 50, flightnos);
				while (!feof(flightnos)){
				        n=atoi(str);
				        if (n==num){
				                check=1;
				                break;
				        }
				        line++;
				        fgets(str, 50, flightnos);
				}
				rewind(flightnos);
				fclose(flightnos);
				//seat increase
				int new_line=(10*(line-1))+5;
				int count=1;
				flightnos=fopen("file.txt", "r");
				fgets(str, 50, flightnos);
				char newstr1[10];
				while (!feof(flightnos)){
				        if (count==new_line){
				                strcpy(newstr1, str);
				        }
				        if (count==new_line+4){
				        	break;
				        }
				        count++;
				        fgets(str, 50, flightnos);
				}
				fclose(flightnos);
				char *type=strremove(newstr1,"Seat Type: ");
				char *flight=strremove(str, "Flight No: ");
				n=atoi(flight);
				flightnos=fopen("flightnums.txt", "r");
				rewind(flightnos);
				int line_no=1;
				int new_n;
				fgets(str, 50, flightnos);
				while (!feof(flightnos)){
				        new_n=atoi(str);
				        if (new_n==n){
				                break;
				        }
				        line_no++;
				        fgets(str, 50, flightnos);
				}
				fclose(flightnos);
				seat_increase(type, line_no);
				if(check){
					delete_line("id.txt", line);
				        check=(10*(line-1))+1;
				        for (int i=0; i<10; i++){
				        	delete_line(name2, check);
				        }
				        return 1;
				}
				
				else{
				        printf("No booking found\n");
				}
				
				return 0;
}
char *int_to_string(int num) {
    int i = 0;
    int is_negative = 0;
    char *str = malloc(20); // allocate memory for maximum length of integer
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }
    while (num != 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    if (is_negative) {
        str[i++] = '-';
    }
    str[i] = '\0';
    int len = strlen(str);
    for (int j = 0; j < len / 2; j++) {
        char tmp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = tmp;
    }
    return str;
}
