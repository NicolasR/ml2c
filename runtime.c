#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//A supprimer??
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
  int size;
  if (((MLvalue*)a)->id == 666)
  {
    //printf("Oui\n");
    //printf("%d\n", ((MLfun*)a)->id);
    size = ((MLfun*)a)->size;
  }
  else
    size =((MLvalue*)a)->size;
  //printf("[debug]size: %d\n", size);
  /*if (((MLvalue*)a)->id == 2)
  	printf("addenv: %d\n", ((MLint*)a)->val);*/
  func->MLenv = (void**)realloc(func->MLenv, /*sizeof(func->MLenv)**/(func->MLcounter+1));
  func->MLenv[func->MLcounter] = malloc(size);
  memcpy(func->MLenv[func->MLcounter], a, size);
  /*if (((MLvalue*)a)->id == 2)
	printf("verif addenv: %d\n", ((MLint*)func->MLenv[func->MLcounter])->val);*/
  func->size = sizeof(*func);
}

/*struct MLprimitive {
  int id;
  char* name;
};
typedef struct MLprimitive MLprimitive;*/


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
  return doubleval;
}

MLstring new_MLstring(char* s){
  MLstring string;
  string.id = 4;
  string.val = s;
  return string;
}

MLpair new_MLpair(void* a/*, int type1*/, void* b/*, int type2*/){
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
  return pair;
}

MLlist new_MLlist(void* a/*, int type1*/, void* b){
  MLlist list;
  list.id = 6;
  MLvalue* va = (MLvalue*)a;
  MLlist* vb = (MLlist*)b;
  if (a != NULL && va->id != 0)
  {
    
    //printf("[debug]id_new_list_a: %d\n", va->id);
    fflush(stdout);
    list.type1 = va->id;
    //printf("[debug]typelistcar: %d\n", list.type1);
    list.MLcar = malloc(va->size);
    memcpy(list.MLcar, a, va->size);
    //printf("[debug]car: %d", ((MLint*)list.MLcar)->val);
    //printf("Testidlistcar: %d\n", ((MLint*)list.MLcar)->val);
  }
  else
  {
    //printf("[debug]typelistcar: NULL\n");
    list.type1 = 0;
    list.MLcar = NULL;
  }

  if (b != NULL && vb->id != 0)
  {
    list.MLcdr = malloc(vb->size);
    memcpy(list.MLcdr, b, vb->size);
  }
  else
  {
     list.MLcdr = NULL;
  }
	//test = (MLint*) temp->MLcar; 
	//printf("Testidlistcar: %d\n", ((MLint*)temp->MLcar)->id);
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

MLunit MLprint(void* x, int type, int cr){
  int type1, type2;
  MLpair* temppair;
  MLlist* templist;
MLlist* templist2;
  MLfun* tempfun;
  int valint, i;
  double valdouble;
  char* s;
//printf("[debug]type: %d\n", type);
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
        //printf("debug: booleen\n");
      if(valint)
      	printf("true");
      else
	printf("false");
      break;
    case 2:
	//printf("debug: entier\n");
      printf("%d", (valint));
      break;
    case 3:
	//printf("debug: double\n");
      printf("%lf", (valdouble));
      break;
    case 4:
	//printf("debug: chaine\n");
      printf("\"%s\"", (s));
      break;
    case 5:
      //printf("debug: paire\n");
      printf("(");
      //MLvalue* t = temp->MLfst;
	//printf("debug type: %d", type1);
      MLprint(temppair->MLfst, type1, 0);
      printf(",");
      MLprint(temppair->MLsnd, type2, 0);
      printf(")");
      break;
    case 6:
	//printf("debug: liste\n");
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
	//printf("debug: liste\n");
      printf("<fun> [");
      //printf("counterprint: %d", tempfun->MAX);
      for (i=0; i<tempfun->MLcounter; i++)
      {
           MLprint(tempfun->MLenv[i], ((MLvalue*)tempfun->MLenv[i])->id, 0);
      }
      printf("]");
      break;
    default:
      printf("Erreur print! Arret programme: %d\n",type);
      exit(1);	
  }
  if (cr)
    printf("\n");
  MLunit unit = MLlrp();
  return unit;
}
