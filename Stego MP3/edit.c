/* Name: Atharva kothawade */
#include<stdio.h>
#include<string.h>
#include "types.h"
#include "edit.h"
Status read_and_validate_edit_args(char *argv[],EditInfo *E_info)
{
    if((strcmp (argv[2],"-t") == 0) || (strcmp (argv[2],"-a") == 0) || (strcmp(argv[2],"-A") == 0) ||
	    (strcmp (argv[2],"-y") == 0) || (strcmp(argv[2],"-m") == 0) || (strcmp(argv[2],"-c") == 0))
    {
	printf("SUCCESS: 3rd argument read\n");
	strcpy(E_info->third_arg,argv[2]);
	printf("3rd argument is %s\n",E_info->third_arg);
    }
    else
    {
	printf("FAILURE: 3rd argument not read\n");
	return e_failure;
    }
    strcpy(E_info->fourth_arg,argv[3]);
    printf("4th argument is %s\n",E_info->fourth_arg);

    if( strstr(argv[4],".mp3") != 0)
    {
	printf("SUCCESS: file is mp3\n");
	E_info->source_mp3_filenme = argv[4];
    }
    else
    {
	printf("FAILURE: file is not mp3 file\n");
	return e_failure;
    }
    return e_success;
}

Status open_file(EditInfo *E_info)
{
    E_info->fptr_source_mp3 = fopen(E_info->source_mp3_filenme,"r+");

    if(E_info->fptr_source_mp3 == NULL)
    {
	perror("fopen");
	fprintf(stderr,"file %s open is failed\n",E_info -> source_mp3_filenme);
	return e_failure;
    }
    else 
	return e_success;
}

Status check_ID3(EditInfo *E_info)
{
    char buffer[4];
    fread(buffer,1,3,E_info->fptr_source_mp3);
    if(strcmp(buffer,"ID3") == 0)
    {
	printf("--> Signature is %s \n",buffer);
	return e_success;
    }
    else
	return e_failure;
}

Status check_version(EditInfo *E_info)
{
    int version;
    fread(&version,1,2,E_info->fptr_source_mp3);
    printf("--> Version  %d\n",version);
    if(version == 3)
	return e_success;
    else
	return e_failure;
}

Status check_edit(EditInfo *E_info)
{
    fseek(E_info->fptr_source_mp3,10,SEEK_SET);

    if (strcmp(E_info->third_arg,"-t") == 0)
    {
	char buf[5]; 
	fread(buf,4,1,E_info->fptr_source_mp3);
	buf[4]='\0';
	int tag_size;
	while (1)
	{
	    if (strcmp(buf,"TIT2") == 0)
	    {
		if (!(strcmp(buf,"TIT2") == 0))
		{
		    char buf[5];
		    fread(buf,4,1,E_info->fptr_source_mp3 );
		    buf[4]='\0';
		    int tag_size;
		}
		fread(&tag_size,4,1,E_info->fptr_source_mp3);
		tag_size = reverse_msb_to_lsb(tag_size);

		fseek(E_info->fptr_source_mp3,3,SEEK_CUR);
		fwrite(E_info->fourth_arg ,tag_size-1,1,E_info->fptr_source_mp3);
		break;
	    }
	}
    }
    if (strcmp(E_info->third_arg,"-A") == 0)
    {
	char buf[5];
	fread(buf,4,1,E_info->fptr_source_mp3);
	buf[4]='\0';
	int tag_size;
	while (1)
	{
	    if (strcmp(buf,"") == 0)
		{}
		if (!(strcmp))
		{}
	}
    }
    return e_success;
}

int reverse_msb_to_lsb( int num)
{
    char * ptr =(char *) &num;
    char temp;
    int size =4,i;
    for(i=0;i<2;i++)
    {
	temp=*(char *)(ptr+i);
	*(char *)(ptr+i)=*(char *)(ptr+size-i-1);
	*(char *)(ptr+size-i-1)=temp;
    }
    return num;
}

Status do_edit(EditInfo *E_info)
{
    if (open_file(E_info) == e_success)
    {
	printf("SUCCESS: File open\n");
	if (check_ID3(E_info) == e_success)
	{
	    printf("SUCCESS: Check ID3\n");
	    if (check_version(E_info) == e_success)
	    {
		printf("SUCCESS: Check version\n");
		if (check_edit(E_info) == e_success)
		{
		    printf("SUCCESS: Check edit\n");
		}
		else 
		{
		    printf("FAILURE: Check edit\n");
		    return e_failure;
		}
	    }
	    else 
	    {
		printf("FAILURE: Check version\n");
		return e_failure;
	    }
	}
	else
	{
	    printf("FAILURE: Check ID3\n");
	    return e_failure;
	}
    }
    else 
    {
	printf("FAILURE: File open\n");
	return e_failure;
    }
    return e_success;
}
