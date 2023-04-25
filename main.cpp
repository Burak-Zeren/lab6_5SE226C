#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int list1[] = {1,15,48,96,2,5,6,75};
int list2[] = {2,45,7,15,23,68,48,5};
int sL1 = sizeof (list1) / sizeof (list1[0]);
int sL2 = sizeof (list2) / sizeof (list2[0]);
int * question1(int l1[], int l2[]){
    int a =0;
    int* list3= new int [sL1<sL2? sL1: sL2];
    for (int i = 0; i < sL1; ++i) {
        for (int j = 0; j < sL2; ++j) {
           if (l1[i]==l2[j]){
               list3[a++]=l1[i];
        }
    }
    }
    return list3;
}
string array1[]={"ada","burak","ahmet","deified","car","rotator"};
int sA1 = sizeof (array1) / sizeof (array1[0]);
int sA2=0;
string * quesiton2(string* a1){
    string * array2=new string[sA1];
    for (int i = 0; i < sA1; i++) {
        string nonReverse = a1[i];
        string reverse = "";
        for (int j = nonReverse.length() - 1; j >= 0; j--) {
            reverse += nonReverse[j]; // Reverse the string
        }
        if (nonReverse == reverse) {
            array2[sA2] = nonReverse;
            sA2++;
        }
    }
    return array2;
}

int prime1[] = {5,9,14,17,21,25,29,31,35,44,51};
int sP1 = sizeof (prime1) / sizeof (prime1[0]);
int* question3(int list1[]) {
    int* list2 = new int[sP1];
    int count = 0;
    for(int j = 0; j < sP1; j++) {
        int num = list1[j];
        bool prime[num+1];
        memset(prime, true, sizeof(prime));
        int p = 2;
        while (p * p <= num){
            if (prime[p] == true){
                for (int i = p * p; i <= num; i += p){
                    prime[i] = false;
                }
            }
            p++;
        }
        for (int p = 2; p <= num; p++){
            if (prime[p]){
                if (num == p){
                    list2[count] = num;
                    count++;
                }
            }
        }
    }
    return list2;
}

const char* word_list[] = {"iceman", "nemaic", "burak", "car", "google", "apple", "maenci"};
int size12 = sizeof (word_list) / sizeof (word_list[0]);
char** question4(const char* word, const char** word_list) {
    char** sorted_list = new char*[size12];
    int count = 0;
    char* newItem = new char[strlen(word)];
    strcpy(newItem, word);
    for (int i = 0; i < strlen(newItem); i++) {
        newItem[i] = tolower(newItem[i]);
    }
    for (int i = 0; i < size12; i++) {
        char* newWord = new char[strlen(word_list[i])];
        strcpy(newWord, word_list[i]);
        for (int j = 0; j < strlen(newWord); j++) {
            newWord[j] = tolower(newWord[j]);
        }
        if (strcmp(newWord, newItem) == 0) {
            sorted_list[count] = new char[strlen(word_list[i])];
            strcpy(sorted_list[count], word_list[i]);
            count++;
        }
        delete[] newWord;
    }
    sorted_list[count] = NULL;
    delete[] newItem;
    return sorted_list;
}

int main() {
    //Question1
    //-------------------------------------------------------------------
    int* list3=question1(list1,list2);
    int sL3 = sizeof (list3) / sizeof (list3[0]);
    cout<<"Result of Question 1 :"<<endl;
    for (int i = 0; i < sL3; i++) {
        cout << list3[i] << " ";
    }
    cout<<endl;
    //-------------------------------------------------------------------

    //Question2
    //-------------------------------------------------------------------
    string* array2 = quesiton2(array1);
    cout<<"Result of Question 2 :"<<endl;
    for (int i = 0; i < sA2; i++) {
        cout << array2[i] << " ";
    }
    cout<<endl;
    //-------------------------------------------------------------------

    //Question3
    //-------------------------------------------------------------------
    int* prime2 = question3(list1);
    cout<<"Result of Question 3 :"<<endl;
    for (int i = 0; i < sP1; i++) {
        cout << prime2[i] << " ";
    }
    cout<<endl;
    //-------------------------------------------------------------------

    //Question4
    //-------------------------------------------------------------------

    char ** listPrime = question4("cinema",word_list);
    cout<<"Result of Question 4 :"<<endl;
    for (int i = 0; listPrime[i] != NULL; i++) {
        cout << listPrime[i] << endl;
        delete[] listPrime[i];
    }
    cout<<endl;
    return 0;
}
