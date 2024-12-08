#include<stdio.h>
#include<math.h>
double divide(double , double);
int mod(int,int);
void printmenu();


int main(){
  float num1 , num2 , result= 0 ;
  int choice ;
    while(1){
    printmenu();
    scanf(" %d", &choice);
    if (choice ==7)
    break;

    if (choice < 1 || choice >7){
    printf("Invalid , please enter choice from the menu");
    }
    else{

        printf("\nplease enter the first number=");
        scanf(" %f",&num1 );

        printf("\nplease enter the second number=");
        scanf(" %f",&num2 );

        switch(choice){
          case 1:
          result =num1+num2;       //addition
        break;
          case 2: 
          result =num1-num2;       //substact
        break;
          case 3: 
           result =num1*num2;     //multiply
        break;
          case 4:result = divide(num1 ,num2); //divide
        break;
          case 5:
          result= mod((int)num1 ,(int)num2);  //modulus
        break;
          case 6:
           result= pow(num1 , num2); //power
        break;
        }
         if ( !isnan(result))
   printf(" the result of the operation is %.2f" , result);
   }
    }
   
   
   return 0;
}


double divide( double a , double b)
{
    if (a == 0 || b == 0){
        fprintf(stderr , "\n\n Error :Invalid Argument for devision");
        return NAN;
    }
    else{
    return a/b;
    }
}

int mod(int a ,int b){
     if (a == 0 || b == 0){
        fprintf(stderr , "\n\nError :Invalid Argument for modulus");
        return -1;       // to indicate error
    }
    else{
    return a%b;
    }

}
