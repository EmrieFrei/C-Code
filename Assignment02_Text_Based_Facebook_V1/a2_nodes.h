/********* nodes.h ********
    Student Name 	= Emrie Frei
    Student Number	= 101297809
*/

/********** DON'T MODIFY **********/
// Structure to represent a linked list of users
#ifndef __A2_NODES_H__
#define __A2_NODES_H__

typedef struct user
{
    char username[30];
    char password[15];
    struct friend *friends;
    struct post *posts;
    struct user *next;
} user_t;

// Structure to represent linked list of a user's posts
typedef struct friend
{
    char username[30];
    struct friend *next;
}
friend_t;

// Structure to represent linked list of a user's posts
typedef struct post
{
    char content[250];
    struct post *next;
} post_t;

#endif