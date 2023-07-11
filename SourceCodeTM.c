#include<stdio.h>
#include<string.h>
#include<time.h>

#include "test.h"

int t(void)
{
	time_t t;
	time(&t);
	printf("%s\n",ctime(&t));
}

long int dateformat(int day, int month, int year) //time value
{
	time_t nulltime = time(NULL);
	struct tm *DueDateDetail = localtime(&nulltime);
	DueDateDetail -> tm_year = year - 1900;
	DueDateDetail -> tm_mon = month - 1;
	DueDateDetail -> tm_mday = day;
	time_t DueDateTime = mktime(DueDateDetail);
	return(DueDateTime);
}

void view_all() //view all tasks
{
	int category, status;
	long int datedetail;
	char tname[25], tdesc[50];
	FILE *fp;
	printf("\nNAME\tDATE\t\tCATEGORY\t\tSTATUS\t\tDESCRIPTION\n");
	fp = fopen("TaskData.txt","r");
	fseek(fp,0,SEEK_SET);
	while (fscanf(fp,"%s\t",&tname)!=EOF)
	{
		fscanf(fp,"%ld\t", &datedetail);
		fscanf(fp,"%d\t",&category);
		fscanf(fp,"%d\t", &status);
		fgets(tdesc,50,fp);
		time_t taskdate = datedetail;
		struct tm *TaskStruct=localtime(&taskdate);
		printf("%s\t",tname);
		printf("%d/%d/%d\t",TaskStruct -> tm_mday, TaskStruct->tm_mon+1, TaskStruct->tm_year+1900);
		if(category == 1)
		{
			printf("Important Task\t\t");
		}
		else if (category == 2)
		{
			printf("Business Task\t\t");
		}
		else if (category == 3)
		{
			printf("Personal Task\t\t");
		}
		else if (category == 4)
		{
			printf("Regular Task\t\t");
		}
		else if (category == 5)
		{
			printf("Family Task\t\t");
		}
		if(status == 1)
		{
			printf("Pending\t\t");
		}
		else if (status == 2)
		{
			printf("Finish\t\t");
		}
		printf("%s",&tdesc);
	}
	fclose(fp);
}

void view_cate()//view all tasks based on category
{
	int category, level,status;
	long int datedetail;
	char tname[25], tdesc[50];
	FILE *fp;
	fp = fopen("TaskData.txt","r");
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VIEW TASK CATEGORY MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\xDB\xDB\xDB\xDB\xB2 1. IMPORTANT TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 2. BUSINESS TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 3. PERSONAL TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 4. REGULAR TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 5. FAMILY TASK\n");
	printf(" Please Enter Level Category You Want to View: ");
	scanf("%d",&level);
	fseek(fp,0,SEEK_SET);
	printf("\nNAME\tDATE\t\tCATEGORY\t\tSTATUS\t\tDESCRIPTION\n");
	while (fscanf(fp,"%s",&tname)!=EOF)
	{
		fscanf(fp,"%ld", &datedetail);
		fscanf(fp,"%d",&category);
		fscanf(fp,"%d", &status);
		fgets(tdesc,50,fp);
		if (category == level)
		{
			time_t taskdate = datedetail;
			struct tm *TaskStruct=localtime(&taskdate);
			printf("%s\t",tname);
			printf("%d/%d/%d\t",TaskStruct -> tm_mday, TaskStruct->tm_mon+1, TaskStruct->tm_year+1900);
			if(category == 1)
			{
				printf("Important Task\t\t");
			}
			else if (category == 2)
			{
				printf("Business Task\t\t");
			}
			else if (category == 3)
			{
				printf("Personal Task\t\t");
			}
			else if (category == 4)
			{
				printf("Regular Task\t\t");
			}
			else if (category == 5)
			{
				printf("Family Task\t\t");
			}
			if(status == 1)
			{
				printf("Pending\t\t");
			}
			else if (status == 2)
			{
				printf("Finish\t\t");
			}


			printf("%s",&tdesc);
		}
	}
	fclose(fp);
}

void view_status()//view all tasks based on status
{
	int category, vstats,status;
	long int datedetail;
	char tname[25], tdesc[50];
	FILE *fp;

	fp = fopen("TaskData.txt","r");

	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VIEW TASK STATUS MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\xDB\xDB\xDB\xDB\xB2 1. PENDING TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 2. FINISHED TASK\n");
	printf(" Please Enter Status You Want to View: ");
	scanf("%d",&vstats);


	fseek(fp,0,SEEK_SET);
	printf("\nNAME\tDATE\t\tCATEGORY\t\tSTATUS\t\tDESCRIPTION\n");
	while (fscanf(fp,"%s",&tname)!=EOF)
	{
		fscanf(fp,"%ld", &datedetail);
		fscanf(fp,"%d",&category);
		fscanf(fp,"%d", &status);
		fgets(tdesc,50,fp);

		if (status == vstats)
		{
			time_t taskdate = datedetail;
			struct tm *TaskStruct=localtime(&taskdate);
			printf("%s\t",tname);
			printf("%d/%d/%d\t",TaskStruct -> tm_mday, TaskStruct->tm_mon+1, TaskStruct->tm_year+1900);

			if(category == 1)
			{
				printf("Important Task\t\t");
			}
			else if (category == 2)
			{
				printf("Business Task\t\t");
			}
			else if (category == 3)
			{
				printf("Personal Task\t\t");
			}
			else if (category == 4)
			{
				printf("Regular Task\t\t");
			}
			else if (category == 5)
			{
				printf("Family Task\t\t");
			}


			if(status == 1)
			{
				printf("Pending\t\t");
			}
			else if (status == 2)
			{
				printf("Finish\t\t");
			}

			printf("%s",&tdesc);
		}
	}
	fclose(fp);
}


long int edit_date(long int datedetail)//editr time from edit task
{
	int day, month, year;
	time_t nowdate = time(NULL);


	printf("\n\xDB\xDB\xB2 PLEASE ENTER NEW TASK DAY: ");
	scanf("%d", &day);

	printf("\n\xDB\xDB\xB2 PLEASE ENTER NEW TASK MONTH: ");
	scanf("%d", &month);

	printf("\n\xDB\xDB\xB2 PLEASE ENTER NEW TASK YEAR: ");
	scanf("%d",&year);

	struct tm *DueDateDetail = localtime(&nowdate);
	DueDateDetail->tm_year = year -1900;
	DueDateDetail->tm_mon = month -1;
	DueDateDetail->tm_mday = day;

	time_t NewTime = mktime(DueDateDetail);
	return(NewTime);


}

int edit_cate(int category) //edit category from edit task
{

	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TASK CATEGORY MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\xDB\xDB\xDB\xDB\xB2 1. IMPORTANT TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 2. BUSINESS TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 3. PERSONAL TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 4. REGULAR TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 5. FAMILY TASK\n");

	printf("Please Enter New Task Category: ");
	scanf("%d",&category);
	if (category != 1 && category != 2 && category != 3 && category !=4 && category !=5)
		{
			printf("INVALID INPUT");
			return 1;
		}

	return (category);

}

int edit_status(int status) //edit status from edit task
{
	//printf("New Task Status:\n 1. Pending Task\n 2. Finish Task\n 3. On Progress Task\n");
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TASK STATUS MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\xDB\xDB\xDB\xDB\xB2 1. PENDING TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 2. FINISH TASK\n");
	//printf("\xDB\xDB\xDB\xDB\xB2 3. ON PROGRESS TASK\n");


	printf(" Please Enter New Task Status: ");
	scanf("%d",&status);
	if (status != 1 && status != 2)
		{
			printf("INVALID INPUT");
			return 1;
		}
	return (status);
}


void add_task() //add new task
{
	char tname[25], tdesc[50];
	int category, day, month, year, status;
	long int datedetail;
	FILE *fp;

	fp = fopen("TaskData.txt","r+");

	printf("\n\xDB\xDB\xB2 PLEASE ENTER TASK NAME: ");
	scanf("%s",&tname);

	//printf("Category Level: \n 1. Important \n 2. Business\n 3. Personal \nPlease Enter Your Category Level: ");
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TASK CATEGORY LEVEL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\xDB\xDB\xDB\xDB\xB2 1. IMPORTANT TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 2. BUSINESS TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 3. PERSONAL TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 4. REGULAR TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 5. FAMILY TASK\n");
	printf(" Please Enter Your Task Category Level: ");
	scanf("%d",&category);
	getchar();

	//printf("Task Status: \n 1. Pending\n 2. Finished \nSelect Task Status: ");
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TASK STATUS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\xDB\xDB\xDB\xDB\xB2 1. PENDING TASK\n");
	printf("\xDB\xDB\xDB\xDB\xB2 2. FINISHED TASK\n");
	//printf("\xDB\xDB\xDB\xDB\xB2 3. PROGRESS TASK\n");
	printf(" Please Enter Your Task Status: ");
	scanf("%d",&status);
	getchar();

	printf("\n\xDB\xDB\xB2 PLEASE ENTER TASK DESCRICPTION: \n\t");
	fgets(tdesc,50,stdin);

	printf("\n\xDB\xDB\xB2 PLEASE ENTER TASK DATE: ");
	scanf("%d",&day);
	getchar();

	printf("\n\xDB\xDB\xB2 PLEASE ENTER TASK MONTH: ");
	scanf("%d",&month);
	getchar();

	printf("\n\xDB\xDB\xB2 PLEASE ENTER TASK YEAR: ");
	scanf("%d",&year);
	getchar();

	datedetail = dateformat(day, month, year);

	fseek(fp,0,SEEK_END);
	fprintf(fp,"%s %ld %d %d %s", tname, datedetail, category, status, tdesc);

	fclose(fp);
}

void view_task() //view task menu
{
	int option;

	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VIEW TASKS MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\xDB\xDB\xDB\xDB\xB2 1. VIEW ALL TASKS\n");
	printf("\xDB\xDB\xDB\xDB\xB2 2. SORT BY CATEGORY\n");
	printf("\xDB\xDB\xDB\xDB\xB2 3. SORT BY STATUS\n");
	printf("\n *** Please Input a valid choice *** \n");

	printf(" Please Enter View Task Option: ");
	scanf("%d",&option);
	if(option == 1)
	{
		view_all();
	}
	else if (option == 2)
	{
		view_cate();
	}
	else if (option == 3)
	{
		view_status();
	}
}


void update_task() //edit task menu
{
	char tname[25], tdesc[50], edit_name[25];
	int category, status,option, check;
	long int datedetail;
	FILE *fp;
	FILE *fp2;

	printf("\n\xDB\xDB\xB2 ENTER TASK NAME THAT WANT TO BE EDITED: ");
	scanf("%s",&edit_name);

	fp = fopen ("TaskData.txt","r");
	fp2 = fopen("Tempor.txt","w");

	fseek(fp,0,SEEK_SET);
	while(fscanf (fp,"%s",&tname)!=EOF)
	{
		fscanf(fp,"%ld",&datedetail);
		fscanf(fp,"%d",&category);
		fscanf(fp,"%d",&status);
		fgets(tdesc,50,fp);
		check = 0;

		if(strcmp(tname,edit_name)==0)
		{
			//printf("1. Task Date\n2. Task Category \n3. Task Status \n4. Task Description\n");
			printf("\n\xB2\xB2\xB2\xB2\xB2 EDIT TASK MENU \xB2\xB2\xB2\xB2\xB2\n");
			printf("\xDB\xDB\xDB\xDB\xB2 1. TASK DATE\n");
			printf("\xDB\xDB\xDB\xDB\xB2 2. TASK CATEGORY\n");
			printf("\xDB\xDB\xDB\xDB\xB2 3. TASK STATUS\n");
			printf(" Please Enter Your Option: ");
			scanf("%d",&option);

			if (option == 1)
			{
				datedetail = edit_date(datedetail);
			}
			else if (option == 2)
			{
				category = edit_cate(category);
				if (category == 1)
				{
					continue;
				}

			}
			else if (option == 3)
			{
				status = edit_status(status);
				if (status ==1)
				{
					continue;
				}
			}

		}

		fprintf(fp2, "%s %ld %d %d", tname, datedetail, category, status);

		if(check == 1)
		{
			fprintf(fp2," %s", tdesc);
		}
		else if (check == 0);
		{
			fprintf(fp2,"%s", tdesc);
		}

	}
	fclose(fp2);
	fclose(fp);

	remove("TaskData.txt");
	rename("Tempor.txt","TaskData.txt");

}

void delete_task()//delete task menu
{
	char tname[25], tdesc[50], edit_name[25];
	int category, status,option, check;
	long int datedetail;
	FILE *fp;
	FILE *fp2;
	printf("\n\xDB\xDB\xB2 ENTER TASK NAME TO BE DELETED: ");
	scanf("%s",&edit_name);
	fp = fopen ("TaskData.txt","r");
	fp2 = fopen("Tempor.txt","w");
	fseek(fp,0,SEEK_SET);
	while(fscanf (fp,"%s",&tname)!=EOF)
	{
		fscanf(fp,"%ld",&datedetail);
		fscanf(fp,"%d",&category);
		fscanf(fp,"%d",&status);
		fgets(tdesc,50,fp);
		check = 0;
		if(strcmp(tname,edit_name)==0)
		{
			continue;
		}
		fprintf(fp2, "%s %ld %d %d", tname, datedetail, category, status);
		if(check == 1)
		{
			fprintf(fp2," %s", tdesc);
		}
		else if (check == 0);
		{
			fprintf(fp2,"%s", tdesc);
		}
	}
	fclose(fp2);
	fclose(fp);
	remove("TaskData.txt");
	rename("Tempor.txt","TaskData.txt");
}

int main()
{
	int ch;
	do
	{
		printf("\nDate and Time:\n");
		t();
		//printf("TASK MANAGER SYSTEM\n\n");
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TASK MANAGER MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
		printf("\xDB\xDB\xDB\xDB\xB2 1. ADD NEW TASK\n");
		printf("\xDB\xDB\xDB\xDB\xB2 2. VIEW TASKS\n");
		printf("\xDB\xDB\xDB\xDB\xB2 3. UPDATE TASK\n");
		printf("\xDB\xDB\xDB\xDB\xB2 4. DELETE TASK\n");
		printf("\xDB\xDB\xDB\xDB\xB2 0. EXIT PROGRAM\n");
		printf("\n *** Please Input a valid choice *** \n");
		printf("\n Enter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add_task();
			break;
			case 2:
				view_task();
			break;
			case 3:
				update_task();
			break;
			case 4:
				delete_task();
			break;
			case 0:
				continue;
			default:
				printf("INVALID NUMBER, PLEASE TRY AGAIN\n\n");
		}
	}
	while(ch!=0);
	printf("\t ***** Tasks Manager System *****\n");
    printf("\t **** EUGENE_WINATA TP066869 ****\n");
    printf("\t **** \22\22\22\22\22\22\22\22\22\22\22\22\22\22\22\22\22\22\22\22\22 ****\n");
    printf("\t **** \2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2 ****\n");
	return 0;
}
