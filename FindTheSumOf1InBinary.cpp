/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
#if 0
//由于该二进制数可能是负数，所以不能向右移动原数，因为负数右移最高位会补0，只能将标志位左移进行相与比较
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         unsigned int flag = 1;
         while(flag)
         {
             if(n & flag)
             {
                 count++;
             }
             flag <<= 1;
         }
         return count; 
     }
};
#endif
//每一次与其自身减一的值相与，没循环一次会检测出一个1的个数
// 如：
// 1101010 & 1101001 = 1101000   count = 1
// 1101000 & 1100111 = 1100000   count = 2
// 1100000 & 1011111 = 1000000   count = 3
// 1000000 & 0111111 = 0         count = 4
class Solution {
public:
     int  NumberOf1(int n) {
     	int count = 0;
         while(n)
         {
             n = (n - 1) & n;
             count++;
         }
         return count;
	}
     
};