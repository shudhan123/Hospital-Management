#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int token_no=0;
int count=-1;

typedef struct PATIENT
{
    char Name[50];
    char Phone_number[10];
    int age;
    char sex[10];
    char symptoms[500];
    char medication[500];
    int height;
    int weight;
    int token;
    struct PATIENT *next;
}PATIENT;

PATIENT *front=NULL;
PATIENT *rear=NULL;

void new_patient();
int check_pos(int );
void display();
void prescription();
int check_no_of_patients();
void see_prescription(int );
void feedback_patient();
void feedback_doctor1();
void feedback_doctor2();
void feedback_doctor3();

int main()
{
    int appointment;
    int choice;
    int left;
    int position;
    int doctor_feedback;
    int id;
    char stored[20];
    char password[10];
    int doctor_choice;
    int patient_choice;
    char name1[20]="rukesh",name2[20]="vishwa",name3[20]="shudhan";
    char pass1[20]="rukesh_pass",pass2[20]="vishwa_pass",pass3[20]="shudhan_pass";
    do 
    {
        system("cls");
		printf("\t\t                  				 ********************************************************** ");
	    printf("\n\t\t                                   			 Welcome to CARE FREE CLINIC!     \n");	
	    printf("\t\t                  				 ********************************************************** ");
        printf("\n\n\t\tPlease choose from the menu below!\n\n\t\t	You ARE Our Beloved ?\n\n");
        printf("\t\t\t1. Doctor\t\t");
        printf("\t2. Patient");
		printf("\n\t\t\t\t\tor");
        printf("\n\n\t\t\t\t      3.Exit\n\n\t\t");
        printf("Your answer: ");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1: system("cls");
                        char doctor_name[20];
                        printf("\t\t                   ************************************************* ");
                        printf("\n\t\t                                Welcome Back Doctor! \n");
                        printf("\t\t                   ************************************************* ");
                        printf("\nPlease Enter The Username To Proceed: ");
                        fgets(doctor_name,20,stdin);
                        getchar();
                        printf("\nPlease Enter The Password To Proceed: ");
                        fgets(password,10,stdin);
                        if(scanf("%s",password) == 0) 
                        {
                            fgetc(stdin);
                            printf("Error\n");
                        }
                        
                        if((strcmp(name1,doctor_name)||strcmp(pass1,password)))
                        {
                            printf("\n\t\t1.Attend Patients");
                            printf("\n\t\t2.View Feedback\n\t\t");
                            scanf("%d",&doctor_feedback);
                            if(doctor_feedback==1)
                            {
                                do
                                {
                                    system("cls");

                                    if(check_no_of_patients()==-1)
                                    {
                                        printf("\n\n\t\t\tNo appointments yet!");
                                        do
                                        {
                                            printf("\n\n\t\t\tPress 3 to exit: ");
                                            scanf("%d",&doctor_choice);
                                            if(doctor_choice!=3)
                                            {
                                                printf("\n\n\t\t\tINVALID OPERATION. Press 3 to exit: ");
                                            }
                                        }while(doctor_choice!=3);
                                    }

                                    else
                                    {
                                        printf("\n\n\t\t\tYou still have %d patients left!",check_no_of_patients());
                                        printf("\n\n\t\t\tYou current patient info:\n\t\t\t");
                                        display();
                                        printf("\n\n\t\t\tChoose the operation you would like to perform:\t1.Write Prescription\t2.Make a video call\t3.EXIT");
                                        scanf("%d",&doctor_choice);
                                    }

                                    if(doctor_choice==2)
                                    {
                                
                                        printf("\n\n\t\tCall in progress!");
                                        printf("\n\t\tCall ended!");
                                        prescription();
                                        printf("\n\t\tEnter any key to see next patient!");
                                        getchar();
                                    }

                                    else if(doctor_choice==1)
                                    {
                                        prescription();
                                    }

                                    else if(doctor_choice!=3)
                                    {
                                        printf("\n\t\tInvalid choice!");
                                    }

                                }while(doctor_choice!=3);
                            }
                            else
                                feedback_doctor1();
                        }
                        else if((strcmp(name2,doctor_name)||strcmp(pass2,password)))
                        {
                            printf("\n\t\t1.Attend Patients");
                            printf("\n\t\t2.View Feedback\n\t\t");
                            scanf("%d",&doctor_feedback);
                            if(doctor_feedback==1)
                            {
                                do
                                {
                                    system("cls");

                                    if(check_no_of_patients()==-1)
                                    {
                                        printf("\n\n\t\t\tNo appointments yet!");
                                        do
                                        {
                                            printf("\n\n\t\t\tPress 3 to exit: ");
                                            scanf("%d",&doctor_choice);
                                            if(doctor_choice!=3)
                                            {
                                                printf("\n\n\t\t\tINVALID OPERATION. Press 3 to exit: ");
                                            }
                                        }while(doctor_choice!=3);
                                    }

                                    else
                                    {
                                        printf("\n\n\t\t\tYou still have %d patients left!",check_no_of_patients());
                                        printf("\n\n\t\t\tYou current patient info:\n\t\t\t");
                                        display();
                                        printf("\n\n\t\t\tChoose the operation you would like to perform:\t1.Write Prescription\t2.Make a video call\t3.EXIT");
                                        scanf("%d",&doctor_choice);
                                    }

                                    if(doctor_choice==2)
                                    {
                                
                                        printf("\n\n\t\tCall in progress!");
                                        printf("\n\t\tCall ended!");
                                        prescription();
                                        printf("\n\t\tEnter any key to see next patient!");
                                        getchar();
                                    }

                                    else if(doctor_choice==1)
                                    {
                                        prescription();
                                    }

                                    else if(doctor_choice!=3)
                                    {
                                        printf("\n\t\tInvalid choice!");
                                    }

                                }while(doctor_choice!=3);
                            }
                            else
                                feedback_doctor2();
                        }
                        else if((strcmp(name3,doctor_name)||strcmp(pass3,password)))
                        {
                            printf("\n\t\t1.Attend Patients");
                            printf("\n\t\t2.View Feedback\n\t\t");
                            scanf("%d",&doctor_feedback);
                            if(doctor_feedback==1)
                            {
                                do
                                {
                                    system("cls");

                                    if(check_no_of_patients()==-1)
                                    {
                                        printf("\n\n\t\t\tNo appointments yet!");
                                        do
                                        {
                                            printf("\n\n\t\t\tPress 3 to exit: ");
                                            scanf("%d",&doctor_choice);
                                            if(doctor_choice!=3)
                                            {
                                                printf("\n\n\t\t\tINVALID OPERATION. Press 3 to exit: ");
                                            }
                                        }while(doctor_choice!=3);
                                    }

                                    else
                                    {
                                        printf("\n\n\t\t\tYou still have %d patients left!",check_no_of_patients());
                                        printf("\n\n\t\t\tYou current patient info:\n\t\t\t");
                                        display();
                                        printf("\n\n\t\t\tChoose the operation you would like to perform:\t1.Write Prescription\t2.Make a video call\t3.EXIT");
                                        scanf("%d",&doctor_choice);
                                    }

                                    if(doctor_choice==2)
                                    {
                                
                                        printf("\n\n\t\tCall in progress!");
                                        printf("\n\t\tCall ended!");
                                        prescription();
                                        printf("\n\t\tEnter any key to see next patient!");
                                        getchar();
                                    }

                                    else if(doctor_choice==1)
                                    {
                                        prescription();
                                    }

                                    else if(doctor_choice!=3)
                                    {
                                        printf("\n\t\tInvalid choice!");
                                    }

                                }while(doctor_choice!=3);
                            }
                            else
                                feedback_doctor3();
                        }
                        else
                        {
                            printf("\n\t\tYou password was incorrect!");
                            getchar();
                            getchar();
                        }
                        break;
                        
                case 2: system("cls");
                        printf("\t\t\t                                      +|||||||||||||||||||||||||||||||||||||||+ \n"); 
                        printf("\t\t\t                                      |                                       |"); 
                        printf("\n\t\t\t                                      |   Welcome to CARE FREE CLINIC!     | \n");
                        printf("\t\t\t                                      |                                       |"); 
                        printf("\n\t\t\t                                      |                ****                   | ");
                        printf("\n\t\t\t                                      |                ****                   | ");
                        printf("\n\t\t\t                                      |                ****                   | ");
                        printf("\n\t\t\t                                      |            ************               |   ");
                        printf("\n\t\t\t                                      |            ************               |    ");
                        printf("\n\t\t\t                                      |            ************               |    ");
                        printf("\n\t\t\t                                      |                ****                   | ");
                        printf("\n\t\t\t                                      |                ****                   | ");
                        printf("\n\t\t\t                                      |                ****                   | \n ");
                        printf("\t\t\t                                      |                                       |"); 
                        printf("\n\t\t\t                                      |  BE DISEASE FREE WITH CARE FREE!!!    |  \n ");
                        printf("\t\t\t                                      |                                       |"); 
                        printf("\n\t\t\t                                      +|||||||||||||||||||||||||||||||||||||||+ "); 
                        printf("\n\n\n\t\t\tChoose one of the options below");
                        printf("\n\n\t\t\t1.New Patient\t2.Already booked appointment\t3.Doctor's details\t4.Feedback of Doctors\t5.DoctorSchedule\t6.Exit ");
                        printf("\n\n\t\t\t     The service Required:");
                        scanf("%d",&patient_choice);
                        switch(patient_choice)
                        {
                            case 1: token_no++;
                                    system("cls");
                                    new_patient();
                                    printf("\n\t\tCongratulations Your Appointment Has Been Confirmed!!!!\n\n" );
                                    printf("\n\t\tYour Destined ID no: %d .\n\n",token_no);
                                    printf("\t\tYour Destined ID is Required For Further Services.....Please Note it Down!!!");
                                    position=check_pos(token_no);
                                    if(position==0)
                                    {
                                        printf("\n\t\t  The doctor is seeing your medical record.\n\n");
                                        printf("\t\t                   ******************************************************** ");
                                        printf("\t\t\t\t\t           			                                           You will be contacted by the doctor Soon!!!");
                                        printf("\n\t\t              			Thank you for your patience!\n");
                                        printf("\t\t                   ******************************************************** ");
                                        getchar();
                                    }
                                    else
                                    {
                                        system("cls");
                                        printf("\n\t\tYou still have %d patients before you. Have patience and please wait!",check_no_of_patients());
                                        getchar();
                                        getchar();
                                    }
                                    break;


                            case 2: system("cls");
                                    printf("\n\t\tPlease enter your ID no.");
                                    scanf("%d",&id);
                                    if(front!=NULL)
                                    {
                                        if(id==front->token)
                                        {
                                            printf("\n\t\t\tThe doctor views your medical record. You will be notified by the doctor in case of more info \n\t\t\tPlease attend his call. Thank you for your patience!");
                                            getchar();
                                            getchar();

                                        }   
                                        else if(id>front->token)
                                        {
                                            position=check_pos(id);
                                            system("cls");
                                            printf("\n\t\tYou still have %d patients before you. Have patience and please wait!",check_no_of_patients());
                                            getchar();
                                            getchar();
                                        }
                                
                                        else if(id<front->token)
                                        {
                                            see_prescription(id);
                                            getchar();
                                            getchar();

                                        }
                                    }

                                    else
                                    {
                                        see_prescription(id);
                                    
                                        getchar();
                                        getchar();
                                    }
                                    
                                    break;
							

                            case 3: system("cls");
                                    getchar();
									printf("\n\t\t                   ******************************************************** ");
									printf("\n\t                        \t\t DOCTOR'S DETAILS\n");
									printf("\t\t                   ******************************************************** ");
                                    printf("\n\t\t\t\t\t\t---------OUR MOTTO---------\n");
									printf("\n\n ' Every patient and their family are different with thier unique needs.My goal is to design an individual treatment plan to help each and every one of them to obtain the best outcome'\t\t");
									printf("\n\n\t\t  PRIMARY LOCATION: banaswadi,bangalore");
                                    printf("\n--------->OUR CARDIOLOGY SPECIALIST: Dr.RUKESH");
									printf("\n\n QUALIFICATIONS");
									printf("\n---------------------------");
									printf("\n M.B.B.S,(OCTOBER 1989,BANGALORE MEDICAL COLLEGE)");
									printf("\n M.D (DECEMBER 1992),BOMBAY MEDICAL COLLEGE");
									printf("\nFELICATIONS");
									printf("\n---------------------------\n");
									printf("FELICATIONS RECIEVED FROM THE HANDS OF MAYOR AND OTHER ORGANISATONS");
                                    printf("\n\n------->OUR ENT SPECIALIST: Dr.SHUDHAN");
									printf("\n\n QUALIFICATIONS");
									printf("\n---------------------------");
									printf("\n M.B.B.S,(SEPTEMBER 1991,M.G.R MEDICAL COLLEGE)");
									printf("\n M.D (DECEMBER 1994),BOMBAY MEDICAL COLLEGE");
									printf("\nFELICATIONS");
									printf("\n---------------------------\n");
									printf("FELICATIONS RECIEVED FROM THE HANDS OF PRESIDENT AND OTHER ORGANISATONS");
									printf("\n\n--------->OUR PEDIATIRST SPECIALIST: Dr.VISWANATH ");
									printf("\n\n QUALIFICATIONS");
									printf("\n---------------------------");
									printf("\n M.B.B.S,(OCTOBER 1989,BANGALORE MEDICAL COLLEGE)");
									printf("\n M.D (DECEMBER 1992),BOMBAY MEDICAL COLLEGE");
									printf("\nFELICATIONS");
									printf("\n---------------------------\n");
									printf("FELICATIONS RECIEVED FROM THE HANDS OF CHIEF MINISTER OF TAMIL NADU AND OTHER ORGANISATONS");
									printf("\n\n\t\t\t********************* WE ARE ALWAYS THERE FOR U*********************");
                                    getchar();
									break;

							case 4: 
                                    printf("\n\t\t                   ******************************************************** ");
                                    printf("\n\t\t                                           FEEDBACKS");
                                    printf("\n\t\t                   ********************************************************\n ");
                                    feedback_patient();
									break;

                            case 5: getchar();
                                    printf("\n\t\t                   **********************************************************");
                                    printf("\n\t\t                                   DOCTORS SCHEDULE                     ");
                                    printf("\n\t\t                   **********************************************************");
                                    printf("\n\t\tNAME		    SPECIALIST		    DAY			        TIMING		        CONTACT NO\n");
                                    printf("\n\t\tDr.Rukesh		CARDIOLOGIST		MONDAY,THURSDAY		9.00 AM TO 5.00 PM	9098765467");
                                    printf("\n\t\tDr.Shudhan		E.N.T			TUESDAY,FRIDAY		10.00 AM TO 7.00 PM	9638527410");
                                    printf("\n\t\tDr.Viswanath	    PEDIATRICIAN		WEDNESDAY,SATURDAY	10.00 AM TO 8.00 PM	9518476230");
                                    getchar();
                                    break;
                            
                            case 6: break;
                            
                            default:printf("\n\t\tInvalid operation! Re-enter: ");
                                    
									
									
						}

        }

    }while(choice!=3);  

    return 0;
}

void new_patient()
{
    PATIENT *temp=(PATIENT *)malloc(sizeof(PATIENT));
    if(temp!=NULL)
    {	
		printf("\t\t                   ************************************************************** ");
        printf("\n\t\t                     Please Enter Your Information To Consult Our Specialist:\n");
		printf("\t\t                   ************************************************************** ");
        printf("\n\t\tNAME: ");
        scanf("%s",temp->Name);
        printf("\n\t\tAGE: ");
        scanf("%d",&temp->age);
        printf("\n\t\tGENDER: ");
        scanf("%s",temp->sex);
        printf("\n\t\tHEIGHT (in cms): ");
        scanf("%d",&temp->height);
        printf("\n\t\tWEIGHT (in Kgs): ");
        scanf("%d",&temp->weight);
        getchar();
        printf("\n\t\tSymptoms ..:\n\t\t ");
        fgets(temp->symptoms,500,stdin);
        temp->token=token_no;
        temp->next=NULL;

        if(front==NULL)
        {
            front=rear=temp;
            rear->next=NULL;
        }

        else
        {
            rear->next=temp;
            rear=temp;
        }

    }
    else
    {
        printf("\n\t\tAll SLOTS ARE FULL!...VISIT US AGAIN");
    }
}

int check_pos(int val)
{
    if(front!=NULL)
    {
        PATIENT *temp=front;

        if(val!='*')
        {
        
            int count=-1;
            while(temp!=NULL)
            {
                count++;

                if(temp->token==val)
                {
                    return count;
                }

                else
                {
                    temp=temp->next;
                }
            }
        }

    }
    printf("\n\t\tInvalid Appointment ID. Press '*' to exit. Re-enter: ");
    scanf("%d",&val);
    check_pos(val);   
}

int check_no_of_patients()
{
    int count=0;
    PATIENT *temp=front;

    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    return (count-1);
}

void display()
{
    if(front==NULL)
    {
        printf("\n\t\t\tNO APPOINTMENTS YET!!");
    }

    else
    {
        printf("\n\t\tNAME:%s",front->Name);
        printf("\n\t\tAGE: %d",front->age);
        printf("\n\t\tGENDER: %s",front->sex);
        printf("\n\t\tHEIGHT (in cms): %d",front->height);
        printf("\n\t\tWEIGHT (in Kgs): %d",front->weight);
        printf("\n\t\tSYMPTOMS:\n\t\t\t%s",front->symptoms);
    }

}

void prescription() 
{
    PATIENT *temp=front;
    if(temp==NULL)
    {
        printf("\n\t\tNo appointment yet! You cannot write a prescription!");
    }
    else
    {
        printf("\n\t\tEnter your prescription: ");
        getchar();
        fgets(temp->medication,500,stdin);
        FILE *fp;
        fp=fopen("patient_record.txt","wb");
        fwrite(temp,sizeof(PATIENT),1,fp);
        fclose(fp);

        if(front==rear)
        {
            printf("\n\t\tThat was your last patient as of now!");
        
            front=rear=NULL;
            free(temp);
        }

        else
        {
            front=front->next;
            free(temp);
        }
    }
}

void see_prescription(int val)
{
    FILE *fp;
    PATIENT patient_now;
    PATIENT *temp;
    temp=&patient_now;
    fp=fopen("patient_record.txt","rb");
    while(!feof(fp))
    {
        fread(temp,sizeof(PATIENT),1,fp);

        if(patient_now.token==val)
        {
            printf("\n\t\tYour finished your appointment....Here are your details:");
            printf("\n\t\tNAME:%s",patient_now.Name);
            printf("\n\t\tAGE: %d",patient_now.age);
            printf("\n\t\tGENDER: %s",patient_now.sex);
            printf("\n\t\tHEIGHT (in cms): %d",patient_now.height);
            printf("\n\t\tWEIGHT (in Kgs): %d",patient_now.weight);
            printf("\n\t\tSYMPTOMS:\n\t\t%s",patient_now.symptoms);
            printf("\n\t\tDOCTOR PRESCRIPTION:\n\t\t\t");
            fputs(patient_now.medication,stdout);
            printf("\n\t\tBE IN GOOD HEALTH!");
            break;
        }

    }

    if(feof(fp))
    {
        printf("\n\t\tID does not exist");
        fclose(fp);
    }
}
void feedback_patient()
{
    int choice;
    FILE *fptr;
    char c;
    int feedback_choice;
    printf("\t\tWhich doctor are you going to give feedback on??\n");
    printf("\n\t\t1.DR.RUKESH-CARDIOLOGIST");
    printf("\n\t\t2.DR.SHUDHAN-E.N.T");
    printf("\n\t\t3.DR.VISWANATH-PEDIATRIST");
    printf("Enter your option: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: 
                 
                fptr = fopen("feedback1.txt", "r+"); 
                c = fgetc(fptr); 

                while (c != EOF) 
                { 
                    printf ("%c", c); 
                    c = fgetc(fptr); 
                }
                printf("\n\n\t\tWant to give your Feedback? (1-Yes/2-No) ");
                scanf("%d",&feedback_choice);
                if(feedback_choice==1)
                {
                    char temp_feedback[100];
                    getchar();
                    printf("\n\t\tFeedback: ");
                    fgets(temp_feedback,500,stdin);
                    for(int i=0;temp_feedback[i]!='\0';i++)
                        fputc(temp_feedback[i],fptr);
                    printf("\n\t\tThank you for giving your feedback!!");
                }
                fclose(fptr); 
                getchar();
                break;

        case 2:  
                fptr = fopen("feedback2.txt", "r+"); 
                c = fgetc(fptr); 

                while (c != EOF) 
                { 
                    printf ("%c", c); 
                    c = fgetc(fptr); 
                }
                
                printf("\n\n\t\tWant to give your Feedback? (1-Yes/2-No) ");
                scanf("%d",&feedback_choice);
                if(feedback_choice==1)
                {
                    char temp_feedback[100];
                    getchar();
                    printf("\n\t\tFeedback: ");
                    fgets(temp_feedback,500,stdin);
                    for(int i=0;temp_feedback[i]!='\0';i++)
                        fputc(temp_feedback[i],fptr);
                    printf("\n\t\tThank you for giving your feedback!!");
                }
                fclose(fptr); 
                getchar();
                break;

        case 3:  
                fptr = fopen("feedback3.txt", "r+"); 
                c = fgetc(fptr); 

                while (c != EOF) 
                { 
                    printf ("%c", c); 
                    c = fgetc(fptr); 
                }
                printf("\n\n\t\tWant to give your Feedback? (1-Yes/2-No) ");
                scanf("%d",&feedback_choice);
                if(feedback_choice==1)
                {
                    char temp_feedback[100];
                    getchar();
                    printf("\n\t\tFeedback: ");
                    fgets(temp_feedback,500,stdin);
                    for(int i=0;temp_feedback[i]!='\0';i++)
                        fputc(temp_feedback[i],fptr);
                    printf("\n\t\tThank you for giving your feedback!!");
                }
                fclose(fptr); 
                getchar();
                break;
        default:break;
    }
    
}
void feedback_doctor1()
{
    FILE *fptr;
    char c; 
    fptr = fopen("feedback1.txt", "r+"); 
    c = fgetc(fptr); 

    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    }

    fclose(fptr); 
    getchar();
    getchar();
}
void feedback_doctor2()
{
    
    FILE *fptr;
    char c; 
    fptr = fopen("feedback2.txt", "r+"); 
    c = fgetc(fptr); 

    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    }

    fclose(fptr); 
    getchar();
    getchar();
}
void feedback_doctor3()
{
    FILE *fptr;
    char c; 
    fptr = fopen("feedback3.txt", "r+"); 
    c = fgetc(fptr); 

    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    }

    fclose(fptr); 
    getchar();
    getchar();
}