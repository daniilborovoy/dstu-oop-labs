#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Stock {
    char *campaignName;
    int stockCount;
    int price;
    int totalPrice;

    void setTot(int stockCount, int price) {
        totalPrice = stockCount * price;
    }

public:
    Stock() {
        time_t result = time(nullptr);
        cout << "Stock created at " << ctime(&result) << endl;
    };

    Stock(char *campaignName, int stockCount, int price) {
        acquire(campaignName, stockCount, price);
        time_t result = time(nullptr);
        cout << "Stock created at " << ctime(&result) << endl;
    };

    ~Stock() {
        time_t result = time(nullptr);
        cout << "Stock destroyed at " << ctime(&result) << endl;
    };

    void acquire(char *campaignName, int stockCount, int price) {
        this->campaignName = campaignName;
        this->stockCount = stockCount;
        this->price = price;
        setTot(stockCount, price);
    };

    void buy(int count) {
        cout << "Buying " << count << " stocks of " << campaignName << endl;
        if (count > stockCount) {
            cout << "Not enough stock" << endl;
            return;
        }
        this->stockCount += stockCount;
        setTot(this->stockCount, price);
    };

    void sell(int sellStockCount) {
        cout << "Selling " << sellStockCount << " stocks of " << campaignName << endl;
        if (sellStockCount > stockCount) {
            cout << "You can't sell more than you have!" << endl;
            return;
        }
        stockCount -= sellStockCount;
        setTot(stockCount, price);
    };

    void update(int newPrice) {
        cout << "Updating " << campaignName << " price to " << newPrice << endl;
        price = newPrice;
        setTot(stockCount, price);
    };

    void show() {
        cout << "Campaign Name: " << campaignName << endl;
        cout << "Stock Count: " << stockCount << endl;
        cout << "Price: " << price << endl;
        cout << "Total Price: " << totalPrice << "\n" << endl;
    };
};

class Abiturient {
    char *firstName;
    char *lastName;
    char *patronymic;
    char *address;
    int estimates[5];

public:
    Abiturient(char *firstName, char *lastName, char *patronymic, char *address, int estimates[5]) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->patronymic = patronymic;
        this->address = address;
        for (int i = 0; i < 5; i++) {
            this->estimates[i] = estimates[i];
        }
    }

    int getEstimate(int i) {
        return estimates[i];
    }

    int *getEstimates() {
        return estimates;
    }

    int getEstimatesSum() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += estimates[i];
        }
        return sum;
    }

    string getFullName() {
        return string(firstName) + " " + string(lastName) + " " + string(patronymic);
    }

    char *getFirstName() {
        return firstName;
    }

    char *getLastName() {
        return lastName;
    }

    char *getPatronymic() {
        return patronymic;
    }

    char *getAddress() {
        return address;
    }

};

void showAbiturientsWithHighestScore(Abiturient *abiturients, int abiturientCount);

void showAbiturientsWithSemiPassScore(Abiturient *abiturients, int abiturientCount);

int main() {

    // Task 1
    Stock appleStock = Stock();
    appleStock.acquire("Apple", 10, 100);
    appleStock.show();
    appleStock.buy(5);
    appleStock.show();
    appleStock.sell(5);
    appleStock.show();
    appleStock.update(200);
    appleStock.show();

    // Task 3
    const int stockCount = 5;
    Stock stocks[stockCount] = {
            Stock("Apple", 10, 100),
            Stock("Google", 20, 200),
            Stock("Microsoft", 30, 300),
            Stock("Amazon", 40, 400),
            Stock("Facebook", 50, 500)
    };

    // Task 4
    int IvanovEstimates[] = {5, 5, 5, 5, 5};
    int PetrovEstimates[] = {4, 4, 4, 4, 4};
    int SidorovEstimates[] = {3, 3, 3, 3, 3};
    int MaximovEstimates[] = {2, 2, 2, 2, 2};

    Abiturient abiturients[] = {
            Abiturient("Ivan", "Ivanov", "Ivanovich", "Moscow", IvanovEstimates),
            Abiturient("Petr", "Petrov", "Petrovich", "Moscow", PetrovEstimates),
            Abiturient("Sidor", "Sidorov", "Sidorovich", "Moscow", SidorovEstimates),
            Abiturient("Max", "Maximov", "Maximovich", "Moscow", MaximovEstimates),
    };


    // Show abiturients who has bad estimates
    int abiturientCount = sizeof(abiturients) / sizeof(abiturients[0]);
    for (int i = 0; i < abiturientCount; i++) {
        int *estimates = abiturients[i].getEstimates();
        for (int j = 0; j < 5; j++) {
            if (estimates[j] < 4) {
                cout << "Abiturient " << abiturients[i].getFirstName() << " has bad estimates" << endl;
                break;
            }
        }
    }


    // Show abiturients who has estimates sum more or equal 20
    const int estimatesSum = 20;
    for (int i = 0; i < abiturientCount; i++) {
        int *estimates = abiturients[i].getEstimates();
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += estimates[j];
        }
        if (sum >= estimatesSum) {
            cout << "Abiturient " << abiturients[i].getFirstName() << " has sum of estimates more or equal than "
                 << estimatesSum
                 << endl;
        }
    }

    showAbiturientsWithHighestScore(abiturients, abiturientCount);

    cout << endl;

    showAbiturientsWithSemiPassScore(abiturients, abiturientCount);

    return 0;
}

void showAbiturientsWithHighestScore(Abiturient *abiturients, int abiturientCount) {
    int N;
    cout << "Enter N (abiturients count):  ";
    cin >> N;
    cout << endl;
    if (N > abiturientCount) {
        cout << "N can't be more than abiturient count" << endl;
        return;
    }
    int abiturientsIndexes[N];
    for (int i = 0; i < N; i++) {
        int maxIndex = 0;
        int maxSum = 0;
        for (int j = 0; j < abiturientCount; j++) {
            int sum = abiturients[j].getEstimatesSum();
            if (sum > maxSum) {
                bool isAlreadyInArray = false;
                for (int k = 0; k < N; k++) {
                    if (abiturientsIndexes[k] == j) {
                        isAlreadyInArray = true;
                        break;
                    }
                }
                if (!isAlreadyInArray) {
                    maxIndex = j;
                    maxSum = sum;
                }
            }
        }
        abiturientsIndexes[i] = maxIndex;
    }
    for (int i = 0; i < N; i++) {
        cout << "Abiturient " << abiturients[abiturientsIndexes[i]].getFirstName() << " has highest score" << endl;
    }
}

void showAbiturientsWithSemiPassScore(Abiturient *abiturients, int abiturientCount) {
    const int semiPassScore = 10;

    for (int i = 0; i < abiturientCount; i++) {
        int estimatesSum = abiturients[i].getEstimatesSum();
        if (estimatesSum >= semiPassScore) {
            cout << "Abiturient " << abiturients[i].getFullName() << " has semi-pass score" << endl;
        }
    }
}
