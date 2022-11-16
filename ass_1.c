#include <stdio.h>
#include <stdlib.h>
//Global variable Declaration

int Number_of_candidates_enrolled = 0;

//i is a variable which keeps the track of number of candidates
int i = 0;//The tracking variable or the index variable.


// Structure to store the candidate's different details
struct candidate_info {
    char   name[50];
    int    roll;
    int    chem_marks;
    int    phy_marks;
    int    math_marks;
    char   father_name[20];
    char   mother_name[20];
    int    age;
    char   dob[10];
    int    category_number;
    int    all_india_rank;
    char   district[10];
    int    jee_rank;
    double percentile;
};
struct candidate_info c[50];



//All the functions are declared here so that any function can access any funcion irrespective of any sequence.
void    display();
double  percentile_calculator(int rank);
int     jee_log();
void    find_candidate();
float   total(float x,float y,float z);
void    advance_qualification();
void    take_candidate_info();
void    record_the_entry();
void    take_candidate_info();



//1. Function to add the candidates along with all thier details
//It takes differnt input details of the candidate
void take_candidate_info()
{
    printf("\n\t\t\t\tEnter the name of the candidate : ");
    fflush(stdin);//It is used to avoid errors coming while taking the inputs
    gets(c[i].name);//input the name

    printf("\n\t\t\t\tEnter the father name of the candidate: ");
    fflush(stdin);
    gets(c[i].father_name);//input the father name of the candidate

    printf("\n\t\t\t\tEnter the mother name of the candidate: ");
    fflush(stdin);
    gets(c[i].mother_name);////input the mother name of the candidate

    printf("\n\t\t\t\tEnter the date of birth of the candidate in the format (date-month-year): ");
    fflush(stdin);
    gets(c[i].dob);//input the name date of birth of the candidate

    printf("\n\t\t\t\tEnter age: ");
    scanf("%d", &c[i].age);//input the age

    printf("\n\t\t\t\tEnter the enrollment number of the candidate starting from 1 : ");
    scanf("%d", &c[i].roll);//input the roll number of the candidate

    printf("\n\t\t\t\tEnter the chemistry marks of the candiate :");
    scanf("%d", &c[i].chem_marks);//input the chemistry marks

    printf("\n\t\t\t\tEnter the physics marks of the candiate :");
    scanf("%d", &c[i].phy_marks);//input the physics marks

    printf("\n\t\t\t\tEnter the maths marks of the candiate :");
    scanf("%d", &c[i].math_marks);//input the maths marks

    printf("\n\t\t\t\tEnter the home town:");
    scanf("%s", &c[i].district);//input the district

    printf("\n\t\t\t\tEnter the all india rank of the candidate :");
    scanf("%d", &c[i].all_india_rank);//input the all India rank
    
    printf("\n\t\t\t\tEnter the category of the candidate:");
    printf("\n\t\t\t\t1--->General");
    printf("\n\t\t\t\t2--->OBC");
    printf("\n\t\t\t\t3--->SC");
    printf("\n\t\t\t\t4--->ST  : ");
    scanf("%d", &c[i].category_number);//input the category                              
    printf("\n");
    display();//display function is called here.

    c[i].percentile = percentile_calculator(c[i].all_india_rank);
    i++; //This is a update index statement so that the information of the next candidate gets stored in the 
    // c[i+1].

}




//2. A simple total function which takes 3 inputs and return the sum of all
float total(float x,float y,float z){
    float sum = x+y+z;
    return sum;
}




//3.Function to display the details after adding the candidate info
//It is specifically designed with correct numbers of the identations to give a table like look.
void display(){
    printf("\n------------------------------------------------------------------------------------\n");
    printf("|                               JOINT ENTRANCE EXAMINATION                           |\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("|Name: %s\tCategory: %dth\tRoll Number: %d\n", c[i].name, c[i].category_number, c[i].roll);
    printf("|Father name: %s\t JEE rank :%d\n", c[i].father_name,c[i].all_india_rank);
    printf("|Mother name: %s\n",  c[i].mother_name);
    printf("|Date of birth: %s\n",  c[i].dob);
    printf("|District: %s\n",  c[i].district);
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\tSUBJECTS      \tMAX MARKS\tMIN MARKS NEEDED\tTHEORY MARKS\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\tPhysics      \t  100      \t   33       \t      %d\n",c[i].phy_marks);
    printf("|\tMaths       \t  100      \t   33       \t      %d\n", c[i].math_marks);
    printf("|\tChemistry      \t  100      \t   33       \t      %d\n", c[i].chem_marks);
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\t              \t  300    |    GRAND TOTAL\t    %f\n", total(c[i].phy_marks,c[i].math_marks,c[i].phy_marks));
    printf("|Percentile: %lf\n", percentile_calculator(c[i].all_india_rank) );
    printf("|------------------------------------------------------------------------------------\n");
}





// 4.Function to find the candidate by the roll number
//This function will take a roll number as input and return all the details of that candidate.
void find_candidate()
{
    int x;
    int flag;
    int position;
    fflush(stdin);
    printf("Enter the Roll Number"
           " of the candidate\n");
    scanf("%d", &x);
    for (int j = 0; j < 50; j++)
    {
        if(x  == c[j].roll){
            flag =1;
            position = j;
        }
    }
    //The above segment finds the index variable of the array of the structure used 
    //as per the roll number entered by the user 

    //Below segment comes into the role after the successful indentification of the index variable.
    //This segments prints all the details of that candidate
    if (flag == 1){
         printf("\n\t\t\tName of the candidate is %s : ",c[position].name);
         printf("\n\t\t\tFather's Name of the candidate is %s : ",c[position].father_name);
         printf("\n\t\t\tMother's Name of the candidate is %s : ",c[position].mother_name);
         printf("\n\t\t\tPhysics marks of the candidate are  %d : ",c[position].phy_marks);
         printf("\n\t\t\tMaths marks of the candidate are  %d : ",c[position].math_marks);
         printf("\n\t\t\tChemistry marks of the candidate are  %d : ",c[position].chem_marks);
         printf("\n\t\t\tAge of the candidate is %d : ",c[position].age);
         printf("\n\t\t\tThe date of birth of the candidate is : %s",c[position].dob);
         printf("\n\t\t\tRank of the candidate is : %d",c[position].all_india_rank);
         printf("\n\t\t\tPercentile of the candidate aacording to the number is : %lf",c[position].percentile);
         
    }   
}





//5.Function to modify the candidate details
//This function also takes roll number as inputs and is used to modify the details of that student. 
void modify(){
    int x;
    int flag;
    int position;
    fflush(stdin);
    printf("Enter the Roll Number"
           " of the candidate\n");
    scanf("%d", &x);
    for (int j = 0; j < 50; j++)
    {
        if(x  == c[j].roll){
            flag =1;
            position = j;
        }
    }
    //The above segment finds the index variable of the array of the structure used 
    //as per the roll number entered by the user 
    
    //Below segment comes into the role after the successful indentification of the index variable.
    //This segments reassigns the details of that candidate
    if (flag == 1){
    printf("\n\t\t\t\tEnter the name of the candidate : ");
    fflush(stdin);
    gets(c[position].name);
    printf("\n\t\t\t\tEnter the father name of the candidate: ");
    fflush(stdin);
    gets(c[position].father_name);
    printf("\n\t\t\t\tEnter the mother name of the candidate: ");
    fflush(stdin);
    gets(c[position].mother_name);
    printf("\n\t\t\t\tEnter the date of birth of the candidate in the format (date-month-year): ");
    fflush(stdin);
    gets(c[position].dob);
    printf("\n\t\t\t\tEnter age: ");
    scanf("%d", &c[position].age);
    printf("\n\t\t\t\tEnter the chemistry marks of the candiate :");
    scanf("%d", &c[position].chem_marks);
    printf("\n\t\t\t\tEnter the physics marks of the candiate :");
    scanf("%d", &c[position].phy_marks);
    printf("\n\t\t\t\tEnter the maths marks of the candiate :");
    scanf("%d", &c[position].math_marks);
    printf("\n\t\t\t\tEnter the home town:");
    scanf("%s", &c[position].district);
    printf("\n\t\t\t\tEnter the all india rank of the candidate :");
    scanf("%d", &c[position].all_india_rank);
         
    }
       
}





//6.Function for entering jee conduction details
//also this function throws a brief introduction about the JEE examination.
int jee_log(){
    printf("\n\t\t\t\tJEE or Joint Entrance Examination\n");
    printf("The Joint Entrance Examination (JEE) is an engineering entrance"
    " assessment conducted for admission to various  engineering colleges in India.");
    printf("\n\t\t\t\tEnter the number of students attempted jee this year :");
    scanf("%d",&Number_of_candidates_enrolled);
    return  Number_of_candidates_enrolled;
}




    
//7.This function checks the qualification for advance:
//The function takes the roll number as inputs and returns advanced qualification status on the basis of category
//of the candidate. 
void advance_qualification(){
    int  x;
    int  flag;  //Used to carry forward the process after the identification to the trackiing the variable
    int  position;
    fflush(stdin);
    printf("Enter the Roll Number"
           " of the candidate\n");
    scanf("%d", &x);
    for (int j = 0; j < 50; j++)
    {
        if(x  == c[j].roll){
            flag =1;
            position = j;
        }
    }
    //The above segment finds the index variable of the array of the structure used 
    //as per the roll number entered by the user 

    if (flag == 1) 
        {printf("As per the category criteria \n");

        //checking the category of the candidate and then examining the cutoff marks for the advance 
        //qualification as per the category.
        if(c[position].category_number ==1 ){
            printf("The candidate belong to general category \n");
            if(c[position].percentile>=90){
                printf("The candidate has qualified for jee advanced \n");
            }
        }

        else if(c[position].category_number ==2 ){
            printf("The cadidate belongs to the OBC category \n");
            if(c[position].percentile>=83){
                printf("The candidate has qualified for jee advanced \n");
            }
        }
        else if(c[position].category_number ==3 ){
            printf("The cadidate belongs to the SC category \n");
            if(c[position].percentile>=75){
                printf("The candidate has qualified for jee advanced \n");
            }
        }
        else if(c[position].category_number ==4 ){
            printf("The cadidate belongs to the ST category \n");
            if(c[position].percentile>=60){
                printf("The candidate has qualified for jee advanced \n");
            }
        }
        else{
            printf("Enter the correct category \n");
        }
    }
}


   



//8.Program to find the percentile of the candidate
//the function uses a simple algorithm which converts the rank to the percentile
double percentile_calculator(int rank){
    double percentile;
    if((Number_of_candidates_enrolled !=0)|| (Number_of_candidates_enrolled >= rank))
    {
        percentile = (double)(Number_of_candidates_enrolled - rank)*100/Number_of_candidates_enrolled;
    }
    else{
        printf("Please enter the correct number of the students attempted the exam \n");
    }
    return percentile;
}

//9.The below function uses file handling  and prints the data of the candidate into a seperate text file(emp.txt)
void record_the_entry(){
    FILE *fptr; 
    fptr = fopen("emp.txt", "a+");/*  open for writing */  
    if (fptr == NULL)  
    {  
        printf("File does not exists \n");
    }   
    fprintf(fptr, "Id= %d\n", i+1);   
    fprintf(fptr, "Name= %s\n", c[i].name);
    fprintf(fptr, "Age= %d\n", c[i].age); 
    fprintf(fptr, "Rank= %d\n", c[i].all_india_rank);
    fprintf(fptr, "Percentile = %lf\n", c[i].percentile);
    fprintf(fptr, "dob= %s\n", c[i].all_india_rank);
    fprintf(fptr, "Mother name= %s\n", c[i].mother_name);
    fprintf(fptr, "District= %s\n", c[i].district);
    fprintf(fptr, "Roll number= %d\n", c[i].roll);  
    fclose(fptr);  
}




//10.main function
int main(){
    int arbitrary_rank;
    int loop_terminater = 1;
    int option;

    //A catchy display
    printf("\n\n\t\t\t\t Joint Entrance Examination (2022)");
    printf("\n\n\t\t\t\t\t\t   NTA \n");

    // The below segment redirects the user to the jee_log function to fetch some basic data needed for the program
    //running.
    printf("\n\n\t\t\t\t JEE information\n");
    jee_log();

    //A while loop is introduced over here to basically put the program in an unending loop
    //So that as far as user wants the program runs
    while(loop_terminater == 1)
    {
        printf("\n\n");
        printf("\n\n\t\t\t\t   Select from the given options");
        printf("\n\n\t\t\t\t1. Add Student");
        printf("\n\n\t\t\t\t2. Find the candidate by the roll number");
        printf("\n\n\t\t\t\t3. Modify Student");
        printf("\n\n\t\t\t\t4. Record the entry int the text file");
        printf("\n\n\t\t\t\t5. check elegibility for the jee advance");
        printf("\n\n\t\t\t\t6. Criterion and information");
        printf("\n\n\t\t\t\t7. Rank to percentile convertor");
        printf("\n\n\t\t\t\t8. Logout");
        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        scanf("%d",&option);
        fflush(stdin);
        

        //Switch case is used here to give the user with various options each leading to a different function 
        //and ultimately to the different use and utility.
        switch (option)
        {

        //This case redirects the user to take_candidate_info function followed by the display function
        case 1:
            take_candidate_info();
            void display();
            break;

        //This case redirects the user to find_candidate function
        case 2:
            find_candidate();
            break;

        //This case redirects the user to modify function
        case 3:
            modify();
            break;

        //This case redirects the user to record_the_entry function
        case 4:
            record_the_entry();         
            break;
        
        //This case redirects the user to advance_qualification function
        case 5:
            advance_qualification();
            break;
        
        //This case redirects the user to jee_log function
        case 6:
            jee_log();
            break;
        
        //This case will take a arbitrary rank and by using the percentile_calculator function will convert it to
        //the percentile
        case 7:
            printf("Enter the rank: ");
            scanf("%d",&arbitrary_rank);
            printf("The percentile is : %lf",percentile_calculator(arbitrary_rank));
            
            break; 
        // The objective of the loop terminater is to end the while rule and ultimately the program
        case 8:
            loop_terminater = 0;
            break;
        
        
        default:
            break;
        }
        
    }
    return 0;
} 

//comment added for learning purpose