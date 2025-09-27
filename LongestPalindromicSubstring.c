/*Given a string s, return the longest

in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

 

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int expandAroundCenter(char* s, int left, int right) {

	int n = strlen(s);
	while (left >= 0 && right < n && s[left] == s[right]) {
		left --; 
		right++;
	}

	return right - left - 1;
}

char* longestPalindrome(char* s) {
	int n = strlen(s);
	if (n == 0) {return "";}

	int start  = 0;
	int maxLen = 1;
	for (int i = 0 ; i < n ; i++) {
		int len1 = expandAroundCenter(s, i, i);     //odd 
		int len2 = expandAroundCenter(s, i, i + 1); // even
		int len  = (len1 > len2) ? len1 : len2;

		if (len > maxLen) {
			start = i - (len - 1) / 2;
			maxLen = len;
		}
	}

	char* res = (char*)malloc((maxLen + 1) * sizeof(char));
	strncpy(res, s + start, maxLen);
	res[maxLen] = '\0';
	return res;
}


void reverse(char *s)
{
	int l = 0;
	int r = strlen(s) - 1;
	char temp;
	while (l < r)
	{
		temp = s[l];
		s[l] = s[r];
		s[r] = temp;

		l++;
		r--;
	}
}

int main() {
	int maxLen = 100;
	char input[maxLen];
	printf("Input something : ");
	scanf("%s", input);
	if (strlen(input) > maxLen) {
		printf("Max character length is %d\n", maxLen);
		return 0;
	}
	char* output = longestPalindrome(input);
	printf("output : %s\n", output);
	free(output);
	return 0;
}