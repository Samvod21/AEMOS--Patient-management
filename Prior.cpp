#include <iostream>
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

int main(){
    string name, type;
    int age, p, choice;

    while(true){
        cout << "1. Add patient" << endl;
        cout << "2. Patient list" << endl;
        cout << "3. Exit" << endl;
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
            break;
        }
        
        else{
            cout << "Invalid choice";
        }
    }
}