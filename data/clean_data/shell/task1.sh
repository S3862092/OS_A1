#!/bin/sh

sort fullList.txt > sortedFL.txt
sed -E '{1d}' sortedFL.txt > sortedF1.txt
sed -E "/aaa|bbb|ccc|ddd|eee|fff|ggg|hhh|iii|jjj|kkk|mmm|nnn|lll|ooo|ppp|qqq|rrr|sss|ttt|uuu|vvv|www|xxx|yyy|zzz/d" sortedF1.txt > sortedF2.txt
sed -E "/^[[:punct:]]/d" sortedF2.txt > sortedF3.txt  
sed -E "/[0-9]/d" sortedF3.txt > sortedF4.txt
uniq sortedF4.txt > sortedF5.txt
sed -E "/'s$/d" sortedF5.txt > sortedF6.txt
sed -E "/[a-zA-Z][[:punct:]]{1,}/d" sortedF6.txt > sortedF7.txt
