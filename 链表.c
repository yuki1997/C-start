#define N 10
typedef struct list
{
	int data;
	struct list *next;
} SLIST;

main( )
{
	SLIST *head,*p,*q;
	int i;
	int a[10] = {1,3,5,9,10,12,14,17,18,22};
	head = p = (SLIST *)malloc(sizeof(SLIST));
	for(i = 0; i < N; i++){
		q = (SLIST *)malloc(sizeof(SLIST));
		q->data=a[i];
		p->next=q;
		p=q;
	} 
	p->next=0;
} 
void insert(SLIST *h,int x)
{
	int i;
	SLIST *p,*q,*t;
	p = h;
	p = (SLIST *)malloc(sizeof(SLIST));
	q->data = x;
	
	while(p != 0){
		if(x > p->data){
			t = p;
			p = p->next;
		}
		else 
			break;
	}
	q->next = p;
	t->next = q;
 } 
