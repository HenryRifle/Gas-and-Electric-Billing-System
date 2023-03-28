
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ARRAYSIZE 12

//Programmer:Henry/Muhammad/Kareem
//Date:10/26/2022
//File:final.c
//Program Description:Gas and Electric Billing System

int main_1(void)
{
    char bill_system;
    FILE *out_file=fopen("billings.txt","a");


    while(bill_system!='l'&& bill_system!='L'){
    puts("");
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\nInput: ","Which Billing System would you like to use?","-E for Electricity Billing System",
           "-G for Gas Billing System","-B for Both Billing Systems","-R for Reading OutputFile","-F for Frequently Asked Questions","-L to leave System");
    scanf(" %c",&bill_system);
    switch(bill_system){
    case 'E':
    case 'e':
       elect_bill();                                  // switch function to determine what function is being used
        break;
    case 'G':
    case 'g':
        gas_bill();
        break;
    case 'B':
    case 'b':
        float total=elect_bill()+gas_bill();
        char total_bill_ans;
        printf("\n%s\n%s\n%s\nInput:","Would you like to print your Total Bill to a separate file?","-type y for yes","-type n for no");
        scanf(" %c",&total_bill_ans);
        if(total_bill_ans =='y'){
        fprintf(out_file ,"Total Bill for this month is $%f\n", total);
        printf("...Printed to file\n");
        }
        printf("\nTotal Bill for this month is $%.2f\n",total);                       // calculates the total when both systems are chosen
        break;
    case 'R"':
    case 'r':
        read_files();
        break;
    case 'l':
    case 'L':
        int clear_answer;
        printf("%s\n%s\n%s\nInput:","Would you like to clear your file?","-type y for yes","-type n for no");
        scanf(" %c",&clear_answer);
        if (clear_answer=='y'){
        clear_file();                  // clears the file for the nest user
        }
        break;
    case 'F':
    case 'f':
        FAQ();
        break;
    default:
        printf("Incorrect input try again\n");
        break;

    }

    }
printf("Thank you for running the Billing Program\n");
fclose(out_file);
}


int elect_bill_2(){
FILE *out_file=fopen("billings.txt","a");
float elect;
int elect_hours;
float kilo_watt;        //initilizes variables
float elect_bill;
float kwh;
float elect_tariff;
char out_answer;
char info_answer;
float elect_bills[ARRAYSIZE]={0,0,0,0,0,0,0,0,0,0,0,0};
char exit='n';

while (exit!='y'){
puts("");
printf("Electricity Billing System\n");
printf("%s\n%s\nInput:","Would you like to leave the electricity billing system?","-type y for yes");
scanf(" %s",&exit);
printf("%s\n%s\nInput:","Would you like to print your electric billing information to a separate file?","-type y for yes");
scanf(" %c",&out_answer);
printf("Please Enter Your Electricity usage in Watts:");
scanf("%f",&elect);
printf("Please Enter the amount of Electricity usage in hours:");
scanf("%d",&elect_hours);
kilo_watt=elect/1000;                                                 //gathers all the needed information from user and calculates bill
kwh=kilo_watt*elect_hours;
printf("Please Enter your Tariff rate per KiloWatt Hour(average is $0.12):");
scanf(" %f",&elect_tariff);
elect_bill=kwh*elect_tariff;
printf("%s\n%s\nInput:","Would you like your data in table format?","-type y for yes");
scanf(" %c",&info_answer);





if (out_answer=='y'){
        if (info_answer=='y'){
                printf("Your cost of electricity is $%.2f\n",elect_bill);
                printf("Billing info printed to billings.txt\n");
                fprintf(out_file,"Electricity Billing Information\n");
                fprintf(out_file,"%s %13s %18s \n","KiloWattsHour","Electricity Tariff","Electricity Bill");
                fprintf(out_file,"%.1f %14.2f %21.1f \n",kwh,elect_tariff,elect_bill);
        }else{
            printf("Your cost of electricity is $%.2f\n",elect_bill);
            printf("Billing info printed to billings.txt\n");
            fprintf(out_file,"Electricity Billing Information\n");
            fprintf(out_file,"Watts: %.2f\n",elect);
            fprintf(out_file,"KiloWatts: %.2f\n",kilo_watt);                                 //prints out information according to user choice
            fprintf(out_file,"Hours Used: %d\n",elect_hours);
            fprintf(out_file,"KiloWattsHour: %.2f\n",kwh);
            fprintf(out_file,"Electricity Tariff: %.2f\n",elect_tariff);
            fprintf(out_file,"Electricity Bill: %.2f\n\n",elect_bill);
}}else{
    if(info_answer=='y'){
            printf("%s %13s %18s \n","KiloWattsHour","Electricity Tariff","Electricity Bill");
            printf("%.1f %14.2f %21.1f \n",kwh,elect_tariff,elect_bill);
    }else{
        puts("");
        printf("Watts: %.2f\n",elect);
        printf("KiloWatts: %.2f\n",kilo_watt);
        printf("Hours Used: %d\n",elect_hours);
        printf("KiloWattsHour: %.2f\n",kwh);
        printf("Electricity Tariff: %.2f\n",elect_tariff);
        printf("Electricity Bill: $%.2f\n",elect_bill);
        puts("");
    }
}

for(int i=0;i<ARRAYSIZE-1;i++){
        if(elect_bills[i]==0){
            elect_bills[i]=elect_bill;           //if elect_bills array index i equals 0 it replaces it with the elect_bill value
            break;
        }



}}

float sum=0;
float hold;

for (int i=0;i<ARRAYSIZE-1;i++){
        for (int j=0;j<ARRAYSIZE-i-1;j++){
        if (elect_bills[j]>elect_bills[j+1]){
                    hold = elect_bills[j];                            //bubble sort for the elect_bills array ,sorting from lowest to highest
                    elect_bills[j] = elect_bills[j+1];
                    elect_bills[j+1] = hold;
                }

}}
printf("%s\n%s\nInput:","Would you like to print your sorted bills to a separate file?","y for yes");
char sorted_ans;                                                         //prompting the user for input
scanf(" %c",&sorted_ans);
puts("");
printf("All of you Electricity Bills sorted from lowest to highest is :\n");
if (sorted_ans=='y'){
fprintf(out_file,"\nElectric Billing System Sorted\n");
}
for(int i=0;i<ARRAYSIZE;i++){
        if (elect_bills[i]!= 0){
        printf("Your Electricity Bill is $%.2f\n",elect_bills[i]);
        if(sorted_ans=='y'){
        fprintf(out_file,"Your Electricity Bill is $%.2f\n\n",elect_bills[i]);           //printing out all the gas bills sorted,printing to file also
        }
        }
        sum+=elect_bills[i];                                                       //adds up the sum of all the bills in elect_bills
    }
printf("The Sum of all your Electricity Bills : $%.2f\n",sum);
if(sorted_ans=='y'){
fprintf(out_file,"The Sum of all your Electricity Bills : $%.2f\n",sum);
}
fclose(out_file);
return sum;                                                                 //returns the sum of all the bills

}





int gas_bill_2(){
FILE *out_file=fopen("billings.txt","a");
float cubic_feet;
float cubic_meters;
float kw_gas;
int gas_hours;
float total_gas_bill;
char answer;                     //initilizes variables
float gas_tariff;
float kwh_gas;
char out_answer;
char info_answer;
float gas_bills[ARRAYSIZE]={0,0,0,0,0,0,0,0,0,0,0,0};
char exit='n';


while (exit!='y'){
puts("");
printf("Gas Billing System\n");
printf("%s\n%s\nInput:","Would you like to exit the Gas Billing System ?","-type y for yes");
scanf(" %c",&exit);
printf("%s\n%s\nInput:","Would you like to print your gas billing information to a separate file?","-type y for yes");
scanf(" %c",&out_answer);
printf("%s\n%s\nInput:","Is your meter measurement in cubic feet?","-type y for yes");
scanf(" %c",&answer);
switch(answer){
case 'Y':                                                          //switch function allows you to choose between the two ways to calculate your gas bill
case 'y':
    printf("Please Enter your Cubic Feet Measurement:");
    scanf("%f",&cubic_feet);
    cubic_meters=cubic_feet*2.83;
    kw_gas=(cubic_meters*1.02264)/3.6;                   //calculates the total gas bill
    printf("Please Enter Your Hours of Gas Usage:");
    scanf("%d",&gas_hours);                                            //gathers all the needed information from the user
    printf("Please Enter Your Gas Tariff per Kilowatt Hour(average is $0.12):");
    scanf("%f",&gas_tariff);
    kwh_gas=kw_gas*gas_hours;
    total_gas_bill=kwh_gas*gas_tariff;
    printf("%s\n%s\nInput:","Would you want your data in table format?","-type y for yes");
    scanf(" %c",&info_answer);


    if (out_answer=='y'){
            if (info_answer=='y'){
                    printf("Total Gas Bill is $%.2f\n",total_gas_bill);
                    printf("Billing info printed to billings.txt\n");
                    fprintf(out_file,"Gas Billing System\n");                                         //prints information according to users choice
                    fprintf(out_file,"%s %13s %18s \n","KiloWattsHour","Gas Tariff","Gas Bill");
                    fprintf(out_file,"%.1f %15.2f %21.f \n",kwh_gas,gas_tariff,total_gas_bill);

            }else{
                printf("Total Gas Bill is $%.2f\n",total_gas_bill);
                printf("Billing info printed to billings.txt\n");
                fprintf(out_file,"Gas Billing Information\n");
                fprintf(out_file,"Cubic Feet: %.2f\n",cubic_feet);
                fprintf(out_file,"Cubic Meters: %.2f\n",cubic_meters);
                fprintf(out_file,"Kilowatts: %.2f\n",kw_gas);
                fprintf(out_file,"Gas Usage Hours: %d\n",gas_hours);
                fprintf(out_file,"KiloWattsHour: %.2f\n",kwh_gas);
                fprintf(out_file,"Gas Tariff: %.2f\n",gas_tariff);
                fprintf(out_file,"Gas Bill: %.2f\n\n",total_gas_bill);                                 //prints information according to users choice
    }}else{
        if (info_answer=='y'){
                printf("%s %13s %18s \n","KiloWattsHour","Gas Tariff","Gas Bill");
                printf("%.1f %15.2f %21.1f \n",kwh_gas,gas_tariff,total_gas_bill);

        }else{
            puts("");
            printf("Cubic Feet:%.2f\n",cubic_feet);
            printf("Cubic Meters:%.2f\n",cubic_meters);
            printf("Kilowatts:%.2f\n",kw_gas);
            printf("Gas Usage Hours:%d\n",gas_hours);
            printf("KiloWattsHour:%.2f\n",kwh_gas);
            printf("Gas Tariff:%.2f\n",gas_tariff);
            printf("Gas Bill:$%.2f\n",total_gas_bill);
            puts("");
    }
    }
    break;

default:
printf("Please Enter Your Gas usage in Cubic Meters from your meter:");
scanf("%f",&cubic_meters);
kw_gas=(cubic_meters*1.02264)/3.6;
printf("Please Enter Your Hours of Gas Usage:");
scanf("%d",&gas_hours);
kwh_gas=kw_gas*gas_hours;                                            //gathers information for the other way to calculate the gas bill
printf("Please Enter Gas Tariff per Kilowatt Hour(average is $0.12):");
scanf("%f",&gas_tariff);
total_gas_bill=kwh_gas*gas_tariff;
printf("%s\n%s\nInput:","Would you like your data in table format ?","-type y for yes");
scanf(" %c",&info_answer);




if (out_answer=='y'){
        if (info_answer=='y'){
                printf("Total Gas bill is $%.2f\n",total_gas_bill);
                printf("Billing info printed to billings.txt\n");
                fprintf(out_file,"Gas Billing System\n");
                fprintf(out_file,"%s %13s %18s \n","KiloWattsHour","Gas Tariff","Gas Bill");
                fprintf(out_file,"%.1f %15.2f %21.1f \n",kwh_gas,gas_tariff,total_gas_bill);

        }else{
            printf("Total Gas bill is $%.2f\n",total_gas_bill);
            printf("Billing info printed to billings.txt\n");                        //prints out information according to user choice
            fprintf(out_file,"Gas Billing Information\n");
            fprintf(out_file,"Cubic Meters:%.2f\n",cubic_meters);
            fprintf(out_file,"Kilowatts:%.2f\n",kw_gas);
            fprintf(out_file,"Gas Usage Hours:%d\n",gas_hours);
            fprintf(out_file,"KiloWattsHour:%.2f\n",kwh_gas);
            fprintf(out_file,"Gas Tariff:%.2f\n",gas_tariff);
            fprintf(out_file,"Gas Bill:$%.2f\n\n",total_gas_bill);
        }
}
else{
        if (info_answer=='y'){
                printf("%s %13s %18s \n","KiloWattsHour","Gas Tariff","Gas Bill");
                printf("%.1f %15.2f %21.1f \n",kwh_gas,gas_tariff,total_gas_bill);

        }else{
            puts("");
            printf("Cubic Meters:%.2f\n",cubic_meters);
            printf("Kilowatts:%.2f\n",kw_gas);                                     //prints out the information according to user choice
            printf("Gas Usage Hours:%d\n",gas_hours);
            printf("KiloWattsHour:%.2f\n",kwh_gas);
            printf("Gas Tariff:%.2f\n",gas_tariff);
            printf("Gas Bill:$%.2f\n",total_gas_bill);
            puts("");
        }
}
break;



}
for(int i=0;i<ARRAYSIZE-1;i++){
        if(gas_bills[i]==0){
            gas_bills[i]=total_gas_bill;                       //if the array gas_bills index i equals 0 it replaces that value with the total_gas_bill
            break;
        }
    }

}

float sum=0;
float hold=0;
for (int i=0;i<ARRAYSIZE-1;i++){
        for(int j=0;j<ARRAYSIZE-i-1;j++){
        if (gas_bills[j]>gas_bills[j+1]){
                    hold = gas_bills[j];                          //bubble sort ,sorting from lowest to highest in the gas_bills array
                    gas_bills[j] = gas_bills[j+1];
                    gas_bills[j+1] = hold;
                }

}}

printf("%s\n%s\nInput:","Would you like to print your sorted bills to a separate file ?","-type y for yes");
char sorted_ans;
scanf(" %c",&sorted_ans);
puts("");
printf("All of your Gas Bills sorted from lowest to highest:\n");
if(sorted_ans=='y'){
fprintf(out_file,"\nGas Billing System Sorted\n");
}
for(int i=0;i<ARRAYSIZE;i++){
        if (gas_bills[i]!= 0){
        printf("Your Gas Bill is $%.2f\n",gas_bills[i]);           //prints out all the gas bills and prints to file if wanted
        if(sorted_ans=='y'){
            fprintf(out_file,"Your Gas Bill is $%.2f\n\n",gas_bills[i]);
        }
        }
        sum+=gas_bills[i];                                     //adds up sum for each bill in the array
    }
printf("The sum of all your gas bills: $%.2f\n",sum);
if(sorted_ans=='y'){
fprintf(out_file,"The sum of all your gas bills: $%.2f\n",sum);
}
fclose(out_file);
return sum;                                       //returns the sum
}







void read_files_2(void){

FILE *in_file=fopen("billings.txt","r");


if(in_file==NULL){
    printf("Unable to open File\n");
}else{
char line[255];
while(fgets(line,255,in_file)!=NULL){           //reads the file line by line until the end of the file
printf("%s",line);
}}

int c=fgetc(in_file);
if (c==EOF){                         // if file is empty it prints a message
    printf("End of file\n");
}

fclose(in_file);


}


void clear_file_2(void){
FILE *out_file=fopen("billings.txt","w");
fprintf(out_file," ");
printf("File Cleared\n");                 //clears file buy writing to it,and prints a message accordingly
fclose(out_file);
}


void FAQ_2(void){
printf("\nFrequently Asked Questions\n\n");
printf("Who built this program?\n");
printf("%s\n%s\n%s\n%s\n\n","Programmers","-Henry","-Muhammad","-Kareem");
printf("How are the bills calculated?\n");
printf("Electricity bills\n%s\n%s\n%s\n\n","-KiloWatts=Watts/1000","-KiloWattsHours=Kilowatts*Electricity Hours","-Electricity Bill=KiloWattHours*Gas Tariff");
printf("Gas Bills\n%s\n%s\n%s\n%s\n\n","-Cubic Meters=Cubic Feet*2.83","-KiloWatt=(Cubic Meters*1.02264)/3.6","-KiloWattHours=KiloWatt*Hours","-Gas Bill=KiloWattHours*Gas Tariff");
printf("How many lines of Code is the program?\n%s\n","-418");
}
