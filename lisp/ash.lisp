;; 論理シフト
;; (ash 値 ビットシフト量)
;;
;; 関数名	機能
;; logand &rest integers	ビットごとの論理積を返す
;; logior &rest integers	ビットごとの論理和を返す
;; logxor &rest integers	ビットごとの排他的論理和を返す
;; lognot integer	ビットごとの論理的な否定を返す
;; logbitp index integer	index 番目のビットが 1 ならば真を返す
;; logcount integer	integer が正ならば 1 のビットの数を、負ならば 0 のビットの数を返す
;; ash integer count	count が正ならば count ビットだけ左シフト、負ならば右
(defparameter val 7)
(print "7(111b) 0 Over  , 1bit Left Shift")
(setq ans (ash val 1))  ; 1bit 左論理シフト (正数を指定したとき)
(print ans)
(print "7(111b) 0 Under , 1bit Right Shift")
(setq ans (ash val -1)) ; 1bit 右論理シフト（負数を指定した時）
(print ans)
;;
;;
(defparameter val -1)
(print "7(111b) 0 Over  , 1bit Left Shift")
(setq ans (ash val 1))  ; 1bit 左論理シフト (正数を指定したとき)
(print ans)
(print "7(111b) 0 Under , 1bit Right Shift")
(setq ans (ash val -1)) ; 1bit 右論理シフト（負数を指定した時）
(print ans)
