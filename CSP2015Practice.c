
/*
 #include <stdio.h>
 问题描述
 　　给定一个整数数列，数列中连续相同的最长整数序列算成一段，问数列中共有多少段？
 输入格式
 　　输入的第一行包含一个整数n，表示数列中整数的个数。
 　　第二行包含n个整数a1, a2, …, an，表示给定的数列，相邻的整数之间用一个空格分隔。
 输出格式
 　　输出一个整数，表示给定的数列有多个段。
 样例输入
 8
 8 8 8 0 12 12 8 0
 样例输出
 5
 样例说明
 　　8 8 8是第一段，0是第二段，12 12是第三段，倒数第二个整数8是第四段，最后一个0是第五段。
 评测用例规模与约定
 　　1 ≤ n ≤ 1000，0 ≤ ai ≤ 1000。
int main()
{
    int ch[1000];
    int count;
    int result = 0;
    scanf( "%d", &count);
    for( int i = 0; i < count; i++)
        scanf( "%d", &ch[i]);
    for( int i = 0; i < count; i++)
    {
        if( (i == 0)||( ch[i] != ch[i-1]))
            result ++;
    }
    printf("%d",result);
}
*/



/*
 问题描述
 　　给定一个年份y和一个整数d，问这一年的第d天是几月几日？
 　　注意闰年的2月有29天。满足下面条件之一的是闰年：
 　　1） 年份是4的整数倍，而且不是100的整数倍；
 　　2） 年份是400的整数倍。
 输入格式
 　　输入的第一行包含一个整数y，表示年份，年份在1900到2015之间（包含1900和2015）。
 　　输入的第二行包含一个整数d，d在1至365之间。
 输出格式
 　　输出两行，每行一个整数，分别表示答案的月份和日期。
 样例输入
 2015
 80
 样例输出
 3
 21
 样例输入
 2000
 40
 样例输出
 2
 9
 */






/*
 
 int is(int year)
 {
 if( ( year%4 == 0 && year % 100 != 0) || (year % 400 == 0))
 return 29;
 else
 return 28;
 }
int main()
{
    int year,day,resultday,resultmonth;
    scanf("%d",&year);
    scanf("%d",&day);
    if(day <= 31)
    {
        resultday = day;
        resultmonth = 1;
    }
    else if(day <= 31 + is(year))
    {
        resultday = day -31;
        resultmonth = 2;
    }
    else if (day <= 62 + is(year))
    {
        resultday = day - 31 - is(year);
        resultmonth = 3;
    }
    else if (day <= 92 + is(year))
    {
        resultday = day - 62 - is(year);
        resultmonth = 4;
    }
    else if (day <= 123 + is(year))
    {
        resultday = day - 92 - is(year);
        resultmonth = 5;
    }
    else if (day <= 153 + is(year))
    {
        resultday = day - 123 - is(year);
        resultmonth = 6;
    }
    else if (day <= 184 + is(year))
    {
        resultday = day - 153 - is(year);
        resultmonth = 7;
    }
    else if (day <= 215 + is(year))
    {
        resultday = day - 184 - is(year);
        resultmonth = 8;
    }
    else if (day <= 245 + is(year))
    {
        resultday = day - 215 - is(year);
        resultmonth = 9;
    }
    else if (day <= 276 + is(year))
    {
        resultday = day - 245 - is(year);
        resultmonth = 10;
    }
    else if (day <= 306 + is(year))
    {
        resultday = day - 276 - is(year);
        resultmonth = 11;
    }
    else if (day <= 337 + is(year))
    {
        resultday = day - 306 - is(year);
        resultmonth = 12;
    }
    printf("%d\n",resultmonth);
    printf("%d\n",resultday);
    return 0;
}

*/

/*
 问题描述：
 问题描述
 　　成成最近在搭建一个网站，其中一些页面的部分内容来自数据库中不同的数据记录，但是页面的基本结构是相同的。例如，对于展示用户信息的页面，当用户为 Tom 时，网页的源代码是
 
 
 　　而当用户为 Jerry 时，网页的源代码是
 
 
 　　这样的例子在包含动态内容的网站中还有很多。为了简化生成网页的工作，成成觉得他需要引入一套模板生成系统。
 　　模板是包含特殊标记的文本。成成用到的模板只包含一种特殊标记，格式为 {{ VAR }}，其中 VAR 是一个变量。该标记在模板生成时会被变量 VAR 的值所替代。例如，如果变量 name = "Tom"，则 {{ name }} 会生成 Tom。具体的规则如下：
 　　·变量名由大小写字母、数字和下划线 (_) 构成，且第一个字符不是数字，长度不超过 16 个字符。
 　　·变量名是大小写敏感的，Name 和 name 是两个不同的变量。
 　　·变量的值是字符串。
 　　·如果标记中的变量没有定义，则生成空串，相当于把标记从模板中删除。
 　　·模板不递归生成。也就是说，如果变量的值中包含形如 {{ VAR }} 的内容，不再做进一步的替换。
 输入格式
 　　输入的第一行包含两个整数 m, n，分别表示模板的行数和模板生成时给出的变量个数。
 　　接下来 m 行，每行是一个字符串，表示模板。
 　　接下来 n 行，每行表示一个变量和它的值，中间用一个空格分隔。值是字符串，用双引号 (") 括起来，内容可包含除双引号以外的任意可打印 ASCII 字符（ASCII 码范围 32, 33, 35-126）。
 输出格式
 　　输出包含若干行，表示模板生成的结果。
 样例输入
11 2
<!DOCTYPE html>
<html>
<head>
<title>User {{ name }}</title>
</head>
<body>
<h1>{{ name }}</h1>
<p>Email: <a href="mailto:{{ email }}">{{ email }}</a></p>
<p>Address: {{ address }}</p>
</body>
</html>
name "David Beckham"
email "david@beckham.com"
 样例输出
 <!DOCTYPE html>
 <html>
 <head>
 <title>User David Beckham</title>
 </head>
 <body>
 <h1>David Beckham</h1>
 <p>Email: <a href="mailto:david@beckham.com">david@beckham.com</a></p>
 <p>Address: </p>
 </body>
 </html>
 评测用例规模与约定
 　　0 ≤ m ≤ 100
 　　0 ≤ n ≤ 100
 　　输入的模板每行长度不超过 80 个字符（不包含换行符）。
 　　输入保证模板中所有以 {{ 开始的子串都是合法的标记，开始是两个左大括号和一个空格，然后是变量名，结尾是一个空格和两个右大括号。
 　　输入中所有变量的值字符串长度不超过 100 个字符（不包括双引号）。
 　　保证输入的所有变量的名字各不相同。
 */
/*
int isSame(char* str1,char* str2)
{
    for(int x =0 , y = 0; ;x++,y++)
    {
        if(str1[x] !=  str2[y])
            return 0;
        else if(str1[x] == '\0')
        {
            if(str2[y] == '\0')
                return 1;
            else
                return 0;
        }
        else if(str2[y] == '\0')
        {
            if(str1[x] == '\0')
                return 1;
            else
                return 0;
        }
        
    }
    return 1;
}
 */
/*
#include "string.h"
int main()
{
    int m,n;
    char wtf;
    scanf("%d %d",&m,&n);
    scanf("%c",&wtf);//缓冲区里有 m n 的换行
    char ch[100][80];
    char varname[100][100];
    char var[100][100];
   // for(int i = 0; i < m; i++)
     //   scanf("%s",&ch[m]);
    //读文本
    for (int x = 0; x < m; x++)
    {
        for(int y = 0; y< 100;y++)
        {
            scanf("%c",&ch[x][y]);
            if(ch[x][y] == '\n')
            {
                ch[x][y] = '\0';
                break;
            }
        }
    }
    //读变量
    for(int x = 0; x < n; x++)
    {
        for(int y = 0;y < 100;y++)
        {
            scanf("%c",&varname[x][y]);
            if(varname[x][y] == '"')
            {
                varname[x][y] = '\0';
                varname[x][y -1] = '\0';
                break;
            }
        }
        for(int y = 0;y < 100;y++)
        {
            scanf("%c",&var[x][y]);
            if(var[x][y] == '"')
            {
                var[x][y] = '\0';
                scanf("%c",&wtf);
                break;
            }
        }
        
    }
    //scanf("%s %s",&varname[i],&var[i]);
    //输出
    for(int i = 0; i < m; i++)// out 输出所有模板循环，输出i行
    {
        int temp = 0;
        while (1)// 输出单行，遇'\0'停止（末尾
        {
            if(ch[i][temp] == '\0')//提前一位查尾
            {
                printf("\n");
                break;
            }
            if(ch[i][temp + 1] == '\0')//提前一位查尾
            {
                printf("%c",ch[i][temp]);
                printf("\n");
                break;
            }
            if(ch[i][temp] == '{' && ch[i][temp + 1] == '{')//遇到了变量 这时 temp 为左第一个大括号
            {
                char tempvar[100];
                temp += 3;
                for(int j = 0; j < 100; j++,temp++)
                {
                    tempvar[j] = ch[i][temp];
                    if(ch[i][temp + 2] == '}')
                    {
                        temp += 3;
                        break;
                    }
                }
                for(int j = 0;;j++)//看跟哪个定义变量名一样
                {
                    if(strcmp(tempvar, varname[j]) == 0)
                    {
                        printf("%s",var[j]);
                        break;
                    }
                    else if( j == n-1)
                    {
                        break;
                    }
                }
                for(int x = temp;;x ++)
                {
                    if((ch[i][x-1] == '}')&&(ch[i][x-2] == '}'))
                        break;
                }
            }
            else//无变量 ，直接输出
                printf("%c",ch[i][temp]);
            temp ++;
        }
    }
    return 0;

}


*/

/*
 问题描述
 　　旋转是图像处理的基本操作，在这个问题中，你需要将一个图像逆时针旋转90度。
 　　计算机中的图像表示可以用一个矩阵来表示，为了旋转一个图像，只需要将对应的矩阵旋转即可。
 输入格式
 　　输入的第一行包含两个整数n, m，分别表示图像矩阵的行数和列数。
 　　接下来n行每行包含m个整数，表示输入的图像。
 输出格式
 　　输出m行，每行包含n个整数，表示原始矩阵逆时针旋转90度后的矩阵。
 样例输入
 2 3
 1 5 3
 3 2 4
 样例输出
 3 4
 5 2
 1 3
 评测用例规模与约定
 　　1 ≤ n, m ≤ 1,000，矩阵中的数都是不超过1000的非负整数。
 */
/*#include <stdio.h>
int main()
{
    int x = 0,y = 0;
    scanf("%d %d",&x,&y);
    int var[100][100];
    for(int i = 0;i < x; i++)
        for(int j = 0; j < y; j++)
            scanf("%d",&var[i][j]);
    for(int i = y - 1;i >= 0; i--)
        for(int j = 0; j < x; j++)
        {
            printf("%d",var[j][i]);
            if( j == x-1)
            {
                if(i == 0)
                    return 0;
                else
                    printf("\n");
            }
            else
                printf(" ");
        }
    
    
    
    
    
    
    return 0;
}
 */


/*
 
 问题描述
 　　给定n个整数，请统计出每个整数出现的次数，按出现次数从多到少的顺序输出。
 输入格式
 　　输入的第一行包含一个整数n，表示给定数字的个数。
 　　第二行包含n个整数，相邻的整数之间用一个空格分隔，表示所给定的整数。
 输出格式
 　　输出多行，每行包含两个整数，分别表示一个给定的整数和它出现的次数。按出现次数递减的顺序输出。如果两个整数出现的次数一样多，则先输出值较小的，然后输出值较大的。
 样例输入
 12
 5 2 3 3 1 3 4 2 5 2 3 5
 样例输出
 3 4
 2 3
 5 3
 1 1
 4 1
 评测用例规模与约定
 　　1 ≤ n ≤ 1000，给出的数都是不超过1000的非负整数。
 */
/*
#include <stdio.h>
int main()
{
    int varcount;
    scanf("%d",&varcount);
    int var[1000];
    int count[1000];
    for(int i = 0;i < 1000; i++)
        var[i] = -1;
    for(int i = 0;i < 1000; i++)
        count[i] = -1;
    int temp;
    for(int i = 0; i < varcount; i++)
    {
        scanf("%d",&temp);
        for(int j = 0;;j++)
        {
            if(var[j] == -1)
            {
                var[j] = temp;
                count[j] = 1;
                break;
            }
            else if(var[j] == temp)
            {
                count[j]++;
                break;
            }
        }
    }
    for(int j = varcount - 1; j >= 0; j--)
        for(int i = 0; i < j - 1; i++)
        {
            if(count[i] < count[i+1])
            {
                temp = count[i];
                count[i] = count[i+1];
                count[i+1] = temp;
                temp = var[i];
                var[i] = var[i+1];
                var[i+1] = temp;
            }
            else if(count[i] == count[i+1])
            {
                if(var[i] >= var[i+1])
                {
                    temp = count[i];
                    count[i] = count[i+1];
                    count[i+1] = temp;
                    temp = var[i];
                    var[i] = var[i+1];
                    var[i+1] = temp;
                }
            }
        }
    for(int i = 0;; i++)
    {
        if(var[i] == -1)
            break;
        printf("%d %d\n",var[i],count[i]);
    }
    return 0;
}
 */



/*
 问题描述
 给定n个正整数，找出它们中出现次数最多的数。如果这样的数有多个，请输出其中最小的一个。
 输入格式
 输入的第一行只有一个正整数n(1 ≤ n ≤ 1000)，表示数字的个数。
 输入的第二行有n个整数s1, s2, …, sn (1 ≤ si ≤ 10000, 1 ≤ i ≤ n)。相邻的数用空格分隔。
 输出格式
 输出这n个次数中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。
 样例输入
 6
 10 1 10 20 30 20
 样例输出
 10
 */

/*
#include <stdio.h>
int main()
{
    int varcount;
    scanf("%d",&varcount);
    int var[1000];
    int count[1000];
    for(int i = 0;i < 1000; i++)
        var[i] = -1;
    for(int i = 0;i < 1000; i++)
        count[i] = -1;
    int temp;
    for(int i = 0; i < varcount; i++)
    {
        scanf("%d",&temp);
        for(int j = 0;;j++)
        {
            if(var[j] == -1)
            {
                var[j] = temp;
                count[j] = 1;
                break;
            }
            else if(var[j] == temp)
            {
                count[j]++;
                break;
            }
        }
    }
    for(int j = varcount - 1; j >= 0; j--)
        for(int i = 0; i < j - 1; i++)
        {
            if(count[i] < count[i+1])
            {
                temp = count[i];
                count[i] = count[i+1];
                count[i+1] = temp;
                temp = var[i];
                var[i] = var[i+1];
                var[i+1] = temp;
            }
            else if(count[i] == count[i+1])
            {
                if(var[i] >= var[i+1])
                {
                    temp = count[i];
                    count[i] = count[i+1];
                    count[i+1] = temp;
                    temp = var[i];
                    var[i] = var[i+1];
                    var[i+1] = temp;
                }
            }
        }
    printf("%d",var[0]);
    return 0;
}
*/


/*
 问题描述
 　　每一本正式出版的图书都有一个ISBN号码与之对应，ISBN码包括9位数字、1位识别码和3位分隔符，
 其规定格式如“x-xxx-xxxxx-x”，
 其中符号“-”是分隔符（键盘上的减号），
 最后一位是识别码，例如0-670-82162-4就是一个标准的ISBN码。ISBN码的首位数字表示书籍的出版语言，
 例如0代表英语；第一个分隔符“-”之后的三位数字代表出版社，例如670代表维京出版社；第二个分隔之后的五位数字代表该书在出版社的编号；最后一位为识别码。
 　　识别码的计算方法如下：
 
 
 
 
 
 首位数字乘以1加上次位数字乘以2……以此类推，用所得的结果mod 11，
 所得的余数即为识别码，如果余数为10，则识别码为大写字母X。例如ISBN号码
 0-670-82162-4
 中的识别码4是这样得到的：
 对
 067082162
 这9个数字，从左至右，分别乘以1，2，…，9，再求和，即0×1+6×2+……+2×9=158，
 然后取158 mod 11的结果4作为识别码。
 编写程序判断输入的ISBN号码中识别码是否正确，如果正确，则仅输出“Right”；如果错误，则输出是正确的ISBN号码。
 
 
 
 
 输入格式
 　　输入只有一行，是一个字符序列，表示一本书的ISBN号码（保证输入符合ISBN号码的格式要求）。
 输出格式
 　　输出一行，假如输入的ISBN号码的识别码正确，那么输出“Right”，否则，按照规定的格式，输出正确的ISBN号码（包括分隔符“-”）。
 样例输入
 0-670-82162-4
 样例输出
 Right
 样例输入
 0-670-82162-0
 样例输出
 0-670-82162-4
*/
/*
#include <stdio.h>
int main()
{
    char chaIsbn[13];
    for(int i = 0; i < 13; i++)
        scanf("%c",&chaIsbn[i]);
    int intIsbn[10];
    int chartoint = '1' - 1;
    intIsbn[0] = chaIsbn[0] - chartoint;
    intIsbn[1] = chaIsbn[2] - chartoint;
    intIsbn[2] = chaIsbn[3] - chartoint;
    intIsbn[3] = chaIsbn[4] - chartoint;
    intIsbn[4] = chaIsbn[6] - chartoint;
    intIsbn[5] = chaIsbn[7] - chartoint;
    intIsbn[6] = chaIsbn[8] - chartoint;
    intIsbn[7] = chaIsbn[9] - chartoint;
    intIsbn[8] = chaIsbn[10] - chartoint;
    if(chaIsbn[12] == 'X')
        intIsbn[9] = 10;
    else
        intIsbn[9] = chaIsbn[12] - chartoint;
    
    int tempisbn = 0;
    for(int i = 1; i <= 9; i++)
        tempisbn += (intIsbn[i-1]*i);
    tempisbn = tempisbn%11 ;
    if(tempisbn == intIsbn[9])
        printf("Right");
    else if(tempisbn == 10)
        printf("%d-%d%d%d-%d%d%d%d%d-X",intIsbn[0],intIsbn[1],intIsbn[2],intIsbn[3],intIsbn[4],intIsbn[5],intIsbn[6],intIsbn[7],intIsbn[8]);
    else
        printf("%d-%d%d%d-%d%d%d%d%d-%d",intIsbn[0],intIsbn[1],intIsbn[2],intIsbn[3],intIsbn[4],intIsbn[5],intIsbn[6],intIsbn[7],intIsbn[8],tempisbn);
        
    
    
    return 0;
}


*/

/*
 问题描述
 　　有一类节日的日期并不是固定的，而是以“a月的第b个星期c”的形式定下来的，比如说母亲节就定为每年的五月的第二个星期日。
 　　现在，给你a，b，c和y1, y2(1850 ≤ y1, y2 ≤ 2050)，希望你输出从公元y1年到公元y2年间的每年的a月的第b个星期c的日期。
 　　提示：关于闰年的规则：年份是400的整数倍时是闰年，否则年份是4的倍数并且不是100的倍数时是闰年，其他年份都不是闰年。例如1900年就不是闰年，而2000年是闰年。
 　　为了方便你推算，已知1850年1月1日是星期二。
 输入格式
 　　输入包含恰好一行，有五个整数a, b, c, y1, y2。其中c=1, 2, ……, 6, 7分别表示星期一、二、……、六、日。
 输出格式
 　　对于y1和y2之间的每一个年份，包括y1和y2，按照年份从小到大的顺序输出一行。
 　　如果该年的a月第b个星期c确实存在，则以"yyyy/mm/dd"的格式输出，即输出四位数的年份，两位数的月份，两位数的日期，中间用斜杠“/”分隔，位数不足时前补零。
 　　如果该年的a月第b个星期c并不存在，则输出"none"（不包含双引号)。
 样例输入
 5 2 7 2014 2015
 样例输出
 2014/05/11
 2015/05/10
 评测用例规模与约定
 　　所有评测用例都满足：1 ≤ a ≤ 12，1 ≤ b ≤ 5，1 ≤ c ≤ 7，1850 ≤ y1, y2 ≤ 2050。
  */

#include <stdio.h>

int isR(int year)//闰年？
{
    if(year%400 == 0)
        return 1;
    else if((year%4 == 0)&&( year%100 != 0))
        return 1;
    else
        return 0;
    
}


int getDayofmonth(int year,int month)//
{
    if(month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)
        return 31;
    else if(month == 2)
    {
        if(isR(year))
            return 29;
        else
            return 28;
    }
    else
        return 30;
}

int getFinyear(int year)//一年的1/1是星期几
{
    int result = 2;
    if(year == 1850)
        return result;
    for(int temp = 1851; ;temp ++)//对普通年来说，下一年元旦的周几+1，如果当年是闰年，则（下一年）元旦的周几+2
    {
        if(isR(temp -1))
            result++;
        result++;
        result = result%7;
        if(temp == year)
            break;
    }
    return result;
}

int getFinmonth(int year,int month)//year年month月的第一天是周几 //周日为0
{
    int result = getFinyear(year);//当月第一天为星期X，天数为day，下月第一天为day-28+X，即135781012，31天，将周一变为周4，+3，30天+2，29天（闰年2月）+1，28天（普通2月）不加
    if(month == 1)
        return result;
    for(int temp = 2;;temp++)
    {
        int wtf =getDayofmonth(year, temp - 1);
        result += wtf - 28;
        result = result%7;
        if(temp == month)
            break;
    }
    
    return result;
}

int getResult(int a,int b,int c,int year)//第year年的a月第b个星期c
{
    int result = 0;
    //找到第一个星期c
    if(c == 7)
        c = 0;
    //第一个星期c为a月resul号
    if(c == getFinmonth(year, a))
        result = 1;
    else
        result = 7+c -getFinmonth(year, a) + 1;
    
    //第b个星期c为？
    result = result + 7*(b-1);
    if(result > getDayofmonth(year, a))
        printf("none");
    else
    {
        printf("%d/",year);
        if(a >= 10)
            printf("%d/",a);
        else
            printf("0%d/",a);
        if(result >= 10)
            printf("%d",result);
        else
            printf("0%d",result);
    }
    //printf("%d/%d/%d",year,a,result);
    return 0;
}




int main()
{
    int a = 0,b = 0,c = 0,y1 = 0,y2 = 0;
    scanf("%d %d %d %d %d",&a,&b,&c,&y1,&y2);
    //getResult(5, 2, 7, 2015);
    for(int temp = y1; temp <=y2; temp++)
    {
        getResult(a, b, c, temp);
        if(temp != y2)
            printf("\n");
    }
    
    
    
    return 0;
}







