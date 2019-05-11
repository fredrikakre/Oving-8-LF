#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title)
	: Graph_lib::Window(xy, w, h, title),

	quitBtn{ Point{x_max() - btnW - pad, pad}, btnW, btnH, "Quit", cb_quit },

	personName{ Point{fieldPad, pad}, fieldW, btnH, "Name" },
	personEmail{ Point{fieldPad, 2*pad + btnH}, fieldW, btnH, "Email" },
	personNewBtn{ Point{fieldPad, 3*pad + btnH *2}, btnW, btnH, "Add person", cb_new_person }
{
	// Common
	attach(quitBtn);

	// New person
	attach(personName);
	attach(personEmail);
	attach(personNewBtn);
}

void MeetingWindow::addPerson()
{

	const string& name = personName.get_string();
	const string& email = personEmail.get_string();
	if (name.empty() || email.empty()) {
		cerr << "Not enough information to add person.\n";
		return;
	}
	else
	{
		people.push_back(new Person{ name, email/*, car */});
	}
}

// Callback functions
void MeetingWindow::cb_quit(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).hide();
}
void MeetingWindow::cb_new_person(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).addPerson();
}
