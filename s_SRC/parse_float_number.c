#include "../h_HEAD/header.h"

char *parse_float_number(long double number, int pres, char sharp)
{
    ld_cast d1 = { .ld = number };
    char *str_right;
    char *str_left;
    char *full_str;
    if (pres == -1)
        pres = 0;
    //printf("%d\n", pres);
    //if (d1.parts.exponent == 32767)
    //    return(inf_nan(d1.parts.mantisa));
    // printf("%lu\n", d1.parts.mantisa);
    // printf("IM HERE %hu\n", d1.parts.exponent);
    // ZERO INF NAN
    if (d1.parts.exponent == 32767)
        return (ft_is_nan(d1.parts.mantisa));
    if (d1.parts.exponent == 0 && d1.parts.exponent == 0)
    {
        if (pres == 0)
        {
            if (sharp)
                return ("0.");
            return ("0");
        }

        else
            {
                int g = 2;
                if(!(full_str = (char *)malloc(sizeof(char) * (pres + 3))))
                    return (NULL);
                full_str[0] = '0';
                full_str[1] = '.';
                while (g < pres + 2)
                {
                    full_str[g] = '0';
                    g++;
                }
                full_str[g] = '\0';
                //if (pres == 0 && sharp)
                //   full_str = ft_strjoin(full_str, ".");
                return (full_str);
            }
    }

    // КУСОК ПАРСА МАНТИССЫ
    str_right = (char *)malloc(sizeof(char) * 65);
    str_right = parse_mantis(d1.parts.mantisa);
    // КУСОК ПАРСА ЭКСПОНЕНТЫ
    str_left = (char *)malloc(sizeof(char) * 5000);
    str_left = parse_exponent(d1.parts.exponent);
    // СОБИРАЕМ ПОЛНУЮ СТРОКУ
    full_str = (char *)malloc(sizeof(char) * 5000);
    int len1 = ft_strlen(str_left) - 1;
    int len2 = ft_strlen(str_right) - 1;
    int k = 0;
    while (k < (len1 + len2))
    {
        full_str[k] = '0';
        k++;
    }
    len1 < len2 ? (full_str = ft_str_multiply(str_left, str_right, len1, len2, full_str)) : (full_str = ft_str_multiply(str_right, str_left, len2, len1, full_str));
    full_str[len1 + len2 - 1] = '\0';
    // ПОРА ПЕРЕПИСАТЬ ЭТОТ КУСОК
    //printf("%s\n", full_str);
    if (number >= 1 || number <= -1)
        full_str = make_dot(full_str, d1.parts.exponent);
    else
        full_str = make_dot_zero(full_str, d1.parts.exponent);
    //printf("%s\n", full_str);
    full_str = make_rounding(full_str, pres);
    //printf("PORNONAL %s\n", full_str);
    if (full_str[ft_strlen(full_str) - 1] == '.')
        full_str[ft_strlen(full_str) - 1] = '\0';
    if (pres == 0 && sharp)
        full_str = ft_strjoin(full_str, ".");
    return (full_str);
}

//ZERO NAN INF
char    *ft_is_nan(unsigned long mantisa)
{
    uint64_t head = (mantisa >> 62);
    uint64_t tail = (mantisa << 2);

    if (head == 0)
    {
        if (tail == 0)
            return ("inf");
        else
            return ("nan");
    }
    else if ((head == 1) || (head == 3))
        return ("nan");
    else
    {
        if (tail == 0)
            return ("inf");
        else
            return ("nan");
    }
}

// ОКРУГЛЯЕМ ДО ЗАДАННОГО ЗНАЧЕНИЯ
char *make_rounding(char *str, int pres)
{
    char *tmp;
    if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + pres + 1))))
        return (NULL);
    int i; // Считаем до точки и после точки
    int j;
    int mem;
    j = 0;
    i = 0;
    while (str[i] != '.')
    {
        tmp[i] = str[i];
        i++;
    }
    tmp[i++] = '.';
    j = i;
    while (pres-- > -1)
    {
        while (str[j] != '\0' && pres-- >= 0)
            tmp[i++] = str[j++];
        tmp[i++] = '0';
    }
    i--;
    (str[i] >= '5' ? (mem = 1) : (mem = 0));
    //printf("HERE: %c\n", str[i]);
    tmp[i] = '\0';
    tmp = ft_rounding(tmp, mem);
    return (tmp);
}
// НАКОНЕЦ ОКРУГЛЯЕМ ДО КОНЦА
char *ft_rounding(char *str, int mem)
{
    int i;
    i = ft_strlen(str) - 1;
    //printf("%d\n", i);
    while (i >= 0)
    {
        if (str[i] == '.')
            i--;
        if (mem == 1 && str[i] >= '0' && str[i] < '9')
        {
            str[i] = ((str[i] - '0') + mem) + '0';
            mem = 0;
            break;
        }
        else if (mem == 1 && str[i] == '9')
        {
            str[i] = '0';
            i--;
        }
        else
        {
            break;
        }
    }
    if (i == -1 && mem == 1)
        str = ft_strjoin("1", str);
    return (str);
}
// СТАВИТ ТОЧКУ В ЧИСЛЕ. ВРОДЕ НОРМ. ПОКА НЕ ТРОГАТЬ
char *make_dot(char *str, unsigned short exponent)
{
    int i;
    int j;
    char *tmp;
    i = 0;
    j = 0;
    if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
        return (NULL);
    tmp[ft_strlen(str)] = '\0';
    if (str[i] == '0')
        i++;
    while (i <= ((exponent - 16383) * 0.301 + 1))
        tmp[j++] = str[i++];
    tmp[j] = '.';
    j++;
    while (str[i] != '\0')
        tmp[j++] = str[i++];
    return (tmp);
}
char *make_dot_zero(char *str, unsigned short exponent)
{
    int i;
    int j;
    char *tmp;
    i = 2;
    j = 2;
    if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
        return (NULL);
    tmp[ft_strlen(str)] = '\0';
    tmp[0] = '0';
    tmp[1] = '.';
    while (str[i] != '\0')
    {
        tmp[j] = str[i];
        i++;
        j++;
    }
    return (tmp);
}
// Парсим экспоненту в строку
char *parse_exponent(unsigned short exponent)
{
    int pow;
    char *str;
    pow = exponent - 16383;
    if (pow > 0)
    {
        str = (char *)malloc(sizeof(char) * (pow * 0.301 + 1));
        str = ft_pow(str, pow);
    }
    else if (pow == 0)
    {
        return ("1");
    }
    else
    {
        pow = pow * -1;
        str = (char *)malloc(sizeof(char) * (pow + 1));
        str = ft_pow5(str, pow);
    }
    return (str);
}
// Начинаем парсить МАНТИССУ в строку
char *parse_mantis(unsigned long mantisa)
{
    // мантисса в виде степеней -2 в нужных местах (массив строк)
    char *str;
    str = (char *)malloc(sizeof(char) * 65);
    str[64] = '\0';
    int j = 0;
    while (j <= 63)
    {
        str[j] = '0';
        j++;
    }
    str = make_mantisa(str, mantisa);
    return (str);
}
// Собирает МАНТИССУ из индексов массива
char *make_mantisa(char *str, unsigned long mantisa)
{
    char bin_str[CHAR_BIT * sizeof(unsigned long) + 1];
    int i;
    int j;
    int mem;
    char tmp;
    mem = 0;
    i = 0;
    while (itobs(mantisa, bin_str)[i] != '\0')
    {
        j = 63;
        if (itobs(mantisa, bin_str)[i] == '1')
        {
            while (j >= 0)
            {
                tmp = str[j];
                str[j] = ((str[j] - '0') + (DEG_ARR[i][j] - '0') + mem) % 10 + '0';
                mem = ((tmp - '0') + (DEG_ARR[i][j] - '0') + mem) / 10;
                j--;
            }
        }
        i++;
    }
    return (str);
}
// Мантиссу в строку битов
char *itobs(unsigned long long n, char *ps)
{
    int i;
    uint64_t size = CHAR_BIT * sizeof(uint64_t);
    i = size - 1;
    while (i >= 0)
    {
        ps[i] = (01 & n) + '0';
        i--;
        n >>= 1;
    }
    ps[size] = '\0';
    return (ps);
}
char *ft_str_multiply(char *str1, char *str2, int len1, int len2, char *tmp)
{
    int i;
    int j;
    int shift; // Поразрядный сдвиг
    int mem;   // Число "в уме"
    int res;
    shift = 0;
    i = len2;
    while (i >= 0)
    {
        j = len1;
        mem = 0;
        while (j >= 0)
        {
            res = (str1[j] - '0') * (str2[i] - '0') + (tmp[j + len2 + 1 - shift] - '0') + mem;
            mem = res / 10;
            tmp[j + len2 + 1 - shift] = res % 10 + '0';
            if (j == 0)
                tmp[i] = mem + '0';
            j--;
        }
        shift++;
        i--;
    }
    //tmp[len1 + len2 - 3] = '\0';
    return (tmp);
}
char *ft_pow(char *res, int pow) // 26 STRINGS
{
    int len;
    int ret;
    int dec;
    int j;
    
    len = pow * 0.301 + 1;
    ret = 0;
    res[len] = '\0';
    res[len - 1] = '2';
    j = -1;
    while (j++ < (len - 2))
        res[j] = '0';
    while (pow > 1)
    {
        len = ft_strlen(res) - 1;
        while (len >= 0)
        {
            dec = res[len] - '0';
            res[len] = (dec * 2 + ret) % 10 + '0';
            ret = (dec * 2 + ret) < 10 ? 0 : 1;
            len--;
        }
        res[len] = ret + '0';
        pow--;
    }

    return (res);
}
char *ft_pow5(char *res, int pow)  // 26 STRINGS
{
    int len;
    int ret;
    int dec;
    int j;
    
    len = pow + 1;
    ret = 0;
    res[len] = '\0';
    res[len - 1] = '5';
    j = -1;
    while (j++ < (len - 2))
        res[j] = '0';
    while (pow > 1)
    {
        len = ft_strlen(res) - 1;
        while (len >= 0)
        {
            dec = res[len] - '0';
            res[len] = (dec * 5 + ret) % 10 + '0';
            ret = (dec * 5 + ret) < 10 ? 0 : ((dec * 5 + ret) / 10);
            len--;
        }
        res[len] = ret + '0';
        pow--;
    }
    
    return (res);
}