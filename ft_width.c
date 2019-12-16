#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_width(char *str, int width, char sign);
// При входе идет поверка знака, если минус выравниевание слева
// если + -

char *ft_width(char *str, int width, char sign)
{
    int i = 0;
    int x;
    int j = 0;
    //sign == '-' ? (i = 0) : (i = strlen(str));
    char tmp[x];
    
    width > strlen(str) ? (x = width) : (x = strlen(str));
    if (sign == '+')
    {
        while (i < (x - strlen(str)))
        {
            tmp[i] = '!';
            i++;
        }
        while (str[j] != '\0')
        {
            tmp[i] = str[j];
            i++;
            j++;
        }
    }
    else if (sign == '-')
    {
        while (str[j] != '\0')
        {
            tmp[j] = str[j];
            j++;
        }
        while (j < width)
        {
            tmp[j] = '!';
            j++;
        }
    }
    (i > j) ? (tmp[i] = '\0') : (tmp[j] = '\0');
    
    if (!(str = (char *)malloc(sizeof(*str) * (strlen(tmp) + 1))))
        return (NULL);
    str = tmp;
    j = 0;
    /*while (str[j] != '\0')
    {
        printf("%c", str[j]);
        j++;
    }*/
    return (str);
}

int main(void)
{
    char *str = "privet";
    char sign = '+';

    printf("%s\n", ft_width(str, 20, sign));
    printf("%20s", str);
    //free(str);
    return (0);
}