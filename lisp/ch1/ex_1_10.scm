(define (A x y)
  (cond ((= y 0) 0)
	((= x 0) (* 2 y))
	((= y 1) 2)
	(else (A (- x 1)
		 (A x (- y 1))))))

(define (f n) (A 0 n)) ;; 2n

(define (g n) (A 1 n)) ;; 2^n

(define (h n) (A 2 n)) ;; 2^2^2...(n times)
;; (A 2 3)
;; (A 1 (A 2 2))
;; (A 1 (A 1 (A 2 1)))
;; (A 1 (A 1 2))
;; (A 1 (A 0 (A 1 1)))
;; (A 1 (A 0 2))
;; (A 1 4)
;; (A 0 (A 1 3))
;; (A 0 (A 0 (A 1 2)))
;; (A 0 (A 0 (A 0 (A 1 1))))
;; (A 0 (A 0 (A 0 2)))
;; (A 0 (A 0 4))
;; (A 0 8)
;; 16

