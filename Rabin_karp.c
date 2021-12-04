#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define d 256

void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0;
	int t = 0; 
	int h = 1;
	int val = 0;

	for (i = 0; i < M-1; i++)
		h = (h*d)%q;

	for (i = 0; i < M; i++)
	{
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}
	for (i = 0; i <= N - M; i++)
    {

		if ( p == t )
		{
			for (j = 0; j < M; j++)
			{
				if (txt[i+j] != pat[j])
					break;
			}

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
			if (j == M){
				printf("String found in position %d \n", (i+1));
				val = 1;
			}
		}

		
		if ( i < N-M )
		{
			t = (d*(t - txt[i]*h) + txt[i+M])%q;

		
			if (t< 0)
			t = (t + q);
		}
	}
	if(val == 0)
	    printf("String not found");
}

/* Driver Code */
int main()
{
    char txt[256] , pat[256];
    int txtlen , patlen;
    scanf("%d %s",&txtlen,txt);
    scanf("%d %s",&patlen,pat);
	
	// A prime number
	int q = 101;
	
	// function call
	search(pat, txt, q);
	return 0;
}
