#include <stdio.h>

int main()
{
  char S[100000],goal[10000];
  int num = 0;
  int zero_count = 0,one_count = 0;
  scanf("%s",S);

  for ( num; S[num] != '\0'; num++ );
  if ( num == '1' ) {
    printf("%d",0);
    return 0;
  } 
  for ( int i = 0; i < num; i++ ) {
    if ( ( i % 2 == 0 && S[i] != '0' ) || ( i % 2 == 1 && S[i] != '1' ) )
      zero_count++;
    if ( ( i % 2 == 0 && S[i] != '1' ) || ( i % 2 == 1 && S[i] != '0' ) )
      one_count++;
  }
  if ( zero_count > one_count ) {
    printf("%d\n",one_count);
  } else {
    printf("%d\n",zero_count);
  }
  return 0;
}
