#include <bits/stdc++.h>
using namespace std;

void processFile(const string &fileName, const string &key, const string &outputFileName)
{
    ifstream inputFile(fileName, ios::binary);
    ofstream outputFile(outputFileName, ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Error: Unable to open file(s)." << endl;
        return;
    }

    char ch;
    int keyIndex = 0;
    int keyLength = key.length();

    // Process the file character by character
    while (inputFile.get(ch))
    {
        // XOR the character with the corresponding key character
        char encryptedChar = ch ^ key[keyIndex];
        outputFile.put(encryptedChar);

        // Move to the next character in the key, looping back if necessary
        keyIndex = (keyIndex + 1) % keyLength;
    }

    inputFile.close();
    outputFile.close();

    cout << "File processed successfully! Output written to: " << outputFileName << endl;
}

int main()
{
    string fileName, key, outputFileName;
    int choice;

    cout << "File Encryption and Decryption\n";
    cout << "1. Encrypt a file\n";
    cout << "2. Decrypt a file\n";
    cout << "Enter your choice (1/2): ";
    cin >> choice;

    cout << "Enter the name of the input file: ";
    cin >> fileName;
    fileName += ".txt";

    cout << "Enter the encryption/decryption key: ";
    cin >> key;

    if (choice == 1)
    {
        outputFileName = "encrypted_" + fileName;
        processFile(fileName, key, outputFileName);
    }
    else if (choice == 2)
    {
        outputFileName = "decrypted_" + fileName;
        processFile(fileName, key, outputFileName);
    }
    else
    {
        cout << "Invalid choice. Exiting program." << endl;
    }

    return 0;
}
