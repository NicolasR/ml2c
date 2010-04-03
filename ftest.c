/**
 *  ftest.c engendre par ml2c 
 */
#include "runtime.c"
void* (**tabfun)(MLfun*, void*);
  MLfun null___1= {666, "", 0, 1, 0, 32, 1, NULL};
  MLfun g___8= {666, "", 0, 2, 0, 32, 1, NULL};
  MLfun h___12= {666, "", 0, 3, 0, 32, 2, NULL};
  MLfun q___17= {666, "", 0, 4, 0, 32, 1, NULL};
  MLfun v___25= {666, "", 0, 5, 0, 32, 1, NULL};
  MLfun w___27= {666, "", 0, 6, 0, 32, 2, NULL};
  MLfun map___37= {666, "", 0, 7, 0, 32, 2, NULL};
  MLfun iter___57= {666, "", 0, 8, 0, 32, 2, NULL};
  MLfun inter___71= {666, "", 0, 9, 0, 32, 2, NULL};
  MLfun mult___87= {666, "", 0, 10, 0, 32, 2, NULL};
  MLlist i___92;
  MLlist l___98;
  MLfun fd___106;
  MLfun ig___108;
  MLlist bi___114;
  MLfun ik___118;
  MLlist b___122;
  MLfun umap___126= {666, "", 0, 11, 0, 32, 2, NULL};
  MLlist value___146;

/**
 *  de'claration de la fonction null___1
 *    vue comme la classe : MLfun_null___1
 */ 

  void* invoke_real1(void* l___2, void* (*invokef)(MLfun*, void*)) {

    { 
      MLbool T___3;
      { 
        MLlist T___4;
        MLlist T___5;
        T___4=*(MLlist *)l___2;
        T___5=MLnil();
        T___3=MLequal( &T___4, &T___5);
      }
      if (T___3.val)
        { 
          MLbool T___6;
          T___6=MLtrue();
          void* return_value;
          return_value = &T___6;
          return return_value;
        }
      else
        { 
          MLbool T___7;
          T___7=MLfalse();
          void* return_value;
          return_value = &T___7;
          return return_value;
        }
    }
  }

void* invokef1(MLfun* func, void* MLparam){
    func->MAX = 1;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef1;
      return invoke_real1(MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction g___8
 *    vue comme la classe : MLfun_g___8
 */ 

  void* invoke_real2(void* x___9, void* (*invokef)(MLfun*, void*)) {

    { 
      MLlist T___10;
      MLlist T___11;
      T___10=*(MLlist *)x___9;
      T___11=MLnil();
      void* return_value;
      MLbool prim_value = MLequal( &T___10, &T___11);
      return_value = &prim_value;
      return return_value;
    }
  }

void* invokef2(MLfun* func, void* MLparam){
    func->MAX = 1;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef2;
      return invoke_real2(MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction h___12
 *    vue comme la classe : MLfun_h___12
 */ 

  void* invoke_real3(void* x___13, void* y___14, void* (*invokef)(MLfun*, void*)) {

    { 
      void* T___15;
      MLlist T___16;
      T___15=*(void* *)x___13;
      void* temp = x___13;
      if (((MLvalue*)temp)->id == 666)
      {
        T___15= malloc(((MLfun*)temp)->size);
	memcpy(T___15, temp, ((MLfun*)temp)->size);
      }
      else
      {
      	T___15= malloc(((MLvalue*)temp)->size);
      	memcpy(T___15, temp, ((MLvalue*)temp)->size);
      }
      T___16=*(MLlist *)y___14;
      void* return_value;
      MLlist prim_value = new_MLlist( T___15, &T___16);
      return_value = &prim_value;
      return return_value;
    }
  }

void* invokef3(MLfun* func, void* MLparam){
    func->MAX = 2;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef3;
      return invoke_real3(func->MLenv[0], MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction q___17
 *    vue comme la classe : MLfun_q___17
 */ 

  void* invoke_real4(void* x___18, void* (*invokef)(MLfun*, void*)) {

    { 
      void* T___19;
      MLlist T___22;
      { 
        MLfun T___20;
        MLlist T___21;
        T___20=MLhd();
        T___21=*(MLlist *)x___18;
	void* temp = (*tabfun[T___20.number])( &T___20, &T___21);
        if (((MLvalue*)temp)->id == 666)
        {
          T___19= malloc(((MLfun*)temp)->size);
	  memcpy(T___19, temp, ((MLfun*)temp)->size);
        }
        else
        {
      	  T___19= malloc(((MLvalue*)temp)->size);
      	  memcpy(T___19, temp, ((MLvalue*)temp)->size);
        }
      }
      { 
        MLfun T___23;
        MLlist T___24;
        T___23=MLtl();
        T___24=*(MLlist *)x___18;
        T___22=*(MLlist*)(*tabfun[T___23.number])( &T___23, &T___24);
      }
      void* return_value;
      MLpair prim_value = new_MLpair( T___19, &T___22);
      return_value = &prim_value;
      return return_value;
    }
  }

void* invokef4(MLfun* func, void* MLparam){
    func->MAX = 1;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef4;
      return invoke_real4(MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction v___25
 *    vue comme la classe : MLfun_v___25
 */ 

  void* invoke_real5(void* x___26, void* (*invokef)(MLfun*, void*)) {

    void* return_value;
    MLlist prim_value = MLnil();
    return_value = &prim_value;
    return return_value;
  }

void* invokef5(MLfun* func, void* MLparam){
    func->MAX = 1;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef5;
      return invoke_real5(MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction w___27
 *    vue comme la classe : MLfun_w___27
 */ 

  void* invoke_real6(void* l___28, void* x___29, void* (*invokef)(MLfun*, void*)) {

    { 
      MLbool T___30;
      { 
        MLlist T___31;
        MLlist T___32;
        T___31=*(MLlist *)l___28;
        T___32=MLnil();
        T___30=MLequal( &T___31, &T___32);
      }
      if (T___30.val)
        { 
          MLlist T___33;
          T___33=MLnil();
          void* return_value;
          return_value = &T___33;
          return return_value;
        }
      else
        { 
          MLlist T___34;
          { 
            void* T___35;
            MLlist T___36;
            void* temp = x___29;
            if (((MLvalue*)temp)->id == 666)
            {
              T___35= malloc(((MLfun*)temp)->size);
	      memcpy(T___35, temp, ((MLfun*)temp)->size);
            }
            else
            {
      	      T___35= malloc(((MLvalue*)temp)->size);
      	      memcpy(T___35, temp, ((MLvalue*)temp)->size);
            }
            T___36=MLnil();
            T___34=new_MLlist( T___35, &T___36);
          }
          void* return_value;
          return_value = &T___34;
          return return_value;
        }
    }
  }

void* invokef6(MLfun* func, void* MLparam){
    func->MAX = 2;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef6;
      return invoke_real6(func->MLenv[0], MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction map___37
 *    vue comme la classe : MLfun_map___37
 */ 

  void* invoke_real7(void* f___38, void* l___39, void* (*invokef)(MLfun*, void*)) {

    { 
      MLbool T___40;
      { 
        MLfun T___41;
        MLlist T___42;
        T___41=null___1;
        T___42=*(MLlist *)l___39;
        T___40=*(MLbool*)(*tabfun[T___41.number])( &T___41, &T___42);
      }
      if (T___40.val)
        { 
          MLlist T___43;
          T___43=MLnil();
          void* return_value;
          return_value = &T___43;
          return return_value;
        }
      else
        { 
          MLlist T___44;
          { 
            void* T___45;
            MLlist T___50;
            { 
              MLfun T___46;
              void* T___47;
              T___46=*(MLfun *)f___38;
              { 
                MLfun T___48;
                MLlist T___49;
                T___48=MLhd();
                T___49=*(MLlist *)l___39;
                T___47=(*tabfun[T___48.number])( &T___48, &T___49);
              }
	      void* temp;
              temp=(*tabfun[T___46.number])( &T___46, T___47);
	      if (((MLvalue*)temp)->id == 666)
              {
	      	T___45 = malloc(((MLfun*)temp)->size);
	      	memcpy(T___45, temp, ((MLfun*)temp)->size);
  	      }
	      else
	      {
		T___45 = malloc(((MLvalue*)temp)->size);
	      	memcpy(T___45, temp, ((MLvalue*)temp)->size);
              }
            }
            { 
              MLfun T___51;
              MLlist T___54;
              { 
                MLfun T___52;
                MLfun T___53;
                T___52=map___37;
                T___53=*(MLfun *)f___38;
                T___51=*(MLfun*)(*tabfun[T___52.number])( &T___52, &T___53);
              }
              { 
                MLfun T___55;
                MLlist T___56;
                T___55=MLtl();
                T___56=*(MLlist *)l___39;
                T___54=*(MLlist*)(*tabfun[T___55.number])( &T___55, &T___56);
              }
              T___50=*(MLlist*)(*tabfun[T___51.number])( &T___51, &T___54);
            }
            T___44=new_MLlist( T___45, &T___50);
          }
          void* return_value;
          return_value = &T___44;
          return return_value;
        }
    }
  }

void* invokef7(MLfun* func, void* MLparam){
    func->MAX = 2;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef7;
      return invoke_real7(func->MLenv[0], MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction iter___57
 *    vue comme la classe : MLfun_iter___57
 */ 

  void* invoke_real8(void* f___58, void* l___59, void* (*invokef)(MLfun*, void*)) {

    { 
      MLbool T___60;
      { 
        MLfun T___61;
        MLlist T___62;
        T___61=null___1;
        T___62=*(MLlist *)l___59;
        T___60=*(MLbool*)(*tabfun[T___61.number])( &T___61, &T___62);
      }
      if (T___60.val)
        { 
          MLlist T___63;
          T___63=MLnil();
          void* return_value;
          return_value = &T___63;
          return return_value;
        }
      else
        { 
          MLlist T___64;
          { 
            MLfun T___65;
            void* T___66;
            T___65=iter___57;
            { 
              MLfun T___67;
              MLlist T___68;
              T___67=*(MLfun *)f___58;
              { 
                MLfun T___69;
                MLlist T___70;
                T___69=MLtl();
                T___70=*(MLlist *)l___59;
                T___68=*(MLlist*)(*tabfun[T___69.number])( &T___69, &T___70);
              }
	      void* temp = (*tabfun[T___67.number])( &T___67, &T___68);
	      if (((MLvalue*)temp)->id == 666)
	      {
              	T___66= malloc(((MLfun*)temp)->size);
	      	memcpy(T___66, temp, ((MLfun*)temp)->size);
   	      }
	      else
	      {
              	T___66= malloc(((MLvalue*)temp)->size);
	      	memcpy(T___66, temp, ((MLvalue*)temp)->size);
   	      }
            }
            T___64=*(MLlist*)(*tabfun[T___65.number])( &T___65, T___66);
          }
          void* return_value;
          return_value = &T___64;
          return return_value;
        }
    }
  }

void* invokef8(MLfun* func, void* MLparam){
    func->MAX = 2;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef8;
      return invoke_real8(func->MLenv[0], MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction inter___71
 *    vue comme la classe : MLfun_inter___71
 */ 

  void* invoke_real9(void* a___72, void* b___73, void* (*invokef)(MLfun*, void*)) {

    { 
      MLbool T___74;
      { 
        MLint T___75;
        MLint T___76;
        T___75=*(MLint *)a___72;
        T___76=*(MLint *)b___73;
        T___74=MLgtint( T___75, T___76);
      }
      if (T___74.val)
        { 
          MLlist T___77;
          T___77=MLnil();
          void* return_value;
          return_value = &T___77;
          return return_value;
        }
      else
        { 
          MLlist T___78;
          { 
            MLint T___79;
            MLlist T___80;
            T___79=*(MLint *)a___72;
            { 
              MLfun T___81;
              MLint T___86;
              { 
                MLfun T___82;
                MLint T___83;
                T___82=inter___71;
                { 
                  MLint T___84;
                  MLint T___85;
                  T___84=*(MLint *)a___72;
                  T___85=new_MLint(1);
                  T___83=MLaddint( T___84, T___85);
                }
                T___81=*(MLfun*)(*tabfun[T___82.number])( &T___82, &T___83);
              }
              T___86=*(MLint *)b___73;
              T___80=*(MLlist*)(*tabfun[T___81.number])( &T___81, &T___86);
            }
            T___78=new_MLlist( &T___79, &T___80);
          }
          void* return_value;
          return_value = &T___78;
          return return_value;
        }
    }
  }

void* invokef9(MLfun* func, void* MLparam){
    func->MAX = 2;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef9;
      return invoke_real9(func->MLenv[0], MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);

      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction mult___87
 *    vue comme la classe : MLfun_mult___87
 */ 

  void* invoke_real10(void* x___88, void* y___89, void* (*invokef)(MLfun*, void*)) {

    { 
      MLint T___90;
      MLint T___91;
      T___90=*(MLint *)x___88;
      T___91=*(MLint *)y___89;
      void* return_value;
      MLint prim_value = MLmulint( T___90, T___91);
      return_value = &prim_value;
      return return_value;
    }
  }

void* invokef10(MLfun* func, void* MLparam){
    func->MAX = 2;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef10;
      return invoke_real10(func->MLenv[0], MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }




/**
 *  de'claration de la fonction umap___126
 *    vue comme la classe : MLfun_umap___126
 */ 

  void* invoke_real11(void* l___127, void* x___128, void* (*invokef)(MLfun*, void*)) {

    { 
      MLbool T___129;
      { 
        MLfun T___130;
        MLlist T___131;
        T___130=null___1;
        T___131=*(MLlist *)l___127;
        T___129=*(MLbool*)(*tabfun[T___130.number])( &T___130, &T___131);
      }
      if (T___129.val)
        { 
          MLlist T___132;
          T___132=MLnil();
          void* return_value;
          return_value = &T___132;
          return return_value;
        }
      else
        { 
          MLlist T___133;
          { 
            void* T___134;
            MLlist T___139;
            { 
              MLfun T___135;
              void* T___138;
              { 
                MLfun T___136;
                MLlist T___137;
                T___136=MLhd();
                T___137=*(MLlist *)l___127;
                T___135=*(MLfun*)(*tabfun[T___136.number])( &T___136, &T___137);
              }
	      void* temp = x___128;
	      if (((MLvalue*)temp)->id == 666)
	      {
	      	T___138 = malloc( ((MLfun*)temp)->size);
	      	memcpy(T___138, temp, ((MLfun*)temp)->size);
	      }
	      else
	      {
	      	T___138 = malloc( ((MLvalue*)temp)->size);
	      	memcpy(T___138, temp, ((MLvalue*)temp)->size);
	      }
	      temp = (*tabfun[T___135.number])( &T___135, T___138);
	      if (((MLvalue*)temp)->id == 666)
	      {
	      	T___134 = malloc( ((MLfun*)temp)->size);
	      	memcpy(T___134, temp, ((MLfun*)temp)->size);
	      }
	      else
	      {
	      	T___134 = malloc( ((MLvalue*)temp)->size);
	      	memcpy(T___134, temp, ((MLvalue*)temp)->size);
	      }
            }
            { 
              MLfun T___140;
              void* T___145;
              { 
                MLfun T___141;
                MLlist T___142;
                T___141=umap___126;
                { 
                  MLfun T___143;
                  MLlist T___144;
                  T___143=MLtl();
                  T___144=*(MLlist *)l___127;
                  T___142=*(MLlist*)(*tabfun[T___143.number])( &T___143, &T___144);
                }
                T___140=*(MLfun*)(*tabfun[T___141.number])( &T___141, &T___142);
              }
	      void* temp = x___128;
	      if (((MLvalue*)temp)->id == 666)
	      {
              	T___145=malloc(((MLfun*)temp)->size);
   	      	memcpy(T___145, temp, ((MLfun*)temp)->size);
	      }
	      else
	      {
              	T___145=malloc(((MLvalue*)temp)->size);
   	      	memcpy(T___145, temp, ((MLvalue*)temp)->size);
	      }
              T___139=*(MLlist*)(*tabfun[T___140.number])( &T___140, T___145);
            }
            T___133=new_MLlist( T___134, &T___139);
          }
          void* return_value;
          return_value = &T___133;
          return return_value;
        }
    }
  }

void* invokef11(MLfun* func, void* MLparam){
    func->MAX = 2;
    if (func->MLcounter == (func->MAX-1)) {
	      void* (*f)(MLfun*, void*) = &invokef11;
      return invoke_real11(func->MLenv[0], MLparam, f);
    }
    else {
      MLaddenv(func->MLenv, MLparam, func);
      func->MLcounter = func->MLcounter + 1;
	     return func;
    }
  }


/**
 * 
 */


int main(int argc, char* argv) {
tabfun = malloc(sizeof(*tabfun)*12);
tabfun[0] = &invokePrimitive;
tabfun[1] = &invokef1;
tabfun[2] = &invokef2;
tabfun[3] = &invokef3;
tabfun[4] = &invokef4;
tabfun[5] = &invokef5;
tabfun[6] = &invokef6;
tabfun[7] = &invokef7;
tabfun[8] = &invokef8;
tabfun[9] = &invokef9;
tabfun[10] = &invokef10;
tabfun[11] = &invokef11;

{ 
  MLfun T___93;
  MLint T___96;
  { 
    MLfun T___94;
    MLint T___95;
    T___94=inter___71;
    T___95=new_MLint(1);
    T___93=*(MLfun*)(*(tabfun[T___94.number]))( &T___94, &T___95);
  }
  T___96=new_MLint(10);
  i___92=*(MLlist*)(*(tabfun[T___93.number]))( &T___93, &T___96);
}
{ 
  MLunit bidon___97;
  bidon___97=new_MLunit();
  bidon___97=MLprint( &i___92, i___92.id, 1);
}
{ 
  MLfun T___99;
  MLlist T___104;
  { 
    MLfun T___100;
    MLfun T___101;
    T___100=map___37;
    { 
      MLfun T___102;
      MLint T___103;
      T___102=mult___87;
      T___103=new_MLint(5);
      T___101=*(MLfun*)(*(tabfun[T___102.number]))( &T___102, &T___103);
    }
    T___99=*(MLfun*)(*(tabfun[T___100.number]))( &T___100, &T___101);
  }
  T___104=i___92;
  l___98=*(MLlist*)(*(tabfun[T___99.number]))( &T___99, &T___104);
}
{ 
  MLunit bidon___105;
  bidon___105=new_MLunit();
  bidon___105=MLprint( &l___98, l___98.id, 1);
}
fd___106=map___37;
{ 
  MLunit bidon___107;
  bidon___107=new_MLunit();
  bidon___107=MLprint( &fd___106, fd___106.id, 1);
}
{ 
  MLfun T___109;
  MLfun T___110;
  T___109=map___37;
  { 
    MLfun T___111;
    MLint T___112;
    T___111=mult___87;
    T___112=new_MLint(5);
    T___110=*(MLfun*)(*(tabfun[T___111.number]))( &T___111, &T___112);
  }
  ig___108=*(MLfun*)(*(tabfun[T___109.number]))( &T___109, &T___110);
}
{ 
  MLunit bidon___113;
  bidon___113=new_MLunit();
  bidon___113=MLprint( &ig___108, ig___108.id, 1);
}
{ 
  MLfun T___115;
  MLlist T___116;
  T___115=ig___108;
  T___116=l___98;
  bi___114=*(MLlist*)(*(tabfun[T___115.number]))( &T___115, &T___116);
}
{ 
  MLunit bidon___117;
  bidon___117=new_MLunit();
  bidon___117=MLprint( &bi___114, bi___114.id, 1);
}
{ 
  MLfun T___119;
  MLfun T___120;
  T___119=map___37;
  T___120=mult___87;
  ik___118=*(MLfun*)(*(tabfun[T___119.number]))( &T___119, &T___120);
}
{ 
  MLunit bidon___121;
  bidon___121=new_MLunit();
  bidon___121=MLprint( &ik___118, ik___118.id, 1);
}
{ 
  MLfun T___123;
  MLlist T___124;
  T___123=ik___118;
  T___124=i___92;
  b___122=*(MLlist*)(*(tabfun[T___123.number]))( &T___123, &T___124);
}
{ 
  MLunit bidon___125;
  bidon___125=new_MLunit();
  bidon___125=MLprint( &b___122, b___122.id, 1);
}
{ 
  MLfun T___147;
  MLint T___150;
  { 
    MLfun T___148;
    MLlist T___149;
    T___148=umap___126;
    T___149=b___122;
    T___147=*(MLfun*)(*(tabfun[T___148.number]))( &T___148, &T___149);
  }
  T___150=new_MLint(10);
  value___146=*(MLlist*)(*(tabfun[T___147.number]))( &T___147, &T___150);
}
{ 
  MLunit bidon___151;
  bidon___151=new_MLunit();
  bidon___151=MLprint( &value___146, value___146.id, 1);
}
}

// fin du fichier ftest.c
