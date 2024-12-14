#include<stdio.h>  
#include<conio.h>  

int main()  
{  
    int i, k;  
    char text[100], c;      
    printf("Enter a plaintext: \n");  
    gets(text);  
    printf("Enter key: ");  
    scanf("%d", &k);  
    for(i = 0; text[i] != '\0'; i++)  
    {  
        c = text[i];  
        if(c >= 'a' && c <= 'z')  
        {  
            c = c + k;  
            if(c > 'z')  
            {  
                c = c - 'z' + 'a' - 1;  
            }  
            text[i] = c;  
        }  
        else if(c >= 'A' && c <= 'Z')  
        {  
            c = c + k;  
            if(c > 'Z')  
            {  
                c = c - 'Z' + 'A' - 1;  
            }  
            text[i] = c;  
        }  
    }  
    printf("Encrypted message: %s", text);  
    return 0;  
}  
