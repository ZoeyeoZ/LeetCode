// String to Integer (atoi)
/*
! for whitespace in the begin
! there may be unnumerical character in the end
! empty or no valid character or reverse integer is overflow-> 0
! sign of the number

!! 判断输入必须在循环里，否则例如9223372036854775809超过long，会导致以为是负值
*/
class Solution{
public:
	int atoi(string str){
		long ans = 0;
		int sign = 1, i = 0;
		while (str[i] == ' ')
			i++;

		if ((str[i] == '-') || (str[i] == '+')){
			sign = str[i] == '-'? -1 : 1;
			i++;
		}
		while ((str[i] >= '0') && (str[i] <= '9')){
			ans = ans*10 + (str[i]-48);
			i++;
			if (ans * sign > INT_MAX)
				return INT_MAX;
			if (ans * sign < INT_MIN)
				return INT_MIN;
		}
		return ans * sign;
	}

};