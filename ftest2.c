/**
 *  ftest2.c engendre par ml2c 
 */
#include "runtime.c"

  MLpair a___1;
  MLpair b___5;
  MLpair p___9;
  MLlist q___13;
  MLbool test___19;
  MLdouble test2___26;/**
 * 
 */


int main(int argc, char* argv) {
void* (*tabfun[1])(MLfun*, void*);
tabfun[0] = &invokePrimitive;

{ 
  MLint T___2;
  MLint T___3;
  T___2=new_MLint(2);
  T___3=new_MLint(1);
  a___1=new_MLpair( &T___2, &T___3);
}
{ 
  MLunit bidon___4;
  bidon___4=new_MLunit();
  bidon___4=MLprint( &a___1, a___1.id, 1);
}
{ 
  MLint T___6;
  MLint T___7;
  T___6=new_MLint(2);
  T___7=new_MLint(1);
  b___5=new_MLpair( &T___6, &T___7);
}
{ 
  MLunit bidon___8;
  bidon___8=new_MLunit();
  bidon___8=MLprint( &b___5, b___5.id, 1);
}
{ 
  MLstring T___10;
  MLstring T___11;
  T___10=new_MLstring("c");
  T___11=new_MLstring("d");
  p___9=new_MLpair( &T___10, &T___11);
}
{ 
  MLunit bidon___12;
  bidon___12=new_MLunit();
  bidon___12=MLprint( &p___9, p___9.id, 1);
}
{ 
  MLdouble T___14;
  MLlist T___15;
  T___14=new_MLdouble(2.1);
  { 
    MLdouble T___16;
    MLlist T___17;
    T___16=new_MLdouble(2.2);
    T___17=MLnil();
    T___15=new_MLlist( &T___16, &T___17);
  }
  q___13=new_MLlist( &T___14, &T___15);
}
{ 
  MLunit bidon___18;
  bidon___18=new_MLunit();
  bidon___18=MLprint( &q___13, q___13.id, 1);
}
{ 
  MLbool T___20;
  { 
    MLpair T___21;
    MLpair T___22;
    T___21=a___1;
    T___22=b___5;
    T___20=MLequal( &T___21, &T___22);
  }
  if (T___20.val)
    { 
      MLbool T___23;
      T___23=MLtrue();
      test___19=T___23;
    }
  else
    { 
      MLbool T___24;
      T___24=MLfalse();
      test___19=T___24;
    }
}
{ 
  MLunit bidon___25;
  bidon___25=new_MLunit();
  bidon___25=MLprint( &test___19, test___19.id, 1);
}
{ 
  MLfun T___27;
  MLlist T___28;
  T___27=MLhd();
  T___28=q___13;
  test2___26=*(MLdouble*)(*(tabfun[T___27.number]))( &T___27, &T___28);
}
{ 
  MLunit bidon___29;
  bidon___29=new_MLunit();
  bidon___29=MLprint( &test2___26, test2___26.id, 1);
}
}

// fin du fichier ftest2.c
