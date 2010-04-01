(************************************************************************
 *                                                                      *
 *                       MASTER STL M1 anne'e 2005/06                   *
 *                                                                      *
 *                     Cours Compilation Avanceels                      *
 *                                                                      *
 *                       Compilation -> Langage intermediaire           *
 *                                                                      *
 *                         partie de ml2java                            *
 *                                                                      *
 ************************************************************************
 *                                                                      *
 *   prodjava.ml  : traducteur LI_instr -> texte Java                   *
 *                                                                      *
 *   version : 0.1           12/04/06                                   *
 *                                                                      *
 *   auteur : Emmanuel Chailloux                                        *
 *                                                                      *
 ************************************************************************)

open Types;;
open Typeur;;
open Env_typeur;;
open Env_trans;;
open Langinter;;

let ifuncn = ref 1
let ifuncn2 = ref 1
let needtocast = ref []
let funs = ref []
let isInvokeReal = ref false
let isReturn = ref false

(* des symboles globaux bien utiles par la suite *)

let compiler_name = ref "ml2c";;
let object_suffix = ref ".c";;

(* des valeurs pour certains symboles de env_trans *)

pair_symbol:=",";;
cons_symbol:="::";;
ref_symbol:="ref";;

(* l'environnement initial du traducteur en liaison avec la Runtime *)

let build (s,equiv)  = 
  let t = 
      try List.assoc s !initial_typing_env  
      with Not_found -> 
        failwith ("building initial_trans_env : for symbol : "^s)
  in (s,(equiv,type_instance t));;

(*
let get_param_type fun_t =  match fun_t with 
  Fun_type (Pair_type (t1,t2),tr) -> [t1;t2],tr
| Fun_type ( t1,tr) -> [t1],tr
| _ -> failwith "get_param_type"
;;
*)

initial_special_env := 
 List.map build [
      "hd","MLhd()";
      "tl","MLtl()";
      "fst","MLfst()";
      "snd","MLsnd()"
];;


initial_trans_env:= 

let alpha = max_unknown () in
[",",("new_MLpair", Fun_type (Pair_type (alpha,alpha),
                                    Pair_type (alpha,alpha)))]@
["::",("new_MLlist", Fun_type (Pair_type (alpha,alpha),
                                    List_type (alpha)))]@

(
List.map build 
     ["true" ,"MLtrue()";
      "false","MLfalse()";
      "+","MLaddint";
      "-","MLsubint";
      "*","MLmulint";
      "/","MLdivint";
      "=","MLequal";
      "<","MLltint";
      "<=","MLleint";
      ">","MLgtint";
      ">=","MLgeint";
      "^", "MLconcat"
      
]
)
;;

(* des fonctions d'I/O *)

let output_channel = ref stdout;;
let change_output_channel oc = output_channel := oc;;

let shift_string = String.make 256 ' ';;
let out s = output_string !output_channel s;;
let out_start s nb = out ("\n"^(String.sub shift_string 0 (2*nb))^s);;
let out_end s nb = out ("\n"^(String.sub shift_string 0 nb)^"}\n");;
let out_line s = out (s^"\n");;

let out_before (fr,sd,nb,tr,v,isPrim) = 
  if sd<>"" then out_start (sd^"=") nb
  else if fr then
    begin 
      if (not isPrim) then
      begin
	out_start ("void* return_value;") nb;
      	out_start ("return_value = &") nb
      	(*out_start ("return return_value;") nb;*)
      end
      else
      begin
	out_start ("void* return_value;") nb;
	out_start (tr^"prim_value = ") nb
      end;
    end;;


let out_after  (fr,sd,nb,tr,isPrim) = 
  if sd<>"" then 
  begin
      out ";";
      if fr then 
      begin
	(*if (not isPrim) then*)
	(*  if (not isPrim) then*)
	    out ("return "^sd^";")
	(*  else
	  begin
	    out_line("return_value = &prim_value");
	    out("return return_value;");
	  end*)
	(*else
	begin
	  out_line(tr^"prim_value;");
	  out_line("return_value = &prim_value");
	  out("return return_value;");
	end*)
      end
  end
  else if fr then 
  begin
    out ";";
    if (isPrim) then
    	out_start ("return_value = &prim_value;") nb;
    out_start ("return return_value;") nb;
  end;;


(* des fonctions utilitaires pour commenter un peu la production *)

let header_main  s = 
  List.iter out 
   ["/**\n";
    " *  "^ s ^ ".c" ^ " engendre par ml2c \n";
    " */\n"]
;;

let footer_main  s = 
  List.iter out
   ["// fin du fichier " ^ s ^ ".c\n"]
;;

let header_one  s = 
   List.iter out
     [];;


let footer_one  s = ();;

let header_two  s = 
  List.iter out
  [ "/**\n";
    " * \n";
    " */\n";
    (*"class "^s^" {\n"*)
  ]
;;

let footer_two  s = ();;

let header_three  s = 
  List.iter out
  [  "\n\n";
     "int main(int argc, char* argv) {\n"]
;;

let footer_three  s = 
  List.iter out
  [ "\n}\n\n"]
;;

(* on recuoere le  type pour une declaration precise *)

let string_of_const_type ct = match ct with   
  INTTYPE    -> "MLint "
| FLOATTYPE  -> "MLdouble "
| STRINGTYPE -> "MLstring "
| BOOLTYPE   -> "MLbool "
| UNITTYPE   -> "MLunit "
;;
 
let rec string_of_type typ = match typ with 
  CONSTTYPE t -> string_of_const_type t
| ALPHA    ->  (*"MLvalue "*)"void* " 
| PAIRTYPE -> "MLpair "
| LISTTYPE -> "MLlist "
| FUNTYPE  -> "MLfun "
| REFTYPE  -> "MLref "
;;


let prod_global_var instr = match instr with
  VAR (v,t) -> out_start ((string_of_type t)^v^";") 1 
| FUNCTION (ns,t1,ar,(p,t2), instr) ->
    out_start ("MLfun "^ns^"= {666, \"\", 0, "^(string_of_int !ifuncn2)^", 0, 0, "^(string_of_int ar)^", NULL};") 1;
    ifuncn2 := !ifuncn2 + 1
| _ -> ()
;;

let prod_two  ast_li = 
  List.iter prod_global_var ast_li
;;

let get_param_type lv = 
  List.map (function (VAR(name,typ)) -> typ 
        | _ -> failwith "get_param_type" ) lv;;


let prod_const c = match c with 
  INT i -> out ("new_MLint("^(string_of_int i)^")")
| FLOAT f -> out ("new_MLdouble("^(string_of_float f)^")")
| BOOL b  -> out ("new_MLbool("^(if b then "1" else "0")^")")
| STRING s -> out ("new_MLstring("^"\""^s^"\""^")")
| EMPTYLIST -> out ("MLnil()")
| UNIT ->      out ("new_MLunit()")
;;

let rec prod_local_var (fr,sd,nb) (v,t) = 
  out_start ((*"MLvalue "*)(string_of_type t)^v^";") nb;;

let rec prod_instr (fr,sd,nb) instr  = match instr with 
  CONST c -> 
	     if c = EMPTYLIST then
	     	out_before (fr,sd,nb,"MLlist ","", true)
	     else
	     	out_before (fr,sd,nb,"","", false);		
             prod_const c;
	     if c = EMPTYLIST then
             	out_after (fr,sd,nb,"",true)
	     else
		out_after (fr,sd,nb,"",false)
| VAR (v,t) 
          -> if (nb = 0) && ( sd = "") then ()
             else 
             begin
	       let var_type = string_of_type t in
               out_before (fr,sd,nb,var_type,v, false);
	       (*if (!isReturn = false) then*)
	       begin
		(* On cast les variables quand c'est nécessaire *)
		if (List.exists (fun x -> x = v) !needtocast) then
		  out ("*("^var_type^"*)");               
		out v;
               out_after (fr,sd,nb,var_type,false)
	       end           
             end
| IF(i1,i2,i3) -> 
              out_start "if (" nb;
              (*out ("(");*)
              prod_instr (false,"",nb) i1 ;
              (*out ")";
              out".MLaccess()";*)
              out ".val)";
              prod_instr (fr,sd,nb+1) i2 ;
              out_start "else" (nb);
              prod_instr (fr,sd,nb+1) i3
| RETURN i -> isReturn := true;
	      prod_instr (true,"",nb) i;
	      isReturn := false;
| AFFECT (v,i) -> prod_instr (false,v,nb) i
| BLOCK(l,i) -> out_start "{ " nb;
                  List.iter (fun (v,t,i) -> prod_local_var (false,"",nb+1) 
                                           (v,t)) l;
                  List.iter (fun (v,t,i) -> prod_instr (false,v,nb+1) i) l;
                  prod_instr (fr,sd,nb+1) i;
                out_start "}" nb
             
| APPLY(i1,i2) -> 
   out_before(fr,sd,nb,"","", false);
     (*out ("((MLfun)");
     prod_instr (false,"",nb) i1;
     out ")";
     out ".invoke(";*)
     if (!isInvokeReal) then
	out ("invoke( &")
     else
     begin
     	out ("(*(tabfun[");
	prod_instr (false,"",nb) i1;
	out (".number]))( &");
     end;
     prod_instr (false,"",nb) i1;
     out ", &";
     prod_instr (false,"",nb) i2;     
     out")";
   out_after(fr,sd,nb,"",false)
| PRIM ((name,typ),instrl) ->
   let ltp = get_param_type instrl in 
   (*out (name^"( ("^(string_of_type (List.hd ltp))^")");*)
   begin
     match name with (* A COMPLETER??? *)
       | "MLprint" ->
	   begin
	     out_before (fr,sd,nb,"","", false);
	     out (name^"( &");
	     prod_instr (false,"",nb+1) (List.hd instrl);
	     List.iter2 (fun x y -> out (", &");
			   prod_instr (false,"",nb+1) x) 
               (List.tl instrl) (List.tl ltp);
	     out(", ");
	     prod_instr (false,"",nb+1) (List.hd instrl);
	     out (".id, 1)") ;
	     out_after(fr,sd,nb,"",false)
	   end
       | "new_MLpair" -> 
	  begin
	     out_before (fr,sd,nb,"MLpair ","", true);
	     out (name^"( &");
	     prod_instr (false,"",nb+1) (List.hd instrl);
	     (*out (", ");*)
	     (*prod_instr (false,"",nb+1) (List.hd instrl);
	     out (".id");*)
	     List.iter2 (fun x y -> out (", &");
			   prod_instr (false,"",nb+1) x) 
               (List.tl instrl) (List.tl ltp);
	     (*out (", ");*)
	     (*List.iter2 (fun x y -> prod_instr (false,"",nb+1) x) 
               (List.tl instrl) (List.tl ltp);*)
	     (*out (".id )") ;*)out (")") ;
	     out_after(fr,sd,nb,"MLpair ",true)
	   end
       | "new_MLlist" ->
	   begin
	     out_before (fr,sd,nb,"MLlist ","", true);
	     out (name^"( &");
	     prod_instr (false,"",nb+1) (List.hd instrl);
	     (*out (", ");
	     prod_instr (false,"",nb+1) (List.hd instrl);
	     out (".id");*)
	     List.iter2 (fun x y -> out (", &");
			   prod_instr (false,"",nb+1) x) 
               (List.tl instrl) (List.tl ltp);
	     out (")");
	     out_after(fr,sd,nb,"MLlist ",true)
	   end
       | "MLgtint"
       | "MLgeint"
       | "MLltint"
       | "MLleint" ->
	   begin
	     (*out ("MLbool prim_value = "^name^"( &");*)
	     out_before (fr,sd,nb,"MLbool ","", true);
	     out (name^"( ");
	     prod_instr (false,"",nb+1) (List.hd instrl);
	     List.iter2 (fun x y -> out (", ");
			   prod_instr (false,"",nb+1) x) 
               (List.tl instrl) (List.tl ltp);
	     out ")" ;
	     out_after(fr,sd,nb,"MLbool ",true);
	   end
       | "MLequal" ->
	   begin
	     (*out ("MLbool prim_value = "^name^"( &");*)
	     out_before (fr,sd,nb,"MLbool ","", true);
	     out (name^"( &");
	     prod_instr (false,"",nb+1) (List.hd instrl);
	     List.iter2 (fun x y -> out (", &");
			   prod_instr (false,"",nb+1) x) 
               (List.tl instrl) (List.tl ltp);
	     out ")" ;
	     out_after(fr,sd,nb,"MLbool ",true);
	   end

       | "MLaddint"
       | "MLsubint"
       | "MLmulint"
       | "MLdivint" ->
	   begin
	     (*out ("MLint prim_value = "^name^"( &");*)
	     out_before (fr,sd,nb,"MLint ","", true);
 	     out (name^"( ");
	     prod_instr (false,"",nb+1) (List.hd instrl);
	     List.iter2 (fun x y -> out (", ");
			   prod_instr (false,"",nb+1) x) 
               (List.tl instrl) (List.tl ltp);
	     out ")" ;
	     out_after(fr,sd,nb,"MLint ",true);
	   end
       | _ ->
	   begin
	     out (name^"( ");
	     prod_instr (false,"",nb+1) (List.hd instrl);
	     List.iter2 (fun x y -> out (", ");
			   prod_instr (false,"",nb+1) x) 
               (List.tl instrl) (List.tl ltp);
	     out ")" ;
	     out_after(fr,sd,nb,"",true)
	   end
   end

| FUNCTION _ -> ()
;;

let fun_header fn cn  = 
  List.iter out 
    ["\n\n";
     "/**\n";
     " *  de'claration de la fonction "^fn^"\n";
     " *    vue comme la classe : "^cn^"\n";
     " */ \n"]
;;

let prod_invoke cn  ar = 
  let fnumber = (string_of_int !ifuncn) in
  List.iter out_line 
     ["void* invokef"^fnumber^"(MLfun* func, void* MLparam){";
      "    func->MAX = "^(string_of_int ar)^";";
      "    if (func->MLcounter == (func->MAX-1)) {";
      "	      void* (*f)(MLfun*, void*) = &invokef"^fnumber^";";
     ];

  out ("      return invoke_real"^fnumber^"(");
  for i=0 to ar-2 do 
    out ("func->MLenv["^(string_of_int i)^"], ")
  done;
  out_line "MLparam, f);";     

  List.iter out_line 
     ["    }";
      "    else {";
      "      MLaddenv(func->MLenv, MLparam, func);";
      "      func->MLcounter = func->MLcounter + 1;
	     return func;";
      "    }";
      "  }"
      ];
  funs := List.append !funs (("invokef"^fnumber)::[]);
  ifuncn := !ifuncn + 1
;;

let prod_invoke_fun cn ar t lp instr = 

  out_start ("void* invoke_real"^(string_of_int !ifuncn)^"(") 1;
  needtocast := (List.hd lp)::!needtocast;
  out ("void* "^(List.hd lp));
  List.iter (fun x -> out (", void* "^x); needtocast := x::!needtocast;) (List.tl lp);
  out_line ", void* (*invokef)(MLfun*, void*)) {";
  isInvokeReal := true;
  prod_instr (true,"",2) instr;
  isInvokeReal := false;
  out_start "}" 1;
  out_line "";
;;

let prod_fun instr = match instr with 
  FUNCTION (ns,t1,ar,(lp,t2),instr) -> 
      let class_name = "MLfun_"^ns in
      fun_header ns class_name ;
      (*out_line ("class "^class_name^" extends MLfun {");
      out_line "";
      out_line ("  private static int MAX = "^(string_of_int ar)^";") ;
      out_line "";
      out_line ("  "^class_name^"() {super();}") ;
      out_line "";
      out_line ("  "^class_name^"(int n) {super(n);}") ;    *)  
      prod_invoke_fun class_name ar t1 lp instr;
      out_line "";
      prod_invoke "MLfun" ar;
      out_line "";

      out_line ""(*;           
      out_line "}";
      out_line ("// fin de la classe "^class_name)*)
      
      
|  _ -> ()
;;


let prod_one  ast_li = 
  List.iter prod_fun ast_li
;;




let prod_three  ast_li = 
 List.iter (prod_instr  (false,"",0) ) ast_li
;;



let prod_file filename ast_li = 
  let obj_name = filename ^ !object_suffix in 
  let oc = open_out obj_name in 
  change_output_channel oc;  
  module_name:=filename;
  try 
    header_main  filename;
	out_line("#include \"runtime.c\"");
    header_one  filename;
    prod_two  ast_li; (* On veut que les vars globales soient tout en haut *)
    prod_one  ast_li;

    

    footer_one  filename;
    header_two  filename;

    footer_two  filename;
    header_three  filename;
(**DECLARATION DE TABLEAU *)
    out_line ("void* (*tabfun["^(string_of_int ((List.length !funs)+1))^"])(MLfun*, void*);");
    out_line ("tabfun[0] = &invokePrimitive;");
    let i = ref 1 in
    List.iter (fun x -> 
	out ("tabfun["^(string_of_int !i)^"]");
	out_line (" = &"^x^";");
	i := !i+1) !funs;
    prod_three  ast_li;
    footer_three  filename;
    footer_main  filename;

    close_out oc
  with x -> close_out oc; raise x;;



