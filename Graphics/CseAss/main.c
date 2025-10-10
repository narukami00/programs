#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//,,mmmmmm
typedef struct
{
    int day,month,year;
}Date;

typedef struct
{
    float sports,contest,quality;
}Cocurricular;

typedef struct
{
    int roll;
    char name[30];
    Date dateofbirth;
    char dept[50];
    char section;
    float grade;
    Cocurricular extra;
}Student;

Student * inputStudent(int n){

    Student * student = (Student*)malloc((n)*sizeof(Student));
    for(int i=0;i<n;i++){
        printf("\nStudent %d\n",i+1);
        printf("\nEnter roll : ");
        scanf("%d",&student[i].roll);
        fflush(stdin);
        printf("\nEnter name : ");
        scanf("%[^\n]%*c",&student[i].name);
        printf("\nEnter Date of Birth (dd//mm//yy) : ");
        scanf("%d %d %d",&student[i].dateofbirth.day,&student[i].dateofbirth.month,&student[i].dateofbirth.year);
        fflush(stdin);
        printf("\nEnter Department : ");
        scanf("%[^\n]%*c",&student[i].dept);
        printf("\nEnter section : ");
        scanf(" %c",&student[i].section);
        printf("\nEnter CGPA : ");
        scanf("%f",&student[i].grade);
        printf("\nEnter extra activity (Sports, Contests, Quality) : ");
        scanf("%f %f %f",&student[i].extra.sports,&student[i].extra.contest,&student[i].extra.quality);
    }
    return student;
}

void viewStudents(Student*student,int n){

    for (int i = 0; i < n; i++)
    {
        printf("%-10d %-15s %02d/%02d/%04d\t    %-15s %-9c %-9.2f %-9.2f %-9.2f %-9.2f\n",
               student[i].roll,
               student[i].name,
               student[i].dateofbirth.day, student[i].dateofbirth.month, student[i].dateofbirth.year,
               student[i].dept,
               student[i].section,
               student[i].grade,
               student[i].extra.sports,
               student[i].extra.contest,
               student[i].extra.quality);
    }
}


void searchStudent(Student*student,int n){
    int type;
    int roll, day, month, year;
    float grade,sports, contests, quality;
    char name[30];
    char dept[50];
    char section;

    printf("\nEnter Search Type :\n1.By roll\n2.By name\n3.By department\n4.By section\n5.By day of birth\n6.By month of birth\n7.By year of birth\n8.By CGPA\n9.By sports score\n10.By contests score\n11.By quality score\nYour choice : ");
    scanf("%d",&type);
    fflush(stdin);
    switch (type)
    {
    case 1:
        printf("\nEnter the roll you want to search : ");
        scanf("%d",&roll);
        for(int i=0;i<n;i++){
            if(student[i].roll==roll){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 2:
        printf("\nEnter the name you want to search : ");
        scanf("%[^\n]%*c",name);
        for(int i=0;i<n;i++){
            if(strcmp(student[i].name,name)==0){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 3:
        printf("\nEnter the department you want to search : ");
        scanf("%[^\n]%*c",dept);
        for(int i=0;i<n;i++){
            if(strcmp(student[i].dept,dept)==0){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 4:
        printf("\nEnter the section you want to search : ");
        scanf(" %c",&section);
        for(int i=0;i<n;i++){
            if(student[i].section==section){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 5:
        printf("\nEnter the day of birth you want to search : ");
        scanf("%d",&day);
        for(int i=0;i<n;i++){
            if(student[i].dateofbirth.day==day){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 6:
        printf("\nEnter the month of birth you want to search : ");
        scanf("%d",&month);
        for(int i=0;i<n;i++){
            if(student[i].dateofbirth.month==month){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 7:
        printf("\nEnter the year of birth you want to search : ");
        scanf("%d",&year);
        for(int i=0;i<n;i++){
            if(student[i].dateofbirth.year==year){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 8:
        printf("\nEnter the CGPA you want to search : ");
        scanf("%f",&grade);
        for(int i=0;i<n;i++){
            if(student[i].grade==grade){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 9:
        printf("\nEnter the sports score you want to search : ");
        scanf("%f",&sports);
        for(int i=0;i<n;i++){
            if(student[i].extra.sports==sports){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 10:
        printf("\nEnter the contests score you want to search : ");
        scanf("%f",&contests);
        for(int i=0;i<n;i++){
            if(student[i].extra.contest==contests){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    case 11:
        printf("\nEnter the quality score you want to search : ");
        scanf("%f",&quality);
        for(int i=0;i<n;i++){
            if(student[i].extra.quality==quality){
                printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
                viewStudents(&student[i],1);
            }
        }
        break;

    default:
        printf("\nInvalid Choice\n");
        break;
    }
}

void delStudent(Student * student,int * n){
    int roll;
    printf("\nEnter the roll you want to delete : ");
    scanf("%d",&roll);
    for(int i=0;i<*n;i++){
        if(student[i].roll==roll){
            for(int j=i;j<*n-1;j++){
                student[j]=student[j+1];
            }
            (*n)--;
            printf("\nRoll %d record deleted successfully\n",roll);
            return;
        }
    }printf("\nNo Such Student Was Found\n");
}

int compRoll(const void * a, const void * b){
    return ((Student*)a)->roll - ((Student*)b)->roll;
}

int compGrade(const void * a, const void * b){
    float diff = ((Student*)a)->grade - ((Student*)b)->grade;
    return (diff > 0) - (diff < 0);
}

int compDOB(const void * a, const void * b){
    Date date1 = ((Student*)a)->dateofbirth;
    Date date2 = ((Student*)b)->dateofbirth;
    if(date1.year != date2.year)
        return date1.year - date2.year;
    else if(date1.month != date2.month)
        return date1.month - date2.month;
    else
        return date1.day - date2.day;
}

int compSports(const void * a, const void * b){
    float diff = ((Student*)a)->extra.sports - ((Student*)b)->extra.sports;
    return (diff > 0) - (diff < 0);
}

int compContest(const void * a, const void * b){
    float diff = ((Student*)a)->extra.contest - ((Student*)b)->extra.contest;
    return (diff > 0) - (diff < 0);
}

int compQuality(const void * a, const void * b){
    float diff = ((Student*)a)->extra.quality - ((Student*)b)->extra.quality;
    return (diff > 0) - (diff < 0);
}

int compSection(const void * a, const void * b){
    return ((Student*)a)->section - ((Student*)b)->section;
}

int compName(const void * a, const void * b){
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

void sortStudent(Student * student , int n){
    int order, choice;
    printf("\nEnter order: \n1. Ascending order\n2. Descending order\nYour choice: ");
    scanf("%d", &order);
    printf("\nEnter the number corresponding to the field you want to sort by:");
    printf("\n1. Roll\n2. Name\n3. Section\n4. Grade\n5. Sports\n6. Contest\n7. Quality\n8.Date of Birth\n");
    printf("\nYour Choice : ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            qsort(student,n,sizeof(Student),compRoll);
            break;
        case 2:
            qsort(student,n,sizeof(Student),compName);
            break;
        case 3:
            qsort(student,n,sizeof(Student),compSection);
            break;
        case 4:
            qsort(student,n,sizeof(Student),compGrade);
            break;
        case 5:
            qsort(student,n,sizeof(Student),compSports);
            break;
        case 6:
            qsort(student,n,sizeof(Student),compContest);
            break;
        case 7:
            qsort(student,n,sizeof(Student),compQuality);
            break;
        case 8:
            qsort(student,n,sizeof(Student),compDOB);
            break;
        default:
            printf("Invalid choice\n");
            return;
    }
    if(order == 2){
        for(int i = 0; i < n/2; i++){
            Student temp = student[i];
            student[i] = student[n-i-1];
            student[n-i-1] = temp;
        }
    }
}
void menu(Student * student, int * n){
    int choice;
    while(1){
        printf("\n1.Display Students\n2.Search Student\n3.Delete Student\n4.Sort Students\n5.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\nStudent Information List\n");
            printf("\nRoll       Name            Date of Birth    Department      Section   CGPA      Sports    Contests  Quality   \n");
            viewStudents(student,*n);
            break;
            case 2:
            searchStudent(student,*n);
            break;
            case 3:
            delStudent(student,n);
            break;
            case 4:
            sortStudent(student,*n);
            break;
            case 5:
            printf("\nThank You!\n");
            return;
            default:
            printf("\nInvalid Choice\n");
        }
    }
}

int main(){
    int n;
    printf("\nWelcome to the program\n");
    printf("\nEnter the number of students : ");
    scanf("%d",&n);
    Student * student = inputStudent(n);
    menu(student,&n);
    free(student);
    return 0;
}
