#include<stdio.h>
#include<string.h>

int print(int arr[10]){
for(int i=0;i<10;i++){
  printf("%d",arr[i]);
}
return 0;
}

void printfinalkey(int arr[8]){
    for(int i=0;i<8;i++){
    printf("%d",arr[i]);
}
}

void p8(int arr[8],int arr1[10]){
arr[0] = arr1[5];
arr[1] = arr1[2];
arr[2] = arr1[6];
arr[3] = arr1[3];
arr[4] = arr1[7];
arr[5] = arr1[4];
arr[6] = arr1[9];
arr[7] = arr1[8];

}

void applyp10(int arr[10],int arr1[10]){
arr[0] = arr1[2];
arr[1] = arr1[4];
arr[2] = arr1[1];
arr[3] = arr1[6];
arr[4] = arr1[3];
arr[5] = arr1[9];
arr[6] = arr1[0];
arr[7] = arr1[8];
arr[8] = arr1[7];
arr[9] = arr1[5];
}


//expansion function
void expansion( int arr[8], int arr1[8]){
 arr[0] = arr1[3];
arr[1] = arr1[0];
arr[2] = arr1[1];
arr[3] = arr1[2];
arr[4] = arr1[1];
arr[5] = arr1[2];
arr[6] = arr1[3];
arr[7] = arr1[0];
}

//XOR operation function
void Xor(int a[8],int key1[8],int result[8]){
for(int i =0;i<8 ;i++){
  if(a[i]==key1[i]){
    result[i] =0;
  }
  else{
    result[i] =1;}
  }
}


//bits division  into two halves function
void bitsdiv( int arr[4],int arr1[4],int result[8]){
printf("Left Half four bits for S0:");
for(int i =0;i<4;i++){
  arr[i] = result[i];
  arr1[i] = result[i+4];
}}


//S0 function
void S0(int arr[4],int output[2]){
int Sbox0[4][4] =  {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
int row = arr[0]*2 + arr[3];
int column = arr[1]*2 + arr[2];
int value = Sbox0[row][column];

 output[0] = value / 2;
 output[1]= value % 2;
}


//S1
void S1(int arr[4],int output[2]){
  int Sbox1[4][4] =  {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
int row = arr[0]*2 + arr[3];
int column = arr[1]*2 + arr[2];
int value = Sbox1[row][column];

output[0] = value / 2;
 output[1]= value% 2;
}

void combine(int c0[2],int d1[2],int result[4]){
result[0] = c0[0];
result[1] = c0[1];
result[2] = d1[0];
result[3] = d1[1];}

void apply4(int arr[4],int arr1[4]){
 arr[0] = arr1[1];
arr[1] = arr1[3];
arr[2] = arr1[2];
arr[3] = arr1[0];}



int main(){
  int arr[8];
 int arr1[8];
 int exp[8];
 int right_half[4];
 int left_half[4];
 char input[9];
 int  XOR[8];
 int arr2[4];
 int arr3[4];
 int applyp0[4];
 int applyp1[4];
 int temp[4];
 int result1[8];
 int result2[8];
 int arr4[4];
 int arr5[4];
 int output[2];
 int output1[2];
 int output2[2];
 int result3[4];
 int result4[4]; 
 int arr7[8]; 
 int finalarr[8];int originalkey[10];
int newkey[10];
int left_half1[5];
int right_half1[5];
int left_shift2[5];
int right_shift2[5];
int left_shift1[5];
int right_shift1[5];
int newarr[10];
int key1[8];     
int newarr1[10];
int key2[8];
int arr6[4];

//Taking input of plaintext
 printf("Enter the plaintext:");
 scanf("%8s",input);
 for (int i = 0;i<8;i++){
  arr[i]=input[i] -'0';
 } 
printf("\n");
printf("Enter your 10 digit key:");
char input1[11];   // 10 digits + null character
scanf("%s", input1);
for(int i=0; i<10; i++){
    originalkey[i] = input1[i] - '0';   // convert char to int
}
//Round 1
//  apply initial permutation
  arr1[0] = arr[1];
  arr1[1] = arr[5];
  arr1[2] = arr[2];
  arr1[3] = arr[0];
  arr1[4]  = arr[3];
  arr1[5] = arr[7];
  arr1[6] = arr[4];
  arr1[7] = arr[6];
  for(int i=0;i<4;i++){
        left_half[i]=arr1[i];
        right_half[i]=arr1[i+4];
    }
    // Key Generation
    applyp10(newkey,originalkey);
    expansion(exp,right_half);
printf("\n");

//Dividing the p10 applied key into two halves
for(int i =0;i<5;i++){
left_half[i] = newkey[i];
right_half[i] = newkey[i+5];}


//After dividing applying the leftshit  for 1st key 
//i.Left half  is shifted left
for (int i = 0;i<5;i++){
left_shift1[i] = left_half[(i+1)%5];
right_shift1[i] = right_half[(i+1)%5];}

for(int i = 0;i<5;i++){
newarr[i] = left_shift1[i];
newarr[i+5] = right_shift1[i];
}
p8(key1,newarr);


for(int i =0;i<5;i++){
  left_shift2[i] = left_shift1[(i+2)%5];
  right_shift2[i] = right_shift1[(i+2)%5];
}

for(int i=0;i<5;i++){
    newarr1[i] = left_shift2[i];
    newarr1[i+5] = right_shift2[i];
}
p8(key2,newarr1);


//Round 1
Xor(exp,key1,result1);
bitsdiv(arr2,arr3,result1);
S0(arr2,output);
S1(arr3,output1);
combine(output, output1, result3);
apply4(applyp0,result3);

int new_left[4];
for(int i=0; i <4;i++){
  new_left[i] = (applyp0[i]==left_half[i])?0:1;}
//After Swap:
 //New Left  = old Right
//New Right = result of XOR
for(int i=0;i<4;i++){
        left_half[i]=right_half[i];
        right_half[i]=new_left[i];
    }

//Round 2
expansion(arr6,right_half);
Xor(arr6,key2,result2);
 bitsdiv(arr4,arr5,result2);
    S0(arr4,output1);
    S1(arr5,output2);
    combine(output1,output2,result4);
    apply4(applyp1,result4);


    int new_left2[4];
    for(int i=0;i<4;i++)
        new_left2[i]=(applyp1[i]==left_half[i])?0:1;

    for(int i=0;i<4;i++){
        finalarr[i]=new_left2[i];
        finalarr[i+4]=right_half[i];
    }

//Applying inverse permutation
arr7[0] = finalarr[3];
arr7[1] = finalarr[0];
arr7[2] = finalarr[2];
arr7[3] = finalarr[4];
arr7[4] = finalarr[6];
arr7[5] = finalarr[1];
arr7[6] = finalarr[7];
arr7[7] = finalarr[5];


printf("The Ciphertext is:");
for (int i =0;i<8;i++){
  printf("%d",arr7[i]);
}

return 0;
}