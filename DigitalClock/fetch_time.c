#include<time.h>
char *fetch_time( char *str ,int str_size, int format)
{
    time_t raw_time;
    struct tm *current_time;
    

    time(&raw_time);
    current_time= localtime(&raw_time);
      if (format ==1){
    strftime(str ,str_size,"%I:%M:%S %p",current_time);
      } 
      else{
        strftime(str ,str_size,"%H:%M:%S %p",current_time);
      }
      return str;
      
}