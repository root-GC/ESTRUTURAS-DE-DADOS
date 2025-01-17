#include <iostream>
#include <memory>

class LinkedList {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> next;
        Node(int val) : data(val), next(nullptr) {}
    };

    std::shared_ptr<Node> head;

public:
    LinkedList() : head(nullptr) {}

    void createList(int data) {
        auto newNode = std::make_shared<Node>(data);
        if (!head) {
            head = newNode;
        } else {
            auto temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addAtBeginning(int data) {
        auto newNode = std::make_shared<Node>(data);
        newNode->next = head;
        head = newNode;
    }

    void addAfter(int data, int pos) {
        auto temp = head;
        for (int i = 1; i < pos && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            std::cout << "Position out of bounds.\n";
            return;
        }
        auto newNode = std::make_shared<Node>(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int data) {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }

        if (head->data == data) {
            head = head->next;
            return;
        }

        auto temp = head;
        while (temp->next && temp->next->data != data) {
            temp = temp->next;
        }

        if (!temp->next) {
            std::cout << "Element not found.\n";
        } else {
            temp->next = temp->next->next;
        }
    }

    void display() const {
        auto temp = head;
        if (!temp) {
            std::cout << "List is empty.\n";
            return;
        }
        std::cout << "List: ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void countNodes() const {
        int count = 0;
        auto temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        std::cout << "Number of elements: " << count << "\n";
    }

    void reverseList() {
        std::shared_ptr<Node> prev = nullptr, curr = head, next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void search(int data) const {
        auto temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == data) {
                std::cout << "Element " << data << " found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        std::cout << "Element " << data << " not found.\n";
    }
};

int main() {
    LinkedList list;
    int choice, data, pos;

    while (true) {
        std::cout << "1. Create List\n"
                  << "2. Add at Beginning\n"
                  << "3. Add After\n"
                  << "4. Delete\n"
                  << "5. Display\n"
                  << "6. Count\n"
                  << "7. Reverse\n"
                  << "8. Search\n"
                  << "9. Quit\n"
                  << "Enter your choice: ";
         std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter data to add: ";
                std::cin >> data;
                list.createList(data);
                break;
            case 2:
                std::cout << "Enter data to add: ";
                std::cin >> data;
                list.addAtBeginning(data);
                break;
            case 3:
                std::cout << "Enter data to add: ";
                std::cin >> data;
                std::cout << "Enter position: ";
                std::cin >> pos;
                list.addAfter(data, pos);
                break;
            case 4:
                std::cout << "Enter data to delete: ";
                std::cin >> data;
                list.deleteNode(data);
                break;
            case 5:
                list.display();
                break;
            case 6:
                list.countNodes();
                break;
            case 7:
                list.reverseList();
                break;
            case 8:
                std::cout << "Enter data to search: ";
                std::cin >> data;
                list.search(data);
                break;
            case 9:
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}
