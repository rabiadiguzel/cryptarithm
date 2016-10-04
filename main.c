//This program solves alphametic puzzleS (also known as a cryptarithm).
#include <stdio.h>
#include <string.h>
int arrayToint(int [], int);//function for turns array to integer
void barter(int [], int, int);//// function to barter array into elements
void permutation(int [], int, int, char[], char[], char[], char[]);// recursive function to generate permutations
int check(char[], char[], char[], char[], int[]);//tihs function checks the answers

int main()
{
    char input1[7], input2[7], output[7], total[21]; //defined char arrays here

    int gnome[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //defined an integer array here
    int i, k, l, j, n, m;
    do{
        printf("Enter 1st input value:  "); //gets 1st input
        scanf(" %s", input1);
    }
    while(strlen(input1)<2 || strlen(input1)>6);

    do{
        printf("Enter 2nd input value:  "); //gets 2nd input
        scanf(" %s", input2);
    }
    while(strlen(input2)<2 || strlen(input2)>6);

    do{
        printf("Enter output value:     "); //gets output
        scanf(" %s", output);
    }
    while(strlen(output)<2 || strlen(output)>6);

    for(i=0; i<7; i++){ //this for adds input1 array to total array
        total[i]=input1[i];
    }
    for(k=0; k<7; k++){ //this for adds input2 array to total array
        total[k+(strlen(input1))]=input2[k];
    }
    for(l=0; l<=7; l++){ //this for adds output array to total array
        total[l+(strlen(input1)+strlen(input2))]=output[l];
    }
    int length=(strlen(total));
    for(n=0; n<length; n++){ //this block deletes the same elements in the total array
        for(j=n+1; j<length;){
            if(total[n]==total[j]){
                for(m=j; m<length; m++){
                    total[m]=total[m+1];
                }
                length--;
            }
            else {
                j++;
            }
        }
    }
    if (strlen(total)>10){ //if total array's element's number is bigger than 10 returns main
        printf("Too many digits!\n");
        main();
    }
    else{
        printf("searching..."); //if total array's element's number is smaller than 10 program continues
        permutation(gnome, 10, 0, input1, input2, output, total);//program goes to permutation function
        return 0;
    }
}
int arrayToint(int array[], int n){ //this function turns array to integer, n is size of the array
    int i, k = 0;
    for (i = 0; i < n; i++)
        k = 10 * k + array[i];
    return k; //stringToint function returns an integer value
}
void barter (int v[], int i, int j) { // function to barter array into elements
	int	t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}
void permutation (int v[], int n, int i, char input1[], char input2[], char output[], char total[]) { // recursive function to generate permutations

	int	j;

	if (i == n){
		check(input1, input2, output, total, v); //calling check function here
	}
	else{
        for(j=i; j<n; j++){
			barter(v, i, j);
			permutation(v, n, i+1, input1, input2, output, total);
            barter(v, i, j);
		}
	}
}
int check(char input1[], char input2[], char output[], char total[], int gnome[]){//tihs function checks the answers
    int i, j;
    int input11[7], input22[7], outputt[7];

    for(i=0; i<strlen(total); i++){//this for turns input1 into numbers
        for(j=0; j<strlen(input1);j++){
            if(input1[i]==total[j]){
                input11[i]=gnome[j];
            }
        }
    }

    for(i=0; i<strlen(input2); i++){//this for turns input2 into numbers
        for(j=0; j<strlen(total);j++){
            if(input2[i]==total[j]){
                input22[i]=gnome[j];
            }
        }
    }

    for(i=0; i<strlen(output); i++){//this for turns output into numbers
        for(j=0; j<strlen(total);j++){
            if(output[i]==total[j]){
                outputt[i]=gnome[j];
            }
        }
    }

    int a, b, c;
    if (input11[0] != 0 && input22[0] != 0 && outputt[0] != 0){//The biggest digit of a number can't be zero so if it is zero
        a = arrayToint(input11, strlen(input1));              //program does not calculate it
        b = arrayToint(input22, strlen(input2));
        c = arrayToint(outputt, strlen(output));
    }

    int temp1, temp2, temp3;
    if(a + b == c && (temp1 != a ^ temp2 != b ^ temp3 != c)){ //program uses temp because of don't write the same answers again
        printf("found!\n%s:   %d\n%s:   %d\n%s:   %d\n", input1, a, input2, b, output, c);
        temp1=a;
        temp2=b;
        temp3=c;
    }

}
