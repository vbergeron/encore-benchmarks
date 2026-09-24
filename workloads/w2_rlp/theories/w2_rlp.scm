;; This extracted scheme code relies on some additional macros
;; available at http://www.pps.univ-paris-diderot.fr/~letouzey/scheme
(load "macros_extr.scm")


(define length (lambda (l)
  (match l
     ((Nil) `(0))
     ((Cons _ l~) `((lambda (x) (+ x 1)) ,(length l~))))))
  
(define add (lambda (a) (lambda (b) (+ a b))))
  
(define mul (lambda (a) (lambda (b) (* a b))))
  
(define sub (lambda (a) (lambda (b) (int-sub-sat a b))))
  
(define add0 (lambda (a) (lambda (b) (+ a b))))
  
(define sub0 (lambda (a) (lambda (b) (int-sub-sat a b))))
  
(define eqb (lambda (a) (lambda (b) (= a b))))
  
(define leb (lambda (a) (lambda (b) (<= a b))))
  
(define ltb (lambda (a) (lambda (b) (< a b))))

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

(define modulo (lambda (a) (lambda (b) (int-mod a b))))

(define map (lambdas (f l)
  (match l
     ((Nil) `(Nil))
     ((Cons a l0) `(Cons ,(f a) ,(@ map f l0))))))
  
(define input_byte (extern (slot 0) i))

(define read_bytes (lambdas (pos n)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (n~) `(Cons ,(input_byte pos)
     ,(@ read_bytes `((lambda (x) (+ x 1)) ,pos) n~)))
     n)))
  
(define str_off 128)

(define str_long 184)

(define str_long_base 183)

(define list_off 192)

(define list_long 248)

(define list_long_base 247)

(define short_max 56)

(define byte_base 256)

(define max_scalar 32)

(define addr_len 20)

(define ten 10)

(define sixteen 16)

(define ascii_zero 48)

(define ascii_a_off 87)

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
  
(define long_len (lambdas (ll r)
  (match (@ eqb ll `((lambda (x) (+ x 1)) ,`(0)))
     ((True)
       (match r
          ((Nil) `(None))
          ((Cons c r~)
            (match (@ leb short_max c)
               ((True) `(Some ,`(Pair ,c ,r~)))
               ((False) `(None))))))
     ((False)
       (match (@ eqb ll `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
                ,`(0))))
          ((True)
            (match r
               ((Nil) `(None))
               ((Cons c1 l)
                 (match l
                    ((Nil) `(None))
                    ((Cons c2 r~)
                      (match (@ ltb `(0) c1)
                         ((True) `(Some ,`(Pair
                           ,(@ add (@ mul c1 byte_base) c2) ,r~)))
                         ((False) `(None))))))))
          ((False) `(None)))))))

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
                  ((Pair i rest)
                    (match (@ dec_seq f rest)
                       ((Some is) `(Some ,`(Cons ,i ,is)))
                       ((None) `(None))))))
             ((None) `(None))))))
     fuel)))
  
(define dec_one (lambdas (fuel l)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(None))
     (lambda (f)
     (match l
        ((Nil) `(None))
        ((Cons b r)
          (match (@ ltb b str_off)
             ((True) `(Some ,`(Pair ,`(Str ,`(Cons ,b ,`(Nil))) ,r)))
             ((False)
               (match (@ ltb b str_long)
                  ((True)
                    (match (@ split_n (@ sub b str_off) r)
                       ((Some p)
                         (match p
                            ((Pair s rest)
                              (match s
                                 ((Nil) `(Some ,`(Pair ,`(Str ,s) ,rest)))
                                 ((Cons c l0)
                                   (match l0
                                      ((Nil)
                                        (match (@ ltb c str_off)
                                           ((True) `(None))
                                           ((False) `(Some ,`(Pair ,`(Str
                                             ,`(Cons ,c ,`(Nil))) ,rest)))))
                                      ((Cons _ _) `(Some ,`(Pair ,`(Str ,s)
                                        ,rest)))))))))
                       ((None) `(None))))
                  ((False)
                    (match (@ ltb b list_off)
                       ((True)
                         (match (@ long_len (@ sub b str_long_base) r)
                            ((Some p)
                              (match p
                                 ((Pair n r2)
                                   (match (@ split_n n r2)
                                      ((Some p0)
                                        (match p0
                                           ((Pair s rest) `(Some ,`(Pair
                                             ,`(Str ,s) ,rest)))))
                                      ((None) `(None))))))
                            ((None) `(None))))
                       ((False)
                         (match (@ ltb b list_long)
                            ((True)
                              (match (@ split_n (@ sub b list_off) r)
                                 ((Some p)
                                   (match p
                                      ((Pair body rest)
                                        (match (@ dec_seq f body)
                                           ((Some is) `(Some ,`(Pair ,`(Lst
                                             ,is) ,rest)))
                                           ((None) `(None))))))
                                 ((None) `(None))))
                            ((False)
                              (match (@ long_len (@ sub b list_long_base) r)
                                 ((Some p)
                                   (match p
                                      ((Pair n r2)
                                        (match (@ split_n n r2)
                                           ((Some p0)
                                             (match p0
                                                ((Pair body rest)
                                                  (match (@ dec_seq f body)
                                                     ((Some is) `(Some
                                                       ,`(Pair ,`(Lst ,is)
                                                       ,rest)))
                                                     ((None) `(None))))))
                                           ((None) `(None))))))
                                 ((None) `(None))))))))))))))
     fuel)))
  
(define scalar (lambda (s)
  (match s
     ((Nil) (@ leb (length s) max_scalar))
     ((Cons n _)
       ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
          (lambda (_) `(False))
          (lambda (_) (@ leb (length s) max_scalar))
          n)))))

(define is_nil (lambda (s) (match s
                              ((Nil) `(True))
                              ((Cons _ _) `(False)))))

(define decode_tx (lambda (l)
  (match (@ dec_one `((lambda (x) (+ x 1)) ,(length l)) l)
     ((Some p)
       (match p
          ((Pair i l0)
            (match i
               ((Str _) `(None))
               ((Lst items)
                 (match items
                    ((Nil) `(None))
                    ((Cons i0 l1)
                      (match i0
                         ((Str n)
                           (match l1
                              ((Nil) `(None))
                              ((Cons i1 l2)
                                (match i1
                                   ((Str gp)
                                     (match l2
                                        ((Nil) `(None))
                                        ((Cons i2 l3)
                                          (match i2
                                             ((Str gl)
                                               (match l3
                                                  ((Nil) `(None))
                                                  ((Cons i3 l4)
                                                    (match i3
                                                       ((Str t)
                                                         (match l4
                                                            ((Nil) `(None))
                                                            ((Cons i4 l5)
                                                              (match i4
                                                                 ((Str v)
                                                                   (match l5
                                                                    ((Nil)
                                                                    `(None))
                                                                    ((Cons i5
                                                                    l6)
                                                                    (match i5
                                                                    ((Str d)
                                                                    (match l6
                                                                    ((Nil)
                                                                    `(None))
                                                                    ((Cons i6
                                                                    l7)
                                                                    (match i6
                                                                    ((Str c)
                                                                    (match l7
                                                                    ((Nil)
                                                                    `(None))
                                                                    ((Cons i7
                                                                    l8)
                                                                    (match i7
                                                                    ((Str r)
                                                                    (match l8
                                                                    ((Nil)
                                                                    `(None))
                                                                    ((Cons i8
                                                                    l9)
                                                                    (match i8
                                                                    ((Str s)
                                                                    (match l9
                                                                    ((Nil)
                                                                    (match l0
                                                                    ((Nil)
                                                                    (match 
                                                                    (match 
                                                                    (match 
                                                                    (match 
                                                                    (match 
                                                                    (match 
                                                                    (match 
                                                                    (match 
                                                                    (scalar
                                                                    n)
                                                                    ((True)
                                                                    (scalar
                                                                    gp))
                                                                    ((False)
                                                                    `(False)))
                                                                    ((True)
                                                                    (scalar
                                                                    gl))
                                                                    ((False)
                                                                    `(False)))
                                                                    ((True)
                                                                    (@ eqb
                                                                    (length
                                                                    t)
                                                                    addr_len))
                                                                    ((False)
                                                                    `(False)))
                                                                    ((True)
                                                                    (scalar
                                                                    v))
                                                                    ((False)
                                                                    `(False)))
                                                                    ((True)
                                                                    (scalar
                                                                    c))
                                                                    ((False)
                                                                    `(False)))
                                                                    ((True)
                                                                    (is_nil
                                                                    r))
                                                                    ((False)
                                                                    `(False)))
                                                                    ((True)
                                                                    (is_nil
                                                                    s))
                                                                    ((False)
                                                                    `(False)))
                                                                    ((True)
                                                                    `(Some
                                                                    ,`(Mk_tx
                                                                    ,n ,gp
                                                                    ,gl ,t ,v
                                                                    ,d ,c)))
                                                                    ((False)
                                                                    `(None))))
                                                                    ((Cons _
                                                                    _)
                                                                    `(None))))
                                                                    ((Cons _
                                                                    _)
                                                                    `(None))))
                                                                    ((Lst _)
                                                                    `(None))))))
                                                                    ((Lst _)
                                                                    `(None))))))
                                                                    ((Lst _)
                                                                    `(None))))))
                                                                    ((Lst _)
                                                                    `(None))))))
                                                                 ((Lst _)
                                                                   `(None))))))
                                                       ((Lst _) `(None))))))
                                             ((Lst _) `(None))))))
                                   ((Lst _) `(None))))))
                         ((Lst _) `(None))))))))))
     ((None) `(None)))))

(define divmod10 (lambdas (r l)
  (match l
     ((Nil) `(Pair ,`(Nil) ,r))
     ((Cons b t)
       (let ((x (@ add (@ mul r byte_base) b)))
         (match (@ divmod10 (@ modulo x ten) t)
            ((Pair q r~) `(Pair ,`(Cons ,(@ div x ten) ,q) ,r~))))))))
  
(define strip (lambda (l)
  (match l
     ((Nil) l)
     ((Cons n t)
       ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
          (lambda (_) (strip t))
          (lambda (_) l)
          n)))))
  
(define digits_rev (lambdas (fuel l acc)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) acc)
     (lambda (f)
     (match (strip l)
        ((Nil) acc)
        ((Cons n l0)
          (match (@ divmod10 `(0) `(Cons ,n ,l0))
             ((Pair q d) (@ digits_rev f q `(Cons ,d ,acc)))))))
     fuel)))
  
(define show_dec (lambda (l)
  (match (@ digits_rev
           (@ mul `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
             ,`((lambda (x) (+ x 1)) ,`(0)))) (length l))
           l `(Nil))
     ((Nil) `(Cons ,ascii_zero ,`(Nil)))
     ((Cons n l0) (@ map (add0 ascii_zero) `(Cons ,n ,l0))))))

(define hex_digit (lambda (d)
  (match (@ ltb d ten)
     ((True) (@ add ascii_zero d))
     ((False) (@ add ascii_a_off d)))))

(define hex (lambda (l)
  (match l
     ((Nil) `(Nil))
     ((Cons b t) `(Cons ,(hex_digit (@ div b sixteen)) ,`(Cons
       ,(hex_digit (@ modulo b sixteen)) ,(hex t)))))))
  
(define display (lambda (x) `(Cons
  ,(show_dec (match x
                ((Mk_tx _ _ _ _ _ _ chain_id) chain_id)))
  ,`(Cons ,(hex (match x
                   ((Mk_tx _ _ _ to _ _ _) to)))
  ,`(Cons ,(show_dec (match x
                        ((Mk_tx _ _ _ _ value _ _) value)))
  ,`(Cons ,(show_dec (match x
                        ((Mk_tx nonce _ _ _ _ _ _) nonce)))
  ,`(Cons ,(show_dec (match x
                        ((Mk_tx _ gas_price _ _ _ _ _) gas_price)))
  ,`(Cons ,(show_dec (match x
                        ((Mk_tx _ _ gas_limit _ _ _ _) gas_limit)))
  ,`(Cons ,(hex (match x
                   ((Mk_tx _ _ _ _ _ data _) data)))
  ,`(Nil))))))))))

(define run (lambda (n)
  (match (decode_tx (@ read_bytes `(0) n))
     ((Some x) (display x))
     ((None) `(Nil)))))

