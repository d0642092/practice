#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 14
//============================
int i,bNumTemp;
char bNameTemp[100],confirm;
//=============================
typedef struct
{
    char name[Max];
    char sex[2];
    char account[Max];
    char password[Max];
    int Id;
    int borrowlimit;
} Member;
Member totalMember[100];
Member loginMember;
int currentMemberCount=1;
int accountlonger,passwordlonger;

//===============================
typedef struct
{
    char bookName[100];
    char author[100];
    int bookNum;
    int borrowornot;
    int bookbelent;
} Book;
Book totalBook[100];

int totalBookCount=0;
int tempAdd=0;
int resultofborrow;
int flag=0;
//===============================
void signUp (void);
int compareAccount(char addAccount[]);
int compareName(char addName[]);
void change (char type,char wantchange[]);//∑QßÔ±b±K
void logIn(void);
void lentbook(void);//©“≠…™∫Æ—
void mainMenu(void);
void addBook(void);
int bNameChk(int j);
void checkIn(void);
void checkOut(void);
int research(char wantfind[],char wantfindauthor[]);
void logOut(void);
void search (void);
void bNameChk_s(void);
int bNumChk(void);
int space(char check[]);
void AdministratorMenu(void);

int main()
{
    char firstMenu;
    printf("Welcome To Library!\n");
    printf("1.SignUp\n2.Login\n");
    while(scanf(" %c",&firstMenu) == 1)
    {
        switch (firstMenu)
        {
            case '1':
                system("CLS");
                signUp();
                break;
            case '2':
                system("CLS");
                logIn();
                break;
            default:
                system("CLS");
                printf("Error!!please Input Again\n");
                printf("1.SignUp\n2.Login\n");
                break;
        }
    }
}

void signUp()
{
    char addAccount[Max]= {0}, addPassword[Max]= {0}, addName[Max]= {0}, addSex[Max]= {0};
    char lalsd;//∑Q§£®Ï§F
    int x;
    printf("Input Account:");
    gets(addAccount);
    scanf("%[^\n]",addAccount);
    while(addAccount[0] == '0' && addAccount[1] == 0)
    {
        printf("Sorry,You can't use this account!\n");
        system("pause");
        system("CLS");
        printf("Input Account:");
        gets(addAccount);
        scanf("%[^\n]",addAccount);
    }
    while(strlen(addAccount)==0)
    {
        if(strlen(addAccount)==0)
        {
            printf("Account do not Null\n");
            system("pause");
            system("CLS");
            printf("Input Account:");
            gets(addAccount);
            scanf("%[^\n]",addAccount);
            while(addAccount[0] == '0' && addAccount[1] == 0)
            {
                printf("Sorry,You can't use this account!\n");
                system("pause");
                system("CLS");
                printf("Input Account:");
                gets(addAccount);
                scanf("%[^\n]",addAccount);
            }
            while(space(addAccount)==0)
            {
                system("CLS");
                printf("Account do not have space!!\n");
                printf("Input Account:");
                gets(addAccount);
                scanf("%[^\n]",addAccount);
                while(addAccount[0] == '0' && addAccount[1] == 0)
                {
                    printf("Sorry,You can't use this account!\n");
                    system("pause");
                    system("CLS");
                    printf("Input Account:");
                    gets(addAccount);
                    scanf("%[^\n]",addAccount);
                }
            }
            
        }
    }
    while(space(addAccount)==0)
    {
        printf("Account do not have space!!\n");
        printf("Input Account:");
        gets(addAccount);
        scanf("%[^\n]",addAccount);
        while(addAccount[0] == '0' && addAccount[1] == 0)
        {
            printf("Sorry,You can't use this account!\n");
            system("pause");
            system("CLS");
            printf("Input Account:");
            gets(addAccount);
            scanf("%[^\n]",addAccount);
        }
        while(strlen(addAccount)==0)
        {
            if(strlen(addAccount)==0)
            {
                system("CLS");
                printf("Account do not Null\n");
                system("pause");
                system("CLS");
                printf("Input Account:");
                gets(addAccount);
                scanf("%[^\n]",addAccount);
                while(addAccount[0] == '0' && addAccount[1] == 0)
                {
                    printf("Sorry,You can't use this account!\n");
                    system("pause");
                    system("CLS");
                    printf("Input Account:");
                    gets(addAccount);
                    scanf("%[^\n]",addAccount);
                }
            }
        }
    }
    while(compareAccount(addAccount)==0)
    {
        system("CLS");
        printf("Member Account had already been used!\n");
        printf("if you want return press 'R' or 'any'\n");
        scanf(" %c",&lalsd);
        switch(lalsd)
        {
            case 'R':
            case 'r':
                system("CLS");
                printf("1.SignUp\n2.Login\n");
                return;
            default:
                printf("Input Account:");
                gets(addAccount);
                scanf("%[^\n]",addAccount);
                for(x=0; x<strlen(addAccount); x++)
                {
                    if(addAccount[x]==' ')
                    {
                        system("CLS");
                        printf("Do not has space!!\n");
                        printf("please Input again: ");
                        gets(addAccount);
                        scanf("%[^\n]",addAccount);
                        x=-1;
                        continue;
                    }
                }
                continue;
        }
    }
    printf("Input Password:");
    gets(addPassword);
    scanf("%[^\n]",addPassword);
    while(strlen(addPassword)==0)
    {
        if(strlen(addPassword)==0)
        {
            printf("password do not Null\n");
            system("pause");
            system("CLS");
            printf("Input Account:%s\n",addAccount);
            printf("Input password:");
            gets(addPassword);
            scanf("%[^\n]",addPassword);
            while(space(addPassword)==0)
            {
                system("CLS");
                printf("password do not have space!!\n");
                printf("Input Account:%s\n",addAccount);
                printf("Input password:");
                gets(addPassword);
                scanf("%[^\n]",addPassword);
            }
        }
    }
    while(space(addPassword)==0)
    {
        system("CLS");
        printf("password do not have space!!\n");
        printf("Input Account:%s\n",addAccount);
        printf("Input password:");
        gets(addPassword);
        scanf("%[^\n]",addPassword);
        while(strlen(addPassword)==0)
        {
            if(strlen(addPassword)==0)
            {
                system("CLS");
                printf("password do not Null\n");
                system("pause");
                system("CLS");
                printf("Input Account:%s\n",addAccount);
                printf("Input password:");
                gets(addPassword);
                scanf("%[^\n]",addPassword);
            }
        }
    }
    printf("Input UserName:");
    gets(addName);
    scanf("%[^\n]",addName);
    while(strlen(addName)==0)
    {
        if(strlen(addName)==0)
        {
            printf("Name do not Null\n");
            system("pause");
            system("CLS");
            printf("Input Account:%s\n",addAccount);
            printf("Input Password:%s\n",addPassword);
            printf("Input Name:");
            gets(addName);
            scanf("%[^\n]",addName);
        }
    }
    while(compareName(addName)==0)
    {
        system("CLS");
        printf("Input Account:%s\n",addAccount);
        printf("Input Password:%s\n",addPassword);
        printf("Member name had already been used!\n");
        printf("Input Name:");
        gets(addName);
        scanf("%[^\n]",addName);
        while(strlen(addName)==0)
        {
            if(strlen(addName)==0)
            {
                printf("Name do not Null\n");
                system("pause");
                system("CLS");
                printf("Input Account:%s\n",addAccount);
                printf("Input Password:%s\n",addPassword);
                printf("Input name:");
                gets(addName);
                scanf("%[^\n]",addName);
            }
        }
        continue;
    }
    printf("Input Sex(F or M):");
    while(scanf("%s",addSex)==1)
    {
        if(addSex[0]!='F' && addSex[0]!='f' && addSex[0]!='M' && addSex[0]!='m')
        {
            printf("Wrong Sex!Please Input Again\n");
            continue;
        }
        else
        {
            strcpy(totalMember[currentMemberCount].account,addAccount);
            strcpy(totalMember[currentMemberCount].password,addPassword);
            strcpy(totalMember[currentMemberCount].name,addName);
            strcpy(totalMember[currentMemberCount].sex,addSex);
            totalMember[currentMemberCount].Id=currentMemberCount;
            currentMemberCount++;
            break;
        }
    }
    system("CLS");
    printf("Hello %s!Your Account Built Up Successfully\n",totalMember[currentMemberCount-1].name);
    printf("Your Account is %s\n",totalMember[currentMemberCount-1].account);
    printf("Your Password is %s\n",totalMember[currentMemberCount-1].password);
    printf("Your Sex is %s\n",totalMember[currentMemberCount-1].sex);
    printf("Your Member Id is %03d\n",totalMember[currentMemberCount-1].Id);
    loginMember = totalMember[currentMemberCount-1];
    system("pause");
    system("CLS");
    mainMenu();
    return;
}

int compareAccount(char addAccount[])
{
    for(i=currentMemberCount-1; i>=0; i--)
    {
        if(strcmp(totalMember[i].account,addAccount)==0)
        {
            return 0;
        }
    }
    return 1;
}

int compareName(char addName[])
{
    for(i=currentMemberCount-1; i>=0; i--)
    {
        if(strcmp(addName,totalMember[i].name)==0)
        {
            return 0;
        }
    }
    return 1;
}

void change(char type,char wantchange[])
{
    char tempwantchange[Max];
    switch (type)
    {
        case 'A':
        case 'a':
            printf("Input want change Account:");
            gets(tempwantchange);
            scanf("%[^\n]",tempwantchange);
            while(strlen(tempwantchange)==0)
            {
                if(strlen(tempwantchange)==0)
                {
                    printf("Account do not Null\n");
                    system("pause");
                    system("CLS");
                    printf("Input Account:");
                    gets(tempwantchange);
                    scanf("%[^\n]",tempwantchange);
                    while(space(tempwantchange)==0)
                    {
                        system("CLS");
                        printf("Account do not have space!!\n");
                        printf("Input Account:");
                        gets(tempwantchange);
                        scanf("%[^\n]",tempwantchange);
                    }
                    
                }
            }
            while(space(tempwantchange)==0)
            {
                printf("Account do not have space!!\n");
                printf("Input Account:");
                gets(tempwantchange);
                scanf("%[^\n]",tempwantchange);
                while(strlen(tempwantchange)==0)
                {
                    if(strlen(tempwantchange)==0)
                    {
                        system("CLS");
                        printf("Account do not Null\n");
                        system("pause");
                        system("CLS");
                        printf("Input Account:");
                        gets(tempwantchange);
                        scanf("%[^\n]",tempwantchange);
                    }
                }
            }
            if(compareAccount(tempwantchange)==0)
            {
                printf("Member Account had already been used or not change!\n");
                break;
            }
            else
            {
                strcpy(wantchange,tempwantchange);
                printf("now Account is %s\n",totalMember[loginMember.Id].account);
                loginMember = totalMember[loginMember.Id];    //≠´∑sµn§J
                return;
            }
        case 'P':
        case 'p':
            printf("Input want change Password:");
            gets(tempwantchange);
            scanf("%[^\n]",tempwantchange);
            while(strlen(tempwantchange)==0)
            {
                if(strlen(tempwantchange)==0)
                {
                    printf("password do not Null\n");
                    system("pause");
                    system("CLS");
                    printf("Input password:");
                    gets(tempwantchange);
                    scanf("%[^\n]",tempwantchange);
                    while(space(tempwantchange)==0)
                    {
                        system("CLS");
                        printf("password do not have space!!\n");
                        printf("Input password:");
                        gets(tempwantchange);
                        scanf("%[^\n]",tempwantchange);
                    }
                }
            }
            while(space(tempwantchange)==0)
            {
                system("CLS");
                printf("password do not have space!!\n");
                printf("Input password:");
                gets(tempwantchange);
                scanf("%[^\n]",tempwantchange);
                while(strlen(tempwantchange)==0)
                {
                    if(strlen(tempwantchange)==0)
                    {
                        system("CLS");
                        printf("password do not Null\n");
                        system("pause");
                        system("CLS");
                        printf("Input password:");
                        gets(tempwantchange);
                        scanf("%[^\n]",tempwantchange);
                    }
                }
            }
            strcpy(wantchange,tempwantchange);
            printf("now Password is %s\n",totalMember[loginMember.Id].password);
            loginMember = totalMember[loginMember.Id];    //≠´∑sµn§J
            return;
        case 'N':
        case 'n':
            printf("Input want change Name:");
            gets(tempwantchange);
            scanf("%[^\n]",tempwantchange);
            while(strlen(tempwantchange)==0)
            {
                if(strlen(tempwantchange)==0)
                {
                    printf("Name do not Null\n");
                    system("pause");
                    system("CLS");
                    printf("Input Name:");
                    gets(tempwantchange);
                    scanf("%[^\n]",tempwantchange);
                }
            }
            if(compareName(tempwantchange)==0)
            {
                printf("Member Name had already been used or not change!\n");
                break;
            }
            else
            {
                strcpy(wantchange,tempwantchange);
                printf("now Account is %s\n",totalMember[loginMember.Id].name);
                loginMember = totalMember[loginMember.Id];    //≠´∑sµn§J
                return;
            }
        case 'S':
        case 's':
            printf("Input want change Sex:");
            scanf("%s",tempwantchange);
            if(tempwantchange[0]=='F'||tempwantchange[0]=='f'||tempwantchange[0]=='M'||tempwantchange[0]=='m')
            {
                strcpy(wantchange,tempwantchange);
                printf("now Sex is %s\n",totalMember[loginMember.Id].sex);
                loginMember = totalMember[loginMember.Id];    //≠´∑sµn§J
            }
            else
            {
                printf("wrong Sex\n");
            }
            return;
        default:
            return;
    }
    
}

void logIn()
{
    char work;
    while(1)
    {
        char addlogInway[Max],addPassword[Max];
        printf("Account/UserName:");
        gets(addlogInway);
        scanf("%[^\n]",addlogInway);
        printf("Password:");
        scanf("%s",addPassword);
        while(addlogInway[0] == '0' && addlogInway[1] == 0)
        {
            if(addPassword[0] == '0' && addPassword[1] == 0)
            {
                strcpy(totalMember[0].name,"Administrator");
                strcpy(totalMember[0].sex,"N");
                strcpy(totalMember[0].account,"Secret");
                strcpy(totalMember[0].password,"Secret");
                totalMember[0].Id = 0;
                loginMember = totalMember[0];
                AdministratorMenu();
                return;
            }
            else
            {
                printf("Wrong Password!\n");
                system("pause");
                system("CLS");
                printf("Account/UserName:");
                gets(addlogInway);
                scanf("%[^\n]",addlogInway);
                printf("Password:");
                scanf("%s",addPassword);
            }
        }
        if(compareAccount(addlogInway)==0 || compareName(addlogInway)==0)
        {
            if(strcmp(addPassword,totalMember[i].password)==0)
            {
                loginMember=totalMember[i];
                mainMenu();
                return;
            }
            else
            {
                system("CLS");
                printf("Wrong Password!\n");
                continue;
            }
        }
        else
        {
            system("CLS");
            printf("Wrong Account!\n");
            printf("want to signUp press 's' 'any' to logIn\n");
            scanf(" %c",&work);
            switch(work)
            {
                case 'S':
                case 's':
                    signUp();
                    break;
                default:
                    system("CLS");
                    continue;
            }
        }
    }
    return;
}

void mainMenu()
{
    
    int mainMenu;
    char work;
    system("CLS");
    printf("Function List\tNow login member is %s\n",loginMember.name);
    printf("1.Look up the Data of yourself\n2.Change Data\n3.Add New Book\n4.Search Book\n5.Borrow book\n6.Return book\n7.Logout\n");
    while(scanf("%d",&mainMenu)==1)
    {
        switch (mainMenu)
        {
            case 1:
                system("CLS");
                printf("ID: %03d\n",loginMember.Id);
                printf("User Name: %s\n",loginMember.name);
                printf("Sex: %s\n",loginMember.sex);
                printf("Account: %s\n",loginMember.account);
                printf("Password: %s\n",loginMember.password);
                printf("Borrow Book:\n");
                lentbook();
                system("pause");
                system("CLS");
                printf("Function List\tNow login member is %s\n",loginMember.name);
                printf("1.Look up the Data of yourself\n2.Change Data\n3.Add New Book\n4.Search Book\n5.Borrow book\n6.Return book\n7.Logout\n");
                break;
            case 2:
                system("CLS");
                printf("press 'A'(Account) 'P'(password) 'N'(name) 'S'(sex) 'any'(mainMenu)\n");
                scanf(" %c",&work);
                switch (work)
            {
                case 'A':
                case 'a':
                    change(work,totalMember[loginMember.Id].account);
                    break;
                case 'P':
                case 'p':
                    change(work,totalMember[loginMember.Id].password);
                    break;
                case 'N':
                case 'n':
                    change(work,totalMember[loginMember.Id].name);
                    break;
                case 'S':
                case 's':
                    change(work,totalMember[loginMember.Id].sex);
                    break;
                default:
                    break;
            }
                system("pause");
                system("CLS");
                printf("Function List\tNow login member is %s\n",loginMember.name);
                printf("1.Look up the Data of yourself\n2.Change Data\n3.Add New Book\n4.Search Book\n5.Borrow book\n6.Return book\n7.Logout\n");
                break;
            case 3:
                if(loginMember.Id == 0)
                {
                    if(100-tempAdd!=0)
                    {
                        system("CLS");
                        addBook();
                    }
                    else
                    {
                        printf("No Space! Do not click!\n");
                        system("pause");
                        system("CLS");
                    }
                    printf("Function List\tNow login member is %s\n",loginMember.name);
                    printf("1.Look up the Data of yourself\n2.Change Data\n3.Add New Book\n4.Search Book\n5.Borrow book\n6.Return book\n7.Logout\n");
                    break;
                }
                else
                {
                    printf("You aren't administrator.\n");
                    system("pause");
                    system("CLS");
                    printf("Function List\tNow login member is %s\n",loginMember.name);
                    printf("1.Look up the Data of yourself\n2.Change Data\n3.Add New Book\n4.Search Book\n5.Borrow book\n6.Return book\n7.Logout\n");
                    break;
                }
            case 4:
                if(totalBookCount!=0)
                {
                    search();
                    system("CLS");
                }
                else
                {
                    system("CLS");
                    printf("There is no book in the Library.\n");
                    system("pause");
                    system("CLS");
                }
                printf("Function List\tNow login member is %s\n",loginMember.name);
                printf("1.Look up the Data of yourself\n2.Change Data\n3.Add New Book\n4.Search Book\n5.Borrow book\n6.Return book\n7.Logout\n");
                break;
            case 5:
                if(loginMember.borrowlimit<2)
                {
                    system("CLS");
                    checkIn();
                }
                else
                {
                    printf("You already borrow 2 books.\n");
                    system("pause");
                    system("CLS");
                }
                printf("Function List\tNow login member is %s\n",loginMember.name);
                printf("1.Look up the Data of yourself\n2.Change Data\n3.Add New Book\n4.Search Book\n5.Borrow book\n6.Return book\n7.Logout\n");
                break;
            case 6:
                if(loginMember.borrowlimit!=0)
                {
                    system("CLS");
                    checkOut();
                }
                else
                {
                    printf("You did not borrow the book\n");
                    system("pause");
                    system("CLS");
                }
                printf("Function List\tNow login member is %s\n",loginMember.name);
                printf("1.Look up the Data of yourself\n2.Change Data\n3.Add New Book\n4.Search Book\n5.Borrow book\n6.Return book\n7.Logout\n");
                break;
            case 7:
                logOut();
                system("CLS");
                printf("Welcome To Library!\n");
                printf("1.SignUp\n2.Login\n");
                return;
        }
    }
}

void lentbook()
{
    if(loginMember.Id==0){
        return;
    }
    int x;
    if(loginMember.borrowlimit==0)
    {
        printf("\nYou did not borrow any book\n");
        printf("You can still borrow %d books.\n\n",2-loginMember.borrowlimit);
    }
    else
    {
        printf("\nYou had already borrowed %d books :\n",loginMember.borrowlimit);
        for(x=0; x<totalBookCount; x++)
        {
            if(totalBook[x].bookbelent == loginMember.Id)
            {
                printf("\nBook name is: %s\nBook number is : %03d\nAuthor name: %s\n\n",totalBook[x].bookName,totalBook[x].bookNum,totalBook[x].author);
            }
        }
        printf("You can still borrow %d books.\n\n",2-loginMember.borrowlimit);
    }
}

void addBook()
{
    int x,temptotalBookCount;
    temptotalBookCount=totalBookCount;
    printf("Enter New Book Name: (if you want stop input \"stop increasing\")\n");
    for(x=totalBookCount; x<100; x++)
    {
        printf("Book %d: ",tempAdd+1);
        gets(totalBook[x].bookName);
        scanf("%[^\n]",totalBook[x].bookName);
        if(strlen(totalBook[x].bookName)==0)
        {
            printf("Book name do not Null!!\n");
            totalBookCount = tempAdd;
            system("pause");
            break;
        }
        if(totalBook[x].bookName[0]==' ' || totalBook[x].bookName[strlen(totalBook[x].bookName)-1]==' ')
        {
            printf("the begin and end do not have space!!\n");
            totalBookCount = tempAdd;
            system("pause");
            break;
        }
        if(strcmp(totalBook[x].bookName,"stop increasing")==0)
        {
            totalBookCount = tempAdd;
            break;
        }
        else
        {
            printf("Input the author name Book %d: ",tempAdd+1);
            gets(totalBook[x].author);
            scanf("%[^\n]",totalBook[x].author);
            if(strlen(totalBook[x].author)==0)
            {
                printf("Author name do not Null!!\n");
                totalBookCount = tempAdd;
                system("pause");
                break;
            }
            if(totalBook[x].author[0]==' ' || totalBook[x].author[strlen(totalBook[x].author)-1]==' ')
            {
                printf("the begin and end do not have space!!\n");
                totalBookCount = tempAdd;
                system("pause");
                break;
            }
            totalBook[x].bookNum = x+1;
            if(bNameChk(x)==0)
            {
                printf("Already same book name\n");
                totalBookCount = tempAdd;
                break;
            }
            else
            {
                tempAdd += 1;
            }
        }
    }
    system("CLS");
    for(x=temptotalBookCount; x<tempAdd; x++)
    {
        printf("Book ID: %03d\tBook Name: %s\n",totalBook[x].bookNum,totalBook[x].bookName);
        printf("\t\tBook Author: %s\n",totalBook[x].author);
    }
    if(100-tempAdd != 0)
    {
        printf("The space still have %d space\n",100-tempAdd);
    }
    else
    {
        printf("No Space!\n");
    }
    system("pause");
    system("CLS");
    return;
}

int bNameChk(int j)
{
    int x;
    for(x=0; x<j; x++)
    {
        if(strcmp(totalBook[j].bookName,totalBook[x].bookName)==0)
        {
            if(strcmp(totalBook[j].author,totalBook[x].author)==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void checkIn()
{
    char wantborrow[100],authorName[100];
    while(1)
    {
        printf("Input book name:\n");
        gets(wantborrow);
        scanf("%[^\n]",wantborrow);
        if(strlen(wantborrow)==0)
        {
            printf("Book name do not Null!!\n");
            system("pause");
            break;
        }
        printf("Input author Name:\n");     /*•º∏—®M: ¶≥Ω÷??*/
        gets(authorName);
        scanf("%[^\n]",authorName);
        if(strlen(authorName)==0)
        {
            printf("Author name do not Null!!\n");
            system("pause");
            break;
        }
        if(research(wantborrow,authorName)==0&&flag==0)
        {
            printf("Book is not exist\n");
            break;
        }
        else
        {
            if(totalBook[research(wantborrow,authorName)].borrowornot==0)
            {
                totalBook[research(wantborrow,authorName)].borrowornot = 1;
                loginMember.borrowlimit++;
                totalBook[research(wantborrow,authorName)].bookbelent = loginMember.Id;
                printf("Borrow successful!\nOnly can borrow %d\n",2-loginMember.borrowlimit);
                break;
            }
            else
            {
                printf("It was be lent\n");
                break;
            }
        }
    }
    system("pause");
    system("CLS");
    return;
}

void checkOut()
{
    char wantreturn[100],authorName[100];
    int x;
    while(1)
    {
        printf("Did not return:\n");
        for(x=0; x<totalBookCount; x++)
        {
            if(totalBook[x].bookbelent==loginMember.Id)
                printf("Book Name: %s\tAuthor name: %s\n",totalBook[x].bookName,totalBook[x].author);
        }
        printf("Input book name:\n");
        gets(wantreturn);
        scanf("%[^\n]",wantreturn);
        if(strlen(wantreturn)==0)
        {
            printf("Book name do not Null!!\n");
            system("pause");
            break;
        }
        
        printf("Input author name:\n");
        gets(authorName);
        scanf("%[^\n]",authorName);
        if(strlen(authorName)==0)
        {
            printf("Book name do not Null!!\n");
            system("pause");
            break;
        }
        if(research(wantreturn,authorName)==0 && flag==0)
        {
            printf("The book is not exist\n");
            break;
        }
        else
        {
            if(totalBook[research(wantreturn,authorName)].borrowornot == 1)
            {
                totalBook[research(wantreturn,authorName)].borrowornot = 0;
                loginMember.borrowlimit--;
                totalBook[research(wantreturn,authorName)].bookbelent = 0;
                printf("Return successful\nOnly can borrow %d\n",2-loginMember.borrowlimit);
                break;
            }
            else
            {
                printf("Did not borrow\n");
                break;
            }
        }
    }
    system("pause");
    system("CLS");
    return;
}

int research(char wantfind[],char wantfindauthor[])
{
    int x;
    flag=0;
    for(x=0; x<totalBookCount; x++)
    {
        if(strcmp(totalBook[x].bookName,wantfind) == 0 && strcmp(totalBook[x].author,wantfindauthor)==0)
        {
            flag=1;
            return x;
        }
    }
    return 0;
}

void logOut()
{
    int x;
    for(x=0; x<currentMemberCount; x++)
    {
        if(loginMember.Id==totalMember[x].Id)
        {
            break;
        }
    }
    totalMember[x].borrowlimit = loginMember.borrowlimit;
    return;
}

void search ()
{
    int leave=0;
    if(totalBookCount==0){
        printf("There is no book in the Library.\n");
        return;
    }
    while(leave==0)
    {
        system("CLS");
        char searchWay;
        printf("Please select the function you want to use\nA Search by book name\nB Search by book number\n");
        printf("C View all of books in the Library\nD Return to main menu\n");
        scanf(" %c",&searchWay);
        switch(searchWay)
        {
            case 'A':
            case 'a':
                printf("Input the book name you want to find :");
                scanf("%s",bNameTemp);
                bNameChk_s();
                break;
            case 'B':
            case 'b':
                printf("Input the book number you want to find :");
                scanf("%d",&bNumTemp);
                switch (bNumChk())
            {
                case 0:
                    printf("Founded !\n\n");
                    printf("Book name is : %s\n",totalBook[bNumTemp-1].bookName);
                    printf("Book number is : %03d\n",bNumTemp);
                    printf("Book author is : %s\n",totalBook[bNumTemp-1].author);
                    if(totalBook[i].borrowornot==0)
                    {
                        printf("Status : Can be borrowed\n");
                    }
                    else
                    {
                        printf("Status : Can not be borrowed\n");
                    }
                    lentbook();
                    system("pause");
                    break;
                case 1:
                    printf("Did not found !\n");
                    system("pause");
                    break;
            }
                break;
            case 'C':
            case 'c':
                if(totalBookCount==0)
                {
                    printf("\nThere is no book in the Library.\n");
                        lentbook();
                    system("pause");
                    break;
                }
                else
                {
                    printf("\nThere are %03d books in the Library.\n\n",totalBookCount);
                        lentbook();
                    printf(" ============ BOOKS ============\n\n");
                    for(i=0; i<totalBookCount; i++)
                    {
                        printf("   Book number : %03d\n",totalBook[i].bookNum);
                        printf("   Book name : %s\n",totalBook[i].bookName);
                        printf("   Book author : %s\n",totalBook[i].author);
                        if(totalBook[i].borrowornot==0)
                        {
                            printf("   Status : Can be borrowed\n");
                        }
                        else
                        {
                            printf("   Status : Can not be borrowed\n");
                        }
                        printf("\n");
                    }
                    printf(" ===============================\n\n");
                    system("pause");
                    break;
                }
            case 'D':
            case 'd':
                leave=1;
                break;
        }
        if(searchWay!='D'&&searchWay!='d')
        {
            printf("Press\nA to search again\nB to return to main menu :\n");
            scanf(" %c",&confirm);
            switch (confirm)
            {
                case 'A':
                case 'a':
                    break;
                case 'B':
                case 'b':
                    leave=1;
                    break;
            }
        }
    }
    return ;
}

void bNameChk_s()
{
    int x,chk=0;
    for(x=0; x<totalBookCount; x++)
    {
        if(strcmp(bNameTemp,totalBook[x].bookName)== 0)         /*¶≥≠´Ω∆Æ—¶W*/
        {
            printf("\nBook name is : %s\nBook number is : %03d\nBook author name is : %s\n",totalBook[x].bookName,totalBook[x].bookNum,totalBook[x].author);
            printf("Status : ");
            if(totalBook[x].borrowornot==0){
                printf("Can be borrowed\n\n");
            } else {
                printf("Can not be borrowed\n\n");
            }
            chk=1;
        }
    }
    lentbook();
    if(chk==0){
        printf("Did not found !\n");
        lentbook();
    }
    return ;
}

int bNumChk()
{
    int x;
    for(x=0; x<totalBookCount; x++)
    {
        if(bNumTemp==totalBook[x].bookNum)
        {
            return 0;
        }
    }
    return 1;
}

int space(char check[])
{
    int x;
    for(x=0; x<strlen(check); x++)         /*¿À¨d™≈•’¡‰*/
    {
        if(check[x]==' ')
        {
            return 0;
        }
    }
    return 1;
}

void AdministratorMenu ()
{
    int mainMenu;
    system("CLS");
    printf("Function List\tNow login member is %s\n",loginMember.name);
    printf("1.Look up the Data of yourself\n2.Add New Book\n3.Search Book\n4.Logout\n");
    while(scanf("%d",&mainMenu)==1)
    {
        switch (mainMenu)
        {
            case 1:
                system("CLS");
                printf("ID: %03d\n",loginMember.Id);
                printf("User Name: %s\n",loginMember.name);
                printf("Sex: %s\n",loginMember.sex);
                printf("Account: %s\n",loginMember.account);
                printf("Password: %s\n",loginMember.password);
                system("pause");
                system("CLS");
                printf("Function List\tNow login member is %s\n",loginMember.name);
                printf("1.Look up the Data of yourself\n2.Add New Book\n3.Search Book\n4.Logout\n");
                break;
            case 2:
                if(100-tempAdd!=0)
                {
                    system("CLS");
                    addBook();
                }
                else
                {
                    printf("No Space! Do not click!\n");
                    system("pause");
                    system("CLS");
                }
                printf("Function List\tNow login member is %s\n",loginMember.name);
                printf("1.Look up the Data of yourself\n2.Add New Book\n3.Search Book\n4.Logout\n");
                break;
            case 3:
                if(totalBookCount!=0)
                {
                    search();
                    system("CLS");
                }
                else
                {
                    system("CLS");
                    printf("There is no book in the Library.\n");
                    system("pause");
                    system("CLS");
                }
                printf("Function List\tNow login member is %s\n",loginMember.name);
                printf("1.Look up the Data of yourself\n2.Add New Book\n3.Search Book\n4.Logout\n");
                break;
            case 4:
                logOut();
                system("CLS");
                printf("Welcome To Library!\n");
                printf("1.SignUp\n2.Login\n");
                return;
        }
    }
}

