#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char letter;
	int num;
	int bin;
	struct node *left;
	struct node *right;
}node;

void preorder(node *current);
void postorder(node *mommy);
node lol[100];
int y=0;
int main (){
	FILE *fp;
	FILE *fc;
	char holder[9], k = 97;
	node array[26];
	node temp[100];
	node checker;
	node *mommy, *mother, *current, *marker;
	int j, i, sum, x=0, total=0, n = 26, m=0, p;
	int path[20];
	
	k=97;
	//initialize nodes
	for(j=0; j<26;j++){
		array[j].letter = k;
		k++;
		array[j].num = 0;
		array[j].bin = 0;
		array[j].left = '\0';
		array[j].right = '\0';
		path[j] = 9;
	
	}
	
		for(j=0; j<26;j++){
		temp[j].letter = 0;
		temp[j].num = 0;
		temp[j].bin = 0;
		temp[j].left = '\0';
		temp[j].right = '\0';
		}
	mommy = (node*)malloc(sizeof(node));
	mommy->num = 0;
	//file opening
	fc= fopen("201001634.txt", "w");
	fp= fopen("test.txt", "r");
	rewind (fp);
	
	//get and count letters
	
	while(!feof(fp)) {
		m=0;
		for(i=0; i<10; i++){
		holder[i] = '\0';	
		}
		holder[0] = fgetc(fp);
		if (holder[0] != EOF){
		if(holder[0] == '*' && (holder[1]=fgetc(fp)) == '*' && (holder[2]=fgetc(fp)) == '*' && (holder[3]=fgetc(fp)) == 'E' && (holder[4]=fgetc(fp)) == 'N' && (holder[5]=fgetc(fp)) == 'D' && (holder[6]=fgetc(fp)) == '*' && (holder[7]=fgetc(fp)) == '*' && (holder[8]=fgetc(fp)) == '*')break;
		else{
		while(holder[m] != '\0'){
		for(j=0; j<26; j++) {
		if(holder[m] == array[j].letter || holder[m] == array[j].letter - 32) array[j].num++;	
		}m++;}
	}}}
	
	for(i=0; i<26; i++) {
		total = total + array[i].num;
	}


		
		
//	for(i=0; i<26;i++)printf("%c", array[i].letter);
	m=-1;
	x=0;
	n=26;
	i=0;
while(mommy->num < total && n>1){	{	
	
		//SORTING
	for(i=1; i<26; i++) {
		checker = array[i];
		for(j=i; j>0; j--) {
		if(array[j-1].num < checker.num) break; 
		else if(array[j-1].num == checker.num){
			if(array[j-1].letter < checker.letter) break;	
		}
		array[j] = array[j-1];	
		}
		array[j] = checker;	
		}
		

	//take sum of first two
	sum = array[0].num + array[1].num;
	mommy = (node*)malloc(sizeof(node));
	mommy->num = sum;
	mommy->bin =0;
	mommy->letter = 224 +x;
	m++;
	temp[m] = array[0];
	temp[++m] = array[1];
	mommy->left =&temp[m-1]; //printf("%c ", temp[m-1].letter);
	mommy->right =&temp[m]; //printf("%c  ", temp[m].letter);
	current = mommy;
	x++;


	n--;
	array[0] = *mommy;
	
	for(j=1; j<n; j++)array[j] = array[j+1];
	
	
	//SORTING AGAIN
	for(i=1; i<26; i++) {
		checker = array[i];
	for(j=i; j>0; j--) {
		if(array[j-1].num < checker.num) break; 
		else if(array[j-1].num == checker.num){
			if(array[j-1].letter < checker.letter) break;	
		}
		else
	array[j] = array[j-1];	
	}
	array[j] = checker;	
	}
}	}

	mother = mommy;
	mommy->bin = 1;
	//postorder putting ones
	postorder(mommy);
	x=0;
	current = mother;
	//finding letters
	marker= mother;
	mommy = mother;
	preorder(current);

	
	i=0;



for(m=97; m<=122; m++){
	p=0; x=0; i=0; mommy= mother;
	for(n=0; n<20; n++){
	path[n] = 9;	
	}
	
	
	while(lol[i].letter!=m){
		i++;	
	}
	while(lol[x].letter!=mommy->letter){
		x++;	
	}
	
	while(x != i){
	x=0;
	current = mommy;
	while(lol[x].letter!=mommy->letter){
		x++;	
	}
	
	if(i<x){
		if(current->left != '\0')	
		current = current->left;
		else break;
	}
	else{
		 if(current->right != '\0')	
		 current = current->right;
		 else break;
	}
	mommy = current;
	
	
	if(x!=i){
	path[p] = current->bin;
	p++;}
	
}
	
	fprintf(fc, "%c=", m-32);
	j=0;
	while(path[j] <= 1){
		fprintf(fc, "%d", path[j]);
		j++;
	}
	if(m<122)
	fprintf(fc, "\n");
}	
	fclose(fp);
	fclose(fc);
//	printf("\nDONE");
	return 0;
}
void postorder(node *mommy){
	if(mommy != NULL){
		
      if(mommy->right!= '\0') mommy->right->bin =1;
		postorder(mommy->left);	
      postorder(mommy->right);
	}
}

void preorder(node *current){
	if(current!=NULL) {
		
		preorder(current->left);
		lol[y] = *current;
		y++;
		preorder(current->right);
		
		
	}	
}

