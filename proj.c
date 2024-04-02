#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"
struct Admin{
    char Destination[20], Airline[20];
    int Flight_No, Seats_Eco, Seats_Bus, Date, Month, Price_Eco, Price_Bus;
};
struct User{
    char Destination[20], seattype[10], Gender[10], Name[40];
    int travel_date, travel_month, Age;
};

int main(){
    char *input=(char *)malloc(sizeof(char)*10);
    FILE *fdata, *flightnos, *des, *dates, *months, *seateco, *seatbus, *priceeco, *pricebus;
    int task, j=1, count=0;
    printf("Are you a User or Admin: ");
    fgets(input, 10, stdin);
    if (comp_str(input, "Admin")){
        while (j!=0){
            printf("\n1. Enter new flight\n");
            printf("2. Delete existing flight\n");
            printf("3. Update existing flight\n");
            printf("4. View all flights\n");
            printf("Enter any other number to exit\n");
            scanf("%d", &task);
            if (task==1){
            	fdata=fopen("data.txt", "a+");
            	flightnos=fopen("flightnums.txt", "a+");
            	des=fopen("dest.txt", "a+");
            	dates=fopen("date.txt", "a+");
            	months=fopen("month.txt", "a+");
            	seateco=fopen("seat_eco.txt", "a+");
            	seatbus=fopen("seat_bus.txt", "a+");
            	priceeco=fopen("price_eco.txt", "a+");
            	pricebus=fopen("price_bus.txt", "a+");
                struct Admin new;
                printf("Enter Destination: ");
                scanf("%s", new.Destination);
                printf("Enter Date of Departure in DD MM format: ");
                scanf("%d %d", &new.Date, &new.Month);
                while (check_date(new.Date, new.Month)!=1){
                	printf("Enter valid date: ");
                	scanf("%d %d", &new.Date, &new.Month);
                }
                printf("Enter name of Airline: ");
		scanf("%s", new.Airline);
                printf("Enter integral Flight No: ");
                scanf("%d", &new.Flight_No);
                char str[50];
                while (fgets(str, 50, flightnos) != NULL) {
        		int num=atoi(str);
        		while(new.Flight_No==num){
        			printf("A Flight exists with same Flight Number\n");
        			printf("Enter unique Flight No: ");
        			scanf("%d", &new.Flight_No);
        			rewind(flightnos);
        		}
    		}
                printf("Enter total no of Economy seats: ");
                scanf("%d", &new.Seats_Eco);
                printf("Enter total no of Business Class seats: ");
                scanf("%d", &new.Seats_Bus);
                printf("Enter Base Price for Economy Class: ");
                scanf("%d", &new.Price_Eco);
                printf("Enter Base Price for Business Class: ");
                scanf("%d", &new.Price_Bus);
                printf("The flight was successfully added\n");

		enterflight(new.Flight_No, new.Destination, new.Date, new.Month, new.Airline, new.Seats_Eco, new.Seats_Bus, new.Price_Eco, new.Price_Bus);
                
            }
            else if (task==2){
            	int num;
            	printf("Enter the Flight No of the flight to be deleted: ");
            	scanf("%d", &num);
            	int mine=delete_flight(num);
            	if(mine==1){
                	printf("The flight was successfully deleted\n");
                }
            }
            else if (task==3){
            	int num;
            	printf("Enter the Flight No of the flight to be updated: ");
            	scanf("%d", &num);
            	int mine=delete_flight(num);
            	if(mine==1){
			fdata=fopen("data.txt", "a+");
		    	flightnos=fopen("flightnums.txt", "a+");
		    	des=fopen("dest.txt", "a+");
		    	dates=fopen("date.txt", "a+");
		    	months=fopen("month.txt", "a+");
		    	seateco=fopen("seat_eco.txt", "a+");
		    	seatbus=fopen("seat_bus.txt", "a+");
		    	priceeco=fopen("price_eco.txt", "a+");
		    	pricebus=fopen("price_bus.txt", "a+");
		        struct Admin new;
		        printf("Enter Destination: ");
		        scanf("%s", new.Destination);
		        printf("Enter Date of Departure in DD MM format: ");
		        scanf("%d %d", &new.Date, &new.Month);
		        while (check_date(new.Date, new.Month)!=1){
		        	printf("Enter valid date: ");
		        	scanf("%d %d", &new.Date, &new.Month);
		        }
		        printf("Enter name of Airline: ");
			scanf("%s", new.Airline);
		        printf("Enter integral Flight No: ");
		        scanf("%d", &new.Flight_No);
		        char str[50];
		        while (fgets(str, 50, flightnos) != NULL) {
				int num=atoi(str);
				while(new.Flight_No==num){
					printf("A Flight exists with same Flight Number\n");
					printf("Enter unique Flight No: ");
					scanf("%d", &new.Flight_No);
					rewind(flightnos);
				}
	    		}
		        printf("Enter total no of Economy seats: ");
		        scanf("%d", &new.Seats_Eco);
		        printf("Enter total no of Business Class seats: ");
		        scanf("%d", &new.Seats_Bus);
		        printf("Enter Base Price for Economy Class: ");
		        scanf("%d", &new.Price_Eco);
		        printf("Enter Base Price for Business Class: ");
		        scanf("%d", &new.Price_Bus);

			enterflight(new.Flight_No, new.Destination, new.Date, new.Month, new.Airline, new.Seats_Eco, new.Seats_Bus, new.Price_Eco, new.Price_Bus);
		        
		        printf("The flight was successfully updated\n");
            	}
	}
		
            else if (task==4){
                fdata=fopen("data.txt", "r");
                char str = fgetc(fdata);
    		while (str!=EOF){
        		printf ("%c", str);
        		str = fgetc(fdata);
    		}
                fclose(fdata);
            }
            else{
                printf("Exited successfully");
                j=0;
            }
        }    //admin ka end
     }
        
        
        if (comp_str(input, "User")){
            while(j!=0){
                FILE* ptr = NULL;
	        FILE* ptr1 = NULL;
	        struct User s;
	        int n;
	        int task;
	        int count = 1;
	        ptr = fopen("count.txt","r");
	        fscanf(ptr,"%d",&count);
	        fclose(ptr);
		printf("\n");
		printf("1. Book a flight\n");
		printf("2. Update your booking\n");
		printf("3. Cancel your booking\n");
		printf("4. View your booking\n");
		printf("Enter any other number to exit\n");
		scanf("%d",&task);
		if(task == 1){
			    printf("Enter No of Tickets to Book: ");
			    scanf("%d",&n);
			    for (int i=1;i<n+1;i++){
				printf("Enter Destination: ");
				scanf("%s",s.Destination);
				printf("Enter Travel date and month in DD MM format: ");
				scanf("%d %d",&s.travel_date,&s.travel_month); 
				FILE *dates=fopen("date.txt", "r");
				FILE *months=fopen("month.txt", "r");
				FILE *des=fopen("dest.txt", "r");
				FILE *data=fopen("data.txt", "r");
				FILE *seateco=fopen("seat_eco.txt", "r");
		    		FILE *seatbus=fopen("seat_bus.txt", "r");
		    		FILE *priceeco=fopen("price_eco.txt", "r");
		    		FILE *pricebus=fopen("price_bus.txt", "r");
			    	int line=line_link(s.Destination, s.travel_date, s.travel_month, des, dates, months);
			    	if (line==-1){
			    		printf("Sorry for inconvenience but there is no such flight\n");
			    		j=0;
			    	}
			    	else{
			    		char new[50];
			    		int curr=1;
			    		int date, month, date_rep, month_rep;
			    		while(fgets(new, 50, dates)!=NULL){
			    			int date=atoi(new);
			    			if (curr==line){
			    				date_rep=date;
			    				break;
			    			}
			    			curr++;
			    		}
			    		curr=1;
			    		while(fgets(new, 50, months)!=NULL){
			    			int month=atoi(new);
			    			if (curr==line){
			    				month_rep=month;
			    				break;
			    			}
			    			curr++;
			    		}
			    		printf("Enter Date of booking in DD MM format: ");
			    		scanf("%d %d", &date, &month);
					printf("Enter Name of Passenger: ");
					scanf("%s",s.Name);
					printf("Enter Gender of Passenger: ");
					scanf("%s",s.Gender);
					printf("Enter Seat Type(Economy/Business): ");
					scanf("%s",s.seattype); 
					printf("Enter Age of Passenger: ");
					scanf("%d",&s.Age); 
					int price, price_eco, price_bus, nup=0, final_price;
					if(comp_str(s.seattype, "Economy")){
						curr=1;
			    			while(fgets(new, 50, priceeco)!=NULL){
				    			int price=atoi(new);
				    			if (curr==line){
				    				price_eco=price;
				    				break;
				    			}
				    			curr++;
			    			}
			    			final_price=pricing(s.travel_month, s.travel_date, month, date, price_eco, s.seattype);
			    			printf("The price for the ticket is: %d\n", final_price);
			    			printf("Enter 1 to continue: ");
			    			scanf("%d", &nup);
					}
					else if(comp_str(s.seattype, "Business")){
						curr=1;
			    			while(fgets(new, 50, pricebus)!=NULL){
				    			int price=atoi(new);
				    			if (curr==line){
				    				price_bus=price;
				    				nup=1;
				    				break;
				    			}
				    			curr++;
			    			}
			    			final_price=pricing(s.travel_month, s.travel_date, month, date, price_bus, s.seattype);
			    			printf("The price for the ticket is: %d\n", final_price);
			    			printf("Enter 1 to continue: ");
			    			scanf("%d", &nup);
					}
					int result=seat_checker(s.seattype, line);
					if(nup==1 && result==1){
						book_ticket(line, count, s.Destination, s.Name, s.Gender, s.seattype, s.Age, s.travel_date, s.travel_month, final_price);
						count = count+1;
						if(i<n){
						    printf("Enter your details for next Ticket\n");
					       	}

					}
				    }
				    ptr = fopen("count.txt","w");
				    fprintf(ptr,"%d",count);
				    fclose(ptr);
				    fclose(data);
			    	    fclose(flightnos);
			    	    fclose(dates);
			    	    fclose(months);
			    	    fclose(des);
			    	    fclose(seateco);
			    	    fclose(seatbus);
			    	    fclose(priceeco);
			    	    fclose(pricebus);
            		}
            		j=1;
		}
		if(task == 2){
				int num;
				printf("Enter the Ticket ID of the booking to be updated: ");
				scanf("%d", &num);
				int mine=delete_booking(num);
				if (mine){
					printf("Enter Destination: ");
					scanf("%s",s.Destination);
					printf("Enter Travel date and month in DD MM format: ");
					scanf("%d %d",&s.travel_date,&s.travel_month); 
					FILE *dates=fopen("date.txt", "r");
					FILE *months=fopen("month.txt", "r");
					FILE *des=fopen("dest.txt", "r");
					FILE *data=fopen("data.txt", "r");
					FILE *seateco=fopen("seat_eco.txt", "r");
			    		FILE *seatbus=fopen("seat_bus.txt", "r");
			    		FILE *priceeco=fopen("price_eco.txt", "r");
			    		FILE *pricebus=fopen("price_bus.txt", "r");
				    	int line=line_link(s.Destination, s.travel_date, s.travel_month, des, dates, months);
				    	if (line==-1){
				    		printf("Sorry for inconvenience but there is no such flight\n");
				    		j=0;
				    	}
				    	else{
				    	//Pricing to be given
				    		char new[50];
				    		int curr=1;
				    		int date, month, date_rep, month_rep;
				    		while(fgets(new, 50, dates)!=NULL){
				    			int date=atoi(new);
				    			if (curr==line){
				    				date_rep=date;
				    				break;
				    			}
				    			curr++;
				    		}
				    		curr=1;
				    		while(fgets(new, 50, months)!=NULL){
				    			int month=atoi(new);
				    			if (curr==line){
				    				month_rep=month;
				    				break;
				    			}
				    			curr++;
				    		}
				    		printf("Enter Date of booking in DD MM format: ");
				    		scanf("%d %d", &date, &month);
						printf("Enter Name of Passenger: ");
						scanf("%s",s.Name);
						printf("Enter Gender of Passenger: ");
						scanf("%s",s.Gender);
						printf("Enter Seat Type(Economy/Business): ");
						scanf("%s",s.seattype); 
						printf("Enter Age of Passenger: ");
						scanf("%d",&s.Age); 
						int price, price_eco, price_bus, nup=0, final_price;
						if(comp_str(s.seattype, "Economy")){
							curr=1;
				    			while(fgets(new, 50, priceeco)!=NULL){
					    			int price=atoi(new);
					    			if (curr==line){
					    				price_eco=price;
					    				nup=1;
					    				break;
					    			}
					    			curr++;
				    			}
				    			final_price=pricing(s.travel_month, s.travel_date, month, date, price_eco, s.seattype);
				    			printf("The price for the ticket is: %d\n", final_price);
				    			printf("Enter 1 to continue: ");
				    			scanf("%d", &nup);
						}
						
						else if(comp_str(s.seattype, "Business")){
							curr=1;
				    			while(fgets(new, 50, pricebus)!=NULL){
					    			int price=atoi(new);
					    			if (curr==line){
					    				price_bus=price;
					    				nup=1;
					    				break;
					    			}
					    			curr++;
				    			}
				    			final_price=pricing(s.travel_month, s.travel_date, month, date, price_bus, s.seattype);
				    			printf("The price for the ticket is: %d\n", final_price);
				    			printf("Enter 1 to continue: ");
				    			scanf("%d", &nup);
						}
					       int result=seat_checker(s.seattype, line);
						if(nup==1 && result==1){
							book_ticket(line, count, s.Destination, s.Name, s.Gender, s.seattype, s.Age, s.travel_date, s.travel_month, final_price);
							count = count+1;
						}
					    }
					    ptr = fopen("count.txt","w");
					    fprintf(ptr,"%d",count);
					    fclose(ptr);
					    fclose(data);
				    	    fclose(flightnos);
				    	    fclose(dates);
				    	    fclose(months);
				    	    fclose(des);
				    	    fclose(seateco);
				    	    fclose(seatbus);
				    	    fclose(priceeco);
				    	    fclose(pricebus);
				    	    printf("The booking was successfully updated\n");
				    }
				    j=1;
		}	
				
				else if (task == 3){
					int num;
					printf("Enter the Ticket ID of the booking to be deleted: ");
					scanf("%d", &num);
					int mine=delete_booking(num);
					if (mine){
						printf("The booking was successfully deleted\n");
					}
					j=1;

				}
				else if (task == 4){
					int id;
					FILE *ptr, *ptr1;
					printf("Enter Ticket ID of the booking to be viewed: ");
					scanf("%d",&id);
					ptr=fopen("file.txt","r");
					ptr1=fopen("id.txt", "r");
					int count=1;
					int see=0;
					int line=1;
					char str1[1000];
					while(fgets(str1, 1000, ptr1)!=NULL){
						int num=atoi(str1);
						if (id==num){
							see=1;
							break;
						}
						line++;
					}
					if(see){
						while(fgets(str1,1000,ptr)!=NULL){
							if(count>=(10*(line-1)+1) && count<=(10*(line-1)+10)){
								printf("%s\n",str1);
							}
							if(count>(10*(line-1)+10)){
								break;
							}
							count++;
						}

					}
					else{
						printf("No  booking found with the given ID\n");
					}
				fclose(ptr);
				fclose(ptr1);
				j=1;
			}
			else {
				printf("Exited successfully");
				j=0;
			}
		    
        	}
        }

	else{
		printf("Invalid Input\n");
	}

    return 0;
}

