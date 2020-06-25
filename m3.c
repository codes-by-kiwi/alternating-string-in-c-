

/*
Write the definition of the function with the following prototype:
char *alternate(char *s1,char *s2);
which returns a new dynamically allocated string built within the function 
containing the combination of s1 with s2 character by character. After the shorter string is 
consumed during the alternation, the remaining of the other string should be copied at the 
end of the result. For example, if s1="onestring" and s2="another" then the result of the 
alternation is the new string returned by the function which is "oanneosthreirng".
*/
#include <stdio.h>//used for basics like printf
# include <stdlib.h> //included bc of malloc 
# include <string.h>//included bc of strlen 
char *alternate(char *s1, char *s2)
{

    char *final=(char *)malloc(sizeof(char)*(strlen(s1)+strlen(s2)+1));//memory is allocated for the final string 

    if (final==NULL)
    {
        printf("Error when allocating memory!\n");
        exit(1);
      
    }
    int i,j=0;
    for(i=0;i<strlen(s2);i++)
    {
        final[j++]=s1[i];//final[0] is equal to s1[0]
        final[j++]=s2[i];//final[1] is equal to s2[0]
    }
    for(int i=strlen(s2);i<strlen(s1);i++)
        final[j++]=s1[i];
        final[strlen(s1)+strlen(s2)]='\0';
        return final;
    
}


int main(){
    char s1[100],s2[100];
    fgets(s1,100,stdin);//scans for s1
    fgets(s2,100,stdin);//scans for s2
    char *f=alternate(s1,s2);//f points to the new string which is made by alternating s1 and s2 
    printf("Final result=%s\n",f);

return 0;
}