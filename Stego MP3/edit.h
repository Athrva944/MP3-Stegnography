#ifndef EDIT_H
#define EDIT_H
#include<stdio.h>
#include"types.h"

typedef struct EditInfo
{
    /*source mp3 audio information */
    char *source_mp3_filenme;
    FILE *fptr_source_mp3;

    char tag_TIT2[100];
    char tag_TPE1[100];
    char tag_TALB[100];
    char tag_TYER[100];
    char tag_TCON[100];
    char tag_TCOM[100];

    char third_arg[100];
    char fourth_arg[100];
}EditInfo;

//Function defination for the all edit functions
Status read_and_validate_edit_args(char *argv[],EditInfo *E_info);

Status do_edit (EditInfo *E_info);

Status open_file(EditInfo *E_info );

Status check_ID3(EditInfo *E_info);

Status check_version(EditInfo *E_info);

Status check_edit(EditInfo *E_info);

int reverse_msb_to_lsb(int num);
#endif
