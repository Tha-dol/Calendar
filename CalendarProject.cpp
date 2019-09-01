#include <stdio.h> 
#include <conio.h> 
#include <windows.h> 
 
char dAY[][10]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	 
char monTH[][10]={"ERROR","JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
	
int leapcheck(int year); //////////////////////////////////// By ****: Line 90 to 101
	
int nodayear(int year); ////////////////////////////////// By *****: line 103 to 108

int nodamonth(int month, int year); //////////////////// By *****: line 110 to 121

int week(int day, int month, int year); ////////////// By *****: line 123 to 134

void calen(int day, int month, int year); ////////// By *****: line 136 to 154

void printonfile(int day, int month, int year); // Extra Feature: not discussed in the presentation(the latest update): line 156 to END

//******************************************************************************************************************** MAIN
int main(){	                                                                                                      /*MAIN*/
	int day,month,year;                                                                                           /*MAIN*/
	int i=0, j=0;                                                                                                 /*MAIN*/
	                                                                                                              /*MAIN*/
	printf("Enter the year:");                                                                                    /*MAIN*/
	scanf("%d",&year);                                                                                            /*MAIN*/
	                                                                                                              /*MAIN*/
	printf("Enter the month:");                                                                                   /*MAIN*/
	scanf("%d",&month);                                                                                           /*MAIN*/
	                                                                                                              /*MAIN*/
	printf("Enter the day:");                                                                                     /*MAIN*/
	scanf("%d",&day);                                                                                             /*MAIN*/
	                                                                                                              /*MAIN*/
	D://**************************************************** ALSO JUMPS HERE FROM LAST(line 85)                   /*MAIN*/
                                                                                                                      /*MAIN*/
     if(day<1){                                        //Variable Correction                                          /*MAIN*/
         day=nodamonth(month-1,year); month--;         //Variable Correction                                          /*MAIN*/
      }                                                //Variable Correction                                          /*MAIN*/
     if(day>nodamonth(month, year)){                   //Variable Correction                                          /*MAIN*/
	  	j=(int)day/nodamonth(month, year);     //Variable Correction                                          /*MAIN*/
	  	day-=nodamonth(month, year);           //Variable Correction                                          /*MAIN*/
	  	month+=(int)j;                         //Variable Correction                                          /*MAIN*/
      }		                                       //Variable Correction                                          /*MAIN*/
     if(month>12){                                     //Variable Correction                                          /*MAIN*/
		j=month/12; month-=12;                 //Variable Correction                                          /*MAIN*/
		year+=(int)j;                          //Variable Correction                                          /*MAIN*/
	   }                                           //Variable Correction                                          /*MAIN*/
     if(month==0){                                     //Variable Correction                                          /*MAIN*/
		year--; month=12;                      //Variable Correction                                          /*MAIN*/
	   }                                           //Variable Correction                                          /*MAIN*/
                                                                                                                      /*MAIN*/
	system("cls");                                                                                         	      /*MAIN*/
	                                                                                                              /*MAIN*/
   printf("------------%s, %s %d, %d-------------", dAY[week(day,month,year)], monTH[month], day, year);              /*MAIN*/
	                                                                                                              /*MAIN*/
	calen(day, month, year); //defined in line 133                                                                /*MAIN*/
	                                                                                                              /*MAIN*/
	printf("__ _ _ _ _ _ _ _ _ _ _ |Press| _ _ _ _ _ _ _ _ _ _ __\n");                                            /*MAIN*/
	printf("|| P: for previous| _ _ _ _ __ _ _ _ _ |N: for next||\n");                                            /*MAIN*/
	printf("____________ |Press |S| to Save on file| ____________\n");                                            /*MAIN*/
	printf("_______________ |Press enter to Quit| _______________");                                              /*MAIN*/
	                                                                                                              /*MAIN*/
	j=toupper(getch());                                                                                           /*MAIN*/
	if(j==0xE0){                                                                                                  /*MAIN*/
		switch(getch()){                                                                                      /*MAIN*/
			case 72: day-=7; break;                                                                       /*MAIN*/
         case 80: day+=7; break;                                                                                      /*MAIN*/
         case 75: day--; break;                                                                                       /*MAIN*/
         case 77: day++; break;                                                                                       /*MAIN*/
		}                                                                                                     /*MAIN*/
	}                                                                                                             /*MAIN*/
	else if(j=='P') month--;                                                                                      /*MAIN*/
   else if(j=='N') month++;                                                                                           /*MAIN*/
   else if(j=='S'){                                                                                                   /*MAIN*/
   	printonfile(day, month, year);  //Defined on line  153                                                        /*MAIN*/
   	system("cls");                                                                                                /*MAIN*/
   	printf("The calendar is saved with file name: \"Calendar.txt\"");                                             /*MAIN*/                                                 /*MAIN*/                                                                             /*MAIN*/
   	getch();                                                                                                      /*MAIN*/
	}                                                                                                             /*MAIN*/
   else return 0;                                                                                                     /*MAIN*/
	goto D; // Will go to Variable Corrections (line 38)                                                          /*MAIN*/
                                                                                                                      /*MAIN*/
}                                                                                                                     /*MAIN*/
//********************************************************************************************************* END OF MAIN

int leapcheck(int year){ 
	int i=year%4, j=year%100, k=year%400;
	
	if(i==0){
		if(j==0){
			if(k==0) return 1;
			else return 0;
		}
		else return 1;
	}
	else return 0;
}

int nodayear(int year){ 
	int k;
	k=leapcheck(year);
	if(k==0) return 365;
	else return 366;	
}

int nodamonth(int month, int year){  
   int i;
   i=leapcheck(year);
   if (month==1 || month==3 || month==5 || month==7
	     || month==8 || month==10 || month==12)
	 return 31;
	if (month==2){
		if(i==0) return 28;
		else return 29;
	}
	else return 30;
}

int week(int day, int month, int year){
	int total=0;
	int checker;
	int i;
	
	for(i=1;i<=(year-1);i++) total+=nodayear(i);
	for(i=1;i<=(month-1);i++) total+=nodamonth(i,year);
	
	total+=day;
	checker=total%7;
	return checker;
}

void calen(int day, int month, int year){ //used in line 57
	int c=1, m=1, i,j;
	int b=week(1,month,year);
	int k=nodamonth(month,year);
	printf("\n\nSun\tMon\tTue\tWed\tThr\tFri\tSat\n\n");
	
	for(i=1;i<=b;i++){
		printf(" - \t"); c++;
	}
	for(i=0;i<=45;i+=7){
		for(j=c;j<=7;j++){
			if(m<=k){
				if(m==day) printf("[%d]\t",m++);  
			   else printf(" %d \t",m++);
		   }
		}		
		printf("\n"); c=1;
	}
}                                           

void printonfile(int day, int month, int year){  //Used on line 76
	
	int c=1, m=1, i,j;
	FILE *fp;
	fp=fopen("calendar.txt","w");
	int b=week(1,month,year);
	int k=nodamonth(month,year);
	fprintf(fp,"------------%s, %s %d, %d-------------", 
	       dAY[week(day,month,year)], monTH[month], day, year);
	
	fprintf(fp,"\n\nSun\tMon\tTue\tWed\tThr\tFri\tSat\n\n");
	
	for(i=1;i<=b;i++){
		fprintf(fp," - \t"); c++;
	}
	for(i=0;i<=45;i+=7){
		for(j=c;j<=7;j++){
			if(m<=k){
				if(m==day) fprintf(fp,"[%d]\t",m++);  
			   else fprintf(fp," %d \t",m++);
		   }
		}		
		fprintf(fp,"\n"); c=1;
	}
	fclose(fp);
}                                           

