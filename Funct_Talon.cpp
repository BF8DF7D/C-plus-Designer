#define _CRT_SECURE_NO_WARNINGS
#include "Talon.h"
#include <iostream>
#include <iomanip>
#include <sstream>

void Talon::PrintInfo() {
	std::string name = GetDoctor().GetFIO().GetFullName();
	std::cout << " | "; 
	std::cout << std::setfill(' ') << std::setw(45) << name;
	std::cout << " | ";
	Admission_Date.PrintInfo();
	std::cout << " | ";
	Admission_Time.PrintInfo();
	std::cout << " | ";
	std::cout << std::setfill('0') << std::setw(3) << GetKabinet() << " |";
	std::cout.fill(' ');
	std::cout << std::endl;
}

Talon* Doctor::CreateTalon() {
	Talon* AdmissionDay = new Talon(this);
	return AdmissionDay;
}

void Doctor::ChangeTime(Talon* talon) {
	talon->Admission_Date = Date();
}

Talon operator+(Talon& talon, std::string time) {
	for (int dot_position = 0; dot_position != -1;) {
		dot_position = time.find('.');
		if (dot_position != -1)
			time.replace(dot_position, 1, " ");
	}
	Talon value = talon;
	std::stringstream stream(time);
	int minutes = 0,
		hours = 0;
	stream >> hours >> minutes;

	int changing_values[] = { hours, minutes };
	value.Admission_Time.ChangeTime(changing_values, value.Admission_Date);
	return value;
}

Talon operator++(Talon& talon) {
	talon.kabinet += 1;
	return talon;
}

Talon operator++(Talon& talon, int) {
	Talon OldValue = talon;
	talon.kabinet += 1;
	return OldValue;
}

Date Talon::GetDate() {
	return Admission_Date;
}

Time Talon::GetTime() {
	return Admission_Time;
}

int Talon::GetKabinet() {
	return kabinet;
}

Doctor Talon::GetDoctor() {
	return *medic;
}

Talon::Talon(Doctor* medic) {

	bool False_Input_Value;
	enum Limit_Value_for_Number {
		Quantity_input_value = 1,
		Minimum_value_for_number = 0,
		Maximum_number = 999,
		Clean_input_stream = '\n'
	};

	do {
		std::cout << " ����� ��������: ";

		False_Input_Value = scanf("%d", &kabinet) != Quantity_input_value
			|| (kabinet <= Minimum_value_for_number || kabinet > Maximum_number)
			|| std::cin.get() != Clean_input_stream;

		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <����� �������� ������ �����������>" << std::endl;
		}

	} while (False_Input_Value);

	this->medic = medic;

	std::cout << " <���� ��������>" << std::endl;
}

Talon::Talon() {

	bool False_Input_Value;
	enum Limit_Value_for_Number {
		Quantity_input_value = 1,
		Minimum_value_for_number = 0,
		Maximum_number = 999,
		Clean_input_stream = '\n'
	};

	do {
		std::cout << " ����� ��������: ";

		False_Input_Value = scanf("%d", &kabinet) != Quantity_input_value
			|| (kabinet <= Minimum_value_for_number || kabinet > Maximum_number)
			|| std::cin.get() != Clean_input_stream;

		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <����� �������� ������ �����������>" << std::endl;
		}

	} while (False_Input_Value);
	medic = new Doctor();
}

Talon::Talon(Date date, Time time, int kabinet, Doctor& medic) {
	Admission_Date = date;
	Admission_Time = time;
	this->kabinet = kabinet;
	this->medic = &medic;
}


