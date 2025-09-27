#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len = strlen(s);
    char* zarray = (char*)malloc((len + 1)); // +1 for the '\0'

    int index = 0;
    for (int i = 0 ; i < numRows; i++) {
        for (int j = i ; j < len ; j+=2*(numRows - 1)) {
            zarray[index++] = s[j];
            //printf("zarray at the %3d index is this : %20s and j is equal to %3d\n", index, zarray, j);
            printf("thing append : %c\n", s[j]);
            if (i > 0 && i < numRows-1 && j + 2*(numRows-1) - 2*i < len) {
                zarray[index++] = s[j + 2*(numRows-1) - 2*i];
                //printf("s of this shit above is : %c\n", s[j + 2*(numRows-1) - 2*i] );
                //printf("j + 2*(numRows-1) - 2*i is : %3d\n", j + 2*(numRows-1) - 2*i );
            }
            //printf("index is equal to %3d\n", index);
        }
    }
    //printf("index is equal to %3d\n", index);
    zarray[index] = '\0';
    return zarray;
}


int main () {
    int nR = 4;
    char* a = "ABCDEFGHIJKL";
    printf("the length of the input string is %d\n", strlen(a));
    //printf("this is a : %s\n", a);
    char* output = convert(a, nR);
    printf("Output : %s\n", output);
    free(output);
    return 0;
}