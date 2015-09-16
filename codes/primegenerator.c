#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int t;
int next_min, next_max, all_processed, abs_min, abs_max;
struct cases{
	int min;
	int max;
	int processed;
	struct cases *next;
};

struct cases *head, *tail, *ptr;

struct primes{
	int val;
	struct primes *next;
};

struct primes *head1, *tail1, *ptr1;

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
	return;
}

void Enqueue_Input(int min, int max){
	if(head==NULL){
		head = (struct cases *) malloc (sizeof(struct cases));
		tail = head;
	} else {
		tail->next = (struct cases *) malloc (sizeof(struct cases));
		tail = tail->next;
	}
	tail->min = min;
	tail->max = max;
	tail->processed = 0;
	tail->next = NULL;
	return;
}

void Enqueue_Prime(int val){
	if(head1==NULL){
		head1 = (struct primes *) malloc (sizeof(struct primes));
		tail1 = head1;
	} else {
		tail1->next = (struct primes *) malloc (sizeof(struct primes));
		tail1 = tail1->next;
	}
	tail1->val = val;
	tail1->next = NULL;
	return;
}

void FindNextMinMax(){
	all_processed = 1;
	ptr = head;
	next_min = abs_max; next_max = abs_min;
	while(ptr!=NULL){
		if(!ptr->processed) if(ptr->min < next_min){		//Just finding next min here..
			next_min = ptr->min;
			next_max = ptr->max;
			all_processed = 0;
		}
		ptr = ptr->next;
	}
	ptr = head;
	while(ptr!=NULL){						//Checking for overlapping intervals.
		if(!ptr->processed){
			if(!(next_max <= ptr->min)){			//If Overlaps, include the larger interval.
				if(next_max < ptr->max) next_max = ptr->max;
				ptr->processed = 1;			//Mark processed.
			}
		}
		ptr = ptr->next;
	}
	return;
}

void FindAllPrimes(){
	//printf("\nFinding primes b/w %d & %d\n", next_min, next_max);
	int i = next_min, j, prime;
	if(i<=2) {Enqueue_Prime(2);next_min=3;}
	if(i%2==0) next_min++;
	for(i=next_min;i<=next_max;i=i+2){	//Check if i is prime.
		prime = 1;
		for(j=2;j<=sqrt(i);j++){
			if(i%j==0) {prime = 0;break;}
		}
		if(prime) Enqueue_Prime(i);
		//printf("%d is prime: %d\n", i, prime);
	}
	return;
}

void PrintAllPrimes(int min, int max){
	ptr1 = head1;
	while(ptr1!=NULL){
		if(ptr1->val > max) break;
		if(ptr1->val >= min) printf("%d\n", ptr1->val);
		ptr1 = ptr1->next;
	}
	printf("\n");
}

int main(){
	all_processed = 0;
	printf("Enter the value of t: ");
	scanf("%d", &t);
	printf("Enter %d test cases: ", t);
	int i=0,j,k;
	while(i<t){
		scanf("%d %d", &j, &k);
		if(j>k) swap(&j, &k);			//assuring j is the smaller number.
		if(i==0){ abs_min = j; abs_max = k; }
		if(j<abs_min){abs_min = j;}
		if(k>abs_max){abs_max = k;}
		Enqueue_Input(j,k);
		i++;
	}
	abs_min--;abs_max++;
	FindNextMinMax();
	while(!all_processed){
		FindAllPrimes();
		FindNextMinMax();
	}
	ptr = head;ptr1 = head1;
	/*while(ptr1!=NULL){
		printf("%d->", ptr1->val);
		ptr1 = ptr1->next;
	}
	printf("NULL\n");*/
	while(ptr!=NULL){
		PrintAllPrimes(ptr->min, ptr->max);
		ptr = ptr->next;
	}
	return 0;
}
