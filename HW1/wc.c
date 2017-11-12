
// Yogev Swisa 313226912 + Amjad Tarif 203497391 - OS - HW1
#include <stdio.h>

int count_words(FILE *file){
	
	int char_count=0, line_count =0;
	if(file == NULL)
		file = stdin;
	int wordcount =0;
	char tmp1 = getc(file),tmp2 = getc(file);
	if(tmp1 != ' '   && tmp1 != '\n' && tmp2 != EOF)
		wordcount++;
	while(tmp1 != EOF){
		if(tmp1 == '\n')
			line_count++;
		if( (tmp1 == ' ' && tmp2 != ' ' && tmp2 != '\n')  || (tmp1 == '\n' && tmp2 != ' ' && tmp2 != '\n' && tmp2 != EOF ) )		
			wordcount++;
		char_count++;
		tmp1 = tmp2;
		tmp2 = getc(file);
	}
	if(file == stdin)
		printf(" %d %d %d \n", line_count, wordcount, char_count);
	return wordcount;
}

void main(int argc, char *argv[]){
	
	int char_count=-1, line_count =0, word_count=0;
	char* filepath = argv[1];
	if(filepath == NULL){
		word_count = count_words(NULL);
	}else{
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
		word_count = count_words(file);
		fclose(file);
		printf(" %d %d %d %s \n", line_count, word_count, char_count,filepath);
		}
	}
	return;
}
