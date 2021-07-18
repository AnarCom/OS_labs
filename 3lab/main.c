#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void printIds ();
void tryToOpen (char *name);

int main (int argc, char *argv[])
{
  if(argc != 2)
   {
     perror("problems with args");
   }
  printIds ();
  tryToOpen(argv[1]);
  seteuid(getuid());
  printIds();
  tryToOpen(argv[1]);
 return 0;
}

void printIds ()
{
  printf ("Read user ID:%d\n", getuid ());
  printf ("Effective use ID:%d\n", geteuid ());
}

void tryToOpen (char *name)
{
  FILE *file = fopen (name, "r");
  if (file == NULL)
    perror ("CANNOT OPEN FILE");
  else
    {
      printf ("opened\n");
      if (fclose (file) == EOF)
	{
	perror ("cannot close file");
	}
    }
}
