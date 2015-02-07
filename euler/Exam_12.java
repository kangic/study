class Exam_12{
    public static void main(String args[]){
	int index = 2;
	int num = 1;

	while( true ){
	    int jisu_sum = 1;
	    num += index;

	    int divide_num = num;
	    for( int i = 2; ; ++i ){
		int jisu = 1;
		while( true ){
		    if( (divide_num % i) == 0 ){
			++jisu;
			divide_num = divide_num / i;
		    }else{
			jisu_sum = jisu_sum * jisu;
			break;
		    }
		}

		if( divide_num == 1 )
		    break;
	    }

	    if( jisu_sum >= 500 ){
		System.out.println("jisu_sum : " + jisu_sum + ", num : " + num);
		break;
	    }

	    ++index;
	}
    }
}