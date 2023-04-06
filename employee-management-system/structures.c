#include <stdio.h>
#include <string.h>

char *fgets(char *str, int n, FILE *stream);

typedef struct employees {
    int id, age, exp_years;
    char name[50];
} employee;

employee Employees[5];
int count = 0;

void record(){
    int check = 0, temp, record_Check = 0;
    printf("Enter the id:");
    scanf("%d", &temp);
    getchar();
    for(int x = 0; x < 5; x++){
        if( Employees[x].id == temp){
            printf("The employe with such an id is already recorderd \n");
            record_Check = 1;
        }
    }

    if(record_Check != 1){
        Employees[count].id = temp;
        printf("Enter the employee name: ");
        fgets(Employees[count].name, 50, stdin);
        printf("Enter the age:");
        scanf("%d", &Employees[count].age);
        printf("Enter the years of experience:");
        scanf("%d", &Employees[count].exp_years);
    }
    printf("Do you want record another employee press 1 or 0 not to record");
    scanf("%d", &check);
    if(check == 1 && count < 5){
        count++;
        record();
    }else if(count >= 5){
        printf("The number of employess has been exceeded");
    }
    return;
}

void display(){

    for(int i = 0; i < 5; i++){
        if(Employees[i].id == 0){
            printf("No records available \n");
            break;
        }
        printf("Employee No%d: ID: %d \t Name: %s \t Age: %d \t Years of experience: %d \n",i+1, Employees[i].id, Employees[i].name, Employees[i].age, Employees[i].exp_years);
    }

}

void search() {
    int num, id;
    printf("Enter the id of the employee to search for: ");
    scanf("%d", &id);
    for(int i = 0; i < 5; i++){
        if(Employees[i].id == id){
            printf("The searched employee is: \n ");
            printf("Employee %d: ID: %d \t Name: %s \t Age: %d \t Years of experience: %d \n",i+1, Employees[i].id, Employees[i].name, Employees[i].age, Employees[i].exp_years);
            num = 1;
        }
    }
    if(num != 1){
        printf("The searched employee does not exit in our records \n \n");
    }
    return;
}

void main (void){
    int close = 0, check;
    printf(" ______Welcome to our employee management program_______ \n \n \n ");
    printf("--To go along with the program \n Press 1 to record the  employees \t press 2 to display the recorded employees \n \n press 3 to search an employee \t press 4 to display the employees in an ascending order \n \n press 0 to exit the program; \n \n \n");
    while(close == 0){
        printf("Please enter your option: ");
        scanf("%d", &check);
        switch(check){
            case 1:
                record();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                printf("Service not available at the moment");
                break;
            case 0:
                close = 1;
                printf("Thank you for using our program");
                break;
            default:
                printf("\n \n \t !!!!! -----Invalid option---- \n \n");
        }
    }

    return;



}
