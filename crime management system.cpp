#include <iostream>
#include <string>
using namespace std;

const int MAX_CASES = 100;

struct CriminalCase {
    int caseid;
    string name;
    string crime;
    int age;
    string dateStr;
    string sex;
    string crimehistory;
    CriminalCase* next;
};

CriminalCase arrayCases[MAX_CASES];
int arrayCount = 0;
CriminalCase* head = nullptr;

bool adminLogin() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    if (username == "admin" && password == "admin123") {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Invalid username or password.\n";
        return false;
    }
}

// --- Add Case ---
void addArrayCase() {
    if (arrayCount >= MAX_CASES) {
        cout << "Array storage full. Cannot add more cases.\n";
        return;
    }
    CriminalCase &c = arrayCases[arrayCount];
    cout << "Enter Case ID: ";
    cin >> c.caseid;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Enter Crime: ";
    getline(cin, c.crime);
    cout << "Enter Age: ";
    cin >> c.age;
    cout << "Enter Date (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, c.dateStr);
    cout << "Enter Sex: ";
    getline(cin, c.sex);
    cout << "Enter Crime History: ";
    getline(cin, c.crimehistory);
    c.next = nullptr;
    arrayCount++;
    cout << "Case added to array.\n";
}

void addListCase() {
    CriminalCase* c = new CriminalCase;
    cout << "Enter Case ID: ";
    cin >> c->caseid;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, c->name);
    cout << "Enter Crime: ";
    getline(cin, c->crime);
    cout << "Enter Age: ";
    cin >> c->age;
    cout << "Enter Date (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, c->dateStr);
    cout << "Enter Sex: ";
    getline(cin, c->sex);
    cout << "Enter Crime History: ";
    getline(cin, c->crimehistory);
    c->next = nullptr;

    if (!head) {
        head = c;
    } else {
        CriminalCase* temp = head;
        while (temp->next){
        temp = temp->next;
        }
        temp->next = c;

    }
    cout << "Case added to linked list.\n";
}

// --- Display Cases ---
void displayArrayCases() {
    if (arrayCount == 0) {
        cout << "No cases in array.\n";
        return;
    }
    for (int i = 0; i < arrayCount; i++) {
        cout << "Case ID: " << arrayCases[i].caseid << "\n";
        cout << "Name: " << arrayCases[i].name << "\n";
        cout << "Crime: " << arrayCases[i].crime << "\n";
        cout << "Age: " << arrayCases[i].age << "\n";
        cout << "Date: " << arrayCases[i].dateStr << "\n";
        cout << "Sex: " << arrayCases[i].sex << "\n";
        cout << "History: " << arrayCases[i].crimehistory << "\n";
        cout << "-----------------------\n";
    }
}

void displayListCases() {
    if (!head) {
        cout << "No cases in linked list.\n";
        return;
    }
    CriminalCase* temp = head;
    while (temp) {
        cout << "Case ID: " << temp->caseid << "\n";
        cout << "Name: " << temp->name << "\n";
        cout << "Crime: " << temp->crime << "\n";
        cout << "Age: " << temp->age << "\n";
        cout << "Date: " << temp->dateStr << "\n";
        cout << "Sex: " << temp->sex << "\n";
        cout << "History: " << temp->crimehistory << "\n";
        cout << "-----------------------\n";
        temp = temp->next;
    }
}
// --- Update Case ---
void updateArrayCase() {
    if (arrayCount == 0) {
        cout << "No cases in array to update.\n";
        return;
    }
    int id;
    cout << "Enter Case ID to update: ";
    cin >> id;
    int pos = -1;
    for (int i = 0; i < arrayCount; i++) {
        if (arrayCases[i].caseid == id) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Case not found.\n";
        return;
    }
    cout << "Enter new details:\n";
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, arrayCases[pos].name);
    cout << "Enter Crime: ";
    getline(cin, arrayCases[pos].crime);
    cout << "Enter Age: ";
    cin >> arrayCases[pos].age;
    cout << "Enter Date (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, arrayCases[pos].dateStr);
    cout << "Enter Sex: ";
    getline(cin, arrayCases[pos].sex);
    cout << "Enter Crime History: ";
    getline(cin, arrayCases[pos].crimehistory);
    cout << "Case updated in array.\n";
}

void updateListCase() {
    if (!head) {
        cout << "No cases in linked list to update.\n";
        return;
    }
    int id;
    cout << "Enter Case ID to update: ";
    cin >> id;
    CriminalCase* temp = head;
    while (temp && temp->caseid != id) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Case not found.\n";
        return;
    }
    cout << "Enter new details:\n";
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, temp->name);
    cout << "Enter Crime: ";
    getline(cin, temp->crime);
    cout << "Enter Age: ";
    cin >> temp->age;
    cout << "Enter Date (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, temp->dateStr);
    cout << "Enter Sex: ";
    getline(cin, temp->sex);
    cout << "Enter Crime History: ";
    getline(cin, temp->crimehistory);
    cout << "Case updated in linked list.\n";
}

// --- Delete Case ---
void deleteArrayCase() {
    if (arrayCount == 0) {
        cout << "No cases in array to delete.\n";
        return;
    }
    int id;
    cout << "Enter Case ID to delete: ";
    cin >> id;
    int pos = -1;
    for (int i = 0; i < arrayCount; i++) {
        if (arrayCases[i].caseid == id) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Case not found.\n";
        return;
    }
    for (int i = pos; i < arrayCount - 1; i++) {
        arrayCases[i] = arrayCases[i + 1];
    }
    arrayCount--;
    cout << "Case deleted from array.\n";
}

void deleteListCase() {
    if (!head) {
        cout << "No cases in linked list to delete.\n";
        return;
    }
    int id;
    cout << "Enter Case ID to delete: ";
    cin >> id;

    if (head->caseid == id) {
        CriminalCase* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Case deleted from linked list.\n";
        return;
    }
    CriminalCase* temp = head;
    while (temp->next && temp->next->caseid != id) {
        temp = temp->next;
    }
    if (!temp->next) {
        cout << "Case not found.\n";
        return;
    }
    CriminalCase* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    cout << "Case deleted from linked list.\n";
}

// --- Search Functions ---

// Linear search array
int linearSearchArray(int id) {
    for (int i = 0; i < arrayCount; i++) {
        if (arrayCases[i].caseid == id)
        return i;
    }
    return -1;
}

// Binary search array (array must be sorted by caseid)
int binarySearchArray(int id) {
    int left = 0, right = arrayCount - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arrayCases[mid].caseid == id){
        return mid;
        }
        else if (arrayCases[mid].caseid < id){
        left = mid + 1;
        }
        else{
        right = mid - 1;
        }
    }
    return -1;
}

// Linear search linked list
CriminalCase* linearSearchList(int id) {
    CriminalCase* temp = head;
    while (temp) {
        if (temp->caseid == id){
        return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Binary search linked list - must be sorted by caseid
// Because linked list doesn’t support random access, we use slow/fast pointer method to find mid
CriminalCase* getMiddle(CriminalCase* start, CriminalCase* end) {
    if (start == nullptr)
    return nullptr;

    CriminalCase* slow = start;
    CriminalCase* fast = start->next;
    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

CriminalCase* binarySearchListHelper(CriminalCase* start, CriminalCase* end, int id) {
    if (start == end)
    return nullptr;
    CriminalCase* mid = getMiddle(start, end);
    if (!mid)
    return nullptr;
    if (mid->caseid == id)
    return mid;
    else if (mid->caseid < id)
        return binarySearchListHelper(mid->next, end, id);
    else
        return binarySearchListHelper(start, mid, id);
}

CriminalCase* binarySearchList(int id) {
    return binarySearchListHelper(head, nullptr, id);
}

// --- Sort Functions ---

// Swap two CriminalCase objects (for array sorting)
void swapArrayCases(CriminalCase &a, CriminalCase &b) {
    CriminalCase temp = a;
    a = b;
    b = temp;
}

// Bubble sort array by caseid
void bubbleSortArray() {
    for (int i = 0; i < arrayCount - 1; i++) {
        for (int j = 0; j < arrayCount - i - 1; j++) {
            if (arrayCases[j].caseid > arrayCases[j + 1].caseid) {
                swapArrayCases(arrayCases[j], arrayCases[j + 1]);
            }
        }
    }
}

// Selection sort array by caseid
void selectionSortArray() {
    for (int i = 0; i < arrayCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arrayCount; j++) {
            if (arrayCases[j].caseid < arrayCases[minIndex].caseid) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swapArrayCases(arrayCases[i], arrayCases[minIndex]);
        }
    }
}

// Insertion sort array by caseid
void insertionSortArray() {
    for (int i = 1; i < arrayCount; i++) {
        CriminalCase key = arrayCases[i];
        int j = i - 1;
        while (j >= 0 && arrayCases[j].caseid > key.caseid) {
            arrayCases[j + 1] = arrayCases[j];
            j--;
        }
        arrayCases[j + 1] = key;
    }
}

// Swap linked list node data
void swapListCases(CriminalCase* a, CriminalCase* b) {
    if (!a || !b) return;
    CriminalCase temp = *a;
    // Copy data fields except next pointer
    int tempCaseId = a->caseid;
    string tempName = a->name;
    string tempCrime = a->crime;
    int tempAge = a->age;
    string tempDate = a->dateStr;
    string tempSex = a->sex;
    string tempHistory = a->crimehistory;

    a->caseid = b->caseid;
    a->name = b->name;
    a->crime = b->crime;
    a->age = b->age;
    a->dateStr = b->dateStr;
    a->sex = b->sex;
    a->crimehistory = b->crimehistory;

    b->caseid = tempCaseId;
    b->name = tempName;
    b->crime = tempCrime;
    b->age = tempAge;
    b->dateStr = tempDate;
    b->sex = tempSex;
    b->crimehistory = tempHistory;
}

// Bubble sort linked list by caseid
void bubbleSortList() {
    if (!head  ||!head->next) return;
    bool swapped;
    do {
        swapped = false;
        CriminalCase* ptr = head;
        while (ptr->next) {
            if (ptr->caseid > ptr->next->caseid) {
                swapListCases(ptr, ptr->next);
                swapped = true;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

// Selection sort linked list by caseid
void selectionSortList() {
    for (CriminalCase* i = head; i != nullptr; i = i->next) {
        CriminalCase* minNode = i;
        for (CriminalCase* j = i->next; j != nullptr; j = j->next) {
            if (j->caseid < minNode->caseid) {
                minNode = j;
            }
        }
        if (minNode != i) {
            swapListCases(i, minNode);
        }
    }
}

// Insertion sort linked list by caseid
void insertionSortList() {
    if (!head || !head->next) return;
    CriminalCase* sorted = nullptr;
    CriminalCase* current = head;
    while (current) {
        CriminalCase* next = current->next;
        if (!sorted || current->caseid < sorted->caseid) {
            current->next = sorted;
            sorted = current;
        } else {
            CriminalCase* temp = sorted;
            while (temp->next && temp->next->caseid < current->caseid) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

// --- Menu Functions ---
void displayMenu() {
    cout << "\n===== Criminal Case Management System =====\n";
    cout << "1. Add Case\n";
    cout << "2. Display Cases\n";
    cout << "3. Update Case\n";
    cout << "4. Delete Case\n";
    cout << "5. Search Case\n";
    cout << "6. Sort Case\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

int chooseDataStructure() {
    int choice;
    cout << "Choose data structure:\n";
    cout << "1. Array\n";
    cout << "2. Linked List\n";
    cout << "Choose: ";
    cin >> choice;
    return choice;
}

void addCaseMenu() {
    int ds = chooseDataStructure();
    switch(ds) {
        case 1:
        addArrayCase();
        break;
        case 2:
        addListCase();
        break;
        default:
        cout << "Invalid choice.\n";
        break;
    }
}

void displayCaseMenu() {
    int ds = chooseDataStructure();
    switch(ds) {
        case 1:
        displayArrayCases();
        break;
        case 2:
        displayListCases();
        break;
        default: cout << "Invalid choice.\n";
        break;
    }
}

void updateCaseMenu() {
    int ds = chooseDataStructure();
    switch(ds) {
        case 1:
        updateArrayCase();
        break;
        case 2:
        updateListCase();
        break;
        default:
        cout << "Invalid choice.\n";
        break;
    }
}

void deleteCaseMenu() {
    int ds = chooseDataStructure();
    switch(ds) {
        case 1:
        deleteArrayCase();
        break;
        case 2:
        deleteListCase();
        break;
        default:
        cout << "Invalid choice.\n";
        break;
    }
}

void searchCaseMenu() {
    int ds = chooseDataStructure();
    if (ds != 1 && ds != 2) {
        cout << "Invalid choice.\n";
        return;
    }
    int searchType;
    cout << "Search type:\n1. Linear Search\n2. Binary Search\nChoose: ";
    cin >> searchType;

if (ds == 1) { // Array
        int id;
        cout << "Enter case ID to search: ";
        cin >> id;
        int pos = -1;
        if (searchType == 1) {
            pos = linearSearchArray(id);
        } else if (searchType == 2) {
            insertionSortArray();  // Sort first for binary search
            pos = binarySearchArray(id);
        } else {
            cout << "Invalid search type.\n";
            return;
        }
        if (pos == -1) {
            cout << "Case ID not found in array.\n";
        } else {
            cout << "Case found in array:\n";
            cout << "Case ID: " << arrayCases[pos].caseid << "\n";
            cout << "Name: " << arrayCases[pos].name << "\n";
            cout << "Crime: " << arrayCases[pos].crime << "\n";
            cout << "Age: " << arrayCases[pos].age << "\n";
            cout << "Date: " << arrayCases[pos].dateStr << "\n";
            cout << "Sex: " << arrayCases[pos].sex << "\n";
            cout << "History: " << arrayCases[pos].crimehistory << "\n";
        }
    } else { // Linked list
        int id;
        cout << "Enter case ID to search: ";
        cin >> id;
        CriminalCase* found = nullptr;
        if (searchType == 1) {
            found = linearSearchList(id);
        } else if (searchType == 2) {
            insertionSortList(); // Sort first for binary search
            found = binarySearchList(id);
        } else {
            cout << "Invalid search type.\n";
            return;
        }
        if (!found) {
            cout << "Case ID not found in linked list.\n";
        } else {
            cout << "Case found in linked list:\n";
            cout << "Case ID: " << found->caseid << "\n";
            cout << "Name: " << found->name << "\n";
            cout << "Crime: " << found->crime << "\n";
            cout << "Age: " << found->age << "\n";
            cout << "Date: " << found->dateStr << "\n";
            cout << "Sex: " << found->sex << "\n";
            cout << "History: " << found->crimehistory << "\n";
        }
    }
}

void sortCaseMenu() {
    int ds = chooseDataStructure();
    if (ds != 1 && ds != 2) {
        cout << "Invalid choice.\n";
        return;
    }
    int sortType;
    cout << "Sort type:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nChoose: ";
    cin >> sortType;

    if (ds == 1) {
        switch(sortType) {
            case 1: bubbleSortArray(); cout << "Array sorted by bubble sort.\n"; break;
            case 2: selectionSortArray(); cout << "Array sorted by selection sort.\n"; break;
            case 3: insertionSortArray(); cout << "Array sorted by insertion sort.\n"; break;
            default: cout << "Invalid sort type.\n"; break;
        }
    } else {
        switch(sortType) {
            case 1: bubbleSortList(); cout << "Linked list sorted by bubble sort.\n"; break;
            case 2: selectionSortList(); cout << "Linked list sorted by selection sort.\n"; break;
            case 3: insertionSortList(); cout << "Linked list sorted by insertion sort.\n"; break;
            default: cout << "Invalid sort type.\n"; break;
        }
    }
}

int main() {
    if (!adminLogin()) {
        return 0;
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch(choice) {
            case 1: addCaseMenu(); break;
            case 2: displayCaseMenu(); break;
            case 3: updateCaseMenu(); break;
            case 4: deleteCaseMenu(); break;
            case 5: searchCaseMenu(); break;
            case 6: sortCaseMenu(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 0);

    return 0;
}