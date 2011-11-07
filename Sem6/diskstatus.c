// To read disk status

#include<stdio.h>
#include<fcntl.h>
#include<linux/fs.h>
#include<linux/ext2_fs.h>

main()
{

	 int fp,fp2,i,size;
	 struct ext2_super_block *b;
	 char a[1024] ={0};
	 fp=open("/dev/hda3",O_RDONLY);
	 if(fp==-1)
	 {
		 printf("cannot open disk file \n");
		 return 0;
	 }

	 lseek(fp,1024,SEEK_SET);
	 read(fp,a,1024);
	 b=(struct ext2_super_block *)a;
	
	 printf("volume label %s\n",b->s_volume_name);
	 printf("first data block on %s\n",b->s_first_data_block);
	 printf("Inode count %d\n",b->s_inodes_count);
	 printf("inodes per group\n",b->s_inodes_per_group);
	 printf("inode size %d\n",b->s_inode_size);
	 printf("maximum mount count %d\n",b->s_max_mnt_count);
	 close(fp);
	 return 0;
 
}
