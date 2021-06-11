#include <iostream>
#pragma warning (disable:4996)

using namespace std;

class Worker {
    char* name;
    char* number;
    int salary;
    float bonus;
public:
    Worker();
    Worker(Worker& var);
    Worker(char* input_name, char* input_number, int input_salary);
    void set_worker(char* input_name, char* input_number, int input_salary);
    void show_worker();
    char* get_name();
    char* get_number();
    int get_salary();
    int get_bonus();
};



Worker::Worker() {
    name = new char[strlen("None") + 1];
    strcpy(name, "None");
    number = new char[strlen("null") + 1];
    strcpy(number, "null");
    salary = -1;
    bonus = -1;
}

Worker::Worker(Worker& var) {
    name = new char[strlen(var.get_name()) + 1];
    strcpy(name, var.get_name());
    number = new char[strlen(var.get_number()) + 1];
    strcpy(number, var.get_number());
    salary = var.get_salary();
    bonus = salary / 10;
}

Worker::Worker(char* input_name, char* input_number, int input_salary) {
    name = new char[strlen(input_name) + 1];
    strcpy(name, input_name);
    number = new char[strlen(input_number) + 1];
    strcpy(number, input_number);
    salary = input_salary;
    bonus = salary / 10;
}

char* Worker::get_name() {
    return this->name;
}

char* Worker::get_number() {
    return this->number;
}

int Worker::get_salary() {
    return this->salary;
}

int Worker::get_bonus() {
    return this->bonus;
}

void Worker::set_worker(char* input_name, char* input_number, int input_salary) {
    this->name = input_name;
    this->number = input_number;
    this->salary = input_salary;
    this->bonus = this->salary / 10;
}

void Worker::show_worker() {
    cout << "Worker name: " << this->name << "\nWorker number: " << this->number;
    cout << "\nWorker salary: " << this->salary << "\nWorker bonus: " << this->bonus << endl<<endl<<endl;
}

void show_worker(Worker* worker) {
    cout << "Worker name: " << worker->get_name() << "\nWorker number: " << worker->get_number();
    cout << "\nWorker salary: " << worker->get_salary() << "\nWorker bonus: " << worker->get_bonus() << endl << endl << endl;
}

int main()
{

    Worker* w1 = new Worker;
    w1->show_worker();
    char name[] = "my_name";
    char number[] = "my_number";
    w1->set_worker(name, number, 100);
    w1->show_worker();
    show_worker(w1);
    Worker w2(*w1);
    w2.show_worker();
}

