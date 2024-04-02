#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"


int seat_increase(char seat_type[10], int line_num){
    FILE *ptr = NULL;
    FILE *ptr1 = NULL;
    int eco_seat,buss_seat;
    ptr = fopen("seat_eco.txt","r");
    ptr1 = fopen("seat_bus.txt","r");
    char str[50];
    int n, count, line=1;
    fgets(str, 50, ptr);
    while (!feof(ptr)){
                        n=atoi(str);
                        if (line==line_num){
                        	eco_seat=n;
                                break;
                        }
                        line++;
                        fgets(str, 50, ptr);
    }
    line=1;
    fgets(str, 50, ptr1);
    while (!feof(ptr1)){
                        n=atoi(str);
                        if (line==line_num){
                        	buss_seat=n;
                                break;
                        }
                        line++;
                        fgets(str, 50, ptr1);
    }
    int seat_total = eco_seat+buss_seat;
    fclose(ptr);
    fclose(ptr1);
        if(comp_str(seat_type,"Economy")){
            	char name[20]="seat_eco.txt";
		ptr=fopen("seat_eco.txt", "a+");
                delete_line(name, line_num);
                rewind(ptr);
                fclose(ptr);                
                eco_seat = eco_seat+1;
                char *new;
                new=int_to_string(eco_seat);
		int result=add_line(name, line_num, new);
		if (result==-1){
			ptr=fopen("seat_eco.txt", "a+");
    			fprintf(ptr, "%d\n", eco_seat);
    			fclose(ptr);
		}
                return 1;
        }
        else if(comp_str(seat_type,"Business")){
            	char name[20]="seat_bus.txt";
            	ptr=fopen("seat_bus.txt", "a+");
                delete_line(name, line_num);
                rewind(ptr);
                fclose(ptr);
                buss_seat = buss_seat+1;
                char *new=int_to_string(buss_seat);
                int result=add_line(name, line_num, new);
                if (result==-1){
			ptr=fopen("seat_bus.txt", "a+");
    			fprintf(ptr, "%d\n", buss_seat);
    			fclose(ptr);
		}
                return 1;
        }

	return 1;
}
int pricing(int dep_month, int dep_date, int curr_month, int curr_date, int base_price, char flight[]){
	int diff_date;
	int diff_month;
	int price;
	if(dep_month==curr_month){
		if(curr_date>dep_date){
			return 0;
		}
		else{
			diff_date=dep_date-curr_date;
			if(diff_date>=7 && diff_date<15){
				if(comp_str(flight, "Economy")){
					price=base_price+800;
					return (price);
				}
				else if(comp_str(flight, "Business")){
					price=base_price+1500;
					return (price);
				}
			}
			else if(diff_date<7){
				 if(comp_str(flight, "Economy")){
					price=base_price+800+(200*(7-diff_date));
					return (price);
				}
				else if(comp_str(flight, "Business")){
					price=base_price+1500+(400*(7-diff_date));
					return (price);
				}
			}
			else if(diff_date>=15 && diff_date<=30){
				if(comp_str(flight, "Economy")){
					price=base_price+400;
					return (price);
				}
				 else if(comp_str(flight, "Business")){
					price=base_price+800;
					return (price);
				}
			}
		}
	}	
	else if(dep_month>curr_month){
		diff_month=dep_month-curr_month;
		diff_date=dep_date+(diff_month*(30-curr_date));
		if(strcmp(flight, "Economy")){
			if(diff_date>=15 && diff_date<=30){
				price=base_price+400;
				return (price);
			}
			else if(diff_month>=1 && diff_date>30){
				price=base_price;
				return (price);
			}
			else if(diff_date>=7 && diff_date<15){
				price=base_price+800;
				return (price);
			}
			else if(diff_date<7){
				price=base_price+800+(200*(7-diff_date));
				return (price);
			}
		}
		else if(strcmp(flight, "Buisness")){
                        if(diff_date>=15 && diff_date<=30){
                                price=base_price+800;
                                return (price);
                        }
                        else if(diff_month>=1 && diff_date>30){
                                price=base_price;
                                return (price);
                        }
                        else if(diff_date>=7 && diff_date<15){
                                price=base_price+1500;
                                return (price);
                        }
                        else if(diff_date<7){   
                                price=base_price+1500+(400*(7-diff_date));
                                return (price);
                        }
		}
	}
}


int line_link(char name[], int date, int month, FILE *des, FILE *dates, FILE *months){
		int line=1;
                int line_num1, line_num2;
                int check=0;
                char str1[50], str2[50], str3[50];
		while (fgets(str1, 50, des) != NULL) {
			if (comp_str(str1, name)){
				line_num1=1;
				while (fgets(str2, sizeof(str2), dates)) {
					int num=atoi(str2);
        				if (line_num1 == line && num==date){
        					line_num2=1;
            					while (fgets(str3, sizeof(str3), months)) {
							int num_new=atoi(str3);
        						if (line_num2 == line && num_new==month){
            							return line;
     							}
     							if(line_num2>line){
     								rewind(months);
     								break;
     							}
        						line_num2++;
    						}
        				}
        				if(line_num1>line){
        					rewind(dates);
        					break;
        				}
        				line_num1++;
    				}
			}
			line++;
	    	}
	    	return -1;
}

