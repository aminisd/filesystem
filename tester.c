#include "structures.h"
#include <stdio.h>

int main(){
	FILE * fin = fopen("simplefs.bin", "r");
       	
	struct sb super_block;
	fseek(fin, 0, SEEK_SET);
	fread(&super_block,sizeof(super_block), 1,fin);

	printf("inode_bitmap: %d\n",super_block.inode_bitmap );
for(int i=0; i < 10; i++)
	printf("data_bitmap[%d] : %d\n", i,super_block.data_bitmap[i]);





	struct inode slash;
	fseek(fin, sizeof(struct sb), SEEK_SET);
	fread(&slash,sizeof(slash),1,fin);

	printf("type: %d\n", slash.type);
	printf("size: %d\n", slash.size);
for(int i = 0; i < slash.size ; i++){
	printf("datablocks[%d]: %d\n", i , slash.datablocks[i]);
	
}

	

	return 0;
}
