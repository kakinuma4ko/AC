char* convert(char* s, int numRows)
{
    
    int count = (int)strlen(s);
    if(numRows == 1||count <= numRows )
        return s;
    char *result;
    result = malloc((count+1)*sizeof(char));
    char *temp = result;
   // int result_count = 0;
    
    
    for(int h = 0 ; h < numRows ; h ++)
    {
        for(int l = h; l < count ; l += 2*numRows - 2)
        {
            *result = s[l];
            result ++ ;
            if(h != 0 && h != numRows - 1)
            {
                int index = l + 2*(numRows - h - 1);
                if(index < count)
                {
                    *result = s[index];
                    result ++ ;
                }
            }
        }
    }
    *result = '\0';
    return temp;
}
