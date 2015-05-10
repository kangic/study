;; ex 1.3 세 숫자를 인자로 받아 그 가운데 큰 숫자 두개를 제곱한 다음, 그 두값을 덧셈하여 내놓는 프로시저를 정의하라.
(define (min-val x y)
  (if (> x y) y x))
  
(define (max-val x y)
  (if (> x y) x y))

(define (ex1.3 a b c)
  (define x (max-val a b))
  (define y (max-val (min-val a b) c))
  (+ (* x x) (* y y)))
