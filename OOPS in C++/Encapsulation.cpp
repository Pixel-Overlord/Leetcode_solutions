/* Encapsulation is basically hiding data and revealing only necessary data using access modifiers.
 * ACCESS MODIFIERS :  
 * 
 *      public : access to everyone.
 *      private : access to only in-class.
 *      protected : access to in-class and inherited classes.
 * 
 *  by default every element in a class is private.
 * 
 * Constructors : special functions called during object creation or run-time.
 * 
 */

 #include <iostream>
 using namespace std;

 class Teacher
 {
    public:                         // constructor is always public
        Teacher()                   // this is a non-parameterized constructor
        {
            cout << "This is a constructor." << endl;
        }

        Teacher(string newName, string newSubject)   // this is a parameterized constructor
        {
            name = newName;
            subject = newSubject;
        }
        

    public :
        string name;
        string department;

    private :
        double salary;

    protected :
        string subject;

    private:
        void changeSalary (double newSalary){
            salary = newSalary;
        }

    public:
        void changeSubject (string newSubject){
            subject = newSubject;
        }

        string getSubject()              //getter to display subject which is protected.
        {
            return subject;
        }
 };

 int main()
 {
    Teacher t1;                         //internal constructor is called if no constructor is created.
    Teacher t2("Satish","Biology");     // since parameter, so parameterized constructor is called.

    t1.name = "Dinesh";
    t1.changeSubject("Chemistry");

    cout << "Teacher's name is " << t1.name << ". His subject is " << t1.getSubject() << ".\n";
    cout << "Teacher's name is " << t2.name << ". His subject is " << t2.getSubject() << ".\n";
    
 }