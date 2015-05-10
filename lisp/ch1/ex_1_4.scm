;; 다음 프로시저에 인자를 주고 어떻게 계산되는지 밝혀 보라.
(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

;; b가 0보다 크므로 (+ a b)
(a-plus-abs-b 5 3)

;; b가 0보다 작으므로 (- a b)
(a-plus-abs-b 5 -3)
