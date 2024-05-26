/* Name: Atharva kothawade */

#include<stdio.h>
#include<string.h>
#include"types.h"
#include"view.h"
#include"edit.h"
int main(int argc,char *argv[])
{
    ViewInfo V_info;
    EditInfo E_info;
    //If only 1 CLA is present 
    if (argc == 1)
    {
	printf("\n----------------------------------------------------\n");
	printf("ERROR : ./a.out          : INVALID ARGUMENTS\n\nUSAGE :\n");
	printf("To view please pass like : ./a.out -v mp3filename\n");
	printf("To edit pass like        : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
	printf("To get help pass like    : ./a.out --help\n");
	printf("------------------------------------------------------\n");
	return v_failure;
    }
    if (check_operation(argv) == p_help)
    {
	printf("\n---------------- HELP MENU -----------------\n");
	printf("1.  -v  -> to view mp3 file contents\n");
	printf("2.  -e  -> to edit mp3 file contents\n");
	printf("        2.1.  -t  -> to edit song file\n");
	printf("        2.2.  -a  -> to edit artist name\n");
	printf("        2.3.  -A  -> to edit album song\n");
	printf("        2.4.  -y  -> to edit year\n");
	printf("        2.5.  -m  -> to edit content\n");
	printf("        2.6.  -c  -> to edit comment\n");
	printf("--------------------------------------------\n");
    }
    else if (check_operation(argv) == p_view)
    {
	if(argc<3 || argc>3)
	{
	    printf("\n----------------------------------------------------\n");
	    printf("ERROR : ./a.out          : INVALID ARGUMENTS\nUSAGE :\n");
	    printf("To view please pass like : ./a.out -v mp3filename\n");
	    printf("To edit pass like        : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
	    printf("To get help pass like    : ./a.out --help\n");
	    printf("------------------------------------------------------\n");
	    return v_failure;
	}
	if (read_and_validate_encode_args(argv,&V_info) == v_success)
	{
	    printf("SUCCESS: Read and validation\n");
	    printf("------------SELECTED VIEW DETAILS-------------\n");
	    printf("----------------------------------------------\n");
	    printf("        MP3 TAG READER AND EDITOR FOR ID3V2   \n");
	    printf("----------------------------------------------\n");
	    if (do_view(&V_info) == v_success)
	    {
		printf("----------------------------------------------\n");
		printf("---------------File view success--------------\n");
		printf("----------------------------------------------\n");
		return v_success;
	    }
	    else
	    {
		printf("FAILURE: File view fail\n");
		return v_failure;
	    }
	}
    }
    else if (check_operation(argv) == p_edit)
    {
	if (argc<5 || argc>5)
	{
	    printf("\n----------------------------------------------------\n");
	    printf("ERROR : ./a.out          : INVALID ARGUMENTS\nUSAGE :\n");
	    printf("To view please pass like : ./a.out -v mp3filename\n");
	    printf("To edit pass like        : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
	    printf("To get help pass like    : ./a.out --help\n");
	    printf("------------------------------------------------------\n");
	    return v_failure;
	}
	if (read_and_validate_edit_args(argv,&E_info) == e_success)
	{
	    printf("\n------------SELECTED EDIT DETAILS-------------\n");
	    printf("-----------------------------------------------\n");
	    printf("--------------SELECTED EDIT OPTION-------------\n");
	    if (do_edit(&E_info) == e_success)
	    {
		printf("----------------------------------------------\n");
		printf("----------SUCCESS: File edit success----------\n");
		printf("----------------------------------------------\n");
		return v_success;
	    }
	    else 
	    {
		printf("FAILURE: File edit fail\n");
		return v_failure;
	    }
	}
    }
}
//Function for the check operation (-v/-e)
OperationType check_operation(char *argv[])
{
    if ((strcmp(argv[1],"--help") == 0) || (strcmp(argv[1],"--HELP") == 0))
	return p_help;
    else if (strcmp(argv[1],"-v") == 0)
	return p_view;
    else if (strcmp(argv[1],"-e") == 0)
	return p_edit;
    else
	return p_unsupported;
}
