let a = 2;;
let b = 2;;

let l = ("a","b")::("c","d")::[];;
let tll = function x -> hd(tl x);;
let fstp = function x -> fst (tll x);;

let test = function l -> fstp l;;

fstp l;;


