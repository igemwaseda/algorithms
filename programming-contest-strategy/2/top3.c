#include <stdio.h>

int main()
{
  int scores[10],top_index;
  for ( int i = 0; i < 10; i++ ) {
    scanf("%d",&scores[i]);
  }

  for ( int i = 0; i < 3; i++ ) {
    top_index = 0;
    for ( int j = 0; j < 10; j++){
      if ( scores[top_index] < scores[j] )
        top_index = j;
    }
    printf("%d: %d\n",i,scores[top_index]);
    scores[top_index] = -1;
  }

  return 0;
}
