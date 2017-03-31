#include <stdio.h>

int main(int argc,char** argv)
{
        int c = atoi(argv[1]);
        int s = atoi(argv[3]);
        int inner = atoi(argv[4]);
        int interleave = atoi(argv[2]);
        int i,j;
        for (i = s; i < c; i+=interleave)                                                                                            
                for (j = 0; j < inner; j++)                                                                                          
                        if (j+1 == inner && i+interleave >= c)                                                                       
                                printf("%i",i+j);                                                                                    
                        else                                                                                                         
                                printf("%i,",i+j);                                                                                   
        return 0;                                                                                                                    
} 
