#ifndef VIEW_H
#define VIEW_H
#include<stdio.h>
#include"types.h"

typedef struct ViewInfo
{
    /*source mp3 audio information */
    char *source_mp3_filenme;
    FILE *fptr_source_mp3;
    char tag_TIT2[100];
    char tag_TPE1[100];
    char tag_TALB[100];
    char tag_TYER[100];
    char tag_TCON[100];
    char tag_COMM[100];

}ViewInfo;

/*Function Declerations*/

//Cheack operation type (-v/-e)
OperationType check_operation(char *argv[]);

Status read_and_validate_encode_args(char *argv[],ViewInfo *V_info);

Status do_view(ViewInfo *V_info);

Status open_view_file(ViewInfo *V_info );

Status check_view_ID3(ViewInfo *V_info);

Status check_view_version(ViewInfo *V_info);

Status check_view(ViewInfo *V_info);

int reverse_view_msb_to_lsb(int num);
#endif
