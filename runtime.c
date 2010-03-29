#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//A supprimer??
struct MLvalue {
  int id;
  void* val;
/*  void* MLcar;
  void* MLcdr;
  void* MLfst;
  void* MLsnd;*/
};
typedef struct MLvalue MLvalue;

struct MLunit {
  int val;
};
typedef struct MLunit MLunit;

struct MLbool {
  int id;
  int val;
};
typedef struct MLbool MLbool;

struct MLint {
  int id;
  int val;
};
typedef struct MLint MLint;

struct MLdouble {
  int id;
  double val;
};
typedef struct MLdouble MLdouble;

struct MLstring {
  int id;
  char* val;
};
typedef struct MLstring MLstring;

struct MLpair {
  int id;
  void* MLfst;
  int type1;
  void* MLsnd;
  int type2;
};
typedef struct MLpair MLpair;


struct MLlist {
  int id;
  void* MLcar;
  int type1;
  void* MLcdr;
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
  MLfun function;// = malloc(sizeof *function + sizeof(void*[n]));
  function.id = 666;
  function.isPrimitive = 0;
  function.number = funnumber;
  function.MLcounter = 0;
  function.size = 0;
  function.MLenv = (void**)malloc(sizeof(void*)*n);
  return function;
}

void MLaddenv(void** O_env, void* a, MLfun* func){
  int i=0;
  void** MLenv = malloc(sizeof(void*)*(func->size+1));
  for (i; i< func->MLcounter; i++){
    MLenv[i]=O_env[i];
  }
  MLenv[func->MLcounter]=a;
  func->MLcounter++;
}

/*
astract class MLfun extends MLvalue
{
  public int MLcounter;
  protected MLvalue[] MLenv;

  MLfun(){MLcounter=0;}
  MLfun(int n){MLcounter=0;MLenv = new MLvalue[n];}

  public  void  MLaddenv(MLvalue []O_env,MLvalue a)
   { for (int i=0; i< MLcounter; i++) {MLenv[i]=O_env[i];}
     MLenv[MLcounter]=a;MLcounter++;}

 abstract public MLvalue invoke(MLvalue x);

  public void print(){
     System.out.print("<fun> [");
     for (int i=0; i< MLcounter; i++)
           MLenv[i].print();
     System.out.print("]");
  }

}
*/

struct MLprimitive {
  int id;
  char* name;
};
typedef struct MLprimitive MLprimitive;




/*
class MLprimitive extends MLfun { 

  String name="";

  MLprimitive(String n){name=n;}

  public MLvalue invoke(MLvalue l) {
    if (name.equals("hd")) return MLruntime.MLhd_real((MLlist)l);
    else if (name.equals("tl")) return MLruntime.MLtl_real((MLlist)l);
    else if (name.equals("fst")) return MLruntime.MLfst_real((MLpair)l);
    else if (name.equals("snd")) return MLruntime.MLsnd_real((MLpair)l);
    else {System.err.println("Unknown primitive "+name); return l;}
  } 

}
*/

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

MLpair new_MLpair(void* a, int type1, void* b, int type2){
  MLpair pair;
  pair.id = 5;
  pair.MLfst = a;
  pair.type1 = type1;
  pair.MLsnd = b;
  pair.type2 = type2;
  return pair;
}

MLlist new_MLlist(void* a, int type1, void* b){
  MLlist list;
  list.id = 6;
  list.MLcar = a;
  list.type1 = type1;
  list.MLcdr = b;
  return list;
}

MLfun new_MLprimitive(char* n){
  MLfun primitive;
  primitive.name = n;
  primitive.isPrimitive = 1;
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
  return new_MLint(x.val - y.val);
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
  if (((MLvalue*)x)->val == ((MLvalue*)y)->val)
    return new_MLbool(1);
  return new_MLbool(0);
}

MLunit MLlrp(void){
  return new_MLunit();
}

MLlist MLnil(void){
  return new_MLlist(NULL, 0, NULL);
}

void* invokePrimitive(MLprimitive p, void* l, char* cd){
  void (*c)() = NULL;
  c = &cd;
  if (strcmp(p.name, "hd")==0) return MLhd_real((MLlist*)l);
  else if (strcmp(p.name, "tl")==0) return MLtl_real((MLlist*)l);
  else if (strcmp(p.name, "fst")==0) return MLfst_real((MLpair*)l);
  else if (strcmp(p.name, "snd")==0) return MLsnd_real((MLpair*)l);
  else
  {
     printf("Unknown primitive %s", p.name);
     exit(0);
  }
}

MLunit MLprint(void* x, int type, int cr){
  int type1, type2;
  MLpair* temppair;
  MLlist* templist;
  int valint;
  double valdouble;
  char* s;
//printf("type: %d\n", type);
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
    default:
	printf("Erreur print! Arret programme\n");
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
    default:
      printf("Erreur print! Arret programme\n");
      exit(1);	
  }
  if (cr)
    printf("\n");
  MLunit unit = MLlrp();
  return unit;
}
