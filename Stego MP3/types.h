#ifndef TYPES_H
#define TYPES_H

/* Typedef for creating the alias to unsigned int data type */
typedef unsigned int uint;

/* Status will be used as Function return type */
typedef enum
{
    v_success,
    v_failure,
    e_success,
    e_failure,
}Status;

typedef enum
{
    p_view,
    p_edit,
    p_help,
    p_unsupported
}OperationType;

#endif
