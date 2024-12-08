#include<time.h>
char *fetch_date(char *str ,int str_size)
{
    time_t raw_time;
    struct tm *current_time;
    

    time(&raw_time);
    current_time= localtime(&raw_time);
     
    strftime(str ,str_size,"%A,%B ,%d ,%Y",current_time);
     return str;
      
}