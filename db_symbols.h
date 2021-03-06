/* db_symbols.h - symbol table definitions
 *
 * Copyright (c) 2014 by David Michael Betz.  All rights reserved.
 *
 */

#ifndef __DB_SYMBOLS_H__
#define __DB_SYMBOLS_H__

#include "db_types.h"

/* storage class ids */
typedef enum {
    SC_CONSTANT,
    SC_VARIABLE,
    SC_HWVARIABLE
} StorageClass;

/* forward type declarations */
typedef struct Symbol Symbol;

/* symbol table */
typedef struct {
    Symbol *head;
    Symbol **pTail;
    int count;
} SymbolTable;

/* symbol structure */
struct Symbol {
    VMVALUE value;  // must be first
    Symbol *next;
    StorageClass storageClass;
    char name[1];
};

void InitSymbolTable(SymbolTable *table);
Symbol *FindSymbol(SymbolTable *table, const char *name);
void DumpSymbols(SymbolTable *table, char *tag);

#endif
