;; This extracted scheme code relies on some additional macros
;; available at http://www.pps.univ-paris-diderot.fr/~letouzey/scheme
(load "macros_extr.scm")


(define add (lambda (a) (lambda (b) (+ a b))))
  
(define mul (lambda (a) (lambda (b) (* a b))))
  
(define leb (lambda (a) (lambda (b) (<= a b))))
  
(define ltb (lambda (a) (lambda (b) (< a b))))

(define input_byte (extern (slot 0) i))

(define byte_base 256)

(define key_len 2)

(define reg_len 4)

(define lookup (lambdas (x t)
  (match t
     ((E) `(None))
     ((T _ l k v r)
       (match (@ ltb x k)
          ((True) (@ lookup x l))
          ((False)
            (match (@ ltb k x)
               ((True) (@ lookup x r))
               ((False) `(Some ,v)))))))))
  
(define balance (lambdas (c l k v r)
  (match c
     ((Red) `(T ,`(Red) ,l ,k ,v ,r))
     ((Black)
       (match l
          ((E)
            (match r
               ((E) `(T ,`(Black) ,l ,k ,v ,r))
               ((T c0 b yk yv d)
                 (match c0
                    ((Red)
                      (match b
                         ((E)
                           (match d
                              ((E) `(T ,`(Black) ,l ,k ,v ,r))
                              ((T c1 c~ zk zv d0)
                                (match c1
                                   ((Red) `(T ,`(Red) ,`(T ,`(Black) ,l ,k ,v
                                     ,b) ,yk ,yv ,`(T ,`(Black) ,c~ ,zk ,zv
                                     ,d0)))
                                   ((Black) `(T ,`(Black) ,l ,k ,v ,r))))))
                         ((T c1 b0 yk0 yv0 c~)
                           (match c1
                              ((Red) `(T ,`(Red) ,`(T ,`(Black) ,l ,k ,v ,b0)
                                ,yk0 ,yv0 ,`(T ,`(Black) ,c~ ,yk ,yv ,d)))
                              ((Black)
                                (match d
                                   ((E) `(T ,`(Black) ,l ,k ,v ,r))
                                   ((T c2 c~0 zk zv d0)
                                     (match c2
                                        ((Red) `(T ,`(Red) ,`(T ,`(Black) ,l
                                          ,k ,v ,b) ,yk ,yv ,`(T ,`(Black)
                                          ,c~0 ,zk ,zv ,d0)))
                                        ((Black) `(T ,`(Black) ,l ,k ,v ,r))))))))))
                    ((Black) `(T ,`(Black) ,l ,k ,v ,r))))))
          ((T c0 a xk xv c~)
            (match c0
               ((Red)
                 (match a
                    ((E)
                      (match c~
                         ((E)
                           (match r
                              ((E) `(T ,`(Black) ,l ,k ,v ,r))
                              ((T c1 b yk yv d)
                                (match c1
                                   ((Red)
                                     (match b
                                        ((E)
                                          (match d
                                             ((E) `(T ,`(Black) ,l ,k ,v ,r))
                                             ((T c2 c~0 zk zv d0)
                                               (match c2
                                                  ((Red) `(T ,`(Red) ,`(T
                                                    ,`(Black) ,l ,k ,v ,b)
                                                    ,yk ,yv ,`(T ,`(Black)
                                                    ,c~0 ,zk ,zv ,d0)))
                                                  ((Black) `(T ,`(Black) ,l
                                                    ,k ,v ,r))))))
                                        ((T c2 b0 yk0 yv0 c~0)
                                          (match c2
                                             ((Red) `(T ,`(Red) ,`(T
                                               ,`(Black) ,l ,k ,v ,b0) ,yk0
                                               ,yv0 ,`(T ,`(Black) ,c~0 ,yk
                                               ,yv ,d)))
                                             ((Black)
                                               (match d
                                                  ((E) `(T ,`(Black) ,l ,k ,v
                                                    ,r))
                                                  ((T c3 c~1 zk zv d0)
                                                    (match c3
                                                       ((Red) `(T ,`(Red)
                                                         ,`(T ,`(Black) ,l ,k
                                                         ,v ,b) ,yk ,yv ,`(T
                                                         ,`(Black) ,c~1 ,zk
                                                         ,zv ,d0)))
                                                       ((Black) `(T ,`(Black)
                                                         ,l ,k ,v ,r))))))))))
                                   ((Black) `(T ,`(Black) ,l ,k ,v ,r))))))
                         ((T c1 b yk yv c~0)
                           (match c1
                              ((Red) `(T ,`(Red) ,`(T ,`(Black) ,a ,xk ,xv
                                ,b) ,yk ,yv ,`(T ,`(Black) ,c~0 ,k ,v ,r)))
                              ((Black)
                                (match r
                                   ((E) `(T ,`(Black) ,l ,k ,v ,r))
                                   ((T c2 b0 yk0 yv0 d)
                                     (match c2
                                        ((Red)
                                          (match b0
                                             ((E)
                                               (match d
                                                  ((E) `(T ,`(Black) ,l ,k ,v
                                                    ,r))
                                                  ((T c3 c~1 zk zv d0)
                                                    (match c3
                                                       ((Red) `(T ,`(Red)
                                                         ,`(T ,`(Black) ,l ,k
                                                         ,v ,b0) ,yk0 ,yv0
                                                         ,`(T ,`(Black) ,c~1
                                                         ,zk ,zv ,d0)))
                                                       ((Black) `(T ,`(Black)
                                                         ,l ,k ,v ,r))))))
                                             ((T c3 b1 yk1 yv1 c~1)
                                               (match c3
                                                  ((Red) `(T ,`(Red) ,`(T
                                                    ,`(Black) ,l ,k ,v ,b1)
                                                    ,yk1 ,yv1 ,`(T ,`(Black)
                                                    ,c~1 ,yk0 ,yv0 ,d)))
                                                  ((Black)
                                                    (match d
                                                       ((E) `(T ,`(Black) ,l
                                                         ,k ,v ,r))
                                                       ((T c4 c~2 zk zv d0)
                                                         (match c4
                                                            ((Red) `(T
                                                              ,`(Red) ,`(T
                                                              ,`(Black) ,l ,k
                                                              ,v ,b0) ,yk0
                                                              ,yv0 ,`(T
                                                              ,`(Black) ,c~2
                                                              ,zk ,zv ,d0)))
                                                            ((Black) `(T
                                                              ,`(Black) ,l ,k
                                                              ,v ,r))))))))))
                                        ((Black) `(T ,`(Black) ,l ,k ,v ,r))))))))))
                    ((T c1 a0 xk0 xv0 b)
                      (match c1
                         ((Red) `(T ,`(Red) ,`(T ,`(Black) ,a0 ,xk0 ,xv0 ,b)
                           ,xk ,xv ,`(T ,`(Black) ,c~ ,k ,v ,r)))
                         ((Black)
                           (match c~
                              ((E)
                                (match r
                                   ((E) `(T ,`(Black) ,l ,k ,v ,r))
                                   ((T c2 b0 yk yv d)
                                     (match c2
                                        ((Red)
                                          (match b0
                                             ((E)
                                               (match d
                                                  ((E) `(T ,`(Black) ,l ,k ,v
                                                    ,r))
                                                  ((T c3 c~0 zk zv d0)
                                                    (match c3
                                                       ((Red) `(T ,`(Red)
                                                         ,`(T ,`(Black) ,l ,k
                                                         ,v ,b0) ,yk ,yv ,`(T
                                                         ,`(Black) ,c~0 ,zk
                                                         ,zv ,d0)))
                                                       ((Black) `(T ,`(Black)
                                                         ,l ,k ,v ,r))))))
                                             ((T c3 b1 yk0 yv0 c~0)
                                               (match c3
                                                  ((Red) `(T ,`(Red) ,`(T
                                                    ,`(Black) ,l ,k ,v ,b1)
                                                    ,yk0 ,yv0 ,`(T ,`(Black)
                                                    ,c~0 ,yk ,yv ,d)))
                                                  ((Black)
                                                    (match d
                                                       ((E) `(T ,`(Black) ,l
                                                         ,k ,v ,r))
                                                       ((T c4 c~1 zk zv d0)
                                                         (match c4
                                                            ((Red) `(T
                                                              ,`(Red) ,`(T
                                                              ,`(Black) ,l ,k
                                                              ,v ,b0) ,yk ,yv
                                                              ,`(T ,`(Black)
                                                              ,c~1 ,zk ,zv
                                                              ,d0)))
                                                            ((Black) `(T
                                                              ,`(Black) ,l ,k
                                                              ,v ,r))))))))))
                                        ((Black) `(T ,`(Black) ,l ,k ,v ,r))))))
                              ((T c2 b0 yk yv c~0)
                                (match c2
                                   ((Red) `(T ,`(Red) ,`(T ,`(Black) ,a ,xk
                                     ,xv ,b0) ,yk ,yv ,`(T ,`(Black) ,c~0 ,k
                                     ,v ,r)))
                                   ((Black)
                                     (match r
                                        ((E) `(T ,`(Black) ,l ,k ,v ,r))
                                        ((T c3 b1 yk0 yv0 d)
                                          (match c3
                                             ((Red)
                                               (match b1
                                                  ((E)
                                                    (match d
                                                       ((E) `(T ,`(Black) ,l
                                                         ,k ,v ,r))
                                                       ((T c4 c~1 zk zv d0)
                                                         (match c4
                                                            ((Red) `(T
                                                              ,`(Red) ,`(T
                                                              ,`(Black) ,l ,k
                                                              ,v ,b1) ,yk0
                                                              ,yv0 ,`(T
                                                              ,`(Black) ,c~1
                                                              ,zk ,zv ,d0)))
                                                            ((Black) `(T
                                                              ,`(Black) ,l ,k
                                                              ,v ,r))))))
                                                  ((T c4 b2 yk1 yv1 c~1)
                                                    (match c4
                                                       ((Red) `(T ,`(Red)
                                                         ,`(T ,`(Black) ,l ,k
                                                         ,v ,b2) ,yk1 ,yv1
                                                         ,`(T ,`(Black) ,c~1
                                                         ,yk0 ,yv0 ,d)))
                                                       ((Black)
                                                         (match d
                                                            ((E) `(T
                                                              ,`(Black) ,l ,k
                                                              ,v ,r))
                                                            ((T c5 c~2 zk zv
                                                              d0)
                                                              (match c5
                                                                 ((Red) `(T
                                                                   ,`(Red)
                                                                   ,`(T
                                                                   ,`(Black)
                                                                   ,l ,k ,v
                                                                   ,b1) ,yk0
                                                                   ,yv0 ,`(T
                                                                   ,`(Black)
                                                                   ,c~2 ,zk
                                                                   ,zv ,d0)))
                                                                 ((Black) `(T
                                                                   ,`(Black)
                                                                   ,l ,k ,v
                                                                   ,r))))))))))
                                             ((Black) `(T ,`(Black) ,l ,k ,v
                                               ,r))))))))))))))
               ((Black)
                 (match r
                    ((E) `(T ,`(Black) ,l ,k ,v ,r))
                    ((T c1 b yk yv d)
                      (match c1
                         ((Red)
                           (match b
                              ((E)
                                (match d
                                   ((E) `(T ,`(Black) ,l ,k ,v ,r))
                                   ((T c2 c~0 zk zv d0)
                                     (match c2
                                        ((Red) `(T ,`(Red) ,`(T ,`(Black) ,l
                                          ,k ,v ,b) ,yk ,yv ,`(T ,`(Black)
                                          ,c~0 ,zk ,zv ,d0)))
                                        ((Black) `(T ,`(Black) ,l ,k ,v ,r))))))
                              ((T c2 b0 yk0 yv0 c~0)
                                (match c2
                                   ((Red) `(T ,`(Red) ,`(T ,`(Black) ,l ,k ,v
                                     ,b0) ,yk0 ,yv0 ,`(T ,`(Black) ,c~0 ,yk
                                     ,yv ,d)))
                                   ((Black)
                                     (match d
                                        ((E) `(T ,`(Black) ,l ,k ,v ,r))
                                        ((T c3 c~1 zk zv d0)
                                          (match c3
                                             ((Red) `(T ,`(Red) ,`(T
                                               ,`(Black) ,l ,k ,v ,b) ,yk ,yv
                                               ,`(T ,`(Black) ,c~1 ,zk ,zv
                                               ,d0)))
                                             ((Black) `(T ,`(Black) ,l ,k ,v
                                               ,r))))))))))
                         ((Black) `(T ,`(Black) ,l ,k ,v ,r)))))))))))))

(define ins (lambdas (x vx t)
  (match t
     ((E) `(T ,`(Red) ,`(E) ,x ,vx ,`(E)))
     ((T c l k v r)
       (match (@ ltb x k)
          ((True) (@ balance c (@ ins x vx l) k v r))
          ((False)
            (match (@ ltb k x)
               ((True) (@ balance c l k v (@ ins x vx r)))
               ((False) `(T ,c ,l ,x ,vx ,r)))))))))
  
(define make_black (lambda (t)
  (match t
     ((E) `(E))
     ((T _ l k v r) `(T ,`(Black) ,l ,k ,v ,r)))))

(define insert (lambdas (x vx t) (make_black (@ ins x vx t))))

(define assert (lambdas (x t)
  (match (@ lookup x t)
     ((Some c) `(Pair ,(@ insert x `((lambda (x) (+ x 1)) ,c) t)
       ,`((lambda (x) (+ x 1)) ,c)))
     ((None) `(Pair ,t ,`(0))))))

(define read_u16 (lambda (pos)
  (@ add (@ mul (input_byte pos) byte_base)
    (input_byte `((lambda (x) (+ x 1)) ,pos)))))

(define load (lambdas (k pos t)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) t)
     (lambda (k~)
     (@ load k~ (@ add pos reg_len)
       (@ insert (read_u16 pos) (read_u16 (@ add pos key_len)) t)))
     k)))
  
(define answer (lambdas (k pos t)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (k~)
     (match (@ assert (read_u16 pos) t)
        ((Pair t~ a) `(Cons ,a ,(@ answer k~ (@ add pos key_len) t~)))))
     k)))
  
(define run (lambda (n)
  (let ((q (input_byte `(0))))
    (@ answer q `((lambda (x) (+ x 1)) ,`(0))
      (@ load n (@ add `((lambda (x) (+ x 1)) ,`(0)) (@ mul key_len q)) `(E))))))

