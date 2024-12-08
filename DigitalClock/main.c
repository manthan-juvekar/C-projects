#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>


char *fetch_time( char *str ,int str_size, int format);
char *fetch_date(char *str ,int str_size);
void clear_screen(void);

int main(){
    int format;
        printf("Please choose the format from below");
        printf("\n 1.for 24 hr format");
        printf("\n 2.for 12 hr format ( default )");
        printf("\n\nenter the option=");
        scanf(" %d", &format);
    if(format <0 || format >2){
        printf("invalid choice , try again");
         } 
    else{


        int size[2]={50,100};
        char op_time_str[size[0]];
        char op_date_str[size[1]];
        while(1){
        clear_screen();
        fetch_date(op_date_str ,size[1]);
        fetch_time(op_time_str ,size[0] ,format);
        printf("%s \n",op_time_str);
        printf("%s \n",op_date_str);
        sleep(1); // 1 sec delay
        }
        }

return 0;
}
void clear_screen(void){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}