
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// minimum chars to pass username/password
#define MIN_pass 3
// minimum age
#define MIN_age 18
//maximum age 
#define MAX_AGE 100
enum {BASEBALL = 1, BASKETBALL = 2, BICYCLE = 3, 
	 BOOKS=4, DRAWING=5, GYM=6, MOVIES=7, POETRY=8 };
/*
strucr for the person women/men
*/
typedef struct
{
	char  *id;
	char *name;
	char *last;
	int age;
	char gender[1];
	char *username;
	char *password;
	char *Description;
	char hobbies;

} person;

//womennode linikd list 
typedef struct womenNode  womenNode;
struct womenNode
{
	person* personh;
	womenNode* next;

};
// women list of womennode 
typedef struct
{
	womenNode* head, *last;

} womanlist;
/*
declare of functions
Explanation will be provided in the relevant  following lines of code
*/
person* login_name(person **, womenNode*); 
char  *login_pass(person **, womenNode*);
char* id_cheak(person ** mans, womenNode* head);
int front_view_(person ** mans, womenNode* head, person *front);
womenNode* FindPlace(char*, womenNode*);
char *hoobiesscan(char*);
char hoobiesscannew(char*);
void findlove(person **, womenNode*, person *);
int hobbiesmatch(char, char);
void printhobiis(char);
int counter = 0;
void outtext(person ** mens, womenNode* head);
void printhobiis_out(char hobby,FILE* Fptr);
int main()
{   // int key for swich case
	int key;
	/* 
	creat *user 
	creat char [10] user explaine in next line code
	*/
	person *user;
	char users[10];
	// maloc for creacting manss pointers dinamic arry
	person** mans = (person *)malloc(sizeof(person));
	if (mans == NULL)
	{
		exit(1);
	}
	// creat womanlist 
	womanlist listw;
	listw.head = NULL;
	listw.last = NULL;
	// open file and read with strtoke
	FILE *f;
	char line[300];
	f = fopen("input.txt", "r");
	//read all lines 
	while (fgets(line, 300, f) != 0)
	{
		// create new pointer newp that get all new data
		person* newp = (person *)malloc(sizeof(person));
		if (mans == newp)
		{
			exit(1);
		}
		char *dammy;
		int  *dammy1;
		char *dammy3;
		char *dammy4;
		// read and save id from text
		dammy = strtok(line, ";");
		newp->id = (char *)malloc((strlen(dammy) + 1) * sizeof(char));
		if (newp->id == NULL)
		{
			exit(1);
		}
		strcpy(newp->id, dammy);
		dammy = strtok(NULL, ";");
		// read and save name from text
		newp->name = (char *)malloc((strlen(dammy) + 1) * sizeof(char));
		if (newp->name == NULL)
		{
			exit(1);
		}
		strcpy(newp->name, dammy);
		dammy = strtok(NULL, ";");
		// read and save last name from text
		newp->last = (char *)malloc((strlen(dammy) + 1) * sizeof(char));
		if (newp->last == NULL)
		{
			exit(1);
		}
		strcpy(newp->last, dammy);
		newp->age = atoi(strtok(NULL, ";"));
		dammy = strtok(NULL, ";");
		// read and save gender from text
		strcpy(newp->gender, dammy);
		dammy = strtok(NULL, ";");
		// read and save username from text
		newp->username = (char *)malloc((strlen(dammy) + 1) * sizeof(char));
		if (newp->username == NULL)
		{
			exit(1);
		}
		strcpy(newp->username, dammy);
		dammy = strtok(NULL, ";");
		// read and save password from text
		newp->password = (char *)malloc((strlen(dammy) + 1) * sizeof(char));
		if (newp->password == NULL)
		{
			exit(1);
		}
		strcpy(newp->password, dammy);
		dammy = strtok(NULL, ";");
		// read and save description from text
		dammy3 = strtok(NULL, ";");
		newp->Description = (char *)malloc((strlen(dammy3) + 1) * sizeof(char));
		if (newp->Description == NULL)
		{
			exit(1);
		}
		strcpy(newp->Description, dammy3);
		newp->hobbies = hoobiesscan(dammy);

		if (newp->gender[0] == 'F')
		{
			// Creating the node to store the persons data
			womenNode* neww = (womenNode *)malloc(sizeof(womenNode));
			neww->personh = newp;
			neww->next = NULL;

			// Add the node to the women list
			womenNode* temp;
			temp = FindPlace(newp->last, listw.head);
			// a new head
			if (NULL == temp) 
			{
				// for adding the first item (when the head is NULL).
				if (NULL == listw.head) 
				{
					neww->next = NULL;
				}
				else
				{
					neww->next = listw.head;
				}
				listw.head = neww;
			}
			else 
				// add in the midle 
			{
				neww->next = temp->next;
				temp->next = neww;
			}

			

		}

		if (newp->gender[0] == 'M')
		{
			// creating new men 
			counter++;
			// first men
			if (counter == 1)
			{

				mans[0] = newp;

			}

			else
				// realloc to nre place the mens with the new 
			{
				mans = (person **)realloc(mans, counter * sizeof(person*));
				mans[counter - 1] = newp;
			}

		}


	}
	// close the file
	fclose(f);
	// run the program infinity (have exit point in case 3)
	while (1 != 2)
	{
		printf("Welcome! please choose an option\n"
			"1 - Log in\n2 - New member\n3 - Exit \n");
		scanf("%d", &key);
		// switch case 
		switch (key)
		{
		case 1:
			// cheak if user exist in system give two chans
			user = login_name(mans, listw.head);
			// not exist 
			if (user == NULL)
			{
				break;
			}
			else
			{ 
				// after user name we cheak the paswword 
				strcpy(users, login_pass(mans, listw.head));
				// if eror
				if (users[0] == 'e')
				{
					printf("Wrong password\n");
					break;
				}
				// if corect 
				else
				{
					printf("Hello" " %s""!\n", users);
					// go to the front view of program 
					if (front_view_(mans, listw.head, user) == 22)
					{
						// will explain in function explaine 
						listw.head = listw.head->next;
					}
				}
			}

			break;
			// case two new member 
		case 2:
			// cheak if user not exist 
			strcpy(users, id_cheak(mans, listw.head));
			if (users[0] == 'e')
			{
				printf("Error: User already exists\n");
				break;

			}
			// new member
			else
			{
				// create new member 
				person* newp = (person *)malloc(sizeof(person));
				if (newp == NULL)
				{
					exit(1);
				}
				char dammy[200];
				int  dammy1;
				char dammy3[200];
				char dammy4;
				strcpy(dammy, users);
				newp->id = (char *)malloc(strlen(dammy) * sizeof(char)+1);
				if (newp->id == NULL)
				{
					exit(1);
				}
				strcpy(newp->id, dammy);
				// scan and save  the name 
				printf("Please enter your first name:\n");
				scanf("%s", dammy);
				newp->name = (char *)malloc(strlen(dammy) * sizeof(char)+1);
				if (newp->name == NULL)
				{
					exit(1);
				}
				strcpy(newp->name, dammy);
				// scan and save  the last name
				printf("Please enter your last name:\n");
				scanf("%s", dammy);
				newp->last = (char *)malloc(strlen(dammy) * sizeof(char)+1);
				if (newp->last == NULL)
				{
					exit(1);
				}
				strcpy(newp->last, dammy);
				// scan and save  the age
				printf("Please enter your age (18 to 100): \n");
				scanf("%d", &dammy1);
				// cheak if valid if not free 
				if ((dammy1 < MIN_age) || (dammy1 > MAX_AGE))
				{
					free(newp->name);
					free(newp->last);
					free(newp->id);
					free(newp);
					break;
				}
				newp->age = dammy1;
				// scan and save  the gender
				printf("Please enter your gender (F-female, M-male):\n");
				scanf("%s", dammy);
				strcpy(newp->gender, dammy);
				// scan and save  the username 
				printf("Choose a username (3-10 characters): \n");
				scanf("%s", dammy);
				// cheak if valid, if no free
				if (strlen(dammy) < MIN_pass)
				{

					free(newp->age);
					free(newp->name);
					free(newp->last);
					free(newp->id);
					free(newp);
					break;


				}
				// cheak if valid, if no free
				if (((dammy[0] < 'a') || (dammy[0] > 'z')) &&
					((dammy[0] < 'A') || (dammy[0] > 'Z')))
				{
					free(newp->age);
					free(newp->name);
					free(newp->last);
					free(newp->id);
					free(newp);
					break;


				}
				newp->username = (char *)malloc(strlen(dammy) * sizeof(char)+1);
				if (newp->username == NULL)
				{
					exit(1);
				}
				// the hobbis
				strcpy(newp->username, dammy);
				printf("please choose 4 hobbies: Baseball=1, Basketball=2, Bicycle=3,"
					" Books=4, Drawing=5, Gym=6, Movies=7, Poetry=8\n");
				scanf("%c", dammy);
				gets(dammy);
				newp->hobbies = hoobiesscannew(&dammy);
				// the password
				printf("Choose a password (attention-minimum 3 characters): \n");
				scanf("%s", dammy3);
				// cheak if valid, if no free
				if (strlen(dammy3) < MIN_pass)
				{
					free(newp->username);
					free(newp->age);
					free(newp->name);
					free(newp->last);
					free(newp->id);
					free(newp);
					break;

				}
				newp->password = (char *)malloc(strlen(dammy3) * sizeof(char)+1);
				if (newp->password == NULL)
				{
					exit(1);
				}
				strcpy(newp->password, dammy3);
				// discriptions
				printf("Some words about yourself:\n");
				scanf("%c", &dammy3);
				gets(&dammy3);
				strcat(dammy3, "\n");
				strcat(dammy3, "\0");
				newp->Description = (char *)malloc(strlen(dammy3) * sizeof(char)+1);
				if (newp->Description == NULL)
				{
					exit(1);
				}
				strcpy(newp->Description, dammy3);




				
				if (newp->gender[0] == 'F')
				{
					// Creating the node to store the persons data
					womenNode* neww = (womenNode *)malloc(sizeof(womenNode));
					neww->personh = newp;
					neww->next = NULL;

					// Add the node to the women list
					womenNode* temp;
					temp = FindPlace(newp->last, listw.head);
					// a new head 
					if (NULL == temp) 
					{
						// for adding the first item (when the head is NULL).
						if (NULL == listw.head) 
						{
							neww->next = NULL;
						}
						else
						{
							neww->next = listw.head;
						}
						listw.head = neww;
					}
					// add in the midle 
					else 
					{
						neww->next = temp->next;
						temp->next = neww;
					}
				}
				// new men
				if (newp->gender[0] == 'M')
				{

					counter++;
					// if it is the first men
					if (counter == 1)
					{

						mans[0] = newp;

					}

					else

					{
						// realloc for new place for new men 
						mans = (person **)realloc(mans, counter * sizeof(person*));
						if (mans == NULL)
						{
							exit(1);
						}
						mans[counter - 1] = newp;
					}

				}
				// after new signup
				printf("Hi" " %s" ", lets find love!\n", newp->name);
				// go to front view function 
				front_view_(mans, listw.head, newp);			
			}

			break;
		case 3:
		{
			// make output file 
			outtext(mans, listw.head);
			// free all the dynamic data 
			// mans free
			int i = 0;
			for (i = 0; i < counter; i++)
			{
				free(mans[i]->id);
				free(mans[i]->name);
				free(mans[i]->last);
				free(mans[i]->username);
				free(mans[i]->password);
				free(mans[i]->Description);

				free(mans[i]);
			}
			free(mans);
			// womens free
			while (listw.head)
			{
				listw.last = listw.head->next;

				free(listw.head->personh->id);
				free(listw.head->personh->last);
				free(listw.head->personh->name);
				free(listw.head->personh->username);
				free(listw.head->personh->Description);
				free(listw.head->personh->password);
				free(listw.head->personh);
				free(listw.head);

				listw.head = listw.last;
			}
			free(listw.last);
		}
		return 0;
		break;
		default:printf("Bad choice, please try again\n");
			break;
		}
	}
	return 0;
}

/************************************************************************
* function name: FindPlace
* The Function input:(char* newp_last, womenNode* head)// get the
lastname of new women 
The Function ouyput: the adress of the place that the new women need get 
* The Function operation:
the function cheak by the last name where is rhe place of the new
women in the liniked list 
*************************************************************************/
womenNode* FindPlace(char* newp_last, womenNode* head)
{
	womenNode *prev = NULL;
	womenNode *current = head;

	while (current != NULL)
	{
		// copere the last names of womens 
		if (strcmp(newp_last, current->personh->last) < 0)
		{
			break;
		}

		prev = current;
		current = current->next;
	}

	return prev;
}

/************************************************************************
* function name: login_name
* The Function input:person **, womenNode* // sturct of mens pointer and women node
The Function ouyput: person* give string with eror or yhe pointer to user name 
* The Function operation:
the function cheak if is a user in the data and if no give another chance
to put currect user name
*************************************************************************/
person *login_name(person ** mans, womenNode* head)
{ 
	// all verabels 
	char erorr[1];
	erorr[0] = 'e';
	int flag_man = 0;
	int flag_woman = 0;
	int i;
	char test[15];
	// first try 
	printf("Please enter your username:\n");
	scanf("%s", test);
	// cheak all mens user 
	for (i = 0; i < counter; i++)
	{
		if (strcmp(test, mans[i]->username) == 0)
		{
			flag_man++;
			return mans[i];
		}
	}
	//cheak all women users 
	womenNode *prev = NULL;
	womenNode *current = head;

	while (current != NULL)
	{
		if (strcmp(test, current->personh->username) != 0)
		{
			prev = current;
			current = current->next;
		}

		else
		{
			flag_woman++;
			return current->personh;
		}

	}
	// the second chans 
	if ((flag_man == 0) && (flag_woman == 0))
	{
		printf("User do not exist in the system, please try again\n");

		printf("Please enter your username:\n");
		scanf("%s", test);
		for (i = 0; i < counter; i++)
		{
			if (strcmp(test, mans[i]->username) == 0)
			{
				return mans[i];

			}
		}
		womenNode *prev = NULL;
		womenNode *current = head;

		while (current != NULL)
		{
			if (strcmp(test, current->personh->username) != 0)
			{
				prev = current;
				current = current->next;
			}
			else
			{
				return current->personh;
			}
		}

		{
			return NULL;
		}
	}

}

/************************************************************************
* function name: login_pass
* The Function input:person **, womenNode* // sturct of mens pointer and women node
The Function output: char* that indecate if its wrong pass or ok
* The Function operation:
the function cheak if is a user in the data and if no give another chance
to put currect user name
*************************************************************************/
char  *login_pass(person ** mans, womenNode* head)
{
	// all the verabels 
	char erors[1];
	erors[0] = 'e';
	int i;
	char testpass[16];
	printf("Please enter your password:\n");
	scanf("%s", testpass);
	// cheak all mens 
	for (i = 0; i < counter; i++)
	{
		if (strcmp(testpass, mans[i]->password) == 0)
		{
			strcpy(testpass, mans[i]->name);
			return testpass;

		}
	}
	// cheaks all womens 
	womenNode *prev = NULL;
	womenNode *current = head;
	while (current != NULL)
	{
		if (strcmp(testpass, current->personh->password) != 0)
		{
			prev = current;
			current = current->next;
		}
		else
		{
			strcpy(testpass, current->personh->name);
			return testpass;
		}

	}

	return erors;
}
/************************************************************************
* function name: id_cheak
* The Function input:person **, womenNode* // sturct of mens pointer and women node
The Function output: return eror if wrond id return the id if irs corect 
* The Function operation:
the function cheak if is a user in the data and if no give another chance
to put currect user name 
*************************************************************************/
char  *id_cheak(person ** mans, womenNode* head)

{
	int i;
	char testpass[10];
	char eror[1];
	eror[0] = 'e';
	printf("Please enter your ID:\n");
	scanf("%s", testpass);
	// cheak mens 
	for (i = 0; i < counter; i++)
	{
		// wrong
		if (strcmp(testpass, mans[i]->id) == 0)
		{
			return eror;

		}
	}
	// cheak womens 
	womenNode *prev = NULL;
	womenNode *current = head;
	while (current != NULL)
	{
		if (strcmp(testpass, current->personh->id) != 0)
		{
			prev = current;
			current = current->next;
		}
		else
		{
			// wrong case 
			return eror;
		}
	}
	return testpass;
}

/************************************************************************
* function name: front_view
* The Function input:person ** mans, womenNode* head, person *front
The Function output: char* the function output 22 when delete user 
* The Function operation:
the function is the front view of the spesific user that log to the site 
have 3 option find love, delte user or log out 
*************************************************************************/
int front_view_(person ** mans, womenNode* head, person *front)
{
	// all verabels
	int front_key;
	front_key = 0;
	while (front_key != 3)
	{
		int i;
		int j;
		printf("Please choose an option:\n"
			"1. Find a match\n2. I found love, DELETE me\n3. Log out\n");
		scanf("%d", &front_key);
		switch (front_key)
		{
		case 1:
			// find love 
			findlove(mans, head, front);
			break;
		case 2:
		{
			// delete user 
			if (front->gender[0] == 'F')
			{
				// find the women in list and delete 
				womenNode *prev = NULL;
				womenNode *current = head;
				while (current != NULL)
				{
					if (strcmp(front->username, current->personh->username) != 0)
					{
						prev = current;
						current = current->next;
					}
					else if (strcmp(front->username, current->personh->username) == 0)
					{
						// free all the women data if she first and link two next 
						if (prev != NULL)
						{
							prev->next = current->next;
							current->next = NULL;
							
							free(current->personh->id);
							free(current->personh->name);
							free(current->personh->username);
							free(current->personh->password);
							free(current->personh->last);
							free(current->personh->Description);
							free(current->personh);
							free(current);
							current = current->next;
						}

						{
							// free al data of the women and fix the links
							head = current->next;
							front = current->next;
							free(current->personh->id);
							free(current->personh->name);
							free(current->personh->username);
							free(current->personh->password);
							free(current->personh->last);
							free(current->personh->Description);
							free(current->personh);
							free(current);
							return 22;
							break;
						}
					}

				}
			}
			// if its men 
			if (front->gender[0] == 'M')

			{

				// change the pkace of mens sruct and delete the men who need 
				for (i = 0; i < counter; i++)
				{
					if (strcmp(front->username, mans[i]->username) == 0)
					{
						for (j = i; j < (counter - 1); j++)
						{
							mans[j] = mans[j + 1];

						}
						// dree all the spsific men data
						counter--;
						free(front->name);
						free(front->last);
						free(front->username);
						free(front->password);
						free(front->id);
						free(front->Description);

						free(front);
						return 0;
					}
				}
			}
		}
		break;
		case 3:
			// break from the case 
			front_key = 3;
			return;
			break;
		default:
			printf("Bad choice, please try again\n");
			return;
			break;
		}
	}
}


/************************************************************************
* function name: hoobiesscan
* The Function input:char*
The Function output: char* 
* The Function operation:
the function read from text the hobiis and for evry hobby he 
change bit from 0 to 1 
we have char with 8 bits 00000000
each hobby get one bit
*************************************************************************/
char *hoobiesscan(char* dammy)
{
	// all verabels 
	int i;
	int dummy;
	char bit;
	char bit1;
	char bit2;
	char bit3;
	bit = bit & 0;
	bit1 = bit1 & 0;
	bit2 = bit2 & 0;
	bit3 = bit3 & 0;
	// first number 1
	dummy = atoi(strtok(dammy, ","));
	bit |= 0X1;
	for (i = 1; i < dummy; i++)
	{
		bit = bit << 1;

	}
	// number 2
	dummy = atoi(strtok(NULL, ","));
	bit1 |= 0X1;
	for (i = 1; i < dummy; i++)
	{
		bit1 = bit1 << 1;

	}
	// number 3
	dummy = atoi(strtok(NULL, ","));
	bit2 |= 0X1;
	for (i = 1; i < dummy; i++)
	{
		bit2 = bit2 << 1;

	}
	// hobby 4
	dummy = atoi(strtok(NULL, "\0"));
	bit3 |= 0X1;
	for (i = 1; i < dummy; i++)
	{
		bit3 = bit3 << 1;

	}
	bit = bit | bit1 | bit2 | bit3;
	return bit;

}

/************************************************************************
* function name: hoobiesscannew
* The Function input:char*
The Function output: char
* The Function operation: not like (hoobiesscan)
tgis 
the function read from user the hobiis and for evry hobby he
change bit from 0 to 1
we have char with 8 bits 00000000
each hobby get one bit
*************************************************************************/
char hoobiesscannew(char *dammy)

{
	int i;
	int dummy;
	char bit;
	char bit1;
	char bit2;
	char bit3;
	bit = bit & 0;
	bit1 = bit1 & 0;
	bit2 = bit2 & 0;
	bit3 = bit3 & 0;

	dummy = atoi(strtok(dammy, " "));
	bit |= 0X1;
	for (i = 1; i < dummy; i++)
	{
		bit = bit << 1;

	}
	dummy = atoi(strtok(NULL, " "));
	bit1 |= 0X1;
	for (i = 1; i < dummy; i++)
	{
		bit1 = bit1 << 1;

	}
	dummy = atoi(strtok(NULL, " "));
	bit2 |= 0X1;
	for (i = 1; i < dummy; i++)
	{
		bit2 = bit2 << 1;

	}
	dummy = atoi(strtok(NULL, "\0"));
	bit3 |= 0X1;
	for (i = 1; i < dummy; i++)
	{
		bit3 = bit3 << 1;

	}
	bit = bit | bit1 | bit2 | bit3;
	return bit;
}

/************************************************************************
* function name: hobbiesmatch
* The Function input:vhar a, char b
The Function output: int 
* The Function operation:
the function get two chars that represents 

the honnys of women and men then she cheak the mach 
wee need at least 2 hobby mach 
*************************************************************************/
int hobbiesmatch(char a, char b)
{
	// all the verabels
	int counter_mach = 0;
	char save;
	char mach;
	mach = a & b;
	// cheak bit and shift ehile get 0 stop 
	while ((mach != 0) && (counter_mach < 2))
	{
		// maske that save the mache with &1
		save = (mach & 1);
		if (save == 1)
		{
			counter_mach++;
			mach = mach >> 1;
		}

		else
		{
			mach = mach >> 1;
		}
	}
	// cheak if have at least two hobbies
	if (counter_mach >= 2)
	{
		return 1;
	}
	else
		return 0;
}

/************************************************************************
* function name: findlove
* The Function input:person **mans, womenNode*head, person* front)
The Function output: nothink
* The Function operation:
function show all the mach of the user tha log in 
while cheaking hobbis and age ranges 
*************************************************************************/
void findlove(person **mans, womenNode*head, person* front)
{
	// all verabels
	int minrang;
	int maxreng;
	int i;
	// range
	printf("Please choose ages range: \n");
	scanf(" %d" " %d", &minrang, &maxreng);
	// if the user M we need cheak all womens 
	if (front->gender[0] == 'M')
	{
		// the women node 
		womenNode *prev = NULL;
		womenNode *current = head;
		while (current != NULL)
		{
			// cheak the age range 
			if (current->personh->age >= minrang)
			{
				if (current->personh->age <= maxreng)
				{
					// cheak the hobbies 
					if (hobbiesmatch(current->personh->hobbies, front->hobbies) == 1)
					{
						// print the mach 
						printf("Name:"" %s %s" " Age:"" %d "
							, current->personh->name, current->personh->last,
							current->personh->age);
						printhobiis(current->personh->hobbies);
						printf(" Description:"" %s\n", current->personh->Description);
						prev = current;
						current = current->next;
					}
					else
					{
						prev = current;
						current = current->next;
					}
				}

			}
			else
			{
				prev = current;
				current = current->next;
			}
		}

	}
	// if it is a F we need cheak all the mens 
	if (front->gender[0] == 'F')

	{
		for (i = 0; i < counter; i++)
		{
			// cheak the age rang
			if (mans[i]->age >= minrang)
			{
				if (mans[i]->age <= maxreng)
				{
					// cheak the hobbis 
					if (hobbiesmatch(mans[i]->hobbies, front->hobbies) == 1)
					{
						// print the hobbis 
						printf("Name:"" %s %s" " Age:"" %d "
							, mans[i]->name, mans[i]->last,
							mans[i]->age);
						printhobiis(mans[i]->hobbies);
						printf(" Description:"" %s\n", mans[i]->Description);

					}
				}
			}

		}
	}

}

/************************************************************************
* function name: printhobiis
* The Function input:char represnt hobbis 
The Function output: nothink
* The Function operation:
function print the hobbis by the bitwise use on the char 
*************************************************************************/
void printhobiis(char hobby)
{
	int counterhobbi = 0;
	printf("Hobbies:");
	/* i wiil cheak each place in the char
	that have 8 bits and cheak if it is 1 or 0 
	*/
	// first 
	if ((hobby & 00000001) == 00000001)
	{
		// counter hoobi we know that can have only 4 hobbis 
		counterhobbi++;
		printf(" Baseball,");

	}
	//  number second
	if ((hobby & 2) == 2)
	{
		 
		counterhobbi++;
		printf(" Basketball,");

	}
	// number 3
	if ((hobby & 4) == 4)
	{
		counterhobbi++;
		printf(" Bicycle,");

	}
	// number 4
	if ((hobby & 8) == 8)
	{
		counterhobbi++;
		if (counterhobbi == 4)
		{
			printf(" Books");
		}
		else
		{
			printf(" Books,");
		}
	}
	// number 5
	if ((hobby & 16) == 16)
	{
		counterhobbi++;
		if (counterhobbi == 4)
		{
			printf(" Drawing");
		}
		else
		{
			printf(" Drawing,");
		}
	}
	// number 6
	if ((hobby & 32) == 32)
	{
		counterhobbi++;
		if (counterhobbi == 4)
		{
			printf(" GYM");
		}
		else
		{
			printf(" Gym,");
		}
	}
	// number 7
	if ((hobby & 64) == 64)
	{
		counterhobbi++;
		if (counterhobbi == 4)
		{
			printf(" Movies");
		}
		else
		{
			printf(" Movies,");
		}
	}
	// last number 8
	if ((hobby & 128) == 128)
	{
		counterhobbi++;
		printf(" Poetry");
	}

}

/************************************************************************
* function name: outtext
* The Function input:(person ** mens, womenNode* head)
The Function output: nothink
* The Function operation:
function print to file all the data in mens and women database 
*************************************************************************/
void outtext(person ** mens, womenNode* head)
{
	// open file 
	FILE *f;;
	f = fopen("output.txt", "w");
	int i = 0;
	for (i = 0; i < counter; i++)
	{
		// print the mens 
			fprintf(f,"%s"";", mens[i]->id);
			fprintf(f,"%s"";", mens[i]->name);
			fprintf(f,"%s"";", mens[i]->last);
			fprintf(f,"%d"";", mens[i]->age);
			printhobiis_out(mens[i]->hobbies,f);
			fprintf(f,"%s", mens[i]->Description);


		
	}
	// print the women 
	womenNode *prev = NULL;
	womenNode *current = head;
	while (current != NULL)
	{

		fprintf(f, "%s"";""%s"";" "%s"";""%d"";"
			, current->personh->name,
			current->personh->name, current->personh->last,
			current->personh->age);
		printhobiis_out(current->personh->hobbies, f);
		fprintf(f, "%s", current->personh->Description);
			
		
		prev = current;
		current = current->next;
	}
	
	// close 
	fclose(f);
	return;
}
		
/************************************************************************
* function name: printhobiis_out
* The Function input:(char hobby,FILE* fptr)
The Function output: nothink
* The Function operation:
function help to convert the hobbis and  put them on the file  
*************************************************************************/
void printhobiis_out(char hobby,FILE* fptr)
{
	// all verabels 
	char hoobis[10];
	int counterhobbi = 0;
	int i=0;
	// convert the bitwise to numbers on file 
	if ((hobby & 00000001) == 00000001)
	{
		counterhobbi++;
		// counter to cheak whem we get 4 hobbis 
		fprintf(fptr, "%d,", 1);
		
	}
	// the second bitwise 
	if ((hobby & 2) == 2)
	{
		counterhobbi++;
		fprintf(fptr, "%d,", 2);
	}
	// other bitwiese 
	if ((hobby & 4) == 4)
	{
		counterhobbi++;
		fprintf(fptr, "%d,", 3);
	}
	// other bitwiese
	if ((hobby & 8) == 8)
	{
		counterhobbi++;
	   if (counterhobbi == 4)
		{
		   fprintf(fptr, "%d;", 4);
		   return;
		}
		else
		{
		   fprintf(fptr, "%d,", 4);
		}
		
	}
	// other bitwiese
	if ((hobby & 16) == 16)
	{
		counterhobbi++;
		if (counterhobbi == 4)
		{
			fprintf(fptr, "%d;", 5);
			return;
		}
		else
		{
			fprintf(fptr, "%d,", 5);
		}
		
	}
	// other bitwiese
	if ((hobby & 32) == 32)
	{
		counterhobbi++;
		if (counterhobbi == 4)
		{
			fprintf(fptr, "%d;", 6);
			return ;
		}
		else
		{
			fprintf(fptr, "%d,", 6);
		}
		// other bitwiese
	}
	if ((hobby & 64) == 64)
	{
		counterhobbi++;
		if (counterhobbi == 4)
		{
			fprintf(fptr, "%d;", 7);
			return ;
		}
		else
		{
			fprintf(fptr, "%d,", 7);
		}
		i++;
		i++;
	}
	// other bitwiese
	if ((hobby & 128) == 128)
	{
		counterhobbi++;
		fprintf(fptr, "%d;", 8);
		return;
	}
	return;
}

