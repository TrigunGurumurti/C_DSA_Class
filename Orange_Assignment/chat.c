#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USERS 100  // Maximum number of users

// Structure for a message in a doubly linked list
typedef struct Message
{
    char content[300];  // Message content
    char sender[50];  // Sender ID
    struct Message *next;  // Pointer to the next message
    struct Message *prev;  // Pointer to the previous message
} Message;

// Structure for the chat history (Doubly linked list of messages)
typedef struct Chat
{
    Message *head;  // Pointer to the first message
    Message *tail;  // Pointer to the last message
} Chat;

// Structure for User
typedef struct User
{
    char userId[50];  // User ID
    char username[50];  // Username
    Chat chathistory;  // Chat history (one-on-one or group chat)
} User;

// HashMap for storing the user
User *userdirectory[MAX_USERS];

// Hash function to compute index for user ID
int hashfunction(char *userid)
{
    int hash = 0;
    for (int i = 0; userid[i] != '\0'; i++)
    {
        hash = (hash + userid[i]) % MAX_USERS;  // hash function
    }
    return hash;
}

// Function to find a user by ID
User *finduser(char *user)
{
    int index = hashfunction(user);
    return userdirectory[index];
}

// Function to create a new user and add to the directory
void createuser(char *userid, char *username)
{
    int index = hashfunction(userid); // index is the hash code
    User *newuser = (User*)malloc(sizeof(User));
    strcpy(newuser->userId, userid);
    strcpy(newuser->username, username);
    newuser->chathistory.head = NULL;
    newuser->chathistory.tail = NULL;
    userdirectory[index] = newuser;
}

// Function to create a new message
Message *createMessage(char *message, char *sender_id)
{
    Message *newmessage = (Message *)malloc(sizeof(Message));
    strcpy(newmessage->content, message);
    strcpy(newmessage->sender, sender_id);
    newmessage->next = newmessage->prev = NULL;
    return newmessage;
}

// Function to send message (add to the chat history)
void sendMessage(User *sender, char *message, char *sender_id)
{
    Message *newmessage = createMessage(message, sender_id);
    if (sender->chathistory.tail == NULL)  // initially there are no messages
    {
        sender->chathistory.head = sender->chathistory.tail = newmessage;
    }
    else
    {
        // Add the new message at the end of the list
        sender->chathistory.tail->next = newmessage;
        newmessage->prev = sender->chathistory.tail;
        sender->chathistory.tail = newmessage;
    }
}


void listMessage(User *user)
{
    Message *current = user->chathistory.head;
    if(current == NULL)
    {
        printf("No messages in the chat\n");
        return;
    }
    while(current != NULL)
    {
        printf("%s:%s\n",current->sender, current->content);
        current = current->next;
    }
}

int main()
{
    // Initialize the user directory
    for (int i = 0; i < MAX_USERS; i++)
    {
        userdirectory[i] = NULL;
    }

    int num_users, num_messages;
    char user_id[50], username[50], sender_id[50], message[300];
    printf("Enter the number of users to create: ");
    scanf("%d", &num_users);

    for (int i = 0; i < num_users; i++)
    {
        printf("Enter the USERID: ");
        scanf("%s", user_id);
        printf("Enter the USERNAME: ");
        scanf("%s", username);
        createuser(user_id, username);  // function call
    }

    // Input for sending the messages
    printf("\nEnter the number of messages to send: ");
    scanf("%d", &num_messages);

    for (int i = 0; i < num_messages; i++)
    {
        printf("\nEnter the Sender ID: ");
        scanf("%s", sender_id);
        printf("Enter the Message: ");
        getchar();  // Consume the leftover newline from the previous input
        fgets(message, sizeof(message), stdin);

        // Remove newline character from fgets input
        size_t len = strlen(message);
        if (len > 0 && message[len - 1] == '\n')
        {
            message[len - 1] = '\0';
        }

        User *sender = finduser(sender_id);  // function call

        if (sender == NULL)
        {
            printf("User not found\n");
            continue;
        }

        sendMessage(sender, message, sender_id);
    }

    printf("\nEnter the user id to display chat history : ");
    scanf("%s", user_id);
    User *user = finduser(user_id);
    listMessage(user);
    return 0;
}
