#include "KMSTree.h"


typedef char infotype[25];
typedef struct kamus{
	infotype ind,eng;
}kamus;

typedef struct history{
	infotype ind,eng;
}riwayat;

TreeNode Search(TreeNode p,infotype inputUser,bool indo); 
// procedure yang mencari kata sesuai inputan dari procedure InsertkeFile

void cariKata(TreeNode p,infotype inputUser,bool bhs); 
// procedure yang mencari kata pada file  

void openTree(TreeNode *p, bool bhs); 
// procedure yang membuat tree menggunakan file

void tatacaraApk(bool bhs); 
// procedure yang membuka file Help

void insertkeFile(TreeNode *p, bool bhs); 
// procedure yang membuat file

TreeNode HapusKata(TreeNode *p, infotype input, bool bhs); 
// procedure untuk menghapus kata dalam file  

void EditKata(TreeNode *p, infotype input, bool bhs); 
// procedure untuk mengedit kata dalam tree file 

int hitKata(TreeNode p); 
// function untuk menghitung total jumlah kata tree dalam file
