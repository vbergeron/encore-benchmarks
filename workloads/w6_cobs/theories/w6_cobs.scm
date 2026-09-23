;; This extracted scheme code relies on some additional macros
;; available at http://www.pps.univ-paris-diderot.fr/~letouzey/scheme
(load "macros_extr.scm")


(define length (lambda (l)
  (match l
     ((Nil) `(0))
     ((Cons _ l~) `((lambda (x) (+ x 1)) ,(length l~))))))
  
(define app (lambdas (l m)
  (match l
     ((Nil) m)
     ((Cons a l1) `(Cons ,a ,(@ app l1 m))))))
  
(define pred (lambda (n)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) n)
     (lambda (u) u)
     n)))

(define eqb (lambda (a) (lambda (b) (if (= a b) `(True) `(False)))))
  
(define input_byte (extern (slot 0) i))

(define read_bytes (lambdas (pos n)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (n~) `(Cons ,(input_byte pos)
     ,(@ read_bytes `((lambda (x) (+ x 1)) ,pos) n~)))
     n)))
  
(define block_max 254)

(define fits (lambdas (k l)
  (match l
     ((Nil) `(True))
     ((Cons _ t)
       ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
          (lambda (_) `(False))
          (lambda (k~) (@ fits k~ t))
          k)))))
  
(define split_at (lambdas (k l)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Pair ,`(Nil) ,l))
     (lambda (k~)
     (match l
        ((Nil) `(Pair ,`(Nil) ,`(Nil)))
        ((Cons x t)
          (match (@ split_at k~ t)
             ((Pair a b) `(Pair ,`(Cons ,x ,a) ,b))))))
     k)))
  
(define chunks (lambdas (fuel p)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Cons ,`((lambda (x) (+ x 1)) ,(length p)) ,p))
     (lambda (f)
     (match (@ fits (pred block_max) p)
        ((True) `(Cons ,`((lambda (x) (+ x 1)) ,(length p)) ,p))
        ((False)
          (match (@ split_at block_max p)
             ((Pair a b) `(Cons ,`((lambda (x) (+ x 1)) ,block_max)
               ,(@ app a (@ chunks f b))))))))
     fuel)))
  
(define enc_piece (lambda (p) (@ chunks (length p) p)))

(define split_zero (lambda (l)
  (match l
     ((Nil) `(Cons ,`(Nil) ,`(Nil)))
     ((Cons x t)
       (let ((ps (split_zero t)))
         ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
            (lambda (_) `(Cons ,`(Nil) ,ps))
            (lambda (_)
            (match ps
               ((Nil) `(Cons ,`(Cons ,x ,`(Nil)) ,`(Nil)))
               ((Cons p ps~) `(Cons ,`(Cons ,x ,p) ,ps~))))
            x))))))
  
(define enc_pieces (lambda (ps)
  (match ps
     ((Nil) `(Nil))
     ((Cons p ps~) (@ app (enc_piece p) (enc_pieces ps~))))))
  
(define cobs_encode (lambda (l) (enc_pieces (split_zero l))))

(define dec (lambdas (k ff l)
  (match l
     ((Nil)
       ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
          (lambda (_) `(Some ,`(Nil)))
          (lambda (_) `(None))
          k))
     ((Cons x t)
       ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
          (lambda (_)
          ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
             (lambda (_) `(None))
             (lambda (n)
             (let ((r (@ dec n (@ eqb n block_max) t)))
               (match ff
                  ((True) r)
                  ((False)
                    (match r
                       ((Some d) `(Some ,`(Cons ,`(0) ,d)))
                       ((None) `(None)))))))
             x))
          (lambda (k~)
          ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
             (lambda (_) `(None))
             (lambda (_)
             (match (@ dec k~ ff t)
                ((Some d) `(Some ,`(Cons ,x ,d)))
                ((None) `(None))))
             x))
          k)))))
  
(define cobs_decode (lambda (l)
  (match l
     ((Nil) `(None))
     ((Cons _ _) (@ dec `(0) `(True) l)))))

(define encode_input (lambda (n) (cobs_encode (@ read_bytes `(0) n))))

