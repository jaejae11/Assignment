//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#pragma warning(disable:4996) 
//
//#define MAXSIZE 100
//
//void addBooking();
//void searchBooking();
//void modifyBooking();
//void modifyInfo();
//void deleteInfo();
//void displayBooking();
//void searchByBookingID();
//void searchByUserID();
//void generateBookingID(struct Booking*ID);
//char validationBookingDate(int day, int month, int year);
//char idBookvalidation(int strlength, char search[50], char id[50], int day, int month, int year, int session);
//
//typedef struct {
//	int day;
//	int month;
//	int year;
//}Date;
//struct Booking {
//	char bookingID[6];
//	Date today;
//	Date booking;
//	int bookingHour;
//	char userID[11];
//	char facilityID[6];
//};
//
//void main()
//{
//	int choice;
//
//	//printf("Menu\n");
//	//printf("+--------+----------+\n");
//	//printf("| Choice |  Module  |\n");
//	//printf("+--------+----------+\n");
//	//printf("|      1 | Staff    |\n");
//	//printf("|      2 | Facility |\n");
//	//printf("|      3 | User     |\n");
//	//printf("|      4 | Booking  |\n");
//	//printf("|      5 | Facility |\n");
//	//printf("|      6 | Exit     |\n");
//	//printf("+--------+----------+\n");
//	printf("+--------+----------+\n");
//	printf("| Choice | Function |\n");
//	printf("+--------+----------+\n");
//	printf("|      1 | Add      |\n");
//	printf("|      2 | Search   |\n");
//	printf("|      3 | Modify   |\n");
//	printf("|      4 | Display  |\n");
//	printf("|      5 | Exit     |\n");
//	printf("+--------+----------+\n");
//	printf("Enter the number of function>");
//	scanf("%d", &choice);
//	while (choice != 5)
//	{
//		switch (choice)
//		{
//		case 1:
//			addBooking();
//			break;
//		case 2:
//			searchBooking();
//			break;
//		case 3:
//			modifyBooking();
//			break;
//		case 4:
//			displayBooking();
//			break;
//		default:
//			printf("Invalid Choice!! Please re enter your choice.\n");
//		}
//		printf("+--------+----------+\n");
//		printf("| Choice | Function |\n");
//		printf("+--------+----------+\n");
//		printf("|      1 | Add      |\n");
//		printf("|      2 | Search   |\n");
//		printf("|      3 | Modify   |\n");
//		printf("|      4 | Display  |\n");
//		printf("|      5 | Exit     |\n");
//		printf("+--------+----------+\n");
//		printf("Enter the number of function>");
//		scanf("%d", &choice);
//	}
//	system("pause");
//}
//void addBooking()
//{
//	char result, valid, confirm, choice, ID[6];
//	int i;
//	time_t t = time(NULL);
//	struct tm tm = *localtime(&t);
//	FILE*fptr;
//	FILE*fu;
//	struct Booking buffer;
//	struct Booking info[MAXSIZE];
//	do
//	{
//		fptr = fopen("booking.txt", "a");
//		fu = fopen("facilityUsage.bin", "ab");
//		if (fptr == NULL || fu == NULL)
//		{
//			printf("\aUnable to open file\n");
//			system("pause");
//			exit(-1);
//		}
//		do
//		{
//
//			generateBookingID(&ID);
//			strcpy(buffer.bookingID, ID);
//			printf("%-25s>%s\n", "Booking ID", buffer.bookingID);
//
//			buffer.today.day = tm.tm_mday;
//			buffer.today.month = tm.tm_mon + 1;
//			buffer.today.year = tm.tm_year + 1900;
//
//			printf("%-25s>%d/%d/%d  \n", "Today Date", buffer.today.day, buffer.today.month, buffer.today.year);
//			do {
//				printf("%-25s>", "Booking Date(dd mm yyyy)");
//				scanf("%d %d %d", &buffer.booking.day, &buffer.booking.month, &buffer.booking.year);
//				result = validationBookingDate(buffer.booking.day, buffer.booking.month, buffer.booking.year);
//			} while (result == 'n');
//			system("cls");
//			do {
//				printf("\nSelect 1 session\n");
//				printf("+---------+-----------------+\n");
//				printf("| Session |      Time       |\n");
//				printf("+---------+-----------------+\n");
//				printf("|       1 | 9:00am -11:00am |\n");
//				printf("|       2 | 11:00am-1:00pm  |\n");
//				printf("|       3 | 1:00pm -3:00pm  |\n");
//				printf("|       4 | 3:00pm -5:00pm  |\n");
//				printf("|       5 | 5:00pm -7:00pm  |\n");
//				printf("+---------+-----------------+\n");
//				printf("%-25s>", "Booking session");
//				scanf("%d", &buffer.bookingHour);
//			} while (buffer.bookingHour < 1 || buffer.bookingHour>5);
//			printf("%-25s>", "Facility ID");//jordan
//			scanf(" %s", &buffer.facilityID);
//			strupr(buffer.facilityID);
//			printf("%-25s>", "User ID");//wenyi
//			scanf(" %s", &buffer.userID);
//			strupr(buffer.userID);
//			system("cls");
//			valid = idBookvalidation(10, buffer.userID, buffer.facilityID, buffer.booking.day, buffer.booking.month, buffer.booking.year, buffer.bookingHour);
//		} while (valid == 'n');
//
//		system("cls");
//		printf("%-20s>%s\n", "Booking ID", buffer.bookingID);
//		printf("%-20s>%02d/%02d/%d\n", "Today Date", buffer.today.day, buffer.today.month, buffer.today.year);
//		printf("%-20s>%02d/%02d/%d\n", "Booking Date", buffer.booking.day, buffer.booking.month, buffer.booking.year);
//		switch (buffer.bookingHour)
//		{
//		case 1:
//			printf("%-20s>Session %d (9.00am-11.00am)\n", "Booking Hour", buffer.bookingHour);
//			break;
//		case 2:
//			printf("%-20s>Session %d (11.00am-1.00pm)\n", "Booking Hour", buffer.bookingHour);
//			break;
//		case 3:
//			printf("%-20s>Session %d (1.00pm-3.00pm)\n", "Booking Hour", buffer.bookingHour);
//			break;
//		case 4:
//			printf("%-20s>Session %d (3.00pm-5.00pm)\n", "Booking Hour", buffer.bookingHour);
//			break;
//		case 5:
//			printf("%-20s>Session %d (5.00pm-7.00pm)\n", "Booking Hour", buffer.bookingHour);
//			break;
//		}
//		printf("%-20s>%s\n", "Facility ID", buffer.facilityID);
//		printf("%-20s>%s\n\n", "User ID", buffer.userID);
//
//		printf("Confirm Booking?(Y=yes/N=no)>");
//		scanf(" %c", &confirm);
//		if (toupper(confirm) == 'Y')
//		{
//			i = 0;
//			info[i] = buffer;
//			fprintf(fptr, "%s|%02d/%02d/%d|%02d/%02d/%d|%d|%s|%s\n", info[i].bookingID, info[i].today.day, info[i].today.month, info[i].today.year, info[i].booking.day, info[i].booking.month, info[i].booking.year, info[i].bookingHour, info[i].userID, info[i].facilityID);
//			fprintf(fu, "%d/%d/%d|%d|%s|%s|%s", info[i].booking.day, info[i].booking.month, info[i].booking.year, info[i].bookingHour, info[i].userID, info[i].facilityID, "Booked");
//			printf("Done!\n");
//			i++;
//		}
//		fclose(fu);
//		fclose(fptr);
//		printf("Add another Booking?(Y=yes/N=no)>");
//		scanf(" %c", &choice);
//		system("cls");
//	} while (toupper(choice) == 'Y');
//}
//void searchBooking()
//{
//	int choice;
//	char confirm;
//	do
//	{
//		system("cls");
//		printf("+--------+------------+\n");
//		printf("| Choice | Search By  |\n");
//		printf("+--------+------------+\n");
//		printf("|      1 | Booking ID |\n");
//		printf("|      2 | User ID    |\n");
//		printf("|      3 | Exit       |\n");
//		printf("+--------+------------+\n");
//		printf("Enter your choice>");
//		scanf("%d", &choice);
//		system("cls");
//		switch (choice)
//		{
//		case 1:
//			searchByBookingID();
//			break;
//		case 2:
//			searchByUserID();
//			break;
//		}
//		printf("Do you want to search again?(Y=yes)>");
//		scanf(" %c", &confirm);
//	} while (toupper(confirm) == 'Y');
//}
//void modifyBooking()
//{
//	int choice;
//	char confirm;
//	system("cls");
//	do
//	{
//		printf("+--------+-------------+\n");
//		printf("| Choice |   Modify    |\n");
//		printf("+--------+-------------+\n");
//		printf("|      1 | Modify Info |\n");
//		printf("|      2 | Delete Info |\n");
//		printf("|      3 | Exit        |\n");
//		printf("+--------+-------------+\n");
//		printf("Enter your choice>");
//		scanf("%d", &choice);
//		switch (choice)
//		{
//		case 1:
//			modifyInfo();
//			break;
//		case 2:
//			deleteInfo();
//			break;
//		}
//		printf("Do you want to modify/delete other record?(Y=yes)>");
//		scanf(" %c", &confirm);
//	} while (toupper(confirm) == 'Y');
//}
//void modifyInfo()
//{
//	struct Booking info[MAXSIZE];
//	struct Booking buffer;
//	FILE*fptr;
//	FILE*fptr2;
//	int i, count, choice, no;
//	char valid, valid2, confirm, id[30], invalid = 'n';
//
//	searchBooking();
//	do
//	{
//		printf("Enter Booking ID that you wanted to modify(exit=-1)>");
//		scanf(" %s", &id);
//		strupr(id);
//		if (strcmp("-1", id) != 0)
//		{
//			if (strlen(id) == 5)
//			{
//				fptr = fopen("booking.txt", "r");
//				if (fptr == NULL)
//				{
//					printf("Unable to open file\n");
//					exit(-1);
//				}
//				count = 0;
//				i = 0;
//				while (fscanf(fptr, "%[^\|]|%d/%d/%d|%d/%d/%d|%d|%[^\|]|%[^\n]\n", &info[i].bookingID, &info[i].today.day, &info[i].today.month, &info[i].today.year, &info[i].booking.day, &info[i].booking.month, &info[i].booking.year, &info[i].bookingHour, &info[i].userID, &info[i].facilityID) != EOF)
//				{
//					if (strcmp(info[i].bookingID, id) == 0)
//					{
//						buffer = info[i];
//						no = i;
//					}
//					i++;
//					count++;
//				}
//				fclose(fptr);
//				do
//				{
//					do
//					{
//						printf("+--------+--------------+\n");
//						printf("| Choice |     Info     |\n");
//						printf("+--------+--------------+\n");
//						printf("|      1 | Booking Date |\n");
//						printf("|      2 | Booking Hour |\n");
//						printf("|      3 | Exit         |\n");
//						printf("+--------+--------------+\n");
//						printf("Enter the choice of the info that want to rectify>");
//						scanf("%d", &choice);
//						while (choice != 3)
//						{
//							switch (choice)
//							{
//							case 1:
//							{
//								do
//								{
//									printf("Enter New Booking Date(dd mm yyyy)>");
//									scanf("%d %d %d", &buffer.booking.day, &buffer.booking.month, &buffer.booking.year);
//									valid = validationBookingDate(buffer.booking.day, buffer.booking.month, buffer.booking.year);
//								} while (valid == 'n');
//								break;
//							}
//							case 2:
//							{
//								printf("\nSelect 1 session\n");
//								printf("+---------+-----------------+\n");
//								printf("| Session |      Time       |\n");
//								printf("+---------+-----------------+\n");
//								printf("|       1 | 9:00am -11:00am |\n");
//								printf("|       2 | 11:00am-1:00pm  |\n");
//								printf("|       3 | 1:00pm -3:00pm  |\n");
//								printf("|       4 | 3:00pm -5:00pm  |\n");
//								printf("|       5 | 5:00pm -7:00pm  |\n");
//								printf("+---------+-----------------+\n");
//								printf("Enter New Booking Session>");
//								scanf("%d", &buffer.bookingHour);
//								break;
//							}
//							}
//							printf("+--------+--------------+\n");
//							printf("| Choice |     Info     |\n");
//							printf("+--------+--------------+\n");
//							printf("|      1 | Booking Date |\n");
//							printf("|      2 | Booking Hour |\n");
//							printf("|      3 | Exit         |\n");
//							printf("+--------+--------------+\n");
//							printf("Enter the choice of the info that want to rectify>");
//							scanf("%d", &choice);
//						}
//						system("cls");
//						printf("Edited Record\n");
//						printf("------------------\n");
//						printf("%-20s>%s\n", "Booking ID", buffer.bookingID);
//						printf("%-20s>%02d/%02d/%d\n", "Today Date", buffer.today.day, buffer.today.month, buffer.today.year);
//						printf("%-20s>%02d/%02d/%d\n", "Booking Date", buffer.booking.day, buffer.booking.month, buffer.booking.year);
//						switch (buffer.bookingHour)
//						{
//						case 1:
//							printf("%-20s>Session %d (9.00am-11.00am)\n", "Booking Hour", buffer.bookingHour);
//							break;
//						case 2:
//							printf("%-20s>Session %d (11.00am-1.00pm)\n", "Booking Hour", buffer.bookingHour);
//							break;
//						case 3:
//							printf("%-20s>Session %d (1.00pm-3.00pm)\n", "Booking Hour", buffer.bookingHour);
//							break;
//						case 4:
//							printf("%-20s>Session %d (3.00pm-5.00pm)\n", "Booking Hour", buffer.bookingHour);
//							break;
//						case 5:
//							printf("%-20s>Session %d (5.00pm-7.00pm)\n", "Booking Hour", buffer.bookingHour);
//							break;
//						}
//						printf("%-20s>%s\n", "Facility ID", buffer.facilityID);
//						printf("%-20s>%s\n", "User ID", buffer.userID);
//						printf("\n\n Save record?(Y=yes)");
//						scanf(" %c", &confirm);
//					} while (toupper(confirm) != 'Y');
//					valid2 = idBookvalidation(10, buffer.userID, buffer.facilityID, buffer.booking.day, buffer.booking.month, buffer.booking.year, buffer.bookingHour);
//				} while (valid2 == 'n');
//				info[no] = buffer;
//				fptr2 = fopen("booking.txt", "w");
//				if (fptr2 == NULL)
//				{
//					printf("Unable to open file\n");
//					exit(-1);
//				}
//				for (i = 0; i < count; i++)
//				{
//					fprintf(fptr2, "%s|%02d/%02d/%d|%02d/%02d/%d|%d|%s|%s\n", info[i].bookingID, info[i].today.day, info[i].today.month, info[i].today.year, info[i].booking.day, info[i].booking.month, info[i].booking.year, info[i].bookingHour, info[i].userID, info[i].facilityID);
//				}
//				fclose(fptr2);
//			}
//			else
//			{
//				printf("Invalid ID!\n");
//				invalid = 'y';
//			}
//		}
//	}while (invalid == 'y');
//}
//void deleteInfo()
//{
//	struct Booking info[MAXSIZE];
//	FILE*fptr;
//	FILE*fptr2;
//	int count, i, j, no;
//	char confirm, id[30], invalid = 'n';
//	searchBooking();
//	do
//	{
//		printf("Enter Booking ID that you wanted to delete(exit=-1)>");
//		scanf(" %s", &id);
//		strupr(id);
//		if (strcmp("-1", id) != 0)
//		{
//			if (strlen(id) == 5)
//			{
//				fptr = fopen("booking.txt", "r");
//				if (fptr == NULL)
//				{
//					printf("Unable to open file\n");
//					exit(-1);
//				}
//				i = 0;
//				j = 0;
//				count = 0;
//				while (fscanf(fptr, "%[^\|]|%d/%d/%d|%d/%d/%d|%d|%[^\|]|%[^\n]\n", &info[i].bookingID, &info[i].today.day, &info[i].today.month, &info[i].today.year, &info[i].booking.day, &info[i].booking.month, &info[i].booking.year, &info[i].bookingHour, &info[i].userID, &info[i].facilityID) != EOF)
//				{
//					if (strcmp(info[i].bookingID, id) == 0)
//					{
//						no = i;
//						j++;
//					}
//					i++;
//					count++;
//				}
//				fclose(fptr);
//				if (j != 0)
//				{
//					for (i = no; i < count - 1; i++)
//					{
//						info[i] = info[i + 1];
//					}
//					printf("Record %s had been deleted\n", id);
//					fptr2 = fopen("booking.txt", "w");
//					if (fptr2 == NULL)
//					{
//						printf("Unable to open file\n");
//						exit(-1);
//					}
//					for (i = 0; i < count - 1; i++)
//					{
//						fprintf(fptr2, "%s|%02d/%02d/%d|%02d/%02d/%d|%d|%s|%s\n", info[i].bookingID, info[i].today.day, info[i].today.month, info[i].today.year, info[i].booking.day, info[i].booking.month, info[i].booking.year, info[i].bookingHour, info[i].userID, info[i].facilityID);
//					}
//					fclose(fptr2);
//				}
//				else
//				{
//					printf("\aUnable to delete record!\n");
//				}
//			}
//			else
//			{
//				printf("Invalid ID\n");
//				invalid = 'y';
//			}
//		}
//	} while (invalid == 'y');
//}
//void displayBooking()
//{
//	FILE*fptr;
//	struct Booking info[MAXSIZE];
//	int i;
//	char session[30];
//
//	fptr = fopen("booking.txt", "r");
//	if (fptr == NULL)
//	{
//		printf("Unable to open file\n");
//		exit(-1);
//		system("pause");
//	}
//	system("cls");
//	printf("%-13s%-11s%-15s%-25s%-10s%-10s\n", "Booking ID", "Date", "Booking Date", "Booking Time(Session)", "User ID", "Facility ID");
//	printf("======================================================================================\n");
//	i = 0;
//	while (fscanf(fptr, "%[^\|]|%d/%d/%d|%d/%d/%d|%d|%[^\|]|%[^\n]\n", &info[i].bookingID, &info[i].today.day, &info[i].today.month, &info[i].today.year, &info[i].booking.day, &info[i].booking.month, &info[i].booking.year, &info[i].bookingHour, &info[i].userID, &info[i].facilityID) != EOF)
//	{
//		switch (info[i].bookingHour)
//		{
//		case 1:
//			strcpy(session, "(9.00am - 11.00am)");
//			break;
//		case 2:
//			strcpy(session, "(11.00am-1.00pm)");
//			break;
//		case 3:
//			strcpy(session, "(1.00pm-3.00pm)");
//			break;
//		case 4:
//			strcpy(session, "(3.00pm-5.00pm)");
//			break;
//		case 5:
//			strcpy(session, "(5.00pm-7.00pm)");
//			break;
//		}
//		printf("%s%6s%-02d/%-02d/%d%3s%-02d/%-02d/%-6d %d%-23s %-12s%s\n", info[i].bookingID, "", info[i].today.day, info[i].today.month, info[i].today.year, "", info[i].booking.day, info[i].booking.month, info[i].booking.year, info[i].bookingHour, session, info[i].userID, info[i].facilityID);
//		i++;
//	}
//	printf("\t%d record found\n\n", i);
//	fclose(fptr);
//	system("pause");
//}
//void searchByBookingID()
//{
//	struct Booking info[MAXSIZE];
//	FILE*fptr;
//	int i, count = 0;
//	char searchBookingInfo[20];
//	char session[20];
//	fptr = fopen("booking.txt", "r");
//	if (fptr == NULL)
//	{
//		printf("\aUnable to open file\n");
//		exit(-1);
//	}
//	do
//	{
//		printf("Search Booking ID(Bxxxx):");
//		scanf(" %s", &searchBookingInfo);
//		strupr(searchBookingInfo);
//	} while (strlen(searchBookingInfo) != 5);
//	i = 0;
//	printf("%-13s%-11s%-15s%-25s%-10s%-10s\n", "Booking ID", "Date", "Booking Date", "Booking Time(Session)", "User ID", "Facility ID");
//	printf("======================================================================================\n");
//	while (fscanf(fptr, "%[^\|]|%d/%d/%d|%d/%d/%d|%d|%[^\|]|%[^\n]\n", &info[i].bookingID, &info[i].today.day, &info[i].today.month, &info[i].today.year, &info[i].booking.day, &info[i].booking.month, &info[i].booking.year, &info[i].bookingHour, &info[i].userID, &info[i].facilityID) != EOF)
//	{
//		if (strcmp(info[i].bookingID, searchBookingInfo) == 0)
//		{
//			switch (info[i].bookingHour)
//			{
//			case 1:
//				strcpy(session, "(9.00am -11.00am)");
//				break;
//			case 2:
//				strcpy(session, "(11.00am-1.00pm)");
//				break;
//			case 3:
//				strcpy(session, "(1.00pm-3.00pm)");
//				break;
//			case 4:
//				strcpy(session, "(3.00pm-5.00pm)");
//				break;
//			case 5:
//				strcpy(session, "(5.00pm-7.00pm)");
//				break;
//			}
//			printf("%s%6s%-02d/%-02d/%d%3s%-02d/%-02d/%-6d %d%-23s %-12s%s\n", info[i].bookingID, "", info[i].today.day, info[i].today.month, info[i].today.year, "", info[i].booking.day, info[i].booking.month, info[i].booking.year, info[i].bookingHour, session, info[i].userID, info[i].facilityID);
//			count++;
//		}
//		i++;
//	}
//	fclose(fptr);
//	printf("--------------------------------------------------------------------------------------\n");
//	printf("\t %d record found\n", count);
//}
//void searchByUserID()
//{
//	struct Booking info[MAXSIZE];
//	FILE*fptr;
//	int i, count = 0;
//	char searchBookingInfo[20];
//	char session[20];
//	fptr = fopen("booking.txt", "r");
//	if (fptr == NULL)
//	{
//		printf("\aUnable to open file\n");
//		exit(-1);
//	}
//	do
//	{
//		printf("Search User ID:");
//		scanf(" %s", &searchBookingInfo);
//		strupr(searchBookingInfo);
//	} while (strlen(searchBookingInfo) != 10);
//	i = 0;
//	printf("%-13s%-11s%-15s%-25s%-10s%-10s\n", "Booking ID", "Date", "Booking Date", "Booking Time(Session)", "User ID", "Facility ID");
//	printf("======================================================================================\n");
//	while (fscanf(fptr, "%[^\|]|%d/%d/%d|%d/%d/%d|%d|%[^\|]|%[^\n]\n", &info[i].bookingID, &info[i].today.day, &info[i].today.month, &info[i].today.year, &info[i].booking.day, &info[i].booking.month, &info[i].booking.year, &info[i].bookingHour, &info[i].userID, &info[i].facilityID) != EOF)
//	{
//		if (strcmp(info[i].userID, searchBookingInfo) == 0)
//		{
//			switch (info[i].bookingHour)
//			{
//			case 1:
//				strcpy(session, "(9.00am - 11.00am)");
//				break;
//			case 2:
//				strcpy(session, "(11.00am-1.00pm)");
//				break;
//			case 3:
//				strcpy(session, "(1.00pm-3.00pm)");
//				break;
//			case 4:
//				strcpy(session, "(3.00pm-5.00pm)");
//				break;
//			case 5:
//				strcpy(session, "(5.00pm-7.00pm)");
//				break;
//			}
//			printf("%s%6s%-02d/%-02d/%d%3s%-02d/%-02d/%-6d %d%-23s %-12s%s\n", info[i].bookingID, "", info[i].today.day, info[i].today.month, info[i].today.year, "", info[i].booking.day, info[i].booking.month, info[i].booking.year, info[i].bookingHour, session, info[i].userID, info[i].facilityID);
//			count++;
//		}
//		i++;
//	}
//	fclose(fptr);
//	printf("--------------------------------------------------------------------------------------\n");
//	printf("\t %d record found\n", count);
//}
//void generateBookingID(struct Booking*ID)
//{
//	int i, count;
//	FILE*fptr;
//	struct Booking info[MAXSIZE];
//
//	fptr = fopen("booking.txt", "r");
//	if (fptr == NULL)
//	{
//		printf("Unable to open file\n");
//		exit(-1);
//	}
//	i = 0;
//	while (fscanf(fptr, "%[^\|]|%d/%d/%d|%d/%d/%d|%d|%[^\|]|%[^\n]\n", &info[i].bookingID, &info[i].today.day, &info[i].today.month, &info[i].today.year, &info[i].booking.day, &info[i].booking.month, &info[i].booking.year, &info[i].bookingHour, &info[i].userID, &info[i].facilityID) != EOF)
//	{
//		i++;
//	}
//	fclose(fptr);
//
//	count = i;
//	strcpy(ID, "B0000");
//	if (count >= 1 && count <= 9)
//	{
//		ID->bookingID[4] += count;
//	}
//	else if (count <= 99)
//	{
//		ID->bookingID[4] += count % 10;
//		ID->bookingID[3] += count / 10;
//	}
//	else if (count <= 999)
//	{
//		ID->bookingID[4] += count % 10;
//		ID->bookingID[3] += (count / 10) % 10;
//		ID->bookingID[2] += count / 100;
//	}
//	else
//	{
//		ID->bookingID[4] += count % 10;
//		ID->bookingID[3] += (count / 10) % 10;
//		ID->bookingID[2] += (count / 100) % 100;
//		ID->bookingID[1] += count / 1000;
//	}
//}
//char validationBookingDate(int day, int month, int year)
//{
//	int i;
//	char valid;
//	time_t t = time(NULL);
//	struct tm tm = *localtime(&t);
//
//
//	switch (month)
//	{
//	case 2:
//		if (year % 4 == 0)
//		{
//			if (day >= 1 || day <= 29)
//			{
//				valid = 'y';
//			}
//			else
//			{
//				printf("error.\n");
//				valid = 'n';
//			}
//		}
//		else
//		{
//			if (day >= 1 || day <= 28)
//			{
//				valid = 'y';
//			}
//			else
//			{
//				printf("error.\n");
//				valid = 'n';
//			}
//		}
//		break;
//	case 4:
//	case 6:
//	case 9:
//	case 11:
//		if (day >= 1 || day <= 30)
//		{
//			valid = 'y';
//		}
//		else
//		{
//			printf("error.\n");
//			valid = 'n';
//		}
//		break;
//	case 1:
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:
//		if (day >= 1 || day <= 31)
//		{
//			valid = 'y';
//		}
//		else
//		{
//			printf("error.\n");
//			valid = 'n';
//		}
//		break;
//	default:
//		printf("error.\n");
//	}
//
//	if (year - (tm.tm_year + 1900) > 0)
//	{
//		valid = 'y';
//	}
//	else if (year - (tm.tm_year + 1900) == 0)
//	{
//		if (month == tm.tm_mon + 1)
//		{
//			if (day > tm.tm_mday)
//			{
//				valid = 'y';
//			}
//			else
//			{
//				printf("error.\n");
//				valid = 'n';
//			}
//		}
//		else if (month > tm.tm_mon + 1)
//		{
//			valid = 'y';
//		}
//		else
//		{
//			printf("error.\n");
//			valid = 'n';
//		}
//	}
//	else
//	{
//		printf("error.\n");
//		valid = 'n';
//	}
//	return valid;
//}
//char idBookvalidation(int strlength, char search[50], char id[50], int day, int month, int year, int session)
//{
//	char valid = 'y';
//	int i;
//	FILE*fptr;
//	struct Booking info[MAXSIZE];
//	struct Booking buffer;
//	fptr = fopen("booking.txt", "r");
//	if (fptr == NULL)
//	{
//		printf("\aUnable to open file\n");
//		exit(-1);
//	}
//	i = 0;
//	while (fscanf(fptr, "%[^\|]|%d/%d/%d|%d/%d/%d|%d|%[^\|]|%[^\n]\n", &info[i].bookingID, &info[i].today.day, &info[i].today.month, &info[i].today.year, &info[i].booking.day, &info[i].booking.month, &info[i].booking.year, &info[i].bookingHour, &info[i].userID, &info[i].facilityID) != EOF)
//	{
//		if (strcmp(info[i].facilityID, id)==0)
//		{
//			if (info[i].booking.year == year)
//			{
//				if (info[i].booking.month == month)
//				{
//					if (info[i].booking.day == day)
//					{
//						if (info[i].bookingHour == session)
//						{
//							if (strlen(search) == strlength)
//							{
//								if (strcmp(info[i].userID, search) == 0)
//								{
//									printf("You had booked the facility in same session\n");
//									printf("Please re-enter\n");
//									return valid = 'n';
//								}
//							}
//							else
//							{
//								printf("This facility is booked by other user\n");
//								return valid = 'n';
//							}
//						}
//					}
//				}
//			}
//			i++;
//		}
//	}
//	fclose(fptr);
//	return valid;
//}
