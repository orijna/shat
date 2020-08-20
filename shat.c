#include <stdio.h>
#include <string.h>

#define MAXCHAR 1000
int main( int argc, char *argv[] ) {
	FILE *fp;
	char str[MAXCHAR];
	char* filename = argv[1];
	char* linething = "";
	int linenbr = 0;		
	if (argc > 2){
		linething = argv[2];
	}

	fp = fopen(filename, "r");
	if (fp == NULL){
		printf("Ye shant finna open %s bitch",filename);
		return 1;
	}
	printf("Here lay thine file, thot\n");
	while (fgets(str, MAXCHAR, fp) != NULL){
		
		if (!strcmp(linething, "-t")){
			if (linenbr >= 10 && linenbr < 100){
				printf("%d  | ", linenbr);
			}
			else if (linenbr >= 100){
				printf("%d | ", linenbr);
			}
			else{
				printf("%d   | ", linenbr);
			}
		}
		printf("%s", str);
		linenbr++;
	}
	fclose(fp);
	return 0;
}
