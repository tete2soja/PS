#include "generate.h"

int generateFile(int nbMult) {
	FILE* fp;
	int x, y, z;
	int i;

	srand(time(NULL));

	remove("matrice.txt");
	fp = fopen("matrice.txt","a");

	fprintf(fp, "%d\n", nbMult);

	for (i = 0; i < nbMult; i++)
	{
		x = (rand()%20);
		y = (rand()%20);
		z = (rand()%20);

		fprintf(fp, "%d %d\n", x, y);
		fprintf(fp, "%d %d\n", y, z);

		generateMatrice(fp, x, y);
		generateMatrice(fp, y, z);
	}
	fclose(fp);
	return 0;
}

void generateMatrice(FILE* fp, int x, int y) {
	int i, j;
	double tmp;

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			tmp = 10.0*(0.5-((double)rand())/((double)RAND_MAX));
			fprintf(fp, "%.1f ", tmp);
		}
		fprintf(fp, "\n");
	}
}