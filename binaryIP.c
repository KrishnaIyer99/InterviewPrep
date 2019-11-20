//Common interview question: convert IP address XXX.XXX.XXX.XXX into binary

#include <stdio.h>
#include <stdlib.h>
int main(){
	int decimal = 10;
	int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 0; decimal > 0; i++){
       	        binary[i] = decimal%2;
                decimal = decimal/2;
        }
	for(int i = 7; i >= 0; i--){
                printf("%d", binary[i]);
        }
	return 0;
}
