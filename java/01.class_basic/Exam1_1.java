class Dog {
    private String name; // a2

    Dog()
    {
	name = "happy";
    }

    Dog(String _name)
    {
	this.name = _name;
    }

    String getName() {
	return name;
    }
}

class Exam1_1 {
    public static void main(String args[]) {
	Dog d1 = new Dog(); // a1
	//d.name = "happy"; // can't use this line(because name filed is private field)

	Dog d2 = new Dog("java");

	System.out.println("Dog1 name is " + d1.getName() );
	System.out.println("Dog2 name is " + d2.getName() );
    }
}
