#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "customCSVtoXLS.h"

void customCsvtoXls(char *filepath)
{
    char buffer[1024] ;
    char *record,*line,*cell,*eol;
    int i=0,j=0;
    int matrix[100][100];
    FILE *fstream = fopen(filepath,"r");
    // FILE *outStream = fopen("../Files/test.txt","w+");
    FILE *xlsStream = fopen("../Files/test.xlsx","w");
    if(fstream == NULL)   {
       printf("\n Failed to open the file ");
    }
    while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
    {
		record = strtok(line,";");
    // cell = strtok(record,",");
		while(record != NULL)
			{
			 // printf("record : %s \t",record) ;
       fprintf(xlsStream,"%s",record);
			 matrix[i][j++] = atoi(record) ;
			 record = strtok(NULL,";");
			}
      ++i ;
	}
  fclose(fstream);
  fclose(xlsStream);

/*FILE *textStream = fopen("../Files/test.txt","r");
  while((line = fgets(buffer,sizeof(buffer),textStream)) != NULL)
  {
  cell = strtok(line,",");
  eol = strtok(line,";");
  while(eol != NULL)
    {
    while(cell != eol)
      {
      fprintf(xlsStream,"%s",cell);
      }
    }
  }
  fclose(textStream);*/
}
