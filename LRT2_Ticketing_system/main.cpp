#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string Station[] = {"Recto","Legard", "Pureza", "V. Mapa" , "J. Ruiz", "Gilmore", "Betty Go", "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina-Pasig", "Antipolo"};
string paymentOption[] = {"CASH", "GCASH"};
string passengerOption[] = {"Regular" , "PWD / SENIOR CITIZEN/ STUDENT"};
long long int ReferenceNumber = 1023129312;
double SingleJourneyFareMatrix[13][13] = {
        {0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35, 35},
        {15, 0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35},
        {20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30, 30, 30},
        {20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30, 30},
        {20, 20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30},
        {25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25, 30},
        {25, 25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25},
        {25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25, 25},
        {25, 25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25},
        {30, 25, 25, 25, 20, 20, 20, 20, 15, 0, 20, 20, 25},
        {30, 30, 30, 25, 25, 25, 20, 20, 20, 20, 0, 15, 20},
        {35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 15, 0, 20},
        {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 0}
};
void Single_Journey();
void ReceiptTicket();
void PaymentMethod();
void Passengeroption();

void GcashPayment();
void CashPayment();

int Selection, SelectOrigin, ToStation, PassengerOption, PaymentOption, Tickets;
double TotalPrice[2], Payment, Change;
int main() {
    system("clear");
    cout << "+--------------------------------+" << endl
         << "|                                |" << endl
         << "|         LRT 2 TICKETS          |" << endl
         << "|                                |" << endl
         << "+--------------------------------+" << endl;
    cout << "[1] SINGLE JOURNEY" << endl
         << "[0] Exit" << endl
         << "Select: ";
    cin >> Selection;
    switch (Selection) {
            case 1:
            Single_Journey();
            break;
        case 0:
            return 0;
            default:
            cout << "Select 1 or 0 " << endl;
            cout << "Enter to continue...";
            cin.ignore();
            cin.get();
            main();
            break;
    }
    return 0;
}

void Single_Journey() {
    system("clear");
    cout << "+--------------------------------+" << endl
         << "|                                |" << endl
         << "|         SINGLE JOURNEY         |" << endl
         << "|                                |" << endl
         << "+--------------------------------+" << endl;
    for (int i = 0; i < 13; i++) {
        if (i % 2 != 0 && i != 0) {
            cout << "[" << i + 1 << "]" <<Station[i] << "\t" << endl;
        } else {
            cout << "[" << i + 1 << "]" <<Station[i] << "\t";
        }
    }
    cout << endl
         << "Select Origin: ";
    cin >> SelectOrigin;
    cout << "Select Station: ";
    cin >> ToStation;
    cout << endl << endl;
    if (SelectOrigin != ToStation) {
        cout << Station[SelectOrigin - 1] << " to "<< Station[ToStation - 1] << endl
        << "Single Journey: " << endl
        << "Price: " << fixed << setprecision(2) << SingleJourneyFareMatrix[SelectOrigin- 1][ToStation - 1] << endl;
        cout << "How many Tickets: ";
        cin >> Tickets;
        if (SelectOrigin > 0 && SelectOrigin <= 13) {
            Passengeroption();
        } else {
            cout << "The origin and destination cannot be the same" << endl;
            cout << "Enter to continue...";
            cin.ignore();
            cin.get();
            Single_Journey();
        }
    }
}

void Passengeroption() {
    system("clear");
    cout << "Passenger Option: " << endl
         << "[1] Regular " << endl
         << "[2] PWD / SENIOR CITIZEN/ STUDENT" << endl
         << "[0] Back" << endl
         << "Select: ";
    cin >> PassengerOption;
    switch (PassengerOption) {
        case 1: PaymentMethod();break;
        case 2: PaymentMethod(); break;
        case 0: Single_Journey(); break;
        default:
            cout << "Select 1 or 2 and 0 to go back" << endl;
            cout << "Enter to continue...";
            cin.ignore();
            cin.get();
            Passengeroption();
            break;
    }
}

void GcashPayment() {
    system("clear");
    cout << "GCASH" << endl
         << "Amount Due: " << fixed << setprecision(2) << TotalPrice[PassengerOption - 1] << endl
         << "Credited: ";
    cin >> Payment;
    if (Payment >= TotalPrice[PassengerOption - 1]) {
        Change = Payment - TotalPrice[PassengerOption - 1];
        ReceiptTicket();
    }else if (Payment == 0) {
        PaymentMethod();
    }else {
        cout << "Insufficient Payment" << endl;
        cout << "If you have cash: Put 0 to go back " << endl;
        cout << "Enter to continue...";
        cin.ignore();
        cin.get();
        GcashPayment();
    }
}
void CashPayment() {
    system("clear");
    cout << "CASH" << endl
         << "Amount Due: " << fixed << setprecision(2) << TotalPrice[PassengerOption - 1] << endl
         << "Credited: ";
    cin >> Payment;
    if (Payment >= TotalPrice[PassengerOption - 1]) {
        Change = Payment - TotalPrice[PassengerOption - 1];
        ReceiptTicket();
    }else if (Payment == 0) {
        PaymentMethod();
    }else {
        cout << "Insufficient Payment" << endl;
        cout << "If you have cash: Put 0 to go back " << endl;
        cout << "Enter to continue...";
        cin.ignore();
        cin.get();
        GcashPayment();
    }
}

void PaymentMethod() {
    system("clear");
    if (PassengerOption == 1) {
        TotalPrice[PassengerOption - 1] = SingleJourneyFareMatrix[SelectOrigin- 1][ToStation - 1] * Tickets;
    }
    else {
        TotalPrice[PassengerOption - 1] = (SingleJourneyFareMatrix[SelectOrigin- 1][ToStation - 1] * Tickets) - ((SingleJourneyFareMatrix[SelectOrigin- 1][ToStation - 1] * Tickets) * 0.2);
    }
    cout << "Passenger: " << passengerOption[PassengerOption - 1] << endl
         << "Price: " << fixed << setprecision(2) << TotalPrice[PassengerOption - 1] << endl
         << "Payment Option: " << endl
         << "[1] CASH" << endl
         << "[2] GCASH" << endl
         << "[0] BACK" << endl
         << "Select: ";
    cin >> PaymentOption;
    switch (PaymentOption) {
        case 1:
            CashPayment();
            break;
        case 2:
            GcashPayment();
            break;
        case 0:
            Passengeroption();
            break;
        default:
            cout << "Select 1 to 2 and 0 to go back" << endl;
            cout << "Enter to continue...";
            cin.ignore();
            cin.get();
            PaymentMethod();
            break;
    }
}

void ReceiptTicket() {
    system("clear");
    cout << "LRT 2 TICKET: " << endl;
    cout << "Station: " << Station[SelectOrigin - 1] << " to "  << left<< setw(14) << Station[ToStation - 1] << endl
         << "Ticket: " << left << setw(3) << Tickets << endl
         << "Price: " << left << setw(5) << fixed << setprecision(2) << SingleJourneyFareMatrix[SelectOrigin- 1][ToStation - 1] << endl;
    cout << "Total Price: " << fixed << setprecision(2) << TotalPrice[PassengerOption - 1]<< endl
         << "Payment " << left << setw(5) << paymentOption[PaymentOption - 1] << endl;
        if (PaymentOption - 1 == 1) {
            cout << "Reference #: " << left << setw(11) << ReferenceNumber << endl;
        }
    cout << "Credited: " << fixed << setprecision(2) << Payment << endl
         << "Change: " << left << setw(5) << fixed << setprecision(2) << Change << endl
         << endl;
    ReferenceNumber++;
    cout << "Enter to continue...";
        cin.ignore();
        cin.get();
    main();
}