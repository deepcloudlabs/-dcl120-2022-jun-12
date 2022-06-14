#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Component { // abstract class
  public:
    Component(std::string name, double salary) 
          : m_fullName(name), m_valueSalary (salary) {}
    virtual void printSalary(int level) = 0;
    virtual double get_total_salary() = 0;
    virtual int get_total_worker() = 0;
    std::string            m_fullName;
    double                 m_valueSalary;
};

/** "Leaf" */
class Worker : public Component {  
  public:
    Worker(std::string name , double salary): Component(name,salary) {
    }
    void printSalary(int level) {
        for(int j=0; j < level; ++j) cout << "\t";
        cout << "Worker : " <<  
            m_fullName.c_str() << ", salary: " << 
            m_valueSalary << "$\n";
    }
    double get_total_salary() override {
        return m_valueSalary;
    }
    int get_total_worker() override {
        return 1;
    }
};

/** "Composite" */
class Manager: public Component
{
  public:
    Manager(std::string name , double salary) : Component(name,salary) {
    }
    void add(Component *cmp) {
        m_children.push_back(cmp);
    }
    void printSalary(int level) {    
        for(int j=0; j < level; ++j) cout << "\t";
        cout << "Manager : " <<  this->m_fullName.c_str() << 
            ", salary: " << m_valueSalary << "$\n";

        if(!m_children.empty()) {
            for(int x=0; x < level; ++x) cout << "\t";
            cout << "Subordinates  of " <<  
                m_fullName.c_str() << ":\n";
            ++level;
            for (int i = 0; i < m_children.size(); ++i)
              m_children[i]->printSalary(level);
        }
    }
    double get_total_salary() override {
        auto totalSalary=  m_valueSalary;
        for (auto child : m_children){
            totalSalary += child->get_total_salary();
        }
        return totalSalary;
    }
    int get_total_worker() override {
        int totalWorker=0;
        for (auto child : m_children){
            totalWorker += child->get_total_worker();
        }
        return totalWorker;
    }
   private:
    vector < Component * > m_children;
};

int main(){   
    //Let's define a big chief
    Manager president ("Eric Raymond", 500000.0);
    
    //Let's define several average chiefs
    Manager manager_production_department ("Steve Wozniak",400000.0);
    Manager manager_engineering_department ("Donald Knuth",400000.0);
    Manager manager_quality_control_department ("Bjarne Stroustrup",280000.0);
    Manager manager_sales_management_division ("Denis Ritchie",270000.0);
    Manager manager_general_affairs_department ("Richard Stallman" ,200000.0);
    
    //Let's define several managers of a engineering department
    Manager team_leader_RandD ("Ken Thompson", 250000.0); 
    Manager team_leader_QA ("Brian Kernighan", 200000.0); 
    
    //Let's define several engineers of a engineering department
    Worker software_developer1 ("Linus Torvalds", 200000.0);
    Worker software_developer2 ("James Gosling", 240000.0);
    Worker tester ("John McCarthy", 130000.0);
    
    //Now we will add the number of persons as assistants of president
    president.add(&manager_production_department);
    president.add(&manager_engineering_department);
    president.add(&manager_quality_control_department);
    president.add(&manager_sales_management_division);
    president.add(&manager_general_affairs_department );

    //Now we will add the number of persons as assistants of manager engineering department
    manager_engineering_department.add(&team_leader_RandD);
    manager_engineering_department.add(&team_leader_QA );

    //Now we will add the number of persons as assistants of team leader the R&D
    team_leader_RandD.add(&software_developer1);
    team_leader_RandD.add(&software_developer2);

    //Now we will add the tester as assistant of team leader the QA
    team_leader_QA.add(&tester);

    cout << "The hierarchy of the company,\ni.e. president and all who is under his supervision :\n\n" ;
    president.printSalary(0);
    cout << "total salary: " << president.get_total_salary() << endl;
    cout << "total worker: " << president.get_total_worker() << endl;
    cout << '\n';
}
