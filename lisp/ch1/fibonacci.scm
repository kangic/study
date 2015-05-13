(define (fibo-recursive n)
  (cond ((= n 0) 0)
	((= n 1) 1)
	(else (+ (fibo-recursive (- n 1))
		 (fibo-recursive (- n 2))))))

(define (fibo-iterative n)
  (define (fibo-iter a b count)
    (if (= count 0)
	b
	(fibo-iter (+ a b) a (- count 1))))
  (fibo-iter 1 0 n))

