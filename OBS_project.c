#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACADEMIST_SIZE 4
#define USERNAME_SIZE 20
#define PASSWORD_SIZE 10
#define STUDENT_SIZE 100
#define SIZE 50

/// struct definition...
typedef struct
{

	char username[USERNAME_SIZE];
	char password[PASSWORD_SIZE];

} person;

typedef struct
{

	char lesson[SIZE];
	int term;
	int term1[6];
	int department;
	int mark;
	int mark2;

} lessons;

typedef struct
{

	person academ;
	lessons lesson1;
	char department;

} academists;

typedef struct
{

	person person1;
	lessons less2;
	lessons less3;
	int department;
} students;

int upfolder(academists academist[], students student[], person *admin, person *officer, lessons less[], int *studentCount, int *courseCount);
int saveinfolder(academists academist[], students student[], person *admin, person *officer, lessons less[], int *studentCount, int *courseCount);
int adminMenu(person admin, academists academist[], person *officer, students student[], lessons less[]);
int officerMenu(person officer, students student[], academists academist[], lessons less[], int *studentCount, int *courseCount);
int studentMenu(students student[],lessons less[],int *courseCount ,int *studentCount);
int academistMenu(academists academist[], students student[], lessons less[]);
int openLesson(academists academist[], students student[], lessons less[], int *courseCount);
void akademisyenara(academists academist[]);

int main()
{
	int i = 0;
	int studentCount  = 0, courseCount = 0;
	person admin, officer;
	students student[STUDENT_SIZE];
	academists academist[ACADEMIST_SIZE];
	lessons less[50];
	int choice = 0, exit = 1;

	upfolder(academist, student, &admin, &officer, less, &studentCount, &courseCount);

	do
	{
		printf("Select the option you want the login...\n");
		printf("1-Admin Login\n");
		printf("2-Officer Login\n");
		printf("3-Academist Login\n");
		printf("4-Student Login\n");
		printf("6-akademisyen yazdir:\n");
		printf("5-EXIT\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			adminMenu(admin, academist, &officer, student, less);
		}
		else if (choice == 2)
		{
			officerMenu(officer, student, academist, less,  &studentCount, &courseCount);
		}

		else if (choice == 3)
		{
			academistMenu(academist, student, less);
		}
		else if (choice == 4)
		{
			studentMenu(student,less, &studentCount ,&courseCount);
		}
		else if(choice==6)
		{
			akademisyenara(academist);
		}
		else if (choice == 5)
		{
			exit = 0;
		}

	} while (exit);
	saveinfolder(academist, student, &admin, &officer, less,  &studentCount, &courseCount);
	return 0;
}

///admin registration menu...
int adminMenu(person admin, academists academist[], person *officer, students student[], lessons less[])
{
	int academCount = 0, choice = 0, exit = 1;
	char adUsername[USERNAME_SIZE] = {0};
	char adPassword[PASSWORD_SIZE] = {0};

	printf("Please enter username:\n");
	scanf(" %[^\n]%*c", adUsername);
	printf("Please enter password:\n");
	scanf("%s", adPassword);

	if (strcmp(admin.username, adUsername) == 0 && strcmp(admin.password, adPassword) == 0)
	{
		do
		{
			printf("1-Academist Registration\n");
			printf("2-Officer Registration\n");
			printf("3-EXIT\n");
			scanf("%d", &choice);

			if (choice == 1)
			{
				do
				{
					printf("Please enter username:\n");
					scanf(" %[^\n]%*c", academist[academCount].academ.username);
					printf("Please enter password:\n");
					scanf("%s", academist[academCount++].academ.password);

					printf("Do you want to registration of new academist?\n");
					printf("1-Yes\n");
					printf("2-No\n");
					scanf("%d", &exit);
				} while (exit == 1);
			}

			else if (choice == 2)
			{
				printf("Please enter username:\n");
				scanf(" %[^\n]%*c", officer->username);
				printf("Please enter password:\n");
				scanf("%s", officer->password);
			}

			else if (choice == 3)
			{
				exit = 0;
			}
		} while (exit);
	}
	return 1;
}

//officer registration menu..
int officerMenu(person officer, students student[], academists academist[], lessons less[], int *studentCount, int *courseCount)
{
	char offUsername[USERNAME_SIZE] = {0};
	char offPassword[PASSWORD_SIZE] = {0};
	int exit = 1, choice = 0, j;

	printf("Please enter username:\n");
	scanf(" %[^\n]%*c", offUsername);
	printf("Please enter password:\n");
	scanf("%s", offPassword);

	if (strcmp(officer.username, offUsername) == 0 && strcmp(officer.password, offPassword) == 0)
	{
		do
		{
			printf("Enter your choice:\n");
			printf("1-Student Registration:\n");
			printf("2-Course Registration:\n");
			printf("3-EXIT\n");
			scanf("%d", &choice);

			if (choice == 1)
			{
				do
				{
					printf("Please enter username:\n");
					scanf(" %[^\n]%*c", student[*studentCount].person1.username);
					printf("Please enter password:\n");
					scanf("%s", student[*studentCount].person1.password);

					printf("Please enter the course department\n");
					printf("1-Software engineering\n");
					printf("2-Computer engineering\n");
					printf("3-Electric electronic engineering\n");
					scanf("%d", &student[*studentCount].department);

					for (j = 0; j < STUDENT_SIZE; ++j)
					{

						student[j].less2 = less[*studentCount];

						++*studentCount;
						break;
					}

					printf("Do you want to registration of new student?\n");
					printf("1-Yes\n");
					printf("2-No\n");
					scanf("%d", &exit);
				} while (exit == 1);
			}

			else if (choice == 2)
			{
				openLesson(academist, student, less, courseCount);
			}

			else if (choice == 3)
			{
				exit = 0;
			}

		} while (exit);
	}
	return 1;
}

//student information menu...
int studentMenu(students student[],lessons less[],int *studentCount , int *courseCount)
{
	int i = 0, choice = 0,  exit = 1, j = 0, num =0;
	char Username[USERNAME_SIZE] = {0};
	char Password[PASSWORD_SIZE] = {0};
	char str[SIZE]={0};

	printf("Please enter username:\n");
	scanf(" %[^\n]", Username);
	printf("Please enter password:\n");
	scanf("%s", Password);

	for (i = 0; i < STUDENT_SIZE ; i++)
	{
		if (strcmp(student[i].person1.username, Username) == 0 && strcmp(student[i].person1.password, Password) == 0)
		{
			
			do
			{
				student[i].less2.term=1;
				printf("1-Chooose a course and grade status\n");
				printf("2-Chooose a course\n");
				printf("3-student certificate\n");
				printf("4-EXIT\n");
				scanf("%d", &choice);
				
				if (choice == 1)
				{
					printf("%s\n", student[i].less2.lesson);
					printf("%s\n", student[i].less3.lesson);
				}
				else if(choice == 2)
				{
					for (j=0; j < *courseCount; ++j)
					{
						printf("%s\n", less[j].lesson);
					}
					printf("Select the course you want to see your grade!\n");
					scanf("%s", str);
					for (j=0; j < *courseCount; ++j)
					{
						if (strcmp(str, less[j].lesson)==0)
						{
							strcpy(student[i].less2.lesson, less[j].lesson);	
						}
					}
					printf("Do you want to continue yes-1,no-2\n");
					scanf("%d", &num);
					if (num == 1)
					{
						scanf("%s", str);
						for (j=0; j < *courseCount; ++j)
						{
							if (strcmp(str, less[j].lesson)==0)
							{
								strcpy(student[i].less3.lesson, less[j].lesson);	
							}
						}
					}
					if (num == 2)
					{
						exit = 0;
					}
					
				}
				else if(choice == 4)
				{
					exit=0;
				}

			} while (exit);
		}
	}

	return 1;
}

//academician grade entry menu...
int academistMenu(academists academist[], students student[], lessons less[])
{
	int i = 0;
	char Username[USERNAME_SIZE] = {0};
	char Password[PASSWORD_SIZE] = {0};

	printf("Please enter username:\n");
	scanf(" %[^\n]%*c", Username);
	printf("Please enter password:\n");
	scanf("%s", Password);

	for (i = 0; i < ACADEMIST_SIZE; i++)
	{
		if (strcmp(academist[i].academ.username, Username) == 0 && strcmp(academist[i].academ.password, Password) == 0)
		{
			printf(" ");
		}
	}
	return 1;
}

//lesson opening menu...
int openLesson(academists academist[], students student[], lessons less[], int *courseCount)
{

	int j = 0, exit = 1;
	char academicianChoice[SIZE] = {0};

	do
	{
		printf("Please enter the name of the course\n");
		scanf(" %[^\n]%*c", less[*courseCount].lesson);

		printf("Please enter the course department\n");
		printf("1-Software engineering\n");
		printf("2-Computer engineering\n");
		printf("3-Electric electronic engineering\n");
		scanf("%d", &less[*courseCount].department);
		printf("1-1st term of fall\n");
	   	printf("2-1st term of spring\n");
		printf("3-2st term of fall\n");
		printf("4-2st term of spring\n");
		scanf("%d", &less[*courseCount].term);
		printf("Select the instructor you want to match the entered course with\n");

		for (j = 0; j < ACADEMIST_SIZE; ++j)
		{
			printf("%s\n", academist[j].academ.username);
		}
		printf("Please select the academist!\n");
		scanf("%s", academicianChoice);

		for (j = 0; j < ACADEMIST_SIZE; ++j)
		{
			if (strcmp(academicianChoice, academist[j].academ.username) == 0)
			{
				academist[j].lesson1 = less[*courseCount];
				++*courseCount;
				break;
			}
		}
		printf("Do you want to registration of new course ?\n");
		printf("1-Yes\n");
		printf("2-No\n");
		scanf("%d", &exit);
	} while (exit == 1);

	printf("Lessons : %s\n", academist[j].lesson1.lesson);

	return 1;
}

int upfolder(academists academist[], students student[], person *admin, person *officer, lessons less[], int *studentCount, int *courseCount)
{
	int i = 0;
	char arr[SIZE] = {0};
	FILE *ptr;

	ptr = fopen("admin.txt", "r");
	while (fgets(arr, SIZE, ptr))
	{
		sscanf(arr, "%[^,],%[^\n]", admin->username, admin->password);
	}
	fclose(ptr);

	ptr = fopen("officer.txt", "r");
	while (fgets(arr, SIZE, ptr))
	{
		sscanf(arr, "%[^,],%[^\n]", officer->username, officer->password);
	}
	fclose(ptr);

	i = 0;
	ptr = fopen("academist.txt", "r");
	while (fgets(arr, SIZE, ptr))
	{
		sscanf(arr, "%[^,],%[^\n]", academist[i].academ.username, academist[i].academ.password);
		++i;
	}
	fclose(ptr);

	i = 0;
	ptr = fopen("student.txt", "r");
	while (fgets(arr, SIZE, ptr))
	{
		sscanf(arr, "%[^,],%[^,],%d",
			   student[*studentCount].person1.username,
			   student[*studentCount].person1.password,
			   &student[*studentCount].less2.department);
		++*studentCount;
	}
	fclose(ptr);

	i = 0;
	ptr = fopen("courses.txt", "r");
	while (fgets(arr, SIZE, ptr))
	{
		sscanf(arr, "%[^,],%d,%d", less[*courseCount].lesson, &less[*courseCount].department, &less[*courseCount].term);
		++*courseCount;
	}
	fclose(ptr);

	i = 0;
	ptr = fopen("academcourse.txt", "r");
	while (fgets(arr, SIZE, ptr))
	{
		sscanf(arr, "%[^,],%[^\n]", academist[i].academ.username, academist[i].lesson1.lesson);
		++i;
	}
	fclose(ptr);

	return 1;
}

int saveinfolder(academists academist[], students student[], person *admin, person *officer, lessons less[], int *studentCount, int *courseCount)
{
	int i = 0;
	FILE *ptr;

	ptr = fopen("officer.txt", "w");
	if (officer->username != NULL)
	{
		fprintf(ptr, "%s,%s\n", officer->username, officer->password);
	}

	fclose(ptr);
	ptr = fopen("student.txt", "w");
	for (i = 0; i < *studentCount; ++i)
	{
		fprintf(ptr, "%s,%s,%d\n",
				student[i].person1.username,
				student[i].person1.password,
				student[i].less2.department);
	}
	fclose(ptr);

	ptr = fopen("academist.txt", "w");
	for (i = 0; i < ACADEMIST_SIZE; ++i)
	{
		if (academist[i].academ.username != NULL)
		{
			fprintf(ptr, "%s,%s\n", academist[i].academ.username, academist[i].academ.password);
		}
	}
	fclose(ptr);
	ptr = fopen("courses.txt", "w");
	for (i = 0; i < *courseCount; ++i)
	{
		if (less[i].lesson != NULL)
		{
			fprintf(ptr, "%s,%d,%d\n", less[i].lesson, less[i].department, less[i].term);
		}
	}
	fclose(ptr);

	ptr = fopen("academcourse.txt", "w");
	for (i = 0; i < ACADEMIST_SIZE; ++i)
	{
		if (academist[i].academ.username != NULL)
		{
			fprintf(ptr, "%s,%s\n", academist[i].academ.username, academist[i].lesson1.lesson);
		}
	}
	fclose(ptr);

	return 1;
} 



void akademisyenara(academists academist[])

{

 int i;

 for(i=0;i<ACADEMIST_SIZE;i++)
 {
	 printf("%s\n", academist[i].academ.username);

 }
}























