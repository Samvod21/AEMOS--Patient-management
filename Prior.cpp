#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Pat{
    string name;
    int age;
    string type;
    int p;
    Pat* next;
};
Pat *front = nullptr;

void Enqueue(string name, int age, string type, int p){
    Pat *n = new Pat();
    n->name = name;
    n->age = age;
    n->type = type;
    n->p = p;
    n->next = nullptr;

    if (front == nullptr || p > front->p) {
        n->next = front;
        front = n;
    }else{
        Pat* temp = front;
        
        while(temp->next && temp->next->p >= p){
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void display(){
    Pat* temp = front;
    cout << "Name" << '\t' << "Age" << '\t' << "Type" << endl;
    
    while(temp != nullptr){
        cout << temp->name << '\t' << temp->age << '\t' << temp->type << endl;
        temp = temp->next;
    }

    cout << endl;
}

void read(){
    ifstream f("Patient.txt");
    char line[500];

    if(f.is_open()){
        while(f.getline(line, sizeof(line))){
            char *name = strtok(line, "\t");
            char *age = strtok(nullptr, "\t");
            char *type = strtok(nullptr, "\t");
            char *prior = strtok(nullptr, "\t");

            if(name && age && type && prior){
                int page = atoi(age);
                int p = atoi(prior);

                Enqueue(name, page, type, p);
            }else{
                cout << "Missing columns in some rows" << endl;
            }
        }
        f.close();
    }else{
        cout << "Error on opening the file" << endl;
    }
}

void Write(){
    ofstream o("Patient.txt");
    Pat* temp = front;

    if(o.is_open()){
        while(temp != nullptr){
            o << temp->name << '\t' << temp->age << '\t' << temp->type << '\t' << temp->p << endl;
            temp = temp->next;
        }
        o.close();
    }else{
        cout << "Error on opening the file" << endl;
    }
}

void peek(){
    Pat *temp = front;
    front = front->next;

    cout << "Name" << '\t' << "Age" << '\t' << "Type" << endl;
    cout << temp->name << '\t' << temp->age << '\t' << temp->type << endl;

    delete temp;
}

int main(){
    read();
    string name, type;
    int age, p, choice;

    while(true){
        cout << "1. Add patient" << endl;
        cout << "2. Patient list" << endl;
        cout << "3. Next" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        if(choice == 1){
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter medication type(emergency or normal): ";
            cin >> type;

            if(type == "emergency"){
                p = 2;
            }else{
                p = 1;
            }
            Enqueue(name, age, type, p);
        }
        
        else if(choice == 2){
            display();
        }

        else if(choice == 3){
            peek();
        }
        
        else if(choice == 4){
            Write();
            break;
        }
        
        else{
            cout << "Invalid choice";
        }
    }
}