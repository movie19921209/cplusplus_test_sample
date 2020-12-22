#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>

int
main(int argc, char **argv)
{
  int c;

  while (1) {
	 //第四个参数是长参数对应的返回值
   static struct option long_options[] = {
		   {"add",     required_argument, 0,'a' },
 		   {"append",  no_argument,       0,'b' },
		   {"delete",  required_argument, 0,'d' },
 		   {"verbose", no_argument,       0, 'v' },
 		   {"create",  required_argument, 0, 'c' },
		   {"file",    required_argument, 0, 'f' },
 		   {0,         0,                 0, 0 }
	   };
   
	 //第三个参数如果在长参数下，应该是可以省略，置为空字符串
	 //如果有值，会在匹配不到长参数时，匹配设置的短参数值
	 c = getopt_long(argc, argv, "",
	 				long_options, NULL);

   if (c == -1)
		break;

   switch (c) {
	   case 'a':
		   printf("option a with value '%s'\n", optarg);
		   break;

	   case 'b':
		   printf("option b with value \n");
		   break;
																																																																						 		
	   case 'c':
		   printf("option c with value '%s'\n", optarg);
		 break;

 	   case 'd':
 		   printf("option d with value '%s'\n", optarg);
   	   break;

 	   case 'v':
 		   printf("option v with value\n");
   	   break;

 	   case 'f':
 		   printf("option f with value '%s'\n", optarg);
   	   break;

			default:
			 printf("?? getopt returned character code 0%o ??\n", c);
		  }
		}

		printf("ending ......\n");
	
}

