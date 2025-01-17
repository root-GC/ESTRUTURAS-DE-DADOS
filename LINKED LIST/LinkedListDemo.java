import java.util.Scanner;

class LinkedList {
     
    // Estrutura do nó
    private static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node start;

    // Construtor
    public LinkedList() {
        start = null;
    }

    // Método para criar lista
    public void createList(int data) {
        Node newNode = new Node(data);
        if (start == null) {
            start = newNode;
        } else {
            Node temp = start;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    // Adiciona elemento no início
    public void addAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = start;
        start = newNode;
    }

    // Adiciona elemento em posição específica
    public void addAfter(int data, int pos) {
        Node temp = start;
        for (int i = 1; i < pos; i++) {
            if (temp == null) {
                System.out.println("Menos de " + pos + " elementos na lista.");
                return;
            }
            temp = temp.next;
        }
        Node newNode = new Node(data);
        newNode.next = temp.next;
        temp.next = newNode;
    }

    // Remove um elemento da lista
    public void delete(int data) {
        if (start == null) {
            System.out.println("A lista está vazia.");
            return;
        }

        if (start.data == data) {
            start = start.next;
            return;
        }

        Node temp = start;
        while (temp.next != null && temp.next.data != data) {
            temp = temp.next;
        }

        if (temp.next == null) {
            System.out.println("Elemento " + data + " não encontrado.");
        } else {
            temp.next = temp.next.next;
        }
    }

    // Exibe os elementos da lista
    public void display() {
        if (start == null) {
            System.out.println("A lista está vazia.");
            return;
        }
        Node temp = start;
        System.out.print("Lista: ");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // Conta o número de elementos na lista
    public void count() {
        int count = 0;
        Node temp = start;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        System.out.println("Número de elementos: " + count);
    }

    // Reverte a lista
    public void reverse() {
        if (start == null || start.next == null) {
            return;
        }

        Node prev = null;
        Node current = start;
        Node next;

        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        start = prev;
    }

    // Busca por um elemento na lista
    public void search(int data) {
        Node temp = start;
        int pos = 1;

        while (temp != null) {
            if (temp.data == data) {
                System.out.println("Elemento " + data + " encontrado na posição " + pos);
                return;
            }
            temp = temp.next;
            pos++;
        }

        System.out.println("Elemento " + data + " não encontrado.");
    }
}

public class LinkedListDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Criar Lista");
            System.out.println("2. Adicionar no início");
            System.out.println("3. Adicionar após posição");
            System.out.println("4. Deletar");
            System.out.println("5. Exibir");
            System.out.println("6. Contar elementos");
            System.out.println("7. Reverter lista");
            System.out.println("8. Buscar elemento");
            System.out.println("9. Sair");
            System.out.print("Escolha uma opção: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Quantos elementos você deseja adicionar? ");
                    int n = sc.nextInt();
                    for (int i = 0; i < n; i++) {
                        System.out.print("Digite o elemento: ");
                        int data = sc.nextInt();
                        list.createList(data);
                    }
                    break;
                case 2:
                    System.out.print("Digite o elemento: ");
                    int dataAtBeg = sc.nextInt();
                    list.addAtBeginning(dataAtBeg);
                    break;
                case 3:
                    System.out.print("Digite o elemento: ");
                    int dataAfter = sc.nextInt();
                    System.out.print("Digite a posição: ");
                    int pos = sc.nextInt();
                    list.addAfter(dataAfter, pos);
                    break;
                case 4:
                    System.out.print("Digite o elemento a ser deletado: ");
                    int deleteData = sc.nextInt();
                    list.delete(deleteData);
                    break;
                case 5:
                    list.display();
                    break;
                case 6:
                    list.count();
                    break;
                case 7:
                    list.reverse();
                    System.out.println("Lista revertida.");
                    break;
                case 8:
                    System.out.print("Digite o elemento a ser buscado: ");
                    int searchData = sc.nextInt();
                    list.search(searchData);
                    break;
                case 9:
                    System.out.println("Encerrando...");
                    sc.close();
                    return;
                default:
                    System.out.println("Opção inválida.");
            }
        }
    }
}
