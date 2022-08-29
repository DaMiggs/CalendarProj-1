#include "calendar.h"

void print(int MM, int YYYY) {

	int daysIM[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(isLeapYear(YYYY)) daysIM[1] = 29;

	int day1 = beginWeek(YYYY, MM);
	int mDays = daysIM[MM-1];
	printf("Su Mo Tu We Th Fr Sa\n");
	//first we will print the required blank spaces
	//until the first day of the month
	for(int i = 0; i < (day1) % 7; i++) printf("   ");
	
	for(int i = 1; i <= mDays; i++) {
		printf("%2d ", i);
		//if you reach sunday, go to next line
		if(day1 == 6) printf("\n");
		day1 = (day1 + 1) % 7;
	}
   printf("\n");
}
int beginWeek(int year, int mon){
	int n=7;
	int rem;
	for (int i = 1; i<=year; i++) {
		//if (n%7==0) n=0;
		if (isLeapYear(i)) {
			n+=2;
			//printf("yes %d\n", n);
		}
		else{
			n++;
		}
			
		}
		rem = n%7;
		
	if (!isLeapYear(year)) {
		switch (mon) {
			case 1:
			case 10:
				return rem;
			case 2:
			case 3:
			case 11:
				return rem+3;
			case 4:
			case 7:
				return rem-1;
			case 5:
				return rem+1;
			case 6:
				return rem-3;
			case 8:
				return rem+2;
			case 9:
			case 12:
				return rem-2;
		} 
	} else {
		n=2;
		rem=n%7;
		switch (mon) {
			case 1:
			case 4:
			case 7:
				return rem;
			case 2:
			case 8:
				return rem+3;
			case 3:
			case 11:
				return rem+4;
			case 5:
				return rem+2;
			case 6:
				return rem-2;
			case 9:
			case 12:
				return rem-1;
			case 10:
				return rem+1;
		}
	}
		
		return rem;
	}




void handlePrint(void) {
	char date[MAX_COMMAND_TOKEN_LENGTH];
	getDate(date, MAX_COMMAND_TOKEN_LENGTH);
	//printf("this: %d\n", getYear(date+3));
	int yr = getYear(date+3);
	int mn = getMonth(date);
    //printf("printing the weeks of month %s\n", MAX);
	print(mn, yr);
	
    //the variable days will be used for finding out that day
    //on which that months starts
    int days = 0;
    //atoi() function converts strings to integers
    //we have taken '% 400' because after every 400 year
    //the 1st january is monday

    for(int i = 1; i < getYear(date+3); i++)
    {
       //adding 365 days for every year
       days+=365;
       //adding extra day if it is a leap year
       if(isLeapYear(i))
       {
           days++;
       }
    }


}
