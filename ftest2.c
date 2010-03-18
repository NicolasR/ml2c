/**
 *  ftest2.c engendre par ml2c 
 */
/**
 * 
 */

  MLstring a___1;
  MLstring b___3;
  MLbool test___5;

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
  MLbool T___6;
  { 
    MLstring T___7;
    MLstring T___8;
    T___7=a___1;
    T___8=b___3;
    T___6=MLequal( &T___7, &T___8);
  }
  if (T___6.val)
    { 
      MLbool T___9;
      T___9=MLtrue();
      test___5=T___9;
    }
  else
    { 
      MLbool T___10;
      T___10=MLfalse();
      test___5=T___10;
    }
}
{ 
  MLunit bidon___11;
  bidon___11=new_MLunit();
  bidon___11=MLprint( &test___5);
}
}

// fin du fichier ftest2.c
