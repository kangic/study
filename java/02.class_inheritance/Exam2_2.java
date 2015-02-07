class Phone {
  public int cpu_speed;
  public int ram_size;

  public Phone(int _cpu_speed, int _ram_size) {
    cpu_speed = _cpu_speed;
    ram_size = _ram_size;
  }

  public void printPhoneInfo() {
    System.out.println("Phone Info - cpu_speed : " + cpu_speed + ", ram_size : " + ram_size);
  }
}

class IPhone extends Phone {
  public int camera_pixel;

  public IPhone(int _cpu_speed, int _ram_size, int _camera_pixel) {
    super(_cpu_speed, _ram_size);
    camera_pixel = _camera_pixel;
  }

  public void printPhoneInfo() {
    super.printPhoneInfo();
    System.out.println("camera_pixel : " + camera_pixel);
  }
}

class Exam2_2 {
  public static void main(String[] args) {
    Phone old_phone = new Phone(400, 32);
    old_phone.printPhoneInfo();

    IPhone new_phone = new IPhone(3200, 2048, 800);
    new_phone.printPhoneInfo();
  }
}
    
  
