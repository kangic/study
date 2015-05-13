;; recursive
(define (ex1.11-recursive n)
  (if (< n 3)
      n
      (+ (ex1.11 (- n 1)) (* 2 (ex1.11 (- n 2))) (* 3 (ex1.11 (- n 3))))))

;; iterative
(define (ex1.11-iterative n)
  (define (ex1.11-iter a b c count) ;; a : f(n-1), b : f(n-2), c : f(n-3)
    (if (= count 0)
	a
	(ex1.11-iter b c (+ c (* 2 b) (* 3 a)) (- count 1))))
  (ex1.11-iter 0 1 2 n))
;; (ex1.11-iter 0 1 2 4)
;; (ex1.11-iter 1 2 (+ 2 2 0) 3)
;; (ex1.11-iter (ex1.11-iter 2 4 (+ 4 4 3) 2))
;; (ex1.11-iter (ex1.11-iter (ex1.11-iter 4 11 (+ 11 8 6) 1)))
;; (ex1.11-iter (ex1.11-iter (ex1.11-iter (ex1.11-iter (11 25 (+ 25 22 12) 0)))))
;; return 11
