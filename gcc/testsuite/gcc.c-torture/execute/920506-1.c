void abort (void);
void exit (int);
int l[]={0,1};
int main(void){int*p=l;switch(*p++){case 0:exit(0);case 1:break;case 2:break;case 3:case 4:break;}abort();}
