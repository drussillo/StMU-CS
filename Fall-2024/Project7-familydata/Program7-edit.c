/* C Program by Dave Russillo. Made for CS1310. 
 * Reads and writes personal data of family members using separate files.
 *           _                      _
 *          | |                    | |
 *         / /                     \ \
 *        /  \____             ____/  \
 *   ____/   (|____)          (____|)  \____
 *  |   |   (|_____)          (_____|) |    |
 *  |   |    (|____)          (____|)  |    |
 *  |___|_____(|___)          (___|)___|____|
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char current_date[10] = "11-17-2024";  /* current date for age calculation */
struct family {
  char name[50];  /* person's name */
  char street[50];  /* street address */
  char csz[50];  /* city, state, zip */
  char relation[50];  /* relation to you */
  char birthday[11];  /* mm-dd-yyyy */
};
struct family people[7];



void fprint_age(FILE *out, char *birthday) {
  int bday_month = atoi(birthday);  /* birthday month as an integer */
  int bday_day = atoi(birthday+3); /* birthday day as an integer */
  int bday_year = atoi(birthday+6); /* birthday year as an integer */
  int current_month = atoi(current_date); /* current month as an integer */
  int current_day = atoi(current_date+3); /* current day as an integer */
  int current_year = atoi(current_date+6); /* current year as an integer */

  /* 
   * if month is less than birth month -> current year - birth year - 1
   * else if month is more than birth month -> current year - birth year
   * else if day is less than birth day -> current year - birth year - 1
   * else current year - birth year 
   */ 
  
  if(current_month < bday_month) {
    fprintf(out, "%d", current_year - bday_year - 1);  /* birthday not yet reached this year */
  } else if(current_month > bday_month) {
    fprintf(out, "%d", current_year - bday_year);  /* birthday already reached this year */
  } else if(current_day < bday_day) {
    fprintf(out, "%d", current_year - bday_year - 1);  /* birthday not yet reached this year */
  } else {
    fprintf(out, "%d", current_year - bday_year);  /* birthday today or earlier this month */
  }
}



void fprint_fulldate(FILE *out, char *date) {  
  int month = atoi(date);  /* month as an integer */
  int day = atoi(date+3);  /* day as an integer */
  int year = atoi(date+6);  /* year as an integer */

  switch(month) {  /* print month as a word based on the number */
    case 1:
      fprintf(out, "January ");
      break;
    case 2:
      fprintf(out, "February ");
      break;
    case 3:
      fprintf(out, "March ");
      break;
    case 4:
      fprintf(out, "April ");
      break;
    case 5:
      fprintf(out, "May ");
      break;
    case 6:
      fprintf(out, "June ");
      break;
    case 7:
      fprintf(out, "July ");
      break;
    case 8:
      fprintf(out, "August ");
      break;
    case 9:
      fprintf(out, "September ");
      break;
    case 10:
      fprintf(out, "October ");
      break;
    case 11:
      fprintf(out, "November ");
      break;
    case 12:
      fprintf(out, "December ");
      break;
    default:
      fprintf(out, "ERROR: INVALID MONTH VALUE ");
      break;
  }
  fprintf(out, "%d, %d", day, year);  /* print rest of date */
}



void read_data(FILE *inputfile) {  /* reads lines from inputfile and puts them in people array */
  char line[50];  /* next line in file */
  int person;  /* index of current person (every five lines) */
  for(person = 0; person < 7; person++) {  /* for each person in the file */
    fgets(line, 50, inputfile);  /* save current line to line */
    line[strlen(line)-1] = '\0';  /* remove newline character at the end of line */
    strcpy(people[person].name, line);  /* save line to current person attribute in people array */
    fgets(line, 50, inputfile); /* same thing for every attribute until end of function */
    line[strlen(line)-1] = '\0';
    strcpy(people[person].street, line);
    fgets(line, 50, inputfile);
    line[strlen(line)-1] = '\0';
    strcpy(people[person].csz, line);
    fgets(line, 50, inputfile);
    line[strlen(line)-1] = '\0';
    strcpy(people[person].relation, line);
    fgets(line, 50, inputfile);
    line[strlen(line)-1] = '\0';
    strcpy(people[person].birthday, line);
  }
}



void write_data(FILE *outputfile) {  /* writes data from people array to given output file */
  int person;
  for(person = 0; person < 7; person++) {  /* for each person */
    /* print all information to stdout and output file (required format) */
    fprintf(stdout, "%-35s Relation: %s \n", people[person].name, people[person].relation);
    fprintf(outputfile, "%-35s Relation: %s \n", people[person].name, people[person].relation);
    fprintf(stdout,"%-35s Birthday: ", people[person].street);
    fprintf(outputfile, "%-35s Birthday: ", people[person].street);
    fprint_fulldate(stdout, people[person].birthday);
    fprint_fulldate(outputfile, people[person].birthday);
    fprintf(stdout, " \n");
    fprintf(outputfile, " \n");
    fprintf(stdout, "%-35s Age: ", people[person].csz);
    fprintf(outputfile, "%-35s Age: ", people[person].csz);
    fprint_age(stdout, people[person].birthday);
    fprint_age(outputfile, people[person].birthday);
    fprintf(stdout, "\n\n");
    fprintf(outputfile, "\n\n");
  }
}



int main(void) {
  /* open input and output files and save them to infil and outfile variables */
  FILE *infile = fopen("familyin.txt", "r");
  FILE *outfile = fopen("familyout.txt", "w");

  read_data(infile);
  write_data(outfile);

  /* close input and output files */
  fclose(infile);
  fclose(outfile);

  return 0;
}


