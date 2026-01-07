import java.util.Scanner; 
class Employee { 
private int id; 
private String name; 
private double salary; 
public Employee(int id, String name, double salary) { 
this.id = id; 
this.name = name; 
this.salary = salary; 
} 
public void display() { 
System.out.println("Employee Details:"); 

System.out.println("Employee ID : " + id); 
System.out.println("Employee Name : " + name); 
System.out.println("Employee Salary: ₹" + salary); 
System.out.println("---------------------------");
} 
public void raiseSalary(double percent) { 
if (percent > 0) { 
double increment = salary * percent / 100; 
salary += increment; 
System.out.println("Salary increased by " + percent + "% (₹" + increment + ")"); 
} else { 
System.out.println("Invalid percentage. Salary not changed."); 
} 
} 
} 
// Main class 
public class pg3 { 
public static void main(String[] args) { 
Scanner sc = new Scanner(System.in); 
// Input employee details 
System.out.print("Enter Employee ID: "); 
int id = sc.nextInt(); 
sc.nextLine(); 
System.out.print("Enter Employee Name: "); 
String name = sc.nextLine(); 
System.out.print("Enter Employee Salary: "); 
double salary = sc.nextDouble(); 
Employee emp = new Employee(id, name, salary);  
System.out.println("\n--- Employee Details Before Salary Raise ---"); 
emp.display(); 
System.out.print("\nEnter percentage to raise salary: "); 
double percent = sc.nextDouble(); 
emp.raiseSalary(percent); 
System.out.println("\n--- Employee Details After Salary Raise ---"); 
emp.display(); 
sc.close(); 
} 
}
