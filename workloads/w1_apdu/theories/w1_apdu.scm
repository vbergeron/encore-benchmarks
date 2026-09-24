;; This extracted scheme code relies on some additional macros
;; available at http://www.pps.univ-paris-diderot.fr/~letouzey/scheme
(load "macros_extr.scm")


(define length (lambda (l)
  (match l
     ((Nil) `(0))
     ((Cons _ l~) `((lambda (x) (+ x 1)) ,(length l~))))))
  
(define add (lambda (a) (lambda (b) (+ a b))))
  
(define mul (lambda (a) (lambda (b) (* a b))))
  
(define add0 (lambda (a) (lambda (b) (+ a b))))
  
(define mul0 (lambda (a) (lambda (b) (* a b))))
  
(define eqb (lambda (a) (lambda (b) (= a b))))
  
(define leb (lambda (a) (lambda (b) (<= a b))))
  
(define ltb (lambda (a) (lambda (b) (< a b))))

(define even (lambda (a) (= (int-and a 1) 0)))
  
(define odd (lambda (a) (= (int-and a 1) 1)))

(define divmod (lambdas (x y q u)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Pair ,q ,u))
     (lambda (x~)
     ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
        (lambda (_) (@ divmod x~ y `((lambda (x) (+ x 1)) ,q) y))
        (lambda (u~) (@ divmod x~ y q u~))
        u))
     x)))
  
(define div (lambda (a) (lambda (b) (int-div a b))))

(define div2 (lambda (a) (int-shr a 1)))
  
(define bitwise (lambdas (op n a b)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(0))
     (lambda (n~)
     (@ add0
       (match (@ op (odd a) (odd b))
          ((True) `((lambda (x) (+ x 1)) ,`(0)))
          ((False) `(0)))
       (@ mul0 `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0)))
         (@ bitwise op n~ (div2 a) (div2 b)))))
     n)))
  
(define land (lambda (a) (lambda (b) (int-and a b))))

(define fold_right (lambdas (f a0 l)
  (match l
     ((Nil) a0)
     ((Cons b l0) (@ f b (@ fold_right f a0 l0))))))
  
(define input_byte (extern (slot 0) i))

(define read_bytes (lambdas (pos n)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (n~) `(Cons ,(input_byte pos)
     ,(@ read_bytes `((lambda (x) (+ x 1)) ,pos) n~)))
     n)))
  
(define tag_mask 31)

(define constructed_bit 32)

(define high_bit 128)

(define len_one 129)

(define len_two 130)

(define byte_base 256)

(define split_n (lambdas (n l)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Some ,`(Pair ,`(Nil) ,l)))
     (lambda (n~)
     (match l
        ((Nil) `(None))
        ((Cons x t)
          (match (@ split_n n~ t)
             ((Some p)
               (match p
                  ((Pair a b) `(Some ,`(Pair ,`(Cons ,x ,a) ,b)))))
             ((None) `(None))))))
     n)))
  
(define parse_tag (lambda (l)
  (match l
     ((Nil) `(None))
     ((Cons b r)
       (match (@ eqb (@ land b tag_mask) tag_mask)
          ((True)
            (match r
               ((Nil) `(None))
               ((Cons c r~)
                 (match (@ ltb c high_bit)
                    ((True) `(Some ,`(Pair ,(@ add (@ mul b byte_base) c)
                      ,r~)))
                    ((False) `(None))))))
          ((False) `(Some ,`(Pair ,b ,r))))))))

(define parse_len (lambda (l)
  (match l
     ((Nil) `(None))
     ((Cons b r)
       (match (@ ltb b high_bit)
          ((True) `(Some ,`(Pair ,b ,r)))
          ((False)
            (match (@ eqb b len_one)
               ((True)
                 (match r
                    ((Nil) `(None))
                    ((Cons c r~)
                      (match (@ leb high_bit c)
                         ((True) `(Some ,`(Pair ,c ,r~)))
                         ((False) `(None))))))
               ((False)
                 (match (@ eqb b len_two)
                    ((True)
                      (match r
                         ((Nil) `(None))
                         ((Cons c1 l0)
                           (match l0
                              ((Nil) `(None))
                              ((Cons c2 r~)
                                (match (@ ltb `(0) c1)
                                   ((True) `(Some ,`(Pair
                                     ,(@ add (@ mul c1 byte_base) c2) ,r~)))
                                   ((False) `(None))))))))
                    ((False) `(None)))))))))))

(define first_byte (lambda (t)
  (match (@ ltb t byte_base)
     ((True) t)
     ((False) (@ div t byte_base)))))

(define constructed (lambda (t)
  (@ eqb (@ land (first_byte t) constructed_bit) constructed_bit)))

(define dec_seq (lambdas (fuel l)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(None))
     (lambda (f)
     (match l
        ((Nil) `(Some ,`(Nil)))
        ((Cons _ _)
          (match (@ dec_one f l)
             ((Some p)
               (match p
                  ((Pair t rest)
                    (match (@ dec_seq f rest)
                       ((Some ts) `(Some ,`(Cons ,t ,ts)))
                       ((None) `(None))))))
             ((None) `(None))))))
     fuel)))
  
(define dec_one (lambdas (fuel l)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(None))
     (lambda (f)
     (match (parse_tag l)
        ((Some p)
          (match p
             ((Pair tg r1)
               (match (parse_len r1)
                  ((Some p0)
                    (match p0
                       ((Pair n r2)
                         (match (@ split_n n r2)
                            ((Some p1)
                              (match p1
                                 ((Pair v rest)
                                   (match (constructed tg)
                                      ((True)
                                        (match (@ dec_seq f v)
                                           ((Some ks) `(Some ,`(Pair
                                             ,`(Constr ,tg ,ks) ,rest)))
                                           ((None) `(None))))
                                      ((False) `(Some ,`(Pair ,`(Prim ,tg ,v)
                                        ,rest)))))))
                            ((None) `(None))))))
                  ((None) `(None))))))
        ((None) `(None))))
     fuel)))
  
(define parse_apdu (lambda (l)
  (match l
     ((Nil) `(None))
     ((Cons c l0)
       (match l0
          ((Nil) `(None))
          ((Cons i l1)
            (match l1
               ((Nil) `(None))
               ((Cons a l2)
                 (match l2
                    ((Nil) `(None))
                    ((Cons b body)
                      (match body
                         ((Nil) `(Some ,`(Mk_apdu ,c ,i ,a ,b ,`(Nil)
                           ,`(None))))
                         ((Cons lc rest)
                           (match rest
                              ((Nil) `(Some ,`(Mk_apdu ,c ,i ,a ,b ,`(Nil)
                                ,`(Some ,lc))))
                              ((Cons _ _)
                                (match (@ eqb lc `(0))
                                   ((True) `(None))
                                   ((False)
                                     (match (@ split_n lc rest)
                                        ((Some p)
                                          (match p
                                             ((Pair d l3)
                                               (match l3
                                                  ((Nil) `(Some ,`(Mk_apdu ,c
                                                    ,i ,a ,b ,d ,`(None))))
                                                  ((Cons e l4)
                                                    (match l4
                                                       ((Nil) `(Some
                                                         ,`(Mk_apdu ,c ,i ,a
                                                         ,b ,d ,`(Some ,e))))
                                                       ((Cons _ _) `(None))))))))
                                        ((None) `(None)))))))))))))))))))

(define summ (lambdas (d t acc)
  (match t
     ((Prim tg v) `(Cons ,tg ,`(Cons ,d ,`(Cons ,(length v) ,acc))))
     ((Constr tg ks) `(Cons ,tg ,`(Cons ,d ,`(Cons ,(length ks)
       ,(letrec ((go
                (lambda (ks0)
                (match ks0
                   ((Nil) acc)
                   ((Cons k ks~)
                     (@ summ `((lambda (x) (+ x 1)) ,d) k (go ks~)))))))
                (go ks)))))))))
  
(define run (lambda (n)
  (match (parse_apdu (@ read_bytes `(0) n))
     ((Some x)
       (match (@ dec_seq `((lambda (x) (+ x 1))
                ,(length (match x
                            ((Mk_apdu _ _ _ _ data _) data))))
                (match x
                   ((Mk_apdu _ _ _ _ data _) data)))
          ((Some ts) `(Cons ,`(0) ,`(Cons
            ,(match x
                ((Mk_apdu _ ins _ _ _ _) ins))
            ,(@ fold_right (summ `(0)) `(Nil) ts))))
          ((None) `(Cons ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
            ,`(0))) ,`(Nil)))))
     ((None) `(Cons ,`((lambda (x) (+ x 1)) ,`(0)) ,`(Nil))))))

