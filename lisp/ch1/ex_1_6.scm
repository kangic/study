(define (improve guess x)
  (average guess (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
	(else else-clause)))

;; predicate : (good-enough? guess x)
;; then-clause : return guess' value
;; else-clause : call sqrt2
(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
      guess ;; true
      (sqrt-iter (improve guess x) x) ;; false
      ))

(define (sqrt x)
  (sqrt-iter 1.0 x))


;; call to (sqrt2 16)
;; result : Aborting! maximum recursion depth exceeded
;; lisp 실행기는 인자 먼저 계산법(applicative-order evaluation)을 사용한다.
;; 인자로 주어진 값들을 먼저 evaluation 하기 때문에 재귀 호출의 무한 반복이 일어나게 되어 위와 같은 결과가 나오게 된다.

;; 그런데 검색을 하다보니 위 현상은 MIT-Scheme에서만 있는 케이스인가보다...(차후 확인 필요!)
