#include "Person.h"
#include "Meeting.h"

#include "std_lib_facilities.h"
#include "MeetingWindow.h"

int main() {
	setlocale(LC_ALL, "Norwegian");  // Makes printing æ, ø, å, Æ, Ø and Å possible
	cout << "setlocale does not work today ...???\n";
	Car fullCar(0);
	Car car(5);

	Person p1("p1", "p1@ntnu.no");
	Person p2("p2", "p2@ntnu.no");
	Person p3("p3", "p3@ntnu.no", &fullCar);
	Person p4("p4", "p4@ntnu.no", &car);
	Person p5("p5", "p5@ntnu.no");
	Person p6("p6", "p6@ntnu.no");

	Meeting trh1(1, 9, 14, Campus::trh, "C++", &p1);
	trh1.addParticipant(&p3);

	Meeting gjo(1, 9, 14, Campus::gjo, "Fusion", &p2);
	gjo.addParticipant(&p4);

	Meeting trh2(1, 8, 15, Campus::trh, "Faculty naming", &p5);
	trh2.addParticipant(&p6);
	trh2.addParticipant(&p3);
	trh2.addParticipant(&p4);

	vector<string> folks = trh2.getParticipantList();
	for (auto name : folks) cout << name << " ";
	cout << endl;

	cout << "All meetings:\n" << trh1 << '\n' << gjo << '\n' << trh2 << '\n';

	cout << "Persons with free seets to a meeting concurrent with the " << trh1.getSubject() << "-meeting:\n";
	for (auto p : trh1.findPotentialCoDriving()) {
		cout << *p << '\n';
	}

	//// GUI
	constexpr int width = 500;;
	constexpr int height = 600;
	const Point top_left{(x_max() - width) / 2, (y_max() - height) / 2}; // Center window
	MeetingWindow mw{top_left, width, height, "Meetings"};
	gui_main();

	mw.printPeople();
}
