/********* main.c ********
    Student Name 	= Emrie Frei
    Student Number	= 101297809
*/

// Includes go here
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "a2_nodes.h"
#include "a2_functions.h"

int main()
{
    
    FILE *csv_file = fopen("user_details.csv", "r");
    if (csv_file == NULL)
    {
        perror("Error opening the CSV file");
        return 1;
    }
    // Parse CSV data and create users
    user_t *users = read_CSV_and_create_users(csv_file, 50);

    fclose(csv_file);

    // user_t *users = NULL;
    int user_input_main;
    int user_input_secondary;
    _Bool on = true;
    char username[30];
    char password[15];
    char friend_username[30];
    char text[250];

    while(on == true){
        print_menu();
        scanf("%d", &user_input_main);
        switch(user_input_main){
            case 1:
            //Add a new user

                printf("Please create a username and a password: \n");
                printf("What is the new username? ");
                scanf(" %[^\n]s", username);

                printf("\nWhat is the users password? ");
                scanf(" %[^\n]s", password);
                
                users = add_user(users, username, password);
                printf("User %s has been added!!\n\n", username);
                break;

            case 2:
            // Manage a user

                char old_pass[15];

                printf("\nPlease Enter a username to update their password ");
                scanf(" %[^\n]s", username);
                printf("\nPlease Enter your password: ");
                scanf(" %[^\n]s", old_pass);

                if(strcmp(find_user(users, username)->password, old_pass) == 0){

                    if(find_user(users, username) != NULL){
                        printf("\nUser has been found\n");

                    } else {
                        printf("-----------------------\n");
                        printf("    User Not Found.\n");
                        printf("-----------------------\n");
                        break;
                    }

                    printf("\nPlease enter a new password: ");
                    scanf(" %[^\n]s", password);
                    strcpy(find_user(users, username)->password, password);
                    printf("\n\n ***** Password Changed! ***** \n\n");

                } else {
                    printf("\n\nIncorrect Password\n\n");
                }
                //Test if the password worked:
                //printf("The new password is %s", find_user(users, username)->password);
                break;

            case 3:
            // Manage a users posts

                printf("Enter a username to manage their posts: ");
                scanf(" %[^\n]s", username);
                user_t *desired_user = find_user(users, username);

                printf("\n*************************************************** \n\n");
                printf("   %s's Posts", username);
                printf("\n\n************************************************** \n\n");

                if(find_user(users, username) == NULL){
                    printf("Invalid User.\n");
                    break;
                }

                if(desired_user->posts->content == NULL){
                    printf("No posts for user: %s \n\n", username);
                } else {
                    for(post_t *curr = desired_user->posts; curr != NULL; curr = curr->next){
                        printf("\n    %s\n", curr->content);
                    }
                }

                printf("\nWhat would you like to do with %s's posts?\n", username);
                printf("1. Add New Post\n");
                printf("2. Remove Post\n");
                printf("3: Return to main menu\n\n");

                printf("Enter Your Choice:");
                scanf("%d", &user_input_secondary);
                switch(user_input_secondary){

                    case 1:
                    // Add a new post

                        printf("Please Enter a New Post:\n");
                        scanf(" %[^\n]s", text);
                        add_post(desired_user, text);
                        printf("The new post is: %s", desired_user->posts->content);

                        printf("\n*************************************************** \n\n");
                        printf("   %s's Posts", username);
                        printf("\n\n************************************************** \n");
                        for(post_t *curr = desired_user->posts; curr != NULL; curr = curr->next){
                            printf("\n    %s\n", curr->content);
                        }
                        break;
                        
                    case 2:
                    // Delete the most recent post

                        if(desired_user->posts != NULL){
                            printf("Deleting most recent post... \n");
                            delete_post(desired_user);
                        } else {
                            printf("Error: No posts to delete...");
                        }
                        printf("\n*************************************************** \n\n");
                        printf("   %s's Posts", username);
                        printf("\n\n************************************************** \n");
                        for(post_t *curr = desired_user->posts; curr != NULL; curr = curr->next){
                            printf("\n    %s\n", curr->content);
                        }
                        break;
                    case 3:
                    // return to the main meny

                        printf("Returning to main menu... \n\n");
                        break;

                    default:
                    // invalid input

                        printf("Invalid input... Returning to main menu\n\n");
                        break;
                }

                break;
            case 4:
            // Manage a users friends

                printf("Enter a username to manage their friends: ");
                scanf(" %[^\n]s", username);
                user_t *desired_user_friend = find_user(users, username);

                if(find_user(users, username) == NULL){
                    printf("Invalid User.\n");
                    break;
                }
                printf("\nWhat would you like to do with %s's Friends?\n", username);
                printf("1. Add New Friends\n");
                printf("2. Remove Friends\n");
                printf("3: Return to main menu\n\n");

                printf("Enter Your Choice:");
                scanf("%d", &user_input_secondary);
                switch(user_input_secondary){
                    case 1:
                        // Add User
                        printf("Please input the username of the new friend:\n");
                        scanf("%s", friend_username);
                        add_friend(desired_user_friend, friend_username);
                        printf("Friend %s has been added!", friend_username);

                        // Test friend is added in the right spot
                        /*
                        while(desired_user_friend->friends != NULL){
                            printf("\n%s", desired_user_friend->friends->username);
                            desired_user_friend->friends = desired_user_friend->friends->next;
                        } */

                        break;
                    case 2:
                    // Remove a friend

                        printf("\n*************************************************** \n\n");
                        printf("   %s's Friends", username);
                        printf("\n\n************************************************** \n");

                        friend_t *temp_friend = desired_user_friend->friends;
                        _Bool confirmation = false;

                        display_user_friends(desired_user_friend);
                        printf("\nPlease choose a friend to remove: \n");
                        scanf("%s", friend_username);

                        confirmation = delete_friend(desired_user_friend, friend_username);
                        if(confirmation == true){
                            temp_friend = desired_user_friend->friends;
                            printf("\nRemaining friends: \n");
                            display_user_friends(desired_user_friend);
                        } else {
                            printf("User not deleted... \n");
                        }
                        break;

                    case 3:
                    // return to main menu

                        printf("Returning to main menu... \n\n");
                        break;

                    default:
                    // Invalid input

                        printf("Invalid input... Returning to main menu\n\n");
                        break;
                }
                break;

            case 5:

                printf("Please input a user who's posts you'd like to see: \n");
                scanf("%s", username);
                printf("\nDisplaying %s's posts:", username);
                user_t *post_user = find_user(users, username);
                display_posts_by_n(post_user, 3);
                break;

            case 6:
                printf("\n\nExiting...");
                teardown(users);
                on = false;
                break;

            default:
                printf("\n\nInvalid input please try again\n\n");
                break;
        }
    }
}