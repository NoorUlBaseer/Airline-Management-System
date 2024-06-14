#define _CRT_SECURE_NO_WARNINGS //to disable the warning for using unsafe functions like ctime()
#include<iostream> 
#include <conio.h> //to use _getch() function
#include<stdlib.h> //to use system("cls") function
#include<windows.h> //to use Sleep() function
#include<string> 
#include <ctime> //to use time() function
#include <cmath> //to use pow() function
#include <cstdlib> //to use rand() function
using namespace std;

class airplane { //class for airplane object
private:
	string airplane_id;
	int passengers;
public:
	airplane() {
		airplane_id = "";
		passengers = 0;
	}
	airplane(string id, int n) {
		airplane_id = id;
		passengers = n;
	}
	void set_airplane_id(string id) {
		airplane_id = id;
	}
	void set_passengers(int n) {
		passengers = n;
	}
	string get_airplane_id() {
		return airplane_id;
	}
	int get_passengers() {
		return passengers;
	}
};

class airport { //class for airport object
private:
	string airport_name, city_name, country_name;
	int landing_capacity, airplane_count;
	airplane airplanes_available[5];
public:
	airport() {
		airport_name = "";
		city_name = "";
		country_name = "";
		landing_capacity = 0;
		airplane_count = 0;
		for (int i = 0; i < 5; i++) {
			airplanes_available[i] = airplane();
		}
	}
	airport(string name, string city, string country, int capacity, int count) {
		airport_name = name;
		city_name = city;
		country_name = country;
		landing_capacity = capacity;
		airplane_count = count;
		for (int i = 0; i < 5; i++) {
			airplanes_available[i] = airplane();
		}
	}
	void set_airport_name(string name) {
		airport_name = name;
	}
	void set_city_name(string city) {
		city_name = city;
	}
	void set_country_name(string country) {
		country_name = country;
	}
	void set_landing_capacity(int capacity) { //to set the landing capacity of the airport
		landing_capacity = capacity;
	}
	void set_airplane_count(int count) { //to set the number of airplanes available at the airport
		airplane_count = count;
	}
	void set_airplanes_available(airplane a) { //to set the airplanes available at the airport
		if (airplane_count < 5) { //if the airport is not full
			airplanes_available[airplane_count] = a;
			airplane_count++;
		}
		else { //if the airport is full
			cout << "Airport is full" << endl;
		}
	}
	string get_airport_name() {
		return airport_name;
	}
	string get_city_name() {
		return city_name;
	}
	string get_country_name() {
		return country_name;
	}
	int get_landing_capacity() {
		return landing_capacity;
	}
	int get_airplane_count() {
		return airplane_count;
	}
	airplane* get_airplanes_available() { //to get the airplanes available at the airport
		return airplanes_available;
	}
};

class flight { //class for flight object
private:
	string flight_number, departure_date, departure_time, arrival_date, arrival_time;
	airport departure_airport, arrival_airport;
	airplane plane;
	int available_seats_economy, available_seats_business;
	double duration, price;
public:
	flight() {
		flight_number = "";
		departure_date = "";
		departure_time = "";
		arrival_date = "";
		arrival_time = "";
		departure_airport = airport();
		arrival_airport = airport();
		plane = airplane();
		available_seats_economy = 50;
		available_seats_business = 10;
		duration = 0;
		price = 0;
	}
	flight(string number, string date1, string time1, string date2, string time2, airport airport1, airport airport2, airplane p, double d, double price) {
		flight_number = number;
		departure_date = date1;
		departure_time = time1;
		arrival_date = date2;
		arrival_time = time2;
		departure_airport = airport1;
		arrival_airport = airport2;
		plane = p;
		available_seats_economy = 50;
		available_seats_business = 10;
		duration = d;
		this->price = price;
	}
	void set_flight_number(string number) {
		flight_number = number;
	}
	void set_departure_date(string date1) {
		departure_date = date1;
	}
	void set_departure_time(string time1) {
		departure_time = time1;
	}
	void set_arrival_date(string date2) {
		arrival_date = date2;
	}
	void set_arrival_time(string time2) {
		arrival_time = time2;
	}
	void set_departure_airport(airport airport1) {
		departure_airport = airport1;
	}
	void set_arrival_airport(airport airport2) {
		arrival_airport = airport2;
	}
	void set_plane(airplane p) {
		plane = p;
	}
	void set_available_seats_economy(int seats_economy) {
		available_seats_economy = seats_economy;
	}
	void set_available_seats_business(int seats_business) {
		available_seats_business = seats_business;
	}
	void set_duration(double d) {
		duration = d;
	}
	void set_price(double price) {
		this->price = price;
	}
	string get_flight_number() {
		return flight_number;
	}
	string get_departure_date() {
		return departure_date;
	}
	string get_departure_time() {
		return departure_time;
	}
	string get_arrival_date() {
		return arrival_date;
	}
	string get_arrival_time() {
		return arrival_time;
	}
	airport get_departure_airport() {
		return departure_airport;
	}
	airport get_arrival_airport() {
		return arrival_airport;
	}
	airplane get_plane() {
		return plane;
	}
	int get_available_seats_economy() {
		return available_seats_economy;
	}
	int get_available_seats_business() {
		return available_seats_business;
	}
	double get_duration() {
		return duration;
	}
	double get_price() {
		return price;
	}
};

class booking { //class for booking object
private:
	string booking_id, booking_date, departure_date, departure_time, arrival_date, arrival_time, seat_number, status;
	flight flight_details;
public:
	booking() {
		booking_id = "";
		booking_date = "";
		departure_date = "";
		departure_time = "";
		arrival_date = "";
		arrival_time = "";
		seat_number = "";
		status = "Booked";
	}
	booking(string id, string b_date, string d_date, string d_time, string a_date, string a_time, string seat, flight f) {
		booking_id = id;
		booking_date = b_date;
		departure_date = d_date;
		departure_time = d_time;
		arrival_date = a_date;
		arrival_time = a_time;
		seat_number = seat;
		flight_details = f;
		status = "Booked";
	}
	void set_booking_id(string id) {
		booking_id = id;
	}
	void set_booking_date(string b_date) {
		booking_date = b_date;
	}
	void set_departure_date(string d_date) {
		departure_date = d_date;
	}
	void set_departure_time(string d_time) {
		departure_time = d_time;
	}
	void set_arrival_date(string a_date) {
		arrival_date = a_date;
	}
	void set_arrival_time(string a_time) {
		arrival_time = a_time;
	}
	void set_seat_number(string seat) {
		seat_number = seat;
	}
	void set_flight_details(flight f) {
		flight_details = f;
	}
	void set_status(string s) {
		status = s;
	}
	string get_booking_id() {
		return booking_id;
	}
	string get_booking_date() {
		return booking_date;
	}
	string get_departure_date() {
		return departure_date;
	}
	string get_departure_time() {
		return departure_time;
	}
	string get_arrival_date() {
		return arrival_date;
	}
	string get_arrival_time() {
		return arrival_time;
	}
	string get_seat_number() {
		return seat_number;
	}
	string get_status() {
		return status;
	}
	flight get_flight_details() {
		return flight_details;
	}
};

class visa { //class for visa object
private:
	string* issuance_date, * expiry_date, * countries_visa;
	int array_size;
public:
	visa() {
		array_size = 0;
		issuance_date = nullptr;
		expiry_date = nullptr;
		countries_visa = nullptr;
	}
	~visa() { //destructor for dynamic memory deallocation
		delete[] issuance_date;
		delete[] expiry_date;
		delete[] countries_visa;
	}
	void set_visa() { //function to set visas on a passport
		cout << "How many countries Visa do you hold: ";
		cin >> array_size;
		issuance_date = new string[array_size];
		expiry_date = new string[array_size];
		countries_visa = new string[array_size];
		for (int i = 0; i < array_size; i++) {
			cout << "Visa-" << i + 1 << endl;
			cout << "Enter issuance date: ";
			cin >> issuance_date[i];
			cout << "Enter expiry date: ";
			cin >> expiry_date[i];
			cout << "Enter countries: ";
			cin >> countries_visa[i];
		}
	}
	void get_visa() { //function to get visas on a passport
		for (int i = 0; i < array_size; i++) {
			cout << "Visa-" << i + 1 << endl;
			cout << "Issuance date: " << issuance_date[i] << endl;
			cout << "Expiry date: " << expiry_date[i] << endl;
			cout << "Countries: " << countries_visa[i] << endl;
		}
	}
};

class passport { //class for passport object
private:
	string passport_number, issuance_date, expiry_date;
	visa Visa;
public:
	passport() {
		passport_number = "";
		issuance_date = "";
		expiry_date = "";
	}
	passport(string number, string date1, string date2) {
		passport_number = number;
		issuance_date = date1;
		expiry_date = date2;

	}
	void set_passport_number(string number) {
		passport_number = number;
	}
	void set_issuance_date(string date) {
		issuance_date = date;
	}
	void set_expiry_date(string date) {
		expiry_date = date;
	}
	void set_visa(visa v) { //function to set visa on a passport
		Visa = v;
	}
	string get_passport_number() {
		return passport_number;
	}
	string get_issuance_date() {
		return issuance_date;
	}
	string get_expiry_date() {
		return expiry_date;
	}
	visa get_visa() { //function to get visa on a passport
		return Visa;
	}
};

class FinancialDetail { //class for financial details object
private:
	string card_number, card_holder_name, card_expiry_date, card_cvv, card_type, bank_name, bank_account_number;
public:
	FinancialDetail() {
		card_number = "";
		card_holder_name = "";
		card_expiry_date = "";
		card_cvv = "";
		card_type = "";
		bank_name = "";
		bank_account_number = "";
	}
	FinancialDetail(string number, string name, string expiry_date, string code, string type, string bank, string account_number) {
		card_number = number;
		card_holder_name = name;
		card_expiry_date = expiry_date;
		card_cvv = code;
		card_type = type;
		bank_name = bank;
		bank_account_number = account_number;
	}
	void set_card_number(string number) {
		card_number = number;
	}
	void set_card_holder_name(string name) {
		card_holder_name = name;
	}
	void set_card_expiry_date(string expiry_date) {
		card_expiry_date = expiry_date;
	}
	void set_card_cvv(string code) {
		card_cvv = code;
	}
	void set_card_type(string type) {
		card_type = type;
	}
	void set_bank_name(string bank) {
		bank_name = bank;
	}
	void set_bank_account_number(string account_number) {
		bank_account_number = account_number;
	}
	void VerifyFinancialDetail() { //function to verify financial details for payment
		//card number should be 16 digits
		int card_number_length = card_number.length();
		while (card_number_length != 16) {
			cout << "Invalid card number. Please enter again: ";
			cin >> card_number;
			card_number_length = card_number.length();
		}

		//card expiry date should be in dd/mm/yyyy format
		int card_expiry_date_length = card_expiry_date.length();
		while (card_expiry_date_length != 10) {
			cout << "Invalid expiry date. Please enter again: ";
			cin >> card_expiry_date;
			card_expiry_date_length = card_expiry_date.length();
		}

		//checking if card expiry date is valid or expired
		string date = card_expiry_date.substr(0, 2);
		int date1 = stoi(date);
		while (date1 < 1 || date1 > 31) {
			cout << "Invalid expiry date. Please enter again: ";
			cin >> card_expiry_date;
			date = card_expiry_date.substr(0, 2);
			date1 = stoi(date);
		}
		string month = card_expiry_date.substr(3, 2);
		int month1 = stoi(month);
		while (month1 < 1 || month1 > 12) {
			cout << "Invalid expiry date. Please enter again: ";
			cin >> card_expiry_date;
			month = card_expiry_date.substr(3, 2);
			month1 = stoi(month);
		}
		string year = card_expiry_date.substr(6, 4);
		int year1 = stoi(year);
		while (year1 < 2021) {
			cout << "Invalid expiry date. Please enter again: ";
			cin >> card_expiry_date;
			year = card_expiry_date.substr(6, 4);
			year1 = stoi(year);
		}
		//importing current date and time
		time_t current_time = time(0);
		string current_time_string = ctime(&current_time);
		//cout << "The local date and time is: " << current_time_string << endl;
		string current_date = current_time_string.substr(9, 1);
		int current_date1 = stoi(current_date);
		//cout << current_date1 << endl;
		string current_month = current_time_string.substr(4, 3);
		int current_month1 = 0;
		if (current_month == "January" || current_month == "Jan") {
			current_month1 = 1;
		}
		else if (current_month == "February" || current_month == "Feb") {
			current_month1 = 2;
		}
		else if (current_month == "March" || current_month == "Mar") {
			current_month1 = 3;
		}
		else if (current_month == "April") {
			current_month1 = 4;
		}
		else if (current_month == "May") {
			current_month1 = 5;
		}
		else if (current_month == "June" || current_month == "Jun") {
			current_month1 = 6;
		}
		else if (current_month == "July" || current_month == "Jul") {
			current_month1 = 7;
		}
		else if (current_month == "August" || current_month == "Aug") {
			current_month1 = 8;
		}
		else if (current_month == "September" || "current_month ==Sep") {
			current_month1 = 9;
		}
		else if (current_month == "October" || current_month == "Oct") {
			current_month1 = 10;
		}
		else if (current_month == "November" || current_month == "Nov") {
			current_month1 = 11;
		}
		else if (current_month == "December" || current_month == "Dec") {
			current_month1 = 12;
		}
		//cout << current_month1 << endl;
		string current_year = current_time_string.substr(20, 4);
		int current_year1 = stoi(current_year);
		//cout << current_year1 << endl;
		while (current_year1 > year1) {
			cout << "Invalid expiry date or Card is expired. Please enter again: ";
			cin >> card_expiry_date;
			year = card_expiry_date.substr(6, 4);
			year1 = stoi(year);
		}
		if (current_year1 == year1) {
			while (current_month1 > month1) {
				cout << "Invalid expiry date or Card is expired. Please enter again: ";
				cin >> card_expiry_date;
				month = card_expiry_date.substr(3, 2);
				month1 = stoi(month);
			}
			if (current_month1 == month1) {
				while (current_date1 > date1) {
					cout << "IInvalid expiry date or Card is expired. Please enter again: ";
					cin >> card_expiry_date;
					date = card_expiry_date.substr(0, 2);
					date1 = stoi(date);
				}
			}
		}
		//checking if card cvv is valid
		int cvv_length = card_cvv.length();
		while (cvv_length != 3) {
			cout << "Invalid CVV. Please enter again: ";
			cin >> card_cvv;
			cvv_length = card_cvv.length();
		}
		//checking if card type is valid
		while (card_type != "Mastercard" && card_type != "Visa" && card_type != "PayPak") {
			cout << "Invalid card type. Please enter again: ";
			cin >> card_type;
		}
		//checking if card number is valid
		int account_number_length = bank_account_number.length();
		while (account_number_length != 11) {
			cout << "Invalid account number. Please enter again: ";
			cin >> bank_account_number;
			account_number_length = bank_account_number.length();
		}
	}
};

class person { //paernt class for username and password, abstract class
protected:
	string username, password;
public:
	virtual void abstract_class() = 0; //pure virtual function to make class abstract
	person() {
		username="";
		password="";
	}
	person(string u, string p) {
		username = u;
		password = p;
	}
	void set_username(string u) {
		username = u;
	}
	void set_password(string p) {
		password = p;
	}
	string get_username() {
		return username;
	}
	string get_password() {
		return password;
	}
};

class passenger : public person { //child class of person to store passenger details
private:
	string CNIC;
	int age, number_of_bookings;
	FinancialDetail	financial_details;
	passport passport_details;
	booking *booking_details;
public:
	passenger() {
		CNIC = "";
		age = 0;
		number_of_bookings = 0;
		booking_details = new booking[number_of_bookings];
	}
	passenger(string u, string p, string c, int a) : person(u, p) { //parameterized constructor that invokes parent class constructor
		CNIC = c;
		age = a;
		number_of_bookings = 0;
		booking_details = new booking[number_of_bookings];
	}
	~passenger() { //destructor for dynamic array deletion
		delete[] booking_details;
	}
	void abstract_class() override { //overriding abstract class
		cout << "Passenger" << endl;
	}
	void set_CNIC(string c) {
		CNIC = c;
	}
	void set_age(int a) {
		age = a;
	}
	void set_financial_details(FinancialDetail f) { //function to add financial details of a passenger
		financial_details = f;
	}
	void set_passport_details(passport p) { //function to add passport details of a passenger
		passport_details = p;
	}
	void set_booking_details(booking b) { //function to add booking details of a passenger
		number_of_bookings++;
		booking* new_booking_details = new booking[number_of_bookings];
		for (int i = 0; i < number_of_bookings - 1; ++i) {
			new_booking_details[i] = booking_details[i];
		}
		new_booking_details[number_of_bookings - 1] = b;
		delete[] booking_details;
		booking_details = new_booking_details;
	}
	string get_CNIC() {
		return CNIC;
	}
	int get_age() {
		return age;
	}
	FinancialDetail get_financial_details() { //function to get financial details of a passenger
		return financial_details;
	}
	passport get_passport_details() { //function to get passport details of a passenger
		return passport_details;
	}
	void get_booking_details() { //function to get all booking details of a passenger
		for (int i = 0; i < number_of_bookings; i++) {
			if (booking_details[i].get_status() == "Booked") {
				cout << booking_details[i].get_booking_id() << endl;
				cout << booking_details[i].get_booking_date() << endl;
				cout << booking_details[i].get_departure_date() << endl;
				cout << booking_details[i].get_departure_time() << endl;
				cout << booking_details[i].get_arrival_date() << endl;
				cout << booking_details[i].get_arrival_time() << endl;
				cout << booking_details[i].get_seat_number() << endl;
				cout << booking_details[i].get_status() << endl;
				cout << booking_details[i].get_flight_details().get_price() << endl;
				//cout << booking_details[i].get_flight_details() << endl;
			}
		}
	}
	booking get_booking(string booking_id) { //function to get a specific booking detail of a passenger
		for (int i = 0; i < number_of_bookings; i++) {
			if (booking_details[i].get_booking_id() == booking_id) {
				return booking_details[i];
			}
		}
	}
	void remove_booking(string booking_id) { //function to remove a specific booking detail of a passenger
		int remove_index= -1;
		for (int i = 0; i < number_of_bookings; i++) {
			if (booking_details[i].get_booking_id() == booking_id) {
				remove_index = i;
				break;
			}
		}
		if (remove_index == -1) {
			cout << "Booking not found." << endl;
		}
		else {
			number_of_bookings--;
			if (number_of_bookings == 0) {
				delete[] booking_details;
				booking_details = nullptr;
			}
			else {
				booking* new_booking_details = new booking[number_of_bookings];
				int index = 0;
				for (int i = 0; i < number_of_bookings + 1; ++i) {
					if (i != remove_index) {
						new_booking_details[index] = booking_details[i];
						index++;
					}
				}
				delete[] booking_details;
				booking_details = new_booking_details;
			}
			cout << "Booking with id " << booking_id << " removed." << endl;
		}
	}
};

class admin : public person { //child class of person to store admin details
public:
	admin(){}
	admin(string u, string p) : person(u, p) {} //parameterized constructor that invokes parent class constructor 
	void abstract_class() override { //overriding abstract class
		cout << "Admin" << endl;
	}
	void set_flight_schedule(flight *flights, int size) {

	}
	void add_route(flight* flights, int size) {

	}
	void remove_flight(flight* flights, int size) {

	}
	void set_passenger_limit(flight* flights, int size) {
		
	}
};


void login_passenger(passenger* passenger_arr,int passenger_array_size, flight* flights, int size, int index); //function prototypes of passenger login function

void login_admin(admin* admin_arr, int admin_array_size, flight* flights, int size, int index); //function prototypes of admin login function

int main() {
	int n = 0, age = 0, flight_array_size = 50, passenger_array_size = 0, admin_array_size = 0, index = 0;
	string username = "", cnic = "";
	char password[20] = {}, a = ' ';
	flight* flights = new flight[flight_array_size];
	bool exit = false, proceed = true;

	passenger* passenger_arr = new passenger[passenger_array_size]; //creating dynamic array of passenger objects
	passenger* new_passenger_arr = new passenger[passenger_array_size]; //creating dynamic array of passenger objects
	admin* admin_arr = new admin[admin_array_size]; //creating dynamic array of admin objects
	admin* new_admin_arr = new admin[admin_array_size]; //creating dynamic array of admin objects

	//craeting airplane objects
	airplane plane1("Boeing P01", 0);
	airplane plane2("Boeing P02", 0);
	airplane plane3("Boeing P03", 0);
	airplane plane4("Boeing P04", 0);
	airplane plane5("Boeing P05", 0);
	airplane plane6("Boeing P06", 0);
	airplane plane7("Boeing P07", 0);
	airplane plane8("Boeing P08", 0);
	airplane plane9("Boeing P09", 0);
	airplane plane10("Boeing P10", 0);
	airplane plane11("Boeing P11", 0);
	airplane plane12("Boeing P12", 0);
	airplane plane13("Boeing P13", 0);
	airplane plane14("Boeing P14", 0);
	airplane plane15("Boeing P15", 0);
	airplane plane16("Boeing P16", 0);
	airplane plane17("Boeing P17", 0);
	airplane plane18("Boeing P18", 0);
	airplane plane19("Boeing P19", 0);
	airplane plane20("Boeing P20", 0);
	airplane plane21("Boeing P21", 0);
	airplane plane22("Boeing P22", 0);
	airplane plane23("Boeing P23", 0);
	airplane plane24("Boeing P24", 0);
	airplane plane25("Boeing P25", 0);
	airplane plane26("Boeing P26", 0);
	airplane plane27("Boeing P27", 0);
	airplane plane28("Boeing P28", 0);
	airplane plane29("Boeing P29", 0);
	airplane plane30("Boeing P30", 0);
	airplane plane31("Boeing P31", 0);
	airplane plane32("Boeing P32", 0);
	airplane plane33("Boeing P33", 0);
	airplane plane34("Boeing P34", 0);
	airplane plane35("Boeing P35", 0);
	airplane plane36("Boeing P36", 0);
	airplane plane37("Boeing P37", 0);
	airplane plane38("Boeing P38", 0);
	airplane plane39("Boeing P39", 0);
	airplane plane40("Boeing P40", 0);
	airplane plane41("Boeing P41", 0);
	airplane plane42("Boeing P42", 0);
	airplane plane43("Boeing P43", 0);
	airplane plane44("Boeing P44", 0);
	airplane plane45("Boeing P45", 0);
	airplane plane46("Boeing P46", 0);
	airplane plane47("Boeing P47", 0);
	airplane plane48("Boeing P48", 0);
	airplane plane49("Boeing P49", 0);
	airplane plane50("Boeing P50", 0);

	//creating local airport objects
	airport airport1("Karachi_North", "Karachi", "Pakistan", 5, 0);
	airport1.set_airplanes_available(plane1);
	airport1.set_airplanes_available(plane2);
	airport1.set_airplanes_available(plane3);
	airport1.set_airplanes_available(plane4);
	airport1.set_airplanes_available(plane5);
	airport airport2("Karachi_South", "Karachi", "Pakistan", 5, 0);
	airport2.set_airplanes_available(plane6);
	airport2.set_airplanes_available(plane7);
	airport2.set_airplanes_available(plane8);
	airport2.set_airplanes_available(plane9);
	airport2.set_airplanes_available(plane10);
	airport airport3("Islamabad_North", "Islamabad", "Pakistan", 5, 0);
	airport3.set_airplanes_available(plane11);
	airport3.set_airplanes_available(plane12);
	airport3.set_airplanes_available(plane13);
	airport3.set_airplanes_available(plane14);
	airport3.set_airplanes_available(plane15);
	airport airport4("Islamabad_South", "Islamabad", "Pakistan", 5, 0);
	airport4.set_airplanes_available(plane16);
	airport4.set_airplanes_available(plane17);
	airport4.set_airplanes_available(plane18);
	airport4.set_airplanes_available(plane19);
	airport4.set_airplanes_available(plane20);
	airport airport5("Lahore_North", "Lahore", "Pakistan", 5, 0);
	airport5.set_airplanes_available(plane21);
	airport5.set_airplanes_available(plane22);
	airport5.set_airplanes_available(plane23);
	airport5.set_airplanes_available(plane24);
	airport5.set_airplanes_available(plane25);
	airport airport6("Lahore_South", "Lahore", "Pakistan", 5, 0);
	airport6.set_airplanes_available(plane26);
	airport6.set_airplanes_available(plane27);
	airport6.set_airplanes_available(plane28);
	airport6.set_airplanes_available(plane29);
	airport6.set_airplanes_available(plane30);
	airport airport7("Peshawar_North", "Peshawar", "Pakistan", 5, 0);
	airport7.set_airplanes_available(plane31);
	airport7.set_airplanes_available(plane32);
	airport7.set_airplanes_available(plane33);
	airport7.set_airplanes_available(plane34);
	airport7.set_airplanes_available(plane35);
	airport airport8("Peshawar_South", "Peshawar", "Pakistan", 5, 0);
	airport8.set_airplanes_available(plane36);
	airport8.set_airplanes_available(plane37);
	airport8.set_airplanes_available(plane38);
	airport8.set_airplanes_available(plane39);
	airport8.set_airplanes_available(plane40);
	airport airport9("Quetta_North", "Quetta", "Pakistan", 5, 0);
	airport9.set_airplanes_available(plane41);
	airport9.set_airplanes_available(plane42);
	airport9.set_airplanes_available(plane43);
	airport9.set_airplanes_available(plane44);
	airport9.set_airplanes_available(plane45);
	airport airport10("Quetta_South", "Quetta", "Pakistan", 5, 0);
	airport10.set_airplanes_available(plane46);
	airport10.set_airplanes_available(plane47);
	airport10.set_airplanes_available(plane48);
	airport10.set_airplanes_available(plane49);
	airport10.set_airplanes_available(plane50);

	//creating international airport objects
	airport airport11("Dubai_Airport", "Dubai", "UAE", 5,0);
	airport airport12("Istanbul_Airport", "Istanbul", "Turkey", 5, 0);
	airport airport13("London_Airport", "London", "UK", 5, 0);
	airport airport14("New_York_Airport", "New York", "USA", 5, 0);
	airport airport15("Paris_Airport", "Paris", "France", 5, 0);
	airport airport16("Rome_Airport", "Rome", "Italy", 5, 0);
	airport airport17("Singapore_Airport", "Singapore", "Singapore", 5, 0);
	airport airport18("Sydney_Airport", "Sydney", "Australia", 5, 0);
	airport airport19("Tokyo_Airport", "Tokyo", "Japan", 5, 0);
	airport airport20("Toronto_Airport", "Toronto", "Canada", 5, 0);
	airport airport21("Kabul_Airport", "Kabul", "Afghanistan", 5, 0);
	airport airport22("Beijing_Airport", "Beijing", "China", 5, 0);
	airport airport23("Moscow_Airport", "Moscow", "Russia", 5, 0);
	airport airport24("Tehran_Airport", "Tehran", "Iran", 5, 0);
	airport airport25("Kuala_Lumpur_Airport", "Kuala Lumpur", "Malaysia", 5, 0);
	airport airport26("Baghdad_Airport", "Baghdad", "Iraq", 5, 0);
	airport airport27("Dhaka_Airport", "Dhaka", "Bangladesh", 5, 0);
	airport airport28("Damascus_Airport", "Damascus", "Syria", 5, 0);
	airport airport29("Mecca_Airprot", "Mecca", "Saudi Arabia", 5, 0);
	airport airport30("Cairo_Airport", "Cairo", "Egypt", 5, 0);
	airport airport31("Beirut_Airport", "Beirut", "Lebanon", 5, 0);
	airport airport32("Sana'a_Airport", "Sana'a", "Yemen", 5, 0);
	airport airport33("Jerusalem_Airport", "Jerusalem", "Palestine", 5, 0);
	airport airport34("Doha_Airport", "Doha", "Qatar", 5, 0);
	airport airport35("Muscat_Airport", "Muscat", "Oman", 5, 0);

	//populating flight array with flight objects
	flights[0].set_flight_number("PK-123");
	flights[0].set_plane(plane1);
	flights[0].set_departure_date("20/5/2023");
	flights[0].set_departure_time("12:00pm");
	flights[0].set_arrival_date("20/5/2023");
	flights[0].set_arrival_time("2:00pm");
	flights[0].set_available_seats_economy(50);
	flights[0].set_available_seats_business(10);
	flights[0].set_departure_airport(airport1);
	flights[0].set_arrival_airport(airport10);
	flights[0].set_price(10000);
	flights[0].set_duration(2.0);
	flights[1].set_flight_number("PK-124");
	flights[1].set_plane(plane2);
	flights[1].set_departure_date("21/5/2023");
	flights[1].set_departure_time("2:00pm");
	flights[1].set_arrival_date("21/5/2023");
	flights[1].set_arrival_time("5:30pm");
	flights[1].set_available_seats_economy(50);
	flights[1].set_available_seats_business(10);
	flights[1].set_departure_airport(airport3);
	flights[1].set_arrival_airport(airport11);
	flights[1].set_price(20000);
	flights[1].set_duration(3.5);
	flights[2].set_flight_number("PK-125");
	flights[2].set_plane(plane3);
	flights[2].set_departure_date("22/5/2023");
	flights[2].set_departure_time("4:00pm");
	flights[2].set_arrival_date("22/5/2023");
	flights[2].set_arrival_time("7:00pm");
	flights[2].set_available_seats_economy(50);
	flights[2].set_available_seats_business(10);
	flights[2].set_departure_airport(airport5);
	flights[2].set_arrival_airport(airport12);
	flights[2].set_price(30000);
	flights[2].set_duration(3.0);
	flights[3].set_flight_number("PK-126");
	flights[3].set_plane(plane4);
	flights[3].set_departure_date("23/5/2023");
	flights[3].set_departure_time("6:00pm");
	flights[3].set_arrival_date("23/5/2023");
	flights[3].set_arrival_time("9:00pm");
	flights[3].set_available_seats_economy(50);
	flights[3].set_available_seats_business(10);
	flights[3].set_departure_airport(airport7);
	flights[3].set_arrival_airport(airport13);
	flights[3].set_price(40000);
	flights[3].set_duration(3.0);
	flights[4].set_flight_number("PK-127");
	flights[4].set_plane(plane5);
	flights[4].set_departure_date("24/5/2023");
	flights[4].set_departure_time("8:00pm");
	flights[4].set_arrival_date("24/5/2023");
	flights[4].set_arrival_time("11:00pm");
	flights[4].set_available_seats_economy(50);
	flights[4].set_available_seats_business(10);
	flights[4].set_departure_airport(airport9);
	flights[4].set_arrival_airport(airport14);
	flights[4].set_price(50000);
	flights[4].set_duration(3.0);
	flights[5].set_flight_number("PK-128");
	flights[5].set_plane(plane6);
	flights[5].set_departure_date("25/5/2023");
	flights[5].set_departure_time("10:00pm");
	flights[5].set_arrival_date("25/5/2023");
	flights[5].set_arrival_time("1:00am");
	flights[5].set_available_seats_economy(50);
	flights[5].set_available_seats_business(10);
	flights[5].set_departure_airport(airport11);
	flights[5].set_arrival_airport(airport15);
	flights[5].set_price(60000);
	flights[5].set_duration(3.0);
	flights[6].set_flight_number("PK-129");
	flights[6].set_plane(plane7);
	flights[6].set_departure_date("26/5/2023");
	flights[6].set_departure_time("12:00am");
	flights[6].set_arrival_date("26/5/2023");
	flights[6].set_arrival_time("3:00am");
	flights[6].set_available_seats_economy(50);
	flights[6].set_available_seats_business(10);
	flights[6].set_departure_airport(airport13);
	flights[6].set_arrival_airport(airport16);
	flights[6].set_price(70000);
	flights[6].set_duration(3.0);
	flights[7].set_flight_number("PK-130");
	flights[7].set_plane(plane8);
	flights[7].set_departure_date("27/5/2023");
	flights[7].set_departure_time("2:00am");
	flights[7].set_arrival_date("27/5/2023");
	flights[7].set_arrival_time("5:00am");
	flights[7].set_available_seats_economy(50);
	flights[7].set_available_seats_business(10);
	flights[7].set_departure_airport(airport15);
	flights[7].set_arrival_airport(airport17);
	flights[7].set_price(80000);
	flights[7].set_duration(3.0);
	flights[8].set_flight_number("PK-131");
	flights[8].set_plane(plane9);
	flights[8].set_departure_date("28/5/2023");
	flights[8].set_departure_time("4:00am");
	flights[8].set_arrival_date("28/5/2023");
	flights[8].set_arrival_time("7:00am");
	flights[8].set_available_seats_economy(50);
	flights[8].set_available_seats_business(10);
	flights[8].set_departure_airport(airport17);
	flights[8].set_arrival_airport(airport18);
	flights[8].set_price(90000);
	flights[8].set_duration(3.0);
	flights[9].set_flight_number("PK-132");
	flights[9].set_plane(plane10);
	flights[9].set_departure_date("29/5/2023");
	flights[9].set_departure_time("6:00am");
	flights[9].set_arrival_date("29/5/2023");
	flights[9].set_arrival_time("9:00am");
	flights[9].set_available_seats_economy(50);
	flights[9].set_available_seats_business(10);
	flights[9].set_departure_airport(airport18);
	flights[9].set_arrival_airport(airport19);
	flights[9].set_price(100000);
	flights[9].set_duration(3.0);
	flights[10].set_flight_number("PK-133");
	flights[10].set_plane(plane11);
	flights[10].set_departure_date("30/5/2023");
	flights[10].set_departure_time("8:00am");
	flights[10].set_arrival_date("30/5/2023");
	flights[10].set_arrival_time("11:00am");
	flights[10].set_available_seats_economy(50);
	flights[10].set_available_seats_business(10);
	flights[10].set_departure_airport(airport19);
	flights[10].set_arrival_airport(airport20);
	flights[10].set_price(110000);
	flights[10].set_duration(3.0);
	flights[11].set_flight_number("PK-134");
	flights[11].set_plane(plane12);
	flights[11].set_departure_date("31/5/2023");
	flights[11].set_departure_time("10:00am");
	flights[11].set_arrival_date("31/5/2023");
	flights[11].set_arrival_time("1:00pm");
	flights[11].set_available_seats_economy(50);
	flights[11].set_available_seats_business(10);
	flights[11].set_departure_airport(airport20);
	flights[11].set_arrival_airport(airport21);
	flights[11].set_price(120000);
	flights[11].set_duration(3.0);
	flights[12].set_flight_number("PK-135");
	flights[12].set_plane(plane13);
	flights[12].set_departure_date("1/6/2023");
	flights[12].set_departure_time("12:00pm");
	flights[12].set_arrival_date("1/6/2023");
	flights[12].set_arrival_time("3:00pm");
	flights[12].set_available_seats_economy(50);
	flights[12].set_available_seats_business(10);
	flights[12].set_departure_airport(airport21);
	flights[12].set_arrival_airport(airport22);
	flights[12].set_price(130000);
	flights[12].set_duration(3.0);
	flights[13].set_flight_number("PK-136");
	flights[13].set_plane(plane14);
	flights[13].set_departure_date("2/6/2023");
	flights[13].set_departure_time("2:00pm");
	flights[13].set_arrival_date("2/6/2023");
	flights[13].set_arrival_time("5:00pm");
	flights[13].set_available_seats_economy(50);
	flights[13].set_available_seats_business(10);
	flights[13].set_departure_airport(airport22);
	flights[13].set_arrival_airport(airport23);
	flights[13].set_price(140000);
	flights[13].set_duration(3.0);
	flights[14].set_flight_number("PK-137");
	flights[14].set_plane(plane15);
	flights[14].set_departure_date("3/6/2023");
	flights[14].set_departure_time("4:00pm");
	flights[14].set_arrival_date("3/6/2023");
	flights[14].set_arrival_time("7:00pm");
	flights[14].set_available_seats_economy(50);
	flights[14].set_available_seats_business(10);
	flights[14].set_departure_airport(airport23);
	flights[14].set_arrival_airport(airport24);
	flights[14].set_price(150000);
	flights[14].set_duration(3.0);
	flights[15].set_flight_number("PK-138");
	flights[15].set_plane(plane16);
	flights[15].set_departure_date("4/6/2023");
	flights[15].set_departure_time("6:00pm");
	flights[15].set_arrival_date("4/6/2023");
	flights[15].set_arrival_time("9:00pm");
	flights[15].set_available_seats_economy(50);
	flights[15].set_available_seats_business(10);
	flights[15].set_departure_airport(airport24);
	flights[15].set_arrival_airport(airport25);
	flights[15].set_price(160000);
	flights[15].set_duration(3.0);
	flights[16].set_flight_number("PK-139");
	flights[16].set_plane(plane17);
	flights[16].set_departure_date("5/6/2023");
	flights[16].set_departure_time("8:00pm");
	flights[16].set_arrival_date("5/6/2023");
	flights[16].set_arrival_time("11:00pm");
	flights[16].set_available_seats_economy(50);
	flights[16].set_available_seats_business(10);
	flights[16].set_departure_airport(airport25);
	flights[16].set_arrival_airport(airport26);
	flights[16].set_price(170000);
	flights[16].set_duration(3.0);
	flights[17].set_flight_number("PK-140");
	flights[17].set_plane(plane18);
	flights[17].set_departure_date("6/6/2023");
	flights[17].set_departure_time("10:00pm");
	flights[17].set_arrival_date("6/6/2023");
	flights[17].set_arrival_time("1:00am");
	flights[17].set_available_seats_economy(50);
	flights[17].set_available_seats_business(10);
	flights[17].set_departure_airport(airport26);
	flights[17].set_arrival_airport(airport27);
	flights[17].set_price(180000);
	flights[17].set_duration(3.0);
	flights[18].set_flight_number("PK-141");
	flights[18].set_plane(plane19);
	flights[18].set_departure_date("7/6/2023");
	flights[18].set_departure_time("12:00am");
	flights[18].set_arrival_date("7/6/2023");
	flights[18].set_arrival_time("3:00am");
	flights[18].set_available_seats_economy(50);
	flights[18].set_available_seats_business(10);
	flights[18].set_departure_airport(airport27);
	flights[18].set_arrival_airport(airport28);
	flights[18].set_price(190000);
	flights[18].set_duration(3.0);
	flights[19].set_flight_number("PK-142");
	flights[19].set_plane(plane20);
	flights[19].set_departure_date("8/6/2023");
	flights[19].set_departure_time("2:00am");
	flights[19].set_arrival_date("8/6/2023");
	flights[19].set_arrival_time("5:00am");
	flights[19].set_available_seats_economy(50);
	flights[19].set_available_seats_business(10);
	flights[19].set_departure_airport(airport28);
	flights[19].set_arrival_airport(airport29);
	flights[19].set_price(200000);
	flights[19].set_duration(3.0);
	flights[20].set_flight_number("PK-143");
	flights[20].set_plane(plane21);
	flights[20].set_departure_date("9/6/2023");
	flights[20].set_departure_time("4:00am");
	flights[20].set_arrival_date("9/6/2023");
	flights[20].set_arrival_time("7:00am");
	flights[20].set_available_seats_economy(50);
	flights[20].set_available_seats_business(10);
	flights[20].set_departure_airport(airport29);
	flights[20].set_arrival_airport(airport30);
	flights[20].set_price(210000);
	flights[20].set_duration(3.0);
	flights[21].set_flight_number("PK-144");
	flights[21].set_plane(plane22);
	flights[21].set_departure_date("10/6/2023");
	flights[21].set_departure_time("6:00am");
	flights[21].set_arrival_date("10/6/2023");
	flights[21].set_arrival_time("9:00am");
	flights[21].set_available_seats_economy(50);
	flights[21].set_available_seats_business(10);
	flights[21].set_departure_airport(airport30);
	flights[21].set_arrival_airport(airport31);
	flights[21].set_price(220000);
	flights[21].set_duration(3.0);
	flights[22].set_flight_number("PK-145");
	flights[22].set_plane(plane23);
	flights[22].set_departure_date("11/6/2023");
	flights[22].set_departure_time("8:00am");
	flights[22].set_arrival_date("11/6/2023");
	flights[22].set_arrival_time("11:00am");
	flights[22].set_available_seats_economy(50);
	flights[22].set_available_seats_business(10);
	flights[22].set_departure_airport(airport31);
	flights[22].set_arrival_airport(airport32);
	flights[22].set_price(230000);
	flights[22].set_duration(3.0);
	flights[23].set_flight_number("PK-146");
	flights[23].set_plane(plane24);
	flights[23].set_departure_date("12/6/2023");
	flights[23].set_departure_time("10:00am");
	flights[23].set_arrival_date("12/6/2023");
	flights[23].set_arrival_time("1:00pm");
	flights[23].set_available_seats_economy(50);
	flights[23].set_available_seats_business(10);
	flights[23].set_departure_airport(airport32);
	flights[23].set_arrival_airport(airport33);
	flights[23].set_price(240000);
	flights[23].set_duration(3.0);
	flights[24].set_flight_number("PK-147");
	flights[24].set_plane(plane25);
	flights[24].set_departure_date("13/6/2023");
	flights[24].set_departure_time("12:00pm");
	flights[24].set_arrival_date("13/6/2023");
	flights[24].set_arrival_time("3:00pm");
	flights[24].set_available_seats_economy(50);
	flights[24].set_available_seats_business(10);
	flights[24].set_departure_airport(airport33);
	flights[24].set_arrival_airport(airport34);
	flights[24].set_price(250000);
	flights[24].set_duration(3.0);
	flights[25].set_flight_number("PK-148");
	flights[25].set_plane(plane26);
	flights[25].set_departure_date("14/6/2023");
	flights[25].set_departure_time("2:00pm");
	flights[25].set_arrival_date("14/6/2023");
	flights[25].set_arrival_time("5:00pm");
	flights[25].set_available_seats_economy(50);
	flights[25].set_available_seats_business(10);
	flights[25].set_departure_airport(airport34);
	flights[25].set_arrival_airport(airport35);
	flights[25].set_price(260000);
	flights[25].set_duration(3.0);
	flights[26].set_flight_number("PK-149");
	flights[26].set_plane(plane27);
	flights[26].set_departure_date("15/6/2023");
	flights[26].set_departure_time("4:00pm");
	flights[26].set_arrival_date("15/6/2023");
	flights[26].set_arrival_time("7:00pm");
	flights[26].set_available_seats_economy(50);
	flights[26].set_available_seats_business(10);
	flights[26].set_departure_airport(airport35);
	flights[26].set_arrival_airport(airport10);
	flights[26].set_price(270000);
	flights[26].set_duration(3.0);
	flights[27].set_flight_number("PK-150");
	flights[27].set_plane(plane28);
	flights[27].set_departure_date("16/6/2023");
	flights[27].set_departure_time("6:00pm");
	flights[27].set_arrival_date("16/6/2023");
	flights[27].set_arrival_time("9:00pm");
	flights[27].set_available_seats_economy(50);
	flights[27].set_available_seats_business(10);
	flights[27].set_departure_airport(airport5);
	flights[27].set_arrival_airport(airport8);
	flights[27].set_price(280000);
	flights[27].set_duration(3.0);
	flights[28].set_flight_number("PK-151");
	flights[28].set_plane(plane29);
	flights[28].set_departure_date("17/6/2023");
	flights[28].set_departure_time("8:00pm");
	flights[28].set_arrival_date("17/6/2023");
	flights[28].set_arrival_time("11:00pm");
	flights[28].set_available_seats_economy(50);
	flights[28].set_available_seats_business(10);
	flights[28].set_departure_airport(airport8);
	flights[28].set_arrival_airport(airport9);
	flights[28].set_price(290000);
	flights[28].set_duration(3.0);
	flights[29].set_flight_number("PK-152");
	flights[29].set_plane(plane30);
	flights[29].set_departure_date("18/6/2023");
	flights[29].set_departure_time("10:00pm");
	flights[29].set_arrival_date("18/6/2023");
	flights[29].set_arrival_time("1:00am");
	flights[29].set_available_seats_economy(50);
	flights[29].set_available_seats_business(10);
	flights[29].set_departure_airport(airport9);
	flights[29].set_arrival_airport(airport10);
	flights[29].set_price(300000);
	flights[29].set_duration(3.0);
	flights[30].set_flight_number("PK-153");
	flights[30].set_plane(plane31);
	flights[30].set_departure_date("19/6/2023");
	flights[30].set_departure_time("12:00am");
	flights[30].set_arrival_date("19/6/2023");
	flights[30].set_arrival_time("3:00am");
	flights[30].set_available_seats_economy(50);
	flights[30].set_available_seats_business(10);
	flights[30].set_departure_airport(airport10);
	flights[30].set_arrival_airport(airport11);
	flights[30].set_price(310000);
	flights[30].set_duration(3.0);
	flights[31].set_flight_number("PK-154");
	flights[31].set_plane(plane32);
	flights[31].set_departure_date("20/6/2023");
	flights[31].set_departure_time("2:00am");
	flights[31].set_arrival_date("20/6/2023");
	flights[31].set_arrival_time("5:00am");
	flights[31].set_available_seats_economy(50);
	flights[31].set_available_seats_business(10);
	flights[31].set_departure_airport(airport11);
	flights[31].set_arrival_airport(airport12);
	flights[31].set_price(320000);
	flights[31].set_duration(3.0);
	flights[32].set_flight_number("PK-155");
	flights[32].set_plane(plane33);
	flights[32].set_departure_date("21/6/2023");
	flights[32].set_departure_time("4:00am");
	flights[32].set_arrival_date("21/6/2023");
	flights[32].set_arrival_time("7:00am");
	flights[32].set_available_seats_economy(50);
	flights[32].set_available_seats_business(10);
	flights[32].set_departure_airport(airport12);
	flights[32].set_arrival_airport(airport13);
	flights[32].set_price(330000);
	flights[32].set_duration(3.0);
	flights[33].set_flight_number("PK-156");
	flights[33].set_plane(plane34);
	flights[33].set_departure_date("22/6/2023");
	flights[33].set_departure_time("6:00am");
	flights[33].set_arrival_date("22/6/2023");
	flights[33].set_arrival_time("9:00am");
	flights[33].set_available_seats_economy(50);
	flights[33].set_available_seats_business(10);
	flights[33].set_departure_airport(airport13);
	flights[33].set_arrival_airport(airport14);
	flights[33].set_price(340000);
	flights[33].set_duration(3.0);
	flights[34].set_flight_number("PK-157");
	flights[34].set_plane(plane35);
	flights[34].set_departure_date("23/6/2023");
	flights[34].set_departure_time("8:00am");
	flights[34].set_arrival_date("23/6/2023");
	flights[34].set_arrival_time("11:00am");
	flights[34].set_available_seats_economy(50);
	flights[34].set_available_seats_business(10);
	flights[34].set_departure_airport(airport14);
	flights[34].set_arrival_airport(airport15);
	flights[34].set_price(350000);
	flights[34].set_duration(3.0);
	flights[35].set_flight_number("PK-158");
	flights[35].set_plane(plane36);
	flights[35].set_departure_date("24/6/2023");
	flights[35].set_departure_time("10:00am");
	flights[35].set_arrival_date("24/6/2023");
	flights[35].set_arrival_time("1:00pm");
	flights[35].set_available_seats_economy(50);
	flights[35].set_available_seats_business(10);
	flights[35].set_departure_airport(airport15);
	flights[35].set_arrival_airport(airport16);
	flights[35].set_price(360000);
	flights[35].set_duration(3.0);
	flights[36].set_flight_number("PK-159");
	flights[36].set_plane(plane37);
	flights[36].set_departure_date("25/6/2023");
	flights[36].set_departure_time("12:00pm");
	flights[36].set_arrival_date("25/6/2023");
	flights[36].set_arrival_time("3:00pm");
	flights[36].set_available_seats_economy(50);
	flights[36].set_available_seats_business(10);
	flights[36].set_departure_airport(airport16);
	flights[36].set_arrival_airport(airport17);
	flights[36].set_price(370000);
	flights[36].set_duration(3.0);
	flights[37].set_flight_number("PK-160");
	flights[37].set_plane(plane38);
	flights[37].set_departure_date("26/6/2023");
	flights[37].set_departure_time("2:00pm");
	flights[37].set_arrival_date("26/6/2023");
	flights[37].set_arrival_time("5:00pm");
	flights[37].set_available_seats_economy(50);
	flights[37].set_available_seats_business(10);
	flights[37].set_departure_airport(airport17);
	flights[37].set_arrival_airport(airport18);
	flights[37].set_price(380000);
	flights[37].set_duration(3.0);
	flights[38].set_flight_number("PK-161");
	flights[38].set_plane(plane39);
	flights[38].set_departure_date("27/6/2023");
	flights[38].set_departure_time("4:00pm");
	flights[38].set_arrival_date("27/6/2023");
	flights[38].set_arrival_time("7:00pm");
	flights[38].set_available_seats_economy(50);
	flights[38].set_available_seats_business(10);
	flights[38].set_departure_airport(airport18);
	flights[38].set_arrival_airport(airport19);
	flights[38].set_price(390000);
	flights[38].set_duration(3.0);
	flights[39].set_flight_number("PK-162");
	flights[39].set_plane(plane40);
	flights[39].set_departure_date("28/6/2023");
	flights[39].set_departure_time("6:00pm");
	flights[39].set_arrival_date("28/6/2023");
	flights[39].set_arrival_time("9:00pm");
	flights[39].set_available_seats_economy(50);
	flights[39].set_available_seats_business(10);
	flights[39].set_departure_airport(airport19);
	flights[39].set_arrival_airport(airport20);
	flights[39].set_price(400000);
	flights[39].set_duration(3.0);
	flights[40].set_flight_number("PK-163");
	flights[40].set_plane(plane41);
	flights[40].set_departure_date("29/6/2023");
	flights[40].set_departure_time("8:00pm");
	flights[40].set_arrival_date("29/6/2023");
	flights[40].set_arrival_time("11:00pm");
	flights[40].set_available_seats_economy(50);
	flights[40].set_available_seats_business(10);
	flights[40].set_departure_airport(airport20);
	flights[40].set_arrival_airport(airport21);
	flights[40].set_price(410000);
	flights[40].set_duration(3.0);
	flights[41].set_flight_number("PK-164");
	flights[41].set_plane(plane42);
	flights[41].set_departure_date("30/6/2023");
	flights[41].set_departure_time("10:00pm");
	flights[41].set_arrival_date("30/6/2023");
	flights[41].set_arrival_time("1:00am");
	flights[41].set_available_seats_economy(50);
	flights[41].set_available_seats_business(10);
	flights[41].set_departure_airport(airport21);
	flights[41].set_arrival_airport(airport22);
	flights[41].set_price(420000);
	flights[41].set_duration(3.0);
	flights[42].set_flight_number("PK-165");
	flights[42].set_plane(plane43);
	flights[42].set_departure_date("1/7/2023");
	flights[42].set_departure_time("12:00am");
	flights[42].set_arrival_date("1/7/2023");
	flights[42].set_arrival_time("3:00am");
	flights[42].set_available_seats_economy(50);
	flights[42].set_available_seats_business(10);
	flights[42].set_departure_airport(airport22);
	flights[42].set_arrival_airport(airport23);
	flights[42].set_price(430000);
	flights[42].set_duration(3.0);
	flights[43].set_flight_number("PK-166");
	flights[43].set_plane(plane44);
	flights[43].set_departure_date("2/7/2023");
	flights[43].set_departure_time("2:00am");
	flights[43].set_arrival_date("2/7/2023");
	flights[43].set_arrival_time("5:00am");
	flights[43].set_available_seats_economy(50);
	flights[43].set_available_seats_business(10);
	flights[43].set_departure_airport(airport23);
	flights[43].set_arrival_airport(airport24);
	flights[43].set_price(440000);
	flights[43].set_duration(3.0);
	flights[44].set_flight_number("PK-167");
	flights[44].set_plane(plane45);
	flights[44].set_departure_date("3/7/2023");
	flights[44].set_departure_time("4:00am");
	flights[44].set_arrival_date("3/7/2023");
	flights[44].set_arrival_time("7:00am");
	flights[44].set_available_seats_economy(50);
	flights[44].set_available_seats_business(10);
	flights[44].set_departure_airport(airport24);
	flights[44].set_arrival_airport(airport25);
	flights[44].set_price(450000);
	flights[44].set_duration(3.0);
	flights[45].set_flight_number("PK-168");
	flights[45].set_plane(plane46);
	flights[45].set_departure_date("4/7/2023");
	flights[45].set_departure_time("6:00am");
	flights[45].set_arrival_date("4/7/2023");
	flights[45].set_arrival_time("9:00am");
	flights[45].set_available_seats_economy(50);
	flights[45].set_available_seats_business(10);
	flights[45].set_departure_airport(airport25);
	flights[45].set_arrival_airport(airport26);
	flights[45].set_price(460000);
	flights[45].set_duration(3.0);
	flights[46].set_flight_number("PK-169");
	flights[46].set_plane(plane47);
	flights[46].set_departure_date("5/7/2023");
	flights[46].set_departure_time("8:00am");
	flights[46].set_arrival_date("5/7/2023");
	flights[46].set_arrival_time("11:00am");
	flights[46].set_available_seats_economy(50);
	flights[46].set_available_seats_business(10);
	flights[46].set_departure_airport(airport26);
	flights[46].set_arrival_airport(airport27);
	flights[46].set_price(470000);
	flights[46].set_duration(3.0);
	flights[47].set_flight_number("PK-170");
	flights[47].set_plane(plane48);
	flights[47].set_departure_date("6/7/2023");
	flights[47].set_departure_time("10:00am");
	flights[47].set_arrival_date("6/7/2023");
	flights[47].set_arrival_time("1:00pm");
	flights[47].set_available_seats_economy(50);
	flights[47].set_available_seats_business(10);
	flights[47].set_departure_airport(airport27);
	flights[47].set_arrival_airport(airport28);
	flights[47].set_price(480000);
	flights[47].set_duration(3.0);
	flights[48].set_flight_number("PK-171");
	flights[48].set_plane(plane49);
	flights[48].set_departure_date("7/7/2023");
	flights[48].set_departure_time("12:00pm");
	flights[48].set_arrival_date("7/7/2023");
	flights[48].set_arrival_time("3:00pm");
	flights[48].set_available_seats_economy(50);
	flights[48].set_available_seats_business(10);
	flights[48].set_departure_airport(airport28);
	flights[48].set_arrival_airport(airport29);
	flights[48].set_price(490000);
	flights[48].set_duration(3.0);
	flights[49].set_flight_number("PK-172");
	flights[49].set_plane(plane50);
	flights[49].set_departure_date("8/7/2023");
	flights[49].set_departure_time("2:00pm");
	flights[49].set_arrival_date("8/7/2023");
	flights[49].set_arrival_time("5:00pm");
	flights[49].set_available_seats_economy(50);
	flights[49].set_available_seats_business(10);
	flights[49].set_departure_airport(airport29);
	flights[49].set_arrival_airport(airport30);
	flights[49].set_price(500000);
	flights[49].set_duration(3.0);


	//main menu
	cout << "Welcome to the NUCES Airline Flight System (NAFS)" << endl;
	cout << "Press any key to continue" << endl;
	cin.get(); //to pause the screen

	while (exit == false) { //while loop iterates the main menu
		cout << "Press 1 to Login as Passenger" << endl;
		cout << "Press 2 to Register as Passenger" << endl;
		cout << "Press 3 to Login as Admin" << endl;
		cout << "Press 4 to Register as Admin" << endl;
		cout << "Press 5 to continue without login" << endl;
		cout << "Press 6 to exit" << endl;
		cin >> n;
		switch (n) { //switch case for main menu
		case 1: //login as passenger
			Sleep(1 * pow(10, 3));
			system("CLS");
			cout << "Login as a Passenger" << endl;
			cout << "Enter Username: " << endl;
			cin.ignore(); //to ignore the enter key
			getline(cin, username); //to get the whole line
			cout << "Enter Password: " << endl;
			//loop for taking password but displaing in '*' form 
			for (int i = 0;;) {
				a = _getch();
				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
					password[i] = a;
					++i;
					cout << "*";
				}
				if (a == '\b' && i >= 1) {
					cout << "\b \b";
					--i;
				}
				if (a == '\r')
				{
					password[i] = '\0';
					break;
				}
			}
			//cout << "\nYou entered : " << password << endl;
			cout << endl;
			//loop for verifing username and password
			for (int i = 0; i < passenger_array_size; i++) {
				if (passenger_arr[i].get_username() == username) {
					if (passenger_arr[i].get_password() == password) {
						cout << "Login Successful" << endl;
						login_passenger(passenger_arr, passenger_array_size, flights, flight_array_size, i);
						break;
					}
					else {
						cout << "Incorrect Password" << endl;
						break;
					}
				}
				else {
					cout << "Username or Password is incorrect" << endl;
				}
			}
			Sleep(1 * pow(10, 3)); //to pause the screen
			system("CLS"); //to clear the screen
			break;
		case 2:
			//register as passenger
			Sleep(1 * pow(10, 3));
			system("CLS");
			cout << "Register as a Passenger" << endl;
			cout << "Enter your CNIC Number" << endl;
			cin >> cnic;
			cout << "Enter your age" << endl;
			cin >> age;
			cout << "Enter Username: " << endl;
			cin.ignore(); //to ignore the enter key
			getline(cin, username); //to get the whole line
			//loop for checking if the username already exists or not
			for (int i = 0; i < passenger_array_size; i++) {
				if (passenger_arr[i].get_username() == username) {
					cout << "Username already exists" << endl;
					proceed = false; //to break the loop
					break;
				}
			}
			if (proceed == false) { //if username already exists then break the loop
				break;
			}
			cout << "Enter Password: " << endl;
			//loop for taking password but displaing in '*' form
			for (int i = 0;;) {
				a = _getch(); //to get the input without displaying it
				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
					password[i] = a;
					++i;
					cout << "*";
				}
				if (a == '\b' && i >= 1) {
					cout << "\b \b";
					--i;
				}
				if (a == '\r')
				{
					password[i] = '\0';
					break;
				}
			}
			//cout << "\nYou entered : " << password << endl;
			cout << endl;
			//dynamically increasing the size of the array and adding the new passenger to the array
			passenger_array_size++;
			new_passenger_arr = new passenger[passenger_array_size];
			for (int i = 0; i < passenger_array_size - 1; ++i) {
				new_passenger_arr[i] = passenger_arr[i];
			}
			new_passenger_arr[passenger_array_size - 1] = passenger(username, password, cnic, age);
			delete[] passenger_arr;
			passenger_arr = new_passenger_arr;
			cout << "Registration Successful. Login to use system." << endl;
			Sleep(1 * pow(10, 3)); //to pause the screen
			system("CLS"); //to clear the screen
			break;
		case 3:
			//login as admin
			Sleep(1 * pow(10, 3));
			system("CLS");
			cout << "Login as a Admin" << endl;
			cout << "Enter Username: " << endl;
			cin.ignore(); //to ignore the enter key
			getline(cin, username);
			cout << "Enter Password: " << endl;
			//loop for taking password but displaing in '*' form
			for (int i = 0;;) {
				a = _getch();
				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
					password[i] = a;
					++i;
					cout << "*";
				}
				if (a == '\b' && i >= 1) {
					cout << "\b \b";
					--i;
				}
				if (a == '\r')
				{
					password[i] = '\0';
					break;
				}
			}
			//cout << "\nYou entered : " << password << endl;
			cout << endl;
			//loop for verifing username and password
			for (int i = 0; i < admin_array_size; i++) {
				if (admin_arr[i].get_username() == username) {
					if (admin_arr[i].get_password() == password) {
						cout << "Login Successful" << endl;
						login_admin(admin_arr, admin_array_size, flights, flight_array_size, i);
						break;
					}
					else {
						cout << "Incorrect Password" << endl;
						break;
					}
				}
				else {
					cout << "Username or Password is incorrect" << endl;
				}
			}
			Sleep(1 * pow(10, 3)); //to pause the screen
			system("CLS"); //to clear the screen
			break;
		case 4:
			//register as admin
			Sleep(1 * pow(10, 3));
			system("CLS");
			cout << "Register as a Admin" << endl;
			cout << "Enter Username: " << endl;
			cin.ignore(); //to ignore the enter key
			getline(cin, username);
			//loop for checking if the username already exists or not
			for (int i = 0; i < admin_array_size; i++) {
				if (admin_arr[i].get_username() == username) {
					cout << "Username already exists" << endl;
					proceed = false; //to break the loop
					break;
				}
			}
			if (proceed == false) { //if username already exists then break the loop
				break;
			}
			cout << "Enter Password: " << endl;
			//loop for taking password but displaing in '*' form
			for (int i = 0;;) {
				a = _getch(); //to take input without displaying it
				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
					password[i] = a;
					++i;
					cout << "*";
				}
				if (a == '\b' && i >= 1) {
					cout << "\b \b";
					--i;
				}
				if (a == '\r')
				{
					password[i] = '\0';
					break;
				}
			}
			//cout << "\nYou entered : " << password << endl;
			cout << endl;
			//dynamically increasing the size of the array and adding the new admin to the array
			admin_array_size++;
			new_admin_arr = new admin[admin_array_size];
			for (int i = 0; i < admin_array_size - 1; ++i) {
				new_admin_arr[i] = admin_arr[i];
			}
			new_admin_arr[admin_array_size - 1] = admin(username, password);
			delete[] admin_arr;
			admin_arr = new_admin_arr;
			cout << "Registration Successful. Login to use system." << endl;
			Sleep(1 * pow(10, 3)); //to pause the screen
			system("CLS"); //to clear the screen
			break;
		case 5:
			//view flight schedule
			Sleep(1 * pow(10, 3));
			system("CLS");
			cout << "Continuing without login" << endl;
			cout << "Flight Schedule" << endl;
			for (int i = 0; i < 50; i++) { //loop for displaying all the flights
				cout << "Flight-" << i + 1 << ":-" << endl;
				cout << "Flight ID: " << flights[i].get_flight_number() << endl;
				cout << "Airplane ID: " << flights[i].get_plane().get_airplane_id() << endl;
				cout << "Passenger Count: " << flights[i].get_plane().get_passengers() << endl;
				cout << "Departure Date: " << flights[i].get_departure_date() << endl;
				cout << "Departure Time: " << flights[i].get_departure_time() << endl;
				cout << "Arrival Date: " << flights[i].get_arrival_date() << endl;
				cout << "Arrival Time: " << flights[i].get_arrival_time() << endl;
				cout << "Economy Seats Available: " << flights[i].get_available_seats_economy() << endl;
				cout << "Buisness Seats Available: " << flights[i].get_available_seats_business() << endl;
				cout << "Departure Airport Name: " << flights[i].get_departure_airport().get_airport_name() << endl;
				cout << "Departure City Name: " << flights[i].get_departure_airport().get_city_name() << endl;
				cout << "Departure Country Name: " << flights[i].get_departure_airport().get_country_name() << endl;
				cout << "Arrival Airport Name: " << flights[i].get_arrival_airport().get_airport_name() << endl;
				cout << "Arrival City Name: " << flights[i].get_arrival_airport().get_city_name() << endl;
				cout << "Arrival Country Name: " << flights[i].get_arrival_airport().get_country_name() << endl;
				cout << "Price: " << flights[i].get_price() << endl;
				cout << "Duration: " << flights[i].get_duration() << endl;
				cout << "---------------------------------------------" << endl;
			}
			cout << "Press any key to move to main menu" << endl;
			cin.ignore();
			cin.get(); //to pause the screen
			Sleep(1 * pow(10, 3)); //to pause the screen
			system("CLS"); //to clear the screen
			break;
		case 6:
			//exit
			cout << "Exiting the NUCES Airline Flight System (NAFS)" << endl;
			Sleep(1 * pow(10, 3));
			system("CLS");
			cout << "Thank you for using NUCES Airline Flight System (NAFS)" << endl;
			Sleep(1 * pow(10, 3));
			exit = true;
			break;
		default:
			//default case
			cout << "Invalid Input" << endl;
			break;
		}
	}
	return 0;
}

void login_passenger(passenger* passenger_arr, int passenger_array_size, flight* flights, int size, int index) { //function to login passenger and carry out further operations
	Sleep(1 * pow(10, 3));
	system("CLS");

	int x = 0, flight_index = 0;
	string flight_number = "", date = "", seat = "", booking_id_string = "", card_number = "", name = "", expiry_date = "", cvv = "", card_type = "", bank_name = "", account_number = "",
		passport_number = "", passport_expiry_date = "", passport_issue_date = "";
	bool exit = false;
	int booking_id = 0;
	booking b;
	FinancialDetail fd;
	passport p;
	visa v;
	
	while (exit == false) { //while loop to carry out operations until user wants to exit
		cout << "Press 1 to view flight schedule" << endl;
		cout << "Press 2 to book a flight" << endl;
		cout << "Press 3 to add payment details" << endl;
		cout << "Press 4 to add passport details" << endl;
		cout << "Press 5 to logout" << endl;
		cin >> x;
		switch (x) {
		case 1:
			for (int i = 0; i < 50; i++) { //loop for displaying all the flights
				cout << "Flight-" << i + 1 << ":-" << endl;
				cout << "Flight ID: " << flights[i].get_flight_number() << endl;
				cout << "Airplane ID: " << flights[i].get_plane().get_airplane_id() << endl;
				cout << "Passenger Count: " << flights[i].get_plane().get_passengers() << endl;
				cout << "Departure Date: " << flights[i].get_departure_date() << endl;
				cout << "Departure Time: " << flights[i].get_departure_time() << endl;
				cout << "Arrival Date: " << flights[i].get_arrival_date() << endl;
				cout << "Arrival Time: " << flights[i].get_arrival_time() << endl;
				cout << "Economy Seats Available: " << flights[i].get_available_seats_economy() << endl;
				cout << "Buisness Seats Available: " << flights[i].get_available_seats_business() << endl;
				cout << "Departure Airport Name: " << flights[i].get_departure_airport().get_airport_name() << endl;
				cout << "Departure City Name: " << flights[i].get_departure_airport().get_city_name() << endl;
				cout << "Departure Country Name: " << flights[i].get_departure_airport().get_country_name() << endl;
				cout << "Arrival Airport Name: " << flights[i].get_arrival_airport().get_airport_name() << endl;
				cout << "Arrival City Name: " << flights[i].get_arrival_airport().get_city_name() << endl;
				cout << "Arrival Country Name: " << flights[i].get_arrival_airport().get_country_name() << endl;
				cout << "Price: " << flights[i].get_price() << endl;
				cout << "Duration: " << flights[i].get_duration() << endl;
				cout << "---------------------------------------------" << endl;
			}
			cout << "Press any key to move to main menu" << endl;
			cin.ignore();
			cin.get();
			break;
		case 2:
			//book a flight
			cout << "Enter the flight number you want to book" << endl;
			cin >> flight_number;
			for (int i = 0; i < size; i++) {
				if (flights[i].get_flight_number() == flight_number) {
					flight_index = i;
					break;
				}
			}

			cout << "Enter today's date in the format dd/mm/yyyy" << endl;
			cin >> date;
			cout << "Enter the seat you want" << endl;
			cin >> seat;

			srand(time(0));
			booking_id = rand() % 1000;
			booking_id_string = to_string(booking_id);

			b.set_booking_id(booking_id_string);
			b.set_booking_date(date);
			b.set_departure_date(flights[flight_index].get_departure_date());
			b.set_departure_time(flights[flight_index].get_departure_time());
			b.set_arrival_date(flights[flight_index].get_arrival_date());
			b.set_arrival_time(flights[flight_index].get_arrival_time());
			b.set_seat_number(seat);
			b.set_flight_details(flights[flight_index]);
			passenger_arr[index].set_booking_details(b);
			cout << "Booking Successful" << endl;

			cout << "Booking ID: " << passenger_arr[index].get_booking(booking_id_string).get_booking_id() << endl;
			cout << "Booking Date: " << passenger_arr[index].get_booking(booking_id_string).get_booking_date() << endl;
			cout << "Departure Date: " << passenger_arr[index].get_booking(booking_id_string).get_departure_date() << endl;
			cout << "Departure Time: " << passenger_arr[index].get_booking(booking_id_string).get_departure_time() << endl;
			cout << "Arrival Date: " << passenger_arr[index].get_booking(booking_id_string).get_arrival_date() << endl;
			cout << "Arrival Time: " << passenger_arr[index].get_booking(booking_id_string).get_arrival_time() << endl;
			cout << "Seat Number: " << passenger_arr[index].get_booking(booking_id_string).get_seat_number() << endl;
			cout << "Flight Number: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_flight_number() << endl;
			cout << "Airplane ID: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_plane().get_airplane_id() << endl;
			cout << "Passenger Count: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_plane().get_passengers() << endl;
			cout << "Departure Airport Name: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_departure_airport().get_airport_name() << endl;
			cout << "Departure City Name: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_departure_airport().get_city_name() << endl;
			cout << "Departure Country Name: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_departure_airport().get_country_name() << endl;
			cout << "Arrival Airport Name: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_arrival_airport().get_airport_name() << endl;
			cout << "Arrival City Name: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_arrival_airport().get_city_name() << endl;
			cout << "Arrival Country Name: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_arrival_airport().get_country_name() << endl;
			cout << "Price: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_price() << endl;
			cout << "Duration: " << passenger_arr[index].get_booking(booking_id_string).get_flight_details().get_duration() << endl;
			break;
		case 3:
			//enter financial details
			cout << "Enter you financial details" << endl;
			cout << "Enter your 16 digit card number" << endl;
			cin >> card_number;
			cout << "Enter your name" << endl;
			cin >> name;
			cout << "Enter your expiry date in the form dd/mm/yyyy" << endl;
			cin >> expiry_date;
			cout << "Enter your 3 digit CVV" << endl;
			cin >> cvv;
			cout << "Enter your card type(Mastercard/Visa/PayPak)" << endl;
			cin >> card_type;
			cout << "Enter your bank name" << endl;
			cin >> bank_name;
			cout << "Enter your 11 digit bank account number" << endl;
			cin >> account_number;

			//fill the financial details
			fd.set_card_number(card_number);
			fd.set_card_holder_name(name);
			fd.set_card_expiry_date(expiry_date);
			fd.set_card_cvv(cvv);
			fd.set_card_type(card_type);
			fd.set_bank_name(bank_name);
			fd.set_bank_account_number(account_number);

			//verify the financial details
			fd.VerifyFinancialDetail();
			passenger_arr[index].set_financial_details(fd);
			cout << "Payment Successful" << endl;
			break;
		case 4:
			//enter passport details
			cout << "Enter your passport details" << endl;
			cout << "Enter your passport number" << endl;
			cin >> passport_number;
			cout << "Enter your passport expiry date in the form dd/mm/yyyy" << endl;
			cin >> passport_expiry_date;
			cout << "Enter your passport issue date in the form dd/mm/yyyy" << endl;
			cin >> passport_issue_date;
			p.set_passport_number(passport_number);
			p.set_expiry_date(passport_expiry_date);
			p.set_issuance_date(passport_issue_date);
			v.set_visa();
			p.set_visa(v);
			passenger_arr[index].set_passport_details(p);
			cout << "Passport Details Entered" << endl;
			break;
		case 5:
			//logout
			cout << "Logging out" << endl;
			Sleep(1 * pow(10, 3));
			system("CLS");
			exit = true;
			break;
		default:
			cout << "Invalid Input" << endl;
		}
	}
}

void login_admin(admin* admin_arr, int admin_array_size, flight* flights, int size, int index) { //login function for admin
	Sleep(1 * pow(10, 3));
	system("CLS");

}