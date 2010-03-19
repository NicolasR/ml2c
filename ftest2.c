/**
 *  ftest2.c engendre par ml2c 
 */
/**
 * 
 */
#include "runtime.c"
  MLstring a___1;
  MLstring b___3;
  MLpair p___5;
  MLbool test___9;

int main(int argc, char* argv) {

a___1=new_MLstring("1");
{ 
  MLunit bidon___2;
  bidon___2=new_MLunit();
  bidon___2=MLprint( &a___1, a___1.id);
}
b___3=new_MLstring("2");
{ 
  MLunit bidon___4;
  bidon___4=new_MLunit();
  bidon___4=MLprint( &b___3, b___3.id);
}
{ 
  MLstring T___6;
  MLstring T___7;
  T___6=new_MLstring("c");
  T___7=new_MLstring("d");
  p___5=new_MLpair( &T___6, T___6.id, &T___7, T___7.id );
}
{ 
  MLunit bidon___8;
  bidon___8=new_MLunit();
  bidon___8=MLprint( &p___5, p___5.id);
}
{ 
  MLbool T___10;
  { 
    MLstring T___11;
    MLstring T___12;
    T___11=a___1;
    T___12=b___3;
    T___10=MLequal( &T___11, &T___12);
  }
  if (T___10.val)
    { 
      MLbool T___13;
      T___13=MLtrue();
      test___9=T___13;
    }
  else
    { 
      MLbool T___14;
      T___14=MLfalse();
      test___9=T___14;
    }
}
{ 
  MLunit bidon___15;
  bidon___15=new_MLunit();
  bidon___15=MLprint( &test___9, test___9.id);
}
}

// fin du fichier ftest2.c
