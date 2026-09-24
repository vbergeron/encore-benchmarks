;; This extracted scheme code relies on some additional macros
;; available at http://www.pps.univ-paris-diderot.fr/~letouzey/scheme
(load "macros_extr.scm")


(define add (lambda (a) (lambda (b) (+ a b))))
  
(define add0 (lambda (a) (lambda (b) (+ a b))))
  
(define mul (lambda (a) (lambda (b) (* a b))))
  
(define max (lambda (a) (lambda (b) (if (<= a b) b a))))
  
(define even (lambda (a) (= (int-and a 1) 0)))
  
(define odd (lambda (a) (= (int-and a 1) 1)))

(define div2 (lambda (a) (int-shr a 1)))
  
(define bitwise (lambdas (op n a b)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(0))
     (lambda (n~)
     (@ add0
       (match (@ op (odd a) (odd b))
          ((True) `((lambda (x) (+ x 1)) ,`(0)))
          ((False) `(0)))
       (@ mul `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0)))
         (@ bitwise op n~ (div2 a) (div2 b)))))
     n)))
  
(define lxor (lambda (a) (lambda (b) (int-xor a b))))

(define input_byte (extern (slot 0) i))

(define poly16 40961)

(define poly32_hi 60856)

(define poly32_lo 33568)

(define half_mask 65535)

(define top_bit 32768)

(define crc16_bit (lambda (c)
  (match (odd c)
     ((True) (@ lxor (div2 c) poly16))
     ((False) (div2 c)))))

(define crc16_shift (lambdas (k c)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) c)
     (lambda (k~) (@ crc16_shift k~ (crc16_bit c)))
     k)))
  
(define crc16_byte (lambdas (c b)
  (@ crc16_shift `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
    ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
    ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
    ,`(0))))))))) (@ lxor c b))))

(define crc16_from (lambdas (c pos n)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) c)
     (lambda (n~)
     (@ crc16_from (@ crc16_byte c (input_byte pos)) `((lambda (x) (+ x 1))
       ,pos) n~))
     n)))
  
(define crc16_input (lambda (n) (@ crc16_from half_mask `(0) n)))

(define crc32_shift (lambdas (k h l)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Pair ,h ,l))
     (lambda (k~)
     (let ((h~ (div2 h)))
       (let ((l~
         (match (odd h)
            ((True) (@ add (div2 l) top_bit))
            ((False) (div2 l)))))
         (match (odd l)
            ((True)
              (@ crc32_shift k~ (@ lxor h~ poly32_hi) (@ lxor l~ poly32_lo)))
            ((False) (@ crc32_shift k~ h~ l~))))))
     k)))
  
(define crc32_from (lambdas (h l pos n)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Pair ,h ,l))
     (lambda (n~)
     (match (@ crc32_shift `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
              ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
              ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1))
              ,`((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0))))))))) h
              (@ lxor l (input_byte pos)))
        ((Pair h~ l~) (@ crc32_from h~ l~ `((lambda (x) (+ x 1)) ,pos) n~))))
     n)))
  
(define crc32_input (lambda (n)
  (match (@ crc32_from half_mask half_mask `(0) n)
     ((Pair h l) `(Pair ,(@ lxor h half_mask) ,(@ lxor l half_mask))))))

(define run (lambda (n) `(Pair ,(crc16_input n) ,(crc32_input n))))

