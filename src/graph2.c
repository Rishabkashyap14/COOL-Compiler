/* interface for drawing */
#define lmax 200
#define cmax 200
char graph[lmax][cmax]; /* array for ASCII-Graphic */
int graphNumber = 0;

void graphTest (int l, int c)
{
	int ok;
	ok = 1;
	if (l < 0) 
		ok = 0;
	if (l >= lmax) 
		ok = 0;
	if (c < 0) 
		ok = 0;
	if (c >= cmax) 
		ok = 0;
	if (ok) 
		return;
	printf ("\n+++error: l=%d, c=%d not in drawing rectangle 0, 0 ...%d, %d",l, c, lmax, cmax);
	exit (1);
}

void graphInit (void) 
{
	int i, j;
	for (i = 0; i < lmax; i++) 
	{
		for (j = 0; j < cmax; j++) 
		{
			graph[i][j] = ' ';
		}
	}
}

void graphFinish() 
{
	int i, j;
	for (i = 0; i < lmax; i++) 
	{
		for (j = cmax-1; j > 0 && graph[i][j] == ' '; j--);
		graph[i][cmax-1] = 0;
		if (j < cmax-1) graph[i][j+1] = 0;
		if (graph[i][j] == ' ') graph[i][j] = 0;
	}
	for (i = lmax-1; i > 0 && graph[i][0] == 0; i--);
	printf ("\n\nGraph %d:\n", graphNumber++);
	for (j = 0; j <= i; j++) printf ("\n%s", graph[j]);
	printf("\n");
}

void graphBox (char *s, int *w, int *h) 
{
	*w = strlen (s) + del;
	*h = 1;
}

void graphDrawBox (char *s, int c, int l) 
{
	int i;
	graphTest (l, c+strlen(s)-1+del);
	for (i = 0; i < strlen (s); i++) 
	{
		graph[l][c+i+del] = s[i];
	}
}

void graphDrawArrow (int c1,int l1, int c2, int l2) 
{
	int m;
	graphTest (l1, c1);
	graphTest (l2, c2);
	m = (l1 + l2) / 2;
	while (l1 != m) {
		graph[l1][c1] = '|';
		if (l1 < l2) 
			l1++; 
		else 
			l1--;
	}
	while (c1 != c2) 
	{
		graph[l1][c1] = '-';
		if (l1 < l2) 
			l1++; 
		else 
			l1--;
	}
	while (l1 != l2) 
	{
		graph[l1][c1] = '|';
		if (l1 < l2) 
			l1++; 
		else 
			l1--;
	}
	graph[l1][c1] = '|';
}		
