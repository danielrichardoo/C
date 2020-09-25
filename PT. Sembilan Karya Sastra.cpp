#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *file;

struct data{
	int nopendaftar;
	char nama[26], telpon[13];
	char gender[10];
	int tanggal, bulan, tahun, umur;
	
}regis[100];

int pendaftaran(){
A:
	
	int i=0, j, count, temp, tanggal, bulan, tahun, umur;
	char gendercheck;
	char nama[26]={}, notelp[13]={};
	char gender[10]={};
	bool checknama = false;
	bool checkgender = false;
	bool checklahir = false;
	bool checktelp = false;
	bool checkumur = false;

	system("cls");

	printf("Created by : Daniel Richardo\n");
	printf("2201744531\n");	

		
	printf("\t\t\t\t======================================\n");
	printf("\t\t\t\tPendaftaran PT. Sembilan Karya Sastra\n");
	printf("\t\t\t\t========== MENU PENDAFTARAN ==========\n\n");
		
	printf("\t\tKetik '0' jika ingin kembali ke menu.");
	
	for(i=0;i<5;i++){
		printf("\n");
	}
	
	do{
		printf("\tInput Nama [Alphabet]: ");
		scanf("%[^\n]", &nama);
		getchar();
		
		if(nama[0]=='0'){
			return 0;
		}
		
		for(i=0;i<strlen(nama);i++){
			if(isalpha(nama[i]) == 0 && nama[i]!=' '){
				printf("\tNama tidak valid!\n\t");
				getchar();
				goto A;
			}
			if(i==strlen(nama)-1){
				checknama = true;
			}
		}
	}while(checknama == false);
	
	do{
		printf("\tInput Gender [L = 1/P = 2]: ");
		scanf("%c", &gendercheck);
		getchar();
		
		switch(gendercheck){
			case '1' : gender[0] = 'L'; checkgender = true; break;
			case '2' : gender[0] = 'P'; checkgender = true; break;
			default : printf("\tGender tidak valid!\n"); getchar(); goto A;
		}
		
	}while(checkgender == false);

	do{
		printf("\tInput Tanggal Lahir [dd/mm/yyyy]: ");
		scanf("%d/%d/%d", &tanggal, &bulan, &tahun);
		getchar();
		
		if(bulan>12 || tahun>2018){
			printf("\tTanggal lahir tidak valid!\n");
			getchar();
			goto A;
		}
		else if(bulan == 2){
			if(tahun%4!=0 && tanggal>28){
				printf("\tTanggal lahir tidak valid!\n");
				getchar();
				goto A;
			}
			else if(tahun%4==0 && tanggal>29){
				printf("\tTanggal lahir tidak valid!\n");
				getchar();
				goto A;
			}
		}
		else if((bulan == 1 || bulan == 3 || bulan == 5 || bulan == 7 || bulan == 8 || bulan == 10 || bulan == 12) && tanggal>31){
				printf("\tTanggal lahir tidak valid!\n");
				getchar();
				goto A;
		}
		else if((bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) && tanggal > 30){
				printf("\tTanggal lahir tidak valid!\n");
				getchar();
				goto A;
		}
		
		checklahir = true;
	}while(checklahir == false);
	
	do{
		printf("\n\t*Jika tidak ada, ketik \"-\" tanpa kutip*\n");
		printf("\tInput Nomor Handphone [Digit]: ");
		
		scanf("%[^\n]", &notelp);
		getchar();
		count=0;
		i=0;
		while(notelp[i] != '\0'){
			count++;
			i++;
		}
		
		if(notelp[0] == '-'){
			checktelp = true;
		}
		else if(count > 13 || count < 10){
			printf("\tNomor anda tidak valid!!!\n");
			getchar();
			goto A;
		}
		else{
			i=0;
			do{
				if(isdigit(notelp[i]) == 0){
					printf("\tNomor anda tidak valid!\n");
					getchar();
					goto A;
				}
				i++;
			}while(notelp[i]!='\0');
		}
	
		checktelp = true;
	}while(checktelp == false);

	umur = 2018-tahun;
	if(umur < 18){
		printf("\tMaaf umur anda tidak mencukupi untuk mendaftarkan diri.\n");
		getchar();
		goto A;
	}
	else{
		checkumur=true;
	}
	
	
	for(i=0; ;i++){
		if(strcmp(regis[i].nama, "") == 0){
			
			strcpy(regis[i].nama, nama);
			strcpy(regis[i].gender, gender);
			regis[i].tanggal = tanggal;
			regis[i].bulan = bulan;
			regis[i].tahun = tahun;
			regis[i].umur = umur;
			strcpy(regis[i].telpon, notelp);
			regis[i].nopendaftar = i+1;
			
			break;
		}
	}
	
	printf("\n\tAnda telah terdaftar!\n");
	getchar();
	
return 0;
}

int list(){
	int i=0, flag=0;
	system("cls");
	
	printf("Created by : Daniel Richardo\n");
	printf("2201744531\n");
	
	printf("\t\t\t\t======================================\n");
	printf("\t\t\t\tPendaftaran PT. Sembilan Karya Sastra\n");
	printf("\t\t\t\t=========== LIST PENDAFTAR ===========\n\n");
	
	for(i=0;i<5;i++){
		printf("\n");
	}
	
	printf("\t______________________________________________________________________________\n");
	printf("\t|NO ||           NAMA          ||Gender||Tanggal Lahir|| Umur ||Nomor Telpon |\n");
	printf("\t|---||-------------------------||------||-------------||------||-------------|\n");
	
	for(i=0;i<100;i++){
		if(i==99){
			
			printf("\t|___||_________________________||______||_____________||______||_____________|\n");
			if(flag==0){
				printf("\n\tBelum ada pendaftar.\n");
			}
			
//			break;
		}
		if(strcmp(regis[i].telpon, "-") == 0 && strcmp(regis[i].nama, "") != 0){
			printf("\t|%.2d.||%-25s||  %s   ||  %.2d/%.2d/%.4d ||%.2dthn ||      -      |\n", regis[i].nopendaftar, regis[i].nama, regis[i].gender, regis[i].tanggal, regis[i].bulan, regis[i].tahun, regis[i].umur, regis[i].telpon);
			flag=1;
		}
		else if(strcmp(regis[i].nama, "") != 0){
			printf("\t|%.2d.||%-25s||  %s   ||  %.2d/%.2d/%.4d ||%.2dthn ||%-13s|\n",         regis[i].nopendaftar, regis[i].nama, regis[i].gender, regis[i].tanggal, regis[i].bulan, regis[i].tahun, regis[i].umur, regis[i].telpon);
			flag=1;
		}
		else if(regis[i].nopendaftar == -1){
			printf("\t|%.2d.||Telah Mengundurkan diri                                                |\n", i+1);
		}
	}
	printf("\n\tTekan 'Enter' untuk kembali ke Menu.");
	getchar();
	
return 0;
}

int pengunduran(){
	
	int i, nomor;
	system("cls");
	
	printf("Created by : Daniel Richardo\n");
	printf("2201744531\n");
	
	
	printf("\t\t\t\t======================================\n");
	printf("\t\t\t\tPendaftaran PT. Sembilan Karya Sastra\n");
	printf("\t\t\t\t======= MENU PENGUNDURAN DIRI ========\n\n");
	
	printf("\t\tKetik '0' jika ingin kembali ke menu.");
	
	for(i=0;i<5;i++){
		printf("\n");
	}
	
	printf("\tMasukkan nomor pendaftaran anda: ");
	scanf("%d", &nomor);
	getchar();
	
	if(nomor == 0){
		return 0;
	}
	
		if(strcmp(regis[nomor-1].nama, "") == 0){
			printf("\tNomor pendaftaran anda tidak valid!\n");
			getchar();
			return 0;
		}
		else if(strcmp(regis[nomor-1].nama, "") != 0){
			strcpy(regis[nomor-1].nama, "");
			strcpy(regis[nomor-1].gender, "");
			regis[nomor-1].tanggal = 0;
			regis[nomor-1].bulan = 0;
			regis[nomor-1].tahun = 0;
			regis[nomor-1].umur = 0;
			regis[nomor-1].nopendaftar = -1;
			strcpy(regis[nomor-1].telpon, "");
		}
	
	printf("\n\tAnda telah mengundurkan diri!\n"); 
	getchar();
	
return 0;
}

int update(){
A:
	int i=0, j, count, temp, tanggal, bulan, tahun, umur, nomor;
	char gendercheck;
	char nama[26]={}, notelp[13]={};
	char gender[10]={};
	bool checknama = false;
	bool checkgender = false;
	bool checklahir = false;
	bool checktelp = false;
	bool checkumur = false;

	system("cls");

	printf("Created by : Daniel Richardo\n");
	printf("2201744531\n");
		
	printf("\t\t\t\t======================================\n");
	printf("\t\t\t\tPendaftaran PT. Sembilan Karya Sastra\n");
	printf("\t\t\t\t========== MENU PENGUBAHAN ===========\n\n");
	
	printf("\t\tKetik '0' jika ingin kembali ke menu.");
	
	for(i=0;i<5;i++){
		printf("\n");
	}
		
	
	printf("\tMasukkan nomor pendaftaran: ");
	scanf("%d", &nomor);
	getchar();

	if(nomor == 0){
		return 0;
	}

	if(strcmp(regis[nomor-1].nama, "") == 0 && regis[nomor-1].nopendaftar == 0){
		printf("\tNomor pendaftaran anda tidak valid!\n");
		getchar();
		goto A;
	}
	else{
		printf("\t______________________________________________________________________________\n");
		printf("\t|NO ||           NAMA          ||Gender||Tanggal Lahir|| Umur ||Nomor Telpon |\n");
		printf("\t|---||-------------------------||------||-------------||------||-------------|\n");
	
		for(i=nomor-1;i<nomor;i++){
			if(strcmp(regis[i].telpon, "-") == 0 && strcmp(regis[i].nama, "") != 0 && regis[i].nopendaftar != 0){
				printf("\t|%.2d.||%-25s||  %s   ||  %.2d/%.2d/%.4d ||%.2dthn ||      -      |\n", regis[i].nopendaftar, regis[i].nama, regis[i].gender, regis[i].tanggal, regis[i].bulan, regis[i].tahun, regis[i].umur, regis[i].telpon);
			}
			else if(strcmp(regis[i].nama, "") != 0 && regis[i].nopendaftar != 0){
				printf("\t|%.2d.||%-25s||  %s   ||  %.2d/%.2d/%.4d ||%.2dthn ||%-13s|\n",         regis[i].nopendaftar, regis[i].nama, regis[i].gender, regis[i].tanggal, regis[i].bulan, regis[i].tahun, regis[i].umur, regis[i].telpon);
			}
			printf("\t|___||_________________________||______||_____________||______||_____________|\n");
		}
	}
	
	printf("\n");
	
	do{
		printf("\tInput Nama [Alphabhet]: ");
		scanf("%[^\n]", &nama);
		getchar();
		
		for(i=0;i<strlen(nama);i++){
			if(isalpha(nama[i]) == 0 && nama[i]!=' '){
				printf("\tNama tidak valid!\n\t");
				getchar();
				goto A;
			}
			if(i==strlen(nama)-1){
				checknama = true;
			}
		}
	}while(checknama == false);

	do{
		printf("\tInput Gender [L = 1/P = 2]: ");
		scanf("%c", &gendercheck);
		getchar();
		
		switch(gendercheck){
			case '1' : gender[0] = 'L'; checkgender = true; break;
			case '2' : gender[0] = 'P'; checkgender = true; break;
			default : printf("\tGender tidak valid!\n"); getchar(); goto A;
		}
		
	}while(checkgender == false);

	do{
		printf("\tInput Tanggal Lahir [dd/mm/yyyy]: ");
		scanf("%d/%d/%d", &tanggal, &bulan, &tahun);
		getchar();
		
		if(bulan>12 || tahun>2018){
			printf("\tTanggal lahir tidak valid!\n");
			getchar();
			goto A;
		}
		else if(bulan == 2){
			if(tahun%4!=0 && tanggal>28){
				printf("\tTanggal lahir tidak valid!\n");
				getchar();
				goto A;
			}
			else if(tahun%4==0 && tanggal>29){
				printf("\tTanggal lahir tidak valid!\n");
				getchar();
				goto A;
			}
		}
		else if((bulan == 1 || bulan == 3 || bulan == 5 || bulan == 7 || bulan == 8 || bulan == 10 || bulan == 12) && tanggal>31){
				printf("\tTanggal lahir tidak valid!\n");
				getchar();
				goto A;
		}
		else if((bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) && tanggal > 30){
				printf("\tTanggal lahir tidak valid!\n");
				getchar();
				goto A;
		}
		
		checklahir = true;
	}while(checklahir == false);
	
do{
		printf("\n\t*Jika tidak ada, ketik \"-\" tanpa kutip*\n");
		printf("\tInput Nomor Handphone [Digit]: ");
		
		scanf("%[^\n]", &notelp);
		getchar();
		count=0;
		i=0;
		while(notelp[i] != '\0'){
			count++;
			i++;
		}
		
		if(notelp[0] == '-'){
			checktelp = true;
		}
		else if(count > 13 || count < 10){
			printf("\tNomor anda tidak valid!!!\n");
			getchar();
			goto A;
		}
		else{
			
			i=0;
			do{
				if(isdigit(notelp[i]) == 0){
					printf("\tNomor anda tidak valid!\n");
					getchar();
					goto A;
				}
				i++;
			}while(notelp[i]!='\0');
		}
	
		checktelp = true;
	}while(checktelp == false);
	
	umur = 2018-tahun;
	if(umur < 18){
		printf("\tMaaf umur anda tidak mencukupi untuk mendaftarkan diri.\n");
		getchar();
		goto A;
	}
	else{
		checkumur=true;
	}

	strcpy (regis[nomor-1].nama, nama);
	strcpy(regis[nomor-1].gender, gender);
	regis[nomor-1].tanggal = tanggal;
	regis[nomor-1].bulan = bulan;
	regis[nomor-1].tahun = tahun;
	strcpy(regis[nomor-1].telpon, notelp);
	
	printf("\n\tData berhasil diubah!\n"); 
	getchar();
	
return 0;
}

int main(){
	int i=0, input, nomor, tanggal, bulan, tahun, umur;
	char nama[26], gender[5], notelp[14];
	
	file = fopen("word.txt","r");
	while(fscanf(file, "%d#%[^#]#%[^#]#%d#%d#%d#%d#%[^\n]\n", &nomor, &nama, &gender, &tanggal, &bulan, &tahun, &umur, &notelp) != EOF){
	
		regis[nomor-1].nopendaftar = nomor;
		strcpy (regis[nomor-1].nama, nama);
		strcpy(regis[nomor-1].gender, gender);
		regis[nomor-1].tanggal = tanggal;
		regis[nomor-1].bulan = bulan;
		regis[nomor-1].tahun = tahun;
		regis[nomor-1].umur = umur;
		strcpy(regis[nomor-1].telpon, notelp);
	}
	fclose(file);
	i=0;
	
	do{
		system("cls");
	
		printf("Created by : Daniel Richardo\n");
		printf("2201744531\n");
		
	
		printf("\t\t\t\t======================================\n");
		printf("\t\t\t\tPendaftaran PT. Sembilan Karya Sastra\n");
		printf("\t\t\t\t============= MENU UTAMA =============\n\n");
		for(i=0;i<5;i++){
			printf("\n");
		}
		printf("\t\t1. Pendaftaran\n");
		printf("\t\t2. List Pendaftar\n");
		printf("\t\t3. Pengunduran Diri\n");
		printf("\t\t4. Update Pendaftaran\n");
		printf("\t\t5. Exit.\n\n");
		printf("\t\t>> ");
	
		scanf("%d", &input);
		getchar();
	
		switch(input){
			case 1 : pendaftaran(); break;
			case 2 : list(); break;
			case 3 : pengunduran(); break;
			case 4 : update(); break;
		}
		
	}while(input !=5 );

	for(i=0;i<5;i++){
		printf("\n");
	}

	
	printf("\t\t\t\tTerima Kasih Atas Kerjasama Anda!\n");
	
	i=0;
	
	file = fopen("word.txt","w");
	
	while(i<100){
//		printf("test1 %d", i);
//		printf("test2 %d", i);
		if(regis[i].nopendaftar > 0){
			fprintf(file, "%d#%s#%s#%d#%d#%d#%d#%s\n", regis[i].nopendaftar, regis[i].nama, regis[i].gender, regis[i].tanggal, regis[i].bulan, regis[i].tahun, regis[i].umur, regis[i].telpon);
		}
		i++;
	}
	fclose(file);

return 0;
}
