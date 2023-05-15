// Veri Yapilari ve Algoritmalar KS - 2 Soru 4
// Sümeyra Sümer
// 5210505067



#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Deger basariyla eklendi." << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Kuyruk bos, silme islemi gerceklestirilemez." << endl;
        } else {
            Node* temp = front;
            front = front->next;

            delete temp;

            if (front == NULL) {
                rear = NULL;
            }

            cout << "Deger basariyla silindi." << endl;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Kuyruk bos." << endl;
        } else {
            cout << "Kuyruk elemanlari: ";
            Node* current = front;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
	
	cout << "Veri Yapilari ve Algoritmalar KS - 2 Soru 4" << endl;
	cout << "Sumeyra Sumer" << endl;
	cout << "5210505067" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	
    Queue queue;
    int choice, value;

    do {
        cout << "Lutfen asagidaki islemlerden birini seciniz" << endl;
        cout << "1. Ekleme" << endl;
        cout << "2. Silme" << endl;
        cout << "3. Goruntuleme" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Eklemek istediginiz degeri giriniz: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Programdan cikiliyor." << endl;
                break;
            default:
                cout << "Gecersiz secim, lutfen tekrar deneyin." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}

