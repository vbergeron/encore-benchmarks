;; This extracted scheme code relies on some additional macros
;; available at http://www.pps.univ-paris-diderot.fr/~letouzey/scheme
(load "macros_extr.scm")


(define add (lambda (a) (lambda (b) (+ a b))))
  
(define eqb (lambda (a) (lambda (b) (= a b))))
  
(define firstn (lambdas (n l)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (n0)
     (match l
        ((Nil) `(Nil))
        ((Cons a l0) `(Cons ,a ,(@ firstn n0 l0)))))
     n)))
  
(define skipn (lambdas (n l)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) l)
     (lambda (n0) (match l
                     ((Nil) `(Nil))
                     ((Cons _ l0) (@ skipn n0 l0))))
     n)))
  
(define input_byte (extern (slot 0) i))

(define read_bytes (lambdas (pos n)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (n~) `(Cons ,(input_byte pos)
     ,(@ read_bytes `((lambda (x) (+ x 1)) ,pos) n~)))
     n)))
  
(define max_tries 3)

(define max_puk_tries 10)

(define puk_len 8)

(define ins_verify 32)

(define ins_change 36)

(define ins_unblock 44)

(define ins_select 164)

(define digits_eqb (lambdas (a b)
  (match a
     ((Nil) (match b
               ((Nil) `(True))
               ((Cons _ _) `(False))))
     ((Cons x a~)
       (match b
          ((Nil) `(False))
          ((Cons y b~)
            (match (@ eqb x y)
               ((True) (@ digits_eqb a~ b~))
               ((False) `(False)))))))))
  
(define step (lambdas (s c)
  (match c
     ((Verify g)
       ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
          (lambda (_) `(Pair ,`(Mk_state
          ,(match s
              ((Mk_state pin _ _ _ _) pin))
          ,(match s
              ((Mk_state _ puk _ _ _) puk))
          ,`(0) ,(match s
                    ((Mk_state _ _ _ puk_tries _) puk_tries))
          ,`(False)) ,`(Blocked)))
          (lambda (t)
          (match (@ digits_eqb g (match s
                                    ((Mk_state pin _ _ _ _) pin)))
             ((True) `(Pair ,`(Mk_state
               ,(match s
                   ((Mk_state pin _ _ _ _) pin))
               ,(match s
                   ((Mk_state _ puk _ _ _) puk))
               ,max_tries ,(match s
                              ((Mk_state _ _ _ puk_tries _) puk_tries))
               ,`(True)) ,`(Ok)))
             ((False) `(Pair ,`(Mk_state
               ,(match s
                   ((Mk_state pin _ _ _ _) pin))
               ,(match s
                   ((Mk_state _ puk _ _ _) puk))
               ,t ,(match s
                      ((Mk_state _ _ _ puk_tries _) puk_tries))
               ,`(False)) ,`(Wrong ,t)))))
          (match s
             ((Mk_state _ _ tries _ _) tries))))
     ((Change p)
       (match (match s
                 ((Mk_state _ _ _ _ auth) auth))
          ((True) `(Pair ,`(Mk_state ,p
            ,(match s
                ((Mk_state _ puk _ _ _) puk))
            ,(match s
                ((Mk_state _ _ tries _ _) tries))
            ,(match s
                ((Mk_state _ _ _ puk_tries _) puk_tries))
            ,`(True)) ,`(Ok)))
          ((False) `(Pair ,s ,`(Denied)))))
     ((Unblock k p)
       ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
          (lambda (_) `(Pair ,s ,`(Blocked)))
          (lambda (t)
          (match (@ digits_eqb k (match s
                                    ((Mk_state _ puk _ _ _) puk)))
             ((True) `(Pair ,`(Mk_state ,p
               ,(match s
                   ((Mk_state _ puk _ _ _) puk))
               ,max_tries ,max_puk_tries ,`(False)) ,`(Ok)))
             ((False) `(Pair ,`(Mk_state
               ,(match s
                   ((Mk_state pin _ _ _ _) pin))
               ,(match s
                   ((Mk_state _ puk _ _ _) puk))
               ,(match s
                   ((Mk_state _ _ tries _ _) tries))
               ,t ,`(False)) ,`(Wrong ,t)))))
          (match s
             ((Mk_state _ _ _ puk_tries _) puk_tries))))
     ((Select) `(Pair ,`(Mk_state ,(match s
                                      ((Mk_state pin _ _ _ _) pin))
       ,(match s
           ((Mk_state _ puk _ _ _) puk))
       ,(match s
           ((Mk_state _ _ tries _ _) tries))
       ,(match s
           ((Mk_state _ _ _ puk_tries _) puk_tries))
       ,`(False)) ,`(Ok)))
     ((Unknown) `(Pair ,s ,`(BadIns))))))

(define decode_cmd (lambdas (ins data)
  (match (@ eqb ins ins_verify)
     ((True) `(Verify ,data))
     ((False)
       (match (@ eqb ins ins_change)
          ((True) `(Change ,data))
          ((False)
            (match (@ eqb ins ins_unblock)
               ((True) `(Unblock ,(@ firstn puk_len data)
                 ,(@ skipn puk_len data)))
               ((False)
                 (match (@ eqb ins ins_select)
                    ((True) `(Select))
                    ((False) `(Unknown)))))))))))

(define code (lambda (r)
  (match r
     ((Ok) `(0))
     ((Wrong n)
       (@ add `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
         ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0))))) n))
     ((Blocked) `((lambda (x) (+ x 1)) ,`(0)))
     ((Denied) `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0))))
     ((BadIns) `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
       ,`((lambda (x) (+ x 1)) ,`(0))))))))

(define process (lambdas (k s pos)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (k~)
     (let ((ins (input_byte pos)))
       (let ((lc (input_byte `((lambda (x) (+ x 1)) ,pos))))
         (match (@ step s
                  (@ decode_cmd ins
                    (@ read_bytes `((lambda (x) (+ x 1))
                      ,`((lambda (x) (+ x 1)) ,pos)) lc)))
            ((Pair s~ r) `(Cons ,(code r)
              ,(@ process k~ s~
                 (@ add `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,pos))
                   lc))))))))
     k)))
  
(define init `(Mk_state ,`(Cons ,`((lambda (x) (+ x 1)) ,`(0)) ,`(Cons
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0))) ,`(Cons
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
  ,`(0)))) ,`(Cons ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0))))) ,`(Nil)))))
  ,`(Cons ,`((lambda (x) (+ x 1)) ,`(0)) ,`(Cons ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`(0))) ,`(Cons ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0)))) ,`(Cons
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`(0))))) ,`(Cons ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`(0)))))) ,`(Cons ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0))))))) ,`(Cons
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`(0)))))))) ,`(Cons ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
  ,`((lambda (x) (+ x 1)) ,`(0))))))))) ,`(Nil))))))))) ,max_tries
  ,max_puk_tries ,`(False)))

(define run (lambda (n) (@ process n init `(0))))

