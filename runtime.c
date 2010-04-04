/*****************************************************
** RUNTIME POUR LE COMPILATEUR ML2C	            **
** Ecrite par Pauline CHAMOREAU et Nicolas RIGNAULT **
*****************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct MLvalue {
  int id;
  void* val;
  int size;
};
typedef struct MLvalue MLvalue;

struct MLunit {
  int val;
};
typedef struct MLunit MLunit;

struct MLbool {
  int id;
  int val;
  int size;
};
typedef struct MLbool MLbool;

struct MLint {
  int id;
  int val;
  int size;
};
typedef struct MLint MLint;

struct MLdouble {
  int id;
  double val;
  int size;
};
typedef struct MLdouble MLdouble;

struct MLstring {
  int id;
  char* val;
  int size;
};
typedef struct MLstring MLstring;

struct MLpair {
  int id;
  void* MLfst;
  int type1;
  void* MLsnd;
  int type2;
  int size;
};
typedef struct MLpair MLpair;


struct MLlist {
  int id;
  void* MLcar;
  int type1;
  void* MLcdr;
  int size;
};
typedef struct MLlist MLlist;

struct MLfun {
  int id;
  char* name;
  int isPrimitive;
  int number;
  int MLcounter;
  int size;
  int MAX;
  void** MLenv;
};
typedef struct MLfun MLfun;

int getSize(void* var){
  if (var == NULL)
    return 0;
  int id = ((MLvalue*)var)->id;
  switch(id){
    case 1:
	return ((MLbool*)var)->size;
    case 2:
	return ((MLint*)var)->size;
    case 3:
	return ((MLdouble*)var)->size;
    case 4:
	return ((MLstring*)var)->size;
    case 5:
	return ((MLpair*)var)->size;
    case 6:
	return ((MLlist*)var)->size;
    case 666:
	return ((MLfun*)var)->size;
    default:
	printf("Erreur getSize: no id %d\n", id);
	exit(0);
  }
}

MLfun new_fun(int n, int funnumber){
  MLfun function;
  function.id = 666;
  function.isPrimitive = 0;
  function.number = funnumber;
  function.MLcounter = 0;
  function.MLenv = (void**)malloc(sizeof(void*)*n);
  function.size = sizeof(function);
  return function;
}

void MLaddenv(void** O_env, void* a, MLfun* func){
  int i=0;
  int size = getSize(a);
  func->MLenv = (void**)realloc(func->MLenv,(func->MLcounter+1));
  func->MLenv[func->MLcounter] = malloc(size);
  memcpy(func->MLenv[func->MLcounter], a, size);
}

//Fonctions

MLvalue new_MLvalue(void* val){
  MLvalue value;
  value.val = val;
  return value;
}

MLunit new_MLunit() {
  MLunit unit;
  return unit;
}

MLbool new_MLbool(int val){
  MLbool boolean;
  boolean.id = 1;
  boolean.val = val;
  return boolean;
}

MLint new_MLint(int val){
  MLint integer;
  integer.id = 2;
  integer.val = val;
  integer.size = sizeof(integer);
  return integer;
}


MLdouble new_MLdouble(double val){
  MLdouble doubleval;
  doubleval.id = 3;
  doubleval.val = val;
  doubleval.size = sizeof(doubleval);
  return doubleval;
}

MLstring new_MLstring(char* s){
  MLstring string;
  string.id = 4;
  string.val = s;
  string.size = sizeof(string);
  return string;
}

MLpair new_MLpair(void* a, void* b){
  MLpair pair;
  pair.id = 5;
  MLvalue* va = (MLvalue*)a;
  MLvalue* vb = (MLvalue*)b;
  pair.MLfst = malloc(va->size);
  memcpy(pair.MLfst, a, va->size);
  pair.type1 = ((MLvalue*)a)->id;
  pair.MLsnd = malloc(vb->size);
  pair.type2 = ((MLvalue*)b)->id;
  memcpy(pair.MLsnd, b, vb->size);
  pair.size = sizeof(pair);
  return pair;
}

MLlist new_MLlist(void* a, void* b){
  MLlist list;
  list.id = 6;
  int ida = 0, idb = 0;
  int sizea = getSize(a), sizeb = getSize(b);
  if (a != NULL)
  {
    ida = ((MLvalue*)a)->id;
    list.type1 = ida;
    list.MLcar = malloc(sizea);
    memcpy(list.MLcar, a, sizea);
  }
  else
  {
    list.type1 = 0;
    list.MLcar = NULL;
  }

  if (b != NULL)
  {
    list.MLcdr = malloc(sizeb);
    memcpy(list.MLcdr, b, sizeb);
  }
  else
  {
     list.MLcdr = NULL;
  }
  list.size = sizeof(list);
  return list;
}

MLfun new_MLprimitive(char* n){
  MLfun primitive;
  primitive.name = n;
  primitive.isPrimitive = 1;
  primitive.number = 0;
  return primitive;
}


//arithmetique sur les entiers
MLint MLaddint(MLint x, MLint y){
  return new_MLint(x.val + y.val);
}

MLint MLsubint(MLint x, MLint y){
  return new_MLint(x.val - y.val);
}

MLint MLmulint(MLint x, MLint y){
  return new_MLint(x.val * y.val);
}

MLint MLdivint(MLint x, MLint y){
  return new_MLint(x.val / y.val);
}

//inegalite sur les entiers
MLbool MLltint(MLint x, MLint y){
  if (x.val < y.val)
    return new_MLbool(1);
  return new_MLbool(0);
}

MLbool MLleint(MLint x, MLint y){
  if (x.val <= y.val)
    return new_MLbool(1);
  return new_MLbool(0);
}

MLbool MLgtint(MLint x, MLint y){
  if (x.val > y.val)
    return new_MLbool(1);
  return new_MLbool(0);
}

MLbool MLgeint(MLint x, MLint y){
  if (x.val >= y.val)
    return new_MLbool(1);
  return new_MLbool(0);
}

MLstring MLconcat(MLstring x, MLstring y){
  strcat(x.val, y.val);
  return new_MLstring(x.val);
}

//booleens
MLbool MLtrue(void){
  return new_MLbool(1);
}

MLbool MLfalse(void){
  return new_MLbool(0);
}



//acces aux champs des paires
MLfun MLfst(void){
  return new_MLprimitive("fst");
}

MLfun MLsnd(void){
  return new_MLprimitive("snd");
}

void* MLfst_real(MLpair* p){
  return p->MLfst;
}

void* MLsnd_real(MLpair* p){
  return p->MLsnd;
}


//acces aux champs des listes
MLfun MLhd(void){
  return new_MLprimitive("hd");
}

MLfun MLtl(void){
  return new_MLprimitive("tl");
}

void* MLhd_real(MLlist* l){
  return l->MLcar;
}

void* MLtl_real(MLlist* l){
  return l->MLcdr;
}

MLbool MLequal(void* x, void* y){
  if (((MLbool*)x)->val == ((MLbool*)y)->val)
    return new_MLbool(1);
  return new_MLbool(0);
}

MLunit MLlrp(void){
  return new_MLunit();
}

MLlist MLnil(void){
  return new_MLlist(NULL, NULL);
}

void* invokePrimitive(MLfun* primitive, void* MLparam){
  if (strcmp(primitive->name, "hd")==0) return MLhd_real((MLlist*)MLparam);
  else if (strcmp(primitive->name, "tl")==0) return MLtl_real((MLlist*)MLparam);
  else if (strcmp(primitive->name, "fst")==0) return MLfst_real((MLpair*)MLparam);
  else if (strcmp(primitive->name, "snd")==0) return MLsnd_real((MLpair*)MLparam);
  else
  {
     printf("Unknown primitive %s", primitive->name);
     //exit(0);
  }
}

void temp2(void* var, void* source, int size)
{
  memcpy(var, source, size);

}
void* getValue(void* var, void* catch){
  int size = getSize(catch);
  if (((MLvalue*)catch)->id == 666)
  { 
    var=malloc(size);
    temp2(var, catch, size);
  }
  else
  {
    var=malloc(size);
    temp2(var, catch, size);
  }
  return var;
}

MLunit MLprint(void* x, int type, int cr){
  int type1, type2;
  MLpair* temppair;
  MLlist* templist;
  MLlist* templist2;
  MLfun* tempfun;
  int valint, i;
  double valdouble;
  char* s;

  switch(type){
    case 1:
      valint = ((MLbool*)x)->val;
      break;
    case 2:
      valint = ((MLint*)x)->val;
      break;
    case 3:
      valdouble = ((MLdouble*)x)->val;
      break;
    case 4:
      s = ((MLstring*)x)->val;  
      break;
    case 5:
      temppair = (MLpair*)x;
      type1 = temppair->type1;
      type2 = temppair->type2;
      break;
    case 6:
      templist = (MLlist*)x;
      type1 = templist->type1;
      break;
    case 666:
      tempfun = (MLfun*)x;
      break;
    default:
	printf("Erreur print! Arret programme: %d\n", type);
  }
  switch(type){
    case 1: 
      if(valint)
      	printf("true");
      else
	printf("false");
      break;
    case 2:
      printf("%d", (valint));
      break;
    case 3:
      printf("%lf", (valdouble));
      break;
    case 4:
      printf("\"%s\"", (s));
      break;
    case 5:
      printf("(");
      MLprint(temppair->MLfst, type1, 0);
      printf(",");
      MLprint(temppair->MLsnd, type2, 0);
      printf(")");
      break;
    case 6:
      if(templist->MLcar == NULL)
	printf("[]");
      else
      {
	MLprint(templist->MLcar,type1, 0);
	printf("::");
	MLprint(templist->MLcdr,6, 0);
      }
      break;
    case 666:
      printf("<fun> [");
      for (i=0; i<tempfun->MLcounter; i++)
      {
           MLprint(tempfun->MLenv[i], ((MLvalue*)tempfun->MLenv[i])->id, 0);
      }
      printf("]");
      break;
    default:
      printf("Erreur print!: no type with id %d\n",type);
      exit(1);	
  }
  if (cr)
    printf("\n");
  MLunit unit = MLlrp();
  return unit;
}
