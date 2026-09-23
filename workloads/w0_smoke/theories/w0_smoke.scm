;; This extracted scheme code relies on some additional macros
;; available at http://www.pps.univ-paris-diderot.fr/~letouzey/scheme
(load "macros_extr.scm")


(define add (lambda (n) (lambda (m) (+ n m))))
  
(define range_from (lambdas (k n)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (n~) `(Cons ,k ,(@ range_from `((lambda (x) (+ x 1)) ,k) n~)))
     n)))
  
(define sum (lambda (l)
  (match l
     ((Nil) `(0))
     ((Cons x xs) (@ add x (sum xs))))))
  
(define run (lambda (n)
  (sum (@ range_from `((lambda (x) (+ x 1)) ,`(0)) n))))

