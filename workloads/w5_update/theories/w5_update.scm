;; This extracted scheme code relies on some additional macros
;; available at http://www.pps.univ-paris-diderot.fr/~letouzey/scheme
(load "macros_extr.scm")


(define negb (lambda (b) (match b
                            ((True) `(False))
                            ((False) `(True)))))

(define fst (lambda (p) (match p
                           ((Pair x _) x))))

(define snd (lambda (p) (match p
                           ((Pair _ y) y))))

(define add (lambda (a) (lambda (b) (+ a b))))
  
(define mul (lambda (a) (lambda (b) (* a b))))
  
(define sub (lambda (a) (lambda (b) (int-sub-sat a b))))
  
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
  
(define modulo (lambda (a) (lambda (b) (int-mod a b))))

(define firstn (lambdas (n l)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (n0)
     (match l
        ((Nil) `(Nil))
        ((Cons a l0) `(Cons ,a ,(@ firstn n0 l0)))))
     n)))
  
(define fold_left (lambdas (f l a0)
  (match l
     ((Nil) a0)
     ((Cons b l0) (@ fold_left f l0 (@ f a0 b))))))
  
(define input_byte (extern (slot 0) i))

(define byte_base 256)

(define modulus 65521)

(define radix 31)

(define factory_version 1)

(define ev_begin 1)

(define ev_chunk 2)

(define ev_finish 3)

(define ev_confirm 4)

(define ev_reboot 5)

(define ev_cut 6)

(define code_busy 1)

(define code_rollback 2)

(define code_unexpected 3)

(define code_bad_image 4)

(define code_bad_event 5)

(define code_booted 8)

(define other (lambda (i) (match i
                             ((SA) `(SB))
                             ((SB) `(SA)))))

(define get (lambdas (f i)
  (match i
     ((SA) (match f
              ((Mk_flash slot_a _ _ _ _ _) slot_a)))
     ((SB) (match f
              ((Mk_flash _ slot_b _ _ _ _) slot_b))))))

(define put (lambdas (f i s)
  (match i
     ((SA) `(Mk_flash ,s ,(match f
                             ((Mk_flash _ slot_b _ _ _ _) slot_b))
       ,(match f
           ((Mk_flash _ _ active _ _ _) active))
       ,(match f
           ((Mk_flash _ _ _ pending _ _) pending))
       ,(match f
           ((Mk_flash _ _ _ _ tried _) tried))
       ,(match f
           ((Mk_flash _ _ _ _ _ floor) floor))))
     ((SB) `(Mk_flash ,(match f
                          ((Mk_flash slot_a _ _ _ _ _) slot_a))
       ,s ,(match f
              ((Mk_flash _ _ active _ _ _) active))
       ,(match f
           ((Mk_flash _ _ _ pending _ _) pending))
       ,(match f
           ((Mk_flash _ _ _ _ tried _) tried))
       ,(match f
           ((Mk_flash _ _ _ _ _ floor) floor)))))))

(define spare (lambda (f)
  (other (match f
            ((Mk_flash _ _ active _ _ _) active)))))

(define cur (lambda (f)
  (@ get f (match f
              ((Mk_flash _ _ active _ _ _) active)))))

(define mix (lambdas (acc d) (@ modulo (@ add (@ mul acc radix) d) modulus)))

(define apply0 (lambdas (f e)
  (match e
     ((Erase i) (@ put f i `(Mk_slot ,`(False) ,`(0) ,`(0) ,`(0))))
     ((Program i d)
       (let ((s (@ get f i)))
         (@ put f i `(Mk_slot ,`(False) ,(match s
                                            ((Mk_slot _ ver _ _) ver))
           ,`((lambda (x) (+ x 1)) ,(match s
                                       ((Mk_slot _ _ len _) len)))
           ,(@ mix (match s
                      ((Mk_slot _ _ _ sum) sum)) d)))))
     ((Seal i v)
       (let ((s (@ get f i)))
         (@ put f i `(Mk_slot ,`(True) ,v ,(match s
                                              ((Mk_slot _ _ len _) len))
           ,(match s
               ((Mk_slot _ _ _ sum) sum))))))
     ((SetBoot i) `(Mk_flash ,(match f
                                 ((Mk_flash slot_a _ _ _ _ _) slot_a))
       ,(match f
           ((Mk_flash _ slot_b _ _ _ _) slot_b))
       ,i ,`(True) ,`(False) ,(match f
                                 ((Mk_flash _ _ _ _ _ floor) floor))))
     ((MarkTried) `(Mk_flash ,(match f
                                 ((Mk_flash slot_a _ _ _ _ _) slot_a))
       ,(match f
           ((Mk_flash _ slot_b _ _ _ _) slot_b))
       ,(match f
           ((Mk_flash _ _ active _ _ _) active))
       ,(match f
           ((Mk_flash _ _ _ pending _ _) pending))
       ,`(True) ,(match f
                    ((Mk_flash _ _ _ _ _ floor) floor))))
     ((Revert) `(Mk_flash ,(match f
                              ((Mk_flash slot_a _ _ _ _ _) slot_a))
       ,(match f
           ((Mk_flash _ slot_b _ _ _ _) slot_b))
       ,(other (match f
                  ((Mk_flash _ _ active _ _ _) active)))
       ,`(False) ,`(False) ,(match f
                               ((Mk_flash _ _ _ _ _ floor) floor))))
     ((ClearPending) `(Mk_flash
       ,(match f
           ((Mk_flash slot_a _ _ _ _ _) slot_a))
       ,(match f
           ((Mk_flash _ slot_b _ _ _ _) slot_b))
       ,(match f
           ((Mk_flash _ _ active _ _ _) active))
       ,`(False) ,`(False) ,(match f
                               ((Mk_flash _ _ _ _ _ floor) floor))))
     ((Bump v) `(Mk_flash ,(match f
                              ((Mk_flash slot_a _ _ _ _ _) slot_a))
       ,(match f
           ((Mk_flash _ slot_b _ _ _ _) slot_b))
       ,(match f
           ((Mk_flash _ _ active _ _ _) active))
       ,(match f
           ((Mk_flash _ _ _ pending _ _) pending))
       ,(match f
           ((Mk_flash _ _ _ _ tried _) tried))
       ,v)))))

(define apply_all (lambdas (f es) (@ fold_left apply0 es f)))

(define boot_effects (lambda (f)
  (match (match f
            ((Mk_flash _ _ _ pending _ _) pending))
     ((True)
       (match (match f
                 ((Mk_flash _ _ _ _ tried _) tried))
          ((True) `(Cons ,`(Revert) ,`(Nil)))
          ((False) `(Cons ,`(MarkTried) ,`(Nil)))))
     ((False) `(Nil)))))

(define boot (lambda (f) (@ apply_all f (boot_effects f))))

(define step (lambdas (f r c)
  (match c
     ((Begin v size)
       (match (match f
                 ((Mk_flash _ _ _ pending _ _) pending))
          ((True) `(Pair ,`(Pair ,r ,`(Nil)) ,`(Busy)))
          ((False)
            (match (@ leb v (match (cur f)
                               ((Mk_slot _ ver _ _) ver)))
               ((True) `(Pair ,`(Pair ,r ,`(Nil)) ,`(Rollback)))
               ((False) `(Pair ,`(Pair ,`(Loading ,v ,size ,`(0)) ,`(Cons
                 ,`(Erase ,(spare f)) ,`(Nil))) ,`(Ok)))))))
     ((Chunk d)
       (match r
          ((Idle) `(Pair ,`(Pair ,r ,`(Nil)) ,`(Unexpected)))
          ((Loading v size got)
            (match (match (negb
                            (match f
                               ((Mk_flash _ _ _ pending _ _) pending)))
                      ((True) (@ ltb got size))
                      ((False) `(False)))
               ((True) `(Pair ,`(Pair ,`(Loading ,v ,size
                 ,`((lambda (x) (+ x 1)) ,got)) ,`(Cons ,`(Program ,(spare f)
                 ,d) ,`(Nil))) ,`(Ok)))
               ((False) `(Pair ,`(Pair ,r ,`(Nil)) ,`(Unexpected)))))))
     ((Finish digest0)
       (match r
          ((Idle) `(Pair ,`(Pair ,r ,`(Nil)) ,`(Unexpected)))
          ((Loading v size got)
            (match (match (match (match f
                                    ((Mk_flash _ _ _ pending _ _) pending))
                             ((True) `(True))
                             ((False) (negb (@ eqb got size))))
                      ((True) `(True))
                      ((False)
                        (@ leb v (match (cur f)
                                    ((Mk_slot _ ver _ _) ver)))))
               ((True) `(Pair ,`(Pair ,r ,`(Nil)) ,`(Unexpected)))
               ((False)
                 (match (@ eqb
                          (match (@ get f (spare f))
                             ((Mk_slot _ _ _ sum) sum))
                          digest0)
                    ((True) `(Pair ,`(Pair ,`(Idle) ,`(Cons ,`(Seal
                      ,(spare f) ,v) ,`(Cons ,`(SetBoot ,(spare f))
                      ,`(Nil)))) ,`(Ok)))
                    ((False) `(Pair ,`(Pair ,`(Idle) ,`(Nil)) ,`(BadImage)))))))))
     ((Confirm)
       (match (match (match f
                        ((Mk_flash _ _ _ pending _ _) pending))
                 ((True) (match f
                            ((Mk_flash _ _ _ _ tried _) tried)))
                 ((False) `(False)))
          ((True) `(Pair ,`(Pair ,r ,`(Cons ,`(ClearPending) ,`(Cons ,`(Bump
            ,(match (cur f)
                ((Mk_slot _ ver _ _) ver)))
            ,`(Nil)))) ,`(Ok)))
          ((False) `(Pair ,`(Pair ,r ,`(Nil)) ,`(Unexpected)))))
     ((Reboot) `(Pair ,`(Pair ,`(Idle) ,(boot_effects f)) ,`(Booted
       ,(match (cur (boot f))
           ((Mk_slot _ ver _ _) ver)))))
     ((Unknown) `(Pair ,`(Pair ,r ,`(Nil)) ,`(BadEvent))))))

(define effects (lambdas (f r c) (snd (fst (@ step f r c)))))

(define code (lambda (x)
  (match x
     ((Ok) `(0))
     ((Busy) code_busy)
     ((Rollback) code_rollback)
     ((Unexpected) code_unexpected)
     ((BadImage) code_bad_image)
     ((BadEvent) code_bad_event)
     ((Booted v) (@ add code_booted v)))))

(define handle (lambdas (f r e)
  (match e
     ((Do c)
       (match (@ step f r c)
          ((Pair p x)
            (match p
               ((Pair r~ es) `(Pair ,`(Pair ,(@ apply_all f es) ,r~)
                 ,(code x)))))))
     ((Cut i c)
       (let ((f~ (boot (@ apply_all f (@ firstn i (@ effects f r c))))))
         `(Pair ,`(Pair ,f~ ,`(Idle))
         ,(code `(Booted ,(match (cur f~)
                             ((Mk_slot _ ver _ _) ver))))))))))

(define read_u16 (lambda (pos)
  (@ add (@ mul (input_byte pos) byte_base)
    (input_byte `((lambda (x) (+ x 1)) ,pos)))))

(define digest (lambdas (acc pos k)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) acc)
     (lambda (k~)
     (@ digest (@ mix acc (input_byte pos)) `((lambda (x) (+ x 1)) ,pos) k~))
     k)))
  
(define decode_cmd (lambda (pos)
  (let ((t (input_byte pos)))
    (match (@ eqb t ev_begin)
       ((True) `(Pair ,`(Begin ,(read_u16 `((lambda (x) (+ x 1)) ,pos))
         ,(input_byte `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
            ,`((lambda (x) (+ x 1)) ,pos)))))
         ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
         ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,pos))))))
       ((False)
         (match (@ eqb t ev_chunk)
            ((True)
              (let ((n (input_byte `((lambda (x) (+ x 1)) ,pos))))
                `(Pair ,`(Chunk
                ,(@ digest `(0) `((lambda (x) (+ x 1))
                   ,`((lambda (x) (+ x 1)) ,pos)) n))
                ,(@ add `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,pos))
                   n))))
            ((False)
              (match (@ eqb t ev_finish)
                 ((True) `(Pair ,`(Finish
                   ,(read_u16 `((lambda (x) (+ x 1)) ,pos)))
                   ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
                   ,`((lambda (x) (+ x 1)) ,pos)))))
                 ((False)
                   (match (@ eqb t ev_confirm)
                      ((True) `(Pair ,`(Confirm) ,`((lambda (x) (+ x 1))
                        ,pos)))
                      ((False)
                        (match (@ eqb t ev_reboot)
                           ((True) `(Pair ,`(Reboot) ,`((lambda (x) (+ x 1))
                             ,pos)))
                           ((False) `(Pair ,`(Unknown)
                             ,`((lambda (x) (+ x 1)) ,pos)))))))))))))))

(define decode (lambda (pos)
  (match (@ eqb (input_byte pos) ev_cut)
     ((True)
       (match (decode_cmd `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
                ,pos)))
          ((Pair c pos~) `(Pair ,`(Cut
            ,(input_byte `((lambda (x) (+ x 1)) ,pos)) ,c) ,pos~))))
     ((False)
       (match (decode_cmd pos)
          ((Pair c pos~) `(Pair ,`(Do ,c) ,pos~)))))))

(define process (lambdas (k f r pos)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (k~)
     (match (decode pos)
        ((Pair e pos~)
          (match (@ handle f r e)
             ((Pair p x)
               (match p
                  ((Pair f~ r~) `(Cons ,x ,(@ process k~ f~ r~ pos~)))))))))
     k)))
  
(define init `(Mk_flash ,`(Mk_slot ,`(True) ,factory_version ,`(0) ,`(0))
  ,`(Mk_slot ,`(False) ,`(0) ,`(0) ,`(0)) ,`(SA) ,`(False) ,`(False)
  ,factory_version))

(define run (lambda (n) (@ process n init `(Idle) `(0))))

