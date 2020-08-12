#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)
struct facility
{
	char idFacility[20];
	char typeOfFacility[20];
	char descriptionOfFacility[20];
	char venueOfFacility[20];
	int maximumAllowUser;
};
typedef struct
{

	char todaysdate[20];
	char bookingdate[20];
	char bookingtime[20];
	char bookingtimeuntil[20];
	char facilityName[20];
	char userId[20];
	char facilityId[11];

}facilityUse;


void addBooking();
void searchBooking();
void modifyBooking();
void displayBooking();




void main()

{
	int choice;



	system("cls");
	printf("1- Display\n");
	printf("2- Search\n");
	printf("3- Add\n");
	printf("4- Modify\n");
	scanf("%d", &choice);


	if (choice == 1)
	{
		displayBooking();
	}
	else if (choice == 2)
	{
		searchBooking();
	}
	else if (choice == 3)
	{
		addBooking();
	}
	else if (choice == 4)
	{
		modifyBooking();
	}

	else
		printf("Error.\n");
	system("pause");

}



void addBooking()
{
	int checking = 0, chooseTime;
	char menu;
	char todaysdate[20];
	char bookingdate[20];
	char bookingtime[20];
	char facilityused[20];
	char userId[20];
	char facilityId[11];
	facilityUse checkFacilityUsage;
	facilityUse addFacility;
	rewind(stdin);
	printf("Facility ID :");
	scanf("%[^\n]", &addFacility.facilityId);
	rewind(stdin);
	printf("Facility Name:");
	scanf("%[^\n]", &addFacility.facilityName);
	rewind(stdin);
	printf("User ID :");
	scanf("%[^\n]", &addFacility.userId);
	rewind(stdin);
	printf("Booking Date :");
	scanf("%[^\n]", &addFacility.bookingdate);
	rewind(stdin);
	printf("1. 8.00am - 10.00am\n");
	printf("2. 10.00am - 12.00pm\n");
	printf("3. 12.00pm - 2.00pm\n");
	printf("4. 2.00pm - 4.00pm\n");
	printf("Booking Time Selection (1-4) :");
	scanf("%d", &chooseTime);
	if (chooseTime == 1)
	{
		strcpy(addFacility.bookingtime, "8.00am");
		strcpy(addFacility.bookingtimeuntil, "10.00am");
	}
	else if (chooseTime == 2)
	{
		strcpy(addFacility.bookingtime, "10.00am");
		strcpy(addFacility.bookingtimeuntil, "12.00pm");
	}
	else if (chooseTime == 3)
	{
		strcpy(addFacility.bookingtime, "12.00pm");
		strcpy(addFacility.bookingtimeuntil, "2.00pm");
	}
	else if (chooseTime == 4)
	{
		strcpy(addFacility.bookingtime, "2.00pm");
		strcpy(addFacility.bookingtimeuntil, "4.00pm");
	}

	FILE *addFacility2;
	addFacility2 = fopen("booking.txt", "r");
	if (addFacility2 == NULL)
	{
		printf("File Not Found\n");
		system("pause");
		exit(-1);
	}
	while (fscanf(addFacility2, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &checkFacilityUsage.facilityId, &checkFacilityUsage.facilityName, &checkFacilityUsage.userId, &checkFacilityUsage.bookingdate, &checkFacilityUsage.bookingtime, &checkFacilityUsage.bookingtimeuntil) != EOF)
	{
		if (strcmp(checkFacilityUsage.facilityId, addFacility.facilityId) == 0 && strcmp(checkFacilityUsage.bookingtime, addFacility.bookingtime) == 0 && strcmp(checkFacilityUsage.bookingdate, addFacility.bookingdate) == 0)
		{
			checking += 1;
		}
	}
	fclose(addFacility2);
	addFacility2 = fopen("booking.txt", "a");
	if (addFacility2 == NULL)
	{
		printf("File Not Found\n");
		system("pause");
		exit(-1);
	}
	if (checking != 1)
	{
		printf("Book Successful\n");
		fprintf(addFacility2, "%s:%s:%s:%s:%s:%s", addFacility.facilityId, addFacility.facilityName, addFacility.userId, addFacility.bookingdate, addFacility.bookingtime, addFacility.bookingtimeuntil);

	}
	else
	{
		printf("Facility Booked\n");

	}
	fclose(addFacility2);
	puts("");
	printf("Menu (Y = YES)(N = Exit) :");
	rewind(stdin);
	scanf("%c", &menu);
	if (menu == 'Y' || menu == 'y')
	{
		system("cls");
		main();
	}

}

void modifyBooking()
{
	char menu;
	int chooseTime;
	int i = 0, count = 0, selection, k = 0, makeSure = 0;
	facilityUse bookingFind[999];
	facilityUse inputOld;
	facilityUse inputNew;
	FILE*find;
	find = fopen("booking.txt", "r");
	if (find == NULL)
	{
		printf("File Not Found\n");
		system("cls");
		exit(-1);
	}
	while (fscanf(find, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &bookingFind[i].facilityId, &bookingFind[i].facilityName, &bookingFind[i].userId, &bookingFind[i].bookingdate, &bookingFind[i].bookingtime, &bookingFind[i].bookingtimeuntil) != EOF)
	{
		i++;
		count++;
	}
	fclose(find);

	printf("Modify\n ");
	printf("1. Facility ID\n");
	printf("2. Facility Name\n");
	printf("3. User ID\n");
	printf("4. Booking Date\n");
	printf("5. Booking Time Start\n");
	printf("6. Booking Time End\n");
	printf("Selection :");
	scanf("%d", &selection);

	if (selection == 1)
	{
		printf("Enter Your Facility ID :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.facilityId);

		printf("Enter Your Booking Date :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.bookingdate);
		printf("Booking Time\n");
		printf("1. 8.00am - 10.00am\n");
		printf("2. 10.00am - 12.00pm\n");
		printf("3. 12.00pm - 2.00pm\n");
		printf("4. 2.00pm - 4.00pm\n");
		printf("Booking Time Selection (1-4) :");
		scanf("%d", &chooseTime);
		if (chooseTime == 1)
		{
			strcpy(inputOld.bookingtime, "8.00am");
			strcpy(inputOld.bookingtimeuntil, "10.00am");
		}
		else if (chooseTime == 2)
		{
			strcpy(inputOld.bookingtime, "10.00am");
			strcpy(inputOld.bookingtimeuntil, "12.00pm");
		}
		else if (chooseTime == 3)
		{
			strcpy(inputOld.bookingtime, "12.00pm");
			strcpy(inputOld.bookingtimeuntil, "2.00pm");
		}
		else if (chooseTime == 4)
		{
			strcpy(inputOld.bookingtime, "2.00pm");
			strcpy(inputOld.bookingtimeuntil, "4.00pm");
		}

		for (int j = 0; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == 0 && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == 0 && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == 0)
			{
				printf("Enter Your New Facility ID :");
				rewind(stdin);
				scanf("%[^\n]", inputNew.facilityId);
				strcpy(bookingFind[j].facilityId, inputNew.facilityId);
				makeSure += 1;
			}
		}
	}
	else if (selection == 2)
	{
		printf("Enter Your Facility ID :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.facilityId);

		printf("Enter Your Booking Date :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.bookingdate);

		printf("Booking Time\n");
		printf("1. 8.00am - 10.00am\n");
		printf("2. 10.00am - 12.00pm\n");
		printf("3. 12.00pm - 2.00pm\n");
		printf("4. 2.00pm - 4.00pm\n");
		printf("Booking Time Selection (1-4) :");
		scanf("%d", &chooseTime);
		if (chooseTime == 1)
		{
			strcpy(inputOld.bookingtime, "8.00am");
			strcpy(inputOld.bookingtimeuntil, "10.00am");
		}
		else if (chooseTime == 2)
		{
			strcpy(inputOld.bookingtime, "10.00am");
			strcpy(inputOld.bookingtimeuntil, "12.00pm");
		}
		else if (chooseTime == 3)
		{
			strcpy(inputOld.bookingtime, "12.00pm");
			strcpy(inputOld.bookingtimeuntil, "2.00pm");
		}
		else if (chooseTime == 4)
		{
			strcpy(inputOld.bookingtime, "2.00pm");
			strcpy(inputOld.bookingtimeuntil, "4.00pm");
		}
		for (int j = 0; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == 0 && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == 0 && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == 0)
			{
				printf("Enter Your New Facility Name :");
				rewind(stdin);
				scanf("%[^\n]", inputNew.facilityName);
				strcpy(bookingFind[j].facilityName, inputNew.facilityName);
				makeSure += 1;
			}
		}
	}
	else if (selection == 3)
	{
		printf("Enter Your Facility ID :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.facilityId);

		printf("Enter Your Booking Date :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.bookingdate);

		printf("Booking Time\n");
		printf("1. 8.00am - 10.00am\n");
		printf("2. 10.00am - 12.00pm\n");
		printf("3. 12.00pm - 2.00pm\n");
		printf("4. 2.00pm - 4.00pm\n");
		printf("Booking Time Selection (1-4) :");
		scanf("%d", &chooseTime);
		if (chooseTime == 1)
		{
			strcpy(inputOld.bookingtime, "8.00am");
			strcpy(inputOld.bookingtimeuntil, "10.00am");
		}
		else if (chooseTime == 2)
		{
			strcpy(inputOld.bookingtime, "10.00am");
			strcpy(inputOld.bookingtimeuntil, "12.00pm");
		}
		else if (chooseTime == 3)
		{
			strcpy(inputOld.bookingtime, "12.00pm");
			strcpy(inputOld.bookingtimeuntil, "2.00pm");
		}
		else if (chooseTime == 4)
		{
			strcpy(inputOld.bookingtime, "2.00pm");
			strcpy(inputOld.bookingtimeuntil, "4.00pm");
		}
		for (int j = 0; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == 0 && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == 0 && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == 0)
			{
				printf("Enter Your New User ID :");
				rewind(stdin);
				scanf("%[^\n]", inputNew.userId);
				strcpy(bookingFind[j].userId, inputNew.userId);
				makeSure += 1;
			}
		}
	}
	else if (selection == 4)
	{
		printf("Enter Your Facility ID :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.facilityId);

		printf("Enter Your Booking Date :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.bookingdate);

		printf("Booking Time\n");
		printf("1. 8.00am - 10.00am\n");
		printf("2. 10.00am - 12.00pm\n");
		printf("3. 12.00pm - 2.00pm\n");
		printf("4. 2.00pm - 4.00pm\n");
		printf("Booking Time Selection (1-4) :");
		scanf("%d", &chooseTime);
		if (chooseTime == 1)
		{
			strcpy(inputOld.bookingtime, "8.00am");
			strcpy(inputOld.bookingtimeuntil, "10.00am");
		}
		else if (chooseTime == 2)
		{
			strcpy(inputOld.bookingtime, "10.00am");
			strcpy(inputOld.bookingtimeuntil, "12.00pm");
		}
		else if (chooseTime == 3)
		{
			strcpy(inputOld.bookingtime, "12.00pm");
			strcpy(inputOld.bookingtimeuntil, "2.00pm");
		}
		else if (chooseTime == 4)
		{
			strcpy(inputOld.bookingtime, "2.00pm");
			strcpy(inputOld.bookingtimeuntil, "4.00pm");
		}
		for (int j = 0; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == 0 && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == 0 && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == 0)
			{
				printf("Enter Your New Booking Date :");
				rewind(stdin);
				scanf("%[^\n]", inputNew.bookingdate);
				strcpy(bookingFind[j].bookingdate, inputNew.bookingdate);
				makeSure += 1;
			}
		}
	}
	else if (selection == 5)
	{
		printf("Enter Your Facility ID :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.facilityId);

		printf("Enter Your Booking Date :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.bookingdate);

		printf("Booking Time\n");
		printf("1. 8.00am - 10.00am\n");
		printf("2. 10.00am - 12.00pm\n");
		printf("3. 12.00pm - 2.00pm\n");
		printf("4. 2.00pm - 4.00pm\n");
		printf("Booking Time Selection (1-4) :");
		scanf("%d", &chooseTime);
		if (chooseTime == 1)
		{
			strcpy(inputOld.bookingtime, "8.00am");
			strcpy(inputOld.bookingtimeuntil, "10.00am");
		}
		else if (chooseTime == 2)
		{
			strcpy(inputOld.bookingtime, "10.00am");
			strcpy(inputOld.bookingtimeuntil, "12.00pm");
		}
		else if (chooseTime == 3)
		{
			strcpy(inputOld.bookingtime, "12.00pm");
			strcpy(inputOld.bookingtimeuntil, "2.00pm");
		}
		else if (chooseTime == 4)
		{
			strcpy(inputOld.bookingtime, "2.00pm");
			strcpy(inputOld.bookingtimeuntil, "4.00pm");
		}
		for (int j = 0; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == 0 && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == 0 && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == 0)
			{
				printf("Enter Your New Booking Time(Start) :");
				rewind(stdin);
				scanf("%[^\n]", inputNew.bookingtime);
				strcpy(bookingFind[j].bookingtime, inputNew.bookingtime);
				makeSure += 1;
			}
		}
	}
	else if (selection == 6)
	{
		printf("Enter Your Facility ID :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.facilityId);

		printf("Enter Your Booking Date :");
		rewind(stdin);
		scanf("%[^\n]", &inputOld.bookingdate);

		printf("Booking Time\n");
		printf("1. 8.00am - 10.00am\n");
		printf("2. 10.00am - 12.00pm\n");
		printf("3. 12.00pm - 2.00pm\n");
		printf("4. 2.00pm - 4.00pm\n");
		printf("Booking Time Selection (1-4) :");
		scanf("%d", &chooseTime);
		if (chooseTime == 1)
		{
			strcpy(inputOld.bookingtime, "8.00am");
			strcpy(inputOld.bookingtimeuntil, "10.00am");
		}
		else if (chooseTime == 2)
		{
			strcpy(inputOld.bookingtime, "10.00am");
			strcpy(inputOld.bookingtimeuntil, "12.00pm");
		}
		else if (chooseTime == 3)
		{
			strcpy(inputOld.bookingtime, "12.00pm");
			strcpy(inputOld.bookingtimeuntil, "2.00pm");
		}
		else if (chooseTime == 4)
		{
			strcpy(inputOld.bookingtime, "2.00pm");
			strcpy(inputOld.bookingtimeuntil, "4.00pm");
		}
		for (int j = 0; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == 0 && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == 0 && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == 0)
			{
				printf("Enter Your New Booking Time(END) :");
				rewind(stdin);
				scanf("%[^\n]", inputNew.bookingtimeuntil);
				strcpy(bookingFind[j].bookingtimeuntil, inputNew.bookingtimeuntil);
				makeSure += 1;
			}
		}
	}

	if (makeSure == 1)
	{
		FILE *writeIntoFile;
		writeIntoFile = fopen("booking.txt", "w");
		for (k = 0; k < count; k++)
		{
			fprintf(writeIntoFile, "%s:%s:%s:%s:%s:%s", bookingFind[k].facilityId, bookingFind[k].facilityName, bookingFind[k].userId, bookingFind[k].bookingdate, bookingFind[k].bookingtime, bookingFind[k].bookingtimeuntil);
		}
	}
	puts("");
	rewind(stdin);
	printf("Menu (Y = YES)(N = Exit) :");
	rewind(stdin);
	scanf("%c", &menu);
	if (menu == 'Y' || menu == 'y')
	{
		system("cls");
		main();
	}

}


void searchBooking()
{
	char menu;
	facilityUse searchInput;
	facilityUse search;


	FILE*find;
	find = fopen("booking.txt", "r");
	if (find == NULL)
	{
		printf("FILE Not Found\n");
		system("pause");
		exit(-1);
	}
	printf("Please enter the Facility ID that you want to search :");
	rewind(stdin);
	scanf("%[^\n]", &searchInput.facilityId);


	printf("Please enter the Date that you want to search :");
	rewind(stdin);
	scanf("%[^\n]", &searchInput.bookingdate);


	while (fscanf(find, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &search.facilityId, &search.facilityName, &search.userId, &search.bookingdate, &search.bookingtime, &search.bookingtimeuntil) != EOF)
	{
		if (strcmp(searchInput.facilityId, search.facilityId) == 0 && strcmp(searchInput.bookingdate, search.bookingdate) == 0)
		{
			printf("Facility ID :%s\n", search.facilityId);
			printf("Facility Name :%s\n", search.facilityName);
			printf("User ID :%s\n", search.userId);
			printf("Booking Date :%s\n", search.bookingdate);
			printf("Booking Time: %s - %s\n", search.bookingtime, search.bookingtimeuntil);
		}
	}
	fclose(find);
	printf("Menu (Y = YES)(N = Exit) :");
	rewind(stdin);
	scanf("%c", &menu);
	if (menu == 'Y' || menu == 'y')
	{
		system("cls");
		main();
	}

}

void displayBooking()
{
	char menu;
	facilityUse display;
	FILE* displayuse;
	displayuse = fopen("booking.txt", "r");
	if (displayuse == NULL)
	{
		printf("FILE Not Found\n");
		system("pause");
		exit(-1);
	}
	printf("Booking Display\n");
	while (fscanf(displayuse, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &display.facilityId, &display.facilityName, &display.userId, &display.bookingdate, &display.bookingtime, &display.bookingtimeuntil) != EOF)
	{
		printf("%s:%s:%s:%s:%s-%s\n", display.facilityId, display.facilityName, display.userId, display.bookingdate, display.bookingtime, display.bookingtimeuntil);
		puts("");
	}
	puts("");
	printf("Menu (Y = YES)(N = Exit) :");
	rewind(stdin);
	scanf("%c", &menu);
	if (menu == 'Y' || menu == 'y')
	{
		system("cls");
		main();
	}

}


