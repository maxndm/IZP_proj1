/*
Překlad:
gcc -std=c99 -Wall -Wextra -Werror sheet.c -o sheet
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Table adjust - every function in this section is based on the same principle - iterating through table and appending chars to buffers based on conditions of function and when line break occurs, buffer which is representing line is added to newtable variable and then its content is emptied. This proccess is repeated until i(variable) reaches length of input table.

char *dcols(char* table,int arg1,int arg2,int maxdel,int LenofMainStr,char *newtable,char delimiter){
	int col = arg1;
	int colto = arg2;
	int colcnt = 0;
	char buffer[250] = "";
	int row=1;
	int curlen;
	for(int i=0;i<LenofMainStr;i++){
		if((colcnt<col-1 || colcnt>colto-1) && table[i]!='\n'){
			curlen = strlen(buffer);
			buffer[curlen] = table[i];
		}
		if(table[i]==delimiter){
			colcnt++;
		}
		if(table[i]=='\n'){
			curlen = strlen(buffer);
			if(arg2==maxdel+1){
				buffer[curlen-1] = table[i];
			}else{
				buffer[curlen] = table[i];
			}
			row++;
			colcnt=0;
			strcat(newtable,buffer);
			memset(buffer,0,strlen(buffer));
			}
		}
return newtable;
}
//
char *dcol(char* table,int arg1,int maxdel,int LenofMainStr,char *newtable,char delimiter){
	int col = arg1;
	int colcnt = 0;
	char buffer[250] = "";
	int row=1;
	int curlen;
	for(int i=0;i<LenofMainStr;i++){
		if(colcnt!=col-1 && table[i]!='\n'){
			curlen = strlen(buffer);
			buffer[curlen] = table[i];
		}
		if(table[i]==delimiter){
			colcnt++;
		}
		if(table[i]=='\n'){
			curlen = strlen(buffer);
			if(arg1==maxdel+1){
				buffer[curlen-1] = table[i];
			}else{
				buffer[curlen] = table[i];
			}

			row++;
			colcnt=0;
			strcat(newtable,buffer);
			memset(buffer,0,strlen(buffer));
			}
		}
return newtable;
}
//
char *acol(char* table,int LenofMainStr,char *newtable,char delimiter){
	char buffer[250] = "";
	int curlen;
	for(int i=0;i<LenofMainStr;i++){
		curlen = strlen(buffer);
		buffer[curlen] = table[i];
		if(table[i]=='\n'){
			buffer[curlen] = delimiter;
			buffer[curlen+1] = '\n';
			strcat(newtable,buffer);
			memset(buffer,0,strlen(buffer));
			}
		}

		return newtable;
	}
//
char *icol(char* table,int rows,int maxdel,int arg1,int LenofMainStr,char *newtable,char delimiter){
	int col = arg1;
	int curcol=1;
	int row = 1;
	int append = 0;
	int curlen;

	char buffer[250] = "";
	if(col==1){
		buffer[0] = delimiter;
	}

	for(int i=0;i<LenofMainStr;i++){
		if(col>1 && col<=maxdel+1){
			curlen = strlen(buffer);
			buffer[curlen] = table[i];
			if(table[i]==delimiter && col>1){
				if(curcol==col-1 && append==0){
					append++;
					buffer[curlen]=table[i];
					buffer[curlen+1] = delimiter;
				}else{curcol++;}
			}
			if(table[i]=='\n' && col>1){
				row++;
				append=0;
				curcol=1;
				if(row==rows+1){
					buffer[curlen+2] = '\0';
					strcat(newtable,buffer);
					memset(buffer,0,strlen(buffer));
				}
			}
		}else if(col==1){
			curlen = strlen(buffer);
			buffer[curlen] = table[i];
			if(table[i]=='\n'){
				row++;
				if(row<rows+1){
					buffer[curlen]='\n';
					buffer[curlen+1] = delimiter;
					buffer[curlen+2] = '\0';
					strcat(newtable,buffer);
					memset(buffer,0,strlen(buffer));
				}
				else{
					buffer[curlen]='\n';
					buffer[curlen+2] = '\0';
					strcat(newtable,buffer);
					memset(buffer,0,strlen(buffer));
				}
			}
		}
	}

return newtable;
}
char *drows(char* table,int arg1,int arg2,int LenofMainStr,char *newtable){
	int row = 1;
	int rowtodel = arg1;
	int rowtodelto = arg2;
	int curlen;

	char buffer[250] = "";

	for(int i=0;i<LenofMainStr;i++){
		if(row<rowtodel || row>rowtodelto){
			curlen = strlen(buffer);
			buffer[curlen] = table[i];
		}
		if(table[i] == '\n'){
			row++;
			strcat(newtable,buffer);
			memset(buffer,0,strlen(buffer));
		}
	}

	return newtable;
}

char *drow(char* table,int arg1,int LenofMainStr,char *newtable){
	int row = 1;
	int rowtodel = arg1;
	int curlen;

	char buffer[250] = "";

	for(int i=0;i<LenofMainStr;i++){
		if(row!=rowtodel){
			curlen = strlen(buffer);
			buffer[curlen] = table[i];
		}
		if(table[i] == '\n'){
			row++;
			strcat(newtable,buffer);
			memset(buffer,0,strlen(buffer));
		}
	}

	return newtable;
}
//
char *arow(char* table,int rows,int maxdel,int LenofMainStr,char *newtable,char delimiter){
	int rown = rows+1;
	char buffer[250] = "";
	int row=1;
	int curlen;

	for(int i=0;i<LenofMainStr;i++){
			curlen = strlen(buffer);
			buffer[curlen] = table[i];
		if(table[i]=='\n'){
			if(row==rown-1 && rown!=1){
				for(int j=0;j<=maxdel;j++){
					curlen = strlen(buffer);
					buffer[curlen] = delimiter;
				}
			}
			row++;
			buffer[curlen] = '\n';
			strcat(newtable,buffer);
			memset(buffer,0,strlen(buffer));
			}
		}
	return newtable;
}
//
char *irow(char* table,int maxdel,int arg1,int LenofMainStr,char *newtable,char delimiter){
	int rown = arg1;
	char buffer[250] = "";
	int row=1;
	int curlen;
		if(rown==1){
			for(int j=0;j<maxdel;j++){
				curlen = strlen(buffer);
				buffer[curlen] = delimiter;
			}
			curlen = strlen(buffer);
			buffer[curlen] = '\n';
	}
	for(int i=0;i<LenofMainStr;i++){
			curlen = strlen(buffer);
			buffer[curlen] = table[i];
		if(table[i]=='\n'){
			if(row==rown-1 && rown!=1){
				for(int j=0;j<=maxdel;j++){ // here
					curlen = strlen(buffer);
					buffer[curlen] = delimiter;
				}
			}
			row++;
			buffer[curlen] = '\n';
			strcat(newtable,buffer);
			memset(buffer,0,strlen(buffer));
			}
		}
	return newtable;
}
// Adjusting data -  every function in this section is based on the same principle - iterating through input table and searching particular column specified by arg1, arg2 (and argSTR - which is string value used in cset). arg1 and arg2 are compared with curcol(variable holding current column) or maxdel(max delimiter number in row) after that buffer(variable) is filled with characters from input table or variable that holds specific data (for example in function copy N M - copied data from Nth column defined by arg1 - stored in cpyvalue variable) which are afterwards emptied so it can be filled again in next row(defined by \n) - buffer (like in table edjust) represents 1 row in output table.


char *cset(char *table,int arg1,char* argSTR,int LenofMainStr,char *newtable,char delimiter){
int coltoset = arg1;
int curcol=0;
int added = 0;
int curlen;

char buffer[250] = "";

for(int i=0;i<LenofMainStr;i++){
	if(curcol==coltoset-1 && added==0){
		strcat(buffer,argSTR);   //adds argSTR into buffer if current col(curcol) is equal to coltoset-1 (number of delimiters+1 is the same as number of columns)
		added = 1;
	}else if(table[i]==delimiter){
		curcol++;
		curlen = strlen(buffer);
		buffer[curlen] = table[i];
	}
	else if(table[i]=='\n'){
		curcol=0;
		added=0;
		curlen = strlen(buffer);
		buffer[curlen] = table[i];
		strcat(newtable,buffer); //modified buffer is added to output table and then emptied

		memset(buffer,0,strlen(buffer));
	}else if(curcol!=coltoset-1){
		curlen = strlen(buffer);
		buffer[curlen] = table[i];
	}
}

return newtable;
}

char *tolowerf(char *table,int maxdel,int arg1,int LenofMainStr,char *newtable,char delimiter){
int coltoset = arg1;
int curcol=0;
int curlen;

char buffer[250] = "";
char ToLowerVal[100] = ""; //value found in column defined by arg1

for(int i=0;i<LenofMainStr;i++){
	if(curcol==coltoset-1 && table[i]!= delimiter){
			ToLowerVal[strlen(ToLowerVal)] = table[i]; // when curcol is equal to arg1-1 (coltoset-1) characters from input table are appended into Buffer-like variable ToLowerVal  and changes its content to lowercase if its possible - if not its ignored.
		}
	if(table[i]==delimiter || table[i] == '\n'){
		if(atoi(ToLowerVal)==0){										 //only if its string - it determines if single characters are characters of alphabet
			for(int j=0;j<(int)strlen(ToLowerVal);j++){
				if(ToLowerVal[j]>64 && ToLowerVal[j]<91){
					ToLowerVal[j] = ToLowerVal[j]+32;
				}
			}
		}
	}

	if(table[i]==delimiter){
		curcol++;
		strcat(buffer,ToLowerVal);
		buffer[strlen(buffer)] = table[i];
		memset(ToLowerVal,0,strlen(ToLowerVal));
	}
	else if(table[i]=='\n'){
		curcol=0;
		strcat(buffer,ToLowerVal);
		if(coltoset-1!=maxdel){
			buffer[strlen(buffer)] = table[i];
		}
		memset(ToLowerVal,0,strlen(ToLowerVal));
		strcat(newtable,buffer);
		memset(buffer,0,strlen(buffer));
	}else if(curcol!=coltoset-1){
		curlen = strlen(buffer);
		buffer[curlen] = table[i];
	}
}

return newtable;
}


//functionality is same as tolower function
char *tupperf(char *table,int maxdel,int arg1,int LenofMainStr,char *newtable,char delimiter){
int coltoset = arg1;
int curcol=0;
int curlen;

char buffer[250] = "";
char ToUpperVal[100] = "";

for(int i=0;i<LenofMainStr;i++){
	if(curcol==coltoset-1 && table[i]!= delimiter){
			ToUpperVal[strlen(ToUpperVal)] = table[i];
		}
	if(table[i]==delimiter || table[i] == '\n'){
		if(atoi(ToUpperVal)==0){
			for(int j=0;j<(int)strlen(ToUpperVal);j++){
				if(ToUpperVal[j]>96 && ToUpperVal[j]<123){
					ToUpperVal[j] = ToUpperVal[j]-32;
				}
			}
		}
	}

	if(table[i]==delimiter){
		curcol++;
		strcat(buffer,ToUpperVal);
		buffer[strlen(buffer)] = table[i];
		memset(ToUpperVal,0,strlen(ToUpperVal));
	}
	else if(table[i]=='\n'){
		curcol=0;
		strcat(buffer,ToUpperVal);
		if(coltoset-1!=maxdel){
			buffer[strlen(buffer)] = table[i];
		}
		memset(ToUpperVal,0,strlen(ToUpperVal));
		strcat(newtable,buffer);
		memset(buffer,0,strlen(buffer));
	}else if(curcol!=coltoset-1){
		curlen = strlen(buffer);
		buffer[curlen] = table[i];
	}
}

return newtable;
}

char *roundfunc(char *table,int maxdel,int arg1,int LenofMainStr,char *newtable,char delimiter){
int coltoset = arg1;
int curcol=0;
int curlen;

char buffer[250] = "";
char ToRoundVal[100] = "";

float numholderf;

for(int i=0;i<LenofMainStr;i++){
	if(curcol==coltoset-1 && table[i]!= delimiter){ // when current column(curcol) is equal to coltoset-1 (arg1-1) ToToundVal variable is filled with characters and represents value of float. When number after decimal point is bigger then 5, number is rounded up.
			ToRoundVal[strlen(ToRoundVal)] = table[i];
		}
	if(table[i]==delimiter || table[i] == '\n'){
		if(atof(ToRoundVal)>0){
			numholderf = atoi(ToRoundVal);
			for(int j = 0;j<(int)strlen(ToRoundVal);j++){
				if(ToRoundVal[j]=='.' && (int)ToRoundVal[j+1]-'0'>=5 ){
					numholderf++;
				}
			}
		}
	}

	if(table[i]==delimiter){
		curcol++;
		if(atof(ToRoundVal)==0){
			strcat(buffer,ToRoundVal);
		}else{
			buffer[strlen(buffer)] = (char)numholderf+'0';
		}
		buffer[strlen(buffer)] = table[i];
		memset(ToRoundVal,0,strlen(ToRoundVal));
	}
	else if(table[i]=='\n'){
		curcol=0;

		if(atof(ToRoundVal)==0){
			strcat(buffer,ToRoundVal);
		}else if(atof(ToRoundVal)!=0 && coltoset-1==maxdel){
			buffer[strlen(buffer)] = (char)numholderf+'0';
			buffer[strlen(buffer)] = table[i];
		}else{
			buffer[strlen(buffer)] = (char)numholderf+'0';
		}

		if(coltoset-1 != maxdel){
			buffer[strlen(buffer)] = '\n';
		}

		memset(ToRoundVal,0,strlen(ToRoundVal));
		strcat(newtable,buffer);
		memset(buffer,0,strlen(buffer));
	}else if(curcol!=coltoset-1){
		curlen = strlen(buffer);
		buffer[curlen] = table[i];
	}
}

return newtable;
}

//functionality is based on round function - it only ignores everything after decimal point including decimal point.
char *intfunc(char *table,int maxdel,int arg1,int LenofMainStr,char *newtable,char delimiter){
int coltoset = arg1;
int curcol=0;
int curlen;

char buffer[250] = "";
char ToRoundVal[100] = "";

float numholderf;

for(int i=0;i<LenofMainStr;i++){
	if(curcol==coltoset-1 && table[i]!= delimiter){
			ToRoundVal[strlen(ToRoundVal)] = table[i];
		}
	if(table[i]==delimiter || table[i] == '\n'){
		if(atof(ToRoundVal)>0){
			numholderf = atoi(ToRoundVal);
		}
	}

	if(table[i]==delimiter){
		curcol++;
		if(atof(ToRoundVal)==0){
			strcat(buffer,ToRoundVal);
		}else{
			buffer[strlen(buffer)] = (char)numholderf+'0';
		}
		buffer[strlen(buffer)] = table[i];
		memset(ToRoundVal,0,strlen(ToRoundVal));
	}
	else if(table[i]=='\n'){
		curcol=0;

		if(atof(ToRoundVal)==0){
			strcat(buffer,ToRoundVal);
		}else if(atof(ToRoundVal)!=0 && coltoset-1==maxdel){
			buffer[strlen(buffer)] = (char)numholderf+'0';
			buffer[strlen(buffer)] = table[i];
		}else{
			buffer[strlen(buffer)] = (char)numholderf+'0';
		}

		if(coltoset-1 != maxdel){
			buffer[strlen(buffer)] = '\n';
		}

		memset(ToRoundVal,0,strlen(ToRoundVal));
		strcat(newtable,buffer);
		memset(buffer,0,strlen(buffer));
	}else if(curcol!=coltoset-1){
		curlen = strlen(buffer);
		buffer[curlen] = table[i];
	}
}

return newtable;
}

char *copy(char *table,int maxdel,int arg1,int arg2,int LenofMainStr,char *newtable,char delimiter){
int copyfrom = arg1;
int copyto = arg2;
int curcol=0;
int added = 0;
int copied = 0;
int rowstarti = 0;
int setzero = 0;


char buffer[250] = "";
char cpyvalue[100]= "";

for(int i=0;i<LenofMainStr;i++){

	if(setzero==1){
		i = rowstarti;
		setzero=2;
	}
	if(curcol!=copyto-1 && copied==1){
		buffer[strlen(buffer)] = table[i]; //If already copied - inserts chars from table to buffer
	}

	if(curcol==copyfrom-1 && table[i]!=delimiter && table[i]!='\n' && copied==0){
		cpyvalue[strlen(cpyvalue)]=table[i];
	}else if(curcol==copyfrom-1 && table[i]==delimiter && copied==0){
		copied = 1;
		curcol++;

	}else if(curcol==copyfrom-1 && table[i]=='\n' && copied==0){
		copied = 1;

	}else if(table[i]==delimiter){
		curcol++;
	}

	if(copied==1 && setzero==0){
		curcol=0;
		setzero=1;
	}
	if(curcol==copyto-1 && copied==1 && added==0 && setzero==2){
		added=1;
		strcat(buffer,cpyvalue);
		if(copyto-1!=maxdel && arg1<arg2){
			buffer[strlen(buffer)]=delimiter;
		}else if(copyto-1==maxdel){
			buffer[strlen(buffer)]='\n';
		}else{
			buffer[strlen(buffer)]=delimiter;
		}
	}
	if(table[i]=='\n' && copied==1 && setzero==2){
		strcat(newtable,buffer);
		memset(cpyvalue,0,strlen(cpyvalue));
		memset(buffer,0,strlen(buffer));
		rowstarti = i+1;
		copied=0;
		setzero=0;
		curcol=0;
		added=0;

	}
}

return newtable;
}


char *swap(char *table,int maxdel,int arg1,int arg2,int LenofMainStr,char *newtable,char delimiter){
int copyfrom = arg1;
int copyfrom2 = arg2;
int curcol=0;
int added = 0;
int added2 = 0;
int copied = 0;
int copied2 = 0;
int rowstarti = 0;
int setzero = 0;

char buffer[250] = "";
char cpyvalue[100]= "";
char cpyvalue2[100]= "";

for(int i=0;i<=LenofMainStr;i++){

	if(setzero==1 || setzero==3){ //4 phased algoirthm which resets the iteration of current row - if it finds value in columns set by arg1(phase1) it searches for value in columns set by arg2(phase2) - phase3(not really needed just sets to phase4 unpurposefully) - phase4 - appending data to buffer and then modifying buffer to desired.
		i = rowstarti;
		if(setzero==1){
			setzero = 2;

		}else{
			setzero = 4;
		}
	}


	if(curcol==copyfrom-1 && table[i]!=delimiter && table[i]!='\n' && copied==0 && setzero==0){
		cpyvalue[strlen(cpyvalue)]=table[i];
	}else if(curcol==copyfrom-1 && table[i]==delimiter && copied==0 && setzero==0){
		copied = 1;
		curcol++;

	}else if(curcol==copyfrom-1 && table[i]=='\n' && copied==0 && setzero==0){
		copied = 1;
	}else if(table[i]==delimiter && setzero==0){
		curcol++;
	}

	if(copied==1 && copied2==0 && setzero==0){
		curcol=0;
		setzero=1;
	}

	if(curcol==copyfrom2-1 && table[i]!=delimiter && table[i]!='\n' && copied2==0 && setzero==2){
		cpyvalue2[strlen(cpyvalue2)]=table[i];
	}else if(curcol==copyfrom2-1 && table[i]==delimiter && copied2==0 && setzero==2){
		copied2 = 1;
		curcol++;

	}else if(curcol==copyfrom2-1 && table[i]=='\n' && copied2==0 && setzero==2){
		copied2 = 1;
	}else if(table[i]==delimiter && setzero==2 ){
		curcol++;
	}

	if(copied==1 && copied2==1 && setzero==2){
		curcol=0;
		setzero=3;
	}

	if(curcol!=copyfrom2-1 && curcol!=copyfrom-1 && setzero==4){
		// printf("%c\n",table[i] );
		buffer[strlen(buffer)] = table[i]; //If already copied - inserts chars from table to buffer
	}
	if(table[i]==delimiter && setzero==4){
		curcol++;
	}


	if(curcol==copyfrom2-1 && copied==1 && added==0 && setzero==4){
		added=1;
		strcat(buffer,cpyvalue);
		if(copyfrom2-1!=maxdel && arg1<arg2){
			buffer[strlen(buffer)]=delimiter;
		}else if(copyfrom2-1==maxdel){
			buffer[strlen(buffer)]='\n';
		}else{
			buffer[strlen(buffer)]=delimiter;
		}


	}
	if(curcol==copyfrom-1 && copied2==1 && added2==0 && setzero==4){
		added2=1;
		strcat(buffer,cpyvalue2);
		if(copyfrom-1!=maxdel && arg1<arg2){
			buffer[strlen(buffer)]=delimiter;
		}else if(copyfrom-1==maxdel){
			buffer[strlen(buffer)]='\n';
		}else{
			buffer[strlen(buffer)]=delimiter;
		}


	}
	if(table[i]=='\n' && copied==1 && copied2==1 && setzero==4){
		// printf("buffer: %s\n",buffer );

		strcat(newtable,buffer);
		memset(cpyvalue2,0,strlen(cpyvalue2));
		memset(cpyvalue,0,strlen(cpyvalue));
		memset(buffer,0,strlen(buffer));
		rowstarti = i+1;
		// printf("rowstarti: %d\n",rowstarti );
		copied=0;
		copied2=0;
		setzero=0;
		curcol=0;
		added=0;
		added2=0;

	}
}

return newtable;
}

char *move(char *table,int maxdel,int arg1,int arg2,int LenofMainStr,char *newtable,char delimiter){
int movefrom = arg1;
int moveto = arg2;
int curcol=0;
int added = 0;
int copied = 0;
int rowstarti = 0;
int setzero = 0;

char buffer[250] = "";
char cpyvalue[100]= "";

for(int i=0;i<=LenofMainStr;i++){

	if(setzero==1){
		i = rowstarti;   //phases resets the row iteration
		setzero = 2;
		}

	if(curcol==movefrom-1 && table[i]!=delimiter && table[i]!='\n' && copied==0 && setzero==0){
		cpyvalue[strlen(cpyvalue)]=table[i];
	}else if(curcol==movefrom-1 && table[i]==delimiter && copied==0 && setzero==0){
		copied = 1;
		curcol++;

	}else if(curcol==movefrom-1 && table[i]=='\n' && copied==0 && setzero==0){
		copied = 1;
	}else if(table[i]==delimiter && setzero==0){
		curcol++;
	}

	if(copied==1 && setzero==0){
		curcol=0;
		setzero=1;
		// printf("cpyvalue: %s\n",cpyvalue );
	}

	if(arg2 == 1){

		if(table[i]==delimiter && setzero==2){
			curcol++;
		}


		if(curcol==moveto-1 && copied==1 && added==0 && setzero==2){
			added=1;
			if(arg2>arg1){
				cpyvalue[strlen(cpyvalue)]=delimiter;
			}
			if(arg1>arg2){
				cpyvalue[strlen(cpyvalue)]=delimiter;
			}
			strcat(buffer,cpyvalue);
		}

		if(curcol!=movefrom-1 && setzero==2){
				buffer[strlen(buffer)] = table[i];

		}

		if(table[i]=='\n' && copied==1 && setzero==2){
			// printf("buffer: %s\n",buffer );
			if(arg1==maxdel+1){
				buffer[strlen(buffer)]= '\n';
			}
			strcat(newtable,buffer);
			memset(cpyvalue,0,strlen(cpyvalue));
			memset(buffer,0,strlen(buffer));
			rowstarti = i+1;
			// printf("rowstarti: %d\n",rowstarti );
			copied=0;
			setzero=0;
			curcol=0;
			added=0;

		}
	}else{
		if(curcol!=movefrom-1 && setzero==2){
				buffer[strlen(buffer)] = table[i]; //If already copied - inserts chars from table to buffer
		}

		if(table[i]==delimiter && setzero==2){
			curcol++;
		}


		if(curcol==moveto-1 && copied==1 && added==0 && setzero==2){
			added=1;
			// printf("buffer bef: %s\n",buffer );
			if(arg2>arg1){
				cpyvalue[strlen(cpyvalue)]=delimiter;
			}
			if(arg1>arg2){
				cpyvalue[strlen(cpyvalue)]=delimiter;
			}
			strcat(buffer,cpyvalue);
			// printf("buffer af: %s\n",buffer );

		}

		if(table[i]=='\n' && copied==1 && setzero==2){
			// printf("buffer: %s\n",buffer );
			if(arg1>arg2){
				buffer[strlen(buffer)-1]= '\n';
			}
			strcat(newtable,buffer);
			memset(cpyvalue,0,strlen(cpyvalue));
			memset(buffer,0,strlen(buffer));
			rowstarti = i+1;
			// printf("rowstarti: %d\n",rowstarti );
			copied=0;
			setzero=0;
			curcol=0;
			added=0;

		}

	}

}

return newtable;
}

int main(int argc,char *argv[]){ ///////////////////////////////////////////////MAIN///////////////////////////////////////////////////
	char c;
  char str[500] = "";
	char newtable[500] = "";
	char delimiter;
	char delimstr[100] = "";
	char *ret;

	const int cmdcnt = 17; //16 commands

  int rows = 0;
  int maxdel = 0;
  int curlen;
  int LenofMainStr;
	int colsize=0;
	int rowsize=0;

	int cmp;
	int firstfstart;
	int arg1;
	int arg2;
	char argSTR[100] = "";
												//0	   	1      2      3      4      5      6        7      8       9         10       11     12     13    14     15      16
	char* commands[] = {"irow","arow","drow","icol","acol","dcol","drows","dcols","cset","tolower","toupper","round","int","copy","swap","move","rows"};

	// printf("%d\n",argc );
	int firstarg = strcmp(argv[1],"-d"); //if first argument(argv[1]) is '-d' - delimiter is set as argv[2][0] argv[2] might have multiple values surronded by double quotes - it works as filter for possible delimiters - it means: if ":\;." found int input table - it's replaced by first character - so ":" . and if -d parametr is not used - delimiter is 32(space)
	if(firstarg==0){
		memmove(delimstr,argv[2],strlen(argv[2]));
		delimiter = argv[2][0];
		firstfstart = 3; // if -d arguments is included - first command starts at argv[3]
		// printf("delimstr %s\n", delimstr);
		// printf("delimiter %c\n", delimiter);

	}else{
		for(int a=0;a<cmdcnt;a++){
			firstarg = (strcmp(argv[1],commands[a]));
			if(firstarg==0){
				delimiter = 32 ;
				firstfstart = 1;// if -d arguments is excluded - first command starts at argv[1]
				break;
			}else if(firstarg!=0 && a==cmdcnt-1){
				fprintf(stderr, "Invalid argument '%s'.\n",argv[1] );
				return 1;
			}
		}
	}
if(firstfstart==1){
	while ( (c=getchar()) != EOF){
		// printf(" char : %c\n",c );
		curlen = strlen(str);
		str[curlen] = c;
		colsize++;
		rowsize++;
		if(c == '\n'){
			rows++;
			if(rowsize>10240){
				fprintf(stderr, "Max row size exceeded 10kiB %d\n",rowsize );
				return 1;
			}
			rowsize = 0;
		}
		if(c == delimiter && rows<1 ){maxdel++;} //max cols depends on header size
		if(c == delimiter ){
			if(colsize-1 > 100){
				fprintf(stderr, "Max columns size exceeded 100 %d\n",colsize );
				return 1;
			}
			colsize=0;
		}
	}

}else if(firstfstart==3){
	while ( (c=getchar()) != EOF){
		// printf(" char : %c\n",c );
		ret = strchr(delimstr,c);
		if(ret!=NULL){
			str[strlen(str)] = delimiter;
			if(colsize-1 > 100){
				fprintf(stderr, "Max columns size exceeded %d\n",colsize );
				return 1;
			}
			colsize=0;
			if(rows<1){maxdel++;} //max cols depends on header size
		}else{
			str[strlen(str)] = c;
			colsize++;
			rowsize++;
		}
		if(c == '\n'){
			rows++;
			if(rowsize>10240){
				fprintf(stderr, "Max row size exceeded %d\n",rowsize );
				return 1;
			}
			rowsize = 0;
		}
	}
}

  LenofMainStr = strlen(str);
  // printf("%s\n",str); //main string print


	for(int i=firstfstart;i<argc;i++){ //functions are executed 1 by 1 they are stacked in argv and their count is argc every case in switch is decided by index valuefrom commands array variable
		// printf("%s\n",argv[i]);
		if(atoi(argv[i])==0){
			for(int j=0;j<cmdcnt;j++){
				cmp = strcmp(argv[i],commands[j]);
				if(cmp==0){
					switch (j) {

						case 0: //irow
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 ){
								arg1 = atoi(argv[i+1]);
								// printf("%s\n",argv[i]);
								// printf("arg1 %d\n",arg1 );
								if(arg1<=rows && arg1>0){
									irow(str,maxdel,arg1,LenofMainStr,newtable,delimiter);
									rows++;
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d -> '%d' given\n",argv[i],rows,arg1);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;
						break;

						case 1: //arow
						// printf("%s\n",argv[i]);
						arow(str,rows,maxdel,LenofMainStr,newtable,delimiter);
						rows++;
						memset(str,0,strlen(str));
						strcpy(str,newtable);
						LenofMainStr = strlen(str);
						memset(newtable,0,strlen(newtable));
						break;

						case 2://drow
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								// printf("arg1 %d\n",arg1 );
								if(arg1<=rows && arg1>0){
									drow(str,arg1,LenofMainStr,newtable);
									rows--;
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d -> '%d' given\n",argv[i],rows,arg1);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;
						break;

						case 3: //icol
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 ){
								arg1 = atoi(argv[i+1]);
								// printf("%s\n",argv[i]);
								// printf("arg1 %d\n",arg1 );
								if(arg1<=maxdel+1 && arg1>0){
									icol(str,rows,maxdel,arg1,LenofMainStr,newtable,delimiter);
									maxdel++;
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d -> '%d' given\n",argv[i],maxdel+1,arg1);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;
						break;

						case 4: //acol
						// printf("%s\n",argv[i]);
						acol(str,LenofMainStr,newtable,delimiter);
						maxdel++;
						memset(str,0,strlen(str));
						strcpy(str,newtable);
						LenofMainStr = strlen(str);
						memset(newtable,0,strlen(newtable));
						break;

						case 5://dcol
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 ){
								arg1 = atoi(argv[i+1]);
								// printf("%s\n",argv[i]);
								// printf("arg1 %d\n",arg1 );
								if(arg1<=maxdel+1 && arg1>0){
									dcol(str,arg1,maxdel,LenofMainStr,newtable,delimiter);
									maxdel--;
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d -> '%d' given\n",argv[i],maxdel+1,arg1);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;
						break;

						case 6://drows
						if(i>=argc-2){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 && atoi(argv[i+2])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								arg2 = atoi(argv[i+2]);
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=rows && arg1>0 && arg2<=rows && arg2>0 && arg2>arg1){
									drows(str,arg1,arg2,LenofMainStr,newtable);
									rows = rows - (arg2-arg1+1);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N,M<=%d & M>N-> N='%d',M='%d' given\n",argv[i],rows,arg1,arg2);return 1;}

							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;i++;
						break;

						case 7: //dcols
						if(i>=argc-2){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 && atoi(argv[i+2])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								arg2 = atoi(argv[i+2]);
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=maxdel+1 && arg1>0 && arg2<=maxdel+1 && arg2>0 && arg2>arg1){
									dcols(str,arg1,arg2,maxdel,LenofMainStr,newtable,delimiter);
									maxdel = maxdel - (arg2-arg1+1);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N,M<=%d & M>N-> N='%d',M='%d' given\n",argv[i],rows,arg1,arg2);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;i++;
						break;

						case 8: //cset
						// printf("%s\n",argv[i] );
						if(i>=argc-2){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 && atoi(argv[i+2])==0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								strcat(argSTR,argv[i+2]); //STR
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=maxdel+1 && arg1>0 && strlen(argSTR)>0 ){
									cset(str,arg1,argSTR,LenofMainStr,newtable,delimiter);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));
									memset(argSTR,0,strlen(argSTR));

								}else{fprintf(stderr, "Function '%s' requires N<=%d & string value --> '%d' & '%s' given\n",argv[i],maxdel+1,arg1,argSTR);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;i++;
						break;

						case 9: //tolower
						// printf("%s\n",argv[i] );
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=maxdel+1 && arg1>0 ){
									tolowerf(str,maxdel,arg1,LenofMainStr,newtable,delimiter);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d -> '%d' given\n",argv[i],maxdel+1,arg1);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;
						break;

						case 10: //toupper
						// printf("%s\n",argv[i] );
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=maxdel+1 && arg1>0 ){
									tupperf(str,maxdel,arg1,LenofMainStr,newtable,delimiter);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d -> '%d' given\n",argv[i],maxdel+1,arg1);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;
						break;

						case 11: //Round
						// printf("%s\n",argv[i] );
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=maxdel+1 && arg1>0 ){
									roundfunc(str,maxdel,arg1,LenofMainStr,newtable,delimiter);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d -> '%d' given\n",argv[i],maxdel+1,arg1);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;
						break;

						case 12: //Intfunc
						// printf("%s\n",argv[i] );
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=maxdel+1 && arg1>0){
									intfunc(str,maxdel,arg1,LenofMainStr,newtable,delimiter);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d -> '%d' given\n",argv[i],maxdel+1,arg1);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;
						break;

						case 13: //Copy
						// printf("%s\n",argv[i] );
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 && atoi(argv[i+2])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								arg2 = atoi(argv[i+2]);
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=maxdel+1 && arg1>0  && arg2<=maxdel+1 && arg2>0 && arg1!=arg2){
									copy(str,maxdel,arg1,arg2,LenofMainStr,newtable,delimiter);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d & string value --> '%d' & '%s' given\n",argv[i],maxdel+1,arg1,argSTR);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;i++;
						break;

						case 14: //Swap
						// printf("%s\n",argv[i] );
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 && atoi(argv[i+2])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								arg2 = atoi(argv[i+2]);
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=maxdel+1 && arg1>0  && arg2<=maxdel+1 && arg2>0 && arg1!=arg2){
									swap(str,maxdel,arg1,arg2,LenofMainStr,newtable,delimiter);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N,M<=%d N!=M -> '%d' & '%d' given\n",argv[i],maxdel+1,arg1,arg2);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;i++;
						break;

						case 15: //move
						// printf("%s\n",argv[i] );
						if(i>=argc-1){
							fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
							return 1;
						}else{
							if(atoi(argv[i+1])>0 && atoi(argv[i+2])>0 ){
								// printf("%s\n",argv[i]);
								arg1 = atoi(argv[i+1]);
								arg2 = atoi(argv[i+2]);
								// printf("arg1 %d\n",arg1 );
								// printf("arg2 %d\n",arg2 );
								if(arg1<=maxdel+1 && arg1>0  && arg2<=maxdel+1 && arg2>0 && arg1!=arg2){
									move(str,maxdel,arg1,arg2,LenofMainStr,newtable,delimiter);
									memset(str,0,strlen(str));
									strcpy(str,newtable);
									LenofMainStr = strlen(str);
									memset(newtable,0,strlen(newtable));

								}else{fprintf(stderr, "Function '%s' requires N<=%d & string value --> '%d' & '%d' given\n",argv[i],maxdel+1,arg1,arg2);return 1;}
							}else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						}
						i++;i++;
						break;

						// case 16: //rows
						// printf("%s\n",argv[i] );
						// if(i>=argc-1){
						//   fprintf(stderr, "Invalid arguments for '%s' given.\n",argv[i] );
						//   return 1;
						// }else{
						//   if(  (atoi(argv[i+1])>0 || atoi(argv[i+1])==0) &&  (atoi(argv[i+2])>0 || atoi(argv[i+2])==0)  ){
						//     // printf("%s\n",argv[i]);
						//     arg1 = atoi(argv[i+1]);
						// 		arg2 = atoi(argv[i+2]);
						//
						// 		if(arg1==0 && arg2==0){
						// 			if( (char)*argv[i+1] == '-' &&  (char)*argv[i+2] == '-'){
						// 				arg2=rows;
						// 				arg1=0;
						// 			}else{
						// 				fprintf(stderr, "Invalid argument for %s\n",argv[i] );
						// 				return 1;
						// 			}
						// 		}else if(arg1>0 && arg2==0){
						// 			if( (char)*argv[i+2] == '-'){
						// 				arg2 = rows;
						// 				arg1 = atoi(argv[i+1]);
						// 			}else{
						// 				fprintf(stderr, "Invalid argument for %s\n",argv[i] );
						// 				return 1;
						// 			}
						// 		}else if(arg1>0 && arg2>0){
						// 			arg1 = atoi(argv[i+1]);
						// 			arg2 = atoi(argv[i+2]);
						//
						// 		}else{
						// 			fprintf(stderr, "Invalid argument for %s\n",argv[i] );
						// 			return 1;
						//
						// 		}
						//
						//     printf("arg1 %d\n",arg1 );
						//     printf("arg2 %d\n",arg2 );
						//
						//     if(arg1<=rows && arg1>0  && arg2<=rows && arg2>0 && arg1!=arg2){
						//       rowsfunc(str,rows,arg1,arg2,LenofMainStr,newtable,delimiter);
						//       memset(str,0,strlen(str));
						//       strcpy(str,newtable);
						//       LenofMainStr = strlen(str);
						//       memset(newtable,0,strlen(newtable));
						//
						//     }else{fprintf(stderr, "Function '%s' requires N,M<=%d N!=M -> '%d' & '%d' given\n",argv[i],maxdel+1,arg1,arg2);return 1;}
						//   }else{fprintf(stderr, "Invalid argument for '%s'\n",argv[i]);return 1;}
						// }
						// i++;i++;
						// break;

					}
				break;
			} else if(j==cmdcnt-1 && i==argc-1 ){fprintf(stderr, "Unknown command '%s'\n",argv[i]);return 1;}
		}
	}else if(atoi(argv[i])>0){fprintf(stderr, "Unknown command '%s'\n",argv[i]);return 1;}
}

// printf("maxdel %d\n",maxdel );
// printf("rows %d\n",rows );
printf("%s",str );

	return 0;
}
