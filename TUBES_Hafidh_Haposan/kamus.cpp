#include "kamus.h"

TreeNode Search(TreeNode p,infotype inputUser,bool indo){
	
	if(p == NULL)
		return NULL;
	
	if(indo){
		if(strcmp(inputUser,p->indonesia) < 0)
			return Search(p->left,inputUser,indo);
		else if(strcmp(inputUser,p->indonesia) > 0)
			return Search(p->right,inputUser,indo);
		else
			return p;
	}
	else{
		if(strcmp(inputUser,p->inggris)!= 0){
			if(strcmp(inputUser,p->inggris) < 0)
				return Search(p->left,inputUser,indo);
			else
				return Search(p->right,inputUser,indo);
		}else{
			return p;
		}
	}
	return NULL;
}

TreeNode HapusKata(TreeNode *p, infotype input, bool bhs) {

	kamus kms;
	FILE *fkamus, *ftemp;
	TreeNode s, t;
	
	if (p == NULL) {
		if (bhs) {
			printf("\t\t\t        Tidak ada data! Silahkan input kata");
		}
		else{
			printf("\t\t\t        Data not found! Please insert the word");
		}
		getch();	
	}
	else {
		if(bhs) {
			s = Search(*p,input,bhs);
			
			if(s == NULL){
				printf("\t\t\t        Kata tidak di temukan!");
			}
			else {
				if ((fkamus = fopen("filetree.dat","rt")) == NULL){
					printf("\t\t\t        File tidak dapat di buka\n");
					exit(0);
				}
				if ((ftemp = fopen("filetemp.dat","wt")) == NULL){
					printf("\t\t\t        File tidak dapat di buka\n");
					exit(0);
				}
				
				while(fread(&kms, sizeof(kms), 1, fkamus)){
					if(strcmp(s->indonesia,kms.ind) != 0){
						fwrite(&kms, sizeof(kms),1,ftemp);					
					}
				}
				fclose(fkamus);
				fclose(ftemp);
				
				ftemp = fopen("filetemp.dat","rt");				
				fkamus = fopen("filetree.dat","wt");
				while(fread(&kms, sizeof(kms), 1, ftemp)){
						fwrite(&kms, sizeof(kms),1,fkamus);
				}
				fclose(fkamus);
				fclose(ftemp);
				
				fkamus = fopen("filetree.dat","rt");				
				*p = NULL;
				while(fread(&kms,sizeof(kms),1,fkamus) == 1){
					*p= InsertNode(*p,kms.ind,kms.eng,bhs);
				}
				printf("\t\t\t        Kata berhasil terhapus");
			}
		}
		else {
			t = Search(*p,input,bhs);
			
			if(t == NULL){
				printf("Word not found!");
			}
			else {
				if ((fkamus = fopen("filetree.dat","rt")) == NULL){
					printf("\t\t\t        The file can not be open\n");
					exit(0);
				}
				if ((ftemp = fopen("filetemp.dat","wt")) == NULL){
					printf("\t\t\t        The file can not be open\n");
					exit(0);
				}
				
				while(fread(&kms, sizeof(kms), 1, fkamus)){
					if(strcmp(t->inggris,kms.eng) != 0){
						fwrite(&kms, sizeof(kms),1,ftemp);					
					}
				}
				fclose(fkamus);
				fclose(ftemp);
				
				ftemp = fopen("filetemp.dat","rt");				
				fkamus = fopen("filetree.dat","wt");
				while(fread(&kms, sizeof(kms), 1, ftemp)){
						fwrite(&kms, sizeof(kms),1,fkamus);
				}
				fclose(fkamus);
				fclose(ftemp);
				
				fkamus = fopen("filetree.dat","rt");				
				*p = NULL;
				while(fread(&kms,sizeof(kms),1,fkamus) == 1){
					*p= InsertNode(*p,kms.ind,kms.eng,bhs);
				}
				printf("\t\t\t        Success delete a word from the dictionary!");
				
			}
		}
	}
}

void insertkeFile(TreeNode *p, bool bhs) {
	kamus kms;
	TreeNode temp;
	FILE *file;
	
	if((file=fopen("filetree.dat","a+")) == NULL){
		printf("\t\t\t        File tidak ditemukan!");
		exit(1);
	}
	
	if(bhs){
		do{	
			printf("\t\t\t        Masukkan Kata : ");
			fflush(stdin);
			gets(kms.ind);
			temp = Search(*p, kms.ind, bhs);
			if(temp != NULL)												
			printf("\t\t\t        Kata telah ada dalam kamus!\n");
		
		}while(temp != NULL);
		do{	
			printf("\t\t\t        Masukkan Terjemahan : ");
			fflush(stdin);				
			gets(kms.eng);
			temp = Search(*p, kms.eng, bhs);
			if(temp != NULL)												
			printf("\t\t\t        Kata telah ada dalam kamus!\n");
		
		}while(temp != NULL);
			
		fwrite(&kms,sizeof(kms),1,file);
		*p = InsertNode(*p, kms.ind, kms.eng, bhs);		
	}
	else {
		do{	
			printf("\t\t\t        Insert Word : ");
			fflush(stdin);
			gets(kms.eng);
			temp = Search(*p, kms.eng, bhs);
			if(temp != NULL)												
			printf("\t\t\t        Word is available in the dictionary!\n");
		
		}while(temp != NULL);
		do{	
			printf("\t\t\t        Word Translation : ");
			fflush(stdin);				
			gets(kms.ind);
			temp = Search(*p, kms.ind, bhs);
			if(temp != NULL)												
			printf("\t\t\t        Word is available in the dictionary!\n");
		
		}while(temp != NULL);
		fwrite(&kms,sizeof(kms),1,file);
		*p = InsertNode(*p, kms.ind, kms.eng, bhs);
	}
	if(bhs){
		printf("\t\t\t        Kata telah berhasil ditambahkan kedalam kamus...");
	}
	else {
		printf("\t\t\t        Success added word to the dictionary...");
	}
	fclose(file);
	getch();
}

void cariKata(TreeNode p,infotype inputUser,bool bhs){
	FILE *fHistory;
	history riwayat;
	TreeNode nodeTemp;	
	
	fHistory = fopen("History.txt","a+");
	
	if (fHistory == NULL){
		printf("\nFile tidak ditemukan!");
	}
	
	if(bhs){
		
		nodeTemp = Search(p,inputUser,bhs);
		if(nodeTemp != NULL){
			printf("\t\t\t        Kata Ditemukan!\n");
			printf("\t\t\t        %s = %s",nodeTemp->indonesia,nodeTemp->inggris);
			strcpy(riwayat.ind,nodeTemp->indonesia);
			strcpy(riwayat.eng,nodeTemp->inggris);
		    fwrite(&riwayat,sizeof(riwayat),1,fHistory);
		}
		else{
			printf("\t\t\t        Kata Tidak Ada dalam Kamus");
		}	
	}
	else {
		
		nodeTemp = Search(p,inputUser,bhs);
		if(nodeTemp != NULL){
			printf("\t\t\t        Found!\n");
			printf("\t\t\t        %s = %s",nodeTemp->inggris,nodeTemp->indonesia);
			strcpy(riwayat.ind,nodeTemp->inggris);
			strcpy(riwayat.eng,nodeTemp->indonesia);
		    fwrite(&riwayat,sizeof(riwayat),1,fHistory);
		}
		else{
			printf("\t\t\t        Not Found!\n");
		}
	}
	fclose(fHistory);
}

void openTree(TreeNode *p, bool bhs){
	
	kamus kms;	
	FILE *file;
	
	if ((file = fopen("filetree.dat","a+")) == NULL){
		printf("File Tidak Dapat Dibuka\n");
		exit(0);
	}
		
	while(fread(&kms,sizeof(kms),1,file) == 1){
		if(bhs){
			*p = InsertNode(*p, kms.ind, kms.eng,bhs);
		}
		else{
			*p = InsertNode(*p, kms.ind, kms.eng,bhs);
		}
	}
	
	fclose(file);
}

void tatacaraApk(bool bhs){
	FILE *fRules;
	char text[1000];
	
	
	if(bhs){
		if((fRules=fopen("HelpIndo.txt","rt")) == NULL){
			printf("File tidak dapat di buka\n");
			exit(1);
		}
		while(fgets(text,1000,fRules)){
		printf("%s", text);
		}	
	}
	fclose(fRules);	
	getch();
}

void EditKata(TreeNode *p, infotype input, bool bhs) {
	kamus kms, tkms;
	FILE *fkamus, *ftemp;
	TreeNode temp;
	
	if(*p == NULL) {
		if (bhs) {
			printf("\t\t\t        Kata tidak ada! Silahkan input kata");
		}
		else{
			printf("\t\t\t        Word not found! Please insert the word");
		}
		getch();
	}
	else {
		if ((fkamus = fopen("filetree.dat", "r")) == NULL) {
			printf("\t\t\t        The file can not be open\n");				
			exit(1);
		}
		if ((ftemp = fopen("filetree.dat", "w")) == NULL) {
			printf("\t\t\t        The file can not be open\n");
			exit(1);
		}
			
		while (fread(&kms, sizeof(kms), 1, fkamus)) {
			if(strcmp(input, kms.ind) != 0) {
				fwrite(&kms, sizeof(kms), 1, ftemp);
			}
		}
		fclose(fkamus);
		fclose(ftemp);
			
		fkamus = fopen("filetree.dat","a+");
		ftemp = fopen("filetemp.dat","r");
			
		if(bhs) {
			temp = Search(*p, input, bhs);
			
			if(temp == NULL) {
				printf("\t\t\t        Kata tidak di temukan!");
			}
			else {
				printf("\t\t\t        Kata            = %s \n", temp->indonesia);
				printf("\t\t\t        Terjemahan kata = %s \n", temp->inggris);
				strcpy(tkms.ind, temp->indonesia);
				printf("\t\t\t        Masukkan terjemahan kata = "); fflush(stdin);
				gets(temp->inggris);
				strcpy(tkms.eng, temp->inggris);
				
				while(fread(&kms, sizeof(kms), 1, ftemp)){
					fwrite(&kms, sizeof(kms), 1 , fkamus);
				}
				fwrite(&tkms, sizeof(tkms), 1, fkamus);
				printf("\t\t\t        Kata berhasil diganti!\n");
			}
		}
		else {
			temp = Search(*p, input, bhs);
			
			if(temp == NULL) {
				printf("\t\t\t        Word not found!");
			}
			else {
				printf("\t\t\t        Word            = %s \n", temp->indonesia);
				printf("\t\t\t        Translate Word  = %s \n", temp->inggris);
				strcpy(tkms.eng, temp->inggris );
				printf("\t\t\t        Insert Translate Word = "); fflush(stdin);
				gets(temp->indonesia); 
				strcpy(tkms.ind, temp->indonesia);
				
				while(fread(&kms, sizeof(kms), 1, ftemp)){
					fwrite(&kms, sizeof(kms), 1, fkamus);
				}
				fwrite(&tkms, sizeof(tkms), 1, fkamus);
				printf("\t\t\t        Success to replace the word!\n");
			}
		}
		strcpy(input, "NULL");
		temp = Search(*p,input, bhs);
		if(temp == NULL){
			Dealokasi(temp);
		}
		
		fclose(fkamus);
		fclose(ftemp);
	}
}

int hitKata(TreeNode p){
	
	int hitLeft, hitRight, total;
	
	if(p == NULL){
		return 0;
	}else{
		total = 1;
		hitLeft  = hitKata(p->left);
		hitRight = hitKata(p->right);
	}
	return total + hitLeft + hitRight;
}
