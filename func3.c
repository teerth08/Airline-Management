#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"


int check_date(int date, int month){
    if (month<1 || month>12 || date>31){
        return 0;
    }
    if (month < 8 && month%2==1){
        if (date>31){
            return 0;
        }
    }
    if (month > 8 && month%2==0){
        if (date>31){
            return 0;
        }
    }
    if (month==2 && date>29){
    	return 0;
    }
    return 1;
}
char *strremove(char *str, const char *sub) {
    char *p, *q, *r;
    if (*sub && (q = r = strstr(str, sub)) != NULL) {
        size_t len = strlen(sub);
        while ((r = strstr(p = r + len, sub)) != NULL) {
            while (p < r)
                *q++ = *p++;
        }
        while ((*q++ = *p++) != '\0')
            continue;
    }
    return str;
}
int check_file_empty(FILE *fp){
	if (NULL!=fp) {
		int size;
    		fseek (fp, 0, SEEK_END);
    		size = ftell(fp);
    		if (0==size) {
        		return 1;
    		}
    		return 0;
	}
}
int delete_line(char *filename, int line_to_delete) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }
    FILE *tmp = fopen("tempfile", "w");
    if (!tmp) {
        fclose(fp);
        return -1;
    }
    char buf[1024];
    int line_num = 1;
    while (fgets(buf, sizeof(buf), fp)) {
        if (line_num != line_to_delete) {
            fputs(buf, tmp);
        }
        line_num++;
    }
    fclose(fp);
    fclose(tmp);
    if (remove(filename) != 0) {
        return -1; 
    }
    if (rename("tempfile", filename) != 0) {
        return -1;
    }
    return 0;
}
int comp_str(char str1[], char str2[]){
	int i=0;
	while(str1[i] == str2[i] && str1[i] == '\0')
	  	i++; 
  		if(str1[i] < str2[i]){
   			return 0;
		}
		else if(str1[i] > str2[i]){
   			return 0;
		}
		else{
   			return 1;
		}
}
int add_line(char filename[20], int line, char newline[20]){
	FILE *fp = fopen(filename, "r");
    	if (!fp) {
        	return -1;
    	}
    	FILE *tmp = fopen("tempfile", "w");
	if (!tmp) {
		fclose(fp);
		return -1;
	}
    	char buf[1024];
    	int line_num = 1;
    	bool go_on=true;
    	int check=0;
    	do{
    		fgets(buf, 1024, fp);
    		if(feof(fp)){
    			go_on=false;
    		}
    		else if(line_num==line){
    			fputs(newline, tmp);
    			fputs("\n", tmp);
    			fputs(buf, tmp);
    			check=1;
    		}
    		else{
    			fputs(buf, tmp);
    		}
    		line_num++;
    	}while(go_on);
    	fclose(fp);
    	fclose(tmp);
    	if (check==0){
    		return -1;
    	}
    	if (remove(filename) != 0) {
        	return -1; 
    	}
	if (rename("tempfile", filename) != 0) {
		return -1;
	}
	
    	return 1;
    	
}
int seat_checker(char seat_type[10], int line_num){
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
    if(seat_total > 0){
        if(comp_str(seat_type,"Economy")){
            if(eco_seat>0){
            	char name[20]="seat_eco.txt";
		ptr=fopen("seat_eco.txt", "a+");
                delete_line(name, line);
                rewind(ptr);
                fclose(ptr);                
                eco_seat = eco_seat-1;
                char new[20];
                sprintf(new, "%d", eco_seat);
		int result=add_line(name, line, new);
		if (result==-1){
			ptr=fopen("seat_eco.txt", "a+");
    			fprintf(ptr, "%d", eco_seat);
    			fclose(ptr);
		}
                return 1;
            }
            else {
                printf("Sorry there is no Economy seat left\n");
                return -1;
            }
        }
        else if(comp_str(seat_type,"Business")){
            if(buss_seat>0){
            	char name[20]="seat_bus.txt";
            	ptr=fopen("seat_bus.txt", "a+");
		fgets(str, 50, ptr);
                delete_line(name, line);
                rewind(ptr);
                fclose(ptr);
                buss_seat = buss_seat-1;
                //add
                char new[20];
                sprintf(new, "%d\n", buss_seat);
                int result=add_line(name, line, new);
                if (result==-1){
			ptr=fopen("seat_bus.txt", "a+");
    			fprintf(ptr, "%d\n", buss_seat);
    			fclose(ptr);
		}
                return 1;
            }
            else {
                printf("Sorry there is no Business class seat left\n");
                return -1;
            }
        }
    }
    else if(seat_total <= 0) {
        printf("Sorry but this flight is full\n");
        return -1;
    }
	return 1;
}
