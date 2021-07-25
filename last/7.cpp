#include <stdio.h>
#include <gmp.h>
using namespace std;
int main()
{
   int i,j;
   mpz_t t;
    mpz_t a[101][101];
  	for (i = 0; i < 101; i++)
		for (j = 0; j < 101; j++)
			mpz_init(a[i][j]);
    mpz_init(t);
	mpz_set_ui(a[0][0], 0);
	for (i = 0; i < 101; i++)
	{
		mpz_set_ui(a[i][0],1);
		mpz_set_ui(a[0][i],1);
	}
	for (int j = 1; j <= 100; j++)
		for (int i = 1; i <= 100; i++)
        {
			mpz_mul_ui(a[i][j],a[i - 1][j],2);
            if (i == j + 1)
				mpz_sub_ui(a[i][j],a[i][j],1);
			if(i>j+1)
				mpz_sub(a[i][j],a[i][j],a[i-j-2][j]);
		}
	
	while ( scanf("%d %d", &i, &j)!= EOF) {
		mpz_sub(t, a[i][i], a[i][j - 1]);
		gmp_printf("%Zd\n",t);	}
	return 0;
}
