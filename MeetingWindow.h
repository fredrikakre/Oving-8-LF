// MeetingWindow.h
#pragma once
#include "Window.h"
#include "GUI.h"
#include "Meeting.h"
#include "Person.h"
#include "Graph_lib.h"
using namespace Graph_lib;

// Meeting GUI, this implementation handles program state in the Window class
class MeetingWindow : public Graph_lib::Window {
public:
	static constexpr int btnW = 100; 
	static constexpr int btnH = 20;
	static constexpr int pad = 20;
	static constexpr int fieldPad = 60;
	static constexpr int fieldW = 230;
	static constexpr int fieldH = 15;

	MeetingWindow(Point xy, int w, int h, const string& title);

	void printPeople() const {
		for (auto& p : people)
		{
			cout << *p << endl;
		}
	}

private:
	// Program data
	Vector_ref<Person> people;

	Button quitBtn;

	// Person
	In_box personName;
	In_box personEmail;
	Button personNewBtn;
	void addPerson();

	static void cb_quit(Address, Address pw);
	static void cb_new_person(Address, Address pw);
};
