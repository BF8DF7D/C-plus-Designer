#include "FIO.h"

class Talon;

class Doctor {

private: FIO Fio;
private: std::string dolgnost;

public: Doctor();
public: void PrintInfo();

public: Talon* CreateTalon();
public: void ChangeTime(Talon*);

public: FIO GetFIO();
public: std::string GetDolgnost();

public: ~Doctor() {};
};