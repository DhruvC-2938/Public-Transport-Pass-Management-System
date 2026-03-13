#include <iostream>
#include <string>
using namespace std;

class TransportPass
{
private:
    int passID;
    string holderName;
    int age;
    string passType;
    string passPlan;
    int validityDays;
    float price;

public:
    bool applyForPass()
    {
        int choice;

        cout << "Enter Pass ID: ";
        cin >> passID;

        cout << "Enter Holder Name: ";
        cin >> holderName;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Is the pass holder a student? (1 = Yes, 0 = No): ";
        cin >> choice;

        if (choice == 1)
            passType = "Student";
        else
            passType = "Regular";

        cout << "\nSelect Pass Plan\n";
        cout << "1. Monthly\n";
        cout << "2. Quarterly\n";
        cout << "3. Half-Yearly\n";
        cout << "4. Yearly\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            passPlan = "Monthly";
            validityDays = 30;
            price = 500;
            break;

        case 2:
            passPlan = "Quarterly";
            validityDays = 90;
            price = 1400;
            break;

        case 3:
            passPlan = "Half-Yearly";
            validityDays = 180;
            price = 2700;
            break;

        case 4:
            passPlan = "Yearly";
            validityDays = 365;
            price = 5000;
            break;

        default:
            cout << "Invalid plan\n";
            return false;
        }

        if (passType == "Student")
        {
            price *= 0.5;
            cout << "Student Discount Applied\n";
        }

        displayPassDetails();

        int confirm;

        cout << "\nConfirm Pass Application? (1 = Yes, 0 = No): ";
        cin >> confirm;

        if (confirm == 1)
        {
            cout << "Pass Created Successfully!\n";
            return true;
        }
        else
        {
            cout << "Pass Application Cancelled\n";
            return false;
        }
    }

    void displayPassDetails()
    {
        cout << "\n----- Pass Details -----\n";
        cout << "Pass ID: " << passID << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Age: " << age << endl;
        cout << "Pass Type: " << passType << endl;
        cout << "Pass Plan: " << passPlan << endl;
        cout << "Validity Days: " << validityDays << endl;
        cout << "Price: ₹" << price << endl;
    }

    void checkValidity()
    {
        if (validityDays > 0)
            cout << "Status: Active\n";
        else
            cout << "Status: Expired\n";
    }

    void renewPass()
    {
        int choice;

        cout << "\nSelect Renewal Plan\n";
        cout << "1. Monthly (30 days)\n";
        cout << "2. Quarterly (90 days)\n";
        cout << "3. Half-Yearly (180 days)\n";
        cout << "4. Yearly (365 days)\n";
        cout << "Enter choice: ";
        cin >> choice;

        float renewalPrice = 0;

        switch (choice)
        {
        case 1:
            validityDays += 30;
            renewalPrice = 500;
            break;

        case 2:
            validityDays += 90;
            renewalPrice = 1400;
            break;

        case 3:
            validityDays += 180;
            renewalPrice = 2700;
            break;

        case 4:
            validityDays += 365;
            renewalPrice = 5000;
            break;

        default:
            cout << "Invalid option\n";
            return;
        }

        if (passType == "Student")
        {
            renewalPrice *= 0.5;
        }

        price += renewalPrice;

        cout << "Pass renewed successfully!\n";
        cout << "Renewal Price Added: ₹" << renewalPrice << endl;
    }

    int getPassID()
    {
        return passID;
    }
};

int main()
{
    TransportPass passes[100];
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== Transport Pass Management System =====\n";
        cout << "1. Apply for Pass\n";
        cout << "2. Check Pass Validity\n";
        cout << "3. Renew Pass\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (passes[count].applyForPass())
            {
                count++;
            }
            break;

        case 2:
        {
            if (count == 0)
            {
                cout << "No passes available\n";
                break;
            }

            cout << "\nAvailable Pass IDs:\n";

            for (int i = 0; i < count; i++)
            {
                cout << passes[i].getPassID() << endl;
            }

            int id;
            bool found = false;

            cout << "Enter Pass ID: ";
            cin >> id;

            for (int i = 0; i < count; i++)
            {
                if (passes[i].getPassID() == id)
                {
                    passes[i].displayPassDetails();
                    passes[i].checkValidity();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Pass not found\n";

            break;
        }

        case 3:
        {
            if (count == 0)
            {
                cout << "No passes available\n";
                break;
            }

            cout << "\nAvailable Pass IDs:\n";

            for (int i = 0; i < count; i++)
            {
                cout << passes[i].getPassID() << endl;
            }

            int id;
            bool found = false;

            cout << "Enter Pass ID to renew: ";
            cin >> id;

            for (int i = 0; i < count; i++)
            {
                if (passes[i].getPassID() == id)
                {
                    passes[i].renewPass();
                    passes[i].displayPassDetails();
                    passes[i].checkValidity();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Pass not found\n";

            break;
        }

        case 4:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
