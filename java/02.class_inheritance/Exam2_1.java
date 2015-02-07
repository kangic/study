class Animal{
    Animal()
    {
	System.out.println("Animal");
    }

    void bark(){
	System.out.println("bark animal");
    }
}

class Dog extends Animal{
    Dog()
    {
	System.out.println("Dog");
    }

    void bark(){
	System.out.println("WalWal");
    }
}

class Exam2_1{
    public static void main(String args[]){
	Dog dog = new Dog();

	dog.bark();
    }
}