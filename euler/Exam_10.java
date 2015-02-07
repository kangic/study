class Exam_10{
    static boolean isPrimeNum( int num ){
	for( int i = 2; i <= Math.sqrt(num); ++i ){
	    if( num % i == 0 )
		return false;
	}

	System.out.println("prime num : " + num);
	return true;
    }

    public static void main(String args[]){
	long sumOfPrimes = 2;

	for( int num = 3; num < 2000000; num += 2 ){
	    if( isPrimeNum(num) )
		sumOfPrimes += num;
	}

	System.out.println("total prime num = " + sumOfPrimes);
    }
}