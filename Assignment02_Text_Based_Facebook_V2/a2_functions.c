/*****************
    Student Name 	= Emrie Frei
    Student Number	= 101297809
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <ctype.h>
#include "a2_nodes.h"
#include "a2_functions.h"


// Your solution goes here
user_t *add_user(user_t *users, const char *username, const char *password){
    user_t *new_user = malloc(sizeof(user_t));

    //Initialize the username and pass words for the new user and ensures the same size
    strncpy(new_user->username, username, sizeof(new_user->username) - 1);
    new_user->username[sizeof(new_user->username) - 1] = '\0';
    strncpy(new_user->password, password, sizeof(new_user->password) - 1);
    new_user->password[sizeof(new_user->password) - 1] = '\0';
    new_user->next = NULL;
    new_user->friends = NULL;
    new_user->posts = NULL;

    //Add the new user in the correct spot in alphabetical order
    user_t *curr = users;
    if(users == NULL){
        users = new_user;
        return users;
    }
    while(curr != NULL){
        if(curr->next == NULL || strcmp(new_user->username, curr->next->username) < 0){
            new_user->next = curr->next;
            curr->next = new_user;
            return users;
        }
        curr = curr->next;
    }
    return users;
}

user_t *find_user(user_t *users, const char *username){
    for(user_t *curr = users; curr != NULL; curr = curr->next){
        if(strcmp(curr->username, username) == 0){
            return curr;
        } else if (curr->next == NULL){
            return NULL;
        }
    }
}

friend_t *create_friend(const char *username){
    friend_t *new_friend = malloc(sizeof(friend_t));
    strncpy(new_friend->username, username, sizeof(new_friend->username) - 1);
    new_friend->username[sizeof(new_friend->username) - 1] = '\0';
    new_friend->next = NULL;
    new_friend->posts = NULL;
    return new_friend;
}

void add_friend(user_t *user, const char *friend){
    friend_t *new_friend = create_friend(friend);
    if(user == NULL){
        return;
    }
    if(new_friend == NULL){
        return;
    } 

    if(user->friends == NULL){
        user->friends = new_friend;
        return;
    }   

    friend_t *curr = user->friends;
    if(strcmp(friend, curr->username) < 0){
            new_friend->next = user->friends;
            user->friends = new_friend;
            return;
    }

    while(curr != NULL && curr->next != NULL){
        if(strcmp(friend, curr->next->username) < 0){
            new_friend->next = curr->next;
            curr->next = new_friend;
            return;
        }
        curr = curr->next;
    }
    curr->next = new_friend;
}

_Bool delete_friend(user_t *user, char *friend_name){
    if (user == NULL) {
        printf("Error: user is NULL\n");
        return false;
    }
    friend_t *curr = user->friends;
    friend_t *previous = NULL;

    while(curr != NULL){
        if(strcmp(curr->username, friend_name) == 0){
            if(previous == NULL){
                user->friends = curr->next;
            } else {
                previous->next = curr->next;
            }
            free(curr->username);
            return true;
        }
        previous = curr;
        curr = curr->next;
    }
    return false;
}

post_t *create_post(const char *text){
    post_t *new_post = malloc(sizeof(post_t));
    strncpy(new_post->content, text, sizeof(new_post->content) - 1);
    new_post->content[sizeof(new_post->content) - 1] = '\0';
    new_post->next = NULL;
    return new_post;
}

void add_post(user_t *user, const char *text){
    post_t *new_post = create_post(text);
    if(user == NULL || text == NULL){
        return;
    }
    if(new_post == NULL){
        return;
    }
    strcpy(new_post->content, text);

    new_post->next = user->posts;
    user->posts = new_post; 
}

_Bool delete_post(user_t *user){
    if(user == NULL || user->posts == NULL){
        return false;
    }
    post_t *first_post = user->posts;
    user->posts = first_post->next;
    if(user->posts == NULL){
        user->posts = NULL;
    }
    free(first_post);
    return true;
}

void display_all_user_posts(user_t *user){
    short unsigned i = 1;
    for(post_t *curr = user->posts; curr != NULL; curr = curr->next, i++){
        printf("Displaying %s's posts...\n", user->username);
        printf("Post %hu: %s\n", i, curr->content);
    }
}

void display_user_friends(user_t *user){
    short unsigned i = 1;
    printf("Displaying %s's friends...\n", user->username);
    for(friend_t *curr = user->friends; curr != NULL; curr = curr->next, i++){
        printf("Friend %hu: %s\n", i, curr->username);
    }
}

void display_posts_by_n(user_t *users, int number){
    post_t *curr = users->posts;
    int number_displayed = 0;
    char yes_no[4];
    _Bool continue_displaying = true;

    while(curr != NULL && continue_displaying){
        for(int i = 0; i < number && curr != NULL; i++, curr = curr->next){
            printf("\n%s\n", curr->content);
            number_displayed++;
        }

        if(curr != NULL){
            printf("\nDo you want to see more posts (Y/N):");
            scanf("%s", yes_no);

            if(yes_no[0] == 'y' || yes_no[0] == 'Y'){
                continue_displaying = true;
            } else if (yes_no[0] == 'n' || yes_no[0] == 'N'){
                printf("\nDisplaying no more posts... Exiting");
                continue_displaying = false;
                break;
            } else {
                printf("\n Invalid Input.");
                break;
            }
        }
    }
}

void teardown(user_t *users){
    friend_t *friend = users->friends;
    user_t *temp = users;
    while(users->posts != NULL){
        delete_post(users);
    }
    while(users->friends != NULL){
        friend = users->friends->next;
        delete_friend(users, users->friends->username);
    }
    while(users != NULL){
        temp = users->next;
        free(users);
        users = temp;
    }
}

void print_menu(){
    printf("\n*********************************\n");
    printf("            MAIN MENU\n");
    printf("*********************************\n\n");
    printf("1. Register a new user\n");
    printf("2. Login as existing user\n");
    printf("3. Exit\n\n");
    printf("Enter Your Choice: ");

}

/*
   ******** DONT MODIFY THIS FUNCTION ********
   Function that reads users from the text file.
   IMPORTANT: This function shouldn't be modified and used as is
   ******** DONT MODIFY THIS FUNCTION ********
*/
user_t *read_CSV_and_create_users(FILE *file, int num_users)
{
    srand(time(NULL));
    user_t *users = NULL;
    char buffer[500];
    fgets(buffer, sizeof(buffer), file); // Read and discard the header line
    int count = 0;
    for (int i = 0; i < num_users; i++)
    {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline characters

        char *token = strtok(buffer, ",");
        char *token2 = strtok(NULL, ",");
        users = add_user(users, token, token2);
        char *username = token;

        token = strtok(NULL, ",");

        user_t *current_user = users;
        for (; current_user != NULL && strcmp(current_user->username, username) != 0; current_user = current_user->next)
            ;

        while (token != NULL && strcmp(token, ",") != 0 && count < 3)
        {
            if (strcmp(token, " ") != 0)
            {
                add_friend(current_user, token);
            }
            token = strtok(NULL, ",");
            count++;
        }
        count = 0;

        // token = strtok(NULL, ",");
        while (token != NULL && strcmp(token, ",") != 0)
        {
            add_post(current_user, token);
            token = strtok(NULL, ",");
        }
    }
    return users;
}

void print_secondary_menu(const char *username){
    printf("\n*********************************\n");
    printf("Welcome %s\n", username);
    printf("*********************************\n\n");
    printf("1. Manage Profile (change password)\n");
    printf("2. Manage Posts (add/remove)\n");
    printf("3. Manage Friends (add/remove)\n");
    printf("4. Display a Friend's Posts\n");
    printf("5. Exit\n\n");
    printf("Enter Your Choice: ");
}

char *lower_username(char *username){
    for(int i = 0; username[i]; i++){
        username[i] = tolower(username[i]);
    }
    return username;
}



