
// Yogev Swisa 313226912 + Amjad Tarif 203497391 - OS - HW1
#include <stdio.h>

int count_words(FILE *file){
	int char_count=0, line_count =0,wordcount =0;
	if(file == NULL)
		file = stdin;
	char tmp1 = getc(file),tmp2 = getc(file),tmp;
	tmp =tmp1;
	if(tmp1 != ' '   && tmp1 != '\n' && tmp2 != EOF && tmp1 != '\t')
		wordcount++;
	while(tmp1 != EOF){
		if(tmp1 == '\n')
			line_count++;
		if( (tmp != '\t' && tmp1 == ' ' && tmp2 != ' ' && tmp2 != '\n')  || (tmp1 == '\n' && tmp2 != ' ' && tmp2 != '\n' && tmp2 != EOF ) )		
			wordcount++;
		char_count++;
		tmp = tmp1;
		tmp1 = tmp2;
		tmp2 = getc(file);
		if(tmp1 == '\t' && tmp2 == '\n')
			wordcount--;
		if(tmp != '\n' && tmp1 == '\t' && tmp2 == '\n')
			wordcount++;
	}
	if(file == stdin)
		printf(" %d %d %d \n", line_count, wordcount, char_count);
	return wordcount;
}

void main(int argc, char *argv[]){
	int char_count, line_count, word_count,i=2,total_cc=0,total_lc=0,total_wc=0,files_num=0;		
	char* filepath = argv[1];
	if(filepath == NULL){
		word_count = count_words(NULL);
	}else{
			while(filepath != NULL){
			char_count=-1; line_count =0; word_count=0;
			FILE *file; files_num++;
			char current_char = 'a';
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
				total_cc += char_count; total_lc += line_count; total_wc += word_count; 
			}
			filepath = argv[i++];
		 }
		if(files_num > 1)
			printf(" %d %d %d %s \n", total_lc, total_wc, total_cc,"total");
	}
	return;
}
