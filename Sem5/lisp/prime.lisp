(defun prime (n)
	(let ((i 2))
	    (loop
	    	(if (eq n 1) (return nil))
		( if (> i (floor (/ n 2)))
			(return t)
		  ( if (eq (mod n i) 0)
			(return nil)
		    (setf i (+ 1 i)) 
		  )
		)
	    )
	)
)

(defun main ()
	(print "Enter the lower limit: ")
	(setf a (read))
	(print "Enter the upper limit: ")
	(setf b (read))
	
	(loop
	      (if (> a b) exit)
	      (if (prime a) (print a))
	      (incf a)
	)
)

(main)
