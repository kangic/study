(define (pascal-tri r c)
  (cond ((= c 1) 1)
	((= c r) 1)
	(else (+ (pascal-tri (- r 1) (- c 1))
		 (pascal-tri (- r 1) c)))))
		       
