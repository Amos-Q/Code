#include "home.h"

extern struct heap *heap_creat(heap_keycmp keycmp, heap_value_free valuefree);
extern struct heap *heap_creat_default(heap_value_free valuefree);
extern int  heap_insert(struct heap *heap, void *key, void *value);
extern int  heap_delete_max(struct heap *heap);
extern int  heap_build(struct heap *heap);
extern int  heap_sort(struct heap *heap);
extern void heap_empty(struct heap *heap);
extern void heap_destroy(struct heap **heap);

extern void heap_sample(void);