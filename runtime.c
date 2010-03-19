#include <string.h>
#include <stdio.h>

struct MLvalue {
  int id;
  void* val;
  void* MLcar;
  void* MLcdr;
  void* MLfst;
  void* MLsnd;
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

//A def Union? Supprimer id?
struct MLpair {
  int id;
  void* MLfst;
  void* MLsnd;
};
typedef struct MLpair MLpair;

//A def
struct MLlist {
  int id;
  void* MLcar;
  void* MLcdr;
};
typedef struct MLlist MLlist;

struct MLfun {
  int id;
  //???
};
typedef struct MLfun MLfun;


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
  void* fct;
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

/*
MLdouble new_MLdouble(double val){
  MLdouble double;
  double.id = 3;
  double.val = val;
  return double;
}*/

MLstring new_MLstring(char* s){
  MLstring string;
  string.id = 4;
  string.val = s;
  return string;
}

MLpair new_MLpair(void* a, void* b){
  MLpair pair;
  pair.id = 5;
  pair.MLfst = a;
  pair.MLsnd = b;
  return pair;
}

MLlist new_MLlist(void* a, void* b){
  MLlist list;
  list.id = 6;
  list.MLcar = a;
  list.MLcdr = b;
  return list;
}

MLprimitive new_MLprimitive(char* n){
  MLprimitive primitive;
  primitive.name = n;
  //if (strcmp(n, "fst") == 0) A VOIR
  //  primitive.fct = (void*)MLfst_real(MLpair);
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
MLprimitive MLfst(void){
  return new_MLprimitive("fst");
}

MLprimitive MLsnd(void){
  return new_MLprimitive("snd");
}

void* MLfst_real(MLpair p){
  return p.MLfst;
}

void* MLsnd_real(MLpair p){
  return p.MLsnd;
}


//acces aux champs des listes
MLprimitive MLhd(void){
  return new_MLprimitive("hd");
}

MLprimitive MLtl(void){
  return new_MLprimitive("tl");
}

void* MLhd_real(MLlist l){
  return l.MLcar;
}

void* MLtl_real(MLlist l){
  return l.MLcdr;
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
  return new_MLlist(NULL,NULL);
}

MLunit MLprint(void* x){

  printf("passe ici\n");
  MLvalue* temp = (MLvalue*) x;
  switch(temp->id){
    case 1: 
      if(temp->val)
      	printf("true\n");
      else
	printf("false\n");
      break;
    case 2:
      printf("%d\n", (temp->val));
      break;
    case 3:
      printf("%lf\n", (temp->val));
      break;
    case 4:
      printf("%s\n", (temp->val));
      break;
    case 5:
      printf("(");
      MLprint(temp->MLfst);
      printf(",");
      MLprint(temp->MLsnd);
      printf(")");
      break;
    case 6:
      if(temp->MLcar == NULL)
	printf("[]\n");
      else
      {
	MLprint(temp->MLcar);
	printf("::");
	MLprint(temp->MLcdr);
      }
      break;
    default:
      printf("Erreur Affichage! Arret programme\n");
      //exit();	
  }
  MLunit unit = MLlrp();
  return unit;
}
