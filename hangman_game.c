#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
int game(int);
int main()
{
    printf("\t\t**********\n");
    printf("\t\tHANGMAN GAME\t\t\n");
    printf("\t\t**********\n");
    printf("\nINSTRUCTIONS\n\nA MOVIE TITLE IS DISPLAYED HOWEVER THE CONSONANTS OF THE MOVIE TITLE ARE REMOVED (INDICATED BY AN EMPTY BLANK) \nONLY THE VOWELS IN THE TITLE OF THE MOVIE ARE DISPLAYED,THE PLAYER MUST GUESS THE MISSING LETTERS OF THE MOVIE\nTITLE. IF THE PLAYER CHOOSES LEVEL EASY HE/SHE IS GIVEN 11 CHANCES TO GUESS THE MOVIE NAME IF PLAYER CHOOSES MEDIUM\nHE/SHE IS GIVEN 9 CHANCES AND IF THE PLAYER CHOOSES HARD HE/SHE IS GIVEN 7 CHANCES\n");
    printf("\nNOTE : PLAYER MUST NOT ENTER A VOWEL AND HE/SHE MUST NOT ENTER THE SAME LETTER MORE THAN ONCE\n");
    printf("choose the difficulty : \n");
    printf("CHOICE 1 - EASY(11 CHANCES)\n");
    printf("CHOICE 2 - MEDIUM (9 CHANCES)\n");
    printf("CHOICE 3 - HARD (7 CHANCES)\n");
    int choice,z;
    scanf("%d",&choice);
    if(choice==1)
    {
        z=11;
        game(z);
    }
    if(choice==2)
    {
        z=9;
        game(z);
    }
    if(choice==3)
    {
        z=7;
        game(z);
    }
    if(choice!=1&&choice!=2&&choice!=3)
    {
        printf("\nINVALID CHOICE");
    }
    return 0;
}
int game(int z)
{
    char words_easy[][20]={"argo","brave","clue","zootopia","titanic","up","bambi","moana","speed","deadpool"};
    char words_medium[][20]={"maleficent","planes","jumanji","frozen","gravity","batman","aladdin","inception","shrek","matilda"};
    char words_hard[][20]={"divergent","cinderella","madagascar","ghostbusters","moonlight","interstellar","avengers","ratatouille","pinocchio","tangled"};
    int lower=0,upper=9;
    srand(time(0));
    int rand_num = (rand() % (upper - lower + 1)) + lower;
    char key[20];
    if(z==11)
    {
        strcpy(key,words_easy[rand_num]);
    }
    if(z==9)
    {
        strcpy(key,words_medium[rand_num]);
    }
    if(z==7)
    {
        strcpy(key,words_hard[rand_num]);
    }
    int j=0;
    int n=strlen(key);
    for(int u=0;u<n;u++)
    {
        if(key[u]=='a'||key[u]=='e'||key[u]=='o'||key[u]=='i'||key[u]=='u')
	        printf(" %c ",key[u]);
        else
        {
	        printf(" _ ");
            j++;
        }
    }
    printf("\n");
    int k=0,c=0,a[30];
    for(int re=0;re<30;re++)
    {
	    a[re]=100;
    }
    char b[30];
    int p=0;
        while(k<j && p<z)
        {
	        fflush(stdin);
	        char letter;
	        printf("\nenter a letter : ");
	        scanf("%c",&letter);
	        for(int i=0;i<n;i++)
	        {
                int r=0;
		        for(int q=0;q<n;q++)
                {
			        if(i==a[q])
                    {
				        printf(" %c ",b[q]);
                        r++;
                    }
                }
		        
		        if(key[i]==letter)
		        {
			        printf(" %c ",letter);
			        a[c]=i;
			        b[c]=letter;
			        c++;
			        k++;
                    r++;
		        }
		        if(key[i]=='a'||key[i]=='e'||key[i]=='o'||key[i]=='i'||key[i]=='u')
                    {
			        printf(" %c ",key[i]);
                    r++;
                    }
                if(r==0)
                    printf(" _ ");
		    }	
        p++;
        }
    if(k==j)
        printf("\n\t\t\tYOU HAVE WON THE GAME!!!\t\t\t");
    if(k!=j)
        {
        printf("\n\t\t\tYOU HAVE LOST THE GAME\t\t\t");
        printf("\n\t\t\tTHE MOVIE NAME WAS : ");
        for(int ch=0;ch<n;ch++)
        {
            printf("%c",key[ch]);
        }
        }
}
    

