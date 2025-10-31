
#define MIN_LISTINT_SIZE 100
struct List {
    size_t length;
    size_t limit;
    int*   data;
};
struct List* newListInt ( size_t );
struct List* pushListInt( struct List*, int );
int          popListInt ( struct List* );
void         freeListInt( struct List* );

int* dailyTemperatures(int* temps, int temps_size, int* ret_size) 
{
    struct List* stack = newListInt(0);
    struct List* res   = newListInt(temps_size);

    for ( int i=0; i < temps_size; i++ ) {
        while ( stack->length && temps[ stack->data[stack->length-1] ] < temps[i] ) {
            int prev_idx = popListInt( stack );
            res->data[ prev_idx ] = i - prev_idx;
        }
        pushListInt( stack, i );
    }

    for ( int i=0; i < stack->length; i++ ) {
        res->data[ stack->data[i] ] = 0;
    }

    freeListInt(stack);
    int* data = res->data;
    res->data = NULL;
    freeListInt(res);
    ret_size[0] = temps_size;
    return data;
}

struct List* newListInt( size_t size )
{
    struct List* x = (struct List*) malloc( sizeof(struct List) );
    if ( !x ) return NULL;
    *x = (struct List) {
        .length = 0,
        .limit = (int) fmax(MIN_LISTINT_SIZE, size),
        .data = NULL,
    };
    x->data = (int*) malloc( x->limit * sizeof(int) );
    if ( !x->data ) {
        free(x); return NULL;
    }
    return x;
}

struct List* pushListInt( struct List* x, int val )
{
    x->length++;
    if ( x->length == x->limit ) {
        x->limit *= 2;
        x->data = (int*) reallocarray( x->data, x->limit, sizeof(int) );
        if (!x->data) {
            free(x); return NULL;
        }
    }
    x->data[x->length-1] = val;
    return x;
}

int popListInt( struct List* x )
{
    int res = x->data[x->length-1];
    if ( 2 * x->length == x->limit ) {
        x -> limit /= 2;
        x->data = (int*) reallocarray( x->data, x->limit, sizeof(int) );
        if ( !x ) free(x); return res;
    }
    x->length--;
    return res;
}

void freeListInt( struct List* list )
{
    free(list->data); list->data = NULL;
    free(list); list = NULL;
}
