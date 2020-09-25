#include <stdio.h>
#include <string.h>
#include <algorithm>

struct data{
	char namaProduk[30];
	int jumlahProduk;
}supermarket[100];

void generateData(){
	strcpy(supermarket[0].namaProduk,"Teh Semangka");
	supermarket[0].jumlahProduk = 30;
	
	strcpy(supermarket[1].namaProduk,"Teh Jeruk");
	supermarket[1].jumlahProduk = 10;
	
	strcpy(supermarket[2].namaProduk,"Susu Nangka");
	supermarket[2].jumlahProduk = 1;
	
	strcpy(supermarket[3].namaProduk,"Kopi Pisang");
	supermarket[3].jumlahProduk = 3;
}

int countData = 4;

void showData(){
	int i;
	for(i=0;i<countData;i++){
		if(supermarket[i].jumlahProduk >= 10){	
			printf("|%-30s|%-3s%.2d|\n", supermarket[i].namaProduk, " ", supermarket[i].jumlahProduk);
		}
		else{
			printf("|%-30s|%-3s %d|\n", supermarket[i].namaProduk, " ", supermarket[i].jumlahProduk);
		}
	}
}

void swap(data *a, data *b){
	struct data c;
	c = *a;
	*a = *b;
	*b = c;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------Sorting---------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------


void bubbleSortName(){
	int i, j, n;
	
	n=countData;
	
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(strcmp(supermarket[j].namaProduk,supermarket[j-1].namaProduk) < 0){
				swap(&supermarket[j], &supermarket[j-1]);
			}
		}
	}
}

void bubbleSortQty(){
	int i, j, n;
	
	n=countData;
	
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(supermarket[j].jumlahProduk<supermarket[j-1].jumlahProduk){
				swap(&supermarket[j], &supermarket[j-1]);
			}
		}
	}
}

void selectionSortName(){
	int i, j, low;
	for(i=0;i<countData-1;i++){
		low = i;
		for(j=i+1;j<countData;j++){
			if(strcmp(supermarket[j].namaProduk,supermarket[j-1].namaProduk) < 0){
				low = j;
			}
		}
		if(low>i){
			swap(&supermarket[i], &supermarket[low]);
		}
	}
}

void selectionSortQty(){
	int i, j, low;
	for(i=0;i<countData-1;i++){
		low = i;
		for(j=i+1;j<countData;j++){
			if(supermarket[j].jumlahProduk < supermarket[j-1].jumlahProduk){
				low = j;
			}
		}
		if(low>i){
			swap(&supermarket[i], &supermarket[low]);
		}
	}
}

void insertionSortName(){
	int i, j;
	char temp[100];
	for(i=1;i<countData;i++){
		strcpy(temp, supermarket[i].namaProduk);
		for(j=i-1;j>=0; j--){
			if(strcmp(supermarket[j].namaProduk, temp) > 0){
				swap(&supermarket[j+1], &supermarket[j]);
			}
		}
	}
}

void insertionSortQty(){
	int i, j, temp;
	for(i=1;i<countData;i++){
		temp=supermarket[i].jumlahProduk;
		for(j=i-1;j>=0 && temp < supermarket[j].jumlahProduk; j--){
			swap(&supermarket[j+1], &supermarket[j]);
		}
	}
}

void quickSortName(int L, int R){
	int i, j;
	if(L < R){
		i=L;
		j=R+1;
		do{
			do{
				i++;
			}while(strcmp(supermarket[i].namaProduk, supermarket[L].namaProduk) < 0); // >
			do{
				j--;
			}while(strcmp(supermarket[j].namaProduk, supermarket[L].namaProduk) > 0); // <
			if(i<j){
				swap(&supermarket[i], &supermarket[j]);						   // descending
			}
		}while(i<=j);
		swap(&supermarket[L], &supermarket[j]);
		quickSortName(L, j-1);
		quickSortName(j+1, R);
	}
}

void quickSortQty(int L, int R){
	int i, j;
	if(L < R){
		i=L;
		j=R+1;
		do{
			do{
				i++;
			}while(supermarket[i].jumlahProduk < supermarket[L].jumlahProduk); // >
			do{
				j--;
			}while(supermarket[j].jumlahProduk > supermarket[L].jumlahProduk); // <
			if(i<j){
				swap(&supermarket[i], &supermarket[j]);						   // descending
			}
		}while(i<=j);
		swap(&supermarket[L], &supermarket[j]);
		quickSortQty(L, j-1);
		quickSortQty(j+1, R);
	}
}

void merge(){
/*
void merge(int L, int m1, int m2, int R){
	int Lidx = L;
	int Ridx = m2;
	int Cidx = L;
	int i;
	
	struct Product() temparr[countData];

	while(Lidx<=m1 && Ridx<=R){
		if(supermarket[Lidx].jumlahProduk >= supermarket[Ridx].jumlahProduk){
			temparr[Cidx++] = supermarket[Lidx++];
		}else{
			temparr[Cidx++] = supermarket[Ridx++];
		}
	}
	if (Lidx == m2){
		while(Ridx <= R){
			temparr[Cidx++] = supermarket[Ridx++];
		}else{
			temparr[Cidx++] = supermarket[Lidx++];
		}
	}
	for(i=L; i<=R; i++){
		supermarket[i] = temparr[i];
	}
}

void mergeSort(int low, int high){
	int m1, m2;
	if((high-low)>=1){
		m1=(low+high)/2;
		m2=m1+1;
		mergeSort(low,m1);
		mergeSort(m2,high);
		merge( low, m1, m2, high);
	}
}*/
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------Searching---------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

int linearSearch(char namaItem[]){
	int valid=-1;
	for(int i=0;i<countData;i++){
		if(strcmp(namaItem, supermarket[i].namaProduk) == 0){
			valid=i;
			break;
		}
	}
	if(valid == -1){
		return -1;
	}
	return valid;
}

int binarySearch(char namaItem[]){
	int low, high=countData;
	
	do{
		int mid = (low+high)/2;
		if(strcmp(supermarket[mid].namaProduk, namaItem) < 0){
			high = mid;	
		}else if(strcmp(supermarket[mid].namaProduk, namaItem) > 0){
			low = mid;
		}else{
			return mid;
		}
	}while(low <= high);
	return -1;
	
}

int interpolSearch(){
	
}

int main(){
	
	printf("%-47sSorting%-40s\n", " ", " ");
	for(int i=0;i<120;i++){
		printf("_");
	}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	printf("\n");
	printf("%-45sBubble Sort%-40s\n", " ", " ");
	
	generateData();
	printf("Sort By Name:\n");
	bubbleSortName();
	showData();
	
	printf("\n");
	generateData();
	printf("Sort By Quantity:\n");
	bubbleSortQty();
	showData();

	for(int i=0;i<120;i++){
		printf("_");
	}
	
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	printf("\n");
	printf("%-45sSelection Sort%-40s\n", " ", " ");
	
	generateData();
	printf("Sort By Name:\n");
	selectionSortName();
	showData();
	
	printf("\n");
	generateData();
	printf("Sort By Quantity:\n");
	selectionSortQty();
	showData();

	for(int i=0;i<120;i++){
		printf("_");
	}
	
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	printf("\n");
	printf("%-45sInsertion Sort%-40s\n", " ", " ");
	
	printf("Sort By Name:\n");
	generateData();
	insertionSortName();
	showData();
	
	printf("\n");
	generateData();
	printf("Sort By Quantity:\n");
	insertionSortQty();
	showData();
	
	for(int i=0;i<120;i++){
		printf("_");
	}
	
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	printf("\n");
	printf("%-45sQuick Sort%-40s\n", " ", " ");
	
	generateData();
	printf("Sort By Name:\n");
	quickSortName(0, 3);
	//quickSortName(batas kiri, batas kanan);
	showData();
	
	printf("\n");
	generateData();
	printf("Sort By Quantity:\n");
	quickSortQty(0, 3);
	//quickSortName(batas kiri, batas kanan);
	showData();

	for(int i=0;i<120;i++){
		printf("_");
	}
	
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	printf("\n");
	printf("%-45sMerge Sort%-40s\n", " ", " ");

	printf("\n");
	generateData();
	printf("Sort By Quantity:\n");
	insertionSortQty();
	showData();
	
	for(int i=0;i<120;i++){
		printf("_");
	}
	printf("%-47sSearching%-40s\n", " ", " ");
	for(int i=0;i<120;i++){
		printf("_");
	}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

	int result;
	
	printf("\n");
	printf("%-45sLinear Search%-40s\n", " ", " ");
	
	generateData();
	for(int i=0;i<countData;i++){
		result = linearSearch(supermarket[i].namaProduk);
		(result == -1 )? printf("Not Found\n") : printf("Found at %d\n", linearSearch(supermarket[i].namaProduk));
	}

	for(int i=0;i<120;i++){
		printf("_");
	}
	
	printf("\n");
	printf("%-45sBinary Search%-40s\n", " ", " ");
	
	generateData();
	for(int i=0;i<countData;i++){
		result = binarySearch(supermarket[i].namaProduk);
		(result == -1 )? printf("Not Found\n") : printf("Found at %d\n", binarySearch(supermarket[i].namaProduk));
	}
	
	for(int i=0;i<120;i++){
		printf("_");
	}
	
	printf("\n");
	printf("%-45sInterpol Search%-40s\n", " ", " ");
	
	generateData();
	for(int i=0;i<countData;i++){
		
	}
	
return 0;
}
