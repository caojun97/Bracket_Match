//==============================================================================
//
// Title:
// Purpose:
// Author:
// Created on:
// Copyright:
//
//==============================================================================

//==============================================================================
// Include files
#include "sq_stack.h"
#include <stdio.h>
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Global variables


//==============================================================================
// Static functions

//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?
//int Define_Your_Functions_Here (int x)
//{
//	return x;
//}
// ջ��ʼ��
int stack_init(SqStack_T *sq_stack_pt)
{
	/* baseΪջ��ָ�룬��ʼ����ɺ�ջ��ָ��baseʼ��ָ��ջ��λ��.
	 * ��base��ֵΪNULL�������ջ�ṹ�����ڡ�
	*/
	sq_stack_pt->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if (NULL == sq_stack_pt->base)
	{
		//printf("malloc memory fail\n");
		exit(OVERFLOW); // �˳�����
	}
	sq_stack_pt->top = sq_stack_pt->base;
	sq_stack_pt->stack_size = MAXSIZE;
	sq_stack_pt->num_of_elem = 0;
	return OK;
}

// ջ����
void stack_destory(SqStack_T *sq_stack_pt)
{
	if (sq_stack_pt->base != NULL)
		free(sq_stack_pt->base);
	sq_stack_pt->base = NULL;
	sq_stack_pt->top = NULL;
	sq_stack_pt->num_of_elem = 0;
}

// ��ջ
int stack_push(SqStack_T *sq_stack_pt, ElemType elem)
{
	// ��ջǰ�����ж��Ƿ�ջ��
	if (sq_stack_pt->base - sq_stack_pt->top == sq_stack_pt->stack_size)
	{
		printf("stack full\n");
		return ERROR;
	}
	// Ԫ����ջ��ջ��ָ��top+1
	*(sq_stack_pt->top) = elem;
	(sq_stack_pt->top)++;
	(sq_stack_pt->num_of_elem)++;
	return OK;
}

// ��ջ
int stack_pop(SqStack_T *sq_stack_pt, ElemType *elem)
{
	// ��ջǰ�����ж��Ƿ�ջ��
	if (sq_stack_pt->top == sq_stack_pt->base)
	{
		printf("stack empty\n");
		return ERROR;
	}
	// Ԫ�س�ջ��ջ��ָ��top-1
	(sq_stack_pt->top)--;
	(sq_stack_pt->num_of_elem)--;
	*elem = *(sq_stack_pt->top);
	return OK;
}

// ȡջ��Ԫ��
ElemType stack_top_element_get(SqStack_T sq_stack_t)
{
	ElemType elem = { 0 };
	if (sq_stack_t.top != sq_stack_t.base)
		elem = *(sq_stack_t.top - 1);
	return elem;
}