#include <iostream>
#include <cstdlib>

#define newLine      cout << endl << endl;
#define nextNode     currentNode -> next
#define previousNode currentNode -> previous
#define goToNextNode currentNode = currentNode -> next;

using namespace std;

template <class Type>
class DoubleLinkedList {
public:

    struct Node {
        Type value;
        Node *previous, *next;
    };

    Node *root;

    DoubleLinkedList() {
        root = NULL;
    }

    void addElement(Type parameter) {

        // Daca lista e vida(nici macar radacina nu e initializata)
        // atunci se adauga noul element in radacina in sine si se termina functia
        if (root == NULL) {
            root = (Node*)malloc(sizeof(Node));
            root -> next = NULL;
            root -> previous = NULL;
            root -> value = parameter;
            return;
        }

        // Altfel folosim un Node nou pentru a parcurge lista, incepand cu radacina, "din next in next",
        // pana cand ajungem la ultimul element
        // (adica urmatorul next ar fi NULL pentru ca nu mai exista un urmator element)
        Node *currentNode;
        currentNode = root;

        while (nextNode != NULL)
            goToNextNode

        // Creem un Node nou, initial ne-legat de nici un alt nod(adica e complet separat de lista),
        // ii atribuim valoare pe care vrem sa o adaugam la lista,
        // si apoi facem legaturile cu ultimul element din lista(il adaugam la coada listei)
        // Ultimul nod al listei il avem de mai sus din while
        Node *newNode;
        newNode = (Node*)malloc(sizeof(Node));
        newNode -> next = NULL;
        newNode -> previous = NULL;

        newNode ->value = parameter;

        nextNode = newNode;
        newNode -> previous = currentNode;
    }
    void removeElement(int index) {
        Node *currentNode, *aux;
        currentNode = root;

        // Daca se vrea stergerea radacinii, pur si simplu urmatorul(al doilea) element va deveni noua radacina
        if (index == 0) {
            root = root -> next;
            return;
        }

        // Altfel folosim un nou Node pentru a parcurge lista, incepand cu radacina, "din next in next",
        // pana cand ajungem la elementul cu index-ul dorit.
        for (int i = 1; i <= index; ++i)
            goToNextNode

        // Apoi folosim un nod auxiliar mentru a memora vecinii nodului pe care dorim sa il eliminam(nodul curent)
        // si realizam legaturile intre ei:
        // predecesorului nodului curent ii va urma acum noudl care urma dupa nodul curent
        // iar succesorul nodului curent va fi acum precedat ce nodul care era inaintea nodului curent
        aux = (Node*)malloc(sizeof(Node));
        aux -> previous = previousNode;
        aux -> next     = nextNode;
        previousNode -> next     = aux -> next;
        nextNode     -> previous = aux -> previous;
    }
    Type elementAt(int index) {
        Node *currentNode;
        currentNode = root;

        // Folosim un nou Node pentru a parcurge lista, incepand cu radacina, "din next in next",
        // pana cand ajungem la elementul cu index-ul dorit.
        // Deoarece radacina este in acelasi timp si elementul 0,
        // pentru elementul acesta nu va fi necesar nici un next, ci il putem returna direct
        for (int i = 1; i <= index; ++i)
            goToNextNode

        return currentNode -> value;
    }
    int indexOf(Type element) {
        Node *currentNode;
        currentNode = root;
        int index = 0;

        // Daca radacina contine elementul dorit,
        // nu avem altceva de facut decat sa returnam indexul radacinii, adica 0
        if (root -> value == element)
            return index;

        // Altfel folosim un nou Node pentru a parcurge lista, incepand cu radacina(deja verificata)
        // si o valoare int pentru a afla la ce pozitie ne aflam. Daca am ajuns la sfarsitul listei
        // atunci tragem concluzia ca elementul cerut nu apare in lista, si returnam -1,
        // altfel, (daca nu am ajuns la sfarsitul listei) incrementam indexul la care ne aflam
        // si verificam daca nu cumva urmatorul element este cel cerut;
        // daca este, returnam indexul(deja incrementat), altfel trecem la urmatorul element
        while (true) {
            if (nextNode == NULL)
                return -1;
            index++;
            if (nextNode -> value == element)
                return index;
            goToNextNode
        }
    }

    void displayAll() {
        Node *currentNode = root;

        // Daca lista este vida, afisam ca atare
        if (root == NULL) {
            cout << "Void list.";
            return;
        }

        // Altfel folosim un Node nou pentru a parcurge lista, incepand cu radacina, "din next in next", pana cand
        // ajungem la ultimul element (adica urmatorul next ar fi NULL pentru ca nu mai exista un urmator element)
        // si afisam pe parcurs valoarea stocata in fiecare nod
        while (true) {
            cout << currentNode -> value;

            if (nextNode == NULL)
                break;

            cout << " -> ";
            goToNextNode
        }
    }

    bool contains(Type element) {
        Node *currentNode;
        currentNode = root;

        // Daca elementul cerut se afla in radacina il verificam direct
        // si returnam true daca l-am gasit
        if (root -> value == element)
            return true;

        // Altfel folosim un Node nou pentru a parcurge lista, incepand cu radacina,
        // si verificam daca urmatorul element exista (altfel am ajuns la capatul listei
        // si iesim din functie cu concluzia ca elementul cerut nu se afla in aceasta).
        // Daca urmatorul element exista, este verificat pentru valoarea ceruta,
        // daca este gasita evident ca intoarcem true, daca nu, trecem pur si simplu la urmatorul element
        while (true) {
            if (nextNode == NULL)
                break;
            if (nextNode -> value == element)
                return true;
            goToNextNode
        }

        return false;
    }
};


int main() {

    DoubleLinkedList<char> *l = new DoubleLinkedList<char>();
    newLine

    l -> addElement('A');
    l -> addElement('L');
    l -> addElement('I');
    l -> addElement('N');
    l -> addElement('A');
    cout << "ADDED ELEMENTS: \"A\" \"L\" \"I\" \"N\" \"A\"";
    newLine

    cout << "ELEMENT AT(i) i = 0..4: " << l -> elementAt(0)
                                       << l -> elementAt(1)
                                       << l -> elementAt(2)
                                       << l -> elementAt(3)
                                       << l -> elementAt(4);
    newLine

    cout << "DISPLAY ALL: ";
    l -> displayAll();
    newLine

    cout << "CONTAINS(A): " << l -> contains('A') << endl
         << "CONTAINS(B): " << l -> contains('B');
    newLine

    cout << "REMOVE ELEMENT(0): ";
    l -> removeElement(0);
    l -> displayAll();
    newLine

    cout << "INDEX OF(A): " << l -> indexOf('A');
    newLine

    return 0;
}