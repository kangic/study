for i in range(3,1000,3):
    for j in range(4,1000,4):
         for k in range(5,1000,5):
             r1 = i + j + k
             r2 = i*i + j*j
             if( r1 == 1000 and r2 == k*k ):
                 print i*j*k
                 break;
