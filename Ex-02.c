#include<stdio.h>
#include<stdlib.h>

// Structure Definition

struct stack
{
    int *arr;
    int top;
    int size;
};

// Function : init_stack()
void init_stack(struct stack *sp, int size)
{
    sp->size = size;
    sp->top = -1;
    sp->arr = (int *)malloc(size * sizeof(int));
}

// Function : stack_full()

int stack_full(struct stack *sp)
{
    if(sp->top == sp->size - 1)
        return 1;
    else
        return 0;
}

// Function : push()

void push(struct stack *sp, int data)
{
    if(stack_full(sp))
    {
        printf("Stack is Full.\n");
    }
    else
    {
        (sp->top)++;
        sp->arr[sp->top] = data;
        printf("%d <- Inserted\n", data);
    }
}

// Function : stack_empty()

int stack_empty(struct stack *sp)
{
    if(sp->top == -1)
        return 1;
    else
        return 0;
}

// Function : pop()

void pop(struct stack *sp)
{
    if(stack_empty(sp))
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("%d <- Deleted\n", sp->arr[sp->top]);
        (sp->top)--;
    }
}

// Function : peek()

int peek(struct stack *sp)
{
    return sp->arr[sp->top];
}

// Function : display()

void display(struct stack *sp)
{
    int i;

    if(stack_empty(sp))
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("\nStack:\n");

        for(i = sp->top; i >= 0; i--)
        {
            printf("| %d |\n", sp->arr[i]);
        }

        printf("-----\n");
    }

    printf("Top = %d\n", sp->top);
}

// Main Function

int main()
{
    int ch, data, size;

    struct stack s1;

    printf("Enter Size of Stack : ");
    scanf("%d", &size);

    init_stack(&s1, size);

    do
    {
        printf("\n0.Exit\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display Stack\n");

        printf("Enter Your Choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 0:
                printf("Bye Bye...\n");
                break;

            case 1:
                // Push Operation

                printf("Enter Data : ");
                scanf("%d", &data);

                push(&s1, data);
                break;

            case 2:
                // Pop Operation

                pop(&s1);
                break;

            case 3:
                // Peek Operation

                if(stack_empty(&s1))
                {
                    printf("Stack is Empty.\n");
                }
                else
                {
                    data = peek(&s1);
                    printf("Peek Value : %d\n", data);
                }

                break;

            case 4:
                // Display Operation

                display(&s1);
                break;

            default:
                printf("Invalid Choice.\n");
        }

        printf("Top = %d\n", s1.top);

    }while(ch != 0);

    free(s1.arr);

    return 0;
}