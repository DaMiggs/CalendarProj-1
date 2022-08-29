#include"calendar.h"
/* This file contains count function and 
some relevant functions
*/

int getMonth(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' || token[1] < '0' || token[1]> '9')
		return 0;//error in retrieving the month
	n = 10 * (token[0] - '0') + token[1] - '0';
	if (n > 12)
		return 0;//error, month should be from 1 and 12...
	return n;
}

int getDay(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' || token[1] < '0' || token[1]> '9')
		return 0;//error in retrieving the day
	n = 10 * (token[0] - '0') + token[1] - '0';
	if (n > 31)
		return 0;//error, month should be from 1 and 12...
	return n;
}

int getYear(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' ||
		token[1] < '0' || token[1]> '9' ||
		token[2] < '0' || token[2]> '9' ||
		token[3] < '0' || token[3]> '9')
		return 0;//error in retrieving the year
	n = 1000 * (token[0] - '0') + 100 * (token[1] - '0') + 10 * 
	(token[2] - '0') + token[3] - '0';
	return n;
}
int count(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {    
	int day_diff, mon_diff, year_diff;    
	if(!isValidDate(fromMonth, fromDay, fromYear)){        
		printf("First date is invalid.\n");            
		}    
	if(!isValidDate(toMonth, toDay, toYear)){        
		printf("Second date is invalid.\n");        
		exit(0);
		}
	if(toDay < fromDay){              
		if (toMonth == 3){            
			if (isLeapYear(toYear)==1){                
				toDay += 29;            
				}            
			else{                
				toDay += 28;            
				}
			}
		else if (toMonth == 5 || toMonth == 7 || toMonth == 10 || toMonth == 12){           
			toDay += 30;         
			} else {           
			toDay += 31;        
			}
		toMonth = toMonth - 1;    
		}
	if (toMonth < fromMonth){        
		toMonth += 12;        
		toYear -= 1;    
		}           
	day_diff = toDay - fromDay;    
	mon_diff = toMonth - fromMonth;    
	year_diff = toYear - fromYear;    

	int daysIM[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(isLeapYear(fromYear)) daysIM[1] = 29;

	int days;
	days += (fromDay + toDay);
	
	for(int i = 0; i < fromMonth-1; i++) days += daysIM[i];

	if(isLeapYear(toYear)) daysIM[1] = 29;
	for(int i = 0; i < toMonth; i++) days += daysIM[i];
	
	printf("Number of days: %d\n", days);

	printf("Total Difference Between The Two Dates Of:  %d/%d/%d and %d/%d/%d there are %d years %02d months and %02d days.\n\n", 
	fromMonth, fromDay, fromYear, toMonth, toDay, toYear, year_diff, mon_diff, day_diff);
	//printf("%d day(s) between the two dates.\n", days);
	return 0;
	}


void handleCount(void) {
	
	char theCount[MAX_COMMAND_TOKEN_LENGTH]; 
	getDate(theCount, MAX_COMMAND_TOKEN_LENGTH);
	//printf("%c\n", theCount);
	int fmn = getMonth(theCount);
	int fdy = getDay(theCount+3);
	int fyr = getYear(theCount+6);
	//printf("%2d%2d%2d\n", fmn, fdy, fyr);
	getDate(theCount, MAX_COMMAND_TOKEN_LENGTH);
	int tmn = getMonth(theCount);
	int tdy = getDay(theCount+3);
	int tyr = getYear(theCount+6);
	//printf("%2d%2d%2d\n", tmn, tdy, tyr);	
	count(fmn,fdy,fyr,tmn,tdy,tyr);
	}

int monthDays(int month, int year) {
	switch (month) {
	case 1:
	case 3: 
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	return -1;
}
int isValidDate(int month, int day, int year) {
	return year >= 1 && month >= 1 && month <=12 && day >= 1 && day <= monthDays(month, year);
}
int compareTo(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {
	//returns negative int if from date < to date
	//return zero if from date == to date
	//returns positive int otherwise
	if (fromYear != toYear)
		return fromYear - toYear;
	if (fromMonth != toMonth)
		return fromMonth - toMonth;
	return fromDay - toDay;
}
int isLeapYear(int year) //97 leap years in every 400 years... 365 days + 97/400
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);//2000, 2020, 1600, 2024, 2016,... are leap years...
	//1900, 1800, 1700, 2100, 2002, 2019,... are not leap years...
}