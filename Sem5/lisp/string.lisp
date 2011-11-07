(defun len (L)
	(if (null L) 0
		(+ 1 (len (rest L)))
	)
)

(defun rev (L)
	(if (null L) nil 
		(append (rev (rest L)) (list (first L)))
	)
)

(defun palin (L)
	(if (equal L (rev L)) t)
)

(defun main ()
	(print "Enter the string:")
	(defparameter L (read))
	(print "Length is:")
	(print (len L))
	(print "Reverse is:")
	(print (rev L))
	(if (palin L) 
		(print "Is a palindrome")
		(print "Not a palindrome")
	)
)

(main)
