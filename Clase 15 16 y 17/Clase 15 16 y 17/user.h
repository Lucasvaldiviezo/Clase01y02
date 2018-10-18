#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct
{
    int userId;
    char name[33];
    char email[65];
}User;

User* user_new(void);
void user_delete(User* this);
int user_setName(User* this,char* name);

#endif // USER_H_INCLUDED
