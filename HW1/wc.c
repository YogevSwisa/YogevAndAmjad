
// Yogev Swisa 313226912 + Amjad Tarif 203497391 - OS - HW1
#include <stdio.h>

int count_words(FILE *file, int char_len){
	
	int wordcount =0, i,j=0;
	char filestring[char_len];
	filestring[0] = getc(file);
	for(i=1; i <= char_len; i++){
		filestring[i] = getc(file);
		if( (filestring[j] == ' ' && filestring[j+1] != ' ' && filestring[j+1] != '\n')  || (filestring[j] == '\n' && j != ( char_len -1 ) && filestring[j+1] != ' ' && filestring[j+1] != '\n' ) )		
			wordcount++;
		j++;
	}
	if(filestring[0] != ' ' && char_len > 1  && filestring[0] != '\n')
		wordcount++;
	return wordcount;
}

void main(int argc, char *argv[]){
	
	char* filepath = argv[1];
	int char_count=-1, line_count =0, word_count=0;
	FILE *file;
	char current_char;
	file = fopen(filepath,"r");
	
	if(file == NULL)
		printf("The file not found\n");	
	else{
		while(current_char != EOF){
			current_char= getc(file);
			if(current_char == '\n')
				line_count++;		
			char_count++;
		}
		if(line_count == 0 && char_count > 0)
			line_count = 1 ;
		rewind(file);
		word_count = count_words(file,char_count);
		fclose(file);
		printf(" %d %d %d %s \n", line_count, word_count, char_count,filepath);
	}
	return;
}


