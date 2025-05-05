#pragma once
#include <string>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>
//#include <Windows.h>
#include <exception>



//namespace Patientmgmtsystem {


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace msclr::interop;
using namespace std;
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

struct Node {
	string patName;
	int patAge;
	string patPhone;
	string patAddress;
	int patCondition;
	Node* next = nullptr;

};
Node* head = nullptr;

void Enqueue(string name, int age, string phone, string address, string patCon);
void Write();
bool isEmpty();
Node* peek();
string PrioValToName(int val);
void dequeue();
void read();

public ref class MyForm : public System::Windows::Forms::Form
{
public:
	MyForm(void)
	{
		InitializeComponent();
		read();
		this->FormClosing += gcnew FormClosingEventHandler(this, &MyForm::OnFormClosing);

		//
		//TODO: Add the constructor code here
		//			
	}

public:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~MyForm()
	{
		if (components)
		{
			delete components;
		}
	}
private:
	void OnFormClosing(Object^ sender, FormClosingEventArgs^ e) {
		

		if (MessageBox::Show("Are you sure you want to close the application?",
			"Confirm Exit", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			Write();
			
		}
		else {
			e->Cancel = true;
		}
	}
private: System::Windows::Forms::Panel^ mainWrapper;
protected:

private: System::Windows::Forms::Panel^ navBar;
private: System::Windows::Forms::Panel^ homePage;
private: System::Windows::Forms::Panel^ addPatientPage;

private: System::Windows::Forms::Panel^ viewPatientsPage;
private: System::Windows::Forms::Button^ addPatient;







private: System::Windows::Forms::Button^ nextPatient;
private: System::Windows::Forms::Button^ viewPatients;



private: System::Windows::Forms::Label^ homeLabel1;
private: System::Windows::Forms::Label^ homeLabel2;






private: System::Windows::Forms::Label^ patientNameLabel;
private: System::Windows::Forms::Label^ phoneLabel;

private: System::Windows::Forms::Label^ ageLabel;
private: System::Windows::Forms::Label^ addressLabel;
public: System::Windows::Forms::TextBox^ patNameTxt;
public: System::Windows::Forms::TextBox^ addressTxt;
public: System::Windows::Forms::NumericUpDown^ ageInput;


public: System::Windows::Forms::TextBox^ phoneTxt;
private: System::Windows::Forms::GroupBox^ priorityGrBox;
private: System::Windows::Forms::RadioButton^ regularRbtn;

private: System::Windows::Forms::RadioButton^ urgentRbtn;
private: System::Windows::Forms::RadioButton^ emergencyRbtn;
private: System::Windows::Forms::Button^ addBtn;

private: System::Windows::Forms::Button^ clearBtn;
private: System::Windows::Forms::Panel^ nextPatientPage;
private: System::Windows::Forms::Label^ nxtPatientCon;
private: System::Windows::Forms::Label^ nxtPatientAddress;
private: System::Windows::Forms::Label^ nxtPatientNumber;
private: System::Windows::Forms::Label^ nxtPatientAge;
private: System::Windows::Forms::Label^ nxtPatientName;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::TextBox^ nxtNameTxt;
private: System::Windows::Forms::TextBox^ nxtConTxt;


private: System::Windows::Forms::TextBox^ nxtAddressTxt;

private: System::Windows::Forms::TextBox^ nxtPhoneTxt;


private: System::Windows::Forms::TextBox^ nxtAgeTxt;
private: System::Windows::Forms::DataGridView^ patientList;



private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Age;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ PhoneNum;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Address;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Condition;
private: System::Windows::Forms::CheckBox^ isPatientTreated;





































protected:

private:
	/// <summary>
	/// Required designer variable.
	/// </summary>
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->mainWrapper = (gcnew System::Windows::Forms::Panel());
		this->navBar = (gcnew System::Windows::Forms::Panel());
		this->nextPatient = (gcnew System::Windows::Forms::Button());
		this->viewPatients = (gcnew System::Windows::Forms::Button());
		this->addPatient = (gcnew System::Windows::Forms::Button());
		this->addPatientPage = (gcnew System::Windows::Forms::Panel());
		this->clearBtn = (gcnew System::Windows::Forms::Button());
		this->addBtn = (gcnew System::Windows::Forms::Button());
		this->priorityGrBox = (gcnew System::Windows::Forms::GroupBox());
		this->regularRbtn = (gcnew System::Windows::Forms::RadioButton());
		this->urgentRbtn = (gcnew System::Windows::Forms::RadioButton());
		this->emergencyRbtn = (gcnew System::Windows::Forms::RadioButton());
		this->addressTxt = (gcnew System::Windows::Forms::TextBox());
		this->ageInput = (gcnew System::Windows::Forms::NumericUpDown());
		this->phoneTxt = (gcnew System::Windows::Forms::TextBox());
		this->patNameTxt = (gcnew System::Windows::Forms::TextBox());
		this->addressLabel = (gcnew System::Windows::Forms::Label());
		this->phoneLabel = (gcnew System::Windows::Forms::Label());
		this->ageLabel = (gcnew System::Windows::Forms::Label());
		this->patientNameLabel = (gcnew System::Windows::Forms::Label());
		this->nextPatientPage = (gcnew System::Windows::Forms::Panel());
		this->isPatientTreated = (gcnew System::Windows::Forms::CheckBox());
		this->nxtConTxt = (gcnew System::Windows::Forms::TextBox());
		this->nxtAddressTxt = (gcnew System::Windows::Forms::TextBox());
		this->nxtPhoneTxt = (gcnew System::Windows::Forms::TextBox());
		this->nxtAgeTxt = (gcnew System::Windows::Forms::TextBox());
		this->nxtNameTxt = (gcnew System::Windows::Forms::TextBox());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->viewPatientsPage = (gcnew System::Windows::Forms::Panel());
		this->patientList = (gcnew System::Windows::Forms::DataGridView());
		this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Age = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->PhoneNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Condition = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->homePage = (gcnew System::Windows::Forms::Panel());
		this->homeLabel2 = (gcnew System::Windows::Forms::Label());
		this->homeLabel1 = (gcnew System::Windows::Forms::Label());
		this->mainWrapper->SuspendLayout();
		this->navBar->SuspendLayout();
		this->addPatientPage->SuspendLayout();
		this->priorityGrBox->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ageInput))->BeginInit();
		this->nextPatientPage->SuspendLayout();
		this->viewPatientsPage->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->patientList))->BeginInit();
		this->homePage->SuspendLayout();
		this->SuspendLayout();
		// 
		// mainWrapper
		// 
		this->mainWrapper->Controls->Add(this->navBar);
		this->mainWrapper->Controls->Add(this->addPatientPage);
		this->mainWrapper->Controls->Add(this->nextPatientPage);
		this->mainWrapper->Controls->Add(this->viewPatientsPage);
		this->mainWrapper->Location = System::Drawing::Point(-3, 1);
		this->mainWrapper->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->mainWrapper->Name = L"mainWrapper";
		this->mainWrapper->Size = System::Drawing::Size(1440, 900);
		this->mainWrapper->TabIndex = 0;
		// 
		// navBar
		// 
		this->navBar->BackColor = System::Drawing::Color::BlueViolet;
		this->navBar->Controls->Add(this->nextPatient);
		this->navBar->Controls->Add(this->viewPatients);
		this->navBar->Controls->Add(this->addPatient);
		this->navBar->Location = System::Drawing::Point(3, 0);
		this->navBar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->navBar->Name = L"navBar";
		this->navBar->Size = System::Drawing::Size(299, 850);
		this->navBar->TabIndex = 0;
		// 
		// nextPatient
		// 
		this->nextPatient->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->nextPatient->Location = System::Drawing::Point(32, 212);
		this->nextPatient->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->nextPatient->Name = L"nextPatient";
		this->nextPatient->Size = System::Drawing::Size(193, 49);
		this->nextPatient->TabIndex = 8;
		this->nextPatient->Text = L"Next Patient";
		this->nextPatient->UseVisualStyleBackColor = true;
		this->nextPatient->Click += gcnew System::EventHandler(this, &MyForm::nextPatient_Click);
		// 
		// viewPatients
		// 
		this->viewPatients->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->viewPatients->Location = System::Drawing::Point(32, 339);
		this->viewPatients->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->viewPatients->Name = L"viewPatients";
		this->viewPatients->Size = System::Drawing::Size(193, 49);
		this->viewPatients->TabIndex = 6;
		this->viewPatients->Text = L"View Patients";
		this->viewPatients->UseVisualStyleBackColor = true;
		this->viewPatients->Click += gcnew System::EventHandler(this, &MyForm::viewPatients_Click);
		// 
		// addPatient
		// 
		this->addPatient->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->addPatient->Location = System::Drawing::Point(32, 89);
		this->addPatient->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->addPatient->Name = L"addPatient";
		this->addPatient->Size = System::Drawing::Size(193, 49);
		this->addPatient->TabIndex = 0;
		this->addPatient->Text = L"Add Patient";
		this->addPatient->UseVisualStyleBackColor = true;
		this->addPatient->Click += gcnew System::EventHandler(this, &MyForm::addPatient_Click);
		// 
		// addPatientPage
		// 
		this->addPatientPage->BackColor = System::Drawing::Color::White;
		this->addPatientPage->Controls->Add(this->clearBtn);
		this->addPatientPage->Controls->Add(this->addBtn);
		this->addPatientPage->Controls->Add(this->priorityGrBox);
		this->addPatientPage->Controls->Add(this->addressTxt);
		this->addPatientPage->Controls->Add(this->ageInput);
		this->addPatientPage->Controls->Add(this->phoneTxt);
		this->addPatientPage->Controls->Add(this->patNameTxt);
		this->addPatientPage->Controls->Add(this->addressLabel);
		this->addPatientPage->Controls->Add(this->phoneLabel);
		this->addPatientPage->Controls->Add(this->ageLabel);
		this->addPatientPage->Controls->Add(this->patientNameLabel);
		this->addPatientPage->Location = System::Drawing::Point(301, 0);
		this->addPatientPage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->addPatientPage->Name = L"addPatientPage";
		this->addPatientPage->Size = System::Drawing::Size(1085, 850);
		this->addPatientPage->TabIndex = 2;
		// 
		// clearBtn
		// 
		this->clearBtn->BackColor = System::Drawing::Color::Crimson;
		this->clearBtn->Cursor = System::Windows::Forms::Cursors::Hand;
		this->clearBtn->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->clearBtn->ForeColor = System::Drawing::Color::White;
		this->clearBtn->Location = System::Drawing::Point(829, 698);
		this->clearBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->clearBtn->Name = L"clearBtn";
		this->clearBtn->Size = System::Drawing::Size(173, 50);
		this->clearBtn->TabIndex = 10;
		this->clearBtn->Text = L"Clear";
		this->clearBtn->UseVisualStyleBackColor = false;
		this->clearBtn->Click += gcnew System::EventHandler(this, &MyForm::clearBtn_Click);
		// 
		// addBtn
		// 
		this->addBtn->BackColor = System::Drawing::Color::OliveDrab;
		this->addBtn->Cursor = System::Windows::Forms::Cursors::Hand;
		this->addBtn->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->addBtn->ForeColor = System::Drawing::Color::White;
		this->addBtn->Location = System::Drawing::Point(617, 698);
		this->addBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->addBtn->Name = L"addBtn";
		this->addBtn->Size = System::Drawing::Size(164, 50);
		this->addBtn->TabIndex = 9;
		this->addBtn->Text = L"Add";
		this->addBtn->UseVisualStyleBackColor = false;
		this->addBtn->Click += gcnew System::EventHandler(this, &MyForm::addBtn_Click);
		// 
		// priorityGrBox
		// 
		this->priorityGrBox->Controls->Add(this->regularRbtn);
		this->priorityGrBox->Controls->Add(this->urgentRbtn);
		this->priorityGrBox->Controls->Add(this->emergencyRbtn);
		this->priorityGrBox->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->priorityGrBox->Location = System::Drawing::Point(84, 465);
		this->priorityGrBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->priorityGrBox->Name = L"priorityGrBox";
		this->priorityGrBox->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->priorityGrBox->Size = System::Drawing::Size(683, 123);
		this->priorityGrBox->TabIndex = 8;
		this->priorityGrBox->TabStop = false;
		this->priorityGrBox->Text = L"Patient Condition";
		// 
		// regularRbtn
		// 
		this->regularRbtn->AutoSize = true;
		this->regularRbtn->Checked = true;
		this->regularRbtn->Location = System::Drawing::Point(429, 47);
		this->regularRbtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->regularRbtn->Name = L"regularRbtn";
		this->regularRbtn->Size = System::Drawing::Size(113, 35);
		this->regularRbtn->TabIndex = 2;
		this->regularRbtn->TabStop = true;
		this->regularRbtn->Text = L"Regular";
		this->regularRbtn->UseVisualStyleBackColor = true;
		// 
		// urgentRbtn
		// 
		this->urgentRbtn->AutoSize = true;
		this->urgentRbtn->Location = System::Drawing::Point(233, 47);
		this->urgentRbtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->urgentRbtn->Name = L"urgentRbtn";
		this->urgentRbtn->Size = System::Drawing::Size(106, 35);
		this->urgentRbtn->TabIndex = 1;
		this->urgentRbtn->Text = L"Urgent";
		this->urgentRbtn->UseVisualStyleBackColor = true;
		// 
		// emergencyRbtn
		// 
		this->emergencyRbtn->AutoSize = true;
		this->emergencyRbtn->Location = System::Drawing::Point(20, 47);
		this->emergencyRbtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->emergencyRbtn->Name = L"emergencyRbtn";
		this->emergencyRbtn->Size = System::Drawing::Size(148, 35);
		this->emergencyRbtn->TabIndex = 0;
		this->emergencyRbtn->Text = L"Emergency";
		this->emergencyRbtn->UseVisualStyleBackColor = true;
		// 
		// addressTxt
		// 
		this->addressTxt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->addressTxt->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->addressTxt->Location = System::Drawing::Point(267, 357);
		this->addressTxt->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->addressTxt->Name = L"addressTxt";
		this->addressTxt->Size = System::Drawing::Size(307, 34);
		this->addressTxt->TabIndex = 7;
		// 
		// ageInput
		// 
		this->ageInput->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->ageInput->Location = System::Drawing::Point(267, 196);
		this->ageInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->ageInput->Name = L"ageInput";
		this->ageInput->Size = System::Drawing::Size(120, 34);
		this->ageInput->TabIndex = 6;
		// 
		// phoneTxt
		// 
		this->phoneTxt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->phoneTxt->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->phoneTxt->Location = System::Drawing::Point(267, 278);
		this->phoneTxt->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->phoneTxt->Name = L"phoneTxt";
		this->phoneTxt->Size = System::Drawing::Size(307, 34);
		this->phoneTxt->TabIndex = 5;
		// 
		// patNameTxt
		// 
		this->patNameTxt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->patNameTxt->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->patNameTxt->Location = System::Drawing::Point(267, 121);
		this->patNameTxt->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->patNameTxt->Name = L"patNameTxt";
		this->patNameTxt->Size = System::Drawing::Size(307, 34);
		this->patNameTxt->TabIndex = 4;
		// 
		// addressLabel
		// 
		this->addressLabel->AutoSize = true;
		this->addressLabel->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->addressLabel->Location = System::Drawing::Point(77, 357);
		this->addressLabel->Name = L"addressLabel";
		this->addressLabel->Size = System::Drawing::Size(97, 31);
		this->addressLabel->TabIndex = 3;
		this->addressLabel->Text = L"Address";
		// 
		// phoneLabel
		// 
		this->phoneLabel->AutoSize = true;
		this->phoneLabel->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->phoneLabel->Location = System::Drawing::Point(77, 278);
		this->phoneLabel->Name = L"phoneLabel";
		this->phoneLabel->Size = System::Drawing::Size(168, 31);
		this->phoneLabel->TabIndex = 2;
		this->phoneLabel->Text = L"Phone Number";
		// 
		// ageLabel
		// 
		this->ageLabel->AutoSize = true;
		this->ageLabel->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->ageLabel->Location = System::Drawing::Point(77, 196);
		this->ageLabel->Name = L"ageLabel";
		this->ageLabel->Size = System::Drawing::Size(55, 31);
		this->ageLabel->TabIndex = 1;
		this->ageLabel->Text = L"Age";
		// 
		// patientNameLabel
		// 
		this->patientNameLabel->AutoSize = true;
		this->patientNameLabel->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->patientNameLabel->Location = System::Drawing::Point(77, 121);
		this->patientNameLabel->Name = L"patientNameLabel";
		this->patientNameLabel->Size = System::Drawing::Size(152, 31);
		this->patientNameLabel->TabIndex = 0;
		this->patientNameLabel->Text = L"Patient Name";
		// 
		// nextPatientPage
		// 
		this->nextPatientPage->BackColor = System::Drawing::Color::White;
		this->nextPatientPage->Controls->Add(this->isPatientTreated);
		this->nextPatientPage->Controls->Add(this->nxtConTxt);
		this->nextPatientPage->Controls->Add(this->nxtAddressTxt);
		this->nextPatientPage->Controls->Add(this->nxtPhoneTxt);
		this->nextPatientPage->Controls->Add(this->nxtAgeTxt);
		this->nextPatientPage->Controls->Add(this->nxtNameTxt);
		this->nextPatientPage->Controls->Add(this->label5);
		this->nextPatientPage->Controls->Add(this->label4);
		this->nextPatientPage->Controls->Add(this->label3);
		this->nextPatientPage->Controls->Add(this->label2);
		this->nextPatientPage->Controls->Add(this->label1);
		this->nextPatientPage->Location = System::Drawing::Point(301, 0);
		this->nextPatientPage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->nextPatientPage->Name = L"nextPatientPage";
		this->nextPatientPage->Size = System::Drawing::Size(1085, 850);
		this->nextPatientPage->TabIndex = 3;
		// 
		// isPatientTreated
		// 
		this->isPatientTreated->AutoSize = true;
		this->isPatientTreated->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->isPatientTreated->Location = System::Drawing::Point(372, 635);
		this->isPatientTreated->Name = L"isPatientTreated";
		this->isPatientTreated->Size = System::Drawing::Size(258, 35);
		this->isPatientTreated->TabIndex = 10;
		this->isPatientTreated->Text = L"Treatment Completed";
		this->isPatientTreated->UseVisualStyleBackColor = true;
		// 
		// nxtConTxt
		// 
		this->nxtConTxt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->nxtConTxt->Enabled = false;
		this->nxtConTxt->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->nxtConTxt->Location = System::Drawing::Point(319, 532);
		this->nxtConTxt->Name = L"nxtConTxt";
		this->nxtConTxt->Size = System::Drawing::Size(291, 34);
		this->nxtConTxt->TabIndex = 9;
		// 
		// nxtAddressTxt
		// 
		this->nxtAddressTxt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->nxtAddressTxt->Enabled = false;
		this->nxtAddressTxt->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->nxtAddressTxt->Location = System::Drawing::Point(319, 421);
		this->nxtAddressTxt->Name = L"nxtAddressTxt";
		this->nxtAddressTxt->Size = System::Drawing::Size(291, 34);
		this->nxtAddressTxt->TabIndex = 8;
		// 
		// nxtPhoneTxt
		// 
		this->nxtPhoneTxt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->nxtPhoneTxt->Enabled = false;
		this->nxtPhoneTxt->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->nxtPhoneTxt->Location = System::Drawing::Point(319, 317);
		this->nxtPhoneTxt->Name = L"nxtPhoneTxt";
		this->nxtPhoneTxt->Size = System::Drawing::Size(291, 34);
		this->nxtPhoneTxt->TabIndex = 7;
		// 
		// nxtAgeTxt
		// 
		this->nxtAgeTxt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->nxtAgeTxt->Enabled = false;
		this->nxtAgeTxt->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->nxtAgeTxt->Location = System::Drawing::Point(319, 203);
		this->nxtAgeTxt->Name = L"nxtAgeTxt";
		this->nxtAgeTxt->Size = System::Drawing::Size(291, 34);
		this->nxtAgeTxt->TabIndex = 6;
		// 
		// nxtNameTxt
		// 
		this->nxtNameTxt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->nxtNameTxt->Enabled = false;
		this->nxtNameTxt->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->nxtNameTxt->Location = System::Drawing::Point(319, 107);
		this->nxtNameTxt->Name = L"nxtNameTxt";
		this->nxtNameTxt->Size = System::Drawing::Size(291, 34);
		this->nxtNameTxt->TabIndex = 5;
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label5->Location = System::Drawing::Point(81, 536);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(216, 31);
		this->label5->TabIndex = 4;
		this->label5->Text = L"Patient\'s Condition: ";
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label4->Location = System::Drawing::Point(81, 425);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(185, 31);
		this->label4->TabIndex = 3;
		this->label4->Text = L"Patient Address: ";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label3->Location = System::Drawing::Point(81, 317);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(180, 31);
		this->label3->TabIndex = 2;
		this->label3->Text = L"Phone Number: ";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label2->Location = System::Drawing::Point(81, 206);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(157, 31);
		this->label2->TabIndex = 1;
		this->label2->Text = L"Patient\'s Age: ";
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label1->Location = System::Drawing::Point(81, 107);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(163, 31);
		this->label1->TabIndex = 0;
		this->label1->Text = L"Patient Name: ";
		// 
		// viewPatientsPage
		// 
		this->viewPatientsPage->BackColor = System::Drawing::Color::White;
		this->viewPatientsPage->Controls->Add(this->patientList);
		this->viewPatientsPage->Location = System::Drawing::Point(301, 0);
		this->viewPatientsPage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->viewPatientsPage->Name = L"viewPatientsPage";
		this->viewPatientsPage->Size = System::Drawing::Size(1085, 850);
		this->viewPatientsPage->TabIndex = 4;
		// 
		// patientList
		// 
		this->patientList->Anchor = System::Windows::Forms::AnchorStyles::Top;
		this->patientList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->patientList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
			this->Name, this->Age,
				this->PhoneNum, this->Address, this->Condition
		});
		this->patientList->Location = System::Drawing::Point(0, 0);
		this->patientList->Name = L"patientList";
		this->patientList->RowHeadersWidth = 60;
		this->patientList->RowTemplate->Height = 30;
		this->patientList->Size = System::Drawing::Size(1085, 850);
		this->patientList->TabIndex = 0;
		// 
		// Name
		// 
		this->Name->HeaderText = L"Name";
		this->Name->MinimumWidth = 10;
		this->Name->Name = L"Name";
		this->Name->Width = 150;
		// 
		// Age
		// 
		this->Age->HeaderText = L"Age";
		this->Age->MinimumWidth = 6;
		this->Age->Name = L"Age";
		this->Age->Width = 125;
		// 
		// PhoneNum
		// 
		this->PhoneNum->HeaderText = L"PhoneNum";
		this->PhoneNum->MinimumWidth = 6;
		this->PhoneNum->Name = L"PhoneNum";
		this->PhoneNum->Width = 125;
		// 
		// Address
		// 
		this->Address->HeaderText = L"Address";
		this->Address->MinimumWidth = 6;
		this->Address->Name = L"Address";
		this->Address->Width = 125;
		// 
		// Condition
		// 
		this->Condition->HeaderText = L"Condition";
		this->Condition->MinimumWidth = 6;
		this->Condition->Name = L"Condition";
		this->Condition->Width = 125;
		// 
		// homePage
		// 
		this->homePage->BackColor = System::Drawing::Color::GreenYellow;
		this->homePage->Controls->Add(this->homeLabel2);
		this->homePage->Controls->Add(this->homeLabel1);
		this->homePage->Location = System::Drawing::Point(301, 0);
		this->homePage->Name = L"homePage";
		this->homePage->Size = System::Drawing::Size(1086, 850);
		this->homePage->TabIndex = 1;
		// 
		// homeLabel2
		// 
		this->homeLabel2->AutoSize = true;
		this->homeLabel2->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->homeLabel2->Location = System::Drawing::Point(319, 382);
		this->homeLabel2->Name = L"homeLabel2";
		this->homeLabel2->Size = System::Drawing::Size(368, 96);
		this->homeLabel2->TabIndex = 1;
		this->homeLabel2->Text = L"System";
		// 
		// homeLabel1
		// 
		this->homeLabel1->AutoSize = true;
		this->homeLabel1->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 42, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->homeLabel1->Location = System::Drawing::Point(60, 272);
		this->homeLabel1->Name = L"homeLabel1";
		this->homeLabel1->Size = System::Drawing::Size(939, 85);
		this->homeLabel1->TabIndex = 0;
		this->homeLabel1->Text = L"Patient Management";
		// 
		// MyForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(1381, 846);
		this->Controls->Add(this->mainWrapper);
		this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->MaximizeBox = false;
		this->Text = L"Patient Management System";
		this->mainWrapper->ResumeLayout(false);
		this->navBar->ResumeLayout(false);
		this->addPatientPage->ResumeLayout(false);
		this->addPatientPage->PerformLayout();
		this->priorityGrBox->ResumeLayout(false);
		this->priorityGrBox->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ageInput))->EndInit();
		this->nextPatientPage->ResumeLayout(false);
		this->nextPatientPage->PerformLayout();
		this->viewPatientsPage->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->patientList))->EndInit();
		this->homePage->ResumeLayout(false);
		this->homePage->PerformLayout();
		this->ResumeLayout(false);

	}
#pragma endregion


public: System::String^ CheckedPatientCondition() {

	if (emergencyRbtn->Checked) {
		return "Emergency";
	}
	else if (urgentRbtn->Checked) {
		return "Urgent";
	}
	return "Regular";

}

public: void addDataToTable() {
	patientList->Rows->Clear();
	patientList->DefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 12);
	Node* temp = head;

	while (temp) {
		String^ name = gcnew String(temp->patName.c_str());
		String^ age = temp->patAge.ToString(); // Assuming patAge is an int
		String^ phone = gcnew String(temp->patPhone.c_str());
		String^ address = gcnew String(temp->patAddress.c_str());
		string result = PrioValToName(temp->patCondition);
		String^ condition = gcnew String(result.c_str());
	
		patientList->Rows->Add(name, age, phone, address, condition);

		temp = temp->next; 
	}
}
public: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	string name = marshal_as<string>(patNameTxt->Text);
	int age = static_cast<int>(ageInput->Value);
	string phone = marshal_as<string>(phoneTxt->Text);
	string address = marshal_as<string>(addressTxt->Text);
	string patCondition = marshal_as<string>(CheckedPatientCondition());
	try {
		Enqueue(name, age, phone, address, patCondition);
		MessageBox::Show("Succesfully Added", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Data is not added", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	

}
private: System::Void clearBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	patNameTxt->Text = "";
	ageInput->Value = 0;
	phoneTxt->Text = "";
	addressTxt->Text = "";
	regularRbtn->Checked = true;
}
private: System::Void addPatient_Click(System::Object^ sender, System::EventArgs^ e) {	
	this->mainWrapper->Controls->Clear();
	this->mainWrapper->Controls->Add(this->navBar);
	//nextPatientPage->Visible = false;
	//viewPatientsPage->Visible = false;
	this->mainWrapper->Controls->Add(this->addPatientPage);
	if (isPatientTreated->Checked) {
		dequeue();
		isPatientTreated->Checked = false;
	}
}

private: System::Void nextPatient_Click(System::Object^ sender, System::EventArgs^ e) {	
	this->mainWrapper->Controls->Clear();
	this->mainWrapper->Controls->Add(this->navBar);
	//addPatientPage->Visible = false;
	//viewPatientsPage->Visible = false;
	
	this->mainWrapper->Controls->Add(this->nextPatientPage);
	Node* temp = peek();
	nxtNameTxt->Text = marshal_as<String^>(temp->patName);
	int result = temp->patAge;
	std::string ageStr = std::to_string(result);
	String^ ageString = msclr::interop::marshal_as<String^>(ageStr);
	nxtAgeTxt->Text = ageString;
	nxtPhoneTxt->Text = marshal_as<String^>(temp->patPhone);
	nxtAddressTxt->Text = marshal_as<String^>(temp->patAddress);
	string value = PrioValToName(temp->patCondition);
	nxtConTxt->Text = marshal_as<String^>(value);	

}
private: System::Void viewPatients_Click(System::Object^ sender, System::EventArgs^ e) {
	this->mainWrapper->Controls->Clear();
	this->mainWrapper->Controls->Add(this->navBar);
	//addPatientPage->Visible = false;
	//nextPatientPage->Visible = false;
	this->mainWrapper->Controls->Add(this->viewPatientsPage);
	//this->mainWrapper->Controls->Add(this->addPatientPage);
	//this->mainWrapper->Controls->Add(this->nextPatientPage);
	if (isPatientTreated->Checked) {
		dequeue();
		isPatientTreated->Checked = false;
	}
	addDataToTable();
}

};


bool isEmpty() {
	return head == nullptr;
}

string PrioValToName(int val) {
	if (val == 0) {
		return "Emergency";
	}
	else if (val == 1) {
		return "Urgent";
	} 
	return "Regular";
}

void Enqueue(string name, int age, string phone, string address, string patCon) {
	Node* n = new Node();
	int prioVal;
	n->patName = name;
	n->patAge = age;
	n->patPhone = phone;
	n->patAddress = address;
	if (patCon == "Emergency") {
		n->patCondition = 0;
	}
	else if (patCon == "Urgent") {
		n->patCondition = 1;
	}
	else if (patCon == "Regular") {
		n->patCondition = 2;
	}
	prioVal = n->patCondition;
	//n->patCondition = patCon;
	n->next = nullptr;

	if (isEmpty() || prioVal < head->patCondition) {
		n->next = head;
		head = n;
	}
	else {
		Node* temp = head;

		while (temp->next && temp->next->patCondition <= prioVal) {
			temp = temp->next;
		}
		n->next = temp->next;
		temp->next = n;
	}	
}
Node* peek() {
	return isEmpty() ? nullptr : head;
}
void dequeue() {
	if (!isEmpty()) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
void read() {
	ifstream f("Patient.txt");
	char line[500];

	if (f.is_open()) {
		while (f.getline(line, sizeof(line))) {
			char* name = strtok(line, "\t");
			char* age = strtok(nullptr, "\t");
			char* phoneNum = strtok(nullptr, "\t");
			char* address = strtok(nullptr, "\t");
			char* type = strtok(nullptr, "\t");

			if (name && age && phoneNum && address && type) {
				int page = atoi(age);
				//int p = atoi(type);

				Enqueue(name, page, phoneNum, address, type);
			}
			else {
				MessageBox::Show("Missing columns in some rows", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		f.close();
	}
	else {
		MessageBox::Show("Error on opening the file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
void Write() {
	ofstream o("Patient.txt");
	Node* temp = head;

	if (o.is_open()) {
		while (temp != nullptr) {
			int value = temp->patCondition;
			string result = PrioValToName(value);
			/*if (value == 0) {
				result = "Emergency";
			}
			else if (value == 1) {
				result = "Urgent";
			}
			else if (value == 2) {
				result = "Regular";
			}*/
			o << temp->patName << '\t' << temp->patAge << '\t' << temp->patPhone << '\t' << temp->patAddress << '\t' << result << endl;
			temp = temp->next;
		}
		o.close();
	}
	else {
		MessageBox::Show("Error on opening the file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

