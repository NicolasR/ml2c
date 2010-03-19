/**
 *  ftest2.c engendre par ml2c 
 */
/**
 * 
 */
#include "runtime.c"
  MLstring a___1;
  MLstring b___3;
  MLlist l___5;
  MLpair p___11;
  MLbool test___15;

int main(int argc, char* argv) {

a___1=new_MLstring("1");
{ 
  MLunit bidon___2;
  bidon___2=new_MLunit();
  bidon___2=MLprint( &a___1);
}
b___3=new_MLstring("2");
{ 
  MLunit bidon___4;
  bidon___4=new_MLunit();
  bidon___4=MLprint( &b___3);
}
{ 
  MLstring T___6;
  MLlist T___7;
  T___6=new_MLstring("a");
  { 
    MLstring T___8;
    MLlist T___9;
    T___8=new_MLstring("b");
    T___9=MLnil();
    T___7=new_MLlist( &T___8,&T___9);
  }
  l___5=new_MLlist(&T___6,&T___7);
}
{ 
  MLunit bidon___10;
  bidon___10=new_MLunit();
  bidon___10=MLprint( &l___5);
}
{ 
  MLstring T___12;
  MLstring T___13;
  T___12=new_MLstring("c");
  T___13=new_MLstring("d");
  p___11=new_MLpair( &T___12,&T___13);
}
{ 
  MLunit bidon___14;
  bidon___14=new_MLunit();
  bidon___14=MLprint( &p___11);
}
{ 
  MLbool T___16;
  { 
    MLstring T___17;
    MLstring T___18;
    T___17=a___1;
    T___18=b___3;
    T___16=MLequal( &T___17, &T___18);
  }
  if (T___16.val)
    { 
      MLbool T___19;
      T___19=MLtrue();
      test___15=T___19;
    }
  else
    { 
      MLbool T___20;
      T___20=MLfalse();
      test___15=T___20;
    }
}
{ 
  MLunit bidon___21;
  bidon___21=new_MLunit();
  bidon___21=MLprint( &test___15);
}
}

// fin du fichier ftest2.c
