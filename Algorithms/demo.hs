module Demo where
    class Eq a where
        (==), (/=) :: a -> a -> Bool
    
    instance Eq Bool where
        True == True = True
        False == False = True
        _ == _ = False

        x /= y = not (x ==)
