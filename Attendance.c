#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rep 100

void registerAccount();
int loginAdmin();
int loginAdviser();
int loginAccount();
int loginOptions();
void mainMenu(const char username[]);
void dailyLogin(const char username[]);
void logEvent(const char username[]);
void logMeeting(const char username[]);
void eventCreate();
void meetingCreate();
void checkAttendance();
void checkEventAttendance();
void checkMeetingAttendance();
void adminMenu();
int registerOption();
int registerAdmin();
int registerAdviser();

int main()
{
    int opt;
    while (1)
    {
        printf("--Attendance--");
        printf("\n\nWelcome to the Organization Attendance System\n");
        printf("\n\n  Register[1]\n     Login[2]\n      Exit[3]\n\n   --option: ");
        scanf("%d", &opt);
        getchar();
        printf("\n\n\n");
        if (opt == 1)
        {
            registerOption();
        }
        else if (opt == 2)
        {
            loginOptions();
        }
        else if (opt == 3)
        {
            printf("\n---Thank you for using!---\n\n\n");
            exit(0);
        }

        else if (opt > 3)
        {
            printf("Invalid Option. Try Again.");
            return main();
        }
        else
        {
            printf("Error");
            return 0;
        }
    }
}

// loginOptions function
//  This function prompts the user to choose a login option: Member, Admin, or Adviser.
int loginOptions()
{
    int log;
    printf("Choose an option\n");
    printf("\n\n   Member[1]\n    Admin[2]\n  Adviser[3]\n     Back[4]\n\n --option: ");
    scanf("%d", &log);
    getchar();
    if (log == 1)
    {
        loginAccount();
    }
    else if (log == 2)
    {
        loginAdmin();
    }
    else if (log == 3)
    {
        loginAdviser();
    }
    else if (log == 4)
    {
        return main();
    }
    else
    {
        printf("Invalid option. Please try again.\n");
        loginOptions();
    }
    system("cls");
}

// this

int registerOption()

{
    int op;

    printf("Register as a\n[1] Member\t[2] Admin\t[3] Adviser\t[4] Back");
    printf("\nOpption: ");
    scanf("%d", &op);
    getchar();

    if (op == 1)
    {
        registerAccount();
    }
    else if (op == 2)
    {
        registerAdmin();
    }
    else if (op == 3)
    {
        registerAdviser();
    }
    else if (op == 4)
    {
        return main();
    }
}

int registerAdmin()
{
    FILE *file;
    char username[rep];
    char studentID[rep];
    char password[rep];

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\adminaccounts.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }
    while (1)
    {
        printf("Enter Username: ");
        fgets(username, rep, stdin);

        username[strcspn(username, "\n")] = '\0';
        if (strlen(username) == 0)
        {
            printf("Error: Username cannot be empty. Please try again.\n");
        }
        else
        {

            break;
        }
    }
    while (1)
    {
        printf("Enter Admin ID: ");
        fgets(studentID, rep, stdin);

        studentID[strcspn(studentID, "\n")] = '\0';
        if (strlen(studentID) == 0)
        {
            printf("Error: Admin ID cannot be empty. Please try again.\n");
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("Enter Password: ");
        fgets(password, rep, stdin);
        password[strcspn(password, "\n")] = '\0';
        if (strlen(password) == 0)
        {
            printf("Error: Password cannot be empty. Please try again.\n");
        }
        else if (strlen(password) < 6)
        {
            printf("Error: Password should be longer than 6 characters.\n");
        }
        else
        {
            fprintf(file, "Username: %s, StudentID: %s, Password: %s\n", username, studentID, password);
            fclose(file);
            printf("Successfully Registered as an Admin!\n");
            break;
        }
    }
}

int registerAdviser()
{
    FILE *file;
    char username[rep];
    char empID[rep];
    char password[rep];

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\advaccount.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }
    while (1)
    {
        printf("Enter Username: ");
        fgets(username, rep, stdin);

        username[strcspn(username, "\n")] = '\0';
        if (strlen(username) == 0)
        {
            printf("Error: Username cannot be empty. Please try again.\n");
        }
        else
        {

            break;
        }
    }
    while (1)
    {
        printf("Enter Employee ID: ");
        fgets(empID, rep, stdin);

        empID[strcspn(empID, "\n")] = '\0';
        if (strlen(empID) == 0)
        {
            printf("Error: Student ID cannot be empty. Please try again.\n");
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("Enter Password: ");
        fgets(password, rep, stdin);
        password[strcspn(password, "\n")] = '\0';
        if (strlen(password) == 0)
        {
            printf("Error: Password cannot be empty. Please try again.\n");
        }
        else if (strlen(password) < 6)
        {
            printf("Error: Password should be longer than 6 characters.\n");
        }
        else
        {
            fprintf(file, "Username: %s, empID: %s, Password: %s\n", username, empID, password);
            fclose(file);
            printf("Successfully Registered as an Admin!\n");
            break;
        }
    }
}

// registerAccount function
//  This function allows a user to register an account by providing a username, student ID, and password.
void registerAccount()
{
    FILE *file;
    char line[rep];
    int id_exists = 0, username_exists = 0;
    char username[rep];
    char studentID[rep];
    char password[rep];

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\registeredaccounts.txt", "a+");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    // Username input + duplicate check
    while (1)
    {
        printf("Enter Username: ");
        fgets(username, rep, stdin);
        username[strcspn(username, "\n")] = '\0';

        if (strlen(username) == 0)
        {
            printf("Error: Username cannot be empty. Please try again.\n");
            continue;
        }

        rewind(file); // Go back to beginning of file
        username_exists = 0;

        while (fgets(line, sizeof(line), file))
        {
            char tempUsername[rep], tempID[rep], tempPassword[rep];
            if (sscanf(line, "Username: %[^,], StudentID: %[^,], Password: %[^\n]", tempUsername, tempID, tempPassword) == 3)
            {
                if (strcmp(username, tempUsername) == 0)
                {
                    username_exists = 1;
                    break;
                }
            }
        }

        if (username_exists)
        {
            printf("Error: Username already exists. Please enter a different one.\n");
        }
        else
        {
            break;
        }
    }

    // Student ID input + duplicate check
    while (1)
    {
        printf("Enter Student ID: ");
        fgets(studentID, rep, stdin);
        studentID[strcspn(studentID, "\n")] = '\0';

        if (strlen(studentID) == 0)
        {
            printf("Error: Student ID cannot be empty. Please try again.\n");
            continue;
        }
        else if (strlen(studentID) < 6)
        {
            printf("Error: Student ID should be at least 6 characters.\n");
            continue;
        }

        rewind(file);
        id_exists = 0;
        while (fgets(line, sizeof(line), file))
        {
            char tempUsername[rep], tempID[rep], tempPassword[rep];
            if (sscanf(line, "Username: %[^,], StudentID: %[^,], Password: %[^\n]", tempUsername, tempID, tempPassword) == 3)
            {
                if (strcmp(studentID, tempID) == 0)
                {
                    id_exists = 1;
                    break;
                }
            }
        }

        if (id_exists)
        {
            printf("Error: Student ID already exists. Please enter a different one.\n");
        }
        else
        {
            break;
        }
    }

    // Password input
    while (1)
    {
        printf("Enter Password: ");
        fgets(password, rep, stdin);
        password[strcspn(password, "\n")] = '\0';

        if (strlen(password) == 0)
        {
            printf("Error: Password cannot be empty. Please try again.\n");
        }
        else if (strlen(password) < 6)
        {
            printf("Error: Password should be longer than 6 characters.\n");
        }
        else
        {
            fprintf(file, "Username: %s, StudentID: %s, Password: %s\n", username, studentID, password);
            fclose(file);
            printf("Successfully Registered!\n");
            break;
        }
    }
}

// loginAccount function for members
int loginAccount()
{
    FILE *file;
    char username[rep], password[rep];
    char line[rep];
    char storedUsername[rep], storedStudentID[rep], storedPassword[rep];

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\registeredaccounts.txt", "r"); // Fixed path
    if (!file)
    {
        printf("No accounts found. Register first.\n");
        return 0;
    }

    printf("Enter Registered Username: ");
    fgets(username, rep, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter Registered Password: ");
    fgets(password, rep, stdin);
    password[strcspn(password, "\n")] = '\0';

    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "Username: %[^,], StudentID: %[^,], Password: %[^\n]", storedUsername, storedStudentID, storedPassword);
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
        {
            fclose(file);
            printf("Login successful! Welcome, %s.\n", username);
            mainMenu(username);
            return 1;
        }
    }

    fclose(file);
    printf("Invalid username or password. Try again.\n");
    return loginAccount(); // Retry login
}

// loginAdmin function for admin
int loginAdmin()
{
    FILE *file;
    char username[rep], password[rep];
    char line[rep];
    char storedUsername[rep], storedStudentID[rep], storedPassword[rep];
    int found = 0;

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\adminaccounts.txt", "r");
    if (!file)
    {
        printf("Admin account not found. Please consult with the system manager.\n");
        return 0;
    }

    printf("Enter Registered Username: ");
    fgets(username, rep, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter Registered Password: ");
    fgets(password, rep, stdin);
    password[strcspn(password, "\n")] = '\0';

    // Check each line in the admin file
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "Username: %[^,], StudentID: %[^,], Password: %[^\n]", storedUsername, storedStudentID, storedPassword);

        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
        {
            found = 1;

            break;
        }
    }

    fclose(file);

    if (found)
    {
        printf("Login successful! Welcome, %s.\n", username);
        adminMenu();
    }
    else
    {
        printf("Invalid admin username or password. Access denied.\n\n");
        loginAdmin();
    }

    return 0;
}

void adminMenu()
{
    int choice;
    while (1)
    {
        printf("\nChoose an option\n");
        printf("[1] Create Event\n[2] Create Meeting\n[3] Back\n");
        scanf("%d", &choice);
        getchar(); // Clear the newline character
        if (choice == 1)
        {
            eventCreate();
        }
        else if (choice == 2)
        {
            meetingCreate();
        }
        else if (choice == 3)
        {
            printf("Exiting...\n");
            return main();
        }
        else
        {
            printf("Invalid choice. Try again.\n");
            return adminMenu();
        }
    }
}

int loginAdviser()
{
    FILE *file;
    char username[rep], password[rep];
    char line[rep];
    char storedUsername[rep], storedEmpID[rep], storedPassword[rep];
    int found = 0;

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\advaccount.txt", "r");
    if (!file)
    {
        printf("Adviser account not found. Please consult with the system manager.\n");
        return 0;
    }

    printf("Enter Registered Username: ");
    fgets(username, rep, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter Registered Password: ");
    fgets(password, rep, stdin);
    password[strcspn(password, "\n")] = '\0';

    // Check each line in the adviser file
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "Username: %[^,], empID: %[^,], Password: %[^\n]", storedUsername, storedEmpID, storedPassword);

        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
        {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found)
    {
        printf("Login successful! Welcome, %s.\n", username);
    }
    else
    {
        printf("Invalid adviser username or password. Access denied.\n");
        loginAdviser();
    }

    while (1)
    {
        printf("Choose an option\n");
        printf("[1] Check Attendance\n[2] Check Event Attendance\n[3] Check Meeting Attendance\n[4] Back\n");
        int choice;

        scanf("%d", &choice);
        getchar(); // Clear the newline character
        if (choice == 1)
        {
            checkAttendance();
        }
        else if (choice == 2)
        {
            checkEventAttendance();
        }
        else if (choice == 3)
        {
            checkMeetingAttendance();
        }
        else if (choice == 4)
        {
            printf("Exiting...\n");
            main();
        }
        else
        {
            printf("Invalid choice. Exiting...\n");
        }
    }
    return 0;
}
void eventCreate()
{
    int op;
    FILE *event;
    char eventName[rep], eventDate[rep], eventTime[rep], eventLocation[rep];
    // Create and open a file in write mode
    event = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\event.txt", "a");
    if (event == NULL)
    {
        printf("Error: Could not create file.\n");
        return;
    }

    printf("\nCreate an event? 1 for Yes, 2 for No: ");
    scanf("%d", &op);
    getchar(); // Clear the newline character from the input buffer
    if (op != 1)
    {
        fclose(event);
        return;
    }

    while (1)
    {
        printf("\nEnter event name: ");
        fgets(eventName, rep, stdin);
        eventName[strcspn(eventName, "\n")] = '\0';

        if (eventName[0] == '\0')
        {
            printf("Event name cannot be empty. Please try again.\n");
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("Enter event date(MM/DD/YYYY): ");
        fgets(eventDate, rep, stdin);
        eventDate[strcspn(eventDate, "\n")] = '\0';
        if (eventDate[0] == '\0')
        {
            printf("Event date cannot be empty. Please try again.\n");
        }
        else if (strlen(eventDate) < 10)
        {
            printf("Event date should be in MM/DD/YYYY format.\n");
        }
        else if (eventDate[2] != '/' || eventDate[5] != '/')
        {
            printf("Missing slashes. Format should be MM/DD/YYYY.\n");
        }
        else if (eventDate[10] != '\0')
        {
            printf("Invalid date format. Please use MM/DD/YYYY.\n");
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("Enter event time (HH:MM AM/PM): ");
        fgets(eventTime, rep, stdin);
        eventTime[strcspn(eventTime, "\n")] = '\0';

        if (eventTime[0] == '\0')
        {
            printf("Event time cannot be empty. Please try again.\n");
        }
        else if (strlen(eventTime) < 8)
        {
            printf("Event time should be in HH:MM AM/PM format.\n");
        }
        else if (eventTime[2] != ':')
        {
            printf("Missing colon. Format should be HH:MM AM/PM.\n");
        }
        else if (eventTime[5] != ' ')
        {
            printf("Missing space before AM/PM. Format should be HH:MM AM/PM.\n");
        }
        else
        {
            char suffix[3];
            strncpy(suffix, &eventTime[6], 2);
            suffix[2] = '\0';

            if (strcasecmp(suffix, "AM") != 0 && strcasecmp(suffix, "PM") != 0)
            {
                printf("Time must end with AM or PM.\n");
            }
            else
            {
                break; // valid time format
            }
        }
    }

    while (1)
    {
        printf("Enter event location: ");
        fgets(eventLocation, rep, stdin);
        eventLocation[strcspn(eventLocation, "\n")] = '\0';
        printf("Event successfully created!\n");
        if (eventLocation[0] == '\0')
        {
            printf("Event location cannot be empty. Please try again.\n");
        }
        else
        {
            break;
        }

        // Close the file
    }
    fprintf(event, "Event Name: %s\nDate: %s\nTime: %s\nLocation: %s\n", eventName, eventDate, eventTime, eventLocation);
    printf("Event successfully created!\n");

    printf("Create another event? 1 for Yes, 2 for No: ");
    scanf("%d", &op);
    getchar(); // Clear the newline character from the input buffer
    if (op == 1)
    {
        eventCreate(); // Recursive call to create another event
    }
    else
    {
        printf("Exiting event creation.\n");
    }
    fclose(event);
}
void meetingCreate()
{
    int op;
    FILE *meeting;
    char meetingName[rep], meetingDate[rep], meetingTime[rep], meetingLocation[rep];
    // Create and open a file in write mode
    meeting = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\meet.txt", "a");
    if (meeting == NULL)
    {
        printf("Error: Could not create file.\n");
        return;
    }

    printf("\nCreate a meeting? 1 for Yes, 2 for No: ");
    scanf("%d", &op);
    getchar(); // Clear the newline character from the input buffer
    if (op != 1)
    {

        return adminMenu();
    }

    while (1)
    {
        printf("\nEnter meeting name: ");
        fgets(meetingName, rep, stdin);
        meetingName[strcspn(meetingName, "\n")] = '\0';

        if (meetingName[0] == '\0')
        {
            printf("Meeting name cannot be empty. Please try again.\n");
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("Enter meeting date(MM/DD/YYYY): ");
        fgets(meetingDate, rep, stdin);
        meetingDate[strcspn(meetingDate, "\n")] = '\0';
        if (meetingDate[0] == '\0')
        {
            printf("Meeting date cannot be empty. Please try again.\n");
        }
        else if (strlen(meetingDate) < 10)
        {
            printf("Meeting date should be in MM/DD/YYYY format.\n");
        }
        else if (meetingDate[2] != '/' || meetingDate[5] != '/')
        {
            printf("Missing slashes. Format should be MM/DD/YYYY.\n");
        }
        else if (meetingDate[10] != '\0')
        {
            printf("Invalid date format. Please use MM/DD/YYYY.\n");
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("Enter meeting time (HH:MM AM/PM): ");
        fgets(meetingTime, rep, stdin);
        meetingTime[strcspn(meetingTime, "\n")] = '\0';

        if (meetingTime[0] == '\0')
        {
            printf("Meeting time cannot be empty. Please try again.\n");
        }
        else
        {
            break;
        }
    }
    fprintf(meeting, "Meeting Name: %s\nDate: %s\nTime: %s\nLocation: %s\n\n",
            meetingName, meetingDate, meetingTime, meetingLocation);
    fclose(meeting);
    printf("Meeting successfully created!\n");
    printf("Create another Meeting? 1 for Yes, 2 for No: ");
    scanf("%d", &op);
    getchar(); // Clear the newline character from the input buffer
    if (op == 1)
    {
        meetingCreate(); // Recursive call to create another event
    }
    else
    {
        printf("Exiting event creation.\n");
    }
}

// mainMenu function
void mainMenu(const char username[])
{
    int op;
    while (1)
    {
        printf("\nChoose an option\n");
        printf("[1] Daily Log || [2] Event Log || [3] Meeting Log || [4] Back\n");
        printf("Option: ");
        scanf("%d", &op);
        getchar();

        if (op == 1)
            dailyLogin(username);
        else if (op == 2)
            logEvent(username);
        else if (op == 3)
            logMeeting(username);
        else if (op == 4)
            break;
        else
            printf("Invalid option. Try again.\n");
    }
}
void dailyLogin(const char username[])
{
    FILE *file, *accFile;
    char op[rep];
    char line[rep];
    char tempUsername[rep], tempID[rep], tempPassword[rep];
    char studentID[rep] = "";

    // Look up student ID using the username
    accFile = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\registeredaccounts.txt", "r");
    if (accFile == NULL)
    {
        printf("Error opening accounts file.\n");
        return;
    }

    while (fgets(line, sizeof(line), accFile))
    {
        if (sscanf(line, "Username: %[^,], StudentID: %[^,], Password: %[^\n]", tempUsername, tempID, tempPassword) == 3)
        {
            if (strcmp(tempUsername, username) == 0)
            {
                strcpy(studentID, tempID);
                break;
            }
        }
    }
    fclose(accFile);

    if (strlen(studentID) == 0)
    {
        printf("Student ID not found for user %s.\n", username);
        return;
    }

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\Dailylogin.txt", "a");
    if (file == NULL)
    {
        printf("Error opening log file.\n");
        return;
    }

    printf("\nChoose an option (type 'login' or 'logout'):\nOption: ");
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0'; // Remove newline character

    if (strcasecmp(op, "login") == 0)
    {
        fprintf(file, "%s (ID: %s) logged in.\n", username, studentID);
        printf("Daily login recorded for %s (ID: %s)\n", username, studentID);
    }
    else if (strcasecmp(op, "logout") == 0)
    {
        fprintf(file, "%s (ID: %s) logged out.\n", username, studentID);
        printf("Daily logout recorded for %s (ID: %s)\n", username, studentID);
    }
    else
    {
        printf("Invalid option. Please type 'login' or 'logout'.\n");
        return dailyLogin(username); // Retry
    }

    fclose(file);
}

void logEvent(const char username[])
{
    FILE *event;
    char line[rep];
    char events[50][rep]; // max 50 events
    int eventCount = 0;
    int choice;
    // Create and open a file in write mode
    event = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\event.txt", "r+");
    if (event == NULL)
    {
        printf("\nNo events found. Admin must create one first\n");
        return;
    }

    while (fgets(line, sizeof(line), event))
    {
        if (strncmp(line, "Event Name:", 11) == 0)
        {
            strncpy(events[eventCount], line + 12, rep);                  // skip "Event Name: "
            events[eventCount][strcspn(events[eventCount], "\n")] = '\0'; // remove newline
            eventCount++;
        }
    }

    fclose(event);

    if (eventCount == 0)
    {
        printf("No events available.\n");
        return;
    }

    // Display events
    printf("\nAvailable events:\n");
    for (int i = 0; i < eventCount; i++)
    {
        printf("[%d] %s\n", i + 1, events[i]);
    }

    // Get user choice
    printf("\nChoose an event by number: ");
    scanf("%d", &choice);
    getchar();

    if (choice < 1 || choice > eventCount)
    {
        printf("Invalid choice.\n");
        return;
    }

    // Log selected event
    FILE *log = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\eventlog.txt", "a");
    if (log == NULL)
    {
        printf("Error opening event log file.\n");
        return;
    }

    fprintf(log, "\n%s attended event: %s\n", username, events[choice - 1]);
    fclose(log);

    printf("Event log recorded for %s: %s\n", username, events[choice - 1]);
}
void logMeeting(const char username[])
{
    FILE *event, *accFile, *log;
    char line[rep], studentID[rep] = "", tempUsername[rep], tempID[rep], tempPassword[rep];
    char events[50][rep];
    int eventCount = 0, choice;

    // Fetch student ID based on username
    accFile = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\registeredaccounts.txt", "r");
    if (accFile != NULL)
    {
        while (fgets(line, sizeof(line), accFile))
        {
            if (sscanf(line, "Username: %[^,], StudentID: %[^,], Password: %[^\n]", tempUsername, tempID, tempPassword) == 3)
            {
                if (strcmp(username, tempUsername) == 0)
                {
                    strcpy(studentID, tempID);
                    break;
                }
            }
        }
        fclose(accFile);
    }

    event = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\meet.txt", "r");
    if (event == NULL)
    {
        printf("No Meetings found. Admin must create one first\n");
        return;
    }

    while (fgets(line, sizeof(line), event))
    {
        if (strncmp(line, "Meeting Name:", 13) == 0)
        {
            strncpy(events[eventCount], line + 13, rep);
            events[eventCount][strcspn(events[eventCount], "\n")] = '\0';
            eventCount++;
        }
    }
    fclose(event);

    if (eventCount == 0)
    {
        printf("No Meetings available.\n");
        return;
    }

    printf("\nAvailable Meetings:\n");
    for (int i = 0; i < eventCount; i++)
    {
        printf("[%d] %s\n", i + 1, events[i]);
    }

    printf("\nChoose a Meeting by number: ");
    scanf("%d", &choice);
    getchar();

    if (choice < 1 || choice > eventCount)
    {
        printf("Invalid choice.\n");
        return;
    }

    log = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\meetinglog.txt", "a");
    if (log == NULL)
    {
        printf("Error opening meeting log file.\n");
        return;
    }

    fprintf(log, "%s (ID: %s) attended meeting: %s\n", username, studentID, events[choice - 1]);
    fclose(log);

    printf("\nMeeting log recorded for %s (ID: %s): %s\n", username, studentID, events[choice - 1]);
}

void checkAttendance()
{
    FILE *file;
    char line[rep];
    char id[rep];

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\Dailylogin.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter student ID to check attendance: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; // remove newline

    printf("\nAttendance Logs for ID: %s\n\n", id);

    int found = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, id) != NULL)
        {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No attendance logs found for ID: %s\n", id);
    }

    fclose(file);
}

void checkEventAttendance()
{
    FILE *file;
    char line[rep];
    char id[rep];

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\eventlog.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter student ID to check event attendance: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; // remove newline
    printf("\nEvent Attendance Logs for ID: %s\n\n", id);
    int found = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, id) != NULL)
        {
            printf("%s", line);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No event attendance logs found for ID: %s\n", id);
    }

    fclose(file);
}
void checkMeetingAttendance()
{
    FILE *file;
    char line[rep];
    char id[rep];

    file = fopen("C:\\Users\\Yuan\\Desktop\\C lang\\Attend\\meetinglog.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter student ID to check meeting attendance: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    printf("\nMeeting Attendance Logs for ID: %s\n\n", id);
    int found = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, id) != NULL)
        {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No meeting attendance logs found for ID: %s\n", id);
    }

    fclose(file);
}