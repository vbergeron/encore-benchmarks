;; This extracted scheme code relies on some additional macros
;; available at http://www.pps.univ-paris-diderot.fr/~letouzey/scheme
(load "macros_extr.scm")


(define add (lambda (a) (lambda (b) (+ a b))))
  
(define mul (lambda (a) (lambda (b) (* a b))))
  
(define eqb (lambda (a) (lambda (b) (= a b))))
  
(define leb (lambda (a) (lambda (b) (<= a b))))
  
(define ltb (lambda (a) (lambda (b) (< a b))))

(define input_byte (extern (slot 0) i))

(define elem_len 4)

(define range_len 8)

(define amount_len 8)

(define addr_len 20)

(define hdr_len 3)

(define byte_base 256)

(define code_dest 1)

(define code_amount 2)

(define code_path 3)

(define lower (lambdas (a b) (match (@ leb a b)
                                ((True) a)
                                ((False) b))))

(define le_at (lambdas (n a b)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(True))
     (lambda (n~)
     (let ((x (input_byte a)))
       (let ((y (input_byte b)))
         (match (@ ltb x y)
            ((True) `(True))
            ((False)
              (match (@ eqb x y)
                 ((True)
                   (@ le_at n~ `((lambda (x) (+ x 1)) ,a)
                     `((lambda (x) (+ x 1)) ,b)))
                 ((False) `(False))))))))
     n)))
  
(define eq_at (lambdas (n a b)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(True))
     (lambda (n~)
     (match (@ eqb (input_byte a) (input_byte b))
        ((True)
          (@ eq_at n~ `((lambda (x) (+ x 1)) ,a) `((lambda (x) (+ x 1)) ,b)))
        ((False) `(False))))
     n)))
  
(define mem_at (lambdas (k pos q)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(False))
     (lambda (k~)
     (match (@ eq_at addr_len q pos)
        ((True) `(True))
        ((False) (@ mem_at k~ (@ add pos addr_len) q))))
     k)))
  
(define path_at (lambdas (d qd rpos qpos)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_)
     ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
        (lambda (_) `(True))
        (lambda (_) `(False))
        qd))
     (lambda (d~)
     ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
        (lambda (_) `(False))
        (lambda (qd~)
        (match (@ le_at elem_len rpos qpos)
           ((True)
             (match (@ le_at elem_len qpos (@ add rpos elem_len))
                ((True)
                  (@ path_at d~ qd~ (@ add rpos range_len)
                    (@ add qpos elem_len)))
                ((False) `(False))))
           ((False) `(False))))
        qd))
     d)))
  
(define rule_code_at (lambdas (rpos qpos)
  (let ((d (input_byte rpos)))
    (let ((lim (@ add `((lambda (x) (+ x 1)) ,rpos) (@ mul d range_len))))
      (let ((amt
        (@ add `((lambda (x) (+ x 1)) ,qpos)
          (@ mul (input_byte qpos) elem_len))))
        (match (@ path_at d (input_byte qpos) `((lambda (x) (+ x 1)) ,rpos)
                 `((lambda (x) (+ x 1)) ,qpos))
           ((True)
             (match (@ le_at amount_len amt lim)
                ((True)
                  (let ((k_pos (@ add lim amount_len)))
                    (match (@ mem_at (input_byte k_pos)
                             `((lambda (x) (+ x 1)) ,k_pos)
                             (@ add amt amount_len))
                       ((True) `(0))
                       ((False) code_dest))))
                ((False) code_amount)))
           ((False) code_path)))))))

(define rule_end (lambda (pos)
  (let ((k_pos
    (@ add
      (@ add `((lambda (x) (+ x 1)) ,pos) (@ mul (input_byte pos) range_len))
      amount_len)))
    (@ add `((lambda (x) (+ x 1)) ,k_pos)
      (@ mul (input_byte k_pos) addr_len)))))

(define request_end (lambda (pos)
  (@ add
    (@ add
      (@ add `((lambda (x) (+ x 1)) ,pos) (@ mul (input_byte pos) elem_len))
      amount_len)
    addr_len)))

(define eval_rules (lambdas (k rpos qpos best)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) best)
     (lambda (k~)
     (let ((c (@ rule_code_at rpos qpos)))
       (match (@ eqb c `(0))
          ((True) `(0))
          ((False) (@ eval_rules k~ (rule_end rpos) qpos (@ lower c best))))))
     k)))
  
(define process (lambdas (k qpos n rules)
  ((lambdas (fO fS n) (if (= n 0) (fO 0) (fS (- n 1))))
     (lambda (_) `(Nil))
     (lambda (k~) `(Cons ,(@ eval_rules n rules qpos code_path)
     ,(@ process k~ (request_end qpos) n rules)))
     k)))
  
(define run (lambda (n)
  (@ process (input_byte `(0)) hdr_len n
    (@ add (@ mul (input_byte `((lambda (x) (+ x 1)) ,`(0))) byte_base)
      (input_byte `((lambda (x) (+ x 1)) ,`((lambda (x) (+ x 1)) ,`(0))))))))

