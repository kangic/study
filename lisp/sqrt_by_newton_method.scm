(define (sqrt-iter guess x)
  (if (good-enough? guess x)
      guess ;; true
      (sqrt-iter (improve guess x) x) ;; false
      ))

(define (improve guess x)
  (average guess (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))

(define (sqrt x)
  (sqrt-iter 1.0 x))
