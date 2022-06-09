#include "kamus.h"

int main() {
	TreeNode root = NULL;
	infotype input;
	bool indo;
	int pilih;
	
	while(1){
		menu1 :
		printf("--------------------------------------------------------------------------------\n");
		printf("================================================================================\n");
		printf("\t\t\t|KAMUS BAHASA INDONESIA & INGGRIS|\n");
		printf("|==============================================================================|\n");	
		printf("|=================================MENU UTAMA===================================|\n");
		printf("|1. INDONESIA - INGGRIS                                                        |\n");
		printf("|2. INGGRIS - INDONESIA                                                        |\n");
		printf("|3. HELP                                                                       |\n");
		printf("|4. EXIT                                                                       |\n");
		printf("|==============================================================================|\n:");
		printf("\t\t\t        Masukan pilihan : ");
		scanf("%d",&pilih);
		
		if (pilih == 1){
			indo = true;
			break;
		}else if( pilih == 2){
			indo = false;
			break;
		}else if(pilih == 3){
			system("cls");
			tatacaraApk(1);
			getch();
			system("cls");
			goto menu1;
			break;
		}else if(pilih == 4){
			exit(1);
		}else{
			printf("\t\t\t        Masukkan pilihan sesuai menu!");
			getch();
			goto menu1;
		}
	}
	
	openTree(&root,indo);		
	for(;;){
		menu :
		system("cls");
		if(indo){
			printf("--------------------------------------------------------------------------------\n");
			printf("================================================================================\n");
			printf("\t\t\t| BAHASA INDONESIA & INGGRIS |\n");
			printf("|==============================================================================|\n");	
			printf("|==========================MENU INDONESIA - INGGRIS ===========================|\n");
			printf("|1. Masukan Kata                                                               |\n");
			printf("|2. Hapus Kata                                                                 |\n");
			printf("|3. Cari Kata                                                                  |\n");
			printf("|4. Edit Kata                                                                  |\n");
			printf("|5. Tampil Semua Kata                                                          |\n");
			printf("|6. Kembali ke Menu                                                            |\n");
			printf("|==============================================================================|\n:");
			printf("\t\t\t        Masukkan pilihan : ");
			fflush(stdin);
			scanf("%d",&pilih);
			
			switch (pilih){
					case 1 :
						insertkeFile(&root,indo);
						getch(); 
						break;
					case 2 :
						printf("\t\t\t        Masukkan Kata : ");
						fflush(stdin);
						gets(input);
						HapusKata(&root,input, indo);
						getch();
						break;
					case 3 :
						printf("\t\t\t        Kata yang dicari : ");
						fflush(stdin);
						gets(input);
						cariKata(root,input,indo);
						getch();
						break;
					case 4 : 
						printf("\t\t\t        Kata yang terjemahannya akan diganti : ");
						fflush(stdin);
						gets(input);
						EditKata(&root,input,indo);
						getch();
						break;	
					case 5 :
						system("cls");
						printf("|==============================================================================|\n");
						printf("|========================== LIST KATA DALAM KAMUS  ============================|\n");
						printf("|==============================================================================|\n");
						fflush(stdin);
						printf("\n"); PreOrder (root, indo);
						printf("\n\n\t\t\t        Jumlah Kata = %d ", hitKata(root));
						getch();
						break;
					case 6 :
						system("cls");
						indo = false;
						root = NULL;
						openTree(&root,indo);
						goto menu1;
						break;
			}
	
		}
		else{
			printf("--------------------------------------------------------------------------------\n");
			printf("================================================================================\n");
			printf("\t\t\t| DICTIONARY INGGRIS & INDONESIA |\n");
			printf("|==============================================================================|\n");	
			printf("|==========================MENU INGGRIS - INDONESIA ===========================|\n");
			printf("|1. Insert Word                                                                |\n");
			printf("|2. Delete Word                                                                |\n");
			printf("|3. Find Word                                                                  |\n");
			printf("|4. Correction Word                                                            |\n");
			printf("|5. List Word                                                                  |\n");
			printf("|6. Back To Menu                                                               |\n");
			printf("|==============================================================================|\n:");
			printf("\t\t\t        Enter Options : ");
			fflush(stdin);
			scanf("%d",&pilih);
			
			switch (pilih){
					case 1 :
						insertkeFile(&root,indo);
						break;
					case 2 :
						printf("\t\t\t        Insert Word : ");
						fflush(stdin);
						gets(input);
						HapusKata(&root,input, indo);
						getch();
						break;
					case 3 :
						printf("\t\t\t        Key word : ");
						fflush(stdin);
						gets(input);
						cariKata(root,input,indo);
						getch();
						break;
					case 4 : 
						printf("\t\t\t        Insert Word to Correct  : ");
						fflush(stdin);
						gets(input);
						EditKata(&root,input,indo);
						getch();
						break;	
					case 5 :
						system("cls");
						printf("|==============================================================================|\n");
						printf("|=========================== WORD LIST DICTIONARY  ============================|\n");
						printf("|==============================================================================|\n");
						fflush(stdin);
						printf("\n"); PreOrder (root, indo);
						printf("\n\n\t\t\t        Word Count = %d ", hitKata(root));
						getch();
						break;
					case 6 :
						system("cls");
						indo = true;
						root = NULL;
						openTree(&root,indo);
						goto menu1;
						break;	
			}
		}
	}
	return 0;
}
