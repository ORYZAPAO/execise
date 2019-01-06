;;
;; 変数定義
;;
(defparameter a 101) ; a=101 定義
(defparameter b 99)  ; a=99 定義
(print (+ a b))      ; "200" <--(a:101 + b:99)

(defvar a 3333) ; defvar は代入しない
(print a )      ; "101" a=101+99
;; 
