/*
 * ---------------------------------
 * Student Name:Anshul Khatri
 * Student ID:193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "A5.h"

//---------------------- Task 1 ---------------------------------
void analyze_file(const char *filename, const char *filename2) {
	FILE* out_file,*in_file;
	out_file = fopen(filename,"r");
	in_file = fopen(filename2,"a");
	int size;
	if(out_file == NULL)
	{
		fprintf(in_file,"Error(analyze_file): Could not open file %s\n",filename);
		return;
	}
	fseek (out_file, 0, SEEK_END);
	size = ftell(out_file);
	if(size == 0){
			fprintf(in_file,"Error(analyze_file): Could not open file %s\n",filename);
			return;
		}
	fseek(out_file,0,SEEK_SET);
	char ch,ch1;
	int alpha_count = 0,num_count = 0,non_alnum =0,charac=0;
	int word_count =0,line=0;
	int para=0;

	while(!feof(out_file))
	{
		ch = fgetc(out_file);

		if (isalpha(ch))
			alpha_count++;

		else if(isdigit(ch))
			num_count++;

		else if(!isalnum(ch) && ch!='\n'  && !isspace(ch))
			++non_alnum;

		else if(ch=='\n')
		{	line++;
		ch1 = fgetc(out_file);
		fseek(out_file,-1,SEEK_CUR);

		}

		else if(ch == ch1)
			{para++;
			word_count--;
			}


		if(ch==' '||ch=='\n')
		                    {
		                        word_count++;
		                    }
		if(ch==EOF)
		{
			word_count++;line++;para++;
		}
	}
	non_alnum -=1;// EOF character subtracted.
	charac = alpha_count + non_alnum + num_count;
	fclose(out_file);



	fprintf(in_file,"#Paragraphs = %d\n",para);
	fprintf(in_file,"#lines = %d\n",line);
	fprintf(in_file,"#Words = %d\n",word_count);
	fprintf(in_file,"#Characters = %d\n",charac);
	fprintf(in_file,"Alpha = %d\n",alpha_count);
	fprintf(in_file,"Numerical = %d\n",num_count);
	fprintf(in_file,"Other = %d\n",non_alnum);
	fprintf(in_file,"\n");
	fclose(in_file);

	return;
}


//---------------------- Task 2 ---------------------------------
void format_file1(const char *in_file, const char *out_file) {



	FILE *input =fopen(in_file,"r");
	    FILE *output = fopen(out_file,"w");
	    if(input==NULL){
	        fprintf(output,"Error(format_file1): Could not open file %s\n",out_file);
	        fclose(output);
	        fclose(input);
	        return;
	    }
	    if(output==NULL){
	    	        fprintf(output,"Error(format_file1): Could not open file %s\n",in_file);
	    	        fclose(output);
	    	        fclose(input);
	    	        return;
	    	    }

	    fseek (input, 0, SEEK_END);
	    	int size = ftell(input);
	    	if(size == 0){
	    			fprintf(output,"Error(format_file1): Could not open file %s\n",in_file);
	    			fclose(output);
	    			fclose(input);
	    			return;
	    		}
	    	fseek(input,0,SEEK_SET);
	    char word[90];
	    int counter = 0;
	    if (input != NULL) {
	        while (!feof(input)) {
	            fscanf(input, "%s", word);
	            fprintf(output, "%s ", word);
	            counter++;
	            if (counter % 4 == 0) {
	                fprintf(output, "%s", "\n");
	                }
	            }
	        }
	    fclose(input);
	    fclose(output);
	    return;

}

//---------------------- Task 3 ---------------------------------
void format_file2(const char *in_file, const char *out_file) {
   FILE *infile = fopen(in_file, "r+");
   FILE *outfile = fopen(out_file, "w+");
   if(infile==NULL){
   	        fprintf(outfile,"Error(format_file1): Could not open file %s\n",out_file);
   	        fclose(outfile);
   	        fclose(infile);
   	        return;
   	    }
   	    if(outfile==NULL){
   	    	        fprintf(outfile,"Error(format_file1): Could not open file %s\n",in_file);
   	    	        fclose(outfile);
   	    	        fclose(infile);
   	    	        return;
   	    	    }

   	    fseek (infile, 0, SEEK_END);
   	    	int size = ftell(infile);
   	    	if(size == 0){
   	    			fprintf(outfile,"Error(format_file1): Could not open file %s\n",in_file);
   	    			fclose(outfile);
   	    			fclose(infile);
   	    			return;
   	    		}
   	    	fseek(infile,0,SEEK_SET);

   char ch;
   char prevChar = '\n';
   char ppchar = '\n';

   while((ch = fgetc(infile)) != EOF) {
       if(isalnum(ch)!=0 || ch==' ' || ch=='\n'){
           if(ch=='\n'&&ppchar!='\n'){
               fputc('.', outfile);
           }
           if(prevChar=='\n'){
               if(ch >= 'a' && ch <= 'z') {
                    ch = ch - 32;
                }
           }
           fputc(ch, outfile);
       }
       ppchar = prevChar;
       prevChar = ch;
   }
   if(prevChar!='\n'&&ppchar!='\n')
       fputc('.', outfile);
   fclose(infile);
   fclose(outfile);
   return;
}

//---------------------- Task 4 ---------------------------------
void get_city_details(const char *in_file, const char *out_file, char *city) {
	FILE * fil,*fol;
	fil = fopen(in_file,"r");
	fol = fopen(out_file,"a");
	fprintf(fol,"Searching for %s in \"%s\":\n",city,in_file);
	if (fil == NULL)
		        {
			fprintf(fol,"Error(get_city_details): Could not open file %s\n",in_file);
		    return ;
		        }
	if (fol == NULL)
			        {
				printf("Error(get_city_details): Could not open file %s\n",out_file);
			    return ;
			        }

	char popl[20],line[80],province[10];
	char area[20];char city1[20];


	if(strcmp(in_file,"ontario.txt")==0)
	{
		strcpy(province,"Ontario");
	}
	else if(strcmp(in_file,"Quebec.txt")==0)
	{
		strcpy(province,"Quebec");
	}


	while(fgets(line,sizeof(line),fil) != NULL)
	{


		char *token = NULL;
		//------extracting values---//

		token = strtok(line,"f");//garbage

		token = strtok(NULL," ");

		strcpy(city1,token); //city name


		token = strtok(NULL," "); // garbage

		token = strtok(NULL," ");
		strcpy(popl,token); // population


		token = strtok(NULL,"s");//garbage

		token = strtok(NULL," ");
		strcpy(area,token);

		//--------extraction done-----//

		if (strcmp(city1,city)==0)
		{
		fprintf(fol,"Province = %s\n",province);
		fprintf(fol,"Population = %s\n",popl);
		fprintf(fol,"Area = %s\n\n",area);

		break;
		}

	}

	if (strcmp(city1,city)!=0)
	{
		fprintf(fol,"Could not find %s in \"%s\"\n\n",city,in_file);
	}


	printf("\n\n");
	fclose(fol);
	fclose(fil);
	return;
}

//---------------------- Task 5 ---------------------------------
void replace_is(const char *filename, char *new_str) {

	FILE* out_file;
	out_file = fopen(filename,"r");


		if(out_file == NULL)
		{
			printf("Error(replace_is): Could not open file %s\n",filename);
			return;
		}
		/*
	 while(!feof(out_file))
		        {
		 fscanf(out_file, "%s",buf);
		 printf("%s", buf);
		 	 	 	 if (strcmp(buf,"is")==0){

		 	 	 		fseek(out_file,-1*sizeof(buf),SEEK_CUR);
		 	 	 		fprintf(out_file,"%s",new_str);

		 	 	 	 }

		        }*/
	return;
}

