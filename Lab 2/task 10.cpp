#include <iostream>
using namespace std;


int main(){
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;
    int* booksInCategory = new int[categories];
    int** library = new int*[categories];
    for(int i = 0; i < categories; i++){
        cout << "Enter number of books in category" << i + 1 << ": ";
        cin >> booksInCategory[i];
        library[i] = new int[booksInCategory[i]];
        cout << "Enter book IDs for catgeory " << i + 1 << ":\n";
        for(int j = 0; j < booksInCategory[i]; j++){
            cout <<"Book " << j + 1 << ": ";
            cin >> library[i][j];
        }
    }
    int searchID;
    cout << "Enter bok ID to search: ";
    cin >> searchID;
    bool found = false;
    int foundCategory = -1;
    for(int i = 0; i < categories && !found; i++)
    {
        for(int j = 0; j < booksInCategory[i]; j++)
        {
            if(library[i][j] == searchID)
            {
                found = true;
                foundCategory = i;
                break;
            }
        }
    }
    if(found)
    {
        cout << "Book ID " << searchID << " is available in category " 
             << foundCategory + 1 << "." << endl;
    }
    else
    {
        cout << "Book ID " << searchID << " is not available in the library." << endl;
    }
    for(int i = 0; i < categories; i++){
        delete[] library[i];
    }
    delete[] library;
    delete[] booksInCategory;
    return 0;
}
