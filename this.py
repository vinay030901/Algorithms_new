def ministeps(input1,input2):

   ans = 0

   while(input2>input1):

       if (input2&1):

           input2+=1

           ans+=1

       input2//=2

       ans+=1

   return ans+input1-input2

input1 = int(input())

input2 = int(input())

print(ministeps(2,2))