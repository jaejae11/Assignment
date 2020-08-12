#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
#define TWELVE 12

typedef struct
{
	char iD[11];
	char name[20];
	char gender;
	int age;
	char iC[15];
	char contactNumber[20];
	char password[20];
	char student[8];
}UserInformation;

typedef struct
{
	char passWord[20];
	char ID[10];
} loginInformation;
typedef struct
{
	char name[30];
	char gender;
	char contactNumber[15];
	loginInformation require;
}StaffInformationDetail;

typedef struct
{
	char idInput[20];
}facilityUsage2;
typedef struct
{

	char todaysdate[20];
	char bookingdate[20];
	char bookingtime[20];
	char bookingtimeuntil[20];
	char facilityName[20];
	char userId[20];
	char facilityId[11];
	char walkinORonline[20];
	char walkinOROnlineTime[20];
	facilityUsage2 finding;
}facilityUsage;

typedef struct
{


	char bookingdate[20];
	char bookingtime[20];
	char bookingtimeuntil[20];
	char facilityName[20];
	char userId[20];
	char facilityId[11];

}bookingUse;

typedef struct
{
	char facilityID[20];
	char facilityType[50];
	char facilityDesc[100];
	char facilityVenue[50];
	int totalUsers;

}Facility;

void staffInformationModules();
int staffRegister();
int staffLogin();
int staffSearch(StaffInformationDetail searchFunction);
int staffModify(StaffInformationDetail modifyFunction);
int staffDisplay(StaffInformationDetail displayFunction);
int loginedMenu(StaffInformationDetail loginDetail);
int staffinformationMenu(StaffInformationDetail loginDetail);

int selectMenu();
void logoThankyou();
void logoModify();
void logodisplay();
void logoSearch();
void logoFailed();
void logoLogin();
void logoUserInformation();
void logoSignUp();
void successful();
void afterLoginMenuLogo();
int addUserInformation();
int loginUserInformation();
int modifyUserInformation(UserInformation modifyUserInfo);
int displayUserInformation(UserInformation displayUserInfo);
int searchUserInformation(UserInformation searchingFunction);
int editMenu(UserInformation login);
void afterloginMenu(UserInformation login);
void userInformationModule();

int facilityUsageModules();
void addFacilityUsage();
void modifyFacilityUsage();
void displayFacilityUsage();
void searchFacilityUsage();

void addBooking();
void searchBooking();
void modifyBooking();
void displayBooking();
int bookingModules();


void modifyFacilitySub(int i, Facility facilityMenu[30]);
void searchFacility();
void modifyFacility();
void addFacility();
int facilityModules();
int facilityMenu();
void displayFacility();

int loginedMenu(StaffInformationDetail loginDetail);
void afterloginMenu(UserInformation login);
int checkingUserSelection(int userInputForChecking, int correctSelection);
void mainLogo();

void main()
{
	int choice;
	do
	{
		system("cls");
		mainLogo();
		printf("1. Staff\n");
		printf("2. Student\n");
		printf("3. Exit\n");
		printf("Selection :");
		scanf("%d", &choice);
	} while (!checkingUserSelection(choice, THREE));
	if (choice == ONE)
	{
		system("cls");
		staffInformationModules();
	}
	else if (choice == TWO)
	{
		system("cls");
		userInformationModule();
	}
	else
	{
		system("cls");
		logoThankyou();
		system("pause");
		exit(-1);
	}
}
void mainLogo()
{
	printf("   _____                      _             ____                     _    _____           _                 \n");
	printf("  / ____|                    | |           |  _ \\                   | |  / ____|         | |               \n");
	printf(" | |     ___  _ __  ___  ___ | | ___ ______| |_) | __ _ ___  ___  __| | | (___  _   _ ___| |_ ___ _ __ ___  \n");
	printf(" | |    / _ \\| '_ \\/ __|/ _ \\| |/ _ \\______|  _ < / _` / __|/ _ \\/ _` |  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n");
	printf(" | |___| (_) | | | \\__ \\ (_) | |  __/      | |_) | (_| \\__ \\  __/ (_| |  ____) | |_| \\__ \\ ||  __/ | | | | |\n");
	printf("  \\_____\\___/|_| |_|___/\\___/|_|\\___|      |____/ \\__,_|___/\\___|\\__,_| |_____/ \\__, |___/\\__\\___|_| |_| |_|\n");
	printf("                                                                                 __/ |                      \n");
	printf("                                                                                |___/                       \n");
	printf("\n");
	printf("\n");
}

void userInformationModule()
{

	printf("\n");
	int acceptSelection = ZERO;
	int i = ZERO;
	int j = ZERO;
	do
	{
		acceptSelection = selectMenu();
		if (acceptSelection == ONE)
		{

			i = addUserInformation();
		}
		else if (acceptSelection == TWO)
		{

			j = loginUserInformation();

		}
		else if (acceptSelection == THREE)
		{
			system("cls");
			logoThankyou();
			system("pause");
			exit(-1);
		}
	} while (i == TWO || j == THREE);
	puts("");
	system("pause");
}
void logoUserInformation()
{
	printf("  _    _                 _____        __                           _   _               __  __           _       _           \n");
	printf(" | |  | |               |_   _|      / _|                         | | (_)             |  \\/  |         | |     | |          \n");
	printf(" | |  | |___  ___ _ __    | |  _ __ | |_ ___  _ __ _ __ ___   __ _| |_ _  ___  _ __   | \\  / | ___   __| |_   _| | ___  ___ \n");
	printf(" | |  | / __|/ _ \\ '__|   | | | '_ \\|  _/ _ \\| '__| '_ ` _ \\ / _` | __| |/ _ \\| '_ \\  | |\\/| |/ _ \\ / _` | | | | |/ _ \\/ __|\n");
	printf(" | |__| \\__ \\  __/ |     _| |_| | | | || (_) | |  | | | | | | (_| | |_| | (_) | | | | | |  | | (_) | (_| | |_| | |  __/\\__ \\\n");
	printf("  \\____/|___/\\___|_|    |_____|_| |_|_| \\___/|_|  |_| |_| |_|\\__,_|\\__|_|\\___/|_| |_| |_|  |_|\\___/ \\__,_|\\__,_|_|\\___||___/\n");
	printf("\n");
	printf("\n");
	printf("\n");
}
void logoSignUp()
{
	printf("   _____ _               _    _ _____  \n");
	printf("  / ____(_)             | |  | |  __ \\ \n");
	printf(" | (___  _  __ _ _ __   | |  | | |__) |\n");
	printf("  \\___ \\| |/ _` | '_ \\  | |  | |  ___/ \n");
	printf("  ____) | | (_| | | | | | |__| | |     \n");
	printf(" |_____/|_|\\__, |_| |_|  \\____/|_|     \n");
	printf("            __/ |                      \n");
	printf("           |___/                       \n");
	printf("\n");
	printf("\n");
	printf("\n");
}
void logoLogin()
{
	printf("  _                   _____       \n");
	printf(" | |                 |_   _|      \n");
	printf(" | |     ___   __ _    | |  _ __  \n");
	printf(" | |    / _ \\ / _` |   | | | '_ \\\n");
	printf(" | |___| (_) | (_| |  _| |_| | | |\n");
	printf(" |______\\___/ \\__, | |_____|_| |_|\n");
	printf("               __/ |              \n");
	printf("              |___/               \n");
	printf("\n");
	printf("\n");
	printf("\n");
}
void logoFailed()
{
	printf("  ______    _ _          _ \n");
	printf(" |  ____|  (_) |        | |\n");
	printf(" | |__ __ _ _| | ___  __| |\n");
	printf(" |  __/ _` | | |/ _ \\/ _` |\n");
	printf(" | | | (_| | | |  __/ (_| |\n");
	printf(" |_|  \\__,_|_|_|\\___|\\__,_|\n");
	printf("\n");
	printf("\n");
	printf("\n");

}
void logoModify()
{
	printf("  __  __           _ _  __       \n");
	printf(" |  \\/  |         | (_)/ _|      \n");
	printf(" | \\  / | ___   __| |_| |_ _   _ \n");
	printf(" | |\\/| |/ _ \\ / _` | |  _| | | |\n");
	printf(" | |  | | (_) | (_| | | | | |_| |\n");
	printf(" |_|  |_|\\___/ \\__,_|_|_|  \\__, |\n");
	printf("                            __/ |\n");
	printf("                           |___/ \n");
	printf("\n");
	printf("\n");
	printf("\n");

}
void logodisplay()
{
	printf("  _____  _           _             \n");
	printf(" |  __ \\(_)         | |            \n");
	printf(" | |  | |_ ___ _ __ | | __ _ _   _ \n");
	printf(" | |  | | / __| '_ \\| |/ _` | | | |\n");
	printf(" | |__| | \\__ \\ |_) | | (_| | |_| |\n");
	printf(" |_____/|_|___/ .__/|_|\\__,_|\\__, |\n");
	printf("              | |             __/ |\n");
	printf("              |_|            |___/ \n");
	printf("\n");
	printf("\n");
	printf("\n");
}
void logoSearch()
{
	printf("   _____                     _     \n");
	printf("  / ____|                   | |    \n");
	printf(" | (___   ___  __ _ _ __ ___| |__  \n");
	printf("  \\___ \\ / _ \\/ _` | '__/ __| '_ \\ \n");
	printf("  ____) |  __/ (_| | | | (__| | | |\n");
	printf(" |_____/ \\___|\\__,_|_|  \\___|_| |_|\n");
	printf("\n");
	printf("\n");
	printf("\n");

}
void afterLoginMenuLogo()
{
	printf("  __  __                  \n");
	printf(" |  \\/  |                 \n");
	printf(" | \\  / | ___ _ __  _   _ \n");
	printf(" | |\\/| |/ _ \\ '_ \\| | | |\n");
	printf(" | |  | |  __/ | | | |_| |\n");
	printf(" |_|  |_|\\___|_| |_|\\__,_|\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
}
void successful()
{
	printf("   _____                              __       _ \n");
	printf("  / ____|                            / _|     | |\n");
	printf(" | (___  _   _  ___ ___ ___  ___ ___| |_ _   _| |\n");
	printf("  \\___ \\| | | |/ __/ __/ _ \\/ __/ __|  _| | | | |\n");
	printf("  ____) | |_| | (_| (_|  __/\\__ \\__ \\ | | |_| | |\n");
	printf(" |_____/ \\__,_|\\___\\___\\___||___/___/_|  \\__,_|_|\n");
	printf("\n");
	printf("\n");
	printf("\n");

}
void logoThankyou()
{
	printf("  _______ _                 _     __     __         \n");
	printf(" |__   __| |               | |    \\ \\   / /         \n");
	printf("    | |  | |__   __ _ _ __ | | __  \\ \\_/ /__  _   _ \n");
	printf("    | |  | '_ \\ / _` | '_ \\| |/ /   \\   / _ \\| | | |\n");
	printf("    | |  | | | | (_| | | | |   <     | | (_) | |_| |\n");
	printf("    |_|  |_| |_|\\__,_|_| |_|_|\\_\\    |_|\\___/ \\__,_|\n");
	printf("\n");
	printf("\n");
	printf("\n");
}
int selectMenu()
{
	int selection;
	do
	{
		system("cls");
		logoUserInformation();
		printf("1. Sign Up\n");
		printf("2. Login\n");
		printf("3. Exit\n");
		printf("Your Choice :");
		scanf("%d", &selection);
	} while (!checkingUserSelection(selection, THREE));

	return selection;
}
int addUserInformation()
{
	int idRegistered = ZERO;
	int signUPAgain = ZERO;
	int selection;
	int stringLengthContactNumber = ZERO;
	int stringLengthPassword = ZERO;
	int stringLengthID = ZERO;
	int stringLengthIC = ZERO;
	int checkingGender = ZERO;
	int checkingAge = ZERO;
	int checkingName = ZERO;
	do
	{


		system("cls");
		logoSignUp();


		UserInformation detail;
		UserInformation check;
		do
		{
			printf("ID                             (E.G = 1910751):");
			rewind(stdin);
			scanf("%s", &detail.iD);
			stringLengthID = strlen(detail.iD);
			if (stringLengthID != SEVEN)
			{
				printf("Error: Invalid input!\n");
				printf("Please Inpur Again\n");
				puts("");
			}
		} while (stringLengthID != SEVEN);

		do
		{
			printf("Password       (At least minimum 8 characters):");
			rewind(stdin);
			scanf("%s", &detail.password);
			stringLengthPassword = strlen(detail.password);
			if (stringLengthPassword < EIGHT)
			{
				printf("Minimum 8 Characters\n");
				printf("Please Inpur Again\n");
				puts("");
			}
		} while (stringLengthPassword < EIGHT);
		do
		{
			printf("Name                                          :");
			rewind(stdin);
			if (scanf(" %20[a-z A-Z]", &detail.name) == ONE)
			{
				checkingName += ONE;
			}
			else
			{
				printf("Error: Invalid input!\n");
			}
		} while (checkingName != ONE);

		do
		{
			printf("Gender                                   (M/F):");
			rewind(stdin);
			scanf("%c", &detail.gender);
			if (detail.gender == "M" || "F")
			{
				checkingGender += ONE;
			}
			else
			{
				printf("Error: Invalid input!\n");
				printf("Please Input Again\n");
				puts("");
			}
		} while (checkingGender != ONE);

		do
		{
			printf("Age                                           :");
			rewind(stdin);
			scanf("%d", &detail.age);
			if (detail.age < 0)
			{
				checkingAge += ONE;
				printf("Error: Invalid input!\n");
				printf("Please Input Again\n");
				puts("");
			}
		} while (checkingAge == ONE);

		do
		{
			printf("IC                               (Without '-'):");
			rewind(stdin);
			scanf("%s", &detail.iC);
			stringLengthIC = strlen(detail.iC);
			if (stringLengthIC != TWELVE)
			{
				printf("Error: Invalid input!\n");
				printf("Please Input Again\n");
				puts("");
			}
		} while (stringLengthIC != TWELVE);

		do
		{

			printf("Contact Number     e.g 0000000000(Without '-'):");
			rewind(stdin);
			scanf("%s", &detail.contactNumber);
			stringLengthContactNumber = strlen(detail.contactNumber);
			if (stringLengthContactNumber != TEN)
			{
				printf("Error: Invalid input!\n");
				printf("Please Input Again\n");
				puts("");;
			}
		} while (stringLengthContactNumber != TEN);
		FILE * signUP;

		signUP = fopen("UserInfor.dat", "ab+");
		if (signUP == NULL)
		{
			printf("File Error!\n");
			system("pause");
			exit(-1);

		}
		while (fread(&check, sizeof(check), ONE, signUP))
		{
			if (strcmp(check.iD, detail.iD) == ZERO)
			{
				idRegistered += ONE;
			}

		}
		fclose(signUP);
		signUP = fopen("UserInfor.dat", "a");
		if (signUP == NULL)
		{
			printf("File Error!\n");
			system("pause");
			exit(-1);

		}

		if (idRegistered != ONE)
		{

			strcpy(detail.student, "STUDENT");
			fwrite(&detail, sizeof(detail), ONE, signUP);
			fclose(signUP);
			do {
				system("cls");
				successful();
				printf("Account Register Successful\n");
				printf("1. Main Menu\n");
				printf("2. Exit\n");
				printf("Selection :");
				scanf("%d", &selection);
			} while (!checkingUserSelection(selection, TWO));
			if (selection == TWO)
			{
				system("cls");
				logoThankyou();
				system("pause");
				exit(-1);
			}
		}
		else
		{
			do {
				system("cls");
				logoFailed();
				printf("ID Registered\n");
				printf("1. Sign Up\n");
				printf("2. Main Menu\n");
				printf("3. Exit\n");
				scanf("%d", &signUPAgain);
			} while (!checkingUserSelection(signUPAgain, THREE));


			if (signUPAgain == THREE)
			{
				system("cls");
				logoThankyou();
				system("pause");
				exit(-1);

			}
		}
	} while (signUPAgain == ONE);
	if (signUPAgain == TWO || selection == ONE)
	{
		return TWO;
	}

}
int loginUserInformation()
{
	system("cls");
	logoLogin();
	int logined = ZERO, loginAgain = ZERO, stringLengthID = ZERO, stringLengthPassword = ZERO;
	do
	{

		UserInformation login;
		UserInformation loginCheck;

		do
		{

			printf("ID             (E.G = 1910751):");
			rewind(stdin);
			scanf("%s", &login.iD);
			stringLengthID = strlen(login.iD);
			if (stringLengthID != SEVEN)
			{
				printf("Error: Invalid input!\n");
				printf("Please Inpur Again\n");
				puts("");
			}
		} while (stringLengthID != SEVEN);

		do
		{
			printf("Password       (At least minimum 8 characters):");
			rewind(stdin);
			scanf("%s", &login.password);
			stringLengthPassword = strlen(login.password);
			if (stringLengthPassword < EIGHT)
			{
				printf("Minimum 8 Characters\n");
				printf("Please Inpur Again\n");
				puts("");
			}
		} while (stringLengthPassword < EIGHT);

		FILE * loginChecking;
		loginChecking = fopen("UserInfor.dat", "rb");
		if (loginChecking == NULL)
		{
			printf("File Error!\n");
			system("pause");
			exit(-1);

		}

		while (fread(&loginCheck, sizeof(loginCheck), ONE, loginChecking))
		{
			if (strcmp(loginCheck.iD, login.iD) == ZERO && strcmp(loginCheck.password, login.password) == ZERO)
			{
				logined += ONE;
			}

		}

		if (logined == ONE)
		{
			system("cls");
			afterloginMenu(login);

		}
		else
		{
			do {
				printf("1. Login\n");
				printf("2. Main Menu\n");
				printf("3. Exit\n");
				printf("Selection :");
				scanf("%d", &loginAgain);
			} while (!checkingUserSelection(loginAgain, THREE));

			if (loginAgain == THREE)
			{
				system("cls");
				logoThankyou();
				system("pause");
				exit(-1);
			}
		}
	} while (loginAgain == ONE);
	return TWO;
}
int editMenu(UserInformation login)
{
	int afterLogIn;
	int i = ZERO, j = ZERO, k = ZERO;
	do
	{


		do
		{
			system("cls");
			afterLoginMenuLogo();
			printf("1. Modify\n");
			printf("2. Display\n");
			printf("3. Search\n");
			printf("4. Program Menu\n");
			printf("5. Exit\n");
			printf("Your Selection :");
			scanf("%d", &afterLogIn);
		} while (!checkingUserSelection(afterLogIn, FIVE));
		if (afterLogIn == ONE)
		{
			system("cls");
			i = ZERO;
			i = modifyUserInformation(login);
		}
		else if (afterLogIn == TWO)
		{
			system("cls");
			j = ZERO;
			j = displayUserInformation(login);
		}
		else if (afterLogIn == THREE)
		{
			system("cls");
			k = ZERO;
			k = searchUserInformation(login);
		}
		else if (afterLogIn == FIVE)
		{
			system("cls");
			logoThankyou();
			system("pause");
			exit(-1);
		}
	} while (i == TWO || j == TWO || k == TWO);
	if (i == ONE)
	{
		return i;
	}
	else if (j == ONE)
	{
		return j;
	}
	else if (k == ONE)
	{
		return k;
	}
	else if (afterLogIn == FOUR)
	{
		return afterLogIn;
	}
}
int modifyUserInformation(UserInformation modifyUserInfo)
{
	logoModify();
	int selection, i = ZERO, totalAccountCount = ZERO, askForMenu, j, ensure = ZERO, stringLengthID = ZERO, checkingName = ZERO, checkingGender = ZERO, checkingAge = ZERO, stringLengthIC = ZERO, stringLengthContactNumber = ZERO;
	do
	{
		printf("1. Name\n");
		printf("2. Gender\n");
		printf("3. Age\n");
		printf("4. IC\n");
		printf("5. Contact Number\n");
		printf("6. Exit Modify\n");
		printf("Selection :");
		scanf("%d", &selection);
	} while (!checkingUserSelection(selection, SIX));
	UserInformation finding[999];
	UserInformation modifyInput;
	FILE *modifyFunction;
	modifyFunction = fopen("UserInfor.dat", "rb");
	if (modifyFunction == NULL)
	{
		printf("File Error!\n");
		system("pause");
		exit(-1);

	}


	if (selection == ONE)
	{
		while (fread(&finding[i], sizeof(finding[i]), ONE, modifyFunction) > ZERO)
		{

			if (strcmp(modifyUserInfo.iD, finding[i].iD) == ZERO && strcmp(modifyUserInfo.password, finding[i].password) == ZERO)
			{
				printf("Your Old Name           : %s\n", finding[i].name);
				do
				{
					printf("Your New Name           :");
					rewind(stdin);
					if (scanf(" %20[a-z A-Z]", &modifyInput.name) == ONE)
					{
						checkingName += ONE;
					}
					else
					{
						printf("Error: Invalid input!\n");
					}
				} while (checkingName != ONE);
				strcpy(finding[i].name, modifyInput.name);
				ensure += ONE;
			}
			i++;
			totalAccountCount++;
		}
	}
	else if (selection == TWO)
	{
		while (fread(&finding[i], sizeof(finding[i]), ONE, modifyFunction) > ZERO)
		{

			if (strcmp(modifyUserInfo.iD, finding[i].iD) == ZERO && strcmp(modifyUserInfo.password, finding[i].password) == ZERO)
			{
				printf("Your Old Gender         : %c\n", finding[i].gender);
				do
				{
					printf("Gender          (M/F):");
					rewind(stdin);
					scanf("%c", &modifyInput.gender);
					if (modifyInput.gender == "M" || "F")
					{
						checkingGender += ONE;
					}
					else
					{
						printf("Error: Invalid input!\n");
						printf("Please Input Again\n");
						puts("");
					}
				} while (checkingGender != ONE);
				strcpy(finding[i].gender, modifyInput.gender);
				ensure += ONE;
			}
			i++;
			totalAccountCount++;
		}
	}
	else if (selection == THREE)
	{
		while (fread(&finding[i], sizeof(finding[i]), ONE, modifyFunction) > ZERO)
		{

			if (strcmp(modifyUserInfo.iD, finding[i].iD) == ZERO && strcmp(modifyUserInfo.password, finding[i].password) == ZERO)
			{
				do
				{
					printf("Age                  :");
					rewind(stdin);
					scanf("%d", &modifyInput.age);
					if (modifyInput.age < 0)
					{
						checkingAge += ONE;
						printf("Error: Invalid input!\n");
						printf("Please Input Again\n");
						puts("");
					}
				} while (checkingAge == ONE);
				finding[i].age = modifyInput.age;
				ensure += ONE;
			}
			i++;
			totalAccountCount++;
		}
	}

	else if (selection == FOUR)
	{
		while (fread(&finding[i], sizeof(finding[i]), ONE, modifyFunction) > ZERO)
		{

			if (strcmp(modifyUserInfo.iD, finding[i].iD) == ZERO && strcmp(modifyUserInfo.password, finding[i].password) == ZERO)
			{
				printf("Your Old IC             : %s\n", finding[i].iC);
				do
				{
					printf("IC             (Without '-'):");
					rewind(stdin);
					scanf("%s", &modifyInput.iC);
					stringLengthIC = strlen(modifyInput.iC);
					if (stringLengthIC != TWELVE)
					{
						printf("Error: Invalid input!\n");
						printf("Please Input Again\n");
						puts("");
					}
				} while (stringLengthIC != TWELVE);
				strcpy(finding[i].iC, modifyInput.iC);
				ensure += ONE;
			}
			i++;
			totalAccountCount++;
		}
	}
	else if (selection == FIVE)
	{
		while (fread(&finding[i], sizeof(finding[i]), ONE, modifyFunction) > ZERO)
		{

			if (strcmp(modifyUserInfo.iD, finding[i].iD) == ZERO && strcmp(modifyUserInfo.password, finding[i].password) == ZERO)
			{

				printf("Your Old Contact Number : %s\n", finding[i].contactNumber);
				do
				{

					printf("Contact Number e.g 0000000000(Without '-'):");
					rewind(stdin);
					scanf("%s", &modifyInput.contactNumber);
					stringLengthContactNumber = strlen(modifyInput.contactNumber);
					if (stringLengthContactNumber != TEN)
					{
						printf("Error: Invalid input!\n");
						printf("Please Input Again\n");
						puts("");;
					}
				} while (stringLengthContactNumber != TEN);
				strcpy(finding[i].contactNumber, modifyInput.contactNumber);
				ensure += ONE;
			}
			i++;
			totalAccountCount++;
		}
	}







	fclose(modifyFunction);
	if (ensure == ONE)
	{
		FILE *modifyFunction2;
		modifyFunction2 = fopen("UserInfor.dat", "wb");
		if (modifyFunction2 == NULL)
		{
			printf("File Error!\n");
			system("pause");
			exit(-1);

		}
		for (j = ZERO; j < totalAccountCount; j++)
		{
			fwrite(&finding[j], sizeof(finding[j]), ONE, modifyFunction2);
		}
		fclose(modifyFunction2);
	}


	do
	{
		puts("");
		printf("1. Program Menu\n");
		printf("2. User Menu\n");
		printf("3. Exit\n");
		printf("Your Selection :");
		scanf("%d", &askForMenu);

	} while (!checkingUserSelection(askForMenu, THREE));
	if (askForMenu == THREE)
	{
		system("cls");
		logoThankyou();
		system("pause");
		exit(-1);
	}
	else
	{
		return askForMenu;
	}
}
int displayUserInformation(UserInformation displayUserInfo)
{

	int askForMenu;
	logodisplay();
	UserInformation finding;
	FILE *displayFunction;
	displayFunction = fopen("UserInfor.dat", "rb");
	if (displayFunction == NULL)
	{
		printf("File Error!\n");
		system("pause");
		exit(-1);

	}
	while (fread(&finding, sizeof(finding), ONE, displayFunction) > ZERO)
	{
		if (strcmp(displayUserInfo.iD, finding.iD) == ZERO && strcmp(displayUserInfo.password, finding.password) == ZERO)
		{

			puts("");
			printf("Your ID             : %s\n", finding.iD);
			printf("Your Name           : %s\n", finding.name);
			printf("Your Gender         : %c\n", finding.gender);
			printf("Your Age            : %d\n", finding.age);
			printf("Your IC             : %s\n", finding.iC);
			printf("Your Contact Number : %s\n", finding.contactNumber);
			break;
		}

	}
	do
	{
		puts("");
		printf("1. Program Menu\n");
		printf("2. User Menu\n");
		printf("3. Exit\n");
		printf("Your Selection :");
		scanf("%d", &askForMenu);

	} while (!checkingUserSelection(askForMenu, THREE));

	if (askForMenu == THREE)
	{
		system("cls");
		logoThankyou();
		system("pause");
		exit(-1);
	}
	else
	{
		return askForMenu;
	}
}
int searchUserInformation(UserInformation searchingFunction)
{

	int checking = ZERO, stringLengthID = ZERO;
	char searchiAgain;
	int searchOneMoreTime = ZERO;
	int selection, askForMenu;
	do
	{
		system("cls");
		logoSearch();
		UserInformation search;
		UserInformation finding;
		FILE *searchingUserInfo;
		searchingUserInfo = fopen("UserInfor.dat", "rb");
		do
		{

			printf("ID             (E.G = 1910751):");
			rewind(stdin);
			scanf("%s", &search.iD);
			stringLengthID = strlen(search.iD);
			if (stringLengthID != SEVEN)
			{
				printf("Error: Invalid input!\n");
				printf("Please Inpur Again\n");
				puts("");
			}
		} while (stringLengthID != SEVEN);



		while (fread(&finding, sizeof(finding), ONE, searchingUserInfo) > ZERO)
		{
			if (strcmp(search.iD, finding.iD) == ZERO)
			{
				checking += ONE;
				puts("");
				printf("Your ID             : %s\n", finding.iD);
				printf("Your Name           : %s\n", finding.name);
				printf("Your Gender         : %c\n", finding.gender);
				printf("Your Age            : %d\n", finding.age);
				printf("Your IC             : %s\n", finding.iC);
				printf("Your Contact Number : %s\n", finding.contactNumber);

			}
		}
		if (checking != ONE)
		{
			printf("No Record Found\n");
			printf("Do You Want To Search Again?(Y/y = Yes) :");
			rewind(stdin);
			scanf("%c", &searchiAgain);
			if (searchiAgain == 'Y' || searchiAgain == 'y')
			{
				searchOneMoreTime += ONE;
			}

		}
		do
		{
			puts("");
			printf("1. Program Menu\n");
			printf("2. User Menu\n");
			printf("3. Exit\n");
			printf("Your Selection :");
			scanf("%d", &askForMenu);

		} while (!checkingUserSelection(askForMenu, THREE));

		if (askForMenu == THREE)
		{
			system("cls");
			logoThankyou();
			system("pause");
			exit(-1);
		}
	} while (searchOneMoreTime == ONE);
	return askForMenu;
}

void staffInformationModules()
{
	int choose;
	int i = ZERO;
	do
	{
		system("cls");
		printf("                                      ▄████████     ███        ▄████████    ▄████████    ▄████████                                    \n");
		printf("                                     ███    ███ ▀█████████▄   ███    ███   ███    ███   ███    ███                                    \n");
		printf("                                     ███    █▀     ▀███▀▀██   ███    ███   ███    █▀    ███    █▀                                     \n");
		printf("                                     ███            ███   ▀   ███    ███  ▄███▄▄▄      ▄███▄▄▄                                        \n");
		printf("                                   ▀███████████     ███     ▀███████████ ▀▀███▀▀▀     ▀▀███▀▀▀                                        \n");
		printf("                                            ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                      ▄█    ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                    ▄████████▀     ▄████▀     ███    █▀    ███          ███                                           \n");
		printf("                                                                                                                                      \n");
		printf("           ▄█  ███▄▄▄▄      ▄████████  ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████     ███      ▄█   ▄██████▄  ███▄▄▄▄        \n");
		printf("          ███  ███▀▀▀██▄   ███    ███ ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ▀█████████▄ ███  ███    ███ ███▀▀▀██▄      \n");
		printf("          ███▌ ███   ███   ███    █▀  ███    ███   ███    ███ ███   ███   ███   ███    ███    ▀███▀▀██ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███  ▄███▄▄▄     ███    ███  ▄███▄▄▄▄██▀ ███   ███   ███   ███    ███     ███   ▀ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███ ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀▀▀   ███   ███   ███ ▀███████████     ███     ███▌ ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███ ▀███████████ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███   ███    ███ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          █▀    ▀█   █▀    ███         ▀██████▀    ███    ███  ▀█   ███   █▀    ███    █▀     ▄████▀   █▀    ▀██████▀   ▀█   █▀       \n");
		printf("                                                   ███    ███                                                                         \n");
		do
		{
			printf("1- Register Account\n");
			printf("2- Log In Account\n");
			printf("3- Exit\n");
			scanf("%d", &choose);
		} while (!checkingUserSelection(choose, THREE));

		if (choose == ONE)
		{
			i = ZERO;
			i = staffRegister();
		}
		else if (choose == TWO)
		{
			i = ZERO;
			i = staffLogin();
		}
		else if (choose == THREE)
		{
			printf("Thank You\n");
			system("pause");
			exit(-1);
		}
	} while (i == TWO);
	puts("");
	system("pause");
}
int staffRegister()
{
	int askForRegisterAgain = ZERO;
	int checking = ZERO, selection = ZERO;
	int askForMenu = ZERO;
	int nameValidation = ZERO;
	do
	{


		printf("                                      ▄████████     ███        ▄████████    ▄████████    ▄████████                                    \n");
		printf("                                     ███    ███ ▀█████████▄   ███    ███   ███    ███   ███    ███                                    \n");
		printf("                                     ███    █▀     ▀███▀▀██   ███    ███   ███    █▀    ███    █▀                                     \n");
		printf("                                     ███            ███   ▀   ███    ███  ▄███▄▄▄      ▄███▄▄▄                                        \n");
		printf("                                   ▀███████████     ███     ▀███████████ ▀▀███▀▀▀     ▀▀███▀▀▀                                        \n");
		printf("                                            ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                      ▄█    ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                    ▄████████▀     ▄████▀     ███    █▀    ███          ███                                           \n");
		printf("                                                                                                                                      \n");
		printf("           ▄█  ███▄▄▄▄      ▄████████  ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████     ███      ▄█   ▄██████▄  ███▄▄▄▄        \n");
		printf("          ███  ███▀▀▀██▄   ███    ███ ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ▀█████████▄ ███  ███    ███ ███▀▀▀██▄      \n");
		printf("          ███▌ ███   ███   ███    █▀  ███    ███   ███    ███ ███   ███   ███   ███    ███    ▀███▀▀██ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███  ▄███▄▄▄     ███    ███  ▄███▄▄▄▄██▀ ███   ███   ███   ███    ███     ███   ▀ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███ ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀▀▀   ███   ███   ███ ▀███████████     ███     ███▌ ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███ ▀███████████ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███   ███    ███ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          █▀    ▀█   █▀    ███         ▀██████▀    ███    ███  ▀█   ███   █▀    ███    █▀     ▄████▀   █▀    ▀██████▀   ▀█   █▀       \n");
		printf("                                                   ███    ███                                                                         \n");
		system("cls");
		printf("   ?????????    ?????????    ????????   ??     ?????????     ???        ?????????    ?????????      \n");
		printf("  ???    ???   ???    ???   ???    ??? ???    ???    ??? ???????????   ???    ???   ???    ???      \n");
		printf("  ???    ???   ???    ??    ???    ??  ????   ???    ??     ????????   ???    ??    ???    ???      \n");
		printf(" ???????????  ???????      ????        ????   ???            ???   ?  ???????      ???????????      \n");
		printf("??????????   ????????     ????? ?????  ???? ????????????     ???     ????????     ??????????        \n");
		printf("????????????   ???    ??    ???    ??? ???           ???     ???       ???    ??  ????????????      \n");
		printf("  ???    ???   ???    ???   ???    ??? ???     ??    ???     ???       ???    ???   ???    ???      \n");
		printf("  ???    ???   ??????????   ?????????  ??    ??????????     ??????     ??????????   ???    ???      \n");
		printf("  ???    ???                                                                        ???    ???      \n");
		puts("");
		printf("   ?????????  ?????????  ?????????  ????????  ???    ??  ???????       ???                          \n");
		printf("  ???    ??? ???    ??? ???    ??? ???    ??? ???    ??? ????????? ???????????                      \n");
		printf("  ???    ??? ???    ??  ???    ??  ???    ??? ???    ??? ???   ???    ????????                      \n");
		printf("  ???    ??? ???        ???        ???    ??? ???    ??? ???   ???     ???   ?                      \n");
		printf("???????????? ???        ???        ???    ??? ???    ??? ???   ???     ???                          \n");
		printf("  ???    ??? ???    ??  ???    ??  ???    ??? ???    ??? ???   ???     ???                          \n");
		printf("  ???    ??? ???    ??? ???    ??? ???    ??? ???    ??? ???   ???     ???                          \n");
		printf("  ???    ??  ?????????  ?????????   ????????  ?????????   ??   ??     ??????                        \n");
		printf("                                                                                                    \n");
		printf("\n");
		printf("\n");
		printf("\n");
		StaffInformationDetail registerAccount;
		StaffInformationDetail finding;

		printf("ID            :");
		rewind(stdin);
		scanf("%s", &registerAccount.require.ID);

		printf("Password      :");
		rewind(stdin);
		scanf("%s", &registerAccount.require.passWord);

		do
		{
			nameValidation = ZERO;
			printf("Name          :");
			rewind(stdin);
			if (scanf(" %20[a-z A-Z]", &registerAccount.name) == ONE)
			{
				nameValidation += ONE;
			}
			else
			{
				printf("Error: Invalid input!\n");
			}
		} while (nameValidation != ONE);

		printf("Gender        :");
		rewind(stdin);
		scanf("%c", &registerAccount.gender);


		printf("Contact Number:");
		rewind(stdin);
		scanf("%[^\n]", &registerAccount.contactNumber);

		FILE*registerACC;
		registerACC = fopen("staff.txt", "r");
		while (fscanf(registerACC, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding.require.ID, &finding.require.passWord, &finding.name, &finding.gender, &finding.contactNumber) != EOF)
		{
			if (strcmp(finding.require.ID, registerAccount.require.ID) == ZERO)
			{
				checking = checking + ONE;
			}
		}
		fclose(registerACC);
		FILE*registerACC2;
		registerACC2 = fopen("staff.txt", "a");
		if (checking != ONE)
		{
			printf("Account Register Successful\n");
			fprintf(registerACC2, "%s:%s:%s:%c:%s\n", registerAccount.require.ID, registerAccount.require.passWord, registerAccount.name, registerAccount.gender, registerAccount.contactNumber);
			fclose(registerACC2);


		}
		else
		{
			printf("Register Unsuccessful\n\n");

		}
		do
		{

			printf("1. Register\n");
			printf("2. Menu\n");
			printf("3. Exit\n");
			printf("Selection :");
			scanf("%d", &askForRegisterAgain);
		} while (!checkingUserSelection(askForRegisterAgain, THREE));
		if (askForRegisterAgain == THREE)
		{
			printf("Thank You!");
			system("pause");
			exit(-1);
		}


	} while (askForRegisterAgain == ONE);
	return askForRegisterAgain;

}
int staffLogin()
{
	int loginAgain;
	do
	{
		system("cls");
		printf("                                      ▄████████     ███        ▄████████    ▄████████    ▄████████                                    \n");
		printf("                                     ███    ███ ▀█████████▄   ███    ███   ███    ███   ███    ███                                    \n");
		printf("                                     ███    █▀     ▀███▀▀██   ███    ███   ███    █▀    ███    █▀                                     \n");
		printf("                                     ███            ███   ▀   ███    ███  ▄███▄▄▄      ▄███▄▄▄                                        \n");
		printf("                                   ▀███████████     ███     ▀███████████ ▀▀███▀▀▀     ▀▀███▀▀▀                                        \n");
		printf("                                            ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                      ▄█    ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                    ▄████████▀     ▄████▀     ███    █▀    ███          ███                                           \n");
		printf("                                                                                                                                      \n");
		printf("           ▄█  ███▄▄▄▄      ▄████████  ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████     ███      ▄█   ▄██████▄  ███▄▄▄▄        \n");
		printf("          ███  ███▀▀▀██▄   ███    ███ ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ▀█████████▄ ███  ███    ███ ███▀▀▀██▄      \n");
		printf("          ███▌ ███   ███   ███    █▀  ███    ███   ███    ███ ███   ███   ███   ███    ███    ▀███▀▀██ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███  ▄███▄▄▄     ███    ███  ▄███▄▄▄▄██▀ ███   ███   ███   ███    ███     ███   ▀ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███ ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀▀▀   ███   ███   ███ ▀███████████     ███     ███▌ ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███ ▀███████████ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███   ███    ███ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          █▀    ▀█   █▀    ███         ▀██████▀    ███    ███  ▀█   ███   █▀    ███    █▀     ▄████▀   █▀    ▀██████▀   ▀█   █▀       \n");
		printf("                                                   ███    ███                                                                         \n");
		printf(" ??        ????????     ????????   ??  ???????   \n");
		printf("???       ???    ???   ???    ??? ???  ????????? \n");
		printf("???       ???    ???   ???    ??  ???? ???   ??? \n");
		printf("???       ???    ???  ????        ???? ???   ??? \n");
		printf("???       ???    ??? ????? ?????  ???? ???   ??? \n");
		printf("???       ???    ???   ???    ??? ???  ???   ??? \n");
		printf("????    ? ???    ???   ???    ??? ???  ???   ??? \n");
		printf("?????????  ????????    ?????????  ??    ??   ??  \n");
		printf("?                                                \n");
		printf("\n");
		printf("\n");
		printf("\n");
		StaffInformationDetail loginDetail;
		StaffInformationDetail finding;
		int checking = ZERO, selection;
		printf("ID            :");
		scanf("%s", &loginDetail.require.ID);
		rewind(stdin);
		printf("Password      :");
		scanf("%s", &loginDetail.require.passWord);
		rewind(stdin);
		FILE *stafflogin;
		stafflogin = fopen("staff.txt", "r");
		while (fscanf(stafflogin, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding.require.ID, &finding.require.passWord, &finding.name, &finding.gender, &finding.contactNumber) != EOF)
		{
			if (strcmp(finding.require.ID, loginDetail.require.ID) == ZERO && strcmp(finding.require.passWord, loginDetail.require.passWord) == ZERO)
			{
				checking = checking + ONE;
			}
		}
		if (checking == ONE)
		{

			loginedMenu(loginDetail);

		}
		else
		{
			do
			{
				printf("Login Unsuccessful\n");
				printf("1. Login Again\n");
				printf("2. Menu\n");
				printf("3. Exit\n");
				printf("Selection :");
				scanf("%d", &loginAgain);
			} while (!checkingUserSelection(loginAgain, THREE));
			if (loginAgain == THREE)
			{
				printf("Thank You!");
				system("pause");
				exit(-1);
			}
		}
	} while (loginAgain == ONE);
	return loginAgain;
}
int staffinformationMenu(StaffInformationDetail loginDetail)
{
	int selection;
	int i = ZERO;
	do
	{


		do
		{

			system("cls");
			printf("                                      ▄████████     ███        ▄████████    ▄████████    ▄████████                                    \n");
			printf("                                     ███    ███ ▀█████████▄   ███    ███   ███    ███   ███    ███                                    \n");
			printf("                                     ███    █▀     ▀███▀▀██   ███    ███   ███    █▀    ███    █▀                                     \n");
			printf("                                     ███            ███   ▀   ███    ███  ▄███▄▄▄      ▄███▄▄▄                                        \n");
			printf("                                   ▀███████████     ███     ▀███████████ ▀▀███▀▀▀     ▀▀███▀▀▀                                        \n");
			printf("                                            ███     ███       ███    ███   ███          ███                                           \n");
			printf("                                      ▄█    ███     ███       ███    ███   ███          ███                                           \n");
			printf("                                    ▄████████▀     ▄████▀     ███    █▀    ███          ███                                           \n");
			printf("                                                                                                                                      \n");
			printf("           ▄█  ███▄▄▄▄      ▄████████  ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████     ███      ▄█   ▄██████▄  ███▄▄▄▄        \n");
			printf("          ███  ███▀▀▀██▄   ███    ███ ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ▀█████████▄ ███  ███    ███ ███▀▀▀██▄      \n");
			printf("          ███▌ ███   ███   ███    █▀  ███    ███   ███    ███ ███   ███   ███   ███    ███    ▀███▀▀██ ███▌ ███    ███ ███   ███      \n");
			printf("          ███▌ ███   ███  ▄███▄▄▄     ███    ███  ▄███▄▄▄▄██▀ ███   ███   ███   ███    ███     ███   ▀ ███▌ ███    ███ ███   ███      \n");
			printf("          ███▌ ███   ███ ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀▀▀   ███   ███   ███ ▀███████████     ███     ███▌ ███    ███ ███   ███      \n");
			printf("          ███  ███   ███   ███        ███    ███ ▀███████████ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
			printf("          ███  ███   ███   ███        ███    ███   ███    ███ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
			printf("          █▀    ▀█   █▀    ███         ▀██████▀    ███    ███  ▀█   ███   █▀    ███    █▀     ▄████▀   █▀    ▀██████▀   ▀█   █▀       \n");
			printf("                                                   ███    ███                                                                         \n");
			printf("                                          ▄▄▄▄███▄▄▄▄      ▄████████ ███▄▄▄▄   ███    █▄                                              \n");
			printf("                                        ▄██▀▀▀███▀▀▀██▄   ███    ███ ███▀▀▀██▄ ███    ███                                             \n");
			printf("                                        ███   ███   ███   ███    █▀  ███   ███ ███    ███                                             \n");
			printf("                                        ███   ███   ███  ▄███▄▄▄     ███   ███ ███    ███                                             \n");
			printf("                                        ███   ███   ███ ▀▀███▀▀▀     ███   ███ ███    ███                                             \n");
			printf("                                        ███   ███   ███   ███    █▄  ███   ███ ███    ███                                             \n");
			printf("                                        ███   ███   ███   ███    ███ ███   ███ ███    ███                                             \n");
			printf("                                         ▀█   ███   █▀    ██████████  ▀█   █▀  ████████▀                                              \n");
			printf("                                                                                                                                      \n");

			printf("\n");
			printf("\n");
			printf("\n");
			printf("1- Display\n");
			printf("2- Search\n");
			printf("3- Modify\n");
			printf("Selection :");
			scanf("%d", &selection);

		} while (selection < ONE && selection > THREE);
		if (selection == ONE)
		{
			i = staffDisplay(loginDetail);
		}
		else if (selection == TWO)
		{
			i = staffSearch(loginDetail);
		}
		else if (selection == THREE)
		{
			i = staffModify(loginDetail);
		}
	} while (i == THREE);
	return i;
}
int staffDisplay(StaffInformationDetail displayFunction)
{
	int selection = ZERO;
	do
	{

		system("cls");
		printf("                                      ▄████████     ███        ▄████████    ▄████████    ▄████████                                    \n");
		printf("                                     ███    ███ ▀█████████▄   ███    ███   ███    ███   ███    ███                                    \n");
		printf("                                     ███    █▀     ▀███▀▀██   ███    ███   ███    █▀    ███    █▀                                     \n");
		printf("                                     ███            ███   ▀   ███    ███  ▄███▄▄▄      ▄███▄▄▄                                        \n");
		printf("                                   ▀███████████     ███     ▀███████████ ▀▀███▀▀▀     ▀▀███▀▀▀                                        \n");
		printf("                                            ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                      ▄█    ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                    ▄████████▀     ▄████▀     ███    █▀    ███          ███                                           \n");
		printf("                                                                                                                                      \n");
		printf("           ▄█  ███▄▄▄▄      ▄████████  ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████     ███      ▄█   ▄██████▄  ███▄▄▄▄        \n");
		printf("          ███  ███▀▀▀██▄   ███    ███ ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ▀█████████▄ ███  ███    ███ ███▀▀▀██▄      \n");
		printf("          ███▌ ███   ███   ███    █▀  ███    ███   ███    ███ ███   ███   ███   ███    ███    ▀███▀▀██ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███  ▄███▄▄▄     ███    ███  ▄███▄▄▄▄██▀ ███   ███   ███   ███    ███     ███   ▀ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███ ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀▀▀   ███   ███   ███ ▀███████████     ███     ███▌ ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███ ▀███████████ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███   ███    ███ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          █▀    ▀█   █▀    ███         ▀██████▀    ███    ███  ▀█   ███   █▀    ███    █▀     ▄████▀   █▀    ▀██████▀   ▀█   █▀       \n");
		printf("                                                   ███    ███                                                                         \n");
		printf("?????????   ??     ?????????    ?????????  ??          ????????? ???   ?   \n");
		printf("???   ???? ???    ???    ???   ???    ??? ???         ???    ??? ???   ??? \n");
		printf("???    ??? ????   ???    ??    ???    ??? ???         ???    ??? ????????? \n");
		printf("???    ??? ????   ???          ???    ??? ???         ???    ??? ????????? \n");
		printf("???    ??? ???? ???????????? ???????????  ???       ????????????       ??? \n");
		printf("???    ??? ???           ???   ???        ???         ???    ??? ???   ??? \n");
		printf("???   ???? ???     ??    ???   ???        ????    ?   ???    ??? ???   ??? \n");
		printf("?????????  ??    ??????????   ??????      ?????????   ???    ??   ???????  \n");
		printf("                                          ?                                \n");
		printf("\n");
		printf("\n");
		printf("\n");

		StaffInformationDetail finding;
		FILE*displayInfo;
		displayInfo = fopen("staff.txt", "r");
		while (fscanf(displayInfo, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding.require.ID, &finding.require.passWord, &finding.name, &finding.gender, &finding.contactNumber) != EOF)
		{
			if (strcmp(finding.require.ID, displayFunction.require.ID) == ZERO && strcmp(finding.require.passWord, displayFunction.require.passWord) == ZERO)
			{
				printf("Your ID             : %s\n", finding.require.ID);
				printf("Your Name           : %s\n", finding.require.passWord);
				printf("Your Gender         : %c\n", finding.gender);
				printf("Your Contact Number : %s\n", finding.contactNumber);
				break;
			}
		}
		puts("");
		do
		{
			printf("1. Display\n");
			printf("2. Program Menu\n");
			printf("3. Staff Information Menu\n");
			printf("4. Exit\n");
			rewind(stdin);
			scanf("%d", &selection);
		} while (!checkingUserSelection(selection, FOUR));

		if (selection == FOUR)
		{
			printf("Thanks for using\n");
			system("pause");
			exit(-1);
		}

	} while (selection == ONE);
	return selection;
}
int staffModify(StaffInformationDetail modifyFunction)
{
	int selection;
	do
	{


		system("cls");
		printf("                                      ▄████████     ███        ▄████████    ▄████████    ▄████████                                    \n");
		printf("                                     ███    ███ ▀█████████▄   ███    ███   ███    ███   ███    ███                                    \n");
		printf("                                     ███    █▀     ▀███▀▀██   ███    ███   ███    █▀    ███    █▀                                     \n");
		printf("                                     ███            ███   ▀   ███    ███  ▄███▄▄▄      ▄███▄▄▄                                        \n");
		printf("                                   ▀███████████     ███     ▀███████████ ▀▀███▀▀▀     ▀▀███▀▀▀                                        \n");
		printf("                                            ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                      ▄█    ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                    ▄████████▀     ▄████▀     ███    █▀    ███          ███                                           \n");
		printf("                                                                                                                                      \n");
		printf("           ▄█  ███▄▄▄▄      ▄████████  ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████     ███      ▄█   ▄██████▄  ███▄▄▄▄        \n");
		printf("          ███  ███▀▀▀██▄   ███    ███ ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ▀█████████▄ ███  ███    ███ ███▀▀▀██▄      \n");
		printf("          ███▌ ███   ███   ███    █▀  ███    ███   ███    ███ ███   ███   ███   ███    ███    ▀███▀▀██ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███  ▄███▄▄▄     ███    ███  ▄███▄▄▄▄██▀ ███   ███   ███   ███    ███     ███   ▀ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███ ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀▀▀   ███   ███   ███ ▀███████████     ███     ███▌ ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███ ▀███████████ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███   ███    ███ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          █▀    ▀█   █▀    ███         ▀██████▀    ███    ███  ▀█   ███   █▀    ███    █▀     ▄████▀   █▀    ▀██████▀   ▀█   █▀       \n");
		printf("                                                   ███    ███                                                                         \n");
		printf("   ???????????    ????????  ?????????   ??     ????????? ???   ?   \n");
		printf(" ??????????????? ???    ??? ???   ???? ???    ???    ??? ???   ??? \n");
		printf(" ???   ???   ??? ???    ??? ???    ??? ????   ???    ??  ????????? \n");
		printf(" ???   ???   ??? ???    ??? ???    ??? ????  ???????     ????????? \n");
		printf(" ???   ???   ??? ???    ??? ???    ??? ???? ????????           ??? \n");
		printf(" ???   ???   ??? ???    ??? ???    ??? ???    ???        ???   ??? \n");
		printf(" ???   ???   ??? ???    ??? ???   ???? ???    ???        ???   ??? \n");
		printf("  ??   ???   ??   ????????  ?????????  ??     ???         ???????  \n");
		printf("                                                                   \n");
		printf("\n");
		printf("\n");
		printf("\n");
		int choice, i = ZERO, accountcount = ZERO, j = ZERO;

		do
		{
			printf("1- ID\n");
			printf("2- Name\n");
			printf("3- Gender\n");
			printf("4- Contact Number\n");
			printf("5- Password\n");
			printf("6- Exit\n");
			printf("Selection :");
			scanf("%d", &choice);
		} while (!checkingUserSelection(choice, SIX));
		StaffInformationDetail finding[999];
		StaffInformationDetail modifyData;
		FILE *modifyACC;
		modifyACC = fopen("staff.txt", "r");
		if (choice == 1)
		{
			printf("New ID :");
			scanf("%s", &modifyData.require.ID);
			rewind(stdin);
			while (fscanf(modifyACC, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding[i].require.ID, &finding[i].require.passWord, &finding[i].name, &finding[i].gender, &finding[i].contactNumber) != EOF)
			{
				if (strcmp(finding[i].require.ID, modifyFunction.require.ID) == ZERO && strcmp(finding[i].require.passWord, modifyFunction.require.passWord) == ZERO)
				{
					strcpy(finding[i].require.ID, modifyData.require.ID);

				}
				i++;
				accountcount++;
			}
		}
		else if (choice == TWO)
		{
			printf("New Name :");
			scanf("%[^\n]", &modifyData.name);
			rewind(stdin);
			while (fscanf(modifyACC, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding[i].require.ID, &finding[i].require.passWord, &finding[i].name, &finding[i].gender, &finding[i].contactNumber) != EOF)
			{
				if (strcmp(finding[i].require.ID, modifyFunction.require.ID) == ZERO && strcmp(finding[i].require.passWord, modifyFunction.require.passWord) == ZERO)
				{
					strcpy(finding[i].name, modifyData.name);

				}
				i++;
				accountcount++;
			}
		}
		else if (choice == THREE)
		{
			printf("New Gender :");
			scanf("%c", &modifyData.gender);
			rewind(stdin);
			while (fscanf(modifyACC, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding[i].require.ID, &finding[i].require.passWord, &finding[i].name, &finding[i].gender, &finding[i].contactNumber) != EOF)
			{
				if (strcmp(finding[i].require.ID, modifyFunction.require.ID) == ZERO && strcmp(finding[i].require.passWord, modifyFunction.require.passWord) == ZERO)
				{
					strcpy(finding[i].gender, modifyData.gender);

				}
				i++;
				accountcount++;
			}
		}
		else if (choice == FOUR)
		{
			printf("New Contact Number :");
			scanf("%s", &modifyData.contactNumber);
			rewind(stdin);
			while (fscanf(modifyACC, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding[i].require.ID, &finding[i].require.passWord, &finding[i].name, &finding[i].gender, &finding[i].contactNumber) != EOF)
			{
				if (strcmp(finding[i].require.ID, modifyFunction.require.ID) == ZERO && strcmp(finding[i].require.passWord, modifyFunction.require.passWord) == ZERO)
				{
					strcpy(finding[i].contactNumber, modifyData.contactNumber);

				}
				i++;
				accountcount++;
			}
		}
		else if (choice == FIVE)
		{
			printf("New Password :");
			scanf("%s", &modifyData.require.passWord);
			rewind(stdin);
			while (fscanf(modifyACC, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding[i].require.ID, &finding[i].require.passWord, &finding[i].name, &finding[i].gender, &finding[i].contactNumber) != EOF)
			{
				if (strcmp(finding[i].require.ID, modifyFunction.require.ID) == ZERO && strcmp(finding[i].require.passWord, modifyFunction.require.passWord) == ZERO)
				{
					strcpy(finding[i].require.passWord, modifyData.require.passWord);

				}
				i++;
				accountcount++;
			}
		}
		else
		{
			printf("Thanks for using\n");
			system("pause");
			exit(-1);
		}
		fclose(modifyACC);
		FILE*writeIntoFIle;
		writeIntoFIle = fopen("staff.txt", "w");
		for (j = ZERO; j < accountcount; j++)
		{
			fprintf(writeIntoFIle, "%s:%s:%s:%c:%s\n", finding[j].require.ID, finding[j].require.passWord, finding[j].name, finding[j].gender, finding[j].contactNumber);
		}
		fclose(writeIntoFIle);
		puts("");
		do
		{
			printf("1. Modify\n");
			printf("2. Program Menu\n");
			printf("3. Staff Information Menu\n");
			printf("4. Exit\n");
			rewind(stdin);
			scanf("%d", &selection);
		} while (!checkingUserSelection(selection, FOUR));

		if (selection == FOUR)
		{
			printf("Thanks for using\n");
			system("pause");
			exit(-1);
		}
	} while (selection == ONE);
	return selection;
}
int staffSearch(StaffInformationDetail searchFunction)
{
	int choice;
	int selection = ZERO;
	do
	{


		system("cls");
		printf("                                      ▄████████     ███        ▄████████    ▄████████    ▄████████                                    \n");
		printf("                                     ███    ███ ▀█████████▄   ███    ███   ███    ███   ███    ███                                    \n");
		printf("                                     ███    █▀     ▀███▀▀██   ███    ███   ███    █▀    ███    █▀                                     \n");
		printf("                                     ███            ███   ▀   ███    ███  ▄███▄▄▄      ▄███▄▄▄                                        \n");
		printf("                                   ▀███████████     ███     ▀███████████ ▀▀███▀▀▀     ▀▀███▀▀▀                                        \n");
		printf("                                            ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                      ▄█    ███     ███       ███    ███   ███          ███                                           \n");
		printf("                                    ▄████████▀     ▄████▀     ███    █▀    ███          ███                                           \n");
		printf("                                                                                                                                      \n");
		printf("           ▄█  ███▄▄▄▄      ▄████████  ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████     ███      ▄█   ▄██████▄  ███▄▄▄▄        \n");
		printf("          ███  ███▀▀▀██▄   ███    ███ ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ▀█████████▄ ███  ███    ███ ███▀▀▀██▄      \n");
		printf("          ███▌ ███   ███   ███    █▀  ███    ███   ███    ███ ███   ███   ███   ███    ███    ▀███▀▀██ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███  ▄███▄▄▄     ███    ███  ▄███▄▄▄▄██▀ ███   ███   ███   ███    ███     ███   ▀ ███▌ ███    ███ ███   ███      \n");
		printf("          ███▌ ███   ███ ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀▀▀   ███   ███   ███ ▀███████████     ███     ███▌ ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███ ▀███████████ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          ███  ███   ███   ███        ███    ███   ███    ███ ███   ███   ███   ███    ███     ███     ███  ███    ███ ███   ███      \n");
		printf("          █▀    ▀█   █▀    ███         ▀██████▀    ███    ███  ▀█   ███   █▀    ███    █▀     ▄████▀   █▀    ▀██████▀   ▀█   █▀       \n");
		printf("                                                   ███    ███                                                                         \n");
		printf("   ?????????    ?????????    ?????????    ?????????  ?????????    ??    ??    \n");
		printf("  ???    ???   ???    ???   ???    ???   ???    ??? ???    ???   ???    ???   \n");
		printf("  ???    ??    ???    ??    ???    ???   ???    ??? ???    ??    ???    ???   \n");
		printf("  ???         ???????       ???    ???  ??????????? ???         ????????????? \n");
		printf("???????????? ????????     ???????????? ??????????   ???        ?????????????  \n");
		printf("         ???   ???    ??    ???    ??? ???????????? ???    ??    ???    ???   \n");
		printf("   ??    ???   ???    ???   ???    ???   ???    ??? ???    ???   ???    ???   \n");
		printf(" ??????????    ??????????   ???    ??    ???    ??? ?????????    ???    ??    \n");
		printf("                                         ???    ???                           \n");
		printf("\n");
		printf("\n");
		printf("\n");
		do
		{
			printf("1- ID\n");
			printf("2- Name\n");
			printf("3- Gender\n");
			printf("4-- Contact Number\n");
			printf("5- Exit\n");
			printf("Selection :");
			scanf("%d", &choice);
		} while (!checkingUserSelection(choice, FIVE));
		StaffInformationDetail finding;
		FILE*displayInfo;
		displayInfo = fopen("staff.txt", "r");

		if (choice == ONE)
		{
			while (fscanf(displayInfo, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding.require.ID, &finding.require.passWord, &finding.name, &finding.gender, &finding.contactNumber) != EOF)
			{
				if (strcmp(finding.require.ID, searchFunction.require.ID) == ZERO && strcmp(finding.require.passWord, searchFunction.require.passWord) == ZERO)
				{
					printf("Your ID             : %s\n", finding.require.ID);

					break;
				}
			}
		}
		else if (choice == TWO)
		{
			while (fscanf(displayInfo, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding.require.ID, &finding.require.passWord, &finding.name, &finding.gender, &finding.contactNumber) != EOF)
			{
				if (strcmp(finding.require.ID, searchFunction.require.ID) == ZERO && strcmp(finding.require.passWord, searchFunction.require.passWord) == ZERO)
				{
					printf("Your Name           : %s\n", finding.require.passWord);


					break;
				}
			}
		}
		else if (choice == THREE)
		{
			while (fscanf(displayInfo, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding.require.ID, &finding.require.passWord, &finding.name, &finding.gender, &finding.contactNumber) != EOF)
			{
				if (strcmp(finding.require.ID, searchFunction.require.ID) == ZERO && strcmp(finding.require.passWord, searchFunction.require.passWord) == ZERO)
				{

					printf("Your Gender         : %c\n", finding.gender);


					break;
				}
			}
		}
		else if (choice == FOUR)
		{
			while (fscanf(displayInfo, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &finding.require.ID, &finding.require.passWord, &finding.name, &finding.gender, &finding.contactNumber) != EOF)
			{
				if (strcmp(finding.require.ID, searchFunction.require.ID) == ZERO && strcmp(finding.require.passWord, searchFunction.require.passWord) == ZERO)
				{


					printf("Your Contact Number : %s\n", finding.contactNumber);

					break;
				}
			}
		}
		else
		{
			printf("Thanks for using\n");
			system("pause");
			exit(-1);
		}
		puts("");
		do
		{
			printf("1. Search\n");
			printf("2. Program Menu\n");
			printf("3. Staff Information Menu\n");
			printf("4. Exit\n");
			rewind(stdin);
			scanf("%d", &selection);
		} while (!checkingUserSelection(selection, FOUR));

		if (selection == FOUR)
		{
			printf("Thanks for using\n");
			system("pause");
			exit(-1);
		}

	} while (selection == ONE);

	return selection;
}

void afterloginMenu(UserInformation login)
{

	int afterLogIn;
	int i = ZERO;
	do
	{


		do
		{
			system("cls");
			//afterLoginMenuLogo();
			printf("1. Facility Modules\n");
			printf("2. Booking Modules\n");;
			printf("3. Edit Account\n");
			printf("4. Exit\n");
			printf("Your Selection :");
			scanf("%d", &afterLogIn);
		} while (!checkingUserSelection(afterLogIn, FOUR));
		if (afterLogIn == ONE)
		{
			system("cls");
			i = ZERO;
			i = facilityModules();
		}
		else if (afterLogIn == TWO)
		{
			system("cls");
			i = ZERO;
			i = bookingModules();
		}
		else if (afterLogIn == THREE)
		{
			system("cls");
			i = ZERO;
			i = editMenu(login);
		}
		else
		{
			system("cls");
			//logoThankyou();
			system("pause");
			exit(-1);
		}
	} while (i == ONE || i == FOUR || i == TWO);

}
int loginedMenu(StaffInformationDetail loginDetail)
{
	int selection;
	int i = ZERO;
	do
	{


		system("cls");
		printf("                                          ▄▄▄▄███▄▄▄▄      ▄████████ ███▄▄▄▄   ███    █▄                                              \n");
		printf("                                        ▄██▀▀▀███▀▀▀██▄   ███    ███ ███▀▀▀██▄ ███    ███                                             \n");
		printf("                                        ███   ███   ███   ███    █▀  ███   ███ ███    ███                                             \n");
		printf("                                        ███   ███   ███  ▄███▄▄▄     ███   ███ ███    ███                                             \n");
		printf("                                        ███   ███   ███ ▀▀███▀▀▀     ███   ███ ███    ███                                             \n");
		printf("                                        ███   ███   ███   ███    █▄  ███   ███ ███    ███                                             \n");
		printf("                                        ███   ███   ███   ███    ███ ███   ███ ███    ███                                             \n");
		printf("                                         ▀█   ███   █▀    ██████████  ▀█   █▀  ████████▀                                              \n");
		printf("                                                                                                                                      \n");

		printf("\n");
		printf("\n");
		printf("\n");
		printf("1. Facility Modules\n");
		printf("2. Booking Modules\n");
		printf("3. Facility Usage Modules\n");
		printf("4. Edit Account\n");
		printf("5. Exit\n");
		printf("Selection :");
		scanf("%d", &selection);

		if (selection == ONE)
		{
			system("cls");
			i = facilityModules();
		}
		else if (selection == TWO)
		{
			system("cls");
			i = bookingModules();
		}
		else if (selection == THREE)
		{
			system("cls");
			i = facilityUsageModules();
		}
		else if (selection == FOUR)
		{
			system("cls");
			i = staffinformationMenu(loginDetail);
		}
	} while (i == TWO);
}

int bookingModules()

{
	int choice, selection;
	do
	{


		system("cls");

		do
		{
			system("cls");
			printf(" ______   _____   _____  _    _ _____ ______   ______    ______   _____  _____   _     _ _       _______ \n");
			printf("(____  \\ / ___ \\ / ___ \\| |  / |_____)  ___ \\ / _____)  |  ___ \\ / ___ \\(____ \\ | |   | | |     (_______)\n");
			printf(" ____)  ) |   | | |   | | | / /   _  | |   | | /  ___   | | _ | | |   | |_   \\ \\| |   | | |      _____   \n");
			printf("|  __  (| |   | | |   | | |< <   | | | |   | | | (___)  | || || | |   | | |   | | |   | | |     |  ___)  \n");
			printf("| |__)  ) |___| | |___| | | \\ \\ _| |_| |   | | \\____/|  | || || | |___| | |__/ /| |___| | |_____| |_____ \n");
			printf("|______/ \\_____/ \\_____/|_|  \\_|_____)_|   |_|\\_____/   |_||_||_|\\_____/|_____/  \\______|_______)_______)\n\n");
			printf("HOW CAN I HELP YOU?\n");
			printf("1- ADD BOOKING.\n");
			printf("2- SEARCH BOOKING.\n");
			printf("3- DISPLAY BOOKING.\n");
			printf("4- MODIFY BOOKING.\n");
			printf("5- Exit.\n");
			puts("");
			printf("Please enter your choice. > ");
			scanf("%d", &choice);
		} while (choice <1 || choice > 5);

		if (choice == 1)
		{
			addBooking();
		}
		else if (choice == 2)
		{
			searchBooking();
		}
		else if (choice == 3)
		{
			displayBooking();
		}
		else if (choice == 4)
		{
			modifyBooking();
		}
		else if (choice == 5)
		{
			printf("Thank You");
			system("pause");
			exit(-1);
		}

		do
		{
			printf("1- Booking Menu\n");
			printf("2- Modules Menu\n");
			printf("3- Exit\n");
			printf("Selection :");
			scanf("%d", &selection);
		} while (selection < 1 || selection >  3);
		if (selection == 3)
		{
			printf("Thank You");
			system("pause");
			exit(-1);
		}
	} while (selection == 1);
	return selection;
}
void addBooking()
{
	system("cls");
	int checking = ZERO, chooseTime;
	int bookingMenu, programMenu;
	bookingUse checkBooking;
	bookingUse addBooking;
	rewind(stdin);
	puts("");
	printf("Enter Your Facility ID : ");
	scanf("%[^\n]", &addBooking.facilityId);
	rewind(stdin);
	printf("Enter Facility Name(court): ");
	scanf("%[^\n]", &addBooking.facilityName);
	rewind(stdin);
	printf("Enter your User ID : ");
	scanf("%[^\n]", &addBooking.userId);
	rewind(stdin);
	printf("Enter Booking Date : ");
	scanf("%[^\n]", &addBooking.bookingdate);
	rewind(stdin);
	printf("1. 8.00am - 10.00am\n");
	printf("2. 10.00am - 12.00pm\n");
	printf("3. 12.00pm - 2.00pm\n");
	printf("4. 2.00pm - 4.00pm\n");
	printf("Please Select Your Booking Time. (1-4) :");
	scanf("%d", &chooseTime);
	if (chooseTime == 1)
	{
		strcpy(addBooking.bookingtime, "8.00am");
		strcpy(addBooking.bookingtimeuntil, "10.00am");
	}
	else if (chooseTime == 2)
	{
		strcpy(addBooking.bookingtime, "10.00am");
		strcpy(addBooking.bookingtimeuntil, "12.00pm");
	}
	else if (chooseTime == 3)
	{
		strcpy(addBooking.bookingtime, "12.00pm");
		strcpy(addBooking.bookingtimeuntil, "2.00pm");
	}
	else if (chooseTime == 4)
	{
		strcpy(addBooking.bookingtime, "2.00pm");
		strcpy(addBooking.bookingtimeuntil, "4.00pm");
	}

	FILE *bookingADD;
	bookingADD = fopen("booking.txt", "r");
	if (bookingADD == NULL)
	{
		printf("File Not Found\n");
		system("pause");
		exit(-1);
	}
	while (fscanf(bookingADD, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &checkBooking.facilityId, &checkBooking.facilityName, &checkBooking.userId, &checkBooking.bookingdate, &checkBooking.bookingtime, &checkBooking.bookingtimeuntil) != EOF)
	{
		if (strcmp(checkBooking.facilityId, addBooking.facilityId) == ZERO && strcmp(checkBooking.bookingtime, addBooking.bookingtime) == ZERO && strcmp(checkBooking.bookingdate, addBooking.bookingdate) == ZERO)
		{
			checking += 1;
		}
	}
	fclose(bookingADD);
	bookingADD = fopen("booking.txt", "a");
	if (bookingADD == NULL)
	{
		printf("File Not Found\n");
		system("pause");
		exit(-1);
	}
	if (checking != 1)
	{
		printf("Congrats!!Your booking already confirmed.\n");
		fprintf(bookingADD, "%s:%s:%s:%s:%s:%s\n", addBooking.facilityId, addBooking.facilityName, addBooking.userId, addBooking.bookingdate, addBooking.bookingtime, addBooking.bookingtimeuntil);

	}
	else
	{
		printf("\n");
		printf("Sorry,This Facility already booked by others.\n");

	}
	fclose(bookingADD);

}
void modifyBooking()
{
	system("cls");
	char menu;
	int chooseTime, chooseTime2;
	int i = ZERO, count = ZERO, selection, k = ZERO, makeSure = ZERO;
	bookingUse bookingFind[999];
	bookingUse inputOld;
	bookingUse inputNew;
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

	system("cls");
	printf("MODIFY BOOKING.\n");
	printf("----------------\n");
	printf("1. Facility ID\n");
	printf("2. Facility Name\n");
	printf("3. User ID\n");
	printf("4. Booking Date\n");
	printf("5. Booking Time\n\n");
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
		printf("Select Your Your Booking Time. (1-4) :");
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

		for (int j = ZERO; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == ZERO && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == ZERO && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == ZERO)
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
		printf("Please Select Your Booking Time. (1-4) :");
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
		for (int j = ZERO; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == ZERO && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == ZERO && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == ZERO)
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
		printf("Please Select Your Booking Time. (1-4) :");
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
		for (int j = ZERO; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == ZERO && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == ZERO && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == ZERO)
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
		printf("Please Select Your Booking Time. (1-4) :");
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
		for (int j = ZERO; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == ZERO && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == ZERO && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == ZERO)
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
		printf("Please Select Your Booking Time. (1-4) :");
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
		for (int j = ZERO; j < count; j++)
		{
			if (strcmp(inputOld.facilityId, bookingFind[j].facilityId) == ZERO && strcmp(inputOld.bookingdate, bookingFind[j].bookingdate) == ZERO && strcmp(inputOld.bookingtime, bookingFind[j].bookingtime) == ZERO)
			{
				printf("New Booking Time\n");
				printf("1. 8.00am - 10.00am\n");
				printf("2. 10.00am - 12.00pm\n");
				printf("3. 12.00pm - 2.00pm\n");
				printf("4. 2.00pm - 4.00pm\n");
				printf("Please Select Your Booking Time. (1-4) :");
				scanf("%d", &chooseTime2);
				if (chooseTime2 == 1)
				{
					strcpy(bookingFind[j].bookingtime, "8.00am");
					strcpy(bookingFind[j].bookingtimeuntil, "10.00am");
				}
				else if (chooseTime2 == 2)
				{
					strcpy(bookingFind[j].bookingtime, "10.00am");
					strcpy(bookingFind[j].bookingtimeuntil, "12.00pm");
				}
				else if (chooseTime2 == 3)
				{
					strcpy(bookingFind[j].bookingtime, "12.00pm");
					strcpy(bookingFind[j].bookingtimeuntil, "2.00pm");
				}
				else if (chooseTime2 == 4)
				{
					strcpy(bookingFind[j].bookingtime, "2.00pm");
					strcpy(bookingFind[j].bookingtimeuntil, "4.00pm");
				}
				makeSure += 1;
			}
		}
	}
	else
	{
		printf("\nINVALID SELECTION.\n\n");
	}


	if (makeSure == 1)
	{
		FILE *writeIntoFile;
		writeIntoFile = fopen("booking.txt", "w");
		for (k = ZERO; k < count; k++)
		{
			fprintf(writeIntoFile, "%s:%s:%s:%s:%s:%s", bookingFind[k].facilityId, bookingFind[k].facilityName, bookingFind[k].userId, bookingFind[k].bookingdate, bookingFind[k].bookingtime, bookingFind[k].bookingtimeuntil);
			fclose(writeIntoFile);
		}

	}

}
void searchBooking()
{
	system("cls");
	char menu;
	bookingUse searchInput;
	bookingUse search;


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
		if (strcmp(searchInput.facilityId, search.facilityId) == ZERO && strcmp(searchInput.bookingdate, search.bookingdate) == ZERO)
		{
			system("cls");
			printf("BELOW IS THE BOOKING DETAILS.\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Facility ID :%s\n", search.facilityId);
			printf("Facility Name :%s\n", search.facilityName);
			printf("User ID :%s\n", search.userId);
			printf("Booking Date :%s\n", search.bookingdate);
			printf("Booking Time: %s - %s\n", search.bookingtime, search.bookingtimeuntil);
		}
		else if (strcmp(searchInput.facilityId, search.facilityId) == ZERO && strcmp(searchInput.bookingdate, search.bookingdate) == ZERO)
		{
			system("cls");
			printf("Opps sorry,this booking doesn't exist.\n");
			break;
		}
		/*else
		{
		system("cls");
		printf("Opps sorry,this booking doesn't exist.\n");
		break;
		}*/
	}
	fclose(find);


}
void displayBooking()
{
	system("cls");
	char menu;
	bookingUse display;
	FILE* displayuse;
	displayuse = fopen("booking.txt", "r");
	if (displayuse == NULL)
	{
		printf("FILE Not Found\n");
		system("pause");
		exit(-1);
	}
	system("cls");
	printf("BOOKING LIST.\n");
	printf("==============\n");
	while (fscanf(displayuse, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &display.facilityId, &display.facilityName, &display.userId, &display.bookingdate, &display.bookingtime, &display.bookingtimeuntil) != EOF)
	{
		printf("%s:%s:%s:%s:%s-%s\n", display.facilityId, display.facilityName, display.userId, display.bookingdate, display.bookingtime, display.bookingtimeuntil);
		printf("---------------------------------------------------------\n");
	}
	puts("");


}

int facilityModules()
{
	int choice, selection;

	choice = 0;
	choice = facilityMenu();
	if (choice == 1)
	{
		displayFacility();
	}
	else if (choice == 2)
	{
		searchFacility();

	}
	else if (choice == 3)
	{
		addFacility();

	}
	else if (choice == 4)
	{
		modifyFacility();
	}


	do
	{
		printf("1- Facility Menu\n");
		printf("2- Modules Menu\n");
		printf("3- Exit\n");
		printf("Selection :");
		scanf("%d", &selection);
	} while (selection < 1 || selection >  3);
	if (selection == 3)
	{
		printf("Thank You");
		system("pause");
		exit(-1);
	}

	return selection;
}
int facilityMenu()
{
	system("cls");
	int choice;
	printf("Facility Menu\n");
	printf("=============\n");
	printf("1. Dislay Facility List / Facility Menu\n");
	printf("2. Search Facility Menu\n");
	printf("3. Add New Facility\n");
	printf("4. Modify Facility Menu\n");
	printf("5. Previous Menu\n");
	printf("Enter your option>> ");
	scanf("%d", &choice);
	printf("\n");
	return choice;

}
void displayFacility()
{
	system("cls");
	int i;
	Facility facilityMenu[30];
	FILE* display;
	display = fopen("facilitymenu.txt", "r");
	if (!display)
	{
		printf("Error. Invalid File.");
		system("pause");
		exit(-1);
	}

	printf("\t\t==================\n");
	printf("\t\t||Facility Menu List||\n");
	printf("\t\t==================\n");
	printf("Facility ID         Facility Type      Venue        Facility Allowed Number User\n");
	printf("================================================================================\n");
	printf("|||||||              |||||||||||       |||||           |||||||||||||||||||\n");
	printf("__________________________________________________________________________________________________________\n");
	i = ZERO;
	while (fscanf(display, "%[^|]|%[^|]|%[^|]|%[^|]|%d|\n", &facilityMenu[i].facilityID, &facilityMenu[i].facilityType, &facilityMenu[i].facilityDesc, &facilityMenu[i].facilityVenue, &facilityMenu[i].totalUsers) != EOF)
	{
		printf("%-12.8s         %-13.25s  %-25.25s  %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
		printf("Desc : %s\n", facilityMenu[i].facilityDesc);
		printf("__________________________________________________________________________________________________________\n");


		i++;
	}
	fclose(display);
	system("pause");




}
void searchFacility()
{
	int choice;
	char yesno;
	int i;
	int found = ZERO;

	do
	{


		system("cls");
		Facility facilityMenu[30] = { ZERO }, check;
		FILE* display;
		display = fopen("facilitymenu.txt", "r");
		if (!display)
		{
			printf("Error. Invalid File.\n");
			system("pause");
			exit(-1);
		}
		i = ZERO;
		while (fscanf(display, "%[^|]|%[^|]|%[^|]|%[^|]|%d|\n", &facilityMenu[i].facilityID, &facilityMenu[i].facilityType, &facilityMenu[i].facilityDesc, &facilityMenu[i].facilityVenue, &facilityMenu[i].totalUsers) != EOF)
		{
			i++;
		}
		do {
			printf("||========================||\n");
			printf("||Search the facility menu||\n");
			printf("||========================||\n");
			printf("1. Search By Facility Type\n");
			printf("2. Search By Facility ID\n");
			printf("3. Return to previous page\n");
			printf("Enter to select:");
			rewind(stdin);
			scanf("%d", &choice);
			if (choice == 1)
			{
				printf("Please enter the Facility Type:");
				rewind(stdin);
				scanf("%[^\n]", &check.facilityType);
				for (i = ZERO, found = ZERO; i < 30 && found != 1; i++)
				{
					if (strcmp(check.facilityType, facilityMenu[i].facilityType) == ZERO)
					{
						printf("Facility ID         Facility Type            Venue        Facility Allowed Number User\n");
						printf("==========================================================================================\n");
						printf("|||||||              |||||||||||             |||||           |||||||||||||||||||\n");
						printf("%-12.8s         %-25.25s %-25.25s  %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
						printf("Desc : %s\n", facilityMenu[i].facilityDesc);
						printf("_______________________________________________________________________________\n");
						found = 1;
					}
					else if (strcmp(check.facilityType, facilityMenu[i].facilityType) != ZERO && i == 29)
					{
						printf("____________________________________________\n");
						printf("No result\n");
						printf("The facility is not found in the Facility Menu !\n");
						printf("____________________________________________\n");
					}

				}
				printf("Would you like to proceed by searching another facility(Y/N):");
				rewind(stdin);
				scanf("%c", &yesno);
				if (yesno == 'Y' || yesno == 'y')
				{
					searchFacility();
				}


			}

			else if (choice == 2)
			{
				printf("Please enter the Facility ID number:");
				rewind(stdin);
				scanf("%[^\n]", &check.facilityID);

				for (i = ZERO, found = ZERO; i < 30 && found != 1; i++)
				{
					if (strcmp(check.facilityID, facilityMenu[i].facilityID) == ZERO)
					{
						printf("Facility ID         Facility Type            Venue        Facility Allowed Number User\n");
						printf("==========================================================================================\n");
						printf("|||||||              |||||||||||             |||||           |||||||||||||||||||\n");
						printf("%-12.8s         %-25.25s %-25.25s  %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
						printf("Desc : %s\n", facilityMenu[i].facilityDesc);
						printf("_____________________________________________________________________\n");
						found = 1;
					}
					else if (strcmp(check.facilityID, facilityMenu[i].facilityID) != ZERO && i == 29)
					{
						printf("____________________________________________\n");
						printf("No result\n");
						printf("The facility is not found in the Facility Menu !\n");
						printf("____________________________________________\n");
					}

				}

			}
			else
				printf("Invalid choice. Please select again\n");
		} while (choice != 3 && choice != 2 && choice != 1);
		printf("Would you like to proceed by searching another facility(Y/N):");
		rewind(stdin);
		scanf("%c", &yesno);
	} while (yesno == 'Y' || yesno == 'y');
}
void addFacility()
{

	int choice;
	Facility check;
	char yesno, yesno2;


	FILE* addfacility;
	addfacility = fopen("facilitymenu.txt", "a");
	if (!addfacility)
	{
		printf("Error. Invalid File.\n");
		system("pause");
		exit(-1);
	}
	do
	{
		printf("||========================||\n");
		printf("||----Add new facility----||\n");
		printf("||========================||\n");
		printf("Enter (Y/y) to proceed or (N/n) to return to previous page\n");
		scanf("%c", &yesno);
		if (yesno == 'Y' || yesno == 'y')
		{
			system("cls");
			printf("||----NEW FACILITY DETAILS----||\n");
			printf("\nEnter new Facility Type:");
			rewind(stdin);
			scanf("%[^\n]", &check.facilityType);
			printf("\nEnter new Facility ID:");
			rewind(stdin);
			scanf("%[^\n]", &check.facilityID);
			printf("\nEnter new Facility Description:");
			rewind(stdin);
			scanf("%[^\n]", &check.facilityDesc);
			printf("\nEnter new Facility Allowed User:");
			rewind(stdin);
			scanf("%d", &check.totalUsers);
			printf("\nEnter new Venue:");
			rewind(stdin);
			scanf("%[^\n]", &check.facilityVenue);
			printf("\n");

			printf("Facility ID         Facility Type            Venue        Facility Allowed Number User\n");
			printf("==========================================================================================\n");
			printf("|||||||              |||||||||||             |||||           |||||||||||||||||||\n");
			printf("%-12.8s         %-25.25s %-25.25s  %d\n", check.facilityID, check.facilityType, check.facilityVenue, check.totalUsers);
			printf("Desc : %s\n", check.facilityDesc);

			printf("Are you confirm to add this new facility into the Facility Menu(Y for Yes)(N to Previous Page\n");
			rewind(stdin);
			scanf("%c", &yesno2);
			if (yesno2 == 'Y' || yesno2 == 'y')
			{
				fprintf(addfacility, "%s|%s|%s|%s|%d|\n", check.facilityID, check.facilityType, check.facilityDesc, check.facilityVenue, check.totalUsers);
				fclose(addfacility);
			}

			else
			{
				printf("Invalid choice. Please enter again!");
			}

			printf("What to do next?\n");
			printf("1. Add another new facility\n");
			printf("2. Return to previous page\n");
			scanf(" %d", &choice);

		}

	} while (choice == 1);

}
void modifyFacility()
{
	int i;
	int choice, option;
	int found;
	char yesno, yesno2, searchFacilityType[50], searchFacilityID[50];
	Facility facilityMenu[30] = { ZERO }, check;

	FILE* modifyfacility;
	modifyfacility = fopen("facilitymenu.txt", "r");
	if (!modifyfacility)
	{
		printf("Error. Invalid File.\n");
		system("pause");
		exit(-1);
	}
	i = ZERO;
	while (fscanf(modifyfacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|\n", &facilityMenu[i].facilityID, &facilityMenu[i].facilityType, &facilityMenu[i].facilityDesc, &facilityMenu[i].facilityVenue, &facilityMenu[i].totalUsers) != EOF)
	{
		i++;
	}
	fclose(modifyfacility);



	do {
		printf("||<<-------------------->>||\n");
		printf("||<<Modify Facility Menu>>||\n");
		printf("||<<-------------------->>||\n");
		printf("Enter (Y/y) to proceed or (N/n) to return to previous page\n");
		rewind(stdin);
		scanf("%c", &yesno);
		if (yesno == 'Y' || yesno == 'y')
		{

			do {
				printf("Search the Facility to be modified by:\n");
				printf("1. Search by Facility Type\n");
				printf("2. Search by Facility ID\n");
				printf("Enter to select:");
				rewind(stdin);
				scanf("%d", &choice);
				printf("\n");
				if (choice == 1)
				{
					printf("Please enter the Facility Type to search:");
					rewind(stdin);
					scanf("%[^\n]", &searchFacilityType);

					for (i = ZERO, found = ZERO; i < 30 && found != 1; i++)
					{
						if (strcmp(searchFacilityType, facilityMenu[i].facilityType) == ZERO)
						{
							modifyFacilitySub(i, facilityMenu);
							found = 1;
						}
						else if (strcmp(searchFacilityType, facilityMenu[i].facilityType) != ZERO && i == 29)
						{
							printf("____________________________________________\n");
							printf("No result\n");
							printf("The facility is not found in the Facility Menu !\n");
							printf("____________________________________________\n");
						}
					}

				}
				else if (choice == 2)
				{
					printf("Please enter the Facility ID to search:");
					rewind(stdin);
					scanf("%[^\n]", &searchFacilityID);
					for (i = ZERO, found = ZERO; i < 30 && found != 1; i++)
					{
						if (strcmp(searchFacilityID, facilityMenu[i].facilityID) == ZERO)
						{
							modifyFacilitySub(i, facilityMenu);
							found = 1;
						}
						else if (strcmp(searchFacilityID, facilityMenu[i].facilityType) != ZERO && i == 29)
						{
							printf("____________________________________________\n");
							printf("No result\n");
							printf("The facility is not found in the Facility Menu !\n");
							printf("____________________________________________\n");
						}
					}
				}
				else
					printf("Invalid choice. Please enter again.\n");

			} while (choice != 2 && choice != 1);
			do
			{
				printf("Would you like to modify another facility?\n");
				rewind(stdin);
				scanf("%c", &yesno);
				if (tolower(yesno) == 'y')
				{
					modifyFacility();
				}
				else if (tolower(yesno) == 'n')
				{
					facilityModules();
				}
				else
					printf("Invalid choice. Please enter again.\n");
			} while (tolower(yesno) == 'n' && tolower(yesno) == 'y');
		}
		else if (yesno == 'n' || yesno == 'N')
		{
			facilityModules();
		}
		else
			printf("Invalid choice. Please enter again.\n");
	} while (tolower(yesno) != 'n' && tolower(yesno) != 'y');
}
void modifyFacilitySub(int i, Facility facilityMenu[30])
{
	Facility  check;
	int option;
	char yesno2;
	FILE* modifyfacility;
	modifyfacility = fopen("facilitymenu.txt", "w");


	printf("Facility ID         Facility Type      Venue        Facility Allowed Number User\n");
	printf("================================================================================\n");
	printf("|||||||              |||||||||||       |||||           |||||||||||||||||||\n");
	printf("%-12.8s         %-25.25s %-25.25s  %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
	printf("Desc : %s\n", facilityMenu[i].facilityDesc);
	printf("_______________________________________________________________________________\n");

	printf("1. Modify the Total Allowed User\n");
	printf("2. Modify the Facility ID\n");
	printf("3. Modify the Facility Description\n");
	printf("4. Modify the Facility Type\n");
	printf("5. Modify the Venue\n");
	printf("6. Modify Facility Type + Facility Description + Venue + Total Allowed User\n");
	printf("7. Return to Facility Menu\n");
	rewind(stdin);
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		printf("Enter Total Allowed User:");
		rewind(stdin);
		scanf("%d", &check.totalUsers);
		printf("Are you sure of the change(Y/N)\n");
		printf("Facility ID         Facility Type      Venue        Facility Allowed Number User\n");
		printf("================================================================================\n");
		printf("|||||||              |||||||||||       |||||           |||||||||||||||||||\n");
		printf("%-12.8s         %-25.25s %-25.25s  %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
		printf("                                                >>>>>>>>>>\n");
		printf("                                                %d\n", check.totalUsers);
		printf("Desc : %s\n", facilityMenu[i].facilityDesc);
		printf("_______________________________________________________________________________\n");
		rewind(stdin);
		printf("Confirm the change (Y/N):");
		scanf("%c", &yesno2);
		printf("\n");
		if (yesno2 == 'Y' || yesno2 == 'y')
			facilityMenu[i].totalUsers = check.totalUsers;
		else if (yesno2 == 'N' || yesno2 == 'n')
			system("cls");
		break;
	case 2:
		printf("Enter new Facility ID:");
		rewind(stdin);
		scanf("%[^\n]", &check.facilityID);
		printf("Are you sure of the change(Y/N)\n");
		printf("Facility ID         Facility Type      Venue        Facility Allowed Number User\n");
		printf("================================================================================\n");
		printf("|||||||              |||||||||||       |||||           |||||||||||||||||||\n");
		printf("%-12.8s         %-25.25s %-25.25s %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
		printf(">>>>>>>             \n");
		printf("%s\n", check.facilityID);
		printf("Desc : %s\n", facilityMenu[i].facilityDesc);
		printf("_______________________________________________________________________________\n");
		printf("Confirm the change (Y/N):");
		scanf(" %c", &yesno2);
		printf("\n");
		if (yesno2 == 'Y' || yesno2 == 'y')
			strcpy(facilityMenu[i].facilityID, check.facilityID);
		else if (yesno2 == 'N' || yesno2 == 'n')
			system("cls");
		break;
	case 3:
		printf("Enter new Facility Description:");
		rewind(stdin);
		scanf("%[^\n]", &check.facilityDesc);
		printf("Are you sure of the change(Y/N)\n");
		printf("Facility ID         Facility Type      Venue        Facility Allowed Number User\n");
		printf("================================================================================\n");
		printf("|||||||              |||||||||||       |||||           |||||||||||||||||||\n");
		printf("%-12.8s         %-25.25s %-25.25s %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
		printf("Desc : %s\n", facilityMenu[i].facilityDesc);
		printf(">>>>>>>>>>>>>>>>>>>>>\n");
		printf("%s\n", check.facilityDesc);
		printf("_______________________________________________________________________________\n");
		printf("Confirm the change (Y/N):");
		rewind(stdin);
		scanf("%c", &yesno2);
		printf("\n");
		if (yesno2 == 'Y' || yesno2 == 'y')
			strcpy(facilityMenu[i].facilityDesc, check.facilityDesc);
		else if (yesno2 == 'N' || yesno2 == 'n')
			system("cls");
		break;
	case 4:
		printf("Enter new Facility Type:");
		rewind(stdin);
		scanf("%[^\n]", &check.facilityType);
		printf("Are you sure of the change(Y/N)\n");
		printf("Facility ID         Facility Type      Venue        Facility Allowed Number User\n");
		printf("================================================================================\n");
		printf("|||||||              |||||||||||       |||||           |||||||||||||||||||\n");
		printf("%-12.8s         %-25.25s %-25.25s %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
		printf("                     >>>>>>>>>>>>               ||||||||||\n");
		printf("                     %s\n", check.facilityType);
		printf("Desc : %s\n", facilityMenu[i].facilityDesc);
		printf("_______________________________________________________________________________\n");
		printf("Confirm the change (Y/N):");
		rewind(stdin);
		scanf("%c", &yesno2);
		printf("\n");
		if (yesno2 == 'Y' || yesno2 == 'y')
			strcpy(facilityMenu[i].facilityType, check.facilityType);
		else if (yesno2 == 'N' || yesno2 == 'n')
			system("cls");
		break;
	case 5:
		printf("Enter new Venue:");
		rewind(stdin);
		scanf("%[^\n]", &check.facilityVenue);
		printf("Are you sure of the change(Y/N)\n");
		printf("Facility ID         Facility Type      Venue        Facility Allowed Number User\n");
		printf("================================================================================\n");
		printf("|||||||              |||||||||||       |||||           |||||||||||||||||||\n");
		printf("%-12.8s         %-25.25s %-25.25s %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
		printf(">>>>>>>>>>>>>>>>>>>>>\n");
		printf("%s\n", check.facilityVenue);
		printf("Desc : %s\n", facilityMenu[i].facilityDesc);
		printf("_______________________________________________________________________________\n");
		printf("Confirm the change (Y/N):");
		rewind(stdin);
		scanf("%c", &yesno2);
		printf("\n");
		if (yesno2 == 'Y' || yesno2 == 'y')
			strcpy(facilityMenu[i].facilityVenue, check.facilityVenue);
		else if (yesno2 == 'N' || yesno2 == 'n')
			system("cls");
		break;
	case 6:
		printf("Enter new Facility Type:");
		rewind(stdin);
		scanf("%[^\n]", &check.facilityType);
		printf("\n");
		printf("Enter new Venue:");
		rewind(stdin);
		scanf("%[^\n]", &check.facilityVenue);
		printf("\n");
		printf("Enter new Facility ID:");
		rewind(stdin);
		scanf("%[^\n]", &check.facilityID);
		printf("\n");
		printf("Enter new Facility Description:");
		rewind(stdin);
		scanf("%[^\n]", &check.facilityDesc);
		printf("\n");
		printf("Enter new Facility Allowed User:");
		rewind(stdin);
		scanf("%d", &check.totalUsers);
		printf("\n");

		printf("Are you sure of the change(Y/N)\n");
		printf("Facility ID         Facility Type      Venue        Facility Allowed Number User\n");
		printf("================================================================================\n");
		printf("|||||||              |||||||||||       |||||           |||||||||||||||||||\n");
		printf("%-12.8s         %-25.25s %-25.25s %d\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
		printf(">>>>>>>>             >>>>>>>>>>>>               >>>>>>>>>>\n");
		printf("%-12.8s         %-25.25s %-25.25s %d\n", check.facilityID, check.facilityType, check.facilityVenue, check.totalUsers);
		printf("Desc : %s\n", facilityMenu[i].facilityDesc);
		printf(">>>>>>>>>>>>>>>>>>>>>\n");
		printf("%s\n", check.facilityDesc);
		printf("_______________________________________________________________________________\n");
		printf("Confirm the change (Y/N):");
		rewind(stdin);
		scanf("%c", &yesno2);
		printf("\n");
		if (yesno2 == 'Y' || yesno2 == 'y')
		{
			strcpy(facilityMenu[i].facilityID, check.facilityID);
			strcpy(facilityMenu[i].facilityType, check.facilityType);
			strcpy(facilityMenu[i].facilityVenue, check.facilityVenue);
			strcpy(facilityMenu[i].facilityDesc, check.facilityDesc);
			facilityMenu[i].totalUsers = check.totalUsers;
		}
		else if (yesno2 == 'N' || yesno2 == 'n')
			system("cls");
		break;
	case 7:
		facilityModules();
		break;
	default:
		printf("Invalid selection. Please enter again");
	}
	for (i = ZERO; i < 30 && facilityMenu[i].totalUsers != ZERO; i++)
	{
		fprintf(modifyfacility, "%s|%s|%s|%s|%d|\n", facilityMenu[i].facilityID, facilityMenu[i].facilityType, facilityMenu[i].facilityDesc, facilityMenu[i].facilityVenue, facilityMenu[i].totalUsers);
	}
	fclose(modifyfacility);


}

int facilityUsageModules()
{
	int selection;

	do
	{

		int selection2;
		system("cls");
		printf("  ____|            _)  | _)  |               |   |                                 \\  |             |         |                      \n");
		printf("  |     _` |   __|  |  |  |  __|  |   |      |   |   __|   _` |   _` |   _ \\      |\\/ |   _ \\    _` |  |   |  |   _ \\             \n");
		printf("  __|  (   |  (     |  |  |  |    |   |      |   | \\__ \\  (   |  (   |   __/      |   |  (   |  (   |  |   |  |   __/               \n");
		printf(" _|   \\__,_| \\___| _| _| _| \\__| \\__, |     \\___/  ____/ \\__,_| \\__, | \\___|     _|  _| \\___/  \\__,_| \\__,_| _| \\___|     \n");
		printf("                               ___/                      ____/                                                                        \n");
		puts("");


		printf("1. Add Facility Usage\n");
		printf("2. Modify Facility Usage\n");
		printf("3. Display Facility Usage\n");
		printf("4. Search Facility Usage\n");
		printf("Selection :");
		scanf("%d", &selection2);

		if (selection2 == 1)
		{
			addFacilityUsage();
		}
		else if (selection2 == 2)
		{
			modifyFacilityUsage();
		}
		else if (selection2 == 3)
		{
			displayFacilityUsage();
		}
		else if (selection2 == 4)
		{
			searchFacilityUsage();
		}
		printf("\n");
		do
		{
			printf("1- Facility Usage Menu\n");
			printf("2- Modules Menu\n");
			printf("3- Exit\n");
			printf("Selection :");
			scanf("%d", &selection);
		} while (selection < 1 || selection >  3);
		if (selection == 3)
		{
			printf("Thank You");
			system("pause");
			exit(-1);
		}
	} while (selection == ONE);
	return selection;
}
void addFacilityUsage()
{
	system("cls");
	int selection, check = ZERO;
	char choice;
	facilityUsage addFunction;

	printf("              _     _   ______         _ _ _ _           _    _                                  \n");
	printf("     /\\      | |   | | |  ____|       (_) (_) |         | |  | |                                \n");
	printf("    /  \\   __| | __| | | |__ __ _  ___ _| |_| |_ _   _  | |  | |___  __ _  __ _  ___            \n");
	printf("   / /\\ \\ / _` |/ _` | |  __/ _` |/ __| | | | __| | | | | |  | / __|/ _` |/ _` |/ _ \\         \n");
	printf("  / ____ \\ (_| | (_| | | | | (_| | (__| | | | |_| |_| | | |__| \\__ \\ (_| | (_| |  __/         \n");
	printf(" /_/    \\_\\__,_|\\__,_| |_|  \\__,_|\\___|_|_|_|\\__|\\__, |  \\____/|___/\\__,_|\\__, |\\___| \n");
	printf("                                                  __/ |                    __/ |                 \n");
	printf("                                                 |___/                    |___/                  \n");
	puts("");

	printf("Enter ID :");
	rewind(stdin);
	scanf("%[^\n]", &addFunction.finding.idInput);
	FILE * facilityUsageAdd;
	facilityUsageAdd = fopen("booking.txt", "r");
	if (facilityUsageAdd == NULL)
	{
		printf(" Error. Invalid File\n");
		system("pause");
		exit(-1);

	}
	while (fscanf(facilityUsageAdd, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &addFunction.facilityId, &addFunction.facilityName, &addFunction.userId, &addFunction.bookingdate, &addFunction.bookingtime, &addFunction.bookingtimeuntil) != EOF)
	{
		if (addFunction.finding.idInput, addFunction.userId)
		{
			printf("Facility ID            : %s\n", addFunction.facilityId);
			printf("Facility Name          : %s\n", addFunction.facilityName);
			printf("User ID                : %s\n", addFunction.userId);
			printf("Booking Date           : %s\n", addFunction.bookingdate);
			printf("Booking Time           : %s - %s\n", addFunction.bookingtime, addFunction.bookingtimeuntil);
			printf("\n");
			printf("1. Walk In Booking\n");
			printf("2. Online Booking\n");
			printf("Selection :");
			scanf("%d", &selection);
			if (selection == 1)
			{
				strcpy(addFunction.walkinORonline, "Walk In Booking");
				printf("Walk In Time :");
				rewind(stdin);
				scanf("%[^\n]", &addFunction.walkinOROnlineTime);
			}
			else if (selection == 2)
			{
				strcpy(addFunction.walkinORonline, "Online Booking");
				printf("Online Booking Time :");
				rewind(stdin);
				scanf("%[^\n]", &addFunction.walkinOROnlineTime);
			}
			check += 1;
			break;
		}
	}
	fclose(facilityUsageAdd);
	FILE*facilityUsageAdd2;
	facilityUsageAdd2 = fopen("facilityusage.txt", "a");
	if (facilityUsageAdd2 == NULL)
	{
		printf(" Error. Invalid File\n");
		system("pause");
		exit(-1);

	}
	if (check == 1)
	{
		fprintf(facilityUsageAdd2, "%s:%s:%s:%s:%s:%s:%s:%s\n", addFunction.facilityId, addFunction.facilityName, addFunction.userId, addFunction.bookingdate, addFunction.bookingtime, addFunction.bookingtimeuntil, addFunction.walkinORonline, addFunction.walkinOROnlineTime);

	}
	fclose(facilityUsageAdd2);
	system("pause");
}
void modifyFacilityUsage()
{
	system("cls");
	int i = ZERO, selection, count = ZERO, j, check = ZERO, choice, sure = ZERO;
	char choice2;
	facilityUsage modifyFunction[999];
	facilityUsage modifyFunctionInput;
	facilityUsage modifyFunctionInputForModify;
	FILE*facilityUsageMdify;
	facilityUsageMdify = fopen("facilityusage.txt", "r");
	if (facilityUsageMdify == NULL)
	{
		printf(" Error. Invalid File\n");
		system("pause");
		exit(-1);

	}
	while (fscanf(facilityUsageMdify, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &modifyFunction[i].facilityId, &modifyFunction[i].facilityName, &modifyFunction[i].userId, &modifyFunction[i].bookingdate, &modifyFunction[i].bookingtime, &modifyFunction[i].bookingtimeuntil, &modifyFunction[i].walkinORonline, &modifyFunction[i].walkinOROnlineTime) != EOF)
	{
		i++;
		count++;
	}
	printf("  __  __           _ _  __         ______         _ _ _ _           _    _                                    \n");
	printf(" |  \\/  |         | (_)/ _|       |  ____|       (_) (_) |         | |  | |                                  \n");
	printf(" | \\  / | ___   __| |_| |_ _   _  | |__ __ _  ___ _| |_| |_ _   _  | |  | |___  __ _  __ _  ___              \n");
	printf(" | |\\/| |/ _ \\ / _` | |  _| | | | |  __/ _` |/ __| | | | __| | | | | |  | / __|/ _` |/ _` |/ _ \\           \n");
	printf(" | |  | | (_) | (_| | | | | |_| | | | | (_| | (__| | | | |_| |_| | | |__| \\__ \\ (_| | (_| |  __/            \n");
	printf(" |_|  |_|\\___/ \\__,_|_|_|  \\__, | |_|  \\__,_|\\___|_|_|_|\\__|\\__, |  \\____/|___/\\__,_|\\__, |\\___|   \n");
	printf("                            __/ |                            __/ |                    __/ |                   \n");
	printf("                           |___/                            |___/                    |___/                    \n");
	puts("");

	printf("1. Facility ID\n");
	printf("2. Facility Name\n");
	printf("3. User ID\n");
	printf("4. Booking Date\n");
	printf("5. Booking Time\n");
	printf("6. Walking Or Online\n");
	printf("7. Walking Or Online Time\n");

	printf("Selection :");
	scanf("%d", &selection);
	if (selection == 1)
	{
		system("cls");
		printf("Enter User ID: ");
		rewind(stdin);
		scanf("%[^\n]", &modifyFunctionInput.userId);
		for (j = ZERO; j < count; j++)
		{
			if (strcmp(modifyFunctionInput.userId, modifyFunction[j].userId) == ZERO)
			{
				printf("   ____         _ ___ __         _______           \n");
				printf("  / __/__ _____(_) (_) /___ __  /  _/ _ \\         \n");
				printf(" / _// _ `/ __/ / / / __/ // / _/ // // /          \n");
				printf("/_/  \\_,_/\\__/_/_/_/\\__/\\_, / /___/____/       \n");
				printf("                       /___/                       \n");
				puts("");

				printf("OLD Faclity ID                     : %s\n", modifyFunction[j].facilityId);
				puts("");
				printf("NEW Faclity ID                     :");
				rewind(stdin);
				scanf("%[^\n]", &modifyFunctionInputForModify.facilityId);
				strcpy(modifyFunction[j].facilityId, modifyFunctionInputForModify.facilityId);
				sure += 1;
			}
		}
	}

	else if (selection == 2)
	{
		system("cls");
		printf("Enter User ID: ");
		rewind(stdin);
		scanf("%[^\n]", &modifyFunctionInput.userId);
		for (j = ZERO; j < count; j++)
		{
			if (strcmp(modifyFunctionInput.userId, modifyFunction[j].userId) == ZERO)
			{
				printf("   ____         _ ___ __         _  __                     \n");
				printf("  / __/__ _____(_) (_) /___ __  / |/ /__ ___ _  ___        \n");
				printf(" / _// _ `/ __/ / / / __/ // / /    / _ `/  ' \/ -_)       \n");
				printf("/_/  \\_,_/\\__/_/_/_/\\__/\\_, / /_/|_/\\_,_/_/_/_/\\__/  \n");
				printf("                      /___/                                \n");
				puts("");

				printf("OLD Facility Name                     : %s\n", modifyFunction[j].facilityName);
				puts("");
				printf("NEW Facility Name                     :");
				rewind(stdin);
				scanf("%[^\n]", &modifyFunctionInputForModify.facilityName);
				strcpy(modifyFunction[j].facilityName, modifyFunctionInputForModify.facilityName);
				sure += 1;
			}
		}
	}
	else if (selection == 3)
	{
		system("cls");
		printf("Enter User ID: ");
		rewind(stdin);
		scanf("%[^\n]", &modifyFunctionInput.userId);
		for (j = ZERO; j < count; j++)
		{
			if (strcmp(modifyFunctionInput.userId, modifyFunction[j].userId) == ZERO)
			{
				printf("  __  __             _______        \n");
				printf(" / / / /_____ ____  /  _/ _ \\      \n");
				printf("/ /_/ (_-< -_) __/ _/ // // /       \n");
				printf("\\____/___|__/_/   /___/____/       \n");
				puts("");

				printf("OLD User ID                     : %s\n", modifyFunction[j].userId);
				puts("");
				printf("NEW User ID                     :");
				rewind(stdin);
				scanf("%[^\n]", &modifyFunctionInputForModify.userId);
				strcpy(modifyFunction[j].userId, modifyFunctionInputForModify.userId);
				sure += 1;
			}
		}
	}
	else if (selection == 4)
	{
		system("cls");
		printf("Enter User ID: ");
		rewind(stdin);
		scanf("%[^\n]", &modifyFunctionInput.userId);
		for (j = ZERO; j < count; j++)
		{
			if (strcmp(modifyFunctionInput.userId, modifyFunction[j].userId) == ZERO)
			{
				printf("   ___            __    _             ___       __                \n");
				printf("  / _ )___  ___  / /__ (_)__  ___ _  / _ \\___ _/ /____           \n");
				printf(" / _  / _ \\/ _ \\/  '_// / _ \\/ _ `/ / // / _ `/ __/ -_)        \n");
				printf("/____/\\___/\\___/_/\\_\\/_/_//_/\\_, / /____/\\_,_/\\__/\\__/    \n");
				printf("                            /___/                                 \n");
				puts("");

				printf("OLD Booking Date                     : %s\n", modifyFunction[j].bookingdate);
				puts("");
				printf("NEW Booking Date                     :");
				rewind(stdin);
				scanf("%[^\n]", &modifyFunctionInputForModify.bookingdate);
				strcpy(modifyFunction[j].bookingdate, modifyFunctionInputForModify.bookingdate);
				sure += 1;
			}
		}
	}
	else if (selection == 5)
	{
		system("cls");
		printf("Enter User ID: ");
		rewind(stdin);
		scanf("%[^\n]", &modifyFunctionInput.userId);
		for (j = ZERO; j < count; j++)
		{
			if (strcmp(modifyFunctionInput.userId, modifyFunction[j].userId) == ZERO)
			{
				sure += 1;
				printf("   ___            __    _             _______                     \n");
				printf("  / _ )___  ___  / /__ (_)__  ___ _  /_  __(_)_ _  ___            \n");
				printf(" / _  / _ \\/ _ \\/  '_// / _ \\/ _ `/   / / / /  ' \\/ -_)       \n");
				printf("/____/\\___/\\___/_/\\_\\/_/_//_/\\_, /   /_/ /_/_/_/_/\\__/      \n");
				printf("                            /___/                                 \n");
				puts("");

				printf("OLD Booking Time                     : %s-%s\n", modifyFunction[j].bookingtime, modifyFunction[j].bookingtimeuntil);
				puts("");
				printf("NEW Booking Date                     :\n");
				printf("1. 8.00am - 10.00am\n");
				printf("2. 10.00am - 12.00pm\n");
				printf("3. 12.00pm - 2.00pm\n");
				printf("4. 2.00pm - 4.00pm\n");
				printf("Selection :");
				scanf("%d", &choice);
				if (choice == 1)
				{
					strcpy(modifyFunction[j].bookingtime, "8.00am");
					strcpy(modifyFunction[j].bookingtimeuntil, "10.00am");
				}
				else if (choice == 2)
				{

					strcpy(modifyFunction[j].bookingtime, "10.00am");
					strcpy(modifyFunction[j].bookingtimeuntil, "12.00pm");
				}
				else if (choice == 3)
				{
					strcpy(modifyFunction[j].bookingtime, "12.00pm");
					strcpy(modifyFunction[j].bookingtimeuntil, "2.00pm");
				}
				else if (choice == 2)
				{
					strcpy(modifyFunction[j].bookingtime, "2.00pm");
					strcpy(modifyFunction[j].bookingtimeuntil, "4.00pm");
				}

			}
		}
	}
	else if (selection == 6)
	{
		system("cls");
		printf("Enter User ID: ");
		rewind(stdin);
		scanf("%[^\n]", &modifyFunctionInput.userId);
		for (j = ZERO; j < count; j++)
		{
			if (strcmp(modifyFunctionInput.userId, modifyFunction[j].userId) == ZERO)
			{
				printf("  _      __     ____     _        ____        ____       ___                   \n");
				printf(" | | /| / /__ _/ / /__  (_)__    / __ \\____  / __ \\___  / (_)__  ___         \n");
				printf(" | |/ |/ / _ `/ /  '_/ / / _ \\  / /_/ / __/ / /_/ / _ \/ / / _ \\/ -_)        \n");
				printf(" |__/|__/\\_,_/_/_/\\_\\ /_/_//_/  \\____/_/    \\____/_//_/_/_/_//_/\\__/     \n");
				puts("");

				printf("OLD Walk In Or Online Booking                     : %s\n", modifyFunction[j].walkinORonline);
				puts("");
				printf("NEW Walk In Or Online Booking                     :");
				printf("1 . Walk In\n");
				printf("2. Online Booking\n");
				scanf("%d", &choice);
				if (choice == 1)
				{
					strcpy(modifyFunction[j].walkinORonline, "Walk In");

				}
				else if (choice == 2)
				{
					strcpy(modifyFunction[j].walkinORonline, "Online Booking");

				}
				sure += 1;
			}
		}
	}
	else if (selection == 7)
	{
		system("cls");
		printf("Enter User ID: ");
		rewind(stdin);
		scanf("%[^\n]", &modifyFunctionInput.userId);
		for (j = ZERO; j < count; j++)
		{
			if (strcmp(modifyFunctionInput.userId, modifyFunction[j].userId) == ZERO)
			{
				printf("  _      __     ____     _        ____        ____       ___            _______                   \n");
				printf(" | | /| / /__ _/ / /__  (_)__    / __ \\____  / __ \\___  / (_)__  ___   /_  __(_)_ _  ___        \n");
				printf(" | |/ |/ / _ `/ /  '_/ / / _ \\  / /_/ / __/ / /_/ / _ \\/ / / _ \\/ -_)   / / / /  ' \\/ -_)     \n");
				printf(" |__/|__/\\_,_/_/_/\\_\\ /_/_//_/  \\____/_/    \\____/_//_/_/_/_//_/\\__/   /_/ /_/_/_/_/\\__/   \n");
				puts("");

				printf("Walk In Or Online Booking Time   : %s\n", modifyFunction[j].walkinORonline);
				printf("Old %s Time                      : %s\n", modifyFunction[j].walkinORonline, modifyFunction[j].walkinOROnlineTime);
				printf("New %s Time                      :", modifyFunction[j].walkinORonline);
				rewind(stdin);
				scanf("%[^\n]", &modifyFunctionInputForModify.walkinOROnlineTime);
				strcpy(modifyFunction[j].walkinOROnlineTime, modifyFunctionInputForModify.walkinOROnlineTime);
				sure += 1;
			}
		}
	}
	fclose(facilityUsageMdify);
	if (sure == 1)
	{
		FILE*facilityUsageMdify2;
		facilityUsageMdify2 = fopen("facilityusage.txt", "w");
		if (facilityUsageMdify2 == NULL)
		{
			printf(" Error. Invalid File\n");
			system("pause");
			exit(-1);

		}
		for (int k = ZERO; k < count; k++)
		{
			fprintf(facilityUsageMdify2, "%s:%s:%s:%s:%s:%s:%s:%s\n", modifyFunction[k].facilityId, modifyFunction[k].facilityName, modifyFunction[k].userId, modifyFunction[k].bookingdate, modifyFunction[k].bookingtime, modifyFunction[k].bookingtimeuntil, modifyFunction[k].walkinORonline, modifyFunction[k].walkinOROnlineTime);
			fclose(facilityUsageMdify2);
		}
	}
	system("pause");
}
void displayFacilityUsage()
{
	int i = 1;
	char choice;

	facilityUsage displayFunction;
	FILE*forDisplay;
	forDisplay = fopen("facilityusage.txt", "r");
	if (forDisplay == NULL)
	{
		printf(" Error. Invalid File\n");
		system("pause");
		exit(-1);

	}
	printf("\t\t\t\tFacility Usage\n");
	printf("---------------------------------------------------------------\n");
	while (fscanf(forDisplay, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &displayFunction.facilityId, &displayFunction.facilityName, &displayFunction.userId, &displayFunction.bookingdate, &displayFunction.bookingtime, &displayFunction.bookingtimeuntil, &displayFunction.walkinORonline, &displayFunction.walkinOROnlineTime) != EOF)
	{
		printf("  _____  _           _               ______         _ _ _ _           _    _                                       \n");
		printf(" |  __ \\(_)         | |             |  ____|       (_) (_) |         | |  | |                                     \n");
		printf(" | |  | |_ ___ _ __ | | __ _ _   _  | |__ __ _  ___ _| |_| |_ _   _  | |  | |___  __ _  __ _  ___                  \n");
		printf(" | |  | | / __| '_ \\| |/ _` | | | | |  __/ _` |/ __| | | | __| | | | | |  | / __|/ _` |/ _` |/ _ \\               \n");
		printf(" | |__| | \\__ \\ |_) | | (_| | |_| | | | | (_| | (__| | | | |_| |_| | | |__| \\__ \\ (_| | (_| |  __/             \n");
		printf(" |_____/|_|___/ .__/|_|\\__,_|\\__, | |_|  \\__,_|\\___|_|_|_|\\__|\\__, |  \\____/|___/\\__,_|\\__, |\\___|       \n");
		printf("              | |             __/ |                            __/ |                    __/ |                      \n");
		printf("              |_|            |___/                            |___/                    |___/                       \n");
		puts("");

		printf("\n------------------------------%d------------------------------\n", i);
		printf("Booking Date                   : %s\n", displayFunction.bookingdate);
		printf("Booking Time                   : %s-%s\n", displayFunction.bookingtime, displayFunction.bookingtimeuntil);
		printf("Booked By                      : %s\n", displayFunction.userId);
		printf("Faclity Name                   : %s\n", displayFunction.facilityName);
		printf("Faclity ID                     : %s\n", displayFunction.facilityId);
		printf("Walk In Or Online Booking      : %s\n", displayFunction.walkinORonline);
		printf("Walk In Or Online Booking Time : %s\n", displayFunction.walkinOROnlineTime);
		puts("");
		i++;
	}
	system("pause");
}
void searchFacilityUsage()
{
	int again = ZERO;
	do
	{
		facilityUsage searchFunction;
		FILE *forSearch;
		printf("   _____                     _       ______         _ _ _ _           _    _                                           \n");
		printf("  / ____|                   | |     |  ____|       (_) (_) |         | |  | |                                          \n");
		printf(" | (___   ___  __ _ _ __ ___| |__   | |__ __ _  ___ _| |_| |_ _   _  | |  | |___  __ _  __ _  ___                      \n");
		printf("  \\___ \\ / _ \\/ _` | '__/ __| '_ \\  |  __/ _` |/ __| | | | __| | | | | |  | / __|/ _` |/ _` |/ _ \\                \n");
		printf("  ____) |  __/ (_| | | | (__| | | | | | | (_| | (__| | | | |_| |_| | | |__| \\__ \\ (_| | (_| |  __/                   \n");
		printf(" |_____/ \\___|\\__,_|_|  \\___|_| |_| |_|  \\__,_|\\___|_|_|_|\\__|\\__, |  \\____/|___/\\__,_|\\__, |\\___|          \n");
		printf("                                                               __/ |                    __/ |                          \n");
		printf("                                                              |___/                    |___/                           \n");
		puts("");

		printf("Enter User ID :");
		rewind(stdin);
		scanf("%s", &searchFunction.finding.idInput);
		forSearch = fopen("facilityusage.txt", "r");
		if (forSearch == NULL)
		{
			printf(" Error. Invalid File\n");
			system("pause");
			exit(-1);

		}
		while (fscanf(forSearch, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]\n", &searchFunction.facilityId, &searchFunction.facilityName, &searchFunction.userId, &searchFunction.bookingdate, &searchFunction.bookingtime, &searchFunction.bookingtimeuntil, &searchFunction.walkinORonline, &searchFunction.walkinOROnlineTime) != EOF)
		{
			if (strcmp(searchFunction.finding.idInput, searchFunction.userId) == ZERO)
			{
				again += 1;
				printf("Booking Date                   : %s\n", searchFunction.bookingdate);
				printf("Booking Time                   : %s-%s\n", searchFunction.bookingtime, searchFunction.bookingtimeuntil);
				printf("Booked By                      : %s\n", searchFunction.userId);
				printf("Faclity Name                   : %s\n", searchFunction.facilityName);
				printf("Faclity ID                     : %s\n", searchFunction.facilityId);
				printf("Walk In Or Online Booking      : %s\n", searchFunction.walkinORonline);
				printf("Walk In Or Online Booking Time : %s\n", searchFunction.walkinOROnlineTime);
				puts("");
			}
		}
		if (again != 1)
		{
			printf("ID Error");
			system("pause");
		}
	} while (again != 1);
}

int checkingUserSelection(int userInputForChecking, int correctSelection)
{
	if (userInputForChecking > correctSelection)
	{
		return ZERO;
	}
	if (userInputForChecking <= correctSelection)
	{
		return 1;
	}
}