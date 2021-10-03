#inverse pyramid pattern
def func(r):
 for x in range (r):
   print('#'(r-(r-x)+1)+''(2(r-x-2)+1)+'#'*(r-(r-x)+1))
func(int(input()))   



#pyramid
def func(r):
 for x in range (r):
   print('#'(r-x-1)+''(2*x+1)+'#'(r-x-1))
func(int(input()))

'''
take inputs on different line 
4
4
change the code with simple logic to get different types of pattern 

'''
